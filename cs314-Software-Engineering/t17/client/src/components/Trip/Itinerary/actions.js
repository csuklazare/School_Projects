import React from 'react';
import { ButtonGroup, DropdownItem, DropdownMenu, DropdownToggle, UncontrolledDropdown } from 'reactstrap';
import { BiDotsVerticalRounded } from 'react-icons/bi';
import { FaCog, FaHome, FaPlus, FaTrash, FaTrashAlt, FaUpload, FaUserCog, FaMapMarkedAlt, FaSave } from 'react-icons/fa';
import { DEFAULT_STARTING_POSITION } from '../../../utils/constants';
import TourRequest from './TourRequest';

export function ItineraryActionsDropdown(props) {
    return (
        <ActionsDropdown {...props}>
            <DropdownItem onClick={() => props.placeActions.append(DEFAULT_STARTING_POSITION)} data-testid='home-button'>
                <FaHome />
            </DropdownItem>
            <DropdownItem disabled={props.disableRemoveAll} onClick={() => handleRemoveAll(props.placeActions.removeAll, props.setDistances)} data-testid='delete-all-button'>
                <FaTrashAlt />
            </DropdownItem>
            <DropdownItem onClick={() => props.toggleSaveTrip()} data-testid='save-button'>
                <FaSave />
            </DropdownItem>
            <DropdownItem onClick={() => props.toggleLoadTrip()} data-testid='load-trip-button'>
                <FaUpload />
            </DropdownItem>
            <DropdownItem onClick={() => props.toggleAddPlace()} data-testid='add-place-button'>
                <FaPlus />
            </DropdownItem>
            <DropdownItem onClick={() => props.toggleSettings()} data-testid='settings-button'>
                <FaUserCog />
            </DropdownItem>
            {<DropdownItem onClick={() => handleOptimize(props.places, props.setTour, props.toggleOptimizeTrip, props.serverUrl)} data-testid='optimize-button'>
                <FaMapMarkedAlt />
            </DropdownItem>}
        </ActionsDropdown>
    );
}

export function PlaceActionsDropdown(props) {
    return (
        <ActionsDropdown {...props}>
            <DropdownItem onClick={() => props.placeActions.removeAtIndex(props.index)} data-testid={`delete-button-${props.index}`}>
                <FaTrash />
            </DropdownItem>
        </ActionsDropdown>
    );
}

function ActionsDropdown(props) {
    return (
        <UncontrolledDropdown direction="left">
            <DropdownToggle tag="div" data-testid={`row-toggle-${props.index}`}>
                <BiDotsVerticalRounded size="1.5em" />
            </DropdownToggle>
            <DropdownMenu>
                <ButtonGroup>
                    {props.children}
                </ButtonGroup>
            </DropdownMenu>
        </UncontrolledDropdown>
    );
}

function handleRemoveAll(removeAll, setDistances) {
    removeAll();
    setDistances([]);
}

function handleOptimize(places, setTour, toggleOptimizeTrip) {
    setTour(places);
    toggleOptimizeTrip();
    
}