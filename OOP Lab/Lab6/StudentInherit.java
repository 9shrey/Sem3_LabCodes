import java.util.*;

class StudentInherit {
    String sname;
    int[] marks_array;

    public StudentInherit() {
        sname = "Default Student";
        marks_array = new int[0];
    }

    public StudentInherit(String name, int[] marks) {
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
    StudentInherit defaultStudent = new StudentInherit();
    System.out.println("Default Student Details:");
    defaultStudent.display();
    System.out.println("\nMarks Computation:");
    defaultStudent.compute();
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
    System.out.print("Enter practical marks for ScienceStudent: ");
    int practicalMarks = scanner.nextInt();
    scanner.nextLine();
    System.out.print("Enter elective subject for ArtsStudent: ");
    String electiveSubject = scanner.nextLine();
    scanner.close();
    StudentInherit student = new StudentInherit(name, marks);
    System.out.println("\nStudent Details:");
    student.display();
    System.out.println("\nMarks Computation:");
    student.compute();
    ScienceStudent scienceStudent = new ScienceStudent(name, marks, practicalMarks);
    System.out.println("\nScience Student Details:");
    scienceStudent.display();
    scienceStudent.displayPracticalMarks();
    System.out.println("\nMarks Computation for Science Student:");
    scienceStudent.compute();
    ArtsStudent artsStudent = new ArtsStudent(name, marks, electiveSubject);
    System.out.println("\nArts Student Details:");
    artsStudent.display();
    System.out.println("Elective Subject: " + artsStudent.getElectiveSubject());
    System.out.println("\nMarks Computation for Arts Student:");
    artsStudent.compute();
}
}

class ScienceStudent extends StudentInherit {
    private int practicalMarks;

    public ScienceStudent(String name, int[] marks, int practicalMarks) {
        super(name, marks);
        this.practicalMarks = practicalMarks;
    }
    void compute() {
        int total = 0;
        for (int mark : marks_array) {
            total += mark;
        }
        total += practicalMarks;
        double average = (double) total / (marks_array.length + 1); 
        System.out.println("Total Marks (including Practical): " + total);
        System.out.println("Average Marks (including Practical): " + average);
    }

    void displayPracticalMarks() {
        System.out.println("Practical Marks: " + practicalMarks);
    }
}

class ArtsStudent extends StudentInherit {
    private String electiveSubject;

    public ArtsStudent(String name, int[] marks, String electiveSubject) {
        super(name, marks);
        this.electiveSubject = electiveSubject;
    }

    public String getElectiveSubject() {
        return electiveSubject;
    }
}
