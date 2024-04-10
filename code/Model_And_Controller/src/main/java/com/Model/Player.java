package com.Model;

public class Player implements Comparable<Player> {

    private int points = 0;
    private int id_player;

    public Player(int id_player){
        this.id_player = id_player;
    }

    public int getId_player(){
        return id_player;
    }

    public int getPoints(){
        return Math.abs(points);
    }

    public void updateEarned(int points){
        this.points += points;
    }

    @Override
    public int compareTo(Player otherPlayer) {
        return Integer.compare(otherPlayer.getPoints(), getPoints());
    }

    @Override
    public String toString(){
        return "" + id_player + "";
    }



}