<!DOCTYPE html>
<?php
  require_once 'db.php';

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $trainee = [
      'name' => $_POST['name'],
      'surname' => $_POST['surname'],
      'class' => $_POST['class'],
      'company' => $_POST['company'],
      'tutor' => $_POST['tutor']
    ];

    if (insertTrainee($trainee)) {
      echo "<p>Trainee inserted successfully!</p>";
    } else {
      echo "<p>Error inserting trainee.</p>";
    }
  }
?>
<html>
  <head>
    <meta charset="utf-8">
    <title>Company | Insert Trainee</title>
  </head>
  <body>
    <h2>Insert Trainee</h2>
    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
      <label for="name">Name:</label>
      <input type="text" id="name" name="name" required><br><br>

      <label for="surname">Email:</label>
      <input type="surname" id="surname" name="surname" required><br><br>

      <label for="class">Class:</label>
      <select id="class" name="class">
        <?php
          foreach ($enums['class'] as $class) {
            echo "<option value='{$class}'>{$class}</option>";
          }
        ?>
      </select>

      <label for="company">Company:</label>
      <select id="company" name="company">
        <?php
          foreach (getCompanies() as $company) {
            echo "<option value='{$company["id"]}'>{$company["name"]}</option>";
          }
        ?>
      </select>

      <label for="tutor">Tutor:</label>
      <select id="tutor" name="tutor">
        <?php
          foreach (getTutors() as $tutor) {
            echo "<option value='{$tutor["id"]}'>{$tutor["name"]}</option>";
          }
        ?>
      </select><br><br>
      <input type="submit" value="Insert">
  </body>
</html>
