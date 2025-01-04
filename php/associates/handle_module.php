<?php
include 'Associate.php';
?>
<!DOCTYPE html>
<html>

<head>
    <title>Module Received</title>
</head>

<body>
    <h2>Module Received</h2>

    <p>Thank you for your submission.</p>
    <p>The module we have received is:</p>

    <?php
    $associate = new Associate();
    $associate->set_info($_POST);
    $associate->save_to_file();

    $fname = "./imgs/" . implode("AT", explode("@", $_POST["email"])) . "-avatar." . pathinfo($_FILES["img"]["name"], PATHINFO_EXTENSION);
    move_uploaded_file($_FILES["img"]["tmp_name"], $fname);

    echo "<p>You submitted:" . $associate->to_string() . "</p>";

    echo $associate->create_card($fname);
    ?>
</body>

</html>
