package edu.fauser.verifica;

public class Player {
  String exec;
  protected Integer kbyte;
  protected Boolean active;
  Format[] formats;
  Codec[] codecs;

  Player(String exec, Format[] formats, Codec[] codecs) {
    this.kbyte = 0;
    this.active = false;
    this.exec = exec;
    this.formats = formats;
    this.codecs = codecs;
  }

  Boolean isActive() {
    return this.active;
  }

  Integer getKbyte() {
    return this.kbyte;
  }

  String getExec() {
    return this.exec;
  }

  void setExec(String exec) {
    this.exec = exec;
  }

  void setKbyte(Integer kbyte) {
    this.kbyte = kbyte;
  } 

  void activate(Integer kbyte) {
    setKbyte(kbyte);
    this.active = true;
    System.out.println("Activated with " + this.kbyte + "KB\n\n");
  }

  void deactivate() {
    this.kbyte = 0;
    this.active = false;
  }

  @Override
  public String toString() {
    String player = "Executable: " + this.exec +
            "Size (KB): " + this.kbyte +
            "Compatible with:\n";

    for (Format format : formats) {
      player = player + format.toString();
    }

    player += "Codecs:\n";

    for (Codec codec : codecs) {
      player += codec.toString();
    }

    return player;
  }
      
}
