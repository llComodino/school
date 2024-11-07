<?php

$nf = $_POST['nf'];
$if = $_POST['if'];
$df = $_POST['data'];
$ps = 0;
$cc = $_POST['cc'];
$iva = $_POST['iva'];
$verifica = 0;

echo '<center>';

$clienti = fopen('clienti.txt', 'r');
if ($clienti == false){
    echo 'Errore apertura file <br>';
}
else{
    while ($cliente = fgets($clienti)){
        $cliente = explode(';', $cliente);
        if ($cc == $cliente[0]){
            if ($if > 250){
                $ps = 0.02;
            }
            else{
                $ps = 0.015;
            }
            $stringa = $nf.';'.$if.';'.$df.';'.$ps.';'.$cc.';'.$iva;
            $fatture = fopen('fatture.txt', 'a');
            if ($clienti == false){
                echo 'Errore apertura file';
                break;
                $verifica = 1;
            }
            else{
                echo 'Fattura caricata correttamente<br><br>';
                fputs($fatture, "$stringa\n");
                fclose($fatture);
                fclose($clienti);
                $verifica = 1;
            }
            break;
        }

    }
}

if ($verifica == 0){
    echo 'Cliente non trovato, fattura non inserita<br><br>';
}

echo '<a href="menu.html"><button>TORNA AL MENU\'</button></a></p>';

echo '</center>';


?>