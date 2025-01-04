package org.esercizi.professore;

public class Professore {

  String nome;
  String materia;
  Integer age;

  public Professore(String nome, String materia, Integer age) {
    this.nome = nome;
    this.materia = materia;
    this.age = age;
  }

  final public void appello() {
    System.out.println("Appello");
  }

}
