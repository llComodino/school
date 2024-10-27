<!DOCTYPE html>
<?php
  $n1 = $_POST["num-1"];
  $n2 = $_POST["num-2"];
  $operand = $_POST["oper"];

  $op_names = [
    "+" => "Sum",
    "-" => "Difference",
    "/" => "Quotient",
    "*" => "Product",
  ];

  $operation = $n1 . $operand . $n2;
  $result = eval("return $operation;");
?>
<html>
  <head>
    <title>Sum</title>
  </head>
  <body>
    <span>
      <?php
        echo $op_names[$operand] . " is: " . $result . "<br>";
      ?>
    </span>
  </body>
</html>
