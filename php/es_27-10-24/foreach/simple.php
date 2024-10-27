<!DOCTYPE html>
<html>
  <head>
    <title>Foreach</title>
  </head>
  <body>
    <?php
      $nation_capitals = [
        "USA" => "Washington D.C.",
        "France" => "Paris",
        "Germany" => "Berlin",
        "Italy" => "Rome",
        "Japan" => "Tokyo",
        "China" => "Beijing",
        "Russia" => "Moscow",
      ];
    
      foreach ($nation_capitals as $nation => $capital) {
        echo "The capital of $nation is $capital.<br>";
      }
    ?>
  </body>
</html>
