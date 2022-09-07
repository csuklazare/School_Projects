package com.tco.misc;

import com.tco.requests.ConfigRequest;

import java.lang.reflect.Type;

import org.everit.json.schema.SchemaException;
import org.everit.json.schema.loader.SchemaLoader;
import org.json.JSONObject;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.DisplayName;
import org.mockito.MockedStatic;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

public class TestGreatCircleDistance {

    private void test(double expected, double lat1, double lat2, double lon1, double lon2, double earthRadius) {
        assertEquals(expected, GreatCircleDistance.calculate(lat1, lat2, lon1, lon2, earthRadius));
    }

    @Test
    @DisplayName("zypher: Test GCD gives 0 with all inputs 0")
    public void testGCDWithAllZeroInput() {    
        test(0, 0, 0, 0, 0, 0);
    }

    @Test
    @DisplayName("zypher: Test GCD gives 7382 from Alaska Zoo to Dom Treasury w/ standard EarthRadius")
    public void testGCDAlaskaToTreasuryStandardRadius() {    
        test(7381, 61.14, -149.79, 50.94, 6.96, 6371.0);
    }

    @Test
    @DisplayName("travpark: Test GCD gives 20015 from North Pole to South Pole w/ standard EarthRadius")
    public void testGCDNorthPoleToSouthPole() {
        test(20015, 90.0, 0, -90.0, 0, 6371.0);
    }
    
    @Test
    @DisplayName("amwaddle: Test GCD gives 1124 from Colorado State University to AT&T Stadium w/ standard earthRadius")
    public void testGCDWithAllOneInputs() {
        test(1124, 40.57, -105.08, 32.74, -97.09, 6371.0);
    }

    @Test
    @DisplayName("henocky: Test GCD gives 10650 from Alaska Zoo to Dom Treasury w/ standard EarthRadius")
    public void testGCDExploratoriumToGoldenGateKyiv() {
        test(9851, 50.44, 30.52, 37.8, -122.4, 6371.0);
    }
    
}