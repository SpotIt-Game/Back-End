import java.util.*;
import java.awt.*;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.geom.AffineTransform;
import javax.swing.ImageIcon;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;




public class ImageProcessor{


    private Image image;


    //this may change, to suit sql
    public ImageProcessor(String path){

        ImageIcon icon = new ImageIcon(path);
        image = icon.getImage();

    }

    public Image getImage(){
        return image;
    }


    public void scale(double factor){

        factor = Math.sqrt(factor);

        int newWidth = (int)(image.getWidth(null) * factor), newHeight = (int)(image.getHeight(null)*factor);

        image = new ImageIcon(image.getScaledInstance(newWidth, newHeight, Image.SCALE_SMOOTH)).getImage();

    }



    public void rotate(double radians){

        BufferedImage bufferedImage = new BufferedImage(
                image.getWidth(null),
                image.getHeight(null),
                BufferedImage.TYPE_INT_ARGB
        );

        Graphics2D g2d = bufferedImage.createGraphics();
        AffineTransform transform = AffineTransform.getRotateInstance(radians, image.getWidth(null) / 2, image.getHeight(null) / 2);
        g2d.setTransform(transform);
        g2d.drawImage(image, 0, 0, null);
        g2d.dispose();
        this.image = bufferedImage;

    } 



    public static void main(String []args){

        ImageProcessor proc = new ImageProcessor("/home/danilo/android.png");
        proc.scale(2);
        proc.rotate(3);
        Image processed = proc.getImage();

    }





} 
