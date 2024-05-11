package org.esercizi.corso;

public class Corso {

  String nome;
  Integer cfu;

  public Corso(String nome, Integer cfu) {
    this.nome = nome;
    this.cfu = cfu;
  }

  public void info() {
    System.out.println("Informazioni");
  }

}
