package com.Model;
import com.util.ExpiringHashMap;
import com.google.gson.*;


public class Main {

    private static Main main;

    private ExpiringHashMap<Integer, Lobby> lobbies = new ExpiringHashMap<>();

    private Main() {}

    public static Main getInstance() {
        if (main == null) main = new Main();
        return main;
    }



    private JsonObject initEndVerify(int move, JsonObject jsonGod, JsonObject json){

        json.addProperty("move", move);
        int id_lobby = jsonGod.get("id_lobby").getAsInt();
        if (move == 1) lobbies.put(id_lobby, new Lobby(jsonGod));
        else if (move == 2) json = lobbies.get(id_lobby).verifyMove(jsonGod);
        else{
            json = lobbies.get(id_lobby).calculateWinner(jsonGod);
            lobbies.remove(id_lobby);
        }return json;

    }


    private JsonObject showLobbies(JsonObject json) {

        JsonArray lobbiesArray = new JsonArray();
        for (Lobby lobby : lobbies.values()) lobbiesArray.add(lobby.toJson());
        json.add("lobbies", lobbiesArray);
        return json;

    }



    public JsonObject handleRequest(JsonObject jsonGod){

        JsonObject json = new JsonObject();
        if(jsonGod == null) return json;
        int move = jsonGod.get("move").getAsInt();
        return (move > 3)? showLobbies(json) : initEndVerify(move, jsonGod, json);

    }



}
