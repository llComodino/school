<!DOCTYPE html>
<?php
  require_once './db.php';

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $surname = ucwords($_POST['surname']);
    $name = ucwords($_POST['name']);
    $mail = strtolower($_POST['mail']);
    $phone = $_POST['phone'];
    $city = ucwords($_POST['city']);
    $prov = strtoupper($_POST['prov']);
    $pwd = $_POST['pwd'];
    $cpwd = $_POST['cpwd'];

    if ($pwd != $cpwd) {
      echo "The password and confirm password are not the same";
      exit;
    }

    echo "<span>" . register_user($surname, $name, $mail, $phone, $city, $prov, $pwd) . "</span>";
  }
?>
<html>
  <head>
    <title>Register</title>
  </head>
  <body>
    <h1 class="generic">Register</h1>
    <hr>

    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">
      <label for="surname">Surname:</label>
      <input type="text" name="surname" required><br>

      <label for="name">name:</label>
      <input type="text" name="name" required><br>

      <label for="mail">mail:</label>
      <input type="text" name="mail" required><br>

      <label for="phone">phone:</label>
      <input type="text" name="phone" required><br>

      <label for="city">city:</label>
      <input type="text" name="city" required><br>

      <label for="prov">province:</label>
      <input type="text" name="prov" required><br>

      <label for="pwd">password:</label><input type="password" name="pwd" required><br>
      <label for="cpwd">confirm password:</label><input type="password" name="cpwd" required><br><br>

      <br>
      <input type="submit" name="submit">
    </form>
  </body>
</html>
