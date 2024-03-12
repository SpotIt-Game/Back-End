import java.sql.*;
import java.io.*;
import java.awt.*;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.util.*;













public class RotateAndScaleCard{


    private Connection conn;
    private ArrayList<PNG> card = new ArrayList<PNG>();
    private ArrayList<Integer> ids;



    public RotateAndScaleCard(ArrayList<Integer> arr, Connection c) {
        ids = arr;
        conn = c;
    }




    private BufferedImage readImage(byte[] imageData) throws IOException{
        ByteArrayInputStream bis = new ByteArrayInputStream(imageData);
        return ImageIO.read(bis);
    }




    public ArrayList<PNG> processImages() throws SQLException, ClassNotFoundException, IOException{

        for(int i: ids){

            PreparedStatement statement = conn.prepareStatement("SELECT * FROM image WHERE id_image = " + i);
            ResultSet resultSet = statement.executeQuery();
            while(resultSet.next()){

                System.out.println("id_image: " + i);
                BufferedImage img = readImage(resultSet.getBytes("data"));
                card.add(new PNG(i, img.getWidth(), img.getHeight()));
                
            }

        }return card;

    }







    public static void main(String[] args) throws Exception{

        ArrayList<Integer> arr = new ArrayList<>(Arrays.asList(1, 6, 18, 22, 29, 31));
        RotateAndScaleCard RotateAndScaleCard = new RotateAndScaleCard(arr, connectDB.init());
        RotateAndScaleCard.processImages();

    }




}
