<!DOCTYPE html>
<html>
  <head>
    <title>Module Received</title>
  </head>
  <body>
    <h2>Module Received</h2>
    <p>Thank you for your submission.</p>
    <p>The module you have received is:</p>
    <?php
      foreach ($_POST as $key => $value) {
        echo "<p><strong>$key</strong>: $value</p>";
      }
    ?>
  </body>
</html>
