<?php

$subjects = [
  "Maths" => [ "grades" => [], "failed" => 0 ],
  "English" => [ "grades" => [], "failed" => 0 ],
  "Science" => [ "grades" => [], "failed" => 0 ],
  "History" => [ "grades" => [], "failed" => 0 ],
  "Geography" => [ "grades" => [], "failed" => 0 ],
  "Art" => [ "grades" => [], "failed" => 0 ],
  "Music" => [ "grades" => [], "failed" => 0 ],
  "Drama" => [ "grades" => [], "failed" => 0 ],
  "PE" => [ "grades" => [], "failed" => 0 ],
  "IT" => [ "grades" => [], "failed" => 0 ],
  "gpa" => 0,
];

foreach ($subjects as &$subject) {
  if (is_array($subject))
    for ($j = 0; $j < 10; $j++) {
      array_push($subject["grades"], rand(3, 10)); // Range 3 to 10 to make it feasible to pass
    }
}
unset($subject);

$count = 0;
foreach ($subjects as $key => &$subject) {
  if ($key == "gpa") continue;
  $avg = array_sum($subject["grades"]) / count($subject["grades"]);
  $subjects["gpa"] += $avg;
  if ($avg < 6) {
    $subject["failed"] = 1;
    $count++;
  }
}
unset($subject);

$subjects["gpa"] /= count($subjects);

?>

<html lang='en'>
  <head>
    <title>Grades</title>
    <style>
      table {
        border-collapse: collapse;
      }
      th, td {
        border: 1px solid black;
        padding: 5px;
      }
    </style>
  </head>
  <body>
    <?php
    echo "
      <table>
        <thead>
        <tr>
    ";
    foreach ($subjects as $subject => $values) {
      echo "<th><span>$subject</span></th>";
    }
    echo "</tr>";

    echo "</thead>";
    echo "<tbody>";

    foreach ($subjects as $subject) {
      echo "<tr>";
      foreach ($subject["grades"] as $grade) {
        if ($grade < 6) {
          echo "<td style='color: red;'>$grade</td>";
        } else {
          echo "<td>$grade</td>";
        }
      }
      echo "</tr>";
    }

    echo "<tr>";

    foreach ($subjects as $key => $subject) {
      if ($key == "gpa") {
        printf("<td><span>%.2f</span></td>", $subjects["gpa"]);
      } else {
        if ($subject["failed"]) {
          echo "<td style='color: red;'>Fail</td>";
        } else {
          echo "<td style='color: green;'>Pass</td>";
        }
      }
    }

    echo "</tr>";
    echo "</tbody>";
    echo "</table>";

    echo "Overall: ";

    if ($count >= 3) {
      echo "<span style='color: red'>Failed</span>";
    } else if ($count < 3 && $count > 1) {
      echo "<span style='color: orange'>Pending</span>";
    } else {
      echo "<span style='color: green'>Passed</span>";
    }

    ?>
  </body>
</html>
