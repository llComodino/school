import java.security.MessageDigest;
import java.util.Random;

public class Utente {
  private String nome;
  private String cognome;
  private String username;
  private String password;
  private int[] voti = new int[10];

  public Utente(String nome, String cognome, String username, String password) {
    this.nome = nome;
    this.cognome = cognome;
    this.username = username;
    this.password = password;
  }

  public String genID() {
    Random rand = new Random();
    return "usr." + Utente.genEncryptedPassword(this.toString()) + "." + "abcdef".charAt(rand.nextInt(5)) + rand.nextInt(9);
  }

  public String getNome() {
    return nome;
  }

  public String getCognome() {
    return cognome;
  }

  public String getUsername() {
    return username;
  }

  public String getPassword() {
    return password;
  }

  public int[] getVoti() {
    return voti;
  }

  public void setVoto(int voto, int index) {
    if (index >= 0 && index < voti.length) {
      voti[index] = voto;
    }
  }

  public double getMedia() {
    return calcolaMedia();
  }

  private double calcolaMedia() {
    int somma = 0;
    int count = 0;
    for (int voto : voti) {
      if (voto > 0) {
        somma += voto;
        count++;
      }
    }
    return (count > 0) ? (double) somma / count : 0;
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
