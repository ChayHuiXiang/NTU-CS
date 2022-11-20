package SC2002.AY1920_Sem1_Paper.Q2;

public abstract class ClassA {
  public abstract void transmit(int i, int j);
  public void transmit(int i, String s) {
    System.out.println("In A: " + i + " " + s);
  }
}
