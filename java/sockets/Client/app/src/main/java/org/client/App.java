package org.client;

import java.io.*;
import java.net.*;

class App {
  public static void main (String[] args) {
    try (Socket client = new Socket("localhost", 8080)) {
      System.out.println("Client initialized!");

      PrintWriter out = new PrintWriter(client.getOutputStream(), true);
      out.println("Hello, World (from another machine)!");

      BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
      System.out.println("Server says: " + in.readLine());

      client.close();
    } catch (IOException e) {
      System.err.println(e);
    }
  }
}
