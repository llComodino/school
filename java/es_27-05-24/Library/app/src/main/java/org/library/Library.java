package org.library;

import java.util.HashMap;
import org.library.Book;

public class Library {
  
  HashMap<String, Book> books;
  String address;
  String email;

  Library(String address, String email, HashMap<String, Book> books) {
    this.address = address;
    this.email = email;
    this.books = books;
  }

}
