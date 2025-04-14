<?php
  $servername = "localhost";
  $username = "tmp";
  $password = "tmppwd!";

  $enums = [
    'class' => ['Quarta', 'Quinta'],
    'sector' => ['Sector 1', 'Sector 2', 'Sector 3'],
    'subject' => ['Subject 1', 'Subject 2', 'Subject 3'],
  ];

  try {
    $conn = new PDO("mysql:host=$servername;dbname=company", $username, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
  } catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
    $conn = null;
  }

  function getTutors() {
    global $conn;
    $stmt = $conn->prepare("SELECT id, name FROM tutor");
    $stmt->execute();
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
  }

  function getCompanies() {
    global $conn;
    $stmt = $conn->prepare("SELECT id, name FROM company");
    $stmt->execute();
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
  }

  function mkid($prefix) {
    return substr($prefix, 0, 3) . '.' .
    substr(md5(microtime()), 0, 9) . '.' .
    substr(md5(microtime()), 0, 2);
  }

  function insertTrainee($trainee) {
    global $conn;
    $stmt = $conn->prepare("INSERT INTO trainee (id, name, surname, class, id_company, id_tutor) VALUES 
      (:id, :name, :surname, :class, :id_company, :id_tutor)");
    $stmt->bindParam(':id', mkid('trn'));
    $stmt->bindParam(':name', $trainee['name']);
    $stmt->bindParam(':surname', $trainee['surname']);
    $stmt->bindParam(':class', $trainee['class']);
    $stmt->bindParam(':id_company', $trainee['company']);
    $stmt->bindParam(':id_tutor', $trainee['tutor']);
    return $stmt->execute();
  }
?>
