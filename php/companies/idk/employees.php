<!DOCTYPE html>
<?php
  include('Employee.php');

  $user = 'register';
  $dbname = 'company';
  $hostname = 'localhost';
  $pwd = 'tmppwd1!';

  try {
    $conn = new PDO("mysql:host=$hostname;dbname=$dbname", $user, $pwd);
  } catch (PDOException $e) {
    var_dump($e);
  } finally {
    if ( $conn == null ) return;
  }

  function getEmployees($conn, $query): array {
    $stmt = $conn->query($query);

    return $stmt->fetchAll(PDO::FETCH_ASSOC);
  }

  function constructQuery($data) {
    $query = "SELECT * FROM employee e WHERE\n";

    if ($data["salary"]) {
      $query .= "e.salary >= ".$data["salary"]." AND\n";
    }

    if ($data["age"]) {
      $query .= "YEAR(e.b_date) - YEAR(curdate()) >= ".$data["age"]." AND\n";
    }

    if ($data["month"]) {
      $query .= "MONTH(e.b_date) = ".$data["month"]." AND\n";
    }

    if ($data["filial"]) {
      $query .= "e.filial = '".$data["filial"]."' AND\n";
    }

    return substr($query, 0, strlen($query) - 4);
  }

  $query = "SELECT * FROM employee";
  $employees = getEmployees($conn, $query);

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $query = constructQuery($_POST);
    $employees = getEmployees($conn, $query);
  }
?>
<html>
  <head>
    <title>Employees</title>

    <style>
      table, td, th {
        border: 1px solid black;
        border-collapse: collapse;
      }

      td, th {
        padding: 0.4rem;
      }

      form * {
        margin: 1rem;
      }
    </style>
  </head>
  <body>
    <h2>Employees</h2>
    <form action="<?php $_SERVER["PHP_SELF"] ?>" method="POST">
      <label for="filial">Filial:</label>
      <select name="filial">
        <option></option>
        <option>Milan</option>
        <option>Turin</option>
        <option>Rome</option>
        <option>Naples</option>
      </select>

      <select name="month">
        <option></option>
        <option value="1">January</option>
        <option value="2">February</option>
        <option value="3">March</option>
        <option value="4">April</option>
        <option value="5">May</option>
        <option value="6">June</option>
        <option value="7">July</option>
        <option value="8">August</option>
        <option value="9">September</option>
        <option value="10">October</option>
        <option value="11">November</option>
        <option value="12">December</option>
      </select>

      <input type="number" name="age" placeholder="min age">
      <input type="number" name="salary" placeholder="min salary">

      <input type="submit" name="submit">
    </form>
    <table>
      <thead>
        <tr>
          <th><span>Code</span></th>
          <th><span>Name</span></th>
          <th><span>Surname</span></th>
          <th><span>Filial</span></th>
          <th><span>Salary</span></th>
          <th><span>Association Date</span></th>
          <th><span>Birth Date</span></th>
          <th><span>Residence City</span></th>
        </tr>
      </thead>
      <tbody>
        <?php
          foreach ($employees as $employee) {
            echo "<tr>";
            foreach ($employee as $k => $v) {
              echo "<td><span>$v</span></td>";
            }
            echo "</tr>";
          }
        ?>
      </tbody>
    </table>
  </body>
</html>
