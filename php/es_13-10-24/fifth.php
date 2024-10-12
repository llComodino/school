<html>
  <head>
    <title>Fifth Page</title>
  </head>
  <body>
    <h1>Trimmed String</h1>
  <?php
    function trim_string($str) {
      return trim($str);
    }

    $strings = ["  Hello  ", "  World  ", "  PHP  "];
    foreach ($strings as $string) {
      echo "<p>";
      echo "Original: $string<br>";
      echo "Trimmed: " . trim_string($string) . "<br>";
      echo "</p>";
    }
  ?>
  </body>
</html>
