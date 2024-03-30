import java.util.*;




public class Center {
    
    private ArrayList<Card> centerCards = new ArrayList<>();
    private boolean side; // 1 hacia arriba, 0 para abajo


    
    public Center(boolean side, ArrayList<Card> centerCards){

        this.side = side;
        this.centerCards = centerCards;
        Collections.shuffle(centerCards);

    }




    public void push(Card a){
        centerCards.add(a);
    }

    public Card top(){
        return centerCards.get(centerCards.size() - 1);
    }

    public void pop(){
        centerCards.remove(centerCards.size()-1);
    }

    public boolean isEmpty(){
        return centerCards.isEmpty();
    }





}
