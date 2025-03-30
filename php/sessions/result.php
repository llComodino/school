<!DOCTYPE html>
<?php
  session_start();

  if (!isset($_SESSION['name'], $_SESSION['surname'], $_SESSION['gender']) || !isset($_POST['sport'])) {
    header('Location: index.php');
    exit();
  }

  $title = ($_SESSION['gender'] == 'm') ? 'Mr.' : 'Ms.';
  $sport = $_POST['sport'];
?>
<html>
  <head>
    <title>Result</title>
  </head>
  <body>
    <h1>Summary</h1>
    <p><?php echo "$title {$_SESSION['name']} {$_SESSION['surname']} prefers $sport."; ?></p>
  </body>
</html>
