<?php
$pf = 0;
if ($_POST['anni_conducente'] < 25){
    $pf += 12.50;
}
switch ($_POST['macchina']){
    case 'FIAT PANDA (€25)':
        $pf += 25*$_POST['n_giorni'];
        break;
    case 'MERCEDES CLASSE A (€100)':
        $pf += 100*$_POST['n_giorni'];
        break;
    case 'BMW SERIE 3 (€150)':
        $pf += 150*$_POST['n_giorni'];
        break;
    case 'MERCEDES CLASSE S (€200)':
        $pf += 200*$_POST['n_giorni'];
        break;
}
if ($_POST['n_giorni'] > 3){
    $pf -= 5*$_POST['n_giorni'];
}

echo '<fieldset>';
echo 'Gentile Sig. '.$_POST['cognome'].' '.$_POST['nome'].' la sua prenotazione per il giorno '.$_POST['data'].' è stata accettata.<br>';
echo "Al momento del ritiro, dovrà saldare un conto di €".$pf." per ".$_POST['n_giorni']." giorni di noleggio dell' auto ".$_POST['macchina'];
echo '</fieldset><br>';
echo '<a href="Gila_es_file.php"><button>NUOVA PRENOTAZIONE</button></a>'
?>