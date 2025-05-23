<?php
session_start();
if(!isset($_SESSION['email'])) {
    header("Location: login.html");
}

$ruolo =$_SESSION['ruolo'];

if($ruolo != 'Amministratore') {
    header("Location: no_permessi.html");
}

$email =$_SESSION['email'];
$conn = mysqli_connect('localhost', 'root', '', 'Gila_circolari') or die(mysqli_connect_error().'Errore connessione al database');

$query = mysqli_query($conn, "select * from utenti where email='$email'");
$query = mysqli_fetch_array($query);
?>

<!DOCTYPE html>
<html lang="en">
<head>

    <title>Nuovo utente</title>
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
            <form class="login100-form validate-form" method="post" action="creazione_utente.php" enctype="multipart/form-data">
					<span class="login100-form-title p-b-49">
						Creazione utente
					</span>

                <div class="wrap-input100 validate-input m-b-23" data-validate = "Cognome richiesto">
                    <span class="label-input100">Cognome</span>
                    <input class="input100" type="text" name="cognome" placeholder="Inserisci il cognome">
                    <span class="focus-input100" data-symbol="&#xf206;"></span>
                </div>

                <div class="wrap-input100 validate-input m-b-23" data-validate = "Nome richiesto">
                    <span class="label-input100">Nome</span>
                    <input class="input100" type="text" name="nome" placeholder="Inserisci il nome">
                    <span class="focus-input100" data-symbol="&#xf206;"></span>
                </div>

                <div class="wrap-input100 validate-input m-b-23" data-validate = "Data di nascita richiesta">
                    <span class="label-input100">Data di nascita</span>
                    <input class="input100" type="date" name="data">
                    <span class="focus-input100" data-symbol="&#xf206;"></span>
                </div>

                <div class="wrap-input100 validate-input m-b-23" data-validate = "Email richiesta">
                    <span class="label-input100">Email</span>
                    <input class="input100" type="text" name="email" placeholder="Inserisci la tua email">
                    <span class="focus-input100" data-symbol="&#xf206;"></span>
                </div>

                <div class="wrap-input100 validate-input m-b-23" data-validate = "Foto richiesta">
                    <span class="label-input100">Foto</span><br><br>
                    <input class="input100" type="file" name="foto" accept="image/*">
                    <span class="focus-input100" data-symbol="&#xf206;"></span>
                </div>


                <div class="wrap-input100 validate-input m-b-23" data-validate = "Ruolo richiesto">
                    <span class="label-input100">Ruolo</span><br>
                    <div style="padding: 20px">
                        <input type="radio" name="ruolo" value="Presidenza" required> Presidenza
                        <input type="radio" name="ruolo" value="Docenti"> Docente
                        <input type="radio" name="ruolo" value="Studenti"> Studente
                    </div>
                </div>



                <br><br>

                <div class="container-login100-form-btn">
                    <div class="wrap-login100-form-btn">
                        <div class="login100-form-bgbtn"></div>
                        <button class="login100-form-btn">
                            Crea
                        </button>
                    </div>
                </div>

            </form>
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