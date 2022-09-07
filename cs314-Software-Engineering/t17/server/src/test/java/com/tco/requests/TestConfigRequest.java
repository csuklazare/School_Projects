package com.tco.requests;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class TestConfigRequest {

    private ConfigRequest conf;

    @BeforeEach
    public void createConfigurationForTestCases() {
        conf = new ConfigRequest();
        conf.buildResponse();
    }

    @Test
    @DisplayName("base: Request type is \"config\"")
    public void testType() {
        String type = conf.getRequestType();
        assertEquals("config", type);
    }

    @Test
    @DisplayName("base: Features includes \"config\"")
    public void testFeatures(){
        assertTrue(conf.validFeature("config"));
    }

    @Test
    @DisplayName("tschroe: Features includes \"distances\"")
    public void testFeaturesDistances() {
        assertTrue(conf.validFeature("distances"));
    }

    @Test
    @DisplayName("tschroe: Features includes \"find\"")
    public void testFeaturesFind() {
        assertTrue(conf.validFeature("find"));
    }

    @Test
    @DisplayName("base: Team name is correct")
    public void testServerName() {
        String name = conf.getServerName();
        assertEquals("t17 The Moist Pigeons", name);
    }
}