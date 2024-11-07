<?php
session_start();
if(!isset($_SESSION['email'])) {
    header("Location: login.html");
}

$ruolo =$_SESSION['ruolo'];

if($ruolo != 'Presidenza') {
    header("Location: no_permessi.html");
}


$conn = mysqli_connect('localhost', 'root', '', 'Gila_circolari') or die(mysqli_connect_error().'Errore connessione al database');

$titolo = $_POST['titolo'];
$perchi = $_POST['perchi'];
$email = $_SESSION['email'];

$query = mysqli_query($conn, "select * from utenti where email='$email'");
$query = mysqli_fetch_array($query);

if(is_uploaded_file($_FILES['pdf']['tmp_name']) || $_FILES['pdf']["error"] == 0){
    $nome_tmp = $_FILES['pdf']['tmp_name'];
    $nome_origine = $_FILES['pdf']['name'];

    $cartella = "pdf/";
    $nome_finale = $cartella.$titolo.".pdf";
    $flag=move_uploaded_file($nome_tmp, $nome_finale);
    if(!$flag){
        die("ERRORE NEL FILE");
    }
    unset($_FILES);
}

$id = mysqli_query($conn, "select * from utenti where email = '$email'");

$id = mysqli_fetch_array($id);

$id = $id['idutente'];

$flag = mysqli_query($conn, "insert into circolari(dataupload, titolo, perchi, nomepdf, idutente) values (curdate(), '$titolo', '$perchi', '$nome_finale', '$id')");

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>✅</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!--===============================================================================================-->
    <link rel="icon" type="image/png" href="images/icons/favicon.ico"/>
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="vendor/bootstrap/css/bootstrap.min.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="fonts/font-awesome-4.7.0/css/font-awesome.min.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="fonts/iconic/css/material-design-iconic-font.min.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="vendor/animate/animate.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="vendor/css-hamburgers/hamburgers.min.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="vendor/animsition/css/animsition.min.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="vendor/select2/select2.min.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="vendor/daterangepicker/daterangepicker.css">
    <!--===============================================================================================-->
    <link rel="stylesheet" type="text/css" href="css/util.css">
    <link rel="stylesheet" type="text/css" href="css/main.css">
    <!--===============================================================================================-->
</head>
<body>

<div class="limiter">
    <div class="container-login100" style="background-image: url('images/bg-01.jpg');">
        <div class="wrap-login100 p-l-55 p-r-55 p-t-65 p-b-54">
            <?php echo '<p align="right">'.$query['nome'].' '.$query['cognome'].' <img class="circular-square" src="'.$query['foto'].'" width="15%"></p><br>'?>

            <span class="login100-form-title p-b-49">
                Upload circolare
            </span>

            <h5 align="center">Circolare caricata con successo✅<h5/><br>

            <div class="container-login100-form-btn">
                <div class="wrap-login100-form-btn">
                    <div class="login100-form-bgbtn"></div>
                    <a href="upload_circolare.php">
                        <button class="login100-form-btn">
                            Carica una nuova circolare
                        </button>
                    </a>
                </div>
            </div>
            <br>
            <div class="container-login100-form-btn">
                <div class="wrap-login100-form-btn">
                    <div class="login100-form-bgbtn"></div>
                    <a href="logout.php">
                        <button class="login100-form-btn-2" >
                            Logout
                        </button>
                    </a>
                </div>
            </div>
        </div>
    </div>
</div>


<div id="dropDownSelect1"></div>

<!--===============================================================================================-->
<script src="vendor/jquery/jquery-3.2.1.min.js"></script>
<!--===============================================================================================-->
<script src="vendor/animsition/js/animsition.min.js"></script>
<!--===============================================================================================-->
<script src="vendor/bootstrap/js/popper.js"></script>
<script src="vendor/bootstrap/js/bootstrap.min.js"></script>
<!--===============================================================================================-->
<script src="vendor/select2/select2.min.js"></script>
<!--===============================================================================================-->
<script src="vendor/daterangepicker/moment.min.js"></script>
<script src="vendor/daterangepicker/daterangepicker.js"></script>
<!--===============================================================================================-->
<script src="vendor/countdowntime/countdowntime.js"></script>
<!--===============================================================================================-->
<script src="js/main.js"></script>

</body>
</html>
