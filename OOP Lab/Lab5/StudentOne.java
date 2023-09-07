import java.util.Scanner;

public class Stud1 {
    private String name;

    public Stud1(String name) {
        this.name = name;
    }

    public String extractInitials() {
        String[] words = name.split(" ");
        StringBuilder initials = new StringBuilder();

        for (String word : words) {
            if (!word.isEmpty()) {
                initials.append(Character.toUpperCase(word.charAt(0)));
            }
        }

        return initials.toString();
    }

    public String removeWhitespace() {
        return name.replaceAll("\\s", "");
    }

    public static void findNamesWithSubstring(Stud1[] students, String substring) {
        System.out.println("Names containing '" + substring + "':");
        for (Stud1 student : students) {
            if (student.name.contains(substring)) {
                System.out.println(student.name);
            }
        }
    }

    public static void sortStudentsAlphabetically(Stud1[] students) {
        for (int i = 0; i < students.length - 1; i++) {
            for (int j = i + 1; j < students.length; j++) {
                if (students[i].name.compareToIgnoreCase(students[j].name) > 0) {
                    Stud1 temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int numStudents = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        Stud1[] students = new Stud1[numStudents];

        for (int i = 0; i < numStudents; i++) {
            System.out.print("Enter name for student " + (i + 1) + ": ");
            String name = scanner.nextLine();
            students[i] = new Stud1(name);
        }

        System.out.println("Initials and Names without Whitespace:");
        for (Stud1 student : students) {
            String initials = student.extractInitials();
            String nameWithoutWhitespace = student.removeWhitespace();

            System.out.println("Name: " + student.name);
            System.out.println("Initials: " + initials);
            System.out.println("Without Whitespace: " + nameWithoutWhitespace);
            System.out.println();
        }

        System.out.print("Enter a substring to search for in names: ");
        String substring = scanner.nextLine();
        findNamesWithSubstring(students, substring);

        sortStudentsAlphabetically(students);
        System.out.println("Sorted Student Names:");
        for (Stud1 student : students) {
            System.out.println(student.name);
        }

        scanner.close();
    }
}
