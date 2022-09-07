package com.tco.requests;

import java.util.List;
import java.util.ArrayList;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Map;
import java.util.HashMap;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import com.tco.misc.NearestNeighbor;

public class TestTourRequest {

    private TourRequest tour;

    @BeforeEach
    public void createTourForTestCases() {
        tour = new TourRequest();
        tour.buildResponse();
    }

    @Test
    @DisplayName("zypher: Request type is \"tour\"")
    public void testType() {
        String type = tour.getRequestType();
        assertEquals("tour", type);
    }

    @Test
    @DisplayName("zypher: check start city is the same after optimizing")
    public void testPlaces() {
        tour = new TourRequest();
        List<Map<String,String>> places = tour.getPlaces(); 
        String startPlace = places.get(0).get("name");

        NearestNeighbor opt = new NearestNeighbor(places, 3959.0, 1);
        places = opt.bestTrip();
        String returnedStartPlace = places.get(0).get("name");

        assertEquals(startPlace, returnedStartPlace);
    }


}