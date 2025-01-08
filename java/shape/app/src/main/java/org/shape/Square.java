package org.shape;

public class Square extends Parallelogram {
  protected final String shape = "square";

  public Square(int b, int h) {
    super(b, h);
  }

  @Override
  public String toString() {
    return this.shape + ": " + super.toString();
  }
}
