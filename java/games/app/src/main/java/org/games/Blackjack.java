package org.games;

import java.util.List;

public class Blackjack extends Game {
  private static final int BLACKJACK_VALUE = 21;

  public Blackjack(List<Player> players) {
    super(6, players);
  }

  @Override
  public void dealInitialCards() {
    Card card = null;
    System.out.println("Dealing first hand");
    deck.shuffle();
    for (int i = 0; i < 2; i++) {
      for (Player player : players) {
        card = deck.drawCard();
        player.addCard(card);
        System.out.println(player.getName() + " got " + card.toString());
      }
      card = deck.drawCard();
      dealer.addCard(card);
    }
  }

  public void playerHit(Player player) {
    if (getHandValue(player) < BLACKJACK_VALUE) {
      Card card = deck.drawCard();
      player.addCard(card);
      System.out.println("Player Hit -> " + card.toString());
    }
  }

  public void dealerPlay() {
    while (getHandValue(dealer) < 17) {
      Card card = deck.drawCard();
      dealer.addCard(card);
      System.out.println("Dealer Hit -> " + card.toString());
    }
  }

  public int getHandValue(Player player) {
    List<Card> hand = player.getHand();
    int value = 0;
    int aces = 0;

    for (Card card : hand) {
      if (card.getRank() == Rank.ACE) {
        aces++;
      } else if (card.getRank().getValue() >= 10) {
        value += 10;
      } else {
        value += card.getRank().getValue();
      }
    }

    for (int i = 0; i < aces; i++) {
      if (value + 11 <= BLACKJACK_VALUE) {
        value += 11;
      } else {
        value += 1;
      }
    }

    return value;
  }

  @Override
  public boolean isGameOver() {
    for (Player player : players) {
      if (getHandValue(player) > BLACKJACK_VALUE) {
        return true;
      }
    }
    return getHandValue(dealer) > BLACKJACK_VALUE;
  }

  @Override
  public void determineWinners() {
    int dealerValue = getHandValue(dealer);

    for (Player player : players) {
      int playerValue = getHandValue(player);

      if (playerValue > BLACKJACK_VALUE) {
        System.out.println(player.getName() + " busts!");
      } else if (dealerValue > BLACKJACK_VALUE) {
        System.out.println(player.getName() + " wins! Dealer busted.");
      } else if (playerValue > dealerValue) {
        System.out.println(player.getName() + " wins!");
      } else if (playerValue < dealerValue) {
        System.out.println(player.getName() + " loses!");
      } else {
        System.out.println(player.getName() + " pushes (ties).");
      }
    }
  }
}
