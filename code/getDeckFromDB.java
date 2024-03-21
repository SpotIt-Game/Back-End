import java.sql.*;
import java.io.*;
import java.util.*;
import java.nio.file.*;








public class getDeckFromDB {

    static String path = "/home/duquehp/SpotIT/code/out.txt";

    public static void main(String[] args) throws IOException, SQLException, ClassNotFoundException {

        Connection conn = connectDB.init(); 
        List<String> lines = Files.readAllLines(Paths.get(path));
        int id_deck = Integer.parseInt(lines.get(0)); 
        int order = Integer.parseInt(lines.get(1));
        
        BufferedWriter writer = new BufferedWriter(new FileWriter("deck" + id_deck));
        writer.write(id_deck + " " + order + "\n");

        for(int j = 2; j < lines.size(); j += 2) {  

            int id_card = Integer.parseInt(lines.get(j)); 
            String[] numberStrings = lines.get(j+1).split(" "); 
            ArrayList<Integer> row = new ArrayList<>();
            for (String numberString : numberStrings) row.add(Integer.parseInt(numberString)); 

            getCardFromDB card_i = new getCardFromDB(row, conn); 
            writer.write(id_card + "\n");
            for(PNG i: card_i.processImages()) writer.write(i.toString());

        }writer.close();
           

    }
}
