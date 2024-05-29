package org.library;

import java.util.HashMap;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileReader;

public class Program {

  public static void main (String[] args) {

    HashMap<String, Book> books = new HashMap<>();

    try (BufferedReader br = new BufferedReader(new FileReader("./books.txt"))) {

      String line;
      while ((line = br.readLine()) != null) {
        String[] parts = line.split(";");
        Book book = new Book(parts[0], parts[1], parts[2], parts[3]);
        books.put(parts[2], book);
      }

    } catch (IOException e) {
      e.printStackTrace();
    }

    Book test = books.get("100100");

    System.out.println("Title: " + test.title);

  }
  
}
