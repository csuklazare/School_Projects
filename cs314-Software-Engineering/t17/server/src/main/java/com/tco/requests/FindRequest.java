package com.tco.requests;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import com.tco.misc.SQLAccess;
import java.util.ArrayList;
import java.util.HashMap;
import com.tco.misc.SQLAccess.Place;
import com.tco.misc.SQLAccess.Places;


public class FindRequest extends Request {

    private static final transient Logger log = LoggerFactory.getLogger(FindRequest.class);

    private String match;
    private Integer limit;
    private Integer found;
    private Places places;
    private String[] type;
    private String[] where;

    @Override
    public void buildResponse() {
        buildFoundPlacesList();
        log.trace("buildResponse -> {}", this);
    }

    public void buildFoundPlacesList() {
        String useTunnel = System.getenv("CS314_USE_DATABASE_TUNNEL");
        String dburl = "";
        if (useTunnel != null && useTunnel.equals("true")) {
            dburl = "jdbc:mariadb://127.0.0.1:56247/cs314";
        }
        else {
            dburl = "jdbc:mariadb://faure.cs.colostate.edu/cs314";
        }
		try {
            if (type != null || where != null) {
                throw new Exception("type and where are not supported by the server!");
            }
            else {
			    SQLAccess.Credential.setUrl(dburl);
			    found = SQLAccess.Database.found(match);
			    places = SQLAccess.Database.places(match, limit);
            }
		} catch (Exception e) {
			System.err.println("Exception: " + e.getMessage());
		}
    }

        /* The following methods exist only for testing purposes and are not used
    during normal execution, including the constructor. */
    public FindRequest() {
        this.requestType = "find";
        this.places = new Places();
        this.match = "paco";
        this.limit = 10;
    }

    public int getNumFoundPlaces() {
        return this.found;
    }
    public String getFoundPlaces() {
        return this.places.toString();
    }
}
