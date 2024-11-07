<?php

$verifica = 0;


echo '<center>';
$file = fopen('dati.txt', 'r');
if ($file == false) {
    echo '<p align="center">Impossibile aprire il file, ricerca non disponibile</p>';
}
else{
    while ($stringa = fgets($file)){
        $stringa = explode(';', $stringa);
        if ($stringa[0] == $_POST['nome'] && $stringa[1] == $_POST['cognome']) {
            echo 'Persona trovata, codice fiscale: ' . $stringa[4].'<br><br>';
            $verifica = 1;
            break;
        }
    }
    if ($verifica == 0){
        echo 'Persona non trovata<br><br>';
    }
}
echo '<a href="es2_file_testo_1.php"><button>TORNA ALLA HOME</button></a>  <a href="es2_file_testo_4.html"><button>NUOVA RICERCA</button></a>';

echo '</center>';


?>