<!DOCTYPE html>
<html>
  <head>
    <title>Smaller</title>
  </head>
  <body>
    <h2>Smaller number calculator</h2>
      <form action="<?php echo $_SERVER['PHP_SELF']; ?>" method="post">
      <label for="num1">First number:</label>
      <input type="text" name="num1" id="num1">
      <label for="num2">Second number:</label>
      <input type="text" name="num2" id="num2">
      <input type="submit" value="Submit">

      <?php
        if (!empty($_POST['num1']) && !empty($_POST['num2'])) {
          if ($_POST['num1'] < $_POST['num2']) {
            echo "<p>" . $_POST['num1'] . " is smaller than " . $_POST['num2'] . "</p>";
          } else {
            echo "<p>" . $_POST['num2'] . " is smaller than " . $_POST['num1'] . "</p>";
          }
        } else {
          echo "<p>Please enter two numbers</p>";
          header("Refresh: 2; URL=smaller.php");
        }
      ?>
  </body>
</html>
