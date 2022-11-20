package SC2002.misc;

class Grandparent {
  public void Print()
  {
      System.out.println("Grandparent's Print()");
  }
}

abstract class Parent extends Grandparent {
  public void Print(int fuck)
  {
      super.Print();
      System.out.println("Parent's Print()");
  }
  public void childPrint() {}
}

class Child extends Parent {
  public void Printd()
  {
      super.childPrint();
      System.out.println("Child's Print()");
  }
  public void childPrint() {
    System.out.println("Printing inside child");
  }
}

public class Main {
  public static void main(String[] args)
  {
      Child c = new Child();
      c.Printd();
  }
}
