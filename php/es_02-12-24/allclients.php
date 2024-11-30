<!DOCTYPE html>
<html>
  <head>
    <title>All Clients Info</title>
  </head>
  <body>
    <?php
      require_once './shared.php';

      try {
        $file = fopen("./clients.txt", "r");
        while ( ($line = fgets($file)) ) {
          print_info(explode(";", $line));
        }
      } catch (Exception $e) {
        echo "Error: $e->getMessage()";
      } finally {
        fclose($file);
      }
    ?>
  </body>
</html>
