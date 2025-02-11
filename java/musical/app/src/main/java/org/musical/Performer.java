package org.musical;

class Performer {
  protected String name;
  protected String genre;
  protected boolean performing;

  public Performer(String name, String genre) {
    this.name = name;
    this.genre = genre;
    this.performing = false;
  }

  void perform() {
    System.out.println(name + " is performing!");
  }
}
