<?php
  session_start();
  if (!isset($_SESSION['grades'])) {
    $_SESSION['grades'] = array();
  }

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $grade = isset($_POST['grade']) ? floatval($_POST['grade']) : 0;
    if ($grade >= 0 && $grade <= 100) {
      $_SESSION['grades'][] = $grade;
    }
  }
?>

<!DOCTYPE html>
<html>
  <head>
    <title>Grade Management</title>
    <style>
      table {
        border-collapse: collapse;
        margin-bottom: 20px;
      }
      th, td {
        border: 1px solid #ddd;
        padding: 8px;
        text-align: center;
      }
      th {
        background-color: #f2f2f2;
      }
      .form-group {
        margin-bottom: 15px;
      }
    </style>
  </head>
  <body>
    <h2>Grades</h2>

    <table>
      <tr>
        <th>Grade #</th>
        <th>Value</th>
      </tr>
      <?php
        foreach ($_SESSION['grades'] as $index => $grade) {
          echo "<tr>";
          echo "<td>" . ($index + 1) . "</td>";
          echo "<td>$grade</td>";
          echo "</tr>";
        }
      ?>
    </table>

    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
      <div class="form-group">
        <label for="grade">Enter Grade (0-10):</label><br>
        <input type="number" name="grade" id="grade" min="0" max="10" step="0.5" required>
      </div>
      <input type="submit" value="Add Grade">
    </form>
  </body>
</html>
