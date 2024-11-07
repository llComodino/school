<?php
$conn = mysqli_connect('localhost', 'root', '', 'Gila_Azienda') or die("Errore connessione".mysqli_connect_error($conn));
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Query 1</title>
</head>
<body>
<center>
    <b>NOME E COGNOME STUDENTI IN UNA DETERMINATA AZIENDA</b><br><br>
    <form action="query1script.php" method="post">
        Azienda
        <select name="ida">
            <?php
            $query = mysqli_query($conn, "select id, nome from Azienda") or die(mysqli_error()."Errore query");
            while ($riga = mysqli_fetch_array($query)){
                echo "<option value='".$riga['id']."'>".$riga['nome'];
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