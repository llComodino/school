<?php

    function gen_pass($lunghezza = 20) {
        $caratteri = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}[]|;:,.<>?';

        $pass = '';
        for ($i = 0; $i < $lunghezza; $i++) {
            $pass .= $caratteri[rand(0, strlen($caratteri) - 1)];
        }

        return $pass;
    }
    function Mail_link($perlink, $destinatario, $pass_random)
    {
        $header = "MIME-Version: 1.0\r\n";
        $header .= "Content-type: text/html; charset=iso-8859-1\r\n";
        $header .= "From: Amministratore sito scolastico <admin@miosito.it> \r\n";
        $header .= "Reply-to: [email]admin@miosito.it[/email]\r\n";
        $oggetto = "Registrazione al sito";
        $messaggio =
            "<html>
    <head>
    <title>email di convalida registrazione</title>
    </head>
    <body>
    <p>Questa mail ti è stata inviata dall'amministratore del sito</p>
    Dati di accesso<br>
    Username: $destinatario<br>
    Password: <strong>$pass_random</strong><br>
    <strong>
    <p>Per concludere la tua registrazione, devi cliccare sul link sottostante...</p>
    <a href=\"$perlink?email=$destinatario\">CLICCA QUI PER CONVALIDARE LA TUA REGISTRAZIONE!</a>
    </strong>
    </body>
    </html>";
        mail($destinatario, $oggetto, $messaggio, $header);
    }
?>