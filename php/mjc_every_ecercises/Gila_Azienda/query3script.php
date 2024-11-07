<?php

$conn = mysqli_connect("localhost", "root", "", "Gila_Azienda") or die("Errore connessione" . mysqli_connect_error($conn));

$matricola = $_POST['matricola'];
$query = "select idazienda from Tirocinante where matricola = '" . $matricola . "';";
$result1 = mysqli_query($conn, $query);
$riga1 = mysqli_fetch_array($result1);

$query = "select settore, tipologia from Azienda where id = '" . $riga1['idazienda'] . "';";
$result2 = mysqli_query($conn, $query);
echo "<center> <b>Settore e tipologia " . $riga1['idazienda'] . "</b><br><br>";

echo "<table border='2' style='text-align: center'><tr><td>SETTORE</td><td>TIPOLOGIA</td></tr>";
while ($riga = mysqli_fetch_array($result2)) {
    echo "<tr><td>" . $riga['settore'] . "</td><td>" . $riga['tipologia'] . "</td></tr>";
}
echo "</table>";

echo "<br><br><a href='menu.html'><button>Torna al menu'</button></a></center>";

mysqli_close($conn);