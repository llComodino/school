<!DOCTYPE html>
<?php
  require_once 'db.php';

  $companies = [];
  $trainee = null;
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $trainee = getTraineeFromName($_POST['name'], $_POST['surname'])[0];
    foreach (getCompanies() as $company) {
      if ($trainee["id_company"] == $company["id"]) {
        array_push($companies, $company);
      }
    }
  }
?>
<html>
  <head>
    <title>Company | Query</title>

    <style>
      table {
        width: 100%;
        border-collapse: collapse;
      }

      th, td {
        border: 1px solid black;
        padding: 8px;
        text-align: left;
      }
    </style>
  </head>
  <body>
    <h2>Find Sector and Type of Company</h2>
    <form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>" method="post">
      <label for="name">Name:</label>
      <input type="text" id="name" name="name" required>
      <br>

      <label for="surname">Surname:</label>
      <input type="text" id="surname" name="surname" required>
      <br>

      <input type="submit" value="Submit">

    <?php
      if (isset($_SERVER["REQUEST_METHOD"]) == "POST") {
        echo "<h3>Companies from which {$trainee["name"]} {$trainee["surname"]} has worked</h1>";
        echo "<table>";
        echo "<tr><th>Sector</th><th>Kind</th></tr>";
        foreach ($companies as $company) {
          echo "<tr>";
          echo "<td>" . $company["sector"] . "</td>";
          echo "<td>" . $company["kind"] . "</td>";
          echo "</tr>";
        }
      }
    ?>
  </body>
</html>
