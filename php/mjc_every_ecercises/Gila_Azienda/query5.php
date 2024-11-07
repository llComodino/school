<?php

$conn = mysqli_connect("localhost", "root", "", "Gila_Azienda") or die("Errore connessione" . mysqli_connect_error($conn));

$query = "select a.luogo from Azienda as a, Tutor as t, Tirocinante as ti where t.nome = 'Mario' and t.cognome = 'Rossi' and ti.idazienda = a.id and ti.idtutor = t.id;";
$result = mysqli_query($conn, $query);


echo "<center><table border='2' style='text-align: center'><tr><td>LUOGO</td></tr>";
while ($riga = mysqli_fetch_array($result)) {
    echo "<tr><td>" . $riga['luogo'] . "</td></tr>";
}
echo "</table>";

echo "<br><br><a href='menu.html'><button>Torna al menu'</button></a></center>";

mysqli_close($conn);