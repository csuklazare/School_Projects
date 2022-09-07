import { useState } from 'react';
import { reverseGeocode } from '../utils/reverseGeocode';
import { LOG } from '../utils/constants';
import { Place } from '../models/place.model';
import DistancesRequest from '../components/Trip/Itinerary/DistancesRequest';
import { getOriginalServerUrl } from '../utils/restfulAPI';

export function usePlaces() {
    const [places, setPlaces] = useState([]);
    const [selectedIndex, setSelectedIndex] = useState(-1);
    const [distances, setDistances] = useState([]);
    const [foundPlaces, setFoundPlaces] = useState([]);
    const [tour, setTour] = useState([]);
    const [earthRadius, setEarthRadius] = useState(3959);

    const context = { places, setPlaces, selectedIndex, setSelectedIndex, distances, setDistances, foundPlaces, setFoundPlaces, tour, setTour, earthRadius, setEarthRadius };

    const placeActions = {
        append: async (place) => append(place, context, earthRadius),
        removeAtIndex: (index) => removeAtIndex(index, context),
        removeAll: () => removeAll(context),
        selectIndex: (index) => selectIndex(index, context),
        appendMultiple: (place) => appendMultiple(place, context),
    };

    return {places, setPlaces, selectedIndex, placeActions, distances, setDistances, earthRadius, setEarthRadius, foundPlaces, setFoundPlaces, tour, setTour};
}

async function append(latLng, context, earthRadius) {
    const { places, setPlaces, setSelectedIndex, setDistances } = context;

    const newPlaces = [...places];

    const fullPlace = await reverseGeocode(latLng);
    newPlaces.push(fullPlace);

    makeDistancesRequest(newPlaces, setDistances, earthRadius);

    setPlaces(newPlaces);
    setSelectedIndex(newPlaces.length - 1);
}
function appendMultiple(loadedPlace, context) {
    const { places, setPlaces, setSelectedIndex } = context;

    const fullPlace = new Place(loadedPlace);
    places.push(fullPlace);
    setSelectedIndex(places.length - 1);
}

function makeDistancesRequest(newPlaces, setDistances, earthRadius) {
    let serverUrl = getOriginalServerUrl();
    DistancesRequest(setDistances, newPlaces, serverUrl, earthRadius);
}

function removeAtIndex(index, context) {
    const { places, setPlaces, selectedIndex, setSelectedIndex, distances, setDistances } = context;

    if (index < 0 || index >= places.length) {
        LOG.error(`Attempted to remove index ${index} in places list of size ${places.length}.`);
        return;
    }
    const newPlaces = places.filter((place, i) => index !== i);
    const newDistances = distances?.filter((distance, i) => index !== i);
    setDistances(newDistances);
    setPlaces(newPlaces);

    if (newPlaces.length === 0) {
        setSelectedIndex(-1);
    } else if (selectedIndex >= index && selectedIndex !== 0) {
        setSelectedIndex(selectedIndex - 1);
    }
}

function removeAll(context) {
    const { setPlaces, setSelectedIndex } = context;

    setPlaces([]);
    setSelectedIndex(-1);
}

function selectIndex(index, context) {
    const { places, setSelectedIndex } = context;

    if (index < -1 || index >= places.length) {
        LOG.error(`Attempted to select index ${index} in places list of size ${places.length}.`);
        setSelectedIndex(-1);
        return;
    }
    setSelectedIndex(index);
}