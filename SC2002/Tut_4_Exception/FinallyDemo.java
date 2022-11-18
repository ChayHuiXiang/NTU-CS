package SC2002.Tut_4_Exception;


public class FinallyDemo {
  public static void main(String[] args) {
    try {
      sampleMethod(-99);
    }
    catch(Exception e) {
      System.out.println("Caught in main.");
    }
  }

  public static void sampleMethod(int n) throws Exception {
    try {
      if (n > 0)
        throw new Exception( );
      else if (n < 0)
        throw new NegativeNumberException( );
      else
        System.out.println("No Exception.");
      System.out.println("Still in sampleMethod.");
    } catch(NegativeNumberException e) {
      System.out.println("Caught in sampleMethod.");
    } finally {
      System.out.println("In finally block.");
    }
    System.out.println("After finally block.");
  }
}

// 99
// In finally block
// Caught in main

// -99
// Caught in sampleMethod
// In finally block
// After finally block

// 0
// No Exception
// In finally block
// After finally block
