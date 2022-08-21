package SC2002.Lab_1;
import java.util.Scanner;

public class P1 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    char choice = sc.next().charAt(0);
    String a = "Action movie fan";
    String c = "Comedy movie fan";
    String d = "Drama movie fan";

    switch (choice) {
      case 'a':
        System.out.println(a);
        break;
      
      case 'A':
        System.out.println(a);
        break;

      case 'c':
        System.out.println(c);
        break;

      case 'C':
        System.out.println(c);
        break;

      case 'd':
        System.out.println(d);
        break;

      case 'D':
        System.out.println(d);
        break;

      default:
        System.out.println("Invalid choice\n");
        break;
    }
    sc.close();

  }
}
