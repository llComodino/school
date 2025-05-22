import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.ResultSet;

import model.*;

public class Login extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws IOException, ServletException {

    String username = request.getParameter("username");
    String psw = request.getParameter("psw");

    System.out.println("name: " + username + "psw: " + psw);

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
      request.getSession().setAttribute("user", user);
      response.sendRedirect("profile.jsp");
    } else {
      out.println("<h1 style=\"color: red;\">ERRORE ACCESSO</h1>");
      out.println("<a href='homepage-progetto'>Torna alla homepage</a>");
    }

    out.println("</body></html>");
  }
}
