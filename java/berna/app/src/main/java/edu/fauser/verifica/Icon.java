package edu.fauser.verifica;

public class Icon {
  protected String code;
  String img;

  Icon(String code, String img) {
    this.code = code;
    this.img = img;
  }

  void setCode(String code) {
    this.code = code;
  }

  String getCode() {
    return this.code;
  }

  @Override
  public String toString() {
    return "Code: " + this.code + "\nImage: " + this.img + "\n\n";
  }
}
