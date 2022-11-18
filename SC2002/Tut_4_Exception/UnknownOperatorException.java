package SC2002.Tut_4_Exception;

public class UnknownOperatorException extends Exception {
  public UnknownOperatorException() {
    super("Unknown Operator");
  }
  public UnknownOperatorException(char op) {
    super("Unknown operator: " + op);
  }
  public UnknownOperatorException(String message) {
    super(message);
  }
}
