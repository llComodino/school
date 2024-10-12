<html>
  <head>
    <title>Eighth Page</title>
  </head>
  <body>
    <h1>Calculate Age</h1>
  <? 
    function calculate_age($birth_date) {
      $birth_date = new DateTime($birth_date);
      $current_date = new DateTime();
      $diff = $current_date->diff($birth_date);
      return $diff->y;
    }

    $birth_dates = ["1990-01-01", "1980-02-02", "1970-03-03"];

    foreach ($birth_dates as $birth_date) {
      echo "<p>";
      echo "Birth date: $birth_date<br>";
      echo "Age: " . calculate_age($birth_date) . "<br>";
      echo "</p>";
    }
  ?>
  </body>
</html>
