package com.Server.ec2server.http;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;


public class HttpVersionTest {


    @Test
    void getBestCompatibleVersionExactMatch(){

        HttpVersion version = null;
        try {
            version = HttpVersion.getBestCompatibleVersion("HTTP/1.1");
        } catch (BadHttpVersionException e) {
            fail();
        }


        assertNotNull(version);
        assertEquals(version, HttpVersion.HTTP_1_1);

    }



    @Test
    void getBestCompatibleVersionBadFormat() {

        HttpVersion version = null;
        try {
            version = HttpVersion.getBestCompatibleVersion("http/1.0");
        } catch (BadHttpVersionException e) {
        }

    }





    @Test
    void getBestCompatibleVersionHigherVersion() {

        HttpVersion version = null;
        try {
            version = HttpVersion.getBestCompatibleVersion("HTTP/1.2");
        } catch (BadHttpVersionException e) {
            fail();
        }

    }






}