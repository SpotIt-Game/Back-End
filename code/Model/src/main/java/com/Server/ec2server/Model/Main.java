package com.Server.ec2server.Model;
import com.Server.ec2server.util.ExpiringHashMap;
import com.google.gson.JsonObject;


public class Main {

    private static Main main;

    private ExpiringHashMap<Integer, Lobby> lobbies = new ExpiringHashMap<>();

    private Main() {}

    public static Main getInstance() {
        if (main == null) main = new Main();
        return main;
    }

    public JsonObject handleRequest(JsonObject jsonGod){

        JsonObject json = new JsonObject();
        if(jsonGod == null) return json;
        int move = jsonGod.get("move").getAsInt();
        int id_lobby = jsonGod.get("id_lobby").getAsInt();
        json.addProperty("move", move);

        if (move == 1) lobbies.put(id_lobby, new Lobby(jsonGod));
        else if (move == 2) json = lobbies.get(id_lobby).verifyMove(jsonGod);
        else{
            json = lobbies.get(id_lobby).calculateWinner(jsonGod);
            lobbies.remove(id_lobby);

        }return json;

    }



}
