package SC2002.Tut_3_Class_Methods_Inheritance;

import java.util.Scanner;

public class VendingMachine {
  String vendingDisplay = """
    ====== Vending Machine ======
    |1. Buy Beer ($3.00) |
    |2. Buy Coke ($1.00) |
    |3. Buy Green Tea ($5.00) |
    |============================
      """;

  String coinDisplay = """
    Please insert coins: 
    ========== Coins Input ===========
    |Enter 'Q' for ten cents input |
    |Enter 'T' for twenty cents input|
    |Enter 'F' for fifty cents input |
    |Enter 'N' for a dollar input |
    ==================================
      """;

    static Scanner sc;
  // constructor
  public VendingMachine() {
    System.out.print(vendingDisplay);
  }
  // get the drink selection, and return the cost of the drink
  public double selectDrink() {
    System.out.println("Please enter selection:");
    while (true) {
      sc = new Scanner(System.in);
      int choice = sc.nextInt();
      switch (choice) {
        case 1:
          return 3;
  
        case 2:
          return 2;
  
        case 3:
          return 5;
      
        default:
          System.out.println("Invalid Selection!");
          break;
      }
    }
  }
  // insert the coins and returns the amount inserted
  public void insertCoins(double drinkCost) {
    System.out.println(coinDisplay);
    double coinsInserted = 0;
    while (coinsInserted < drinkCost) {
      char coinInput = sc.next().charAt(0);
      switch (coinInput) {
        case 'Q':
          coinsInserted += 0.1;
          break;
        
        case 'T':
          coinsInserted += 0.2;
          break;

        case 'F':
          coinsInserted += 0.5;
          break;

        case 'N':
          coinsInserted += 1;
          break;

        default:
          System.out.println("Invalid Coin!");
          break;
      }
      System.out.println("Coins inserted: " + coinsInserted);
    }
    checkChange(coinsInserted, drinkCost);
    sc.close();
  }
  // check the change and print the change on screen
  public void checkChange(double amount, double drinkCost) {
    double change = amount - drinkCost;
    System.out.println("Change: $ " + change);
  }
  // print the receipt and collect the drink
  public void printReceipt(){
    System.out.println("Please collect your drink");
    System.out.println("Thank You !!");
  }

}
