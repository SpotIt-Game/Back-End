import java.util.*;





public class Player{


    private int pointsEarned = 0;
    private ArrayList<Card> cards = new ArrayList<>();
    private String playerName;

    
    
    public Player(String name, ArrayList<Card> cards){
        playerName = name;
        this.cards = cards;
    }

    public String getName(){
        return playerName;
    }

    public int getPoints(){
        return pointsEarned;
    }

    public boolean isEmpty(){
        return this.cards.size()==0;
    }
    

    public void updateEarned(int points){
        this.pointsEarned += points;
    }
    

    public void push(Card a){
        this.cards.add(a);
    }

    public Card top(){
        return cards.get(cards.size()-1);
    }

    public void pop(){
        cards.remove(cards.size()-1);
    }
    
    
    





    @Override
    public int compareTo(Player otherPlayer) {
        return Integer.compare(otherPlayer.pointsEarned, this.pointsEarned);
    }

    



}
