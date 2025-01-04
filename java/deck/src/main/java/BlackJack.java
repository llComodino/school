import java.util.Random;
import java.util.Vector;

public class BlackJack {
  protected Deck deck;
  protected Vector<Integer> players = new Vector<Integer>();

  public BlackJack() {
    this.initDeck();
  }

  private void initDeck() {
    for (int[] row : this.deck.deck) {
      for (int i = 0; i < 3; i++) {
        row[i] = i + 1;
      }
      row[10] = 10;
      row[11] = 10;
      row[12] = 10;
    }
  }

  public int addPlayer() {
    this.players.add(0);
    return this.players.size();
  }

  private void resetPlayers() {
    players.iterator().forEachRemaining( (el) -> el = 0);
  }

  public int deal() {
    Random rnd = new Random();

    int row, col, val;
    do {
      row = rnd.nextInt();
      col = rnd.nextInt();
    } while (this.deck.deck[row][col] == 0);

    val = this.deck.deck[row][col]; 
    this.deck.deck[row][col] = 0;

    return val;
  }

  public void new_game() {
    this.resetPlayers();
    this.deck.shuffleDeck();

    for (int i = 0; i < this.deck.deck.length * this.deck.deck[0].length; i++) {
      switch (i % this.players.size()) {
        case 0:
          break;
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;

        default:
          System.out.println("Error");
          break;
      }
    }
  }
}
