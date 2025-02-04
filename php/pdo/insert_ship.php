<?php
include('Ship.php');
require_once 'store.php';

$servername = "localhost";
$username = "root";
$dbname = "ship";

try {
  $conn = new PDO("mysql:host=$servername;dbname=$dbname", $username);
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch(PDOException $e) {
  echo "Connection failed: " . $e->getMessage();
  return;
}
?>

<!DOCTYPE html>
<html>
  <head>
    <title>MySQL Usage Throuh PDO</title>
    <meta charset="UTF-8">
  </head>
  <body>

<?php
if ($conn == null) {
  echo "No active connection to the db";
} else {
  if (isset($_POST["submitted"])) {
    $ship = new Ship(
      $_POST["code"],
      $_POST["name"],
      $_POST["nation"],
      date($_POST["date"]),
      $_POST["length"],
      $_POST["width"],
      $_POST["power"]
    );

    saveToDatabase($conn, 'ships', $ship);

    echo "<p>Submitted</p>";
  } else {
    echo "
    <form action='".$_SERVER['PHP_SELF']."' method='post'>
      <legend>Ship</legend>

      <label for='code'>Code:</label><br>
      <input type='text' name='code' required pattern='[A-Za-z0-9]{16}'>   <br>

      <label for='name'>Name:</label><br>
      <input type='text' name='name' required>   <br>

      <label for='nation'>Nation:</label><br>
      <input type='text' name='nation' required pattern='[A-Za-z]{2}'> <br>

      <label for='date'>Date:</label><br>
      <input type='date' name='date' required>   <br>

      <label for='length'>Length:</label><br>
      <input type='number' name='length' required step='0.1'> <br>

      <label for='Width'>Width:</label><br>
      <input type='number' name='width' required step='0.1'>  <br>

      <label for='power'>Power:</label><br>
      <input type='number' name='power' required step='0.1'>  <br>

      <br><br>
      <input type='submit' value='submit' name='submitted' id='submit'>
    </form>";
  }
}
?>

    <footer>
      <a href="./index.html">Go Back</a>
    </footer>
  </body>
</html>
