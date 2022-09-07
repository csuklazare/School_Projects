import { sendAPIRequest } from '../../../utils/restfulAPI';

export default function FindRequest(setFoundPlaces, nameString, serverUrl) {
    sendFindRequest(setFoundPlaces, nameString, serverUrl);
}
function processFindResponseSuccess(findResponse, setFoundPlaces) {
    setFoundPlaces(findResponse.places);
}

async function sendFindRequest(setFoundPlaces, nameString, serverUrl) {

    const findResponse = await sendAPIRequest( { requestType: "find", match: nameString, limit: 10}, serverUrl);
    if (findResponse) {
        processFindResponseSuccess(findResponse, setFoundPlaces);
    }
    else {
        setFoundPlaces(null);
        console.error(`Find request to ${serverUrl} failed. Check the log for more details.`, "error");
    }
}