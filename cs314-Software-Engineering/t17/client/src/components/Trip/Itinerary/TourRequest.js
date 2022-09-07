import { sendAPIRequest } from '../../../utils/restfulAPI';
import { Place } from '../../../models/place.model';

export default function TourRequest(setTour, places, serverUrl) {
    sendTourRequest(setTour, places, serverUrl);
}
function processTourResponseSuccess(tourResponse, setTour) {
    const newPlaces = [];
	for (let i = 0; i < tourResponse.places.length; i++) {
		const newPlace = new Place(tourResponse.places[i]);
    	newPlaces.push(newPlace);
	}
    setTour(newPlaces);
}

async function sendTourRequest(setTour, places, serverUrl) {

    const tourResponse = await sendAPIRequest( { requestType: "tour", earthRadius: 3959.0, response: 1.0, places: places}, serverUrl);
    if (tourResponse) {
        processTourResponseSuccess(tourResponse, setTour);
    }
    else {
        setTour(null);
        console.error(`Tour request to ${serverUrl} failed. Check the log for more details.`, "error");
    }
}