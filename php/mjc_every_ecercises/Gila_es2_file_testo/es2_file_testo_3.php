<?php

$file = fopen('dati.txt', 'r');
if ($file == false){
    echo '<p align="center">Impossibile aprire il file</p>';
}
else{
    echo "<center><table border='2'><tr><td><b>Nome</b></td><td><b>Cognome</b></td><td><b>Data di nascita</b></td><td><b>Luogo di nascita</b></td><td><b>Cofice Fiscale</b></td><td><b>Username</b></td><td><b>Professione</b></td><td><b>Foto tessera</b></td></tr>";
    while($riga = fgets($file)){
        $riga = explode(';', $riga);
        echo "<tr><td>$riga[0]</td><td>$riga[1]</td><td>$riga[2]</td><td>$riga[3]</td><td>$riga[4]</td><td>$riga[5]</td><td>$riga[6]</td><td><img src=$riga[7] width='100'></td></tr>";
    }
    echo "</table></center>";
}
fclose($file);

echo '<p align="center"><a href="es2_file_testo_1.php"><button>TORNA ALLA HOME</button></a></p>';

?>