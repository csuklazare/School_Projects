import React, { useEffect, useState } from 'react';
import {
	Button,
	Col,
	Modal,
	ModalBody,
	ModalHeader,
	Input,
	Collapse,
	ModalFooter,
} from 'reactstrap';
import Coordinates from 'coordinate-parser';
import { reverseGeocode } from '../../../utils/reverseGeocode';
import FindRequest from './FindRequest';
import DynamicTable from '../../../utils/DynamicTable';
import { Place } from '../../../models/place.model';

export default function AddPlace(props) {
	const [foundPlace, setFoundPlace] = useState();
	const [coordString, setCoordString] = useState('');
	const [nameString, setNameString] = useState('');
	return (
		<Modal isOpen={props.isOpen} toggle={props.toggleAddPlace} onClosed={()=> setNameString('')} >
			<AddPlaceHeader toggleAddPlace={props.toggleAddPlace} />
			<PlaceSearch
				foundPlace={foundPlace}
				setFoundPlace={setFoundPlace}
				coordString={coordString}
				setCoordString={setCoordString}
				nameString={nameString}
				setNameString={setNameString}
				foundPlaces={props.foundPlaces}
				setFoundPlaces={props.setFoundPlaces}
				serverUrl={props.serverUrl}
				append={props.append}
			/>
			<AddPlaceFooter
				append={props.append}
				foundPlace={foundPlace}
				setCoordString={setCoordString}
			/>
		</Modal>
	);
}

function AddPlaceHeader(props) {
	return (
		<ModalHeader className='ml-2' toggle={props.toggleAddPlace}>
			Add a Place
		</ModalHeader>
	);
}

function PlaceSearch(props) {
	useEffect(() => {
		verifyCoordinates(props.coordString, props.setFoundPlace);
	}, [props.coordString]);
	useEffect(() => {
		verifyString(props.nameString, props.setFoundPlaces, props.serverUrl);
	}, [props.nameString]);
	return (
		<ModalBody> 
			<Col>
				{buildCoordInput(props.setCoordString, props.coordString, props.foundPlace)}
			</Col>
			<Col>
				{buildTextInput(props)}
			</Col>
		</ModalBody>
	);
}
function buildCoordInput(setCoordString, coordString, foundPlace) {
	return (
		<React.Fragment>
			<Input
				onChange={(input) => setCoordString(input.target.value)}
				placeholder='Enter Place Coordinates'
				data-testid='coord-input'
				value={coordString}
			/>
			<PlaceInfo 
				foundPlace={foundPlace}
			/>
		</React.Fragment>
	);
}
function buildTextInput(props) {
	return (
		<React.Fragment>
			<Input
				onChange={(input) => props.setNameString(input.target.value)}
				placeholder='Enter Place Name'
				data-testid='name-input'
				value={props.nameString}
			/>
			<FoundPlacesInfo 
				foundPlace={props.foundPlace}
				setFoundPlace={props.setFoundPlace}
				append={props.append}
				foundPlaces={props.foundPlaces}
			/>
		</React.Fragment>
	)
}

function PlaceInfo(props) {
	return (
		<Collapse isOpen={!!props.foundPlace}>
			<br />
			{props.foundPlace?.formatPlace()}
		</Collapse>
	);
}
function FoundPlacesInfo(props) {

	let currentPlaces = [];
	for (let i = 0; i < props.foundPlaces?.length; i++) {
		let newFoundPlace = new Place(props.foundPlaces[i]);
		currentPlaces.push(newFoundPlace.formatPlace());
	}
	return (
		<Collapse isOpen={ props.foundPlaces?.length > 0 }>
			<br />
			<DynamicTable
				foundPlace={props.foundPlace}
				foundPlaces={props.foundPlaces}
				setFoundPlace={props.setFoundPlace}
				currentPlaces={currentPlaces}
				append={props.append}
			/>
		</Collapse>
	)
}

function AddPlaceFooter(props) {
	return (
		<ModalFooter>
			<Button
				color='primary'
				onClick={() => {
					props.append(props.foundPlace);
					props.setCoordString('');
				}}
				data-testid='add-place-button'
				disabled={!props.foundPlace}
			>
				Add Place
			</Button>
		</ModalFooter>
	);
}

export async function verifyCoordinates(coordString, setFoundPlace) {
	try {
		const latLngPlace = new Coordinates(coordString);
		const lat = latLngPlace.getLatitude();
		const lng = latLngPlace.getLongitude();
		if (lat !== undefined && lng !== undefined) {
			const fullPlace = await reverseGeocode({ lat, lng });
			setFoundPlace(fullPlace);
		}
	} catch (error) {
		setFoundPlace(undefined);
	}
}

async function verifyString(nameString, setFoundPlaces, serverUrl) {
	try {
		if (nameString.length > 0) {
			FindRequest(setFoundPlaces, nameString, serverUrl);
		} 
	} catch (error) {
		setFoundPlaces(undefined);
	}
}