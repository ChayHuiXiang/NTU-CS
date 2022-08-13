package SC2002.Tut_2_Classes_Objects;

import java.util.*;

public class CircleApp {
  public static void main(String[] args) {
    Circle circle = new Circle(0);
    Scanner sc = new Scanner(System.in);
    int choice = 1;
    loop: while (choice >= 1 && choice <= 3) {
      String menu = """
        ==== Circle Computation =====
        |1. Create a new circle |
        |2. Print Area |
        |3. Print circumference |
        |4. Quit |
        =============================
        Choose option (1-3):
        """;
      System.out.println(menu);
      choice = sc.nextInt();
      switch (choice) {
        case 1:
          System.out.println("Enter the radius to compute the area and circumference");
          int radius = sc.nextInt();
          circle = new Circle(radius);
          System.out.println("A new circle is created");
          break;
        
        case 2:
          System.out.println("Area of circle");
          System.out.println("Radius: " + circle.getRadius());
          System.out.println("Area: " + circle.area());
          break;
        
        case 3: 
          System.out.println("Circumference of circle");
          System.out.println("Radius: " + circle.getRadius());
          System.out.println("Area: " + circle.circumference());
          break;
        
        default:
          System.out.println("Thank you!!");
          break loop;
      }
    }
  }
}
