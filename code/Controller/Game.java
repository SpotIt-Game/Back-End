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


//JUSTIFICACIÓN: En game manipularemos el juego pero necesitamos otra clase que sea "La clase dios" la cuál maneje el nivel y el modo de juego y en base a ella,
//instanciarémos un juego y lo manipularémos.

public abstract class Game{
    protected ArrayList<Player> players = new ArrayList<>();
    protected boolean order; //esta variable nos indicará la manera de ganar, 0 en caso de que se gane acumulando la mayor cantidad de cartas y 1 cuando es la menor cantidad de cartas

    public Game(ArrayList<Player>players, boolean order){
        this.players=players;
        this.order=order
    }
    
    public abstract void handleCoincidence();  //este método dependiendo del juego hará cambios en el mazo del jugador o jugadores
    public abstract void calculateWinner();  //este método me dirá quien va ganando según el modo de juego ya que en algunos tener más cartas es bueno mientras que en otro no lo es.
       
}
