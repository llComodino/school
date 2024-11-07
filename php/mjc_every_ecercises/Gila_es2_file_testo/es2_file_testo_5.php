<?php

$cognome = $_POST['cognome'];
$nome = $_POST['nome'];
$data = $_POST['data'];
$luogo_di_nascita = $_POST['luogo_di_nascita'];
$cf = $_POST['cf'];
$username = $_POST['username'];
$professione = $_POST['professione'];
$nome_tmp = $_FILES['photo']['tmp_name'];
$nome_origine = $_FILES['photo']['name'];
$estensione = explode('.', $nome_origine);
$cartella = "photo/";
$nome_finale = $cartella.$cf.'.'.$estensione[1];

$dati = $cognome.';'.$nome.';'.$data.';'.$luogo_di_nascita.';'.$cf.';'.$username.';'.$professione.';'.$nome_finale;

if ($_POST['pass1'] == $_POST['pass2']){
    $file = fopen('dati.txt', 'a');
    if ($file == false) {
        echo '<p align="center">Impossibile aprire il file, dati non inseriti al suo interno</p>';
    }
    else{
        fputs($file, "$dati\n");
        fclose($file);
        If (move_uploaded_file($nome_tmp, $nome_finale))
            echo '<p align="center">Immagine inserita correttamente<br></p>';
        else
            echo '<p align="center">Immagine NON inserita correttamente<br></p>';
        unset($_FILES);
        echo '<p align="center">Dati caricati correttamente</p>';
    }

}
else{
    echo '<h1 align="center">!!ATTENZIONE!!</h1>';
    echo '<p align="center">Password non uguali, dati non inseriti nel file</p>';
}

echo '<p align="center"><a href="es2_file_testo_1.php"><button>TORNA ALLA HOME</button></a>  <a href="es2_file_testo_2.html"><button>NUOVI DATI</button></a></p>';
?>