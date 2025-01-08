package org.shape;

public class Rectangle extends Parallelogram {
  protected final String shape = "rectangle";
  public Rectangle(int b, int h) {
    super(b, h);
  }

  @Override
  public String toString() {
    return this.shape + ": " + super.toString();
  }
}
