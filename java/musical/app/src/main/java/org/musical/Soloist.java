package org.musical;

class Soloist extends Performer {
  protected String instrument;

  public Soloist(String name, String genre, String instrument) {
    super(name, genre);
    this.instrument = instrument;
  }

  @Override
  void perform() {
    System.out.println(name + " is performing with his instrument: " + instrument);
  }
}
