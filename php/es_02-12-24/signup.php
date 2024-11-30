<!DOCTYPE html>
<html>
  <head>
    <title>Signup</title>
  </head>
  <body>
    <?php
      function already_exist($file) {
        rewind($file);
        while( ($line = fgets($file)) ) {
          if (explode(";", $line)[0] == $_POST['health_card']) return true;
        }
        return false;
      }

      function save_to_file() {
        $exit = false;
        try {
          $file = fopen("./clients.txt", "a+");

          if (!already_exist($file)) {
            fprintf($file, "%s\n", implode(";", $_POST)); 
            $exit = true;
          }
        } catch (Exception $e) {
          echo "<span>Error: $e->getMessage</span>";
        } finally {
          fclose($file);
        }

        return $exit;
      }

      if ($_SERVER['REQUEST_METHOD'] == "POST") {
        if (save_to_file()) {
          echo "<h2>Succesfully saved!</h2>";
        } else {
          echo "<h2>Failure during save</h2><p>Make sure you're not already registered</p>";
        }
      }
    ?>
    <form action="<?php $_SERVER['self'] ?>" method="post">
      <fieldset>
        <legend>Signup Form</legend>

        <label for="health_card">Health Card</label>
        <input name="health_card" type="text" required size="16" pattern="[A-Z]{6}[0-9]{2}[A-Z][0-9]{2}[A-Z][0-9]{3}[A-Z]">
        <br>

        <label for="surname">Surname</label>
        <input name="surname"     type="text" required pattern="[A-Za-z]{2,32}">
        <br>

        <label for="name">Name</label>
        <input name="name"        type="text" required pattern="[A-Za-z]{2,32}">
        <br>

        <label for="bdate">Date of Birth</label>
        <input name="bdate"       type="date" required>
        <br>

        <label for="subscription">Subscription</label>
        <select name="subscription" required>
          <option></option>
          <option>Monthly</option>
          <option>2-Month</option>
          <option>3-Month</option>
          <option>Yearly</option>
        </select>
        <br><br>

        <input type="submit" value="Submit!">
      </fieldset>
    </form>
  </body>
</html>
