<?php

class Ship {
  protected string $code;
  protected string $name;
  protected string $nation;
  protected string $date;
  protected float  $length;
  protected float  $width;
  protected float  $power;
  
  public function __construct(string $code, string $name, string $nation, string $date, float $length, float $width, float $power) {
    $this->setCode($code);
    $this->setName($name);
    $this->setNation($nation);
    $this->setDate($date);
    $this->setLength($length);
    $this->setWidth($width);
    $this->setPower($power);
  }
  
  function insertIntoDatabase($conn, string $table) {
    try {
      $conn->exec("
        INSERT INTO $table (code, name, nation, date, length, width, power)
              VALUES ('$this->code', '$this->name', '$this->nation', '$this->date', '$this->length', '$this->width', '$this->power')
      ");
    } catch (Exception $e) {
      echo $e->getMessage();
      return false;
    }
    return true;
  }
  
  function setCode(string $code) {
    $this->code = $code;
  }
  
  function setName(string $name) {
    $this->name = $name;
  }
  
  function setNation(string $nation) {
    $this->nation = $nation;
  }
  
  function setDate(string $date) {
    $this->date = $date;
  }
  
  function setLength(float $length) {
    $this->length = $length;
  }
  
  function setWidth(float $width) {
    $this->width = $width;
  }
  
  function setPower(float $power) {
    $this->power = $power;
  }
  
  function getCode() {
    return $this->code;
  }
  
  function getName() {
    return $name;
  }
  
  function getNation() {
    return $nation;
  }
  
  function getYear() {
    return $year;
  }
  
  function getLength() {
    return $length;
  }
  
  function getWidth() {
    return $width;
  }
  
  function getPower() {
    return $power;
  }
}