package edu.fauser.verifica;

public class Codec {
  String code;
  String exec;

  Format format;

  Codec(String code, String exec, Format format) {
    this.code = code;
    this.exec = exec;
    this.format = format;
  }

  String getCode() {
    return this.code;
  }

  String getExec() {
    return this.code;
  }

  Format getFormat() {
    return this.format;
  }

  void setCode(String code) {
    this.code = code;
  }

  void setExec(String exec) {
    this.exec = exec;
  }

  void setFormat(Format format) {
    this.format = format;
  }

  @Override
  public String toString() {
    return  "Code: " +
            this.code +
            "\nExecutable: " +
            this.exec +
            "\nFormat:\n" +
            this.format.toString();
  }
}
