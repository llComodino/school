import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.ResultSet;

public class Login extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws IOException, ServletException {

    String username = request.getParameter("username");
    String psw = request.getParameter("psw");

    DBConnection conn = new DBConnection();
    User user = conn.getUser(username, psw);

    response.setContentType("text/html");
    PrintWriter out = response.getWriter();

    out.println("<!DOCTYPE html>");
    out.println("<html><head>");
    out.println("<meta charset='UTF-8'><title>Risultato Login</title>");
    out.println("<link rel='stylesheet' type='text/css' href='css/table.css'>");
    out.println("</head><body>");

    if ( user != null ) {
      out.println("<h1>accesso avvenuto con successo!</h1>");

      out.println("<h2>Bentornato " + user.getUsername() + "</h2>");

      out.println("<h3>I tuoi voti:</h3>");
      out.println("<table>");
      out.println("<thead><th><span>Voto</span></th><th><span>Materia</span></th></thead>");
      out.println("<tbody>");
      for (Grade grade : user.getGrades()) {
        out.println("<tr" + ( ( grade.getMark() < 6 ) ? " style=\"color: red;\">" : "style=\"color: green\">" ));
        out.println("<td><span>" + grade.getMark() + "</span></td><td><span>" + grade.getSubject() + "</span></td>");
        out.println("</tr>");
      }
      out.println("</tbody>");
      out.println("</table>");
    } else {
      out.println("<h1 style=\"color: red;\">ERRORE ACCESSO</h1>");
      out.println("<a href='homepage-progetto'>Torna alla homepage</a>");
    }

    out.println("</body></html>");
  }
}
