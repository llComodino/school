<html>
<head>
  <title>String to Date</title>
</head>
<body>
  <p>
  <?php
    $date = "2020/12/31";

    // Print day month year

    $date_array = explode("/", $date);
    echo "Day: " . $date_array[2] . "<br>";
    echo "Month: " . $date_array[1] . "<br>";
    echo "Year: " . $date_array[0] . "<br>";
  ?>
  </p>
</body>
</html>
