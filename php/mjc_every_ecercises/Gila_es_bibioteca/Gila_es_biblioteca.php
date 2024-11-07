<?php

echo "<b>Dati anagrafici</b> <br><br>";
echo "Nome: ".$_POST['nome']."<br>";
echo "Cognome: ".$_POST['cognome']."<br>";
echo "Data di nascita: ".$_POST['data_di_nascita']."<br>";
echo "Sesso: ".$_POST['sesso']."<br>";
echo "Indirizzo: ".$_POST['indirizzo']." ".$_POST['numciv']."<br>";
echo "Paese residenza: ".$_POST['paese']."<br>";
echo "Professione: ".$_POST['professione']."<br>";

echo "Foto: <br>";
move_uploaded_file($_FILES['foto']['tmp_name'], 'img/'.$_FILES['foto']['name']);
echo "<img src='img/".$_FILES['foto']['name']."'>";
echo "<br><br>Cata d'identità: <br>";
move_uploaded_file($_FILES['carta']['tmp_name'], 'img/'.$_FILES['carta']['name']);
echo "<img src='img/".$_FILES['carta']['name']."'>";

?>