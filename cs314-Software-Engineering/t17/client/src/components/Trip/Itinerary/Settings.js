import React from 'react';
import {
	Button,
	Col,
	Modal,
	ModalBody,
	ModalHeader,
	ModalFooter,
	Input
} from 'reactstrap';
import DistancesRequest from './DistancesRequest';


export default function Settings(props) {
	return (
		<Modal isOpen={props.isOpen} toggle={props.toggleSettings} >
			<SettingsHeader toggleSettings={props.toggleSettings} />
			{buildSettingsInput(props)}
			{buildSettingsFooter(props)}

		</Modal>
	);
}
function buildSettingsInput(props) {
	return (
		<SettingsInput 
			earthRadius={props.earthRadius}
			setEarthRadius={props.setEarthRadius}
			units={props.units}
			setUnits={props.setUnits}
			distances={props.distances}
			setDistances={props.setDistances}
			places={props.places}
			setPlaces={props.setPlaces}
			serverUrl={props.serverUrl}
		/>
	);
}
function buildSettingsFooter(props) {
	return (
		<SettingsFooter
			toggleSettings={props.toggleSettings}
			earthRadius={props.earthRadius}
			setEarthRadius={props.setEarthRadius}
			units={props.units}
			setUnits={props.setUnits}
			distances={props.distances}
			setDistances={props.setDistances}
			places={props.places}
			setPlaces={props.setPlaces}
			serverUrl={props.serverUrl}
		/>
	);
}

function SettingsHeader(props) {
	return (
		<ModalHeader className='ml-2' toggle={props.toggleSettings}>
		User Settings
		</ModalHeader>
	);
}

function SettingsInput(props) {
	return (
		<ModalBody> 
			{buildCustomUnitInput(props)}
			{buildButtons(props, 3959, 'miles')}
			&nbsp;&nbsp;&nbsp;
			{buildButtons(props, 6371, 'kilometers')}
			&nbsp;&nbsp;&nbsp;
			{buildButtons(props, 3440, 'nautical miles')}
		</ModalBody>		
	);
}
function buildCustomUnitInput(props) {
	return (
		<Col > 
			Enter Custom Earth Radius in Miles:
			<Input
				onChange={(input) => handleCustomUnitInput(props, input.target.value)}
				placeholder='Enter Custom Earth Radius. Default is 3,959 miles' 
				data-testid='earthRadius-Input'	
			/>
			Current Earth Radius is {props.earthRadius}
		</Col>
	);
}
function buildButtons(props, earthRadius, type) {
	return (
		<Col className = "text-md-left">
			<Button
				color='primary'
				onClick={() => handleUnitsInput(props, earthRadius, type)
				}
			>
			{type} 	
			</Button>
		</Col>
	);
}
function handleCustomUnitInput(props, input) {
	props.setEarthRadius(input);
	props.setUnits('custom units')
}

function SettingsFooter(props) {
	return(
		<ModalFooter>
				<Button
					color='primary'
					onClick={() => 
						handleUserInput(props)
					}
					data-testid='close-settings-button'
				>
					Confirm
				</Button>

		</ModalFooter>
	);
}

function handleUserInput(props) {

if (isNaN(props.earthRadius) || props.earthRadius < 1) {
	props.setEarthRadius(3959);
	} else {
	props.setEarthRadius(parseInt(props.earthRadius));
	}
	DistancesRequest(props.setDistances, props.places, props.serverUrl, parseInt(props.earthRadius));
	props.setPlaces(props.places);
	props.toggleSettings(); 



}

function handleUnitsInput(props, units, type) {

	props.setEarthRadius(units);
	props.setUnits(type);
	DistancesRequest(props.setDistances, props.places, props.serverUrl, units);
	props.setPlaces(props.places);

}