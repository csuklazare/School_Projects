import { sendAPIRequest } from '../../../utils/restfulAPI';

export default function DistancesRequest(setDistances, file, serverUrl, earthRadius) {
    sendDistanceRequest(setDistances, file, serverUrl, earthRadius);

}
function processDistanceResponseSuccess(distanceResponse, setDistances) {
	setDistances(distanceResponse.distances);
    
}

async function sendDistanceRequest(setDistances, file, serverUrl, earthRadius) { 

    const distanceResponse = await sendAPIRequest({ requestType: "distances", "places": file, "earthRadius": earthRadius}, serverUrl);
    if (distanceResponse) {
        processDistanceResponseSuccess(distanceResponse, setDistances);
    } else {
        setDistances(null);
        console.error(`Distances request to ${serverUrl} failed. Check the log for more details.`, "error");
    }
}

