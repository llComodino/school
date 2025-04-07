<!DOCTYPE html>
<?php
  require_once './db.php';
  session_start();
?>
<html>
  <head>
    <title>Login</title>
  </head>
  <body>
    <h1>Login</h1>
    <form method="post" action="<?php $_SERVER['PHP_SELF']; ?>">
      <label for="email">Email:</label>
      <input type="email" name="email" required>
      <br>
      <label for="password">Password:</label>
      <input type="password" name="pwd" required>
      <br>
      <input type="submit" value="Login">
    </form>

  <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
      $mail = $_POST['email'];
      $password = $_POST['pwd'];

      if (log_in($mail, $password)) {
        $_SESSION['user'] = fetch_user($mail);
        setcookie("user_id", $mail, time() + (86400 * 30), "/");
        header("Location: index.php");
        exit();
      } else {
        echo "<p>Invalid email or password.</p>";
      }
    }
    ?>

    <p>Don't have an account? <a href="./register.php">Register here</a></p>
  </body>
</html>
