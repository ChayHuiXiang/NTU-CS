package SC2002.Lab_1;

import java.util.Scanner;
public class P4 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the height of the pattern: ");
    int height = sc.nextInt();

    if (height <= 0) {
      System.out.println("Error input!!");
      sc.close();
      return;
    }

    String pattern = "";
    for (int i = 1; i <= height; i++) {
      if (i%2 == 1) {
        pattern = "AA" + pattern;
      } else {
        pattern = "BB" + pattern;
      }
      System.out.println(pattern);
    }
    sc.close();
  }
}
