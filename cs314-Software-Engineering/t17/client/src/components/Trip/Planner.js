import React, { useState } from 'react';
import { Col, Container, Row } from 'reactstrap';
import Map from './Map/Map';
import Itinerary from './Itinerary/Itinerary';
import { usePlaces } from '../../hooks/usePlaces';


export default function Planner(props) {
    const {places, setPlaces, selectedIndex, placeActions, distances, setDistances, earthRadius, setEarthRadius, foundPlaces, setFoundPlaces, tour, setTour} = usePlaces();
    const [units, setUnits] = useState('miles'); 
    const plannerObj = {places, setPlaces, selectedIndex, placeActions, distances, setDistances, earthRadius, setEarthRadius, foundPlaces, setFoundPlaces, tour, setTour, units, setUnits};
    return (
        <Container>
            <Section>
                {buildMap(plannerObj)}
            </Section>
            <Section>
                {buildItinerary(plannerObj, props.serverUrl)}
            </Section>
        </Container>
    );
}
function buildMap(plannerObj) {
    return (
        <Map
        places={plannerObj.places}
        selectedIndex={plannerObj.selectedIndex}
        placeActions={plannerObj.placeActions}
        distances={plannerObj.distances}
        setDistances={plannerObj.setDistances}
        />
    );
}
function buildItinerary(plannerObj, serverUrl) {
    return (
        <Itinerary
            places={plannerObj.places}
            setPlaces={plannerObj.setPlaces}
            selectedIndex={plannerObj.selectedIndex}
            placeActions={plannerObj.placeActions}
            serverUrl={serverUrl}
            distances={plannerObj.distances}
            setDistances={plannerObj.setDistances}
            foundPlaces={plannerObj.foundPlaces}
            setFoundPlaces={plannerObj.setFoundPlaces}
            tour={plannerObj.tour}
            setTour={plannerObj.setTour}
            earthRadius={plannerObj.earthRadius}
            setEarthRadius={plannerObj.setEarthRadius}
            units={plannerObj.units}
            setUnits={plannerObj.setUnits}
        />
    );
}

function Section(props) {
    return (
        <Row>
            <Col sm={12} md={{ size: 10, offset: 1 }}>
                {props.children}
            </Col>
        </Row>
    );
}