<!DOCTYPE html>
<html>
  <head>
    <title>Search</title>
  </head>
  <body>
    <?php
      require_once './shared.php';

      function search() {
        $info = null;
        try {
          $file = fopen("./clients.txt", "r");
          while ( ($val = fgets($file)) ) {
            if (explode(";", $val)[0] == $_POST['hc']) {
              $info = $val;
              break;
            }
          }
        } catch (Exception $e) {
          echo "Error: " . $e->getMessage() . "<br>";
        } finally {
          fclose($file);
        }

        return $info;
      }

      function print_subscription_info($info) {
        $base_cost = 45.0;
        if (is_target_age($info[3])) {
          $base_cost = 35.0;
        }

        $info[4] = substr($info[4], 0, -1);

        if ($info[4] === "Monthly") {
          echo "<span>$base_cost $</span>";
        } else if ($info[4] == "2-Month") {
          echo "<span>" . ($base_cost - ($base_cost / 10)) * 2 . " $</span>";
        } else if ($info[4] == "3-Month") {
          echo "<span>" . ($base_cost - (3 * $base_cost / 20)) * 3 . " $</span>";
        } else {
          echo "<span>" . ($base_cost - ($base_cost / 5)) * 12 . " $</span>";
        }
      }

      if ($_SERVER['REQUEST_METHOD'] == "POST") {
        $info = explode(";", search());
        if ($info) {
          print_info($info);
          print_subscription_info($info);
        } else {
          echo "<h2>No client found with health card: " . $_POST['hc'] . "</h2>";
        }
      }
    ?>
    <form action="<?php $_SERVER['self'] ?>" method="post">
      <label for="hc">Health Card</label>
      <input name="hc" type="text" required size="16" pattern="[A-Z]{6}[0-9]{2}[A-Z][0-9]{2}[A-Z][0-9]{3}[A-Z]">
      <input type="submit">
    </form>
  </body>
</html>
