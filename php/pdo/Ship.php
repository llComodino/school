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

  function setCode(string $code): void {
    $this->code = $code;
  }

  function setName(string $name): void {
    $this->name = $name;
  }

  function setNation(string $nation): void {
    $this->nation = $nation;
  }

  function setDate(string $date): void {
    $this->date = $date;
  }

  function setLength(float $length): void {
    $this->length = $length;
  }

  function setWidth(float $width): void {
    $this->width = $width;
  }

  function setPower(float $power): void {
    $this->power = $power;
  }

  function getCode(): string {
    return $this->code;
  }

  function getName(): string {
    return $this->name;
  }

  function getNation(): string {
    return $this->nation;
  }

  function getYear(): string {
    return $this->year;
  }

  function getLength(): float {
    return $this->length;
  }

  function getWidth(): float {
    return $this->width;
  }

  function getPower(): float {
    return $this->power;
  }

  function toKeyValues(): array {
    return [
        "code"   => $this->code,
        "name"   => $this->name,
        "nation" => $this->nation,
        "date"   => $this->date,
        "length" => $this->length,
        "width"  => $this->width,
        "power"  => $this->power
    ];
  }
}
