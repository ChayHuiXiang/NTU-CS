public class SalePerson implements Comparable<SalePerson> {
  private String firstName;
  private String lastName;
  private int totalSales;

  public SalePerson(String firstName, String lastName, int totalSales) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.totalSales = totalSales;
  }

  public String toString() {
    return lastName + "," + firstName + ":" + totalSales;
  }

  public boolean equals(SalePerson salePerson) {
    if (firstName == salePerson.firstName && lastName == salePerson.lastName) {
      return true;
    } else {
      return false;
    }
  }

  public int compareTo(SalePerson salePerson) {
    if (salePerson.totalSales == totalSales) {
      return lastName.compareTo(salePerson.lastName);
    } else {
      return totalSales > salePerson.totalSales ? 1 : -1;
    }
  }

  public String getFirstName() {
    return firstName;
  }

  public String getLastName() {
    return lastName;
  }

  public int getTotalSales() {
    return totalSales;
  }
}
