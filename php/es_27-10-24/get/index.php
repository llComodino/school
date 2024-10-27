<!DOCTYPE html>
<html>
  <head>
    <title>GET</title>
  </head>
  <body>
    <?php
      $server = $_SERVER['PHP_SELF'];
      // gets maker and model from a GET request
      // the URL should look like this: http://localhost/index.php?maker=Toyota&model=Corolla
      // the normal page is a collection of links to JDM cars
      if (isset($_GET['maker']) && isset($_GET['model'])) {
        echo "<span>Maker: " . $_GET['maker'] . "</span><br><span>Model: " . $_GET['model'] . "</span>";
      } else {
        echo "<h1>Japanese Cars</h1>";
        echo "<ul>";
        echo "<li><a href='$server?maker=Toyota&model=Corolla'>Toyota Corolla</a></li>";
        echo "<li><a href='$server?maker=Nissan&model=Skyline'>Nissan Skyline</a></li>";
        echo "<li><a href='$server?maker=Mitsubishi&model=Lancer'>Mitsubishi Lancer</a></li>";
        echo "<li><a href='$server?maker=Subaru&model=WRX'>Subaru WRX</a></li>";
        echo "</ul>";
      }
    ?>
  </body>
</html>
