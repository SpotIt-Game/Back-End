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




    @Override
    public int compareTo(Player otherPlayer) {
        return Integer.compare(otherPlayer.pointsEarned, this.pointsEarned);
    }

    
    


    public void updateEarned(int points){
        this.pointsEarned += points;
    }
    
    
// Método para aumentar los puntos si hay una coincidencia.
// Método para actualizar la carta actual del jugador cuando hay una coincidencia.
// Método para obtener el nombre del jugador y sus puntos.

}