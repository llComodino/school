<html>
  <head>
    <title>Sixth Page</title>
  </head>
  <body>
    <h1>Calendar</h1>
  <?php
    // without cal_days_in_month
    function print_calendar($month, $year) {
      $days = [
        1 => 31,
        2 => 28,
        3 => 31,
        4 => 30,
        5 => 31,
        6 => 30,
        7 => 31,
        8 => 31,
        9 => 30,
        10 => 31,
        11 => 30,
        12 => 31
      ];

      if ($year % 4 == 0) {
        $days[2] = 29;
      }

      echo "<h2>$month/$year</h2>";
      echo "<table border='1'>";
      echo "<tr><th>Mon</th><th>Tue</th><th>Wed</th><th>Thu</th><th>Fri</th><th>Sat</th><th>Sun</th></tr>";

      $first_day = date("N", strtotime("$year-$month-01"));
      $last_day = $days[$month];

      $day = 1;
      $day_of_week = 1;
      echo "<tr>";
      for ($i = 1; $i < $first_day; $i++) {
        echo "<td></td>";
        $day_of_week++;
      }

      while ($day <= $last_day) {
        echo "<td>$day</td>";
        $day++;
        $day_of_week++;
        if ($day_of_week > 7) {
          echo "</tr><tr>";
          $day_of_week = 1;
        }
      }

      for ($i = $day_of_week; $i <= 7; $i++) {
        echo "<td></td>";
      }

      echo "</tr>";
      echo "</table>";
    }

    print_calendar(2, 2023);
    print_calendar(2, 2024);
    print_calendar(1, 2024);
  ?>

  </body>
</html>
