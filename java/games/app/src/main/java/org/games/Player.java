package org.games;

import java.util.ArrayList;
import java.util.List;

class Player {
  private String name;
  private List<Card> hand;

  public Player(String name) {
    this.name = name;
    this.hand = new ArrayList<>();
  }

  public void addCard(Card card) {
    hand.add(card);
  }

  public List<Card> getHand() {
    return new ArrayList<>(hand);
  }

  public String getName() {
    return name;
  }

  public void clearHand() {
    hand.clear();
  }
}
