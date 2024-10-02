<?php
echo "
<html lang=\"en\">

<head>
    <title>Rand Array</title>
</head>

<body>
";
  
  $even_sum = 0;
  $odd_sum = 0;
  for ($i = 1; $i <= 10; $i++) {
    if ($i % 2) {
      $odd_sum += $i;
    } else {
      $even_sum += $i;
    }
  }

  echo "<p>Sum of even numbers: $even_sum</p>";
  echo "<p>Sum of odd numbers: $odd_sum</p>";

echo "
</body>
</html>
";
?>
