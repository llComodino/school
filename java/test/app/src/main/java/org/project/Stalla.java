package org.project;

class Stalla extends Tile {
    protected int horses;
    protected int hayBalls;

    public Stalla(String name, float price, int ntiles, int horses, int hb) {
      super(name, price, ntiles);
      this.horses = horses;
      this.hayBalls = hb;
    }

    public int getHorses() {
        return this.horses;
    }

    public int getHayBalls() {
        return this.hayBalls;
    }

    public void setHorses(int horses) {
        this.horses = horses;
    }

    public void setHayBalls(int hb) {
        this.hayBalls = hb;
    }

    @Override
    public String getTileInfo() {
        return super.getTileInfo() +
          "\nHorses: " + this.horses +
          "\nHayballs: " + this.hayBalls;
    }
}
