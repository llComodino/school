<!DOCTYPE html>
<html>
  <head>
    <title>Minefield</title>
    <style>
      table {
        border-collapse: collapse;
      }
      td {
        padding: 2rem;
        text-align: center;
        font-size: 80px;
      }
      .moves {
        color: green;
        font-size: 24px;
        margin-bottom: 20px;
      }
      .message {
        font-size: 24px;
        margin: 20px 0;
      }
    </style>
  </head>
  <body>
    <?php
      session_start();
      if (!isset($_SESSION['safe_moves'])) {
        $_SESSION['safe_moves'] = 0;
        $_SESSION['revealed'] = array();
      }
      $server = $_SERVER['PHP_SELF'];
      $mines = array(
        array(0, 0),
        array(1, 1),
        array(2, 2)
      );
      function isRevealed($x, $y) {
        return in_array("$x,$y", $_SESSION['revealed']);
      }
      function resetGame() {
        $_SESSION['safe_moves'] = 0;
        $_SESSION['revealed'] = array();
      }
      if (isset($_GET['restart'])) {
        resetGame();
        header("Location: $server");
        exit;
      }
      if (isset($_GET['x']) && isset($_GET['y'])) {
        $x = $_GET['x'];
        $y = $_GET['y'];
        $_SESSION['revealed'][] = "$x,$y";
        $hit = false;
        foreach ($mines as $mine) {
          if ($mine[0] == $x && $mine[1] == $y) {
            $hit = true;
            break;
          }
        }
        if ($hit) {
          echo "<h1>Game Over!</h1>";
          echo "<p class='message'>You hit a mine at $x, $y</p>";
          echo "<a href='$server?restart=1'>Play again</a>";
          resetGame();
        } else {
          $_SESSION['safe_moves']++;
          if ($_SESSION['safe_moves'] >= 3) {
            echo "<h1>You Win!</h1>";
            echo "<p class='message'>Congratulations! You found 3 safe spots!</p>";
            echo "<a href='$server?restart=1'>Play again</a>";
            resetGame();
          } else {
            echo "<h1>Safe Move!</h1>";
            echo "<p class='moves'>Safe moves: {$_SESSION['safe_moves']}/3</p>";
            echo "<p class='message'>Keep going! Find " . (3 - $_SESSION['safe_moves']) . " more safe spots!</p>";
            echo "<a href='$server'>Continue playing</a>";
          }
        }
      } else {
        echo "<h1>Minefield</h1>";
        echo "<p class='moves'>Safe moves: {$_SESSION['safe_moves']}/3</p>";
        echo '<table border=1>';
        for ($i = 0; $i < 3; $i++) {
          echo "<tr>";
          for ($j = 0; $j < 3; $j++) {
            if (isRevealed($i, $j)) {
              $isMine = false;
              foreach ($mines as $mine) {
                if ($mine[0] == $i && $mine[1] == $j) {
                  $isMine = true;
                  break;
                }
              }
              echo "<td>" . ($isMine ? "X" : "V") . "</td>";
            } else {
              echo "<td><a href='$server?x=$i&y=$j'>?</a></td>";
            }
          }
          echo "</tr>";
        }
        echo "</table>";
      }
    ?>
  </body>
</html>
