package com.tco.misc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.HashMap;
import java.lang.Exception;

public class SQLAccess {
    private final static String TABLE = "world";
	private final static String COLUMNS = "world.id,world.name,world.municipality,region.name,country.name,latitude,longitude,altitude";

	public static class Place extends HashMap<String,String> {}
	public static class Places extends ArrayList<Place> {}

	public static class Database {
		public static Integer found(String match) throws Exception {
			String sql = Select.found(match);
			try (
				// connect to the database and query
				Connection conn = DriverManager.getConnection(Credential.getUrl(), Credential.USER, Credential.PASSWORD);
				Statement query = conn.createStatement();
				ResultSet results = query.executeQuery(sql);
			) {
				return count(results);
			} catch (Exception e) {
				throw e;
			}
		}

		private static Integer count(ResultSet results) throws Exception {
			if (results.next()) {
				return results.getInt("count");
			}
			throw new Exception("No count results in found query.");
		}


		public static Places places(String match, Integer limit) throws Exception {
			if (limit == 0) {
				limit = 100;
			}
			String sql = Select.match(match, limit);
			try (
				// connect to the database and query
				Connection conn = DriverManager.getConnection(Credential.getUrl(), Credential.USER, Credential.PASSWORD);
				Statement query = conn.createStatement();
				ResultSet results = query.executeQuery(sql);
			) {
				return convertQueryResultsToPlaces(results, COLUMNS);
			} catch (Exception e) {
				throw e;
			}
		}


		private static Places convertQueryResultsToPlaces(ResultSet results, String columns) throws Exception {
			int count = 0;
			int countCols = 0;
			String[] cols = columns.split(",");
			String[] correctCols = {"id","name","municipality","region","country","latitude","longitude","altitude"};
			Places places = new Places();
			while (results.next()) {
				Place place = new Place();
				for (String col: cols) {
					place.put(correctCols[countCols], results.getString(col));
					countCols++;
				}
				place.put("index", String.format("%d",++count));
				places.add(place);
				countCols = 0;
			}
			return places;
		}
	}
	public static class Credential {
		// shared user with read-only access
		final static String USER = "cs314-db";
		final static String PASSWORD = "eiK5liet1uej";
		// connection information when using port forwarding from localhost
		
		static String Url;
		public static void setUrl(String userUrl) {
			Url = userUrl;
		}
		static String getUrl() {
			return Url;
		}
	}

	static class Select {
		static String match(String match, int limit) {
			return statement(match, "DISTINCT " + COLUMNS, "LIMIT " + limit);
		}

		static String found(String match) {
			return statement(match, "COUNT(*) AS count ", "");
		}

		static String statement(String match, String data, String limit) {
			return "SELECT "
				+ data
				+ " FROM " + TABLE
				+ " INNER JOIN region ON world.iso_region = region.id"
				+ " INNER JOIN country ON world.iso_country = country.id"
				+ " INNER JOIN continent ON world.continent = continent.id"
				+ " WHERE"
				+ " (world.id LIKE \"%" + match + "%\" "
				+ "	OR country.name LIKE \"%" + match + "%\" "
				+ " OR region.name LIKE \"%" + match + "%\" "
				+ " OR world.name LIKE \"%" + match + "%\" "
				+ " OR world.municipality LIKE \"%" + match + "%\") "
				+ limit
				+ " ;";
		}
	}

}