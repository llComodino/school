import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class Hello extends HttpServlet {
  public void doGet(HttpServletRequest request, HttpServletResponse response)
      throws IOException, ServletException {

    response.setContentType("text/html");
    PrintWriter out = response.getWriter();

    out.println("<!DOCTYPE html>");
    out.println("<html>");
    out.println("<head>");
    out.println("<meta charset='UTF-8'>");
    out.println("<title>Homepage Progetto</title>");
    out.println("<link rel='stylesheet' type='text/css' href='css/stile.css'>");
    out.println("<link href='https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css' rel='stylesheet'>");

    out.println("</head>");
    out.println("<body>");

    out.println("<h1>Homepage Progetto</h1>");
    out.println("<h2>Mario Rossi - 5A INF</h2>");
    out.println("<p>Questo è il progetto di TPSIT realizzato per scopi didattici.</p>");
    out.println("<img src='img/logo-fauser.png' alt='Logo Fauser' width='200'/>");

    out.println("<h3>Login</h3>");
    out.println("<form action='login' method='post'>");
    out.println("Username: <input type='text' name='utente'><br>");
    out.println("Password: <input type='password' name='psw'><br>");
    out.println("<input type='submit' value='Login'>");
    out.println("</form>");

    out.println("<footer>");
    out.println("<p>Questo progetto è a scopo didattico</p>");
    out.println("</footer>");

    out.println("</body>");
    out.println("</html>");
  }
}
