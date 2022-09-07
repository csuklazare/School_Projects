import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Arrays;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;

import static org.junit.jupiter.api.Assertions.*;
import com.tco.misc.NearestNeighbor;

public class TestNearestNeighbor {
    
    private List<Map<String,String>> testPlaces;
    private NearestNeighbor nn;
    

    @BeforeEach
    private void createTestObjects() {
        this.testPlaces = new ArrayList<Map<String,String>>();
        HashMap<String,String> Inuvik = new HashMap<String,String>();
        HashMap<String,String> Dehcho = new HashMap<String,String>();
        HashMap<String,String> Yukon = new HashMap<String,String>();
        HashMap<String,String> Sahtu = new HashMap<String,String>();
        HashMap<String,String> Slave = new HashMap<String,String>();
        HashMap<String,String> GWICH = new HashMap<String,String>();
        Inuvik.put("latitude", "69.18");
        Inuvik.put("longitude", "-129.02");
        Dehcho.put("latitude", "61.32");
        Dehcho.put("longitude", "-123.22");
        Yukon.put("latitude", "65.01");
        Yukon.put("longitude", "-137.20");
        Sahtu.put("latitude", "66.24");
        Sahtu.put("longitude", "-117.77");
        Slave.put("latitude", "63.24");
        Slave.put("longitude", "-118.30");
        GWICH.put("latitude", "67.35");
        GWICH.put("longitude", "-133.86");
        this.testPlaces.add(Inuvik);
        this.testPlaces.add(Dehcho);
        this.testPlaces.add(Yukon);
        this.testPlaces.add(Sahtu);
        this.testPlaces.add(Slave);
        this.testPlaces.add(GWICH);
        this.nn = new NearestNeighbor(testPlaces, 3950.0, 1);
    }

    @Test
    @DisplayName("tschroe: nearest neighbor initializes own copy of places array")
    public void testNNPlacesArr() {
        assertEquals(6, nn.places.size());
    }

    @Test
    @DisplayName("tschroe: tour array is proper size")
    public void testTourArraySize() {
        assertEquals(6, nn.tour.length);
    }
    
    @Test
    @DisplayName("tschroe: unvisited cities is initialized to false")
    public void testVisitedIsFalse () {
        for(Boolean i : nn.visitedCities){
            assertEquals(false, i);
        }
    }

    @Test
    @DisplayName("tschroe: distanceMatrix is correct size")
    public void testDistanceMatrixSize() {
        assertEquals(nn.distanceMatrix.length, 6);
        for(long[] i : nn.distanceMatrix) {
            assertEquals(6, i.length);
        }
    }

    @Test
    @DisplayName("henocky: distanceMatrix populated correctly")
    public void testDistanceMatrixValues() {
        assertEquals(502, nn.distanceMatrix[1][2]);
        assertEquals(nn.distanceMatrix[0][0], 0);
    }

    @Test
    @DisplayName("tschroe: places list returned as optimized")
    public void testOptimizedPlacesList() {
        String[] testOptPlaces = {"69.18", "67.35", "65.01", "61.32", "63.24", "66.24"};
        this.testPlaces = nn.bestTrip();

        for(int i = 0; i < testOptPlaces.length; ++i) {
            assertEquals(testOptPlaces[i], this.testPlaces.get(i).get("latitude"));
        }
    }

    @Test
    @DisplayName("henocky: orderedBestTrip starts at specified index")
    public void testOrderedBestTrip() {
        int[] test = {0, 1, 2, 3, 4, 5, 6, 7};
        int startingIndex = 4;
        int[] expected = {4, 5, 6, 7, 0, 1, 2, 3};

        assertArrayEquals(expected, nn.orderedBestTrip(test, startingIndex));
    }

}
