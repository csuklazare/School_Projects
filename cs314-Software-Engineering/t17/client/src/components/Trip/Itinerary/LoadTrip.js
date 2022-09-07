import React from 'react';
import {
	Button,
	Modal,
	ModalHeader,
	ModalFooter,
} from 'reactstrap';
import useFileReader from '../../../hooks/useFileReader';
import FileLoaderApp from './FileLoaderApp';
import DistancesRequest from './DistancesRequest';

export default function LoadTrip(props) {
	const { file, setFile, readFile } = useFileReader();

    return (
        <Modal data-testid='load-file' onClosed={()=> setFile(null)} isOpen={props.isOpen} toggle={props.toggleLoadTrip}>
            <LoadTripHeader
				/>
            <FileLoaderApp
				file={file}
				readFile={readFile}
			/>
            <LoadTripFooter
				toggleLoadTrip={props.toggleLoadTrip}
				appendMultiple={props.appendMultiple}
				file={file}
				isOpen={props.isOpen}
				serverUrl={props.serverUrl}
				setDistances={props.setDistances}
				earthRadius={props.earthRadius}
			/>
        </Modal>
    );
}
function LoadTripHeader() {
	return (
		<ModalHeader className='ml-2'>
			Load a Trip
		</ModalHeader>
	);
}
function LoadTripFooter(props) {
	return (
		<ModalFooter>
			<Button
				color='primary'
				onClick={() =>
					loadTripInMap(props)
				}
				data-testid='load-trip-button'
				disabled={!!props.file?.error || !props.file}
			>
				Upload
			</Button>
			<Button
				color='primary'
				onClick={() => 
					props.toggleLoadTrip()
				}
				data-testid='cancel-trip-button'
			>
				Cancel
			</Button>
		</ModalFooter>
	);
}
function loadTripInMap(props) {
	if (props.file.ext === "json") {
	 	const {places: fileData} = JSON.parse(props.file.text);
		for (let i = 0; i < fileData.length; i++) {
			props.appendMultiple(fileData[i]);
		}
		props.toggleLoadTrip();
		DistancesRequest(props.setDistances, fileData, props.serverUrl, props.earthRadius);
		
	} else {
		console.log("Uploaded file must be JSON");
   }
}
