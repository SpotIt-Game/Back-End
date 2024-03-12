import java.sql.*;
import java.io.*;
import java.util.*;
import java.nio.file.*;





public class ProcessDeck {

    static String path = "/home/danilo/SpotIT-Game/SpotIT/code/out.txt";
    static int file = 1;

    public static void main(String[] args) throws IOException, SQLException, ClassNotFoundException {

        Connection conn = connectDB.init();
        List<String> lines = Files.readAllLines(Paths.get(path));

        for(String line: lines){  

            String[] numberStrings = line.split(" ");
            ArrayList<Integer> row = new ArrayList<>();
            for (int i = 0; i < numberStrings.length; i++) row.add(Integer.parseInt(numberStrings[i]));

            RotateAndScaleCard card_i = new RotateAndScaleCard(row, conn);
            BufferedWriter writer = new BufferedWriter(new FileWriter("card" + (file++) + ".txt"));
            for(PNG i: card_i.processImages())writer.write(i.toString());
            writer.close();
           
        }

    }
}
