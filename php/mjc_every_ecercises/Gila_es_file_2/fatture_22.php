<?php
$file = fopen('fatture.txt', 'r');
$file2 = fopen('clienti.txt', 'r');
$verifica = 0;

echo '<center>';

if ($file == false || $file2 == false ){
    echo 'Errore apertura file <br>';
}

else{
    while ($stringa = fgets($file)){
        $stringa = explode(';', $stringa);
        if ($stringa[5] == 22){

            $sconto = $stringa[1] * $stringa[3];
            $imponibile = $stringa[1] - $sconto;
            $imp_iva = $imponibile * $stringa[5] / 100;

            echo '<table border="2">
                <tr><td colspan="3" align="center">Numero fattura '.$stringa[0].'</td></tr>
                <tr><td>Importo fattura</td><td colspan="2" align="center">'.number_format($stringa[1], 2).'€</td></tr>
                <tr><td>Sconto</td><td colspan="2" align="center">'.number_format($sconto, 2).'€</td></tr>
                <tr><td>Imponibile</td><td colspan="2" align="center">'.number_format($imponibile, 2).'€</td></tr>
                <tr><td>Importo iva</td><td colspan="2" align="center">'.number_format($imp_iva, 2).'€</td></tr>
                <tr><td>Totale fattura</td><td colspan="2" align="center">'.number_format($imponibile + $imp_iva, 2).'€</td></tr>
              </table></t>';

            fseek($file2, 0);


        }

    }
}


echo '<br><a href="menu.html"><button>TORNA AL MENU</button></a>';

echo '</center>';

?>