import java.util.*;
import java.net.*;
import java.io.*;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;



/*
javac -cp .:lib/gson-2.8.8.jar Main.java
java -cp .:lib/gson-2.8.8.jar Main
*/




public class Main{


    

    public boolean equals(String url1, String url2){
        return url1.equals(url2);
    }







    

    public static void sendData(URL url, String jsonBody) throws Exception{

        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("POST");
        connection.setDoOutput(true);
        connection.setRequestProperty("Content-Type", "application/json");
        DataOutputStream outputStream = new DataOutputStream(connection.getOutputStream());
        outputStream.writeBytes(jsonBody);
        outputStream.flush();
        outputStream.close();
        int responseCode = connection.getResponseCode();
        System.out.println("Código de respuesta: " + responseCode);

    }


    public static void receiveData(URL url) throws Exception{
        
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("GET");
        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        StringBuilder responseBuilder = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) responseBuilder.append(line);
        String jsonResponse = responseBuilder.toString();
        System.out.println("Respuesta del servidor JavaScript: " + jsonResponse);
        connection.disconnect();
        
    }


    






    public static void main(String[] args) throws Exception{

        //sendData(new URL("http://localhost:9000/"), "{\"booleano\": true}");
        receiveData(new URL("http://localhost:9000/"));
      

    }   

    
}

    
    


 