package SC2002.Tut_1_OO_Concepts_Basic_Java;

import java.util.Scanner;

class Three {

  public static void bubble(int[] a, int n) {
    int i, j, t;
    for (i = n - 2; i >= 0; i--) {
      for (j = 0; j <= i; j++) {
        if (a[j] > a[j + 1]) {
          t = a[j];
          a[j] = a[j + 1];
          a[j + 1] = t;
        }
      }
    }
  } // end function.

  public static void main(String[] args) {
    int[] a = new int[100];
    int n;
    int i;
    Scanner sc = new Scanner(System.in);
    System.out.println("\n\n Enter number of Integer elements to be sorted: ");
    n = sc.nextInt();

    for (i = 0; i <= n - 1; i++) {
      System.out.println("\n\n Enter integer value for element no." + (i + 1) + ": ");
      a[i] = sc.nextInt();
    }

    bubble(a, n);

    System.out.println("\n\n Finally sorted array is: ");
    for (i = 0; i <= n - 1; i++) {
      System.out.print(a[i]);
    }
  }
}
