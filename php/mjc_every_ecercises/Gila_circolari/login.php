<?php
$conn = mysqli_connect('localhost', 'root', '', 'Gila_circolari') or die(mysqli_connect_error().'Errore connessione databse');

$email = $_POST["email"];
$pass = $_POST["pass"];

//SQL injection
$email = stripslashes($email);
$pass = stripslashes($pass);
$email = mysqli_real_escape_string($conn, $email);
$pass = mysqli_real_escape_string($conn, $pass);
$passmd5 = md5($pass);

// lettura della tabella utenti
$sql="SELECT * FROM utenti WHERE email='$email' AND password='$passmd5'";
$result=mysqli_query($conn, $sql);
$conta=mysqli_num_rows($result);
if($conta==1){
    $stringa = mysqli_fetch_array($result);
    if ($stringa['abilitato'] == 0){
        header("Location: non_abilitato.html");
    }
    else{

        session_start();
        $_SESSION['email'] = $email;
        $_SESSION['ruolo'] = $stringa['ruolo'];

        if ($stringa['abilitato'] == 1 && $stringa['ruolo'] == 'Amministratore'){
            header("Location: nuovo_utente.php");
        }
        else if ($stringa['abilitato'] == 1 && $stringa['ruolo'] == 'Presidenza'){
            header("Location: upload_circolare.php");
        }
        else if ($stringa['abilitato'] == 1 && ($stringa['ruolo'] == 'Docenti' || $stringa['ruolo'] == 'Studenti')){
            header("Location: leggi_circolari.php");
        }
    }

}
else {
    header("Location: non_esistente.html");
}
?>