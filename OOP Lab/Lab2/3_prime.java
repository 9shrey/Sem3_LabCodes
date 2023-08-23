import java.util.Scanner;
class prime {
 public static void main(String[] args) {
  Scanner sc=new Scanner(System.in);
  System.out.println("Enter number of digits: ");
  int n,i,c;  
  n=sc.nextInt(); 
  int a[]=new int[n];
  System.out.println("Enter the elements: ");
  for(i=0;i<n;i++){
    a[i]=sc.nextInt();}
  System.out.println("Prime numbers are: ");
  for(i=0; i<n; i++)
        {
        c=0;
        for(int j=1; j<=a[i]; j++)
        {
            if(a[i]%j==0)
            {
                c++;
            }
        }

            if(c==2)
            {
                System.out.print(a[i]+" ");
            }
        }     
  }
}
