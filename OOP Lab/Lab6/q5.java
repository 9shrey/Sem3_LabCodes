import java.util.*;

abstract class Figure{
    private double dim1;
    private double dim2;

    void setDim1(double dim1){
        this.dim1=dim1;
    }

    void setDim2(double dim2){
        this.dim2=dim2;
    }

    double getDim1() {
        return dim1;
    }

    double getDim2() {
        return dim2;
    }

    abstract double calcArea();
}

class Rectangle extends Figure{
    double calcArea(){
        return getDim1()*getDim2();
    }
}

class Triangle extends Figure{
    double calcArea(){
        return 0.5*getDim1()*getDim2();
    }
}

class Square extends Figure{
    double calcArea(){
        return getDim1()*getDim2();
    }
}

class q5{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Select any option: ");
        System.out.println("1. Rectangle");
        System.out.println("2. Triangle");
        System.out.println("3. Square");
        System.out.print("Option: ");
        int choice = sc.nextInt();

        System.out.print("Dimension 1: ");
        double dim1 = sc.nextDouble();
        System.out.print("Dimension 2: ");
        double dim2 = sc.nextDouble();

        if(choice==1){
            Rectangle obj = new Rectangle();
            obj.setDim1(dim1);
            obj.setDim2(dim2);
            System.out.println("Area: " + obj.calcArea());
        }
        else if(choice==2){
            Triangle obj = new Triangle();
            obj.setDim1(dim1);
            obj.setDim2(dim2);
            System.out.println("Area: " + obj.calcArea());
        }
        else if(choice==3){
            if(dim1!=dim2) System.out.println("Not a Square!!");
            else{
                Square obj = new Square();
                obj.setDim1(dim1);
                obj.setDim2(dim2);
                System.out.println("Area: " + obj.calcArea());
            }
            
        }

        sc.close();
    }
}