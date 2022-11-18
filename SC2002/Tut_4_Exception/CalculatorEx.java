package SC2002.Tut_4_Exception;

import java.util.Scanner;

public class CalculatorEx {
  private double result;
  public CalculatorEx() {
    result = 0;
  }

  public double resultValue() {
    return result;
  }

  public double evaluate(char op, double n1, double n2) {
    switch (op) {
      case '+':
        return n1 + n2;

      case '-':
        return n1 - n2;

      case '*':
        return n1 * n2;

      case '/':
        return n1 / n2;
    
      default:
        return 0;
    }
  }

  public double handleUnknownOpException(UnknownOperatorException e, Scanner sc) {
    System.out.println(e.getMessage());
    System.out.println("Please reenter: ");
    char op = sc.next().charAt(0);
    int n2 = sc.nextInt();
    double updatedResult = evaluate(op, result, n2);
    System.out.println("result " + op + " " + n2 + " = " + updatedResult);
    return updatedResult;
  }

  public void doCalculation() {
    Scanner sc = new Scanner(System.in);
    while (true) {
      char op = sc.next().charAt(0);
      double updatedResult;
      double n2;
      try {
        if (op == 'q' || op == 'Q') {
          break;
        } else if (op != '+' && op != '-' && op != '*' && op != '/') {
          throw new UnknownOperatorException(op);
        }
        n2 = sc.nextInt();
        updatedResult = evaluate(op, result, n2);
        System.out.println("result " + op + " " + n2 + " = " + updatedResult);
      } catch (UnknownOperatorException e) {
        // TODO: handle exception
        updatedResult = handleUnknownOpException(e, sc);
      }
      System.out.println("updated result = " + updatedResult);
      result = updatedResult;
    }
    System.out.println("Final result = " + result);
    sc.close();
  }

  public static void main(String[] args) {
    System.out.println("Calculator is on");
    System.out.println("result = 0.0");
    CalculatorEx c = new CalculatorEx();
    c.doCalculation();
    System.out.println("End of program");
  }
}
