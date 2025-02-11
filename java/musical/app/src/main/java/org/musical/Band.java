package org.musical;

class Band extends Performer {
  protected int members;

  public Band(String name, String genre, int members) {
    super(name, genre);
    this.members = members;
  }

  @Override
  void perform() {
    System.out.println("Band " + name + " is performing with their " + members + " members!");
  }
}
