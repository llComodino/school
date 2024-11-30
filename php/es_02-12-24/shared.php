<?php
  function print_info($info) {
    echo "<p>";
    echo "<span>Health Card: " . $info[0] . "</span><br>";
    echo "<span>Surname: " . $info[1] . "</span><br>";
    echo "<span>Name: " . $info[2] . "</span><br>";
    echo "<span>Birth Date: " . $info[3] . "</span><br>";
    echo "<span>Subscription: " . $info[4] . "</span><br>";
    echo "</p>";
  }

  function is_target_age($bdate) {
    $dob = new DateTime($bdate);
    $today = new DateTime('today');

    $age = $dob->diff($today)->y;

    return ($age < 18 || $age > 64);
  }
?>
