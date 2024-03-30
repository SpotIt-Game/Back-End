import java.util.*;
import java.util.comparator; 

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
    protected boolean order; //esta variable nos indicará la manera de ganar, 1 en caso de que se gane acumulando la mayor cantidad de cartas y 0 cuando es la menor cantidad de cartas

    public Game(ArrayList<Player>players, boolean order){
        this.players=players;
        this.order=order
    }

    //este método dependiendo del juego hará cambios en el mazo del jugador o jugadores
    public abstract void handleCoincidence();  

     //este método me dirá quien va ganando según el modo de juego ya que en algunos tener más cartas es bueno mientras que en otro no lo es.
    //La funcion parece larga pero de esta forma, no hay que crear una funcion para calcular los ganadores en cada uno de los juegos.
    public ArrayList<Player> calculateWinner(){
        Collections.sort(this.players, (p1, p2) -> Integer.compare(p1.getPoints(), p2.getPoints()));  //asumo que sirve (ordena de menor a mayor según el puntaje)
        int mediator;
        ArrayList<Player>winners;
        if(this.order==true){
            int index=this.players.size()-1;
            mediator=this.players.get(index).getPoints();
            for(int i=0;i<index+1;i++){
                if(this.players.get(index-i).getPoints()==mediator){
                    winners.add(this.players.get(index-i));
                } else{
                    break;
                }
            }
        } else{
            mediator=this.players.get(0).getPoints();
            for(int i=0;i<this.players.size();i++){
                if(this.players.get(i).getPoints()==mediator){
                    winners.add(this.players.get(i));
                } else{
                    break;
                }
            }
        } return winners;
    }
       
}
