<!DOCTYPE html>
<?php
  if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    session_start();

    $_SESSION['name'] = $_POST['name'];
    $_SESSION['surname'] = $_POST['surname'];
    $_SESSION['gender'] = $_POST['gender'];

    header('Location: sports.php');

    exit();
  }
?>
<html>
  <head>
    <title>Info</title>
  </head>
  <body>
    <h2>Enter You Information:</h2>

    <form method="POST">
      <label for="name">First Name:</label>
      <input type="text" name="name" required><br>

      <label for="surname">Last Name:</label>
      <input type="text" name="surname" required><br>

      <label for="gender">Gender:</label>
      <select name="gender" required>
        <option value="m">Male</option>
        <option value="f">Female</option>
      </select><br>

      <input type="Submit">
    </form>
  </body>
</html>
