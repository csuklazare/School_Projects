package com.tco.requests;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class TestFindRequest {

    private FindRequest find;

    @BeforeEach
    public void createFindForTestCases() {
        find = new FindRequest();
        find.buildResponse();
    }

    @Test
    @DisplayName("zypher: Request type is \"find\"")
    public void testType() {
        String type = find.getRequestType();
        assertEquals("find", type);
    }

    @Test
    @DisplayName("fisher25: simulate a search query that finds 4 places")
    public void testNumFoundPlace() {
        Integer numPlaces = find.getNumFoundPlaces();
        assertTrue(numPlaces == 6);
    }

    @Test
    @DisplayName("fisher25: simulate a search query and return the places found")
    public void testReturnFoundPlaces() {
        String placesShouldEqual = "[{country=United States, altitude=2039, latitude=34.33359909057617, name=Pacoima Dam Heliport, municipality=Los Angeles, index=1, id=CN47, region=California, longitude=-118.39700317382812}, {country=Honduras, altitude=645, latitude=14.07361125946045, name=Rapaco II Airport, municipality=null, index=2, id=MHRA, region=El Paraiso, longitude=-86.91000366210938}, {country=Mexico, altitude=5019, latitude=20.308378, name=Paco Airport, municipality=Chapala, index=3, id=MX-0190, region=Jalisco, longitude=-103.159506}, {country=United States, altitude=960, latitude=34.258782, name=Barton Heliport, municipality=Pacoima, index=4, id=PAI, region=California, longitude=-118.40785}, {country=Colombia, altitude=549, latitude=0.066667, name=Pacoa Airport, municipality=Pacoa, index=5, id=SK-484, region=Vaupés Department, longitude=-71.208333}, {country=Brazil, altitude=154, latitude=-2.52097, name=Coronel Alexandre Raposo Airport, municipality=Paço Do Lumiar, index=6, id=SNOZ, region=Maranhão, longitude=-44.1213}]";
        String returnedPlaces = find.getFoundPlaces();
        assertTrue(placesShouldEqual.equals(returnedPlaces));
    }

}