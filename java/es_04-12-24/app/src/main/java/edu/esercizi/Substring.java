package edu.esercizi;

public class Substring {
  private String substring;
  private int lowerBound;
  private int upperBound;

  public Substring(String string, int lBound, int uBound) {
    int len = string.length();

    if (len == 0) throw new IllegalArgumentException("Empty String");
    if (lBound < 0 || uBound < lBound || uBound > len) throw new IllegalArgumentException("Invalid bounds");

    this.lowerBound = lBound;
    this.upperBound = uBound;
    this.substring = string.substring(lBound, uBound);
  }

  public String getSubstring() {
    return this.substring;
  }
}
