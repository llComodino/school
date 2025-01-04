package edu.fauser.verifica;

public class DisplayArea {
  protected Integer pos;
  protected String bg_img;
  protected Boolean active;

  DisplayArea(Integer pos, String bg_img){
    this.pos = pos;
    this.bg_img = bg_img;
  }

  void activate() {
    this.active = true;
  }

  void deactivate() {
    this.active = false;
  }

  Boolean isActive() {
    return this.active;
  }

  void setPos(Integer pos) {
    this.pos = pos;
  }

  void setBgimg(String bg_img) {
    this.bg_img = bg_img;
  }

  Integer getPos() {
    return this.pos;
  }

  String getBgimg() {
    return this.bg_img;
  }

  @Override
  public String toString() {
    return "Pos: "    + getPos()    +
           "\nBG: "   + getBgimg()  +
           "Active: " + this.active + "\n\n";
  }
}
