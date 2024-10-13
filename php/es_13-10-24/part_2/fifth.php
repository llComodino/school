<html>
<head>
<title>String to Camel Case</title>
</head>
<body>
  <p>
    <?php
      $str = "tHE qUicK BroWN fOx";
      echo "String: $str<br>";
      echo "Camel Case: " . ucwords(strtolower($str));
    ?>
  </p>
</body>
</html>
