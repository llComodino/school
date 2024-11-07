<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Autonoleggio dinamico</title>
</head>
<body>

    <form action="Gila_es_file_2.php" method="post">
        <fieldset>
            <legend>SCELTA AUTO</legend>
            Scegli una macchina <br>
            Data di ritiro <input type="date" name="data"><br>
            <?php
            $macchine = fopen('macchine.txt', 'r');
            while ($stringa = fgets($macchine)){
                $stringa2 = explode('-', $stringa);
                echo "<img src='photo/".$stringa2[1]."' width='20%'><br>";
                echo "<input required type='radio' name='macchina' value='".$stringa2[0]."'>".$stringa2[0]."<br>";
            }
            fclose($macchine);
            ?>
        </fieldset>
        <fieldset>
            <legend>DATI</legend>
            Cognome <br>
            <input type="text" name="cognome" required pattern="[A-Z]{1}[a-z]{2, }"><br>
            Nome <br>
            <input type="text" name="nome" required pattern="[A-Z]{1}[a-z]{2, }"><br>
            Numero giorni <br>
            <input type="number" name="n_giorni" required pattern="[1-9]{1, }"><br>
            Anni conducente <br>
            <input type="number" name="anni_conducente" required pattern="[18-80]"><br>
        </fieldset> <br>
        <input type="submit" value="PRENOTA"> <input type="reset" value="RESET">
    </form>

</body>
</html>
