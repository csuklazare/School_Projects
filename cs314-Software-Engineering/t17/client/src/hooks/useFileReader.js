import { useState } from 'react';
import tripFileSchema from '../../schemas/TripFile';
import { isJsonResponseValid } from '../utils/restfulAPI';
/*************************************************
 * Title: <Loading a File>
 * Author: <@csucs314>
 * Date: <N/A>
 * Code version: <1>
 * Availability: <https://codepen.io/csucs314/pen/ExvxmpR>
 *************************************************/

export default function useFileReader() {
	const [file, setFile] = useState(null);
	
	function readFile(fileName, fileObject) {
	  const reader = new FileReader();
	  reader.readAsText(fileObject, "UTF-8");
	  reader.onload = event => {
		const file = { name: fileName, text: event.target.result, ext: "" };
		parseFile(file, setFile);
	  };
	}
	return { file, setFile, readFile };
}
	
function parseFile(file, setFile) {
	const extension = file.name.split('.').pop();
	if (extension === "json") {
		file.ext = "json";
		try {
			if (isJsonResponseValid(JSON.parse(file.text), tripFileSchema)) {
				setFile(file);
				return file.text;
			}
		}
		catch (error) {
			setFile({error: "Invalid File"});
		}
	} else {
		setFile({error: "Invalid File"});
	}
}