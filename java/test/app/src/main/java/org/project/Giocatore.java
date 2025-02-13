package org.project;

import java.util.Vector;

class Giocatore {
    protected String name;
    protected float balance = 0.0f;
    protected int[][] matrix;
    protected int tiles = 0;
    protected Vector<Tile> properties = new Vector<>();

    public Giocatore() {
        this.resetMatrix();
    }

    public Giocatore(String name) {
        super();
        this.name = name;
    }

    public Giocatore(String name, float balance) {
        this.name = name;
        this.balance = balance;
        this.resetMatrix();
    }

    public Giocatore(String name, float balance, int[][] matrix) {
        this.name = name;
        this.balance = balance;
        this.matrix = matrix;
    }

    public void resetMatrix() {
        this.matrix = new int[10][10];
    }

    public void printMatrix() {
        for (int[] row : matrix) {
          for (int cell : row) {
            System.out.print(cell + " ");
          }
          System.out.println("");
        }
    }

    public String getName() {
      return this.name;
    }

    public float getBalance() {
      return this.balance;
    }

    public int[][] getMatrix() {
      return this.matrix;
    }

    public int getTiles() {
        return this.tiles;
    }

    public void setName(String name) {
      this.name = name;
    }

    public void setBalance(float balance) {
      this.balance = balance;
    }

    public void incrementBalance(float increment) {
        this.balance += increment;
    }

    public void decrementBalance(float decrement) {
        this.balance -= decrement;
    }

    public void incrementTiles(int tiles) {
        this.tiles += tiles;
    }

    public void setMatrix(int[][] matrix) {
        this.matrix = matrix;
    }

    public int getLargestAvailableTile() {
        int max = 0;
        int c = 0;

        for (int[] row : this.matrix) {
          c = 0;
          for (int cell : row) {
            if (cell == 0) c++;
          }
          if (c > max) max = c;
        }

        return max;
    }

    private int insertAtRow(int row, int cell, int tiles) {
        this.tiles++;

        for (int i = cell; i < tiles; i++) {
          this.matrix[row][i] = tiles;
        }

        return this.tiles;
    }

    public int addTile(Tile tile) {
        int c = 0;
        int rowIdx = 0;
        int cellIdx = 0;
        for (int row[] : this.matrix) {
          c = 0;
          for (int cell : row) {
            if (cell == 0) c++;
            cellIdx++;
          }
          if (c >= tile.ntiles) {
            insertAtRow(rowIdx, cellIdx, tile.ntiles);

            tile.setPosX(cellIdx);
            tile.setPosY(rowIdx);
            break;
          }
          rowIdx++;
        }

        this.properties.add( tile );
        return tile.ntiles;
    }
}
