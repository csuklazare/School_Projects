import React from 'react';
import {
	Input,
	Container,
} from 'reactstrap';
/*************************************************
 * Title: <Loading a File>
 * Author: <@csucs314>
 * Date: <N/A>
 * Code version: <1>
 * Availability: <https://codepen.io/csucs314/pen/ExvxmpR>
 *************************************************/

 const FILE_FORMATS = ".json, .csv, application/json, text/csv";

 export default function FileLoaderApp(props) {
	
	function handleFileUpload(event) {
	  const fileName = event.target.files[0].name;
	  const fileObject = event.target.files[0];
	  props.readFile(fileName, fileObject)
	}
	
	return (
	  <Container>
		<h3 className="font-weight-bold mt-4">Select a JSON file.</h3>
		<Input 
			type="file"
			accept={FILE_FORMATS}
			onChange={handleFileUpload}
			data-testid='loaded-file'
		/>
		<FileDisplay
		file={props.file}
		/>
	  </Container>
	);
  }
  
  function FileDisplay(props) {
	if (!!props.file?.error)
	  return (
		  <h5> Invalid JSON format. Please check the file you have picked.</h5>
	  );
	
	 return (
	  <div>
	  </div>
	 );
  }