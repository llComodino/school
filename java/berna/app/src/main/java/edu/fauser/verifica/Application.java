package edu.fauser.verifica;

public class Application {
  String name;
  String filename;

  Application(String name, String filename) {
    this.name = name;
    this.filename = filename;
  }

  @Override
  public String toString() {
    return "Name: " + this.name + "\nFilename: " + this.filename + "\n\n";
  }
}
