package SC2002.AY1920_Sem1_Paper.Q2;

public class Test {
  public static void main(String[] args) {
    InterfaceA a = new ClassC();
    a.transmit("1", 2);
    ClassC c = (ClassC) a;
    ClassA b = c;
    b.transmit(1, 2);

    ClassD d = new ClassD();
    d.transmit(0, "D");
  }
}
