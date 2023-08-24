import java.util.Scanner;
class foreachtype {
 public static void main(String[] args) {
  Scanner sc=new Scanner(System.in);
  System.out.println("Enter number of digits: ");
  int n,i;  
  n=sc.nextInt(); 
  int a[]=new int[n];
  System.out.println("Enter the elements: ");
  for(i=0;i<n;i++){
    a[i]=sc.nextInt();}
  System.out.println("Elements are: ");
  for(i=0;i<n;i++){
    System.out.println(a[i]);
  }      
  
}
}
