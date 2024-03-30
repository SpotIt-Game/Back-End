import java.util.*;

//OPINIÓN: Clase que quedará obsoleta y tendrá que ser eliminada.

public class Results {
    
    public static ArrayList<Player> Winner(ArrayList<Player> players){
        
        ArrayList<Player> best = new ArrayList<>();
        Collections.sort(players);
        int max = players.get(0).getPoints(), i = 0;
        while(players.get(i).getPoints() == max) best.add(players.get(i++));
        System.out.println((best.size() > 1)? "Tie!": "Congrats!");
        return best;
        
    }




    // si el array len de arraylist > 1, hay que devolver que hubo un tie entre los jugadores que 
    // están en el array, else se devuelve que congrats, el ganador 

}
