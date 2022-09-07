package com.tco.misc;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;
import com.tco.misc.GreatCircleDistance;

public class NearestNeighbor {
    public List<Map<String,String>> places;
    public int[] tour;
    public Boolean[] visitedCities;
    public long[][] distanceMatrix;
    public int shortestTourLength = 0;
    public double earthRadius;
    public long responseTime;

    public NearestNeighbor(List<Map<String,String>> placesArr, double myRadius, double myResponse) {
        this.earthRadius = myRadius;
        this.places = placesArr;
        this.responseTime = (long) myResponse * 1000000000;

        this.distanceMatrix = new long[places.size()][places.size()];
        computeDistanceMatrix();
        
        this.tour = new int[places.size()];
        for(int i = 0; i < this.tour.length; ++i) {
            tour[i] = i;
            shortestTourLength += distanceMatrix[0][i];
        }

        this.visitedCities = new Boolean[places.size()];
        for(int i = 0; i < this.visitedCities.length; ++i) {
            visitedCities[i] = false;
        }

    }

    public void computeDistanceMatrix() {
        for (int i = 0; i < this.places.size(); i++) {
            for (int j = 0; j < this.places.size(); j++) {
                this.distanceMatrix[i][j] = GreatCircleDistance.calculate(Double.parseDouble(places.get(i).get("latitude")), Double.parseDouble(places.get(i).get("longitude")),
                                                       Double.parseDouble(places.get(j).get("latitude")), Double.parseDouble(places.get(j).get("longitude")), this.earthRadius);
            }
        }
    }

    public List<Map<String,String>> bestTrip() {
        long startTime = System.nanoTime();
        int[] shortestTour = tour.clone();

        for (int i = 0; i < places.size() - 1; i++) {
            int[] curTour = tour.clone();
            Boolean[] visited = visitedCities.clone();
            curTour[0] = i;
            visited[i] = true;

            int lastVisitedCity = i;
            int numVisited = 1;
            int curTourLength = 0;

            while (unvisitedCities(visited)) {
                int curShortest = -1;
                for(int x = 0; x < distanceMatrix.length; x++) {
                    if (visited[x] == false) {
                        curShortest = x;
                    }
                }

                curShortest = nearestCity(visited, curShortest, lastVisitedCity);

                curTour[numVisited] = curShortest;
                curTourLength += distanceMatrix[lastVisitedCity][curShortest];
                lastVisitedCity = curShortest;
                visited[lastVisitedCity] = true;
                numVisited++;

                if ((System.nanoTime() - startTime) >= responseTime) return places;
            }

            curTourLength += distanceMatrix[lastVisitedCity][i];
            if (curTourLength < shortestTourLength) {
                shortestTour = curTour;
                shortestTourLength = curTourLength;
            }

        }

        int theHead = findTheHead(shortestTour, 0);
        return createPlaceArrayFromTour(orderedBestTrip(shortestTour, theHead), places);
    }

    public ArrayList<Map<String,String>> createPlaceArrayFromTour(int[] tour, List<Map<String,String>> unoptPlaces) {
        ArrayList<Map<String,String>> optTour = new ArrayList<Map<String,String>> ();
        for(int i = 0; i < tour.length; ++i) {
            optTour.add(unoptPlaces.get(tour[i]));
        }
        return optTour;
    }
    
    public Boolean unvisitedCities(Boolean[] cities) {
        for (int i = 0; i < cities.length; i++) {
            if (cities[i] == false) return true;
        }
        return false;
    }

    public int nearestCity(Boolean[] cities, int shortest, int curCity) {
        for (int i = 0; i < distanceMatrix.length; i++) {
            if ((cities[i] == false) && (distanceMatrix[curCity][i] <= distanceMatrix[curCity][shortest])) {
                shortest = i;
            }
        }
        return shortest;
    }

    public int[] orderedBestTrip(int[] curTrip, int head) {
        int[] sortedArr = curTrip.clone();
        
        for (int i = head; i < curTrip.length; i++) {
            sortedArr[i - head] = curTrip[i];
        }
        for (int i = curTrip.length - head; i < curTrip.length; i++) {
            sortedArr[i] = curTrip[i + head - curTrip.length];
        }

        return sortedArr;
    }

    public int findTheHead(int[] curTrip, int head) {
        for (int i = 1; i < curTrip.length; i++) {
            if (curTrip[i] == 0) head = i;
        }
        
        return head;
    }
    
}

