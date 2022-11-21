package SC2002.Lab_3;

import java.util.Arrays;
import java.util.Comparator;

public class Plane {
  private PlaneSeat[] seat = new PlaneSeat[12];
  private int numEmptySeat = 12;

  public Plane() {
    for (int i = 0; i < seat.length; i++) {
      seat[i] = new PlaneSeat(i+1);
    }
  }

  public void assignSeat(int seatId, int cust_id) {
    for (int i = 0; i < seat.length; i++) {
      if (seat[i].getSeatId() == seatId) {
        if (seat[i].isOccupied()) {
          System.out.println("Seat already assigned to a customer.");
        } else {
          seat[i].assign(cust_id);
          numEmptySeat--;
        }
      }
    }
  }

  public void unAssignSeat(int seatId) {
    for (int i = 0; i < seat.length; i++) {
      if (seat[i].getSeatId() == seatId) {
        seat[i].unAssign();
        numEmptySeat++;
      }
    }
  }

  public void showNumEmptySeats() {
    System.out.printf("There are %d empty seats\n", numEmptySeat);
  }

  public void showEmptySeats() {
    System.out.println("The following seats are empty:");
    for (int i = 0; i < this.seat.length; i++) {
      if (!this.seat[i].isOccupied()) {
        System.out.println("SeatID " + seat[i].getSeatId());
      }
    }
  }

  public void showAssignedSeats(boolean bySeatId) {

    PlaneSeat[] targetSeat = bySeatId ? seat : sortSeats();

    System.out.println("The seat assignments are as follow:");
    for (int i = 0; i < targetSeat.length; i++) {
      if (targetSeat[i].isOccupied()) {
        System.out.println("SeatID " + targetSeat[i].getSeatId() + " assigned to CustomerID " + targetSeat[i].getCustomerId() + ".");
      }
    }
  }

  public PlaneSeat[] sortSeats() {
    PlaneSeat[] clonedSeats = new PlaneSeat[12];
    for (int i = 0; i < clonedSeats.length; i++) {
      clonedSeats[i] = this.seat[i];
    }
    Arrays.sort(clonedSeats, new Comparator<PlaneSeat>() {
      @Override
      public int compare(PlaneSeat seat1, PlaneSeat seat2) {
        return seat1.getCustomerId() - seat2.getCustomerId();
      }
    });
    return clonedSeats;
  }
}
