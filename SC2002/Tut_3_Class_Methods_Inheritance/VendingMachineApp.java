package SC2002.Tut_3_Class_Methods_Inheritance;

public class VendingMachineApp {
  public static void main(String[] args) {
    VendingMachine vendingMachine = new VendingMachine();
    double drinkCost = vendingMachine.selectDrink();
    vendingMachine.insertCoins(drinkCost);
    vendingMachine.printReceipt();
  }
}
