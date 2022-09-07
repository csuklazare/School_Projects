import React, { useState } from 'react';
import { useToggle } from '../../../hooks/useToggle';
import { Table, Collapse } from 'reactstrap';
import { ItineraryActionsDropdown, PlaceActionsDropdown } from './actions.js';
import { latLngToText, placeToLatLng } from '../../../utils/transformers';
import AddPlace from './AddPlace';
import LoadTrip from './LoadTrip';
import OptimizeTrip from './OptimizeTrip';
import Settings from './Settings';
import SaveTrip from './SaveTrip';

export default function Itinerary(props) {
    function tripIsEmpty() {
        return !props.places || props.places.length === 0;
    }
    return (
        <Table responsive>
			{buildTripHeader(props, tripIsEmpty)}
            <PlaceList
				places={props.places}
				placeActions={props.placeActions}
				selectedIndex={props.selectedIndex}
				distances={props.distances}
				setDistances={props.setDistances}
				units={props.units}
				setUnits={props.setUnits}
				setPlaces={props.setPlaces}
			/>
        </Table>
    );
}
function buildTripHeader(props, tripIsEmpty) {
	return (
		<TripHeader 
			places={props.places}
			setPlaces={props.setPlaces}
			selectedIndex={props.selectedIndex}
			placeActions={props.placeActions}
			disableRemoveAll={tripIsEmpty()}
			serverUrl={props.serverUrl}
			distances={props.distances}
			setDistances={props.setDistances}
			foundPlaces={props.foundPlaces}
			setFoundPlaces={props.setFoundPlaces}
			tour = {props.tour}
			setTour = {props.setTour}
			earthRadius={props.earthRadius}
			setEarthRadius={props.setEarthRadius}
			units={props.units}
			setUnits={props.setUnits}
		/>
	);
}

function TripHeader(props) {
	const [showAddPlace, toggleAddPlace] = useToggle(false);
	const [showLoadTrip, toggleLoadTrip] = useToggle(false);
	const [showOptTrip, toggleOptimizeTrip] = useToggle(false);
	const [showSettings, toggleSettings] = useToggle(false);
	const [showSaveTrip, toggleSaveTrip] = useToggle(false);
	const toggleObj = {toggleAddPlace, toggleLoadTrip, toggleOptimizeTrip, toggleSettings, toggleSaveTrip};
	return (
		<React.Fragment>
			<thead>
				<tr>
				 	<th className='trip-header-title'>My Trip</th>
	 				<th className='trip-header-actions'>
						{buildItineraryActionsDropdown(props, toggleObj)}
					</th>
				</tr>
			</thead>
			{buildAddPlace(props, toggleAddPlace, showAddPlace)}
			{buildLoadTrip(props, toggleLoadTrip, showLoadTrip)}
			{buildOptimizeTrip(props, toggleOptimizeTrip, showOptTrip)}
			{buildSettings(props, toggleSettings, showSettings)}
			{buildSaveTrip(props, toggleSaveTrip, showSaveTrip)}
		</React.Fragment>
	);
}
function buildItineraryActionsDropdown(props, toggleObj) {
	return (
		<ItineraryActionsDropdown
			places={props.places}
			placeActions={props.placeActions}
			disableRemoveAll={props.disableRemoveAll}
			toggleAddPlace={toggleObj.toggleAddPlace}
			toggleLoadTrip={toggleObj.toggleLoadTrip}
			toggleOptimizeTrip={toggleObj.toggleOptimizeTrip}
			toggleSettings={toggleObj.toggleSettings}
			toggleSaveTrip={toggleObj.toggleSaveTrip}
			setDistances={props.setDistances}
			tour={props.tour}
			setTour={props.setTour}
			serverUrl={props.serverUrl}
		/>
	);
}
function buildAddPlace(props, toggleAddPlace, showAddPlace) {
	return (
		<AddPlace
			isOpen={showAddPlace}
			toggleAddPlace={toggleAddPlace}
			append={props.placeActions.append}
			foundPlaces={props.foundPlaces}
			setFoundPlaces={props.setFoundPlaces}
			serverUrl={props.serverUrl}
			earthRadius={props.earthRadius}
		/>
	);
}
function buildLoadTrip(props, toggleLoadTrip, showLoadTrip) {
	return (
		<LoadTrip
			isOpen={showLoadTrip}
			toggleLoadTrip={toggleLoadTrip}
			appendMultiple={props.placeActions.appendMultiple}
			serverUrl={props.serverUrl}
			distances={props.distances}
			setDistances={props.setDistances}
			earthRadius={props.earthRadius}
		/>
	);
}
function buildOptimizeTrip(props, toggleOptimizeTrip, showOptTrip) {
	return (
		<OptimizeTrip
			isOpen={showOptTrip}
			toggleOptimizeTrip={toggleOptimizeTrip}
			places={props.places}
			setPlaces = {props.setPlaces}
			placeActions={props.placeActions}
			selectedIndex={props.selectedIndex}
			distances={props.distances}
			setDistances={props.setDistances}
			tour = {props.tour}
			setTour = {props.setTour}
			serverUrl={props.serverUrl}
			earthRadius={props.earthRadius}	
		/>
	);
}
function buildSettings(props, toggleSettings, showSettings) {
	return (
		<Settings
			isOpen={showSettings}
			toggleSettings={toggleSettings}
			earthRadius={props.earthRadius}
			setEarthRadius={props.setEarthRadius}
			units={props.units}
			setUnits={props.setUnits}
			distances={props.distances}
			setDistances={props.setDistances}
			places={props.places}
			setPlaces = {props.setPlaces}
			serverUrl={props.serverUrl}
		/>
	);
}

function buildSaveTrip(props, toggleSaveTrip, showSaveTrip) {
	return (
		<SaveTrip
		places={props.places}
		distances={props.distances}
		earthRadius={props.earthRadius}
		isOpen={showSaveTrip}
		toggleSaveTrip={toggleSaveTrip}
		/>
	)

}

function PlaceList(props) {
	let totalDistance = calculateTotalDistance(props.distances);
	return (
		<React.Fragment>
			{buildPlaceRow(props)}
			<tfoot>
					<tr>
					<th className='total-distance-header'>Total Distance {totalDistance} {props.units}</th>
					</tr>
			</tfoot>
		</React.Fragment>
	);
}
function calculateTotalDistance(distances) {
	let totalDistance = 0;
	for (let i = 0; i < distances.length; i++) {
		totalDistance += distances[i];
	}
	return totalDistance;
}
function buildPlaceRow(props) {
	return (
		<tbody>
			{props.places.map((place, index) => (
				<PlaceRow
					key={`table-${JSON.stringify(place)}-${index}`}
					place={place}
					placeActions={props.placeActions}
					selectedIndex={props.selectedIndex}
					index={index}
					distances={props.distances}
					units={props.units}
					setUnits={props.setUnits}
				/>
			))}
		</tbody>
	);
}

function PlaceRow(props) {
	const [showFullName, toggleShowFullName] = useToggle(false);
	const name = props.place.defaultDisplayName;
	const location = latLngToText(placeToLatLng(props.place));
	let curCumulativeDistance = calculateCumulativeDistance(props.distances);
	return (
		<tr className={props.selectedIndex === props.index ? 'selected-row' : ''}>
			<td
				data-testid={`place-row-${props.index}`}
				onClick={() => placeRowClicked(toggleShowFullName, props.placeActions.selectIndex,props.index)}
			>
				{!showFullName ? name : props.place.formatPlace()}
				<AdditionalPlaceInfo showFullName={showFullName} location={location} />
				<div>Distance from last place: {props.distances[props.index]} {props.units}</div>
				<div>Cumulative Distance: {curCumulativeDistance[props.index]} {props.units}</div>
			</td>
			<td>
				<PlaceActionsDropdown
					placeActions={props.placeActions}
					index={props.index}
				/>
			</td>
		</tr>
	);
}
function calculateCumulativeDistance(distances) {
	let curDistanceSum = 0;
	let curCumulativeDistance = [];
	for (let i = 0; i < distances.length;i++) {
		curCumulativeDistance[i] = curDistanceSum;
		curDistanceSum +=distances[i];
	}
	return curCumulativeDistance;

}

function AdditionalPlaceInfo(props){
	return(
		<Collapse isOpen={props.showFullName}>
			{props.location}
		</Collapse>
	);
}

function placeRowClicked(toggleShowFullName, selectIndex, placeIndex){
    toggleShowFullName();
    selectIndex(placeIndex);
}