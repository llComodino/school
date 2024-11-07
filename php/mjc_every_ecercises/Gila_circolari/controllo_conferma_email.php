<?php
$conn = mysqli_connect('localhost', 'root', '', 'Gila_circolari') or die(mysqli_connect_error().'Errore connessione databse');

$email = $_GET["email"];
$vpass = $_POST["vpass"];
$npass = $_POST["npass"];


//SQL injection
$email = stripslashes($email);
$npass = stripslashes($npass);
$vpass = stripslashes($vpass);
$email = mysqli_real_escape_string($conn, $email);
$npass = mysqli_real_escape_string($conn, $npass);
$vpass = mysqli_real_escape_string($conn, $vpass);
$npassmd5 = md5($npass);
$vpassmd5 = md5($vpass);

// lettura della tabella utenti
$sql="SELECT * FROM utenti WHERE email='$email' AND password='$vpassmd5'";
$result=mysqli_query($conn, $sql);
$conta=mysqli_num_rows($result);
if($conta==1){
    $sql="UPDATE utenti set password = '$npassmd5', abilitato = 1 where email = '$email'";
    $result=mysqli_query($conn, $sql);
    header("Location: vai_al_login.html");
}
else {
    echo 'Vecchia password errata<br/>';
}
?>