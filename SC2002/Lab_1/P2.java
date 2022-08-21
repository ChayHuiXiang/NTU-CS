package SC2002.Lab_1;

import java.util.Scanner;

public class P2 {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter company's salary: ");
    int salary = sc.nextInt();

    System.out.println("Enter merit: ");
    int merit = sc.nextInt();
    String a = "Grade A";
    String b = "Grade B";
    String c = "Grade C";

    if (salary <= 649) {
      if (merit >= 10 && salary >= 600) {
        System.out.println(b);
      } else {
        System.out.println(c);
      }
    } else if (salary <= 799) {
      if (merit >= 20) {
        System.out.println(a);
      } else {
        System.out.println(b);
      }
    } else {
      System.out.println(a);
    }
    
    sc.close();
  }
}
