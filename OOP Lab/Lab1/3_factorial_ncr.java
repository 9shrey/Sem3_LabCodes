import java.util.Scanner;

class factorial_ncr {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter f:");
    int f=sc.nextInt();
    int fac=fact(f);
    System.out.println("Factorial is "+fac);
    System.out.println("for nCr enter n:");
    int n=sc.nextInt();
    System.out.println("enter r: ");
    int r=sc.nextInt();
    int C=fact(n)/(fact(n-r)*fact(r));
    System.out.println("nCr is "+C);
  }
  public static int fact(int n){
    int product=1;
    while(n!=0)
      {
        product*=n;
        n--;
      }
    return product;
  }
}