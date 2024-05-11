package org.esercizi.corso;

public class TestCorso extends Corso {
  
  TestCorso(String nome, Integer cfu) {
    super(nome, cfu);
  }

  void extra() {
    System.out.println("Sono extra");
  }

}
