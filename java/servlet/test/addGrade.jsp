<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Add Grade</title>
    <link rel="stylesheet" type="text/css" href="css/style.css">
  </head>
  <body>
    <div class="container">
      <h1>Aggiungi un Voto</h1>
      <form action="handle_grade" method="post">
        <label for="mark">Voto (0-10):</label>
        <input type="number" id="mark" name="mark" min="0" max="10" step="1" required>
        <br>
        <label for="subj">Materia:</label>
        <select id="subj" name="subj" required>
          <option value="" disabled selected>Seleziona una materia</option>
          <option value="Matematica">Matematica</option>
          <option value="Italiano">Italiano</option>
          <option value="TPSIT">TPSIT</option>
          <option value="Storia">Storia</option>
          <option value="Informatica">Informatica</option>
          <option value="GPOI">GPOI</option>
          <option value="Inglese">Inglese</option>
        <select>
        <br>
        <input type="submit" value="Add Grade">
      </form>
    </div>
  </body>
</html>
