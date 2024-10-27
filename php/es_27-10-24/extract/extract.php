<!DOCTYPE html>
<html>
  <head>
    <title>Extract</title>
  </head>
  <body>
    <h2>POST Data</h2>
    <?php
      // Extract e' una pessima idea
      foreach ($_POST as $key => $value) {
        echo "$key: $value<br>";
      }
    ?>
  </body>
</html>
