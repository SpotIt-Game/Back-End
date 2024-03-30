import java.util.*;





public class Player{


    private int points = 0;
    private int id_player;

    
    
    public Player(int id_player, ArrayList<Card> cards){
        this.id_player = id_player;
        this.cards = cards;
    }

    public int getId_player(){
        return id_player;
    }

    public int getPoints(){
        return points;
    }

    public boolean isEmpty(){
        return this.cards.size()==0;
    }
    

    public void updateEarned(int points){
        this.points += points;
    }
    

    


    @Override
    public int compareTo(Player otherPlayer) {
        return Integer.compare(otherPlayer.points, this.points);
    }

    



}
