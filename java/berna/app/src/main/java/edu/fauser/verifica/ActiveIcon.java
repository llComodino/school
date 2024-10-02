package edu.fauser.verifica;

public class ActiveIcon extends Icon {

  String sound;
  Application app;
  DisplayArea[] d_areas;

  ActiveIcon(String code, String img, String sound, Application app, DisplayArea[] d_areas) {
    super(code, img);
    this.sound = sound;
    this.app = app;
    this.d_areas = d_areas;
  }

  @Override
  public String toString() {
    return "Code: " + getCode() +
            "\nImg: " + this.img +
            "\nSound: " + this.sound +
            "\nApp:\n" + this.app +
            "\nDAreas:\n" + this.d_areas.toString() + "\n\n";
  }

}
