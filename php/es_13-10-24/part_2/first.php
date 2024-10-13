<html>
<head>
<title>Number Array</title>
</head>
<body>
  <p>
  <?php
    $numbers = array(10, 3, 1, 100, 230, 56, 33, 53, 91, 24);
    echo "The numbers are: ";
    foreach ($numbers as $value) {
      echo "$value ";
    }

    echo "<br>";

    echo "The numbers in reverse order are: ";
    foreach (array_reverse($numbers) as $value) {
      echo "$value ";
    }

    echo "<br>";
    
    echo "Maximum number is: " . max($numbers) . "<br>";
    echo "Minimum number is: " . min($numbers) . "<br>";
    echo "Average of the numbers is: " . array_sum($numbers) / count($numbers) . "<br>";

    $even = array();
    $odd = array();

    foreach ($numbers as $value) {
      if ($value % 2 == 0) {
        array_push($even, $value);
      } else {
        array_push($odd, $value);
      }
    }

    echo "Even numbers are: ";
    foreach ($even as $value) {
      echo "$value ";
    }

    echo "<br>";

    echo "Odd numbers are: ";
    foreach ($odd as $value) {
      echo "$value ";
    }

  ?>
  </p>
</body>
</html>
