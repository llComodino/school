package org.shape;

import java.util.Scanner;

class App {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Creating a square");
    System.out.println("Enter base: ");
    int base = getDimension(sc);
    System.out.println("Enter height: ");
    int height = getDimension(sc);

    Square square = new Square(base, height);

    System.out.println("Creating a rectangle");
    System.out.println("Enter base: ");
    base = getDimension(sc);
    System.out.println("Enter height: ");
    height = getDimension(sc);

    sc.close();

    Rectangle rectangle = new Rectangle(base, height);

    System.out.println("\n\n");
    System.out.println(square.toString());
    System.out.println("Area: " + square.getArea());
    System.out.println("Perimeter: " + square.getPerimeter());
    System.out.println(rectangle.toString());
    System.out.println("Area: " + rectangle.getArea());
    System.out.println("Perimeter: " + rectangle.getPerimeter());
    System.out.println("\n\n");

  }

  static int getDimension(Scanner sc) {
    int dim = 0;
    do {
      dim = sc.nextInt();
      sc.nextLine();
    } while (dim < 0);

    return dim;
  }
}
