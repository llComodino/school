package org.project;

class Decorazione extends Tile {
    protected String code;

    public Decorazione(String name, float price, int ntiles, String code) {
        super(name, price, ntiles);
        this.code = code;
    }

    public String getCode() {
        return this.code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    @Override
    public String getTileInfo() {
        return super.getTileInfo() +
               "\nDecoration Code: " + this.code;
    }
}
