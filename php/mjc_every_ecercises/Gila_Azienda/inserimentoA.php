<?php

$conn = mysqli_connect('localhost', 'root', '', 'Gila_Azienda') or die("Errore connessione".mysqli_connect_error($conn));

$id = $_POST['id'];
$nome = $_POST['nome'];
$luogo = $_POST['luogo'];
$settore = $_POST['settore'];
$tipologia = $_POST['tipologia'];

$flag = mysqli_query($conn, "insert into Azienda (id, nome, luogo, settore, tipologia) values ('$id', '$nome', '$luogo', '$settore', '$tipologia');");

echo "<center>";

if (!$flag){
    echo "Errore inserimento query<br><br>";
}
else{
    echo "Inserimento query riuscito con successo<br><br>";
}

echo "<a href='inserimentoA.html'><button>Inserisci nuovo dato</button></a>";
echo "<a href='menu.html'><button>Torna al menu'</button></a>";

echo "</center>";

mysqli_close($conn);