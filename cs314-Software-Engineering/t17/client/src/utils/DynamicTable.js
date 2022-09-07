import React from 'react';
import { Table, Button } from 'reactstrap';
import Coordinates from 'coordinate-parser';
import { reverseGeocode } from './reverseGeocode';


function DynamicTable(props){

if (props.currentPlaces.length == 0) {
    return (
        <div>
        </div>
    );
}
return (
    <Table className="table">
        <thead>
            <tr>
                <th>Found Places:</th>
            </tr>
        </thead>
        <tbody>
            {tdData(props, props.currentPlaces)}
        </tbody>
    </Table>
);
}
function tdData(props, currentPlaces) {
    return currentPlaces.map((placeEntry, index) =>{
        return(
            <tr key={index}>
                <td>{placeEntry}</td>
                <td>
                    <Button
                        color = 'primary'
                        onClick={()=> {
                                addPlaceEntry(props, index);
                        }}
                        data-testid='Add-To-Trip-Button'
                        >
                            Add
                    </Button>
                </td>
            </tr>
        )
    })
}
async function addPlaceEntry(props, index) {
    let coordString = props.foundPlaces[index].latitude + " " + props.foundPlaces[index].longitude;

    try {
		const latLngPlace = new Coordinates(coordString);
		const lat = latLngPlace.getLatitude();
		const lng = latLngPlace.getLongitude();
		if (lat !== undefined && lng !== undefined) {
			const fullPlace = await reverseGeocode({ lat, lng });
			props.append(fullPlace);
		}
	} catch (error) {
		LOG.error(`Failed to add Found Place : ${err}`);
	}
}

export default DynamicTable;