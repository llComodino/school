<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Esercizio 2 file di testo</title>
</head>
<body>
    <center>
    <?php
        $mesi=['Gennaio', 'Febbraio', 'Marzo', 'Aprile', 'Maggio', 'Giugno', 'Luglio', 'Agosto', 'Settembre', 'Ottobre', 'Novembre', 'Dicembre',];
        echo date('d') . ' es2_file_testo_1.php' .$mesi[-1 + date('m')].' '.date('Y H:i');
    ?>
    <fieldset style="width: 400px">
        <legend align="center">menu</legend>
        <p align="center">
            <a href="es2_file_testo_2.html">inserisci i dati</a><br><br>
            <a href="es2_file_testo_3.php">leggi i dati</a><br><br>
            <a href="es2_file_testo_4.html">ricerca dati</a><br>
        </p>
        </fieldset></center>
</body>
</html>