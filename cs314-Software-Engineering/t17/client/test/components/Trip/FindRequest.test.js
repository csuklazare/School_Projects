import React from 'react';
import { beforeEach, describe, expect, it, jest } from '@jest/globals';
import { render, screen, waitFor } from '@testing-library/react';
import PlaceSearch from '../../../src/components/Trip/Itinerary/AddPlace';
import FindRequest from '../../../src/components/Trip/Itinerary/FindRequest';
import sendFindRequest from '../../../src/components/Trip/Itinerary/FindRequest';
import { useState } from 'react';

describe('findRequest', () => {
    //const [foundPlaces, setFoundPlaces] = useState([]);
    const props = {
        foundPlaces: [],
        nameString: 'Alaska',
        serverUrlFaure: "jdbc:mariadb://faure.cs.colostate.edu/cs314",
        serverUrlTunnel: "jdbc:mariadb://127.0.0.1:56247/cs314",
    };

    beforeEach(() => {
        render(
            <PlaceSearch
                 foundPlaces={props.foundPlaces}
                 nameString={props.nameString}
                 serverUrlFaure={props.serverUrlFaure}
                 serverUrlTunnel={props.serverUrlTunnel}           
            />
        );
    });

    it ('zypher: validates find response with Faure', async () => {
        let request = await sendFindRequest(props.foundPlaces, props.nameString, props.serverUrlFaure);
        expect(request).not.toBe(null);
    })
    it ('zypher: validates find response with Tunnel', async () => {
        let request = FindRequest(props.setFoundPlaces, props.nameString, props.serverUrlTunnel);
        expect(request).not.toBe(null);
    })


})