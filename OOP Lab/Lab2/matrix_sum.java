import java.util.Scanner;
class matrix_sum {
 public static void main(String[] args) {
  Scanner sc=new Scanner(System.in);
  System.out.println("Enter dimensions mxn: ");
  int n,m,i;
  System.out.println("Enter m: ");
  m=sc.nextInt(); 
  System.out.println("Enter n: ");
  n=sc.nextInt(); 
  int a[][]=new int[m][n];
  int b[][]=new int[m][n];
  System.out.println("Enter the elements of matrix 1: ");
  for(i=0;i<m;i++){
    for(int j=0;j<n;j++){
        a[i][j]=sc.nextInt();}}
  System.out.println("Enter the elements of matrix 2: ");
  for(i=0;i<m;i  ++){
    for(int j=0;j<n;j++){
        b[i][j]=sc.nextInt();}}
  System.out.println("addition matrix: ");
  for(i=0;i<m;i++){
    for(int j=0;j<n;j++){
        System.out.print(a[i][j]+b[i][j]);
        System.out.print("\t");
  }          
  System.out.print("\n");
}
}
}
