package org.project;

class Orto extends Tile {
    protected int vegetablesNumber;
    protected int fruitNumber;

    public Orto(String name, float price, int ntiles, int veg, int fr) {
      super(name, price, ntiles);
      this.vegetablesNumber = veg;
      this.fruitNumber = fr;
    }

    public int getVegetables() {
        return this.vegetablesNumber;
    }

    public int getFruits() {
        return this.fruitNumber;
    }

    public void setVegetables(int veg) {
        this.vegetablesNumber = veg;
    }

    public void setFruits(int fr) {
        this.fruitNumber = fr;
    }

    @Override
    public String getTileInfo() {
        return super.getTileInfo() +
          "\nVegetables: " + this.vegetablesNumber +
          "\nFruit: " + this.fruitNumber;
    }
}
