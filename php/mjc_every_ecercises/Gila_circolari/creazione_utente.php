<?php
session_start();
if(!isset($_SESSION['email'])) {
    header("Location: login.html");
}

mysqli_report(MYSQLI_REPORT_OFF);

$ruolo =$_SESSION['ruolo'];

if($ruolo != 'Amministratore') {
    header("Location: no_permessi.html");
}

require 'gen_pass.php';

$conn = mysqli_connect('localhost', 'root', '', 'Gila_circolari') or die(mysqli_connect_error().'Errore connessione al database');

$cognome = $_POST['cognome'];
$nome = $_POST['nome'];
$data = $_POST['data'];
$email = $_POST['email'];
$ruolo = $_POST['ruolo'];

$pass = gen_pass();
$md5pass = md5($pass);

if(is_uploaded_file($_FILES['foto']['tmp_name']) || $_FILES['foto']["error"] == 0){
    $nome_tmp = $_FILES['foto']['tmp_name'];
    $nome_origine = $_FILES['foto']['name'];

    $arr=explode(".", $nome_origine);
    $dim=count($arr);
    $estensione=$arr[$dim-1];
    $cartella = "images/";
    $nome_finale = $cartella.$email.".".$estensione;
    $flag=move_uploaded_file($nome_tmp, $nome_finale);
    if(!$flag){
        die(header("Location: creazione_fallita.php"));
    }
    unset($_FILES);
}

$flag = mysqli_query($conn, "select * from utenti where email='$email'");
$count = mysqli_num_rows($flag);

if ($count != 0){
    header("Location: creazione_fallita.php");
}


$query = "insert into utenti(cognome, nome, datanascita, email, password, foto, ruolo, abilitato) values ('$cognome', '$nome', '$data', '$email', '$md5pass', '$nome_finale', '$ruolo', 0)";
mysqli_query($conn, $query);


$s = $_SERVER['SERVER_NAME'];
$p = $_SERVER['PHP_SELF'];
$pezzi = explode("/", $p);
$pezzi[count($pezzi) - 1] = "conferma_email.php";
$pagina = implode("/", $pezzi);
$percorso = $s . $pagina;
Mail_link($percorso, $email, $pass);

header("Location: creazione_finita.php");
?>