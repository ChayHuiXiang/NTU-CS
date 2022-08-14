package SC2002.Tut_2_Classes_Objects;

import java.util.Random;

public class Dice {
  private int valueOfDice;
  public Dice() {
    setDiceValue();
  }
  public void setDiceValue() {
    Random random = new Random();
    this.valueOfDice = random.nextInt(5) + 1;
  }
  public int getDiceValue() {
    return this.valueOfDice;
  }
  public void printDiceValue() {
    System.out.print(getDiceValue());
  }
}
