package org.comodino.azienda;

class Manager extends Person {
  
  Employee[] employees;
  String department;

  Manager(String name, String id, String department, Employee[] emplyees) {
    this.name = name;
    this.id = id;
    this.department = department;
    this.employees = emplyees;
  }

  @Override
  public String toString() {
    String str = "Name: " + this.name + "\nID: " + this.id + "\nEmployees: " + this.employees.toString();
    return str;
  }

}
