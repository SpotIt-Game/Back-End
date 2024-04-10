package com.Controller.core;

import com.Model.Main;
import com.google.gson.Gson;
import com.google.gson.JsonObject;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;




public class HttpConnectionWorker extends Thread {

    private Socket socket;
    private static Logger LOGGER = LoggerFactory.getLogger(ServerListenerThread.class);


    public HttpConnectionWorker(Socket socket) {
        this.socket = socket;
    }


    private JsonObject read() throws Exception {

        InputStream inputStream = socket.getInputStream();
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        while (true) {
            String line = reader.readLine();
            if (line == null || line.isEmpty()) break;

        }StringBuilder bodyData = new StringBuilder();
        while (reader.ready()) bodyData.append((char)reader.read());
        return new Gson().fromJson(bodyData.toString(), JsonObject.class);

    }


    private void write(JsonObject json) throws Exception {

        if(json == null) return;
        OutputStream outputStream = socket.getOutputStream();
        OutputStreamWriter writer = new OutputStreamWriter(outputStream, StandardCharsets.UTF_8);
        writer.write("HTTP/1.1 200 OK\r\n");
        writer.write("Content-Type: application/json\r\n");
        writer.write("\r\n");
        writer.write(json.toString());
        writer.write("\r\n\r\n");
        writer.flush();

    }


    @Override
    public void run() {
        try {

            write(Main.getInstance().handleRequest(read()));

        } catch (Exception e) {
            LOGGER.error("Error while processing client request: " + e.getMessage());
            throw new RuntimeException(e);
        } finally {
            try {
                if (socket != null) socket.close();
            } catch (Exception e) {
                LOGGER.error("Error while closing socket: " + e.getMessage());
            }
        }
    }
}
