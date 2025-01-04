import java.util.Scanner;

public class App {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    
    System.out.println("How many hours will you park here for?");
    System.out.println("You can only park 1 to 20 hours");
    int h = 0;
    do {
      h = scanner.nextInt();
    } while (h < 1 || h > 20);
    scanner.close();

    System.out.println("Your total is: " + (1.5 + (h-1) * 2.5) );
  }
}
