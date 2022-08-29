package SC2002.Lab_3;

public class Main {
  public static void main(String[] args) {
    Plane plane = new Plane();
    plane.assignSeat(5, 10);
    plane.assignSeat(1, 4);
    plane.assignSeat(3,2);
    plane.showAssignedSeats(false);
    plane.showAssignedSeats(true);
  }
}
