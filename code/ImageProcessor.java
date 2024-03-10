import java.sql.*;
import java.util.*;
import java.io.*;
import java.awt.*;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.geom.AffineTransform;
import javax.swing.ImageIcon;
import java.awt.image.BufferedImage;





public class ImageProcessor {


    private Connection conn = null;


    private void connectBD() throws SQLException, ClassNotFoundException {

        Class.forName("com.mysql.cj.jdbc.Driver");
        String host = "jdbc:mysql://spot-it-db.cfw26wk6i0xn.us-east-2.rds.amazonaws.com:3306/spotit_db";
        String user = "root";
        String password = "B3$cYZpijX>tfT+";
        conn = DriverManager.getConnection(host, user, password);
        System.out.println("Successful connection to the database!");


    }




    











    public static void main(String[] args) throws Exception {

        ImageProcessor imageProcessor = new ImageProcessor();

        
        imageProcessor.connectBD();
        
    }
}
