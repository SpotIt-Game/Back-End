import java.util.*;

public class Tower {
    // private int gameMode =  1; //creo que esto ya no haría falta almenos para esta clase

    // public int getgameMode(){
    //     return this.gameMode;
    // }

    public Tower(ArrayList<Player>players){
        super(players,1)
    }
    
    @Override
    public void handleChange(Player p){ 
        return;
    }
}
