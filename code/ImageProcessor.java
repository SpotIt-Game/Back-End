import java.sql.*;
import java.io.*;
import java.awt.*;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.util.*;



class PNG{

    private int id_image;
    private int[][] points = new int[4][2];
    private double scale, rotate;
    private Random random = new Random();


    public PNG(int id, int cols, int rows){

        id_image = id;
        points[0][0] = 0;    points[0][1] = 0;
        points[1][0] = cols; points[1][1] = 0;
        points[2][0] = 0;    points[2][1] = rows;
        points[3][0] = cols; points[3][1] = rows;

        scale = Math.sqrt(0.5 + (1.5 * random.nextDouble()));
        rotate = 2 * Math.PI * random.nextDouble();

        int cX = cols >> 1, cY = rows >> 1;
        double cosTheta = Math.cos(rotate), sinTheta = Math.sin(rotate);

        for (int i = 0; i < 4; ++i) {
            int x = points[i][0] - cX, y = points[i][1] - cY;
            points[i][0] = (int) (x * cosTheta - y * sinTheta) + cX;
            points[i][1] = (int) (x * sinTheta + y * cosTheta) + cY;
            points[i][0] *= scale;
            points[i][1] *= scale;
        }
    }


    public String toString(){

        return id_image + "\n" + 
            points[0][0] + ", " + points[0][1] + "\n" +  
            points[1][0] + ", " + points[1][1] + "\n" +
            points[2][0] + ", " + points[2][1] + "\n" +
            points[3][0] + ", " + points[3][1] + "\n" +
            "R: " + rotate + "\nS: " + scale + "\n";

    }


}









public class ImageProcessor{


    private Connection conn = null;
    private ArrayList<PNG> card = new ArrayList<PNG>();
    private int level;






    public ImageProcessor(int l) {
        level = l;
    }



    private void connectDB() throws SQLException, ClassNotFoundException{
        Class.forName("com.mysql.cj.jdbc.Driver");
        String host = "jdbc:mysql://spot-it-db.cfw26wk6i0xn.us-east-2.rds.amazonaws.com:3306/spotit_db";
        String user = "root";
        String password = "B3$cYZpijX>tfT+";
        conn = DriverManager.getConnection(host, user, password);
        System.out.println("Successful connection to the database!");
    }





    private BufferedImage readImage(byte[] imageData) throws IOException{
        ByteArrayInputStream bis = new ByteArrayInputStream(imageData);
        return ImageIO.read(bis);
    }




    public void getBLOBSFromDB() throws SQLException, ClassNotFoundException, IOException{

        connectDB();
        PreparedStatement statement = conn.prepareStatement("SELECT * FROM image WHERE id_image <= " + level);
        ResultSet resultSet = statement.executeQuery();

        while(resultSet.next()){

            int idImage = resultSet.getInt("id_image");
            System.out.println("id_image: " + idImage);
            BufferedImage img = readImage(resultSet.getBytes("data"));

            if(img != null) card.add(new PNG(idImage, img.getWidth(), img.getHeight()));
            
        }for(PNG i: card) System.out.println(i);

    }



    public static void main(String[] args) throws Exception{

        ImageProcessor imageProcessor = new ImageProcessor(140);
        imageProcessor.getBLOBSFromDB();

    }
}
