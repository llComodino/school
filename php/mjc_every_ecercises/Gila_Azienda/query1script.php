<?php

$conn = mysqli_connect("localhost", "root", "", "Gila_Azienda") or die("Errore connessione" . mysqli_connect_error($conn));

$ida = $_POST['ida'];
$query = "select nome, cognome from Tirocinante where idazienda = '" . $ida . "';";
$result = mysqli_query($conn, $query);
$numrows = mysqli_num_rows($result);

echo "<center> <b>DATI ALUNNI AZIENDA " . $ida . "</b><br><br>";
if ($numrows == 0) {
    echo "Nessun alunno presente!";
} else {
    echo "<table border='2' style='text-align: center'><tr><td>NOME</td><td>COGNOME</td></tr>";
    while ($riga = mysqli_fetch_array($result)) {
        echo "<tr><td>" . $riga['nome'] . "</td><td>" . $riga['cognome'] . "</td></tr>";
    }
    echo "</table>";
}
echo "<br><br><a href='menu.html'><button>Torna al menu'</button></a></center>";

mysqli_close($conn);