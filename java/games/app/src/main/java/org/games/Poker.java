package org.games;

import java.util.*;
import java.util.stream.Collectors;

import javax.print.attribute.standard.PrinterLocation;
import javax.security.auth.PrivateCredentialPermission;

public class Poker extends Game {
  private List<Card> communityCards;
  private int pot;
  private int currentBet;
  private int dealerPosition;
  private List<PokerPlayer> activePlayers;

  public Poker(List<Player> players, int initialChips) {
    super(1, players);    communityCards = new ArrayList<>();
    pot = 0;
    currentBet = 0;
    dealerPosition = 0;

    activePlayers = new ArrayList<>();
    for (Player player : players) {
      activePlayers.add(new PokerPlayer(player.getName(), initialChips));
    }
  }

  @Override
  public void dealInitialCards() {
    deck.shuffle();
    for (int i = 0; i < 2; i++) {
      for (PokerPlayer player : activePlayers) {
        if (!player.hasFolded()) {
          player.addCard(deck.drawCard());
        }
      }
    }
    for (PokerPlayer player : activePlayers) {
        System.out.println(player.getName() + " Hand: " + player.getHand());
    }
  }

  public void dealFlop() {
    deck.drawCard();
    System.out.println("Dealing Flop:");
    for (int i = 0; i < 3; i++) {
      Card card = deck.drawCard();
      communityCards.add(card);
      System.out.println(card.toString());
    }
  }

  public void dealTurnOrRiver() {
    deck.drawCard();
    System.out.println("River:");
    Card card = deck.drawCard();
    communityCards.add(card);
    System.out.println(card.toString());
  }

  public void bettingRound() {
    currentBet = 0;
    for (PokerPlayer player : activePlayers) {
      player.setCurrentBet(0);
    }
  }

  public PokerHand evaluateHand(PokerPlayer player) {
    List<Card> allCards = new ArrayList<>(player.getHand());
    allCards.addAll(communityCards);

    if (hasRoyalFlush(allCards)) return PokerHand.ROYAL_FLUSH;
    if (hasStraightFlush(allCards)) return PokerHand.STRAIGHT_FLUSH;
    if (hasFourOfAKind(allCards)) return PokerHand.FOUR_OF_A_KIND;
    if (hasFullHouse(allCards)) return PokerHand.FULL_HOUSE;
    if (hasFlush(allCards)) return PokerHand.FLUSH;
    if (hasStraight(allCards)) return PokerHand.STRAIGHT;
    if (hasThreeOfAKind(allCards)) return PokerHand.THREE_OF_A_KIND;
    if (hasTwoPair(allCards)) return PokerHand.TWO_PAIR;
    if (hasPair(allCards)) return PokerHand.PAIR;
    return PokerHand.HIGH_CARD;
  }

  private boolean hasFourOfAKind(List<Card> cards) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : cards) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }
    return rankCount.containsValue(4);
  }

  private boolean hasFullHouse(List<Card> cards) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : cards) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }
    return rankCount.containsValue(3) && rankCount.containsValue(2);
  }

  private boolean hasRoyalFlush(List<Card> cards) {
    if (!hasStraightFlush(cards)) return false;

    Suit flushSuit = findFlushSuit(cards);
    List<Card> suitCards = cards.stream()
      .filter(card -> card.getSuit() == flushSuit)
      .sorted((c1, c2) -> c2.getRank().getValue() - c1.getRank().getValue())
      .collect(Collectors.toList());

    return suitCards.get(0).getRank() == Rank.ACE;
  }

  private boolean hasStraightFlush(List<Card> cards) {
    for (Suit suit : Suit.values()) {
      List<Card> suitCards = cards.stream()
        .filter(card -> card.getSuit() == suit)
        .collect(Collectors.toList());

      if (suitCards.size() >= 5 && hasStraight(suitCards)) {
        return true;
      }
    }
    return false;
  }

  private Suit findFlushSuit(List<Card> cards) {
    Map<Suit, Long> suitCounts = cards.stream()
      .collect(Collectors.groupingBy(Card::getSuit, Collectors.counting()));

    return suitCounts.entrySet().stream()
      .filter(entry -> entry.getValue() >= 5)
      .map(Map.Entry::getKey)
      .findFirst()
      .orElse(null);
  }

  private boolean hasFlush(List<Card> cards) {
    return findFlushSuit(cards) != null;
  }

  private boolean hasStraight(List<Card> cards) {
    List<Integer> values = cards.stream()
      .map(card -> card.getRank().getValue())
      .distinct()
      .sorted()
      .collect(Collectors.toList());

    if (values.contains(14)) { values.add(1); }

    int consecutiveCount = 1;
    for (int i = 1; i < values.size(); i++) {
      if (values.get(i) == values.get(i-1) + 1) {
        consecutiveCount++;
        if (consecutiveCount == 5) return true;
      } else {
        consecutiveCount = 1;
      }
    }
    return false;
  }

  private boolean hasThreeOfAKind(List<Card> cards) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : cards) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }
    return rankCount.containsValue(3);
  }

  private boolean hasTwoPair(List<Card> cards) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : cards) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }
    return rankCount.values().stream().filter(count -> count == 2).count() >= 2;
  }

  private boolean hasPair(List<Card> cards) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : cards) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }
    return rankCount.containsValue(2);
  }

  private List<Card> getBestFiveCards(List<Card> cards) {
    List<Card> sortedCards = new ArrayList<>(cards);
    sortedCards.sort((c1, c2) -> {
      int rank1 = c1.getRank() == Rank.ACE ? 14 : c1.getRank().getValue();
      int rank2 = c2.getRank() == Rank.ACE ? 14 : c2.getRank().getValue();
      return rank2 - rank1;
    });

    return sortedCards.subList(0, Math.min(5, sortedCards.size()));
  }

  public int compareEqualHands(PokerPlayer player1, PokerPlayer player2, PokerHand handType) {
    List<Card> hand1 = new ArrayList<>(player1.getHand());
    List<Card> hand2 = new ArrayList<>(player2.getHand());
    hand1.addAll(communityCards);
    hand2.addAll(communityCards);

    switch (handType) {
      case HIGH_CARD:
        return compareHighCards(getBestFiveCards(hand1), getBestFiveCards(hand2));
      case PAIR:
        return comparePairs(hand1, hand2);
      case TWO_PAIR:
        return compareTwoPairs(hand1, hand2);
      case THREE_OF_A_KIND:
        return compareThreeOfAKind(hand1, hand2);
      case STRAIGHT:
        return compareStraights(hand1, hand2);
      case FLUSH:
        return compareFlush(hand1, hand2);
      case FULL_HOUSE:
        return compareFullHouse(hand1, hand2);
      case FOUR_OF_A_KIND:
        return compareFourOfAKind(hand1, hand2);
      default:
        return 0;    }
  }

  private int compareHighCards(List<Card> hand1, List<Card> hand2) {
    for (int i = 0; i < Math.min(hand1.size(), hand2.size()); i++) {
      int rank1 = hand1.get(i).getRank() == Rank.ACE ? 14 : hand1.get(i).getRank().getValue();
      int rank2 = hand2.get(i).getRank() == Rank.ACE ? 14 : hand2.get(i).getRank().getValue();
      if (rank1 != rank2) {
        return rank1 - rank2;
      }
    }
    return 0;
  }

  private int comparePairs(List<Card> hand1, List<Card> hand2) {
    int pair1 = getPairRank(hand1);
    int pair2 = getPairRank(hand2);

    if (pair1 != pair2) {
      return pair1 - pair2;
    }

    return compareHighCards(
      getKickers(hand1, pair1),
      getKickers(hand2, pair2)
    );
  }

  private int compareTwoPairs(List<Card> hand1, List<Card> hand2) {
    List<Integer> pairs1 = getPairRanks(hand1);
    List<Integer> pairs2 = getPairRanks(hand2);

    if (pairs1.get(0) != pairs2.get(0)) {
      return pairs1.get(0) - pairs2.get(0);
    }

    if (pairs1.get(1) != pairs2.get(1)) {
      return pairs1.get(1) - pairs2.get(1);
    }

    return compareHighCards(
      getKickersExcludingPairs(hand1, pairs1),
      getKickersExcludingPairs(hand2, pairs2)
    );
  }

  private List<Integer> getPairRanks(List<Card> hand) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : hand) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }

    return rankCount.entrySet().stream()
      .filter(e -> e.getValue() == 2)
      .map(e -> e.getKey().getValue())
      .sorted(Collections.reverseOrder())
      .collect(Collectors.toList());
  }

  private List<Card> getKickersExcludingPairs(List<Card> hand, List<Integer> pairRanks) {
    return hand.stream()
      .filter(card -> !pairRanks.contains(card.getRank().getValue()))
      .sorted((c1, c2) -> c2.getRank().getValue() - c1.getRank().getValue())
      .collect(Collectors.toList());
  }

  private int compareThreeOfAKind(List<Card> hand1, List<Card> hand2) {
    int three1 = getThreeOfAKindRank(hand1);
    int three2 = getThreeOfAKindRank(hand2);

    if (three1 != three2) {
      return three1 - three2;
    }

    return compareHighCards(
      getKickers(hand1, three1),
      getKickers(hand2, three2)
    );
  }

  private int getThreeOfAKindRank(List<Card> hand) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : hand) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }

    return rankCount.entrySet().stream()
      .filter(e -> e.getValue() == 3)
      .map(e -> e.getKey().getValue())
      .findFirst()
      .orElse(0);
  }

  private int compareStraights(List<Card> hand1, List<Card> hand2) {
    int highCard1 = getHighestStraightCard(hand1).getValue();
    int highCard2 = getHighestStraightCard(hand2).getValue();

    if (isAceLowStraight(hand1)) highCard1 = 5;
    if (isAceLowStraight(hand2)) highCard2 = 5;

    return highCard1 - highCard2;
  }

  private Rank getHighestStraightCard(List<Card> hand) {
    List<Card> sortedCards = new ArrayList<>(hand);
    sortedCards.sort((c1, c2) -> c2.getRank().getValue() - c1.getRank().getValue());

    for (int i = 0; i < sortedCards.size() - 4; i++) {
      if (isStraightFromIndex(sortedCards, i)) {
        return sortedCards.get(i).getRank();
      }
    }
    return Rank.TWO;  }

  private boolean isStraightFromIndex(List<Card> sortedCards, int startIndex) {
    for (int i = startIndex; i < startIndex + 4; i++) {
      if (sortedCards.get(i).getRank().getValue() -
        sortedCards.get(i + 1).getRank().getValue() != 1) {
        return false;
      }
    }
    return true;
  }

  private boolean isAceLowStraight(List<Card> hand) {
    return hand.stream().anyMatch(c -> c.getRank() == Rank.ACE) &&
         hand.stream().anyMatch(c -> c.getRank() == Rank.TWO) &&
         hand.stream().anyMatch(c -> c.getRank() == Rank.THREE) &&
         hand.stream().anyMatch(c -> c.getRank() == Rank.FOUR) &&
         hand.stream().anyMatch(c -> c.getRank() == Rank.FIVE);
  }

  private int compareFlush(List<Card> hand1, List<Card> hand2) {
    List<Card> flush1 = getBestFlushCards(hand1);
    List<Card> flush2 = getBestFlushCards(hand2);

    return compareHighCards(flush1, flush2);
  }

  private List<Card> getBestFlushCards(List<Card> hand) {
    Suit flushSuit = findFlushSuit(hand);
    return hand.stream()
      .filter(card -> card.getSuit() == flushSuit)
      .sorted((c1, c2) -> c2.getRank().getValue() - c1.getRank().getValue())
      .limit(5)
      .collect(Collectors.toList());
  }

  private int compareFullHouse(List<Card> hand1, List<Card> hand2) {
    int three1 = getThreeOfAKindRank(hand1);
    int three2 = getThreeOfAKindRank(hand2);

    if (three1 != three2) {
      return three1 - three2;
    }

    int pair1 = getPairRank(hand1);
    int pair2 = getPairRank(hand2);

    return pair1 - pair2;
  }

  private int compareFourOfAKind(List<Card> hand1, List<Card> hand2) {
    int four1 = getFourOfAKindRank(hand1);
    int four2 = getFourOfAKindRank(hand2);

    if (four1 != four2) {
      return four1 - four2;
    }

    return compareHighCards(
      getKickers(hand1, four1),
      getKickers(hand2, four2)
    );
  }

  private int getFourOfAKindRank(List<Card> hand) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : hand) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }

    return rankCount.entrySet().stream()
      .filter(e -> e.getValue() == 4)
      .map(e -> e.getKey().getValue())
      .findFirst()
      .orElse(0);
  }

  private int getPairRank(List<Card> hand) {
    Map<Rank, Integer> rankCount = new HashMap<>();
    for (Card card : hand) {
      rankCount.merge(card.getRank(), 1, Integer::sum);
    }

    return rankCount.entrySet().stream()
      .filter(e -> e.getValue() == 2)
      .map(e -> e.getKey().getValue())
      .max(Integer::compareTo)
      .orElse(0);
  }

  private List<Card> getKickers(List<Card> hand, int excludeRank) {
    return hand.stream()
      .filter(card -> card.getRank().getValue() != excludeRank)
      .sorted((c1, c2) -> c2.getRank().getValue() - c1.getRank().getValue())
      .collect(Collectors.toList());
  }

  @Override
  public boolean isGameOver() {
    int activePlayers = 0;
    for (PokerPlayer player : this.activePlayers) {
      if (!player.hasFolded()) activePlayers++;
    }
    return activePlayers == 1 || communityCards.size() == 5;
  }

  @Override
  public void determineWinners() {
    List<PokerPlayer> winners = new ArrayList<>();
    PokerHand bestHand = PokerHand.HIGH_CARD;

    for (PokerPlayer player : activePlayers) {
      if (!player.hasFolded()) {
        PokerHand hand = evaluateHand(player);
        if (winners.isEmpty() || hand.ordinal() > bestHand.ordinal()) {
          winners.clear();
          winners.add(player);
          bestHand = hand;
        } else if (hand.ordinal() == bestHand.ordinal()) {
          winners.add(player);
        }
      }
    }

    int winnings = pot / winners.size();
    for (PokerPlayer winner : winners) {
      winner.addChips(winnings);
      System.out.println(winner.getName() + " wins " + winnings + " chips with " + bestHand);
    }
    pot = 0;
  }

  public void postBlinds() {
    int smallBlindPos = (dealerPosition + 1) % activePlayers.size();
    int bigBlindPos = (dealerPosition + 2) % activePlayers.size();

    int smallBlind = 10;
    int bigBlind = 20;

    PokerPlayer smallBlindPlayer = activePlayers.get(smallBlindPos);
    PokerPlayer bigBlindPlayer = activePlayers.get(bigBlindPos);

    smallBlindPlayer.removeChips(smallBlind);
    bigBlindPlayer.removeChips(bigBlind);

    pot += smallBlind + bigBlind;
    currentBet = bigBlind;
  }

  public void rotateDealerButton() {
    dealerPosition = (dealerPosition + 1) % activePlayers.size();
  }
}
