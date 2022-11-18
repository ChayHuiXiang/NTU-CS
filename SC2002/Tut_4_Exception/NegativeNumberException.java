package SC2002.Tut_4_Exception;

public class NegativeNumberException extends Exception {
  public NegativeNumberException() {
    super("Negative Number Exception!");
  }
  
  public NegativeNumberException(String message) {
    super(message);
  }
}
