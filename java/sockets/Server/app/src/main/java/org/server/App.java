package org.server;

import java.io.*;
import java.net.*;
import java.util.Random;

public class App {
    static String content = new String("");
    static final int port = 8080;
    public static void main(String[] args) {
        try (ServerSocket server = new ServerSocket(port)) {
            System.out.println("Listening for connections...");

            Socket client = server.accept();
            System.out.println("Client connected!");

            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            PrintWriter out = new PrintWriter(client.getOutputStream(), true);
            String message = new String("");
            while ( message.toLowerCase().equals("exit") ) {
                message = in.readLine();

                String response = new String(
                    "HTTP/1.1 200 OK\r\n" +
                    "Content-Type: application/json\r\n"
                );

                if ( message.toLowerCase().equals("weather") ) {

                    content += "{";
                    content += "\"weather\": \"" + getRandomWeather() + "\",";
                    content += "\"temperature\": " + getRandomTemperature();
                    content += "}\r\n";

                    response += "Content-Length: " + content.length() + "\r\n";
                    response += "\r\n" + content;

                    out.println(response);
                } else {
                    out.println("Error, valid commands are: `weather` and `exit`");
                }
            }

            client.close();
            server.close();
        } catch (IOException e) {
            System.err.println(e);
        }
    }

    static String getRandomWeather() {
      String[] weathers = { "Sunny", "Windy", "Rainy" };
      Random rnd = new Random();

      return weathers[ rnd.nextInt(3) ];
    }

    static int getRandomTemperature() {
      Random rnd = new Random();
      return rnd.nextInt(18,25);
    }
}
