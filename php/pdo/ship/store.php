<?php

function saveToDatabase($conn, $table, $pdo) {
  try {
    $query_head = "INSERT INTO $table (";
    $query_tail = "VALUES (";
    foreach ($pdo as $key => $val) {
        echo "<span>$key: $val</span><br>";
        $query_head .= " $key,";
        $query_head .= " '$val',";
    }

    rtrim($query_head, ",");
    rtrim($query_tail, ",");

    $query_head .= ")";
    $query_tail .= ")";

    $conn->exec($query_head . $query_tail);
  } catch (Exception $e) {
    echo $e->getMessage();
    return false;
  }
  return true;
}

?>
