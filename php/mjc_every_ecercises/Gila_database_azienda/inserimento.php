<?php

$conn = mysqli_connect('localhost', 'root', '', 'Azinda') or die();

$nome = $_POST['nome'];
$cognome = $_POST['cognome'];
$filiale = $_POST['filiale'];
$stipendio = $_POST['stipendio'];
$data_nascita = $_POST['data'];
$citta = $_POST['citta'];

$strsql = "insert into impiegati (nome, cognome, filiale, stipendio, datass, datanasc, cittaresidenza)";
$strsql .= "values ('$nome', '$cognome', '$filiale', '$stipendio', curdate(), '$data_nascita', '$citta')";

$ris = mysqli_query($conn, $strsql);