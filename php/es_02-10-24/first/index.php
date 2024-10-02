<html lang="en">
  <head>
    <title>Rand Array</title>
  </head>
  <body>
    <?php
      $arr = array();
      
      for ($i = 0; $i < 10; $i++) {
        array_push($arr, rand(60, 100));
      }

      foreach ( $arr as $val ) {
        echo "Val: " . $val . "<br>";
      }
    ?>
  </body>
</html>
