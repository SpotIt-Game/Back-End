import java.sql.*;




public class connectDB{

    public static Connection init() throws SQLException, ClassNotFoundException{

        Class.forName("com.mysql.cj.jdbc.Driver");
        String host = "jdbc:mysql://spot-it-db.cfw26wk6i0xn.us-east-2.rds.amazonaws.com:3306/spotit_db";
        String user = "root";
        String password = "";
        Connection conn = DriverManager.getConnection(host, user, password);
        System.out.println("Successful connection to the database!");
        return conn;
        
    }

}
