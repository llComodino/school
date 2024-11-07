<?php

$conn = mysqli_connect("localhost", "root", "", "Gila_Azienda") or die("Errore connessione" . mysqli_connect_error($conn));

$query = "select t.nome, t.cognome, t.materia from Azienda as a, Tutor as t, Tirocinante as ti where a.settore = 'Informatica' and ti.idazienda = a.id and ti.idtutor = t.id;";
$result = mysqli_query($conn, $query) or die(mysqli_error()."Errore query");


echo "<center><table border='2' style='text-align: center'><tr><td>NOME</td><td>COGNOME</td><td>MATERIA</td></tr>";
while ($riga = mysqli_fetch_array($result)) {
    echo "<tr><td>" . $riga['nome'] . "</td><td>" . $riga['cognome'] . "</td><td>" . $riga['materia'] . "</td></tr>";
}
echo "</table>";

echo "<br><br><a href='menu.html'><button>Torna al menu'</button></a></center>";

mysqli_close($conn);