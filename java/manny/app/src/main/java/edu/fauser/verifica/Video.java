package edu.fauser.verifica;

public class Video {
  String path;
  String format;

  Video(String path, String format) {
    this.path = path;
    this.format = format;
  }

  @Override
  public String toString() {
    return "Path: " + this.path + "Format: " + this.format + "\n\n";
  }
}
