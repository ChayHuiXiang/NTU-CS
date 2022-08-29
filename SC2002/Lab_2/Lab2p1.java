package SC2002.Lab_2;

import java.util.Scanner; 
import java.lang.Math; 
 
public class Lab2p1 { 
  static Scanner sc;
 public static void main(String[] args){ 
  int choice; 
  sc = new Scanner(System.in); 
  do { 
   System.out.println("Perform the following methods: "); 
   System.out.println("1: miltiplication test"); 
   System.out.println("2: quotient using division by subtraction"); 
   System.out.println("3: remainder using division by subtraction"); 
   System.out.println("4: count the number of digits"); 
   System.out.println("5: position of a digit"); 
   System.out.println("6: extract all odd digits"); 
   System.out.println("7: quit"); 
   choice = sc.nextInt(); 
   switch (choice) { 
    case 1: /* add mulTest() call */ 
      mulTest(); 
      break; 
    case 2: /* add divide() call */ 
     int divResult = divide(15, 5); 
     System.out.println(divResult); 
     break;  
    case 3: /* add modulus() call */ 
     int modResult = modulus(14, 6); 
     System.out.println(modResult); 
     break;  
    case 4: /* add countDigits() call */ 
     int digitResult = countDigits(12345); 
     System.out.println(digitResult); 
     break; 
    case 5: /* add position() call */ 
     int posResult = position(12145, 1); 
     System.out.println(posResult); 
     break;  
    case 6: /* add extractOddDigits() call */ 
     long oddResult = extractOddDigits(24); 
     System.out.println(oddResult); 
     break;  
   } 
  } while (choice < 7); 
   
  sc.close(); 
 } 
  
 public static void mulTest() { 
   
  int correctAns = 0; 
  for (int i = 0; i < 5; i++) { 
   int rand1 = (int)(Math.random() * 10); 
   int rand2 = (int)(Math.random() * 10); 
    
   int answer = rand1 * rand2; 
    
   System.out.println("How much is " + rand1 + " times " + rand2 + "?"); 
   int input = sc.nextInt(); 
   if (input == answer) { 
    correctAns++; 
   } 
  } 
   
  System.out.println(correctAns + " answers out of 5 are correct."); 
  return; 
 } 
  
 public static int divide(int m, int n) { 
  int subtractionCount = 0; 
  while (m != 0) { 
   m -= n; 
   subtractionCount++; 
  } 
  return subtractionCount; 
 } 
  
 public static int modulus(int m, int n) { 
  while (m >= n) { 
   m -= n; 
  } 
   
  return m; 
 } 
  
 public static int countDigits(int n) { 
  if (n < 0) { 
   System.out.println("Error: Negative Input Detected."); 
   return -1; 
  } 
   
  int digitCount = 0; 
  while (n != 0) { 
   n /= 10; 
   digitCount++; 
  } 
  return digitCount; 
 } 
  
 public static int position(int n, int digit) { 
   
  int index = 0; 
  while (n != 0) { 
   index++; 
   int number = n % 10; 
   if (number == digit) { 
    return index; 
   } 
   n /= 10; 
  } 
  return -1; 
 } 
  
 public static long extractOddDigits(long n) { 
  String number = ""; 
  while (n != 0) { 
   long digit = n % 10; 
   if (digit % 2 == 1) { 
    String numberChar = Long.toString(digit); 
    number = numberChar + number; 
   } 
   n /= 10; 
  } 
     
  if (number == "") { 
   return -1; 
  } else { 
   return Long.valueOf(number); 
  } 
 } 
}
