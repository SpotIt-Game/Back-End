import java.util.*;
import javax.print.attribute.standard.JobImpressionsCompleted;
import java.net.*;
import java.io.*;
import com.google.gson.*;
import netscape.javascript.JSException;





/*

export CLASSPATH=lib/gson-2.8.8.jar:.
javac *.java
java Main

*/




public class Main{

    private static Game game_mode;
    private static ArrayList<Player> players = new ArrayList<>();

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




    public static void main(String[] args) throws Exception {


        URL url = new URL("http://localhost:9000/move1/");
        JsonObject jsonGod = receiveData(url);                                                //if api wants to create a new game
        int move = jsonGod.get("move").getAsInt();
        
        if(move == 1){                                                                          
            
            game_mode = new Game(jsonGod.get("game_mode").getAsInt());
            JsonArray arr = jsonGod.get("players").getAsJsonArray();
            for(JsonElement p: arr) players.add(new Player(p.getAsInt()));

        }else if(move == 2){                                                                     //if api, wants to verify a move
            
            ArrayList<String> list = new ArrayList<>();
            for(JsonElement e : jsonGod.getAsJsonArray("urls")) list.add(e.getAsString());
            JsonObject jsonObject = new JsonObject();
            jsonObject.addProperty("booleano", game_mode.verifyMove(list, players.get(jsonGod.get("player").getAsInt()))); 
            sendData(url, new Gson().toJson(jsonObject));
            
        }else{                                                                                   //if api wants to end a game
            
            JsonObject jsonObject = new JsonObject();
            JsonArray arr = new JsonArray();
            for(Player p : game_mode.calculateWinner(players))
                arr.add(p.getId_player());
            jsonObject.add("Winners",arr);
            sendData(url, new Gson().toJson(jsonObject));

        }

    }   

}


















