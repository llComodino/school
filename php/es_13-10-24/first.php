<html>
<head>
  <title>First PHP</title>
</head>
<body>
  <h1>Tables</h1>
<?php
/*
1.   
Creare una funzione che stampi una tabella
composta di numeri casuali,   il numero
delle righe ed il numero  delle colonne
dovranno essere passati come  parametro.
Il programma in php dovrà visualizzare più tabelle con n. di righe  e n. di colonne diverse
*/

function print_table($rows, $cols) {
  echo "<table>";
  for ($i = 0; $i < $rows; $i++) {
    echo "<tr>";
    for ($j = 0; $j < $cols; $j++) {
      echo "<td> <span>" . rand(1, 100) . "</span> </td>";
    }
    echo "</tr>";
  }
  echo "</table>";
}

print_table(3, 4);
print_table(5, 6);
print_table(7, 8);

?>

</body>
</html>
