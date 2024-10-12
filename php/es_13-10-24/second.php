<html>
<head>
  <title>Second PHP</title>
</head>
<body>
  <h1>Price + IVA</h1>
<?php
function calculate_price($price, $percentage) {
  $price += $price * $percentage / 100;
  echo "The price is: $price";
}

for ($i = 0; $i < 3; $i++) {
  echo "<p>";
  calculate_price(rand(1, 100), 22);
  echo "</p>";
}
?>
</body>
</html>
