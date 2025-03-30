<!DOCTYPE html>
<?php
  session_start();

  if (!isset($_SESSION['name'], $_SESSION['surname'], $_SESSION['gender'])) {
    header('Location: index.php');
    exit();
  }

  $title = ($_SESSION['gender'] == 'm') ? 'Mr.' : 'Ms.';
?>
<html>
  <head>
    <title>Sport Selection</title>
  </head>
  <body>
    <h1>Welcome, <?php echo $title . ' ' . $_SESSION['name'] . ' ' . $_SESSION['surname']; ?></h1>

    <form method="POST" action="result.php">
      <label for="sport">Select your favorite sport:</label>
      <select name="sport" required>
        <option value="Baseball">Baseball</option>
        <option value="Basketball">Basketball</option>
        <option value="Football">Football</option>
        <option value="Cricket">Cricket</option>
      </select><br>

      <input type="submit" value="Submit">
    </form>
  </body>
</html>
