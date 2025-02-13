package org.project;

class Tile implements TileInterface {
    enum TileKind {
        DECORATION,
        PRODUCT
    };

    protected String name;
    protected int ntiles;
    protected int posX;
    protected int posY;
    protected float price;
    protected TileKind tipoTile;

    public Tile() {
      this.posX = -1;
      this.posY = -1;
    }

    public Tile(String name, float price, int ntiles) {
      super();
      this.name = name;
      this.price = price;
      this.ntiles = ntiles;
    }

    public String getName() {
        return this.name;
    }

    public int getPosX() {
        return this.posX;
    }

    public int getPosY() {
        return this.posY;
    }

    public float getPrice() {
        return this.price;
    }

    public int getNTiles() {
        return this.ntiles;
    }

    public TileKind getKind() {
        return this.tipoTile;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setPosX(int x) {
        this.posX = x;
    }

    public void setPosY(int y) {
        this.posY = y;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public void setNTiles(int ntiles) {
        this.ntiles = ntiles;
    }

    public void setKind(TileKind kind) {
        this.tipoTile = kind;
    }

    public String getTileInfo() {
        return "Tile: " + this.name +
               "\nTiles Occupied: " + this.ntiles +
               "\n(posX, posY): (" + this.posX + ", " + this.posY + ")" +
               "\nPrice: " + price +
               "$\nKind: " + tipoTile;
    }
}
