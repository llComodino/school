package org.games;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class App {
  public static void main (String[] args) {
    List<Player> players = new ArrayList<Player>();

    Scanner scanner = new Scanner(System.in);
    String name;
    do {
      System.out.println("Insert new player name (leave empty to confirm) [1-4]: ");
      name = scanner.nextLine();

      if ( ! name.isBlank() ) players.add(new Player(name));
    } while ( ( ! name.isBlank() && players.size() < 4 ) || ( name.isBlank() && players.size() < 1 ) );
    scanner.close();

    playPoker(players);
  }

  static void playBlackjack(List<Player> players) {
    Blackjack game = new Blackjack(players);

    game.dealInitialCards();

    for (Player player : game.players) {
      while (game.getHandValue(player) < 21) {
        game.playerHit(player);
      }
    }

    game.dealerPlay();
    game.determineWinners();
  }

  static void playPoker(List<Player> players) {
    Poker game = new Poker(players, 1000);

    Scanner scanner = new Scanner(System.in);
    while (true) {
      playPokerRound(game);
      System.out.println("Play another hand? (yes/no)");
      String again = scanner.nextLine().toLowerCase();
      if (again == "no" || again == "n") break;
      game.rotateDealerButton();
    }
    scanner.close();

    System.out.println("Thanks for playing!");
  }

  private static void playPokerRound(Poker game) {
    game.postBlinds();

    game.dealInitialCards();

    game.bettingRound();

    if (!game.isGameOver()) {
        game.dealFlop();
        game.bettingRound();
    }

    if (!game.isGameOver()) {
        game.dealTurnOrRiver();
        game.bettingRound();
    }

    if (!game.isGameOver()) {
        game.dealTurnOrRiver();
        game.bettingRound();
    }

    game.determineWinners();
  }
}
