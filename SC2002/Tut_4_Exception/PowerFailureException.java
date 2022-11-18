package SC2002.Tut_4_Exception;

public class PowerFailureException extends Exception {
  public PowerFailureException() {
    super("Power Failure!");
  }

  public PowerFailureException(String m) {
    super(m);
  }
}
