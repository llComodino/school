package org.games;

import java.util.ArrayList;
import java.util.List;

abstract class Game {
  protected Deck deck;
  protected List<Player> players;
  protected Player dealer;

  public Game(int numberOfDecks, List<Player> ps) {
    this.deck = new Deck(numberOfDecks);
    this.players = new ArrayList<>();
    for (Player player : ps) {
      this.players.add(player);
    }
    this.dealer = new Player("Dealer");
  }

  abstract void dealInitialCards();
  abstract boolean isGameOver();
  abstract void determineWinners();
}
