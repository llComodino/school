package edu.fauser.verifica;

public class Format {
  String name;
  String extension;

  Format(String name, String extension) {
    this.name = name;
    this.extension = extension;
  }

  @Override
  public String toString() {
    return "Name: " + this.name + "\nExtension: " + this.extension + "\n\n";
  }
}
