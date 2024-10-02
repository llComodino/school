<?php
echo "
<html lang=\"en\">

<head>
    <title>Rand Array</title>
</head>
<body>
";
  
  $numbers = array(10,3,1,100,230,56,33,53,91,24);

  echo "<h2>Array content:</h2>";

  echo "<p>";
  foreach ($numbers as $number) {
    echo $number . " ";
  }
  echo "</p>";

  echo "<h2>Array content in reverse order:</h2>";

  echo "<p>";
  for ($i = count($numbers) - 1; $i >= 0; $i--) {
    echo $numbers[$i] . " ";
  }
  echo "</p>";

  $min = $numbers[0];
  $max = $numbers[0];
  $sum = 0;

  foreach ($numbers as $number) {
    $sum += $number;
    if ($number < $min) {
      $min = $number;
    }
    if ($number > $max) {
      $max = $number;
    }
  }

  $even = array();
  $odd = array();

  foreach ($numbers as $number) {
    if ($number % 2 == 0) {
      array_push($even, $number);
    } else {
      array_push($odd, $number);
    }
  }
  
  echo "<p>";
  echo "<b>Min</b>: $min<br>";
  echo "<b>Max</b>: $max<br>";

  $average = $sum / count($numbers);

  echo "<b>Average</b>: $average<br>";
  echo "</p>";

  echo "<p>";

  echo "<b>Even numbers</b>: ";
  foreach ($even as $number) {
    echo $number . " ";
  }

  echo "<br>";

  echo "<b>Odd numbers</b>: ";
  foreach ($odd as $number) {
    echo $number . " ";
  }

  echo "</p>";

echo "
</body>
</html>
";
?>
