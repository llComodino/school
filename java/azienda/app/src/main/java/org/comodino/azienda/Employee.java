package org.comodino.azienda;

class Employee extends Person {

  Job job;

  Employee(String name, String id, Job job) {
    this.name = name;
    this.id = id;
    this.job = job;
  }

  @Override
  public String toString() {
    String str = "Name: " + this.name + "\nID: " + this.id + "\nJob: " + this.job.toString() + "\n\n";
    return str;
  }
  
}
