package org.txtclient;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class App {
    private static final String host = "localhost";
    private static final int port = 8080;

    public static void main(String[] args) {
        try (Socket client = new Socket(host, port)) {
            System.out.println("Connected to server: " + client.getRemoteSocketAddress());

            BufferedReader reader = new BufferedReader(new InputStreamReader(client.getInputStream()));
            PrintWriter writer = new PrintWriter(client.getOutputStream(), true);

            for (String line = reader.readLine(); line != null; line = reader.readLine()) {
                System.out.println(line);
            }

            while (client.isConnected()) {
                Scanner sc = new Scanner(System.in);
                String message = sc.nextLine();

                System.out.println("message: " + message);
                writer.println(message);

                sc.close();

                for (String line = reader.readLine(); line != null; line = reader.readLine()) {
                    System.out.println(line);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
