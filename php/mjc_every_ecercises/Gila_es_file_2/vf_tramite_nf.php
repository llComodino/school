<?php

$file = fopen('fatture.txt', 'r');
$file2 = fopen('clienti.txt', 'r');
$verifica = 0;

echo '<center>';

if ($file == false || $file2 == false ){
    echo 'Errore apertura file <br>';
}

else{
    $nf = $_POST['nf'];
    while ($stringa = fgets($file)){
        $stringa = explode(';', $stringa);
        if ($stringa[0] == $nf){
            while ($cliente = fgets($file2)){
                $cliente = explode(';', $cliente);


                if ($cliente[0] == $stringa[4]){

                    $sconto = $stringa[1] * $stringa[3];
                    $imponibile = $stringa[1] - $sconto;
                    $imp_iva = $imponibile * $stringa[5] / 100;

                    echo '<table border="2">
                            <tr><td colspan="3" align="center">Numero fattura '.$nf.'</td></tr>
                            <tr><td>Cliente '.$cliente[1].' '.$cliente[2].'</td><td>Data fat. '.$stringa[2].'</td><td>Data cor. '.date('d/m/y').'</td></tr>
                            <tr><td>Importo fattura</td><td colspan="2" align="center">'.number_format($stringa[1], 2).'€</td></tr>
                            <tr><td>Sconto</td><td colspan="2" align="center">'.number_format($sconto, 2).'€</td></tr>
                            <tr><td>Imponibile</td><td colspan="2" align="center">'.number_format($imponibile, 2).'€</td></tr>
                            <tr><td>Importo iva</td><td colspan="2" align="center">'.number_format($imp_iva, 2).'€</td></tr>
                            <tr><td>Totale fattura</td><td colspan="2" align="center">'.number_format($imponibile + $imp_iva, 2).'€</td></tr>
                          </table>';

                    $verifica = 1;
                }

            }



        }

    }
}

if ($verifica == 0){
    echo 'Fattura non registrata';
}

echo '<br><a href="menu.html"><button>TORNA AL MENU</button></a>';

echo '</center>';

?>