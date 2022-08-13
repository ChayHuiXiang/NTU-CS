package SC2002.Tut_2_Classes_Objects;

import java.util.Scanner;

public class DiceApp {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.println("Press <key> to roll the first dice");
    sc.next();
    Dice dice1 = new Dice();
    int dice1Value = dice1.getDiceValue();
    System.out.println("Current Value is " + dice1Value);

    System.out.println("Press <key> to roll second dice");
    sc.next();
    Dice dice2 = new Dice();
    int dice2Value = dice2.getDiceValue();
    System.out.println("Current Value is " + dice2Value);

    System.out.println("Your total number is: " + (dice1Value + dice2Value));
  }
}
