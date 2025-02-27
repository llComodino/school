package org.txtserver;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class App {
    private static String getFileContents(String path) {
        InputStream is = App.class.getClassLoader().getResourceAsStream(path);
        try (Scanner sc = new Scanner(is)) {
            StringBuilder sb = new StringBuilder();
            while (sc.hasNextLine()) {
                sb.append(sc.nextLine());
                sb.append("\n");
            }
            return sb.toString();
        }
    }

    public static void main(String[] args) {
        try (ServerSocket server = new ServerSocket(8080)) {
            System.out.println("Server is listening on port 8080");

            Socket client = server.accept();
            System.out.println("Client connected");

            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            PrintWriter out = new PrintWriter(client.getOutputStream(), true);

            out.println("Commands:\n\texit | quit\tclose the connection\n\taforismo\tget a random aphorism\n\tproverbio\tget a random proverb\n\n");

            String command;
            while ((command = in.readLine()) != null) {
                if ("quit".equals(command) || "exit".equals(command)) {
                    break;
                }

                if ("aforismo".equals(command)) {
                    String[] aforismi = getFileContents("aforismi.txt").split("\n");

                    int index = (int) (Math.random() * aforismi.length);
                    out.println(aforismi[index]);
                }

                if ("proverbio".equals(command)) {
                    String[] proverbi = getFileContents("proverbi.txt").split("\n");

                    int index = (int) (Math.random() * proverbi.length);
                    out.println(proverbi[index]);
                }
            }
        } catch (Exception e) {
            System.out.println("Server exception: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
