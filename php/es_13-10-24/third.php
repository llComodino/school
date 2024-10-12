<html>
<head>
  <title>Third Page</title>
</head>
<body>
  <h1>Even or Odd</h1>
<?php

function is_even($num) {
  return $num % 2 == 0;
}

for ($i = 1; $i <= 10; $i++) {
  echo "<p>";
  if (is_even($i)) {
      echo "$i is even<br>";
  } else {
      echo "$i is odd<br>";
  }
  echo "</p>";
}
?>
</body>
</html>
