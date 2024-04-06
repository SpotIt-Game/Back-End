package com.Server.ec2server.Model;
import java.util.*;





public class Game{


    private boolean order;


    public Game(int game_mode){
        this.order = (game_mode == 1 || game_mode == 4);
    }


    public boolean verifyMove(ArrayList<String> arr, Player curr){

        String url = arr.get(0);
        for(String element : arr)
            if(!url.equals(element))
                return false;

        curr.updateEarned((order)? 1: -1);
        return true;

    }


    public ArrayList<Player> calculateWinner(ArrayList<Player> players){

        Collections.sort(players);
        int w = players.get(0).getPoints();
        ArrayList<Player> winners = new ArrayList<>();
        for(int i = 0; i < players.size() && players.get(i).getPoints() == w; ++i)
            winners.add(players.get(i));
        return winners;

    }




}
