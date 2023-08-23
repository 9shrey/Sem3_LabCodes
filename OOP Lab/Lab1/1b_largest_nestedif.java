import java.util.Scanner;
public class largest_nestedif{
public static int max(int x , int y , int z){
if(x>=y && x>=z) {
        return x;}
        else if (y>=x && y>=z){
            return y;}
            else {
                return z;
            }
}

public static void main(String[] args){
Scanner sc=new Scanner(System.in);
System.out.println("enter first number");
int x= sc.nextInt();
System.out.println("enter second number");
int y= sc.nextInt();
System.out.println("enter third number");
int z= sc.nextInt();

int max=max(x,y,z);
System.out.println("largest number is "+max);


}


}