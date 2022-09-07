import React from 'react';
import { beforeEach, describe, expect, it, jest } from '@jest/globals';
import { render} from '@testing-library/react';
import {act, renderHook} from '@testing-library/react-hooks';
import FileLoaderApp from '../../../src/components/Trip/Itinerary/FileLoaderApp';
import goodFileJSON from '../../test.files/json/good.test.json';
import useFileReader from '../../../src/hooks/useFileReader';

describe('FileLoaderApp', () => {

	const props = {
		handleFileUpload: jest.fn(),
	}
	
	let hook;
	beforeEach(() => {
		const { result } = renderHook(() => useFileReader());
		render(
			<FileLoaderApp
				file={result.file}
				readFile={result.readFile}
			/>
		);
		
		hook=result;
	});

	it('fisher25: checks if no file has been loaded in', () => {
			expect(hook.current.file).toEqual(null)
	});
	it('fisher25: checks if file is valid', () => {
		act(() => {
			hook.current.setFile(goodFileJSON);
		});
		expect(!!hook.current.file);
	});
	// it('base: simulates uploading file', () => {
	// 	const fileUpload = screen.getByTestId('loaded-file');
	// 	act(() => {
	// 		user.upload(fileUpload, goodFileJSON);
	// 	});
	// 	console.log(hook.current.file);
	// 	expect(hook.current.file).toEqual("good.test.json");
	// }
	// )
});
