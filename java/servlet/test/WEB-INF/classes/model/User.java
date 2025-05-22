package model;

import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.Random;

public class User {
  private String id;
  private String name;
  private String surname;
  private String username;
  private String password;
  private ArrayList<Grade> grades = new ArrayList<>();

  public User(String name, String surname, String username, String password) {
    this.id = genID();
    this.name = name;
    this.surname = surname;
    this.username = username;
    this.password = genEncryptedPassword(password);
  }

  public User(String id, String name, String surname, String username, String password) {
    this(name, surname, username, password);
    this.id = id;
  }

  public String genID() {
    Random rand = new Random();
    return "usr." + User.genEncryptedPassword(this.toString()) + "." + "abcdef".charAt(rand.nextInt(5)) + rand.nextInt(9);
  }

  public String getID() { return id; }

  public String getName() { return name; }
  public void setName(String name) { this.name = name; }

  public String getSurname() { return surname; }
  public void setSurname(String surname) { this.surname = surname; }

  public String getUsername() { return username; }
  public void setUsername(String username) { this.username = username; }

  public String getPassword() { return password; }
  public void setPassword(String password) { this.password = genEncryptedPassword(password); }

  public ArrayList<Grade> getGrades(boolean fetch) { 
    if ( fetch )
      grades = DBConnection.getGrades(id);

    System.out.println("Grades: " + grades);
    return grades;
  }

  public boolean addGrade(Grade grade) {
    if ( grades.size() < 10 ) {
      grades.add( grade );
      return true;
    }

    return false;
  }

  public double getGradeAvg() { return gradeAvg(); }

  private double gradeAvg() {
    int sum = 0;
    int c = 0;
    for (Grade grade : grades) {
      if (grade.getMark() > 0) {
        sum += grade.getMark();
        c++;
      }
    }
    return (c > 0) ? (double) sum / c : 0;
  }

  public static String genEncryptedPassword(String input) {
    try {
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        byte[] hashBytes = digest.digest(input.getBytes("UTF-8"));

        StringBuilder hexString = new StringBuilder();
        for (byte b : hashBytes) {
            hexString.append(String.format("%02x", b));
        }

        return hexString.toString().substring(0, 32);
    } catch (Exception e) {
        throw new RuntimeException(e);
    }
  }
}
