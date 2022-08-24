// package SC2002.Lab_1;

import java.util.Scanner;
public class P3 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("starting: ");
    int starting = sc.nextInt();
    
    System.out.print("ending: ");
    int ending = sc.nextInt();

    double conversionRate = 1.82;

    if (starting > ending) {
      System.out.println("Error input!!");
      sc.close();
      return;
    }

    System.out.print("increment: ");
    int increment = sc.nextInt();

    if ((ending-starting)%increment != 0) {
      System.out.println("Error input!!");
      sc.close();
      return;
    }

    System.out.println(
      """
      US$         S$
      --------------"""
    );

    for (int i = starting; i <= ending; i += increment) {
      System.out.println(i + "           " + i*conversionRate);
    }

    System.out.println(
      """
      US$         S$
      --------------"""
    );

    int i = 0;
    while (i <= ending) {
      System.out.println(i + "           " + i*conversionRate);
      i += increment;
    }

    System.out.println(
      """
      US$         S$
      --------------"""
    );

    i = 0;
    do {
      System.out.println(i + "           " + i*conversionRate);
      i += increment;
    } while (i <= ending);

    sc.close();
  }
}
