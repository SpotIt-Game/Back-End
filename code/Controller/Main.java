import java.util.*;
import java.net.*;
import java.io.*;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import netscape.javascript.JSException;



/*
javac -cp .:lib/gson-2.8.8.jar Main.java
java -cp .:lib/gson-2.8.8.jar Main
*/




public class Main{

    private static Game game_mode;
    private static ArrayList<Integer> players = new ArrayList<>();



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


    

//return print();
//no sé usar switch :c es para gente trash.
    public static void main(String[] args) throws Exception {


        URL url = new URL("http://localhost:9000/");
        JsonObject jsonGod = receiveData(url);
        int move = jsonGod.get("move").getAsInt();

        
        if(move == 1){
            
            game_mode = new Game(jsonGod.get("game_mode").getAsInt());
            JsonArray arr = jsonGod.get("players").getAsJsonArray();
            for(JsonElement p: arr) players.add(new Player(p.getAsInt()));
            
        }else if(move == 2){
            
            JsonObject jsonObject = new JsonObject();
            jsonObject.addProperty("booleano", game_mode.verifyMove(jsonGod.get("urls").getAsJsonArray()));
            String jsonString = new Gson().toJson(jsonObject);
            sendData(url,jsonString);
            
        }else{
            
            JsonObject jsonObject = new JsonObject();
            jsonObject.addProperty("Winners", game_mode.calculateWinner(players));
            String jsonString = new Gson().toJson(jsonObject);
            sendData(url,jsonString);

        }

    }   

    
}


    


 