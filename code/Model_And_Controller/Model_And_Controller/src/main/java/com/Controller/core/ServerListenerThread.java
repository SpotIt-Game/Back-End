package com.Controller.core;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;



public class ServerListenerThread extends Thread {

    private static Logger LOGGER = LoggerFactory.getLogger(ServerListenerThread.class);
    private int port;
    private String webroot;
    private ServerSocket serverSocket;

    public ServerListenerThread(int port, String webroot) throws IOException {
        this.port = port;
        this.webroot = webroot;
        serverSocket = new ServerSocket(this.port);
    }






    @Override
    public void run() {
        try {
            while (serverSocket.isBound() && !serverSocket.isClosed()) {
                Socket socket = serverSocket.accept();
                LOGGER.info("Connection established with client: " + socket.getInetAddress());
                HttpConnectionWorker worker = new HttpConnectionWorker(socket);
                worker.start();
            }
        } catch (IOException e) {
            LOGGER.error("Error while setting socket: " + e.getMessage());
        } finally {
            if (serverSocket != null) {
                try {
                    serverSocket.close();
                } catch (IOException e) {
                }
            }
        }
    }





}

