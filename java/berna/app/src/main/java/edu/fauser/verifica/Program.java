package edu.fauser.verifica;

public class Program {

  public static void main (String[] args) {

    Icon icon = new Icon("code", "path/to/img.jpg");
    System.out.println(icon.toString());

    Application app = new Application("AppName", "PathToImage");
    System.out.println(app.toString());

    DisplayArea[] d_areas = new DisplayArea[5];

    for (int i = 0; i < 5; i++) {
      d_areas[i] = new DisplayArea(i, "path/to/bg_img.jpg");
      d_areas[i].toString();
    }

    ActiveIcon aIcon = new ActiveIcon("code", "path/to/img.jpg", "sound", app, d_areas);
    System.out.println(aIcon.toString());
  }
  
}
