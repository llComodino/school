import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.ResultSet;

public class Login extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws IOException, ServletException {

    String username = request.getParameter("utente");
    String psw = request.getParameter("psw");

    response.setContentType("text/html");
    PrintWriter out = response.getWriter();

    out.println("<!DOCTYPE html>");
    out.println("<html><head><meta charset='UTF-8'><title>Risultato Login</title></head><body>");

    if ("admin".equals(username) && "1234".equals(psw)) {
      out.println("<h1>ACCESSO AVVENUTO CON SUCCESSO!</h1>");
      out.println("<h3>Utenti presenti nel database:</h3>");

      try {
        DBConnection conn = new DBConnection();

        if ( conn == null ) {
          System.out.println("Error establishing connection");
          return;
        }

        String query = "SELECT * FROM user";
        ResultSet users = conn.fetchByQuery(query);

        if ( users.next() ) {
          users.previous();
          out.println("<table><thead>");
          out.println("<th><span>ID<span></th>");
          out.println("<th><span>Name<span></th>");
          out.println("<th><span>Surname<span></th>");
          out.println("<th><span>Username<span></th>");
          out.println("<th><span>Password<span></th>");
          out.println("</thead><tbody>");

          while ( users.next() ) {
            out.println("<tr>");
            out.println("<td><span>" + users.getString("id") + "</span></td>");
            out.println("<td><span>" + users.getString("name") + "</span></td>");
            out.println("<td><span>" + users.getString("surname") + "</span></td>");
            out.println("<td><span>" + users.getString("username") + "</span></td>");
            out.println("<td><span>" + users.getString("password") + "</span></td>");
            out.println("</tr>");
          }
          out.println("</tbody></table>");
        }
      } catch (Exception e) {
        System.out.println("Exception occoured: " + e.getMessage());
      }
    } else {
      out.println("<h1>ERRORE ACCESSO</h1>");
      out.println("<a href='homepage-progetto'>Torna alla homepage</a>");
    }

    out.println("</body></html>");
  }
}
