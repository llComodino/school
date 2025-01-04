package org.esercizi.universitario;

public class Universitario {

  String name;
  String corso;
  Integer age;

  public Universitario(String name, String corso, Integer age) {
    this.name = name;
    this.corso = corso;
    this.age = age;
  }

  public void saluta() {
    System.out.println("Ciao, mi chiamo " + this.name);
  }

  public void stampa_corso() {
    System.out.println("Frequento: " + this.corso);
  }

}
