package com.tco.requests;

import java.util.List;
import java.util.ArrayList;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Map;
import java.util.HashMap;

import com.tco.misc.NearestNeighbor;


public class TourRequest extends Request {

    private static final transient Logger log = LoggerFactory.getLogger(TourRequest.class);

    // local variables initialize here
    private List<Map<String,String>> places = new ArrayList<> ();
    private double earthRadius;
    private double response;

    public TourRequest() {
        //Below is for testing purposes ONLY
        this.requestType = "tour";
        this.earthRadius = 6371.0;
        this.response = 1; 
        this.places = new ArrayList<Map<String,String>>(); 
        HashMap<String,String> place1 = new HashMap<String,String>();
        HashMap<String,String> place2 = new HashMap<String,String>();
        HashMap<String,String> place3 = new HashMap<String,String>(); 
        place1.put("name", "testPlace");
        place1.put("latitude", "30");
        place1.put("longitude", "20");
        place2.put("name", "testPlace2");
        place2.put("latitude", "10");
        place2.put("longitude", "0");
        place3.put("name", "testPlace3");
        place3.put("latitude","50");
        place3.put("longitude", "40");
        this.places.add(place1);
        this.places.add(place2);
        this.places.add(place3);
        }

    @Override
    public void buildResponse() {
        this.requestType = "tour";
        buildTourList();
        log.trace("buildResponse -> {}", this);
    }

    public void buildTourList() {
        NearestNeighbor opt = new NearestNeighbor(this.places, this.earthRadius, this.response);
        this.places = opt.bestTrip();
    }

        public List getPlaces() {
            return this.places; 
        }
}
