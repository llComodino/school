package org.shape;

public abstract class Parallelogram extends Shape {
  protected int base;
  protected int height;

  public Parallelogram(int b, int h) {
    setBase(b);
    setHeight(h);
  }

  void setBase(int b) {
    this.base = b;
  }

  void setHeight(int h) {
    this.height = h;
  }

  @Override
  int getArea() {
    return this.base * this.height;
  }

  @Override
  int getPerimeter() {
    return this.base * 2 + this.height * 2;
  }

  @Override
  public String toString() {
    return "{ base: " + this.base + ", height: " + this.height + " }";
  }
}
