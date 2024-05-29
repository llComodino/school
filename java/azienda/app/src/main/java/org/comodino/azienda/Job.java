package org.comodino.azienda;

class Job {
  String start_date;
  String end_date;
  String description;

  Job (String start_date, String end_date, String description) {
    this.start_date = start_date;
    this.end_date = end_date;
    this.description = description;
  }
  
  @Override
  public String toString() {
    String str = "Start: " + this.start_date + "\nEnd: " + this.end_date + "\nDescription: " + this.description;
    return str;
  }

}
