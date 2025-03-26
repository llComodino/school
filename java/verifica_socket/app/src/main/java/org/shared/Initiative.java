package org.shared;

public class Initiative {
  private int id;
  private String name;
  private float cost;

  public Initiative(int id, String name, float cost) {
    this.id = id;
    this.name = name;
    this.cost = cost;
  }

  public void setId(int id) {
    this.id = id;
  }

  public int getId() {
    return id;
  }

  public float getCost() {
    return cost;
  }

  public String getType() {
    return name;
  }

  public static Initiative fromString(String data) {
    String[] parts = data.split(",");
    int id = Integer.parseInt(parts[0].split(":")[1]);
    String name = parts[1].split(":")[1];
    float cost = Float.parseFloat(parts[2].split(":")[1].substring(0, parts[2].split(":")[1].length() - 1));
    return new Initiative(id, name, cost);
  }

  @Override
  public String toString() {
    return
      "{" +
      "\"id\":" + id + "," +
      "\"name\":\"" + name + "\"," +
      "\"cost\":" + cost +
      "}";
  }
}
