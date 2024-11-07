<?php
$conn = mysqli_connect('localhost', 'root', '', 'Gila_Azienda') or die("Errore connessione".mysqli_connect_error($conn));
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Inserimento</title>
</head>
<body>
<center>
    <b>INSERIMENTO TIROCINANTE</b><br><br>
    <form action="inserimentoTIscript.php" method="post">
        Matricola
        <input name="matricola" type="text" required><br><br>
        Nome
        <input name="nome" type="text" required><br><br>
        Cognome
        <input name="cognome" type="text" required><br><br>
        Classe
        <input name="classe" type="text" required><br><br>
        ID Azienda
        <select name="ida">
            <?php
            $query = mysqli_query($conn, "select id from Azienda");
            while ($riga = mysqli_fetch_array($query)){
                echo "<option value='".$riga['id']."'>".$riga['id'];
            }
            ?>
        </select><br><br>
        ID Tutor
        <select name="idt">
            <?php
            $query = mysqli_query($conn, "select id from Tutor");
            while ($riga = mysqli_fetch_array($query)){
                echo "<option value='".$riga['id']."'>".$riga['id'];
            }
            ?>
        </select>
        <br><br><input type="submit" value="Invia">
        <input type="reset" value="Annulla">
    </form><br><br>
    <a href="menu.html"><button>TORNA AL MENU'</button></a>
</center>
</body>
</html>