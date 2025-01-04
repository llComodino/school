package edu.esercizi;

public class Matrix {
  private int rows;
  private int cols;
  private double[][] data;

  public Matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
      throw new IllegalArgumentException("Rows and columns must be greater than zero.");
    }

    this.rows = rows;
    this.cols = cols;
    this.data = new double[rows][cols];
  }

  public int getRows() {
    return this.rows;
  }

  public int getCols() {
    return this.cols;
  }

  public void setValue(int row, int col, double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
      throw new IndexOutOfBoundsException("Invalid row or column index.");
    }
    this.data[row][col] = value;
  }

  public double getValue(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
      throw new IndexOutOfBoundsException("Invalid row or column index.");
    }
    return this.data[row][col];
  }

  public void printMatrix() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        System.out.print(this.data[i][j] + " ");
      }
      System.out.println();
    }
  }
}
