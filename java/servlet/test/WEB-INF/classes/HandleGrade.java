import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import model.DBConnection;

import model.*;

public class HandleGrade extends HttpServlet {
  public void doPost(HttpServletRequest request, HttpServletResponse response)
      throws IOException, ServletException {

    String subject = request.getParameter("subj");
    String mark = request.getParameter("mark");

    DBConnection conn = new DBConnection();
    User user = (User) request.getSession().getAttribute("user");
    System.out.println("INSERTING FOR: " + user);
    if ( user.addGrade( new Grade(Integer.parseInt(mark), subject)) ) 
      conn.insertGrade(user, subject, Integer.parseInt(mark));

    response.sendRedirect("profile.jsp");
  }
}
