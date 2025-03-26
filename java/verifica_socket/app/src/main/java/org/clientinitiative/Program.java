package org.clientinitiative;

import org.shared.Initiative;

import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

class Program {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    try (Socket socket = new Socket("localhost", 5300)) {
      System.out.println("Enter your name:");
      String name = scanner.nextLine();

      System.out.println("Enter your surname:");
      String surname = scanner.nextLine();

      System.out.println("Enter your initiative:");
      String initiativeName = scanner.nextLine();

      System.out.println("Enter your cost:");
      float cost = scanner.nextFloat();

      Initiative initiative = new Initiative(-1, initiativeName, cost);

      socket.getOutputStream().write(initiative.toString().getBytes());
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      scanner.close();
    }
  }
}
