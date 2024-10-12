<html>
  <head>
    <title>Seventh PHP</title>
  </head>
  <body>
    <h1>Date</h1>
  <?php
    function next_day($date) {
      return date('Y-m-d', strtotime($date . ' +1 day'));
    }

    function next_week($date) {
      return date('Y-m-d', strtotime($date . ' +1 week'));
    }

    function next_friday($date) {
      $day = date('N', strtotime($date));
      $diff = 5 - $day;
      if ($diff < 0) {
        $diff += 7;
      }
      return date('Y-m-d', strtotime($date . " +$diff days"));
    }

    function last_monday($date) {
      $day = date('N', strtotime($date));
      $diff = $day - 1;
      return date('Y-m-d', strtotime($date . " -$diff days"));
    }

    function christmas($year) {
      return date('Y-m-d', strtotime("$year-12-25"));
    }

    $today = date('Y-m-d');
    echo "<p>Today is: $today</p>";
    echo "<p>Next day is: " . next_day($today) . "</p>";
    echo "<p>Next week is: " . next_week($today) . "</p>";
    echo "<p>Next Friday is: " . next_friday($today) . "</p>";
    echo "<p>Last Monday was: " . last_monday($today) . "</p>";
    echo "<p>Christmas is: " . christmas(date('Y')) . "</p>";
  ?>
  </body>
</html>
