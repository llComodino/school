<?php
$conn = mysqli_connect('localhost', 'root', '', 'Gila_Azienda') or die("Errore connessione".mysqli_connect_error($conn));
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>QUERY 2</title>
</head>
<body>
<center>
    <b>NOME E COGNOME TIROCINANTI IN UNA DETERMINATA CLASSE</b><br><br>
    <form action="query2script.php" method="post">
        Classe
        <select name="classe">
            <?php
            $query = mysqli_query($conn, "select classe from Tirocinante") or die(mysqli_error()."Errore query");
            while ($riga = mysqli_fetch_array($query)){
                echo "<option value='".$riga['classe']."'>".$riga['classe'];
            }
            ?>
        </select><br><br>
        <input type="submit" value="Invia">
        <input type="reset" value="Annulla">
    </form><br><br>
    <a href="menu.html"><button>TORNA AL MENU'</button></a>
</center>
</body>
</html>