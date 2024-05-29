package edu.fauser.verifica;

public class Program {
  public static void main (String[] args) {
    Codec [] codecs = new Codec[10];
    Format[] formats = new Format[10];
    String[] format_exts = { "mkv", "mp4", "vlc", "avi", "mov" };
    String[] format_names = { "name1", "name2", "name3", "name4", "name5" };

    for (int i = 0; i < 10; i++) {
      String code = "CODE-AA";
      String exec = "EXEC-FF";

      code += i;
      exec += i;

      formats[i] = new Format(format_names[i % 5], format_exts[i % 5]);
      codecs[i] = new Codec(code, exec, formats[i]);
    }

    for (Codec codec : codecs) {
      System.out.println(codec.toString());
    }

    for (Format format : formats) {
      System.out.println(format.toString());
    }
  }
}
