package org.bombclient;

import java.io.*;
import java.net.*;
import java.util.Random;
import java.util.Scanner;

public class App {
  static final private String host = "localhost";
  static final private int port = 8080;

  public static void main(String[] args) {
    try (Socket socket = new Socket(host, port);
       BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
       PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
       Scanner scanner = new Scanner(System.in)) {

      System.out.println("Would you like to set a timer on the bomb? Enter a number or any key for random:");
      String input = scanner.nextLine();
      int timer;

      try {
        timer = Integer.parseInt(input);
      } catch (NumberFormatException e) {
        timer = new Random().nextInt(10) + 1;
      }

      out.println(timer);
      System.out.println("Initial timer set to: " + timer);

      while ((input = in.readLine()) != null) {
        int receivedTimer = Integer.parseInt(input);
        if (receivedTimer == 0) {
          System.out.println("BOOM! The bomb exploded!");
          break;
        }
        System.out.println("Timer received: " + receivedTimer);
        out.println(receivedTimer - 1);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
