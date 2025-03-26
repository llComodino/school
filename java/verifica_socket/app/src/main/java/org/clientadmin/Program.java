package org.clientadmin;

import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

import org.shared.Initiative;

class Program {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    try (Socket socket = new Socket("localhost", 5300)) {
      System.out.println("Connected to server");

      System.out.println("Enter your admin code:");
      String code = scanner.nextLine();

      socket.getOutputStream().write(code.getBytes());

      Initiative initiatives[] = new Initiative[10];
      for (int i = 0; i < 10; i++) {
        byte[] buffer = new byte[8192];
        int read = socket.getInputStream().read(buffer);
        String data = new String(buffer, 0, read);
        System.out.println("=== DATA: " + data);
        initiatives[i] = Initiative.fromString(data);

        socket.getOutputStream().write("OK".getBytes());
      }

      for (Initiative initiative : initiatives) {
        System.out.println(initiative);
      }

      System.out.println("Enter your initiatives id:");
      boolean found = false;
      do {
        int id = scanner.nextInt();
        for (Initiative initiative : initiatives) {
          if (initiative.getId() == id) {
            socket.getOutputStream().write(initiative.toString().getBytes());
            found = true;
            break;
          }
        }
      } while (found == false);
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      scanner.close();
    }
  }
}
