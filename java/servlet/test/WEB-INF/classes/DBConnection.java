import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.sql.*;

public class DBConnection {
  private static final String DB_DRIVER = "org.mariadb.jdbc.Driver";
  private static final String DB_CONNECTION = "jdbc:mariadb://localhost/servlet";
  private static final String DB_USER = "servlet";
  private static final String DB_PASSWORD = "servlet123!";

  private Connection conn = null;

  public DBConnection() {
    System.out.println("Inizio Connessione...");
    try {
      System.out.println("Cerco i driver...");
      Class.forName(DB_DRIVER);
      System.out.println("Driver trovati");
    } catch (Exception ex) {
      System.out.println("errore JDBC");
    }

    try {
      System.out.println("Provo a connettermi al Database...");
      conn = DriverManager.getConnection(DB_CONNECTION, DB_USER, DB_PASSWORD);
      System.out.println("SQL Connection to DB eseguita correttamente!");
    } catch (SQLException e) {
      System.out.println("Connection to dbmio database failed");
      System.out.println(e.getErrorCode() + ":" + e.getMessage());

      conn = null;
    }
  }

  public ResultSet fetchQuery(String query) {
    if ( query.isEmpty() ) return null;
    if ( conn == null ) {
      System.out.println("Connection not yet established");
      return null;
    }

    Statement stmt = null;
    try {
      stmt = conn.createStatement();
      return stmt.executeQuery(query);
    } catch(SQLException sqle) {
      System.out.println("SELECT ERROR");
    } catch(Exception err) {
      System.out.println("GENERIC ERROR");
    }

    return null;
  }

  public boolean insertUser(User user) {
    String insertQuery = "INSERT INTO user VALUES (?, ?, ?, ?, ?)";

    PreparedStatement stmt = null;
    try {
      stmt = conn.prepareStatement(insertQuery);

      stmt.setString(1, user.getID());
      stmt.setString(2, user.getName());
      stmt.setString(3, user.getSurname());
      stmt.setString(4, user.getUsername());
      stmt.setString(5, user.getPassword());

      if ( stmt.executeUpdate() > 0 ) {
        System.out.println("User inserted succesfully");
      } else {
        return false;
      }
    } catch(SQLException sqle) {
      System.out.println("INSERT ERROR");
      return false;
    } catch(Exception err) {
      System.out.println("GENERIC ERROR");
      return false;
    }

    return true;
  }

  public User getUser(String username, String password) {
    try {
      DBConnection conn = new DBConnection();
      ResultSet users = conn.fetchQuery("SELECT * FROM user WHERE username = '" + username + "' AND password = '" + User.genEncryptedPassword(password) + "'");

      if ( users.next() ) {
        User user = new User(
            users.getString("id"),
            users.getString("name"),
            users.getString("surname"),
            users.getString("username"),
            users.getString("password")
        );

        return user;
      }
    } catch ( SQLException e ) {
      e.printStackTrace();
    }
    return null;
  }
}
