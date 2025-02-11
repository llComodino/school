package org.musical;

import java.util.Vector;

public class App {
  public static void main(String[] args) {
    Stage stage = new Stage();

    Soloist[] soloists = { 
      new Soloist("Fabrizio De Andre'", "Folk", "Acoustic Guitar"),
      new Soloist("Max Gazze'", "Folk", "Guitar")
    };

    Band[] bands = {
      new Band("System of A Down", "Metal", 4),
      new Band("Metallica", "Metal", 4),
      new Band("Nirvana", "Grunge", 4)
    };

    Vector<Performer> performers = new Vector<Performer>();

    for (Soloist solo : soloists) {
      performers.add(solo);
    }

    for (Band band : bands) {
      performers.add(band);
    }

    for (Performer performer : performers) {
      new Thread(() -> stage.useStage(performer), performer.name).start();
    }
  }
}
