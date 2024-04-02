import java.util.*;
import javax.print.attribute.standard.JobImpressionsCompleted;
import java.net.*;
import java.io.*;
import com.google.gson.*;
import netscape.javascript.JSException;


public class Main{


    public static Map<Integer, Lobby> lobbies = new HashMap<>();


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


    public static JsonObject receiveData(URL url) throws Exception { 
        
        HttpURLConnection connection = (HttpURLConnection) url.openConnection();
        connection.setRequestMethod("GET");
        BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
        StringBuilder responseBuilder = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) responseBuilder.append(line);
        String jsonResponse = responseBuilder.toString();
        JsonObject jsonObject = new Gson().fromJson(jsonResponse,JsonObject.class);
        connection.disconnect();
        return jsonObject;

    }


    public Lobby getLobby(int i){
        return lobbies.get(i);
    }
    




    


    public static void main(String[] args) throws Exception {
    
    
        URL url = new URL("http://localhost:9000/move2/");
        JsonObject jsonGod = receiveData(url);                                                //if api wants to create a new game
        int move = jsonGod.get("move").getAsInt();

        
        if(move == 1) lobbies.add(new Lobby(jsonGod)); 

        else if(move == 2){
            
            int id_lobby = jsonGod.get("id_lobby").getAsInt();
            sendData(url, new Gson().toJson(lobbies.get(id_lobby).verifyMove(jsonGod)));
            
        } else{ 

            int id_lobby = jsonGod.get("id_lobby").getAsInt();
            sendData(url, new Gson().toJson(lobbies.get(id_lobby).calculateWinner(jsonGod)));
    
        }
    
    }   
}


