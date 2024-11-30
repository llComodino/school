<!DOCTYPE html>
<html>
  <head>
    <title>Clients under 18 and Over 64</title>
  </head>
  <body>
    <?php
      require_once './shared.php';

      try {
        $file = fopen("./clients.txt", "r");
        while( ($line = fgets($file)) ) {
          $bdate = explode(";", $line)[3];
          if (is_target_age($bdate)) {
            print_info(explode(";", $line));
          }
        }
      } catch (Exception $e) {
      } finally {
        fclose($file);
      }
    ?>
  </body>
</html>
