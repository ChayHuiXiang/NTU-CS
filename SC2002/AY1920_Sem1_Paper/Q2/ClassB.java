package SC2002.AY1920_Sem1_Paper.Q2;

public abstract class ClassB extends ClassA {
  public abstract void transmit(int i, int j, int k);
  public void transmit(int i, int j) {
    System.out.println("In B: " + i + " " + j);
  }
  public abstract void transmit(String s, int i);
}
