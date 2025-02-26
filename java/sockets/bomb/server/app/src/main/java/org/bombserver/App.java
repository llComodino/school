package org.bombserver;

import java.io.*;
import java.net.*;

public class App {
  static final private int port = 8080;
  public static void main(String[] args) {
    try (ServerSocket serverSocket = new ServerSocket(port)) {
      System.out.println("Server is waiting for a connection...");
      try (Socket socket = serverSocket.accept();
         BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
         PrintWriter out = new PrintWriter(socket.getOutputStream(), true)) {

        System.out.println("Client connected!");
        String input;
        while ((input = in.readLine()) != null) {
          int timer = Integer.parseInt(input);
          System.out.println("Received timer: " + timer);

          if (timer > 0) {
            timer--;
            System.out.println("Sending back: " + timer);
            out.println(timer);
          } else {
            System.out.println("Bomb exploded!");
            break;
          }
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
