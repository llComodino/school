package org.server;

import java.io.*;
import java.net.*;

public class App {
    protected static String name = "GilaServer";
    protected static int port = 8080;
    protected static String address = "localhost";
    protected static String content = new String(
        "{"+
        "\"name\":\"" + name + "\"," +
        "\"addr\":\"" + address + "\"," +
        "\"port\":" + port +
        "}"
    );
    public static void main(String[] args) {
        try (ServerSocket server = new ServerSocket(port)) {
            System.out.println("Listening for connections...");

            Socket client = server.accept();
            System.out.println("Client connected!");

            BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
            String message = in.readLine();
            System.out.println("Client says: " + message);

            String response = new String(
                "HTTP/1.1 200 OK\r\n" +
                "Content-Type: application/json\r\n" +
                "Content-Length: " + content.length() + "\r\n" +
                "\r\n" +
                content
            );
            PrintWriter out = new PrintWriter(client.getOutputStream(), true);
            out.println(response);

            client.close();
            server.close();
        } catch (IOException e) {
            System.err.println(e);
        }
    }
}
