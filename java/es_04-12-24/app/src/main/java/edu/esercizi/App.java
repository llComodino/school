package edu.esercizi;

import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    matrixExercise();
    substrExercise();
  }

  public static void substrExercise() {
    int lBound = 0;
    int uBound = 0;
    String str = "";

    Scanner scanner = new Scanner(System.in);

    System.out.println("Enter string: ");
    do {
      str = scanner.nextLine();
    } while (str.length() < 1);

    int len = str.length();

    System.out.println("Enter lower bound (0," + len + "): ");
    do {
      lBound = scanner.nextInt();
    } while (lBound < 0 || lBound > len);

    System.out.println("Enter upper bound (" + lBound + "," + len + "): ");
    do {
      uBound = scanner.nextInt();
    } while (uBound < lBound || uBound > len);

    scanner.close();

    Substring substring = new Substring(str, lBound, uBound);

    System.out.println("Substring of `" + str + "` is: " + substring.getSubstring());
  }

  public static void matrixExercise() {
    Matrix[] matrixes = new Matrix[3];
    matrixes[0] = new Matrix(4, 4);
    matrixes[1] = new Matrix(2, 5);
    matrixes[2] = new Matrix(6, 3);

    for (Matrix matrix : matrixes) {
      populate(matrix);
    }

    for (Matrix matrix : matrixes) {
      System.out.println("Index of biggest sum row: " + getBiggestValueRowIndex(matrix));
    }
  }
  public static void populate(Matrix matrix) {
    for (int row = 0; row < matrix.getRows(); row++) {
      for (int col = 0; col < matrix.getCols(); col++) {
        matrix.setValue(row, col, Math.random());
      }
    }
  }

  public static int getBiggestValueRowIndex(Matrix matrix) {
    int idx = 0;
    double max = 0;
    for (int row = 0; row < matrix.getRows(); row++) {
      double tot = 0;
      for (int col = 0; col < matrix.getCols(); col++) {
        tot += matrix.getValue(row, col);
      }
      if (tot > max) {
        idx = row;
        max = tot;
      }
    }
    return idx;
  }
}
