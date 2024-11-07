<?php

$costo = 0;

$data = date("d/m/Y");

$film = $_POST['film'];

echo "<h1 align='center'>Biglietto Cinema Fauser - Anno 2023</h1><br><hr><br>";

echo "<p align='center'>$data<br><br><hr></p><br>";

echo "<p align='center'>";
echo "Nome: ".$_POST['nome']."<br>";
echo "Cognome: ".$_POST['cognome']."<br>";
echo "Data di nascita: ".$_POST['data_nascita']."<br>";
echo "CF: ".$_POST['cf']."<br>";
echo "Telefono: ".$_POST['telefono']."<br>";
echo "Numero persone: ".$_POST['persone']."<br><br>";

echo "<hr>";

echo "<p align='center'>";

$costo += ($_POST['persone'] * 6.50);

$orario = $_POST['orario'];

if ($film != 0){
    switch ($film){
        case 1:
            $nomefilm = "LA PANTERA DELLE NEVI";
            break;
        case 2:
            $nomefilm = "MINIONS 2 - COME GRU DIVENTA CATTIVISSIMO";
            break;
        case 3:
            $nomefilm = "MAIGRET";
            break;
        case 4:
            $nomefilm = "IL RAGAZZO E LA TIGRE";
            break;
    }
    echo "<table border='1'>";
    echo "<tr><td colspan='3' align='center'><b>FILM SELEZIONATO</b></td></tr>";
    echo "<tr><td>Sala$film</td><td>$nomefilm</td><td>$orario</td></tr>";
    echo "</table><br><br>";

    $gg = $_POST['g'];
    $mm = $_POST['m'];
    $mm --;
    $aa = date('Y');

    $mesi = ["Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"];

    echo "Data spettacolo: $gg $mesi[$mm] $aa<br><br>";
}

else {
    echo "SPETTACOLO NON SELEZIONATO";
}

echo "</p>";

echo "<hr><br>";

echo "<p align='center'>";

$commento = $_POST['commento'];

if (isset($commento)){
    echo "Commento:<br>";
    echo "$commento<br><br>";
}

echo "</p>";

echo "<hr><br>";

echo "<p align='center'>";

echo "Metodo pagamento: ".$_POST['pagamento']."<br>";

if ($_POST['pagamento'] == "Bancomat"){
    $costo += 0.40;
}
else{
    $costo += 0.70;
}

if ($costo > 50){
    $costo = ($costo * 87.5) / 100;
}

echo "Costo: €$costo<br><br>";

echo "</p>";

echo "<hr><br>";
echo "<p align='center'>";
echo "<a href='vsGila1_5EIN.php'><button>NUOVA PRENOTAZIONE</button></a>";
echo "</p>";

?>
