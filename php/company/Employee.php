<?php
class Employee {
  private   string $table = 'employee';

  protected string $code = '';
  protected string $name;
  protected string $surname;
  protected string $filial;
  protected float  $salary;
  protected string $ass_date;
  protected string $bdate;
  protected string $rcity;

  public function createCode(): string {
    return
          substr(
            md5(
              $this->name.
              $this->surname.
              $this->filial.
              $this->ass_date.
              $this->b_date.
              $this->rcity
            ),
            0, 16
          );
  }

  public function __construct(
    string $code = '',
    string $name,
    string $surname,
    string $filial,
    float  $salary,
    string $ass_date,
    string $bdate,
    string $rcity
  ) {
    $this->setName($name);
    $this->setSurname($surname);
    $this->setFilial($filial);
    $this->setSalary($salary);
    $this->setAssDate($ass_date);
    $this->setBdate($bdate);
    $this->setRcity($rcity);

    if ($code == '') $this->code = $this->createCode();
  }
    /**
     * @param mixed $conn
     */
    public function insertIntoDatabase($conn): bool {
    try {
      $conn->exec("
        INSERT INTO ".$this->table."
        VALUE (
          '$this->code',
          '$this->name',
          '$this->surname',
          '$this->filial',
           $this->salary,
          '$this->ass_date',
          '$this->bdate',
          '$this->rcity'
        )
      ");
    } catch (Exception $e) {
      echo $e->getMessage();
      return false;
    }
    return true;
  }

  function setName(string $name): void {
    $this->name = $name;
  }

  function setSurname(string $val): void {
    $this->surname = $val;
  }

  function setFilial(string $val): void {
    $this->filial = $val;
  }

  function setSalary(float $val): void {
    $this->salary = $val;
  }

  function setAssDate(string $val): void {
    $this->ass_date = $val;
  }

  function setBdate(string $val): void {
    $this->bdate = $val;
  }

  function setRcity(string $val): void {
    $this->rcity = $val;
  }

  function getName(): string {
    return $this->name;
  }

  function getSurname(): string {
    return $this->surname;
  }

  function getFilial(): string {
    return $this->filial;
  }

  function getSalary(): float {
    return $this->salary;
  }

  function getAssDate(): string {
    return $this->ass_date;
  }

  function getBdate(): string {
    return $this->b_date;
  }

  function getRcity(): string {
    return $this->rcity;
  }

  public function getInfoAsDict(): array {
    return
        [
          "code"      => $this->code,
          "name"      => $this->name,
          "surname"   => $this->surname,
          "filial"    => $this->filial,
          "ass_date"  => $this->ass_date,
          "b_date"    => $this->b_date,
          "rcity"     => $this->rcity
        ];
  }
}
?>
