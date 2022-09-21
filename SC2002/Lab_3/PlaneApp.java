import java.util.Scanner;

public class PlaneApp {

  static String menu = """
      (1) Show number of empty seats
      (2) Show the list of empty seats
      (3) Show the list of seat assignments by seat ID
      (4) Show the list of seat assignments by customer ID
      (5) Assign a customer to a seat
      (6) Remove a seat assignment
      (7) Exit
      """;
  public static void main(String[] args) {
    Plane plane = new Plane();
    int choice = 0;
    Scanner sc = new Scanner(System.in);
    System.out.println(menu);
    while (choice != 7) {
      System.out.print("Enter the number of your choice: ");
      choice = sc.nextInt();
      switch (choice) {
        case 1:
          plane.showNumEmptySeats();
          break;
        
        case 2:
          plane.showEmptySeats();
          break;
  
        case 3:
          plane.showAssignedSeats(true);
          break;
  
        case 4:
          plane.showAssignedSeats(false);
          break;
  
        case 5:
          System.out.println("Assigning Seat ..");
          System.out.print("Please enter SeatID: ");
          int seatId = sc.nextInt();
          System.out.print("Please enter CustomerID: ");
          int cust_id = sc.nextInt();
          plane.assignSeat(seatId, cust_id);
          break;
  
        case 6:
          System.out.print("Enter SeatID to unassign customer from: ");
          int seatID = sc.nextInt();
          plane.unAssignSeat(seatID);

        case 7:
          break;
      
        default:
          System.out.println(menu);
          break;
      }
      System.out.println();
    }
    sc.close();
  }
}
