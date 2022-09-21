public class PlaneSeat {
  private int seatId;
  private boolean assigned;
  private int customerId;

  public PlaneSeat(int seat_id) {
    this.seatId = seat_id;
  }

  public int getSeatId() {
    return this.seatId;
  }

  public int getCustomerId() {
    return this.customerId;
  }

  public boolean isOccupied() {
    return this.assigned;
  }

  public void assign(int cust_id) {
    customerId = cust_id;
    assigned = true;
    System.out.println("Seat Assigned!");
  }

  public void unAssign() {
    customerId = 0;
    assigned = false;
    System.out.println("Seat Unassigned!");
  }
}
