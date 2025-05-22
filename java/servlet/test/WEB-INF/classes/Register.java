import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import model.*;

public class Register extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws IOException, ServletException {

    String name = request.getParameter("name");
    String surname = request.getParameter("surname");
    String username = request.getParameter("username");
    String psw = request.getParameter("password");

    DBConnection conn = new DBConnection();
    User user = new User(name, surname, username, psw);
    boolean success = conn.insertUser(user);

    response.setContentType("text/html");
    PrintWriter out = response.getWriter();

    out.println("<!DOCTYPE html>");
    out.println("<html><head>");
    out.println("<meta charset='UTF-8'><title>Registrazione</title>");
    out.println("<link rel='stylesheet' type='text/css' href='css/table.css'>");
    out.println("</head><body>");

    if (success) {
      out.println("<h1>Registrazione avvenuta con successo!</h1>");
    } else {
      out.println("<h1 style=\"color: red;\">ERRORE REGISTRAZIONE</h1>");
    }

    out.println("<a href='homepage-progetto'>Torna alla homepage</a>");
    out.println("</body></html>");
  }
}
