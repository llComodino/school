<!-- registration page, should send data to RegisterServlet -->
<!DOCTYPE html>
<html>
  <head>
    <title>Register</title>
    <link rel="stylesheet" type="text/css" href="style.css">
  </head>
  <body>
    <div class="container">
      <h2>Registrati</h2>
      <form action="register" method="post">
        <label for="username">Nome:</label>
        <input type="text" id="name" name="name" required><br><br>

        <label for="username">Cognome:</label>
        <input type="text" id="surname" name="surname" required><br><br>

        <label for="username">Username:</label>
        <input type="text" id="username" name="username" required><br><br>

        <label for="password">Password:</label>
        <input type="password" id="password" name="password" required><br><br>

        <input type="submit" value="Register">
      </form>
    </div>
  </body>
</html>

