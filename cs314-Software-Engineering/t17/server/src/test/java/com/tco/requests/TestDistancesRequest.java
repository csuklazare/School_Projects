package com.tco.requests;

import java.util.List;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class TestDistancesRequest {

    private DistancesRequest request;
    private List<Integer> distances;

    @BeforeEach
    public void createDistancesForTestCases() {
        request = new DistancesRequest();
        request.buildResponse();
    }

    @Test
    @DisplayName("zypher: Request type is \"distances\"")
    public void testType() {
        String type = request.getRequestType();
        assertEquals("distances", type);
    }

    @Test
    @DisplayName("tschroe: distance request has two places")
    public void testEmptyPlaces() {
        request.buildResponse();
        distances = request.getDistancesArray();
        assertEquals(2, distances.size());

    }

}