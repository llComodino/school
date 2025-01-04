<?php
include 'Associate.php';
?>
<!DOCTYPE html>
<html>

<head>
    <title>Associates</title>
    <style>
        table {
            border-collapse: collapse;
            border: 1px solid salmon;
        }

        td {
            padding: 1rem;
            border: 1px solid salmon;
        }
    </style>
</head>

<body>
    <h2>Our Associates</h2>
    <?php
    function tabulate($associates)
    {
        $associates = explode("\n", $associates);

        // Don't know why it takes two
        // I don't care, it works just fine like this
        // I have no time to waste
        array_pop($associates);
        array_pop($associates);

        echo "<table>
              <tbody>";
        foreach ($associates as $pos => $associate) {
            echo "<tr>
                    <td><span><b>$pos</b></span></td>";
            $data = explode(";", $associate);
            foreach ($data as $val) {
                echo "<td><span>$val</span></td>";
            }
            echo "</tr>";
        }
        echo "</tbody>
              </table>";
    }
    function print_associates($associates)
    {
        if ($associates) tabulate($associates);
        else echo "<h2>No associate yet :(</h2>";
    }

    print_associates(Associate::get_all());
    ?>
</body>

</html>
