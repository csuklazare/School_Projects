 package com.tco.requests;

import java.util.List;
import java.util.ArrayList;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.util.Map;
import java.util.HashMap;
import com.tco.misc.GreatCircleDistance;

public class DistancesRequest extends Request {

    private static final transient Logger log = LoggerFactory.getLogger(DistancesRequest.class);

    private Double earthRadius;
    private List<Map<String,String>> places;
    private List<Long> distances;

    @Override
    public void buildResponse() {
        buildDistancesList();
        log.trace("buildResponse -> {}", this);
    }

    public List getDistancesArray() {
        return distances;
    }

    private void buildDistancesList() {
        distances = new ArrayList<Long>();

        for (int i = 0; i < places.size(); i++) {
            Double lat1 = Double.parseDouble(places.get(i).get("latitude"));
            Double lng1 = Double.parseDouble(places.get(i).get("longitude"));
            Double lat2;
            Double lng2;
            if (places.size() - 1 == i) {
                lat2 = Double.parseDouble(places.get(0).get("latitude"));
                lng2 = Double.parseDouble(places.get(0).get("longitude"));
            }
            else {
                lat2 = Double.parseDouble(places.get(i+1).get("latitude"));
                lng2 = Double.parseDouble(places.get(i+1).get("longitude"));
            }
            distances.add(GreatCircleDistance.calculate(lat1, lng1, lat2, lng2, earthRadius));
        }
    }

    /* The following methods exist only for testing purposes and are not used
    during normal execution, including the constructor. */

    public DistancesRequest() {
        this.requestType = "distances";
        this.places = new ArrayList<Map<String,String>>();
        HashMap<String,String> place1 = new HashMap<String,String>();
        HashMap<String,String> place2 = new HashMap<String,String>();
        place1.put("name", "testPlace");
        place1.put("latitude", "30");
        place1.put("longitude", "20");
        place2.put("name", "testPlace2");
        place2.put("latitude", "10");
        place2.put("longitude", "0");
        this.earthRadius = 6371.0;
        this.places.add(place1);
        this.places.add(place2);
    }
    

}
