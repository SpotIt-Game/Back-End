import java.util.*;

// public class Game implements Result{

//     private int level, game_mode;
//     private ArrayList<Player> players = new ArrayList<>();

//     public Game(int level, int game_mode, ArrayList<Player> players){

//         this.level = level;
//         this.game_mode = game_mode;
//         this.players = players;

//     }
//     // metodo que dirija el game_mode seleccionado
// }


public abstract class Game{

    public abstract void handleCoincidence();  //este método dependiendo del juego hará cambios en el mazo del jugador o jugadores
    public void cacularGanador();  //este método me dirá quien va ganando según el modo de juego ya que en algunos tener más cartas es bueno mientras que en otro no lo es
    
    
    
}
