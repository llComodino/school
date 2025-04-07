<?php
  $db = 'appuser';
  $table = 'user';
  $dbuser = 'publicuser';

  function check_existing_user(string $mail): bool {
    global $db, $table, $dbuser;

    try {
      $conn = new PDO("mysql:host=localhost;dbname=$db", $dbuser, '');
      $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

      $stmt = $conn->prepare("SELECT * FROM $table WHERE mail = :mail");
      $stmt->bindParam(':mail', $mail);
      $stmt->execute();

      if ($stmt->rowCount() > 0) {
        return true;
      } else {
        return false;
      }
    } catch (PDOException $e) {
      return "(check_existing_user) Connection failed: " . $e->getMessage();
    } finally {
      $conn = null;
    }
  }

  function register_user(string $surname, string $name, string $mail, string $phone, string $city, string $prov, string $pwd): string {
    global $db, $table, $dbuser;

    try {
      $conn = new PDO("mysql:host=localhost;dbname=$db", $dbuser, '');
      $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

      if (check_existing_user($mail)) {
        return "Email already registered.";
      }

      $stmt = $conn->prepare("
                  INSERT INTO $table (surname, name, mail, phone, city, prov, password)
                  VALUE (:surname, :name, :mail, :phone, :city, :prov, :pwd)
      ");
      $stmt->bindParam(':surname', $surname);
      $stmt->bindParam(':name', $name);
      $stmt->bindParam(':mail', $mail);
      $stmt->bindParam(':phone', $phone);
      $stmt->bindParam(':city', $city);
      $stmt->bindParam(':prov', $prov);

      $hashed_pwd = password_hash($pwd, PASSWORD_BCRYPT);
      $stmt->bindParam(':pwd', $hashed_pwd);

      if ($stmt->execute()) {
        return "User registered successfully.";
      } else {
        return "Error registering user.";
      }
    } catch (PDOException $e) {
      return "(register_user) Connection failed: " . $e->getMessage();
    } finally {
      $conn = null;
    }
  }

  function fetch_user(string $mail) {
    global $db, $table, $dbuser;

    try {
      $conn = new PDO("mysql:host=localhost;dbname=$db", $dbuser, '');
      $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

      $stmt = $conn->prepare("SELECT * FROM $table WHERE mail = :mail");
      $stmt->bindParam(':mail', $mail);
      $stmt->execute();

      $user = $stmt->fetch(PDO::FETCH_ASSOC);
    } catch (PDOException $e) {
      return [];
    } finally {
      $conn = null;
    }

    return $user;
  }

  function log_in(string $mail, string $pwd): bool {
    global $db, $table, $dbuser;

    try {
      $conn = new PDO("mysql:host=localhost;dbname=$db", $dbuser, '');
      $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

      $stmt = $conn->prepare("SELECT * FROM $table WHERE mail = :mail");
      $stmt->bindParam(':mail', $mail);
      $stmt->execute();

      if ($stmt->rowCount() > 0) {
        $user = $stmt->fetch(PDO::FETCH_ASSOC);
        if (password_verify($pwd, $user['password'])) {
          return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    } catch (PDOException $e) {
      return false;
    } finally {
      $conn = null;
    }
  }
?>
