package org.esercizi.professore;

public class TestProfessore extends Professore {

  TestProfessore(String nome, String materia, Integer age) {
    super(nome, materia, age);
  }

  void extra() {
    System.out.println("Sono extra");
  }

}
