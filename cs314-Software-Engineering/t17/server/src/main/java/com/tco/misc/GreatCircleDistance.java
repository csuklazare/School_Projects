package com.tco.misc;

import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Type;
import java.lang.Math;
import org.everit.json.schema.SchemaException;
import org.everit.json.schema.Schema;
import org.everit.json.schema.loader.SchemaLoader;
import org.everit.json.schema.ValidationException;

import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONTokener;

public final class GreatCircleDistance {

    private GreatCircleDistance() {}

    public static long calculate(double latitude1, double longitude1, double latitude2, double longitude2, double earthRadius) {

        long distance = 0; 

        double lambda1 = longitude1 * Math.PI/180;
        double lambda2 = longitude2 * Math.PI/180;
        double theta1 = latitude1 * Math.PI/180;
        double theta2 = latitude2 * Math.PI/180;

        double deltaLambda = Math.abs(lambda1 - lambda2);
        double deltaTheta = Math.abs(theta1 - theta2);

        double arclengthNumerator = Math.sqrt(Math.pow(Math.cos(theta2) * Math.sin(deltaLambda), 2) + Math.pow((Math.cos(theta1) * Math.sin(theta2) - (Math.sin(theta1) * Math.cos(theta2) * Math.cos(deltaLambda))), 2));
        double arclengthDenominator = (Math.sin(theta1) * Math.sin(theta2)) + (Math.cos(theta1) * Math.cos(theta2) * Math.cos(deltaLambda));
        double arclength = Math.atan2(arclengthNumerator, arclengthDenominator);

        distance = (long) (arclength * earthRadius);

        return distance; 

    }

}