import java.util.*;

class person{
    private String name;
    private String dob;

    void setName(String name){
        this.name=name;
    }

    void setDob(String dob){
        this.dob=dob;
    }

    String getName(){
        return this.name;
    }

    String getDob(){
        return this.dob;
    }
}

class collegeGraduate extends person{
    private float GPA;
    private int graduationYear;

    void setGPA(float GPA){
        this.GPA=GPA;
    }

    void setGraduationYear(int graduationYear){
        this.graduationYear=graduationYear;
    }

    float getGPA(){
        return this.GPA;
    }

    int getGraduationYear(){
        return this.graduationYear;
    }

}

class q3{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        collegeGraduate clgGrad = new collegeGraduate();

        System.out.print("Enter Name: ");
        String name = sc.nextLine();
        clgGrad.setName(name);

        System.out.print("Enter DOB (DD/MM/YYYY): ");
        String dob = sc.nextLine();
        clgGrad.setDob(dob);

        System.out.print("Enter GPA: ");
        float GPA = sc.nextFloat();
        clgGrad.setGPA(GPA);

        System.out.print("Enter Graduation Year: ");
        int graduationYear = sc.nextInt();
        clgGrad.setGraduationYear(graduationYear);

        System.out.println("\nDisplaying Entered data: ");
        System.out.println("Name: " + clgGrad.getName());
        System.out.println("DOB: " + clgGrad.getDob());
        System.out.println("GPA: " + clgGrad.getGPA());
        System.out.println("Graduation Year: " + clgGrad.getGraduationYear());

        sc.close();
    }
}