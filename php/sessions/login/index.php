<!DOCTYPE html>
<?php
  require_once './db.php';

  session_start();

  if (!isset($_SESSION['user'])) {
    if (isset($_COOKIE['user_id'])) {
      $user_id = $_COOKIE['user_id'];
      $_SESSION['user'] = fetch_user($user_id);
    } else {
      header("Location: login.php");
      exit();
    }
  }

  $user = $_SESSION['user'];
?>
<html>
  <head>
    <title>User Information</title>
  </head>
  <body>
    <h1>User Information</h1>
    <p><strong>Name:</strong> <?php echo htmlspecialchars($user['name']); ?></p>
    <p><strong>Email:</strong> <?php echo htmlspecialchars($user['mail']); ?></p>
    <p><strong>Phone:</strong> <?php echo htmlspecialchars($user['phone']); ?></p>
    <a href="./logout.php">Logout</a>
  </body>
</html>
