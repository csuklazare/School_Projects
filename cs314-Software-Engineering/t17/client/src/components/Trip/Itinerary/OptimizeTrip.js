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

import Map from '../Map/Map';
import TourRequest from './TourRequest';
import DistanceRequest from './DistancesRequest';

export default function OptimizeTrip(props) {
	
	return (
		<Modal isOpen={props.isOpen} toggle={props.toggleOptimizeTrip} onClosed={()=> props.setTour([])}>
			<OptimizeTripHeader toggleOptimizeTrip={props.toggleOptimizeTrip} />
            <Map
				places={props.tour}
				placeActions={props.placeActions}
				selectedIndex={0}
				distances={props.distances}
				setDistances={props.setDistances}
            />
            <OptimizeTripFooter
				places={props.places}
				serverUrl={props.serverUrl}
				tour={props.tour}
				setTour={props.setTour}
				setPlaces={props.setPlaces}
				distances={props.distances}
				toggleOptimizeTrip={props.toggleOptimizeTrip}
				earthRadius={props.earthRadius}
				setDistances={props.setDistances}
			/>
		</Modal>
	);
}

function OptimizeTripHeader(props) {
	return (
		<ModalHeader className='ml-2' toggle={props.toggleOptimizeTrip}>
			Optimize A Trip
		</ModalHeader>
	);
}

function OptimizeTripFooter(props) {
	return (
		<ModalFooter>
			<Button
				color='primary'
				onClick={() => handleOptimize(props.setTour, props.places, props.serverUrl)}
				data-testid='Optimize-button'
			>
				Optimize My Trip
			</Button>
			<Button
			color='primary'
			onClick={() => confirmOptimize(props)}
			data-testid='Use-Opt-Trip-Button'
			>
				Use Optimized Trip
			</Button>
		</ModalFooter>
	);
}
function handleOptimize(setTour, places, serverUrl) {
	TourRequest(setTour, places, serverUrl);

}
function confirmOptimize(props) {
	props.setPlaces(props.tour);
	DistanceRequest(props.setDistances, props.tour, props.serverUrl, props.earthRadius);
	props.toggleOptimizeTrip();
}