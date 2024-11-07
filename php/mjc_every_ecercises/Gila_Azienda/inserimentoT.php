<?php

$conn = mysqli_connect('localhost', 'root', '', 'Gila_Azienda') or die("Errore connessione".mysqli_connect_error($conn));

$id = $_POST['id'];
$nome = $_POST['nome'];
$cognome = $_POST['cognome'];
$materia = $_POST['materia'];

$flag = mysqli_query($conn, "insert into Tutor (id, nome, cognome, materia) values ('$id', '$nome', '$cognome', '$materia');");

echo "<center>";

if (!$flag){
    echo mysqli_error($flag)."Errore inserimento query<br><br>";
}
else{
    echo "Inserimento query riuscito con successo<br><br>";
}

echo "<a href='inserimentoT.html'><button>Inserisci nuovo dato</button></a>";
echo "<a href='menu.html'><button>Torna al menu'</button></a>";

echo "</center>";

mysqli_close($conn);