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
?>
<html>
  <head>
    <title>Register | Company</title>
    <meta charset="UTF-8">
  </head>
  <body>
  <?php
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $employee = new Employee(
      '',
      $_POST["name"],
      $_POST["surname"],
      $_POST["filial"],
      $_POST["salary"],
      $_POST["ass_date"],
      $_POST["b_date"],
      $_POST["rcity"]
    );

    if ( $employee->insertIntoDatabase($conn) ) {
      echo "
        <h2>Succesfully sent</h2>
        <span>You are now registered</span>
      ";
    } else {
      echo "
        <h2>ERROR</h2>
        <span>Registration Failed</span>
      ";
    }
  } else {
    echo "
    <form action='".$_SERVER["PHP_SELF"]."' method='POST'>
      <legend>Register</legend>

      <input name='name' type='text' size='32' placeholder='name' required>
      <br>
      <input name='surname' type='text' size='32' placeholder='surname' required>
      <br>
      <select name='filial' required>
        <option></option>
        <option value='Rome'>Rome</option>
        <option value='Florence'>Florence</option>
        <option value='Turin'>Turin</option>
        <option value='Naples'>Naples</option>
      </select>
      <br>
      <input name='salary' type='number' step='0.1' size='32' placeholder='salary' required>
      <br>
      <input name='ass_date' type='date' placeholder='ass_date' required>
      <br>
      <input name='b_date' type='date' placeholder='ass_date' required>
      <br>
      <input name='rcity' type='text' size='32' placeholder='city' required>
      <br>

      <input type='submit' value='submit' name='submit'>
    </form>
    ";
  }
  ?>
  </body>
</html>
