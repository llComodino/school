package org.esercizi;

import org.esercizi.professore.Professore;
import org.esercizi.corso.Corso;
import org.esercizi.universitario.Universitario;

public class App {

  public static void main (String[] argv) {

    Professore prof = new Professore("Marco", "Matematica", 34);
    Universitario uni = new Universitario("Luigi", "Enologia e Viticoltura", 22);
    Corso corso = new Corso("Enologia e Viticoltura", 180);

    System.out.println(prof.toString());
    System.out.println(uni.toString());
    System.out.println(corso.toString());

    System.out.println();

    prof.appello();
    uni.saluta();
    uni.stampa_corso();
    corso.info();

  }

}
