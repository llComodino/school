package edu.esercizi;

import edu.esercizi.string.MyString;

public class App {
    public static void main(String[] args) {
      MyString str = new MyString("programmazione");

      System.out.println("Vowels: " + str.getVowels());
      System.out.println("Cons: " + str.getCons());

      str.setValue("some string with spaces");
      System.out.println("Before trim: " + str);
      System.out.println("Word count: " + str.getWordCount());

      str.setValue(str.aggressiveTrim());
      System.out.println("\nAfter trim: " + str);
      System.out.println("Word count: " + str.getWordCount());
    }
}
