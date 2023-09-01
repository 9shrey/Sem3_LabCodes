import java.text.SimpleDateFormat;
import java.util.*;

class Student{
    private static int registrationCounter = 0;

    private int registrationNumber;
    private String fullName;
    private Date dateOfJoining;
    private short semester;
    private float gpa;
    private float cgpa;

    public Student(String fullName, Date dateOfJoining, short semester, float gpa, float cgpa) {
        registrationCounter++;
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(dateOfJoining);
        int yearOfJoining = calendar.get(Calendar.YEAR);
        this.registrationNumber = yearOfJoining * 100 + registrationCounter;
        this.fullName = fullName;
        this.dateOfJoining = dateOfJoining;
        this.semester = semester;
        this.gpa = gpa;
        this.cgpa = cgpa;
    }

    public void display() {
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        System.out.println("Registration Number: " + registrationNumber);
        System.out.println("Full Name: " + fullName);
        System.out.println("Date of Joining: " + dateFormat.format(dateOfJoining));
        System.out.println("Semester: " + semester);
        System.out.println("GPA: " + gpa);
        System.out.println("CGPA: " + cgpa);
        System.out.println();
    }

    public static void sortByName(List<Student> students) {
        students.sort(Comparator.comparing(Student::getFullName));
    }

    public static void sortBySemesterAndCGPA(List<Student> students) {
        students.sort(Comparator.comparing(Student::getSemester).thenComparing(Student::getCgpa).reversed());
    }

    public static List<Student> filterByStartingLetter(List<Student> students, char startingLetter) {
        List<Student> filteredStudents = new ArrayList<>();
        for (Student student : students) {
            if (student.getFullName().charAt(0) == startingLetter) {
                filteredStudents.add(student);
            }
        }
        return filteredStudents;
    }

    public static List<Student> filterBySubstring(List<Student> students, String substring) {
        List<Student> filteredStudents = new ArrayList<>();
        for (Student student : students) {
            if (student.getFullName().contains(substring)) {
                filteredStudents.add(student);
            }
        }
        return filteredStudents;
    }

    public void changeNameToInitials() {
        String[] names = fullName.split(" ");
        StringBuilder initials = new StringBuilder();
        for (int i = 0; i < names.length - 1; i++) {
            initials.append(names[i].charAt(0)).append(". ");
        }
        initials.append(names[names.length - 1]);
        fullName = initials.toString();
    }

    public String getFullName() {
        return fullName;
    }

    public short getSemester() {
        return semester;
    }

    public float getCgpa() {
        return cgpa;
    }


 public static void main(String[] args) {
        List<Student> students = new ArrayList<>();

        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter Full Name: ");
            String fullName = scanner.nextLine();

            System.out.print("Enter Date of Joining (YYYY-MM-DD): ");
            String dateOfJoiningStr = scanner.nextLine();
            SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
            Date dateOfJoining = null;
            try {
                dateOfJoining = dateFormat.parse(dateOfJoiningStr);
            } catch (Exception e) {
                e.printStackTrace();
            }

            System.out.print("Enter Semester: ");
            short semester = scanner.nextShort();
            System.out.print("Enter GPA: ");
            float gpa = scanner.nextFloat();

            System.out.print("Enter CGPA: ");
            float cgpa = scanner.nextFloat();
            scanner.nextLine(); // Consume newline

            Student student = new Student(fullName, dateOfJoining, semester, gpa, cgpa);
            students.add(student);
        }
        System.out.println("\n--- Student Records ---");
        for (Student student : students) {
            student.display();
        }
        Student.sortBySemesterAndCGPA(students);
        System.out.println("\n--- Sorted by Semester and CGPA ---");
        for (Student student : students) {
            student.display();
        }

        Student.sortByName(students);
        System.out.println("\n--- Sorted by Name ---");
        for (Student student : students) {
            student.display();
        }
        System.out.print("Enter a starting letter to filter students: ");
        char startingLetter = scanner.nextLine().charAt(0);
        List<Student> filteredStudentsByLetter = Student.filterByStartingLetter(students, startingLetter);
        System.out.println("\n--- Students with Name Starting with '" + startingLetter + "' ---");
        for (Student student : filteredStudentsByLetter) {
            student.display();
        }
        System.out.print("Enter a substring to filter students: ");
        String substring = scanner.nextLine();
        List<Student> filteredStudentsBySubstring = Student.filterBySubstring(students, substring);
        System.out.println("\n--- Students with Name Containing '" + substring + "' ---");
        for (Student student : filteredStudentsBySubstring) {
            student.display();
        }
        for (Student student : students) {
            student.changeNameToInitials();
        }
        System.out.println("\n--- Names with Initials ---");
        for (Student student : students) {
            student.display();
        }
        scanner.close();
    }
}
