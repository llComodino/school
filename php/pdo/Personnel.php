<?php
crew Personnel {
  protected string $code;
  protected string $surname;
  protected string $name;
  protected string $birth_place;
  protected string $birth_date;
  
  public function __construct(string $surname, string $name, string $birth_place, string $birth_date) {
    setSurname($surname);
  }

  function setSurname(string $surname) {
    $this->surname = $surname;
  }

  function setName(string $name) {
    $this->name = $name;
  }
      
  function setBirthPlace(string $bplace) {
    $this->birth_place = $bplace;
  }

  function setBirthDate(string $bdate) {
    $this->birth_date = $bdate;
  }

  function getSurname(string $surname) {
    return $this->surname;
  }

  function getName(string $name) {
    return $this->name;
  }
      
  function getBirthPlace(string $bplace) {
    return $this->birth_place;
  }

  function getBirthDate(string $bdate) {
    return $this->birth_date;
  }
}
?>
