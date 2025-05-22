<%@ page import="model.User"%>
<%@ page import="model.Grade"%>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Profile</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
  </head>
  <body>
    <div class="container">
      <h1>Il tuo Profilo</h1>
      <% User user = (User) session.getAttribute("user"); %>

      <% if ( user == null ) { %>
      <span>User not found</span>
      <% } else { %>
      <div class="box">
        <p><strong>Nome:</strong> <%= user.getName() %></p>
        <p><strong>Cognome:</strong> <%= user.getSurname() %></p>
        <p><strong>Username:</strong> <%= user.getUsername() %></p>
      </div>

      <hr>

      <div class="box">
        <p><strong>Voti:</strong></p>
        <table>
          <thead><th><span>Voto</span></th><th><span>Materia</span></th></thead>
          <tbody>
          <% for (Grade grade : user.getGrades(true)) { %>
            <%
              int mark = grade.getMark();
              if ( mark < 6 && mark >= 5) {
            %>
              <tr style="background: orange">
            <% } else if ( mark < 5 ) { %>
              <tr style="background: red">
            <% } else { %>
              <tr style="background: green">
            <% } %>
                <td><span> <%= mark %> </span></td><td><span> <%= grade.getSubject() %> </span></td>
              </tr>
          <% } %>
          </tbody>
        </table>

        <p>Media:
        <%
          double avg = user.getGradeAvg();
          if ( avg < 6f && avg >= 5f ) {
        %>
          <span style="color: orange">
        <% } else if ( avg < 5f ) { %>
          <span style="color: red">
        <% } else { %>
          <span style="color: green">
        <% } %>
        <%= avg %></span>
        <br>
        <a href="addGrade.jsp">Aggiungi Voto</a>
      </div>
      <% } %>
    </div>
  </body>
</html>
