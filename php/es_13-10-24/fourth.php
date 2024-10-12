<html>
<head>
  <title>Fourth Page</title>
</head>
<body>
  <h1>Array Max</h1>
<?php
function max_array($arr) {
  $max = $arr[0];
  for ($i = 1; $i < count($arr); $i++) {
    if ($arr[$i] > $max) {
      $max = $arr[$i];
    }
  }
  return $max;
}

$arr = [4, 2, 5, 1, 3];
echo "<p>The max value is: " . max_array($arr) . "</p>";
?>
</body>
</html>
