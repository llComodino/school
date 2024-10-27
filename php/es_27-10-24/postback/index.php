<!DOCTYPE html>
<html>
  <head>
      <title>Postback</title>
  </head>
  <body>
    <?php
      if (isset($_POST['name'])) {
        echo "<span>" . $_POST["name"] . "</span>";
      } else {
        echo "<form action=" . $_SERVER['PHP_SELF'] . " method='post'>";
        echo "<label for='name'>Name:</label>";
        echo "<input type='text' name='name' id='name'>";
        echo "<input type='submit' value='Submit'>";
        echo "</form>";
      }
    ?>
  </body>
</html>
