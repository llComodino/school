package org.project;

import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Giocatore player = new Giocatore();

        Scanner scanner = new Scanner(System.in);
        do {
            player.setName(scanner.nextLine());
        } while (player.getName().length() < 1);

        Tile[] tiles = generateTiles();

        for (int i = 0; i < 5; i++) {
          buyTile(player, tiles, scanner);
          earn(player);
          System.out.println("You're new balance is: " + player.getBalance());
        }

        scanner.close();
    }

    private static Tile[] generateTiles() {
        Orto orto = new Orto("Orto", 120.0f, 4, 10, 20);
        Decorazione decorazione = new Decorazione("Decorazione", 300.0f, 2, "ABC123X");
        Stalla stalla = new Stalla("Stalla", 650.0f, 6, 5, 15);

        Tile[] tiles = new Tile[3];
        tiles[0] = orto;
        tiles[1] = decorazione;
        tiles[2] = stalla;

        return tiles;
    }

    private static int buyTile(Giocatore player, Tile[] tiles, Scanner sc) {
        int idx = 1;
        System.out.println("0. Exit");
        for (Tile tile : tiles) {
            System.out.println( (idx++) + ". " + tile.getName() + " - " + tile.getNTiles() + " tiles of space needed");
        }

        int choice = 0;
        int maxTiles = 0;
        do {
          maxTiles = player.getLargestAvailableTile();
          do {
            choice = sc.nextInt();
            sc.nextLine();

          } while (choice < 0 || choice > 3);

          if (choice == 0) return -1;
          if (tiles[choice - 1].ntiles > maxTiles) System.out.println("You're trying to purchare a tile too big\nCurrently you can purchase up to " + maxTiles + " tiles");
        } while (tiles[choice - 1].ntiles > maxTiles);

        System.out.println("You bought a new tile");
        System.out.println( tiles[choice - 1].getTileInfo() );

        player.incrementTiles( tiles[choice - 1].getNTiles() );
        player.addTile( tiles[choice - 1] );

        return player.getTiles();
    }

    private static void earn(Giocatore player) {
        player.properties.forEach( (prop) -> player.incrementBalance(prop.getPrice()) );
    }
}
