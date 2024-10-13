<html>
<head>
  <title>Vowels in String</title>
</head>
<body>
  <p>
  <?php
    $string = "Hello World";
    echo "String: $string<br>";

    $vowels = array("a", "e", "i", "o", "u");

    $vowel_count = 0;
    foreach (str_split($string) as $char) {
      if (in_array(strtolower($char), $vowels)) {
        $vowel_count++;
      }
    }

    echo "Number of vowels in the string (w/out `substr_count`): $vowel_count";

    echo "<br>";

    echo "Number of vowels in the string (w `substr_count`): " .
          substr_count(strtolower($string), "a") +
          substr_count(strtolower($string), "e") +
          substr_count(strtolower($string), "i") +
          substr_count(strtolower($string), "o") +
          substr_count(strtolower($string), "u");
  ?>
  </p>
</body>
</html>
