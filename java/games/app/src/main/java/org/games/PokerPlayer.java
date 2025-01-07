package org.games;

enum PokerHand {
  HIGH_CARD,
  PAIR,
  TWO_PAIR,
  THREE_OF_A_KIND,
  STRAIGHT,
  FLUSH,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  STRAIGHT_FLUSH,
  ROYAL_FLUSH
}

class PokerPlayer extends Player {
  private int chips;
  private boolean hasFolded;
  private int currentBet;

  public PokerPlayer(String name, int initialChips) {
    super(name);
    this.chips = initialChips;
    this.hasFolded = false;
    this.currentBet = 0;
  }

  public int getChips() { return chips; }
  public void addChips(int amount) { chips += amount; }
  public void removeChips(int amount) { chips -= amount; }
  public boolean hasFolded() { return hasFolded; }
  public void setFolded(boolean folded) { hasFolded = folded; }
  public int getCurrentBet() { return currentBet; }
  public void setCurrentBet(int bet) { currentBet = bet; }
}
