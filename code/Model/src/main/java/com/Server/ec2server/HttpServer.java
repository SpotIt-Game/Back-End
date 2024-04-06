package com.Server.ec2server;


import com.Server.ec2server.core.ServerListenerThread;
import org.slf4j.LoggerFactory;
import org.slf4j.Logger;
import java.io.IOException;



public class HttpServer {

    private final static Logger LOGGER = LoggerFactory.getLogger(HttpServer.class);
    private static final int port = 8080;
    private static final String webroot = "";

    public static void main(String[] args) {

        LOGGER.info("Starting server...");
        LOGGER.info("Using port: " + port);
        LOGGER.info("Using webroot: " + webroot);

        try {
            ServerListenerThread serverListenerThread = new ServerListenerThread(port, webroot);
            serverListenerThread.start();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
