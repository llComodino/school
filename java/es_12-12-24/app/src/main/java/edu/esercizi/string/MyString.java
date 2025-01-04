package edu.esercizi.string;

public class MyString {
  protected String str;

  public MyString(String str) {
    this.str = str;
  }

  public void setValue(String str) {
    this.str = str;
  }

  public int getVowels() {
    return (int) this.str.chars()
                          .mapToObj( c -> (char) c )
                          .filter( c -> "abcdeABCDE".contains(String.valueOf(c)) )
                          .count();
  }

  public int getCons() {
    return (int) this.str.chars()
                          .mapToObj( c -> (char) c )
                          .filter( c -> "qwrtypsdfghjklzxcvbnmQWRTYPSDFGHJKLZXCVBNM".contains(String.valueOf(c)) )
                          .count();
  }

  public int getWordCount() {
    return 1 + (int) this.str.trim().chars()
                                    .mapToObj( c -> (char) c )
                                    .filter( c -> c == ' ' )
                                    .count();
  }

  public String aggressiveTrim() {
    return this.str.replace(" ", "");
  }

  @Override
  public String toString() {
    return this.str;
  }
}
