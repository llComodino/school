package org.sum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class App {
    public static void main(String[] args) {
        try (ServerSocket server = new ServerSocket(8080)) {
            Socket client = server.accept();

            int num_1 = getNumber(client);
            int num_2 = getNumber(client);

            System.out.println("Sum of nums is: " + (num_1 + num_2));

            client.close();
        } catch (IOException e) {
            System.err.println(e);
        }
    }

    private static int getNumber(Socket client) {
        int num = 0;

        try {
            PrintWriter out = new PrintWriter(client.getOutputStream(), true);
            out.println("Enter an integer: ");

            String line = "";
            do {
                BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                line = in.readLine();
            } while (line.chars().anyMatch( (c) -> c < '0' || c > '9'));

            num = Integer.valueOf(line);
        } catch (IOException e) {
            System.err.println(e);
        }

        return num;
    }

	@Override
	public String toString() {
		return "App []";
	}
}
