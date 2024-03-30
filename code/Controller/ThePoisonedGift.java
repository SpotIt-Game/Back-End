import java.util.*;


public class ThePoisonedGift{
    // private int gameMode =  5; //creo que esto ya no haría falta almenos para esta clase

    //     public int getgameMode(){
    //         return this.gameMode;
    //     }

    public ThePoisonedGift(ArrayList<Player>players){
        super(players,0);
    }
    
    @Override
    public void handleChange(Player p){ 
        return;
    }
}

