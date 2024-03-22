import java.util.*;



public class PNG{

    private int id_image, width, height;
    private int[][] points = new int[4][2];

    public PNG(int id, int cols, int rows){

        id_image = id;
        width = cols; height = rows;
        points[0][0] = 0;     points[0][1] = 0;
        points[1][0] = cols;  points[1][1] = 0;
        points[2][0] = 0;     points[2][1] = rows;
        points[3][0] = cols;  points[3][1] = rows;
        
    }



    @Override
    public String toString(){
        return id_image + " " + width + " " + height + "\n" +
                points[0][0] + " " + points[0][1] + "\n" +  
                points[1][0] + " " + points[1][1] + "\n" +
                points[2][0] + " " + points[2][1] + "\n" +
                points[3][0] + " " + points[3][1] + "\n";
            
    }


}