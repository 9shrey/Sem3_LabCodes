import java.util.Scanner;

public class reverse_palindrome {
  public static int rev(int n) {
    int rem = 0, r = 0;
    while (n > 0) {
      rem = n % 10;
      r = r * 10 + rem;
      n = n / 10;

    }
    return r;
  }
 
  public static void main(String[] args) {
    System.out.print("Enter n to reverse: ");
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int reverse = rev(n);
    System.out.println(reverse);
    System.out.print("Enter x to check if Palindrome: ");
    int x= sc.nextInt();
    int y=rev(x);
    if(y==x)
      System.out.println("It is palindrome");
    else
      System.out.println("It is not palindrome");
  }
}