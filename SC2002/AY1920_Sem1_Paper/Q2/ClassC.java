package SC2002.AY1920_Sem1_Paper.Q2;

public class ClassC extends ClassA implements InterfaceA {
  public void transmit(String s, int i) {
    System.out.println("In C: " + s + " " + i);
  }
  public void transmit(String s) {
    System.out.println("In C: " + s);
  }
  public void transmit(int i, int j) {
    System.out.println("In C: " + i + " " + j);
  }
}
