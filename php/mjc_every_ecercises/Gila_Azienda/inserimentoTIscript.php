<?php

$conn = mysqli_connect('localhost', 'root', '', 'Gila_Azienda') or die("Errore connessione".mysqli_connect_error($conn));

$matricola = $_POST['matricola'];
$nome = $_POST['nome'];
$cognome = $_POST['cognome'];
$classe = $_POST['classe'];
$ida = $_POST['ida'];
$idt = $_POST['idt'];

$flag = mysqli_query($conn, "insert into Tirocinante (matricola, nome, cognome, classe, idazienda, idtutor) values ('$matricola', '$nome', '$cognome', '$classe', '$ida', '$idt');");

echo "<center>";

if (!$flag){
    echo "Errore inserimento query<br><br>";
}
else{
    echo "Inserimento query riuscito con successo<br><br>";
}

echo "<a href='inserimentoTI.php'><button>Inserisci nuovo dato</button></a>";
echo "<a href='menu.html'><button>Torna al menu'</button></a>";

echo "</center>";

mysqli_close($conn);