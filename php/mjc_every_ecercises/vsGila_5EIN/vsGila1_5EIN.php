<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Cinema Fauser - anno 2023</title>
</head>
<body>
<form method="post" action="vsGila2_5EIN.php">
    <h1 align="center">Cinema Fauser - anno 2023</h1>
    <table align="center">
        <tr>
            <td>Nome*</td>
            <td><input type="text" name="nome" required pattern="[A-Z]{1}[a-z]{2,}"></td>
        </tr>
        <tr>
            <td>Cognome*<br></td>
            <td><input type="text" name="cognome" required pattern="[A-Z]{1}[a-z]{2,}"><br></td>
        </tr>
        <tr>
            <td>Data di nascita*</td>
            <td><input type="date" name="data_nascita" required></td>
        </tr>
        <tr>
            <td>Codice fiscale*</td>
            <td><input type="text" name="cf" required pattern="[A-Z]{6}[0-9]{2}[A-Z]{1}[0-9]{2}[A-Z]{1}[0-9]{3}[A-Z]{1}"></td>
        </tr>
        <tr>
            <td>Telefono*</td>
            <td><input type="text" name="telefono" required pattern="[0-9]{10}"></td>
        </tr>
        <tr>
            <td>Numero persone*</td>
            <td><input type="number" name="persone" required></td>
        </tr>
    </table>

    <p align="center">
        Film in programmazine: <br>
        <select name="film">
            <option value="0"></option>
            <option value="1">LA PANTERA DELLE NEVI</option>
            <option value="2">MINIONS 2 - COME GRU DIVENTA CATTIVISSIMO</option>
            <option value="3">MAIGRET</option>
            <option value="4">IL RAGAZZO E LA TIGRE</option>
        </select>
        <br><br>
        Costo biglietto: €6,50 <br>
        <br>
        Scegliere il giorno ed il mese (sab-dom + €0,50)<br>
        <br>
        Giorno >> <select name="g"> <?php for ($i = 1; $i <= 31; $i++){echo "<option value='$i'>$i</option>";} ?></select>
        Mese >> <select name="m"> <?php for ($i = 1; $i <= 12; $i++){echo "<option value='$i'>$i</option>";} ?></select>
        <br>
    </p>
    <table align="center" border="1">
        <tr>
            <td align="center" colspan="4">Orario spettacolo</td>
        </tr>
        <tr>
            <td><input type="radio" name="orario" value="16:00">16:00</td>
            <td><input type="radio" name="orario" value="18:00">18:00</td>
            <td><input type="radio" name="orario" value="20:00">20:00</td>
            <td><input type="radio" name="orario" value="22:00">22:00</td>
        </tr>
    </table>
    <br> <br>
    <table align="center" border="1">
        <tr>
            <td align="center" colspan="2">Tipo pagamento (carta di credito (+0,70), bancomat (+0,40))</td>
        </tr>
        <tr>
            <td><input type="radio" name="pagamento" value="Carta di credito">Carta di credito</td>
            <td><input type="radio" name="pagamento" value="Bancomat">Bancomat</td>
        </tr>
    </table>

    <p align="center">
        Commento <br>
        <textarea name="commento" cols="50" rows="3">Nessun commento</textarea>
        <br><br>
        <input type="submit" name="invia" value="Invia i dati">
        <input type="reset" name="annulla" value="Cancella i dati">
    </p>
</form>
</body>
</html>
