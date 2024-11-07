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
    <b>SETTORE E TIPOLOGIA AZIENDA DOVE HA LAVORATO UN DETERMINATO TIROCINANTE</b><br><br>
    <form action="query3script.php" method="post">
        Nome e cognome tirocinante
        <select name="matricola">
            <?php
            $query = mysqli_query($conn, "select matricola, nome, cognome from Tirocinante") or die(mysqli_error()."Errore query");
            while ($riga = mysqli_fetch_array($query)){
                echo "<option value='".$riga['matricola']."'>".$riga['nome']." ".$riga['cognome'];
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