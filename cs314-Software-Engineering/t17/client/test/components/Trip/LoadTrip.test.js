import React from 'react';
import { beforeEach, describe, expect, it, jest } from '@jest/globals';
import { render, screen, waitFor } from '@testing-library/react';
import {act, renderHook} from '@testing-library/react-hooks';
import LoadTrip from '../../../src/components/Trip/Itinerary/LoadTrip';
import goodFileJSON from '../../test.files/json/good.test.json';
import useFileReader from '../../../src/hooks/useFileReader';

describe('LoadTrip', () => {

	const props = {
		toggleLoadTrip: jest.fn(),
		appendMultiple: jest.fn(),
		isOpen: true,
		
	};
	let hook;
	beforeEach(() => {
		render(
			<LoadTrip
				appendMultiple={props.appendMultiple}
				isOpen={props.isOpen}
				toggleLoadTrip={props.toggleLoadTrip}
			/>
		);
		const { result } = renderHook(() => useFileReader());
		hook=result;
	});

	it('fisher25: checks if it has no file', () => {
		expect(hook.current.file).toEqual(null);
		const uploadButton = screen.getByTestId('load-trip-button');
		expect(uploadButton.classList.contains('disabled')).toBe(true);
	});
	it('fisher25: checks if it has a file', () => {
		act(() => {
			hook.current.setFile(goodFileJSON);
		});
		expect(!!props.file?.error || !props.file);
		
	});
});
