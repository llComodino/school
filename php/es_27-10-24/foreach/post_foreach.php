<!DOCTYPE html>
<html>
  <head>
    <title>POST Method</title>
  </head>
  <body>
    <?php
      foreach ($_POST["names"] as $key => $value) {
        echo "names[" . $key . "]" . " => " . $value . "<br>";
      }
    ?>
  </body>
