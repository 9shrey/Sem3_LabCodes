import java.util.*;
class mixer{
    int arr[];

    void accept(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter size: ");
        int n= sc.nextInt();
        this.arr = new int[n];
        System.out.println("Enter array items: ");
        for(int i=0; i<n; i++){
            int element=sc.nextInt();
            if(i>0){
                if(element<this.arr[i-1]){
                    System.out.println("Enter elements in ascending order!");
                    --i;
                }
                else this.arr[i]=element;
            }
            else this.arr[0]=element;
        }
    }

    mixer mix(mixer m2){
        mixer ans = new mixer();
        ans.arr = new int[this.arr.length + m2.arr.length];
        int i=0, j=0, k=0;
        while(i<this.arr.length && j<m2.arr.length){
            if(this.arr[i]<m2.arr[j]){
                ans.arr[k++]=this.arr[i++];
            }
            else if(this.arr[i]>m2.arr[j]){
                ans.arr[k++]=m2.arr[j++];
            }
            else if(this.arr[i]==m2.arr[j]){
                ans.arr[k++]=m2.arr[j++];
                i++;
            }
            
        }
        while (i<this.arr.length){
            ans.arr[k++]=this.arr[i++];
        }
        while (j<m2.arr.length){
            ans.arr[k++]=m2.arr[j++];
        }

        mixer result = new mixer();
        result.arr = new int[k];

        for(int index=0; index<k; index++){
            result.arr[index]=ans.arr[index];
        }

        return result;
    }

    void display(){
        for(int i=0; i<this.arr.length; i++){
            System.out.print(this.arr[i] + " ");
        }
    }



    public static void main(String args[]){
        
        mixer m1 = new mixer();
        System.out.println("\nArray 1: ");
        m1.accept();

        mixer m2 = new mixer();
        System.out.println("\nArray 2: ");
        m2.accept();

        System.out.println("\nMixing both the arrays: ");
        mixer result = new mixer();
        result=m1.mix(m2);
        result.display();

}}
