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
    Container,
} from 'reactstrap';

export default function SaveTrip(props) {
    const MIME_TYPE = {
        JSON: "application/json",
        CSV: "text/csv",
        SVG: "image/svg+xml",
        KML: "application/vnd.google-earth.kml+xml"
      };
      const [tripName, setTripName] = useState('My Trip');
      const [fileType, setFileType] = useState('.json');
      const saveTripObj = {tripName, setTripName, fileType, setFileType}
    return (
        <Modal isOpen={props.isOpen} toggle={props.toggleSaveTrip}>
            <SaveTripHeader toggleSaveTrip={props.toggleSaveTrip}
            />
            <SaveTripBody saveTripObj={saveTripObj}
            />
            <SaveTripFooter 
              MIME_TYPE = {MIME_TYPE}
              saveTripObj={saveTripObj}
              places = {props.places}
              distances = {props.distances}
              earthRadius = {props.earthRadius}
              toggleSaveTrip = {props.toggleSaveTrip}
            />
        </Modal>
    );
}
function SaveTripHeader(props) {
	return (
		<ModalHeader className='ml-2' toggle={props.toggleSaveTrip}>
			Save Your Trip
		</ModalHeader>
	);

}

function SaveTripBody(props) {
    return (
        <ModalBody>
        <div>
        Select a File Format
        <Col>
        <input onChange = {(input) => props.saveTripObj.setFileType(input.target.value)} type="radio" value=".json" name="fileType" defaultChecked /> .json
        </Col>
        <Col>
        <input onChange = {(input) => props.saveTripObj.setFileType(input.target.value)} type="radio" value=".csv" name="fileType" /> .csv
        </Col>
        </div>
        Trip Name
        <Input
				onChange={(input) => props.saveTripObj.setTripName(input.target.value)}
				placeholder='My Trip'
				data-testid='tripName-input'
				value={props.saveTripObj.tripName}
				/>
        </ModalBody>
    
    )
}

function SaveTripFooter(props) {
    return (
        <ModalFooter>
            <Button
				color='primary'
				onClick={() => props.toggleSaveTrip()}
				data-testid='Close-SaveTrip-button'
			>
				Cancel
			</Button>
            <Button
				color='primary'
				onClick={() => FileSavingApp(props)}
				data-testid='SaveTrip-button'
			>
				Save
			</Button>
        </ModalFooter>
    )
}

function FileSavingApp(props) {


      const tripJSON = buildTripJSON(props);
      const fileName = props.saveTripObj.tripName.replace(/ /g, "_").toLowerCase();
      downloadFile(fileName + props.saveTripObj.fileType.toString(), props.MIME_TYPE.JSON, tripJSON);
    
  }

  function downloadFile(fileNameWithExtension, mimeType, fileText) {
    const file = new Blob([fileText], { type: mimeType });
    const link = document.createElement("a");
    const url = URL.createObjectURL(file);
    link.href = url;
    link.download = fileNameWithExtension;
    document.body.appendChild(link);
    link.click();
    setTimeout(function() {
      document.body.removeChild(link);
      window.URL.revokeObjectURL(url);
    }, 0);
  }
  
  
  function buildTripJSON(props) {
    const tripJSON = {
      earthRadius: props.earthRadius,
      units: "km",
      places: props.places,
      distances: props.distances 
    };
    
    return JSON.stringify(tripJSON, null, 2);
  }
  
  