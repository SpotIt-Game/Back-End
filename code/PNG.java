import java.util.*;




public class PNG{

    private int id_image;
    private int[][] points = new int[4][2];
    private double scale, rotate;
    private Random random = new Random();
    private double size = 2e5;



    public PNG(int id, int cols, int rows){

        id_image = id;
        scale = Math.sqrt(size/(cols*rows) * (0.5 + (1.5 * random.nextDouble())));

        points[0][0] = 0;                    points[0][1] = 0;
        points[1][0] = (int)(cols * scale);  points[1][1] = 0;
        points[2][0] = 0;                    points[2][1] = (int)(rows * scale);
        points[3][0] = (int)(cols * scale);  points[3][1] = (int)(rows * scale);


        rotate = 2 * Math.PI * random.nextDouble();
        int cX = points[3][0]>>1, cY = points[3][1]>>1;
        double cosTheta = Math.cos(rotate), sinTheta = Math.sin(rotate);

        for (int i = 0; i < 4; ++i) {
            int x = points[i][0] - cX, y = points[i][1] - cY;
            points[i][0] = (int)(x * cosTheta - y * sinTheta) + cX;
            points[i][1] = (int)(x * sinTheta + y * cosTheta) + cY;
        }

    }




    @Override
    public String toString(){

        return "" + id_image + "\n" + 
            points[0][0] + " " + points[0][1] + "\n" +  
            points[1][0] + " " + points[1][1] + "\n" +
            points[2][0] + " " + points[2][1] + "\n" +
            points[3][0] + " " + points[3][1] + "\n" +
            rotate + "\n" + scale + "\n";

    }




    public static void main(String[] args){

        PNG p = new PNG(1, 2440, 1000);
        System.out.println(p);

    }


}