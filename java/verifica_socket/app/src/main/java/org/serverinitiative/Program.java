package org.serverinitiative;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

import org.shared.Initiative;

class Program {
  public static void main (String[] args) {
    try (ServerSocket server = new ServerSocket(5300)) {
      System.out.println("Server is listening on port 5300");
      for (int i = 0; i < 10; i++) {
        handler(server.accept());
      }
      System.out.println("Won initiative: " + admin_handler(server.accept()));
    } catch (IOException e) {
      e.printStackTrace();
    }
  }

  private static int mkid() {
    return (int) (Math.random() * 1000);
  }

  private static void handler(Socket socket) {
    try {
      byte[] buffer = new byte[8192];
      int read = socket.getInputStream().read(buffer);
      String data = new String(buffer, 0, read);
      Initiative initiative = Initiative.fromString(data);

      if (initiative.getId() == -1) {
        initiative.setId(mkid());
      }

      File file = new File("project.txt");
      FileWriter fileWriter = new FileWriter(file, true);
      fileWriter.write(initiative.toString() + "\n");
      fileWriter.close();

      socket.getOutputStream().write(initiative.toString().getBytes());
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      try {
        socket.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }
  }

  private static int admin_handler(Socket socket) {
    int id = -1;
    try {
      byte[] buffer = new byte[4096];
      int read = socket.getInputStream().read(buffer);
      String data = new String(buffer, 0, read);
      Initiative initiatives[] = new Initiative[10];
      if (data.equals("AD2345")) {
        File file = new File("project.txt");
        Scanner scanner = new Scanner(file);
        for (int i = 0; i < 10; i++) {
          initiatives[i] = Initiative.fromString(scanner.nextLine());
        }
        scanner.close();

        for (Initiative initiative : initiatives) {
          socket.getOutputStream().write(initiative.toString().getBytes());
          socket.getInputStream().read(buffer);
          if (!new String(buffer, 0, 2).equals("OK")) {
            System.out.println("Invalid response from client");
            return -1;
          }
        }

        Initiative winner = Initiative.fromString(new String(buffer, 0, socket.getInputStream().read(buffer)));
        id = winner.getId();
      }
    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      try {
        socket.close();
      } catch (IOException e) {
        e.printStackTrace();
      }
    }

    return id;
  }
}
