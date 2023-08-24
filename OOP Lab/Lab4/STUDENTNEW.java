import java.util.*;

class STUDENTNEW {
    String sname;
    int[] marks_array;

    // Default constructor
    public STUDENTNEW() {
        sname = "Default Student";
        marks_array = new int[0];
    }

    // Parameterized constructor
    public STUDENTNEW(String name, int[] marks) {
        sname = name;
        marks_array = marks;
    }

    void display() {
        System.out.println("Student Name: " + sname);
        System.out.print("Marks: ");
        for (int mark : marks_array) {
            System.out.print(mark + " ");
        }
        System.out.println();
    }

    void compute() {
        int total = 0;
        for (int mark : marks_array) {
            total += mark;
        }
        double average = (double) total / marks_array.length;
        System.out.println("Total Marks: " + total);
        System.out.println("Average Marks: " + average);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Default constructor usage
        STUDENTNEW defaultStudent = new STUDENTNEW();
        System.out.println("Default Student Details:");
        defaultStudent.display();
        System.out.println("\nMarks Computation:");
        defaultStudent.compute();
        
        // Parameterized constructor usage
        System.out.print("\nEnter student name: ");
        String name = scanner.nextLine();
        System.out.print("Enter number of subjects: ");
        int numSubjects = scanner.nextInt();
        int[] marks = new int[numSubjects];
        System.out.println("Enter marks for each subject:");
        for (int i = 0; i < numSubjects; i++) {
            System.out.print("Subject " + (i + 1) + ": ");
            marks[i] = scanner.nextInt();
        }
        scanner.close();
        
        STUDENTNEW student = new STUDENTNEW(name, marks);
        System.out.println("\nStudent Details:");
        student.display();
        System.out.println("\nMarks Computation:");
        student.compute();
    }
}

