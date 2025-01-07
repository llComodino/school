package org.games;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Deck {
  private List<Card> cards;
  private final int numberOfDecks;

  public Deck(int numberOfDecks) {
    if (numberOfDecks < 1) {
      throw new IllegalArgumentException("Number of decks must be at least 1");
    }
    this.numberOfDecks = numberOfDecks;
    reset();
  }

  public Deck() {
    this(1);
  }

  public void shuffle() {
    Collections.shuffle(cards);
  }

  public Card drawCard() {
    if (cards.isEmpty()) {
      throw new IllegalStateException("No cards left in the deck");
    }
    return cards.remove(cards.size() - 1);
  }

  public List<Card> drawCards(int numCards) {
    if (numCards > cards.size()) {
      throw new IllegalArgumentException("Not enough cards left in the deck");
    }

    List<Card> drawnCards = new ArrayList<>();
    for (int i = 0; i < numCards; i++) {
      drawnCards.add(drawCard());
    }
    return drawnCards;
  }

  public int getRemainingCards() {
    return cards.size();
  }

  public int getNumberOfDecks() {
    return numberOfDecks;
  }

  public int getMaxCards() {
    return 52 * numberOfDecks;
  }

  public void reset() {
    cards = new ArrayList<>();
    for (int i = 0; i < numberOfDecks; i++) {
      for (Suit suit : Suit.values()) {
        for (Rank rank : Rank.values()) {
          cards.add(new Card(suit, rank));
        }
      }
    }
  }

  public void returnCard(Card card) {
    if (cards.size() >= getMaxCards()) {
      throw new IllegalStateException("Cannot return card: deck is full");
    }
    cards.add(card);
  }

  public boolean isFull() {
    return cards.size() == getMaxCards();
  }
}

enum Suit {
  HEARTS, DIAMONDS, CLUBS, SPADES
}

enum Rank {
  ACE(1), TWO(2), THREE(3), FOUR(4), FIVE(5), SIX(6), SEVEN(7),
  EIGHT(8), NINE(9), TEN(10), JACK(11), QUEEN(12), KING(13);

  private final int value;

  Rank(int value) {
    this.value = value;
  }

  public int getValue() {
    return value;
  }
}

class Card {
  private final Suit suit;
  private final Rank rank;

  public Card(Suit suit, Rank rank) {
    this.suit = suit;
    this.rank = rank;
  }

  public Suit getSuit() {
    return suit;
  }

  public Rank getRank() {
    return rank;
  }

  @Override
  public String toString() {
    return rank + " of " + suit;
  }
}
