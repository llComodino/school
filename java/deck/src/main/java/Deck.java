import java.util.Random;

public class Deck {
  protected static final String[] suits = {
    "Hearts",
    "Spades",
    "Diamonds",
    "Clubs"
  };

  protected static final String[] cards = {
    "Ace",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Jack",
    "Queen",
    "King"
  };

  protected int[][] deck = new int[4][13];

  public Deck() {
    shuffleDeck();
  }

  public void shuffleDeck() {
    Random rnd = new Random(); 

    for (int i = 0; i < 52; i++) {
      int suit;
      int card;
      do {
         suit = rnd.nextInt(4);
         card = rnd.nextInt(13);
      } while (deck[suit][card] != 0);
      deck[suit][card] = i + 1;
    }
  }

  public void deal() {
    for (int j = 0; j < 52; j++) {
      for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 13; k++) {
          if (deck[i][k] == j) {
            System.out.println(Deck.cards[k] + " of " + Deck.suits[i]);
          }
        }
      }
    }
  }
}
