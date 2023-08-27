class StudentOne {
    private String name;

    public StudentOne(String name) {
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

    public static void findNamesWithSubstring(StudentOne[] students, String substring) {
        System.out.println("Names containing '" + substring + "':");
        for (StudentOne student : students) {
            if (student.name.contains(substring)) {
                System.out.println(student.name);
            }
        }
    }

    public static void sortStudentsAlphabetically(StudentOne[] students) {
        for (int i = 0; i < students.length - 1; i++) {
            for (int j = i + 1; j < students.length; j++) {
                if (students[i].name.compareToIgnoreCase(students[j].name) > 0) {
                    StudentOne temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        StudentOne[] students = new StudentOne[4];
        students[0] = new StudentOne("John Doe");
        students[1] = new StudentOne("Jane Smith");
        students[2] = new StudentOne("Alice Johnson");
        students[3] = new StudentOne("Robert Brown");

        System.out.println("Initials: " + students[0].extractInitials());
        System.out.println("Without Whitespace: " + students[1].removeWhitespace());

        String substring = "John";
        findNamesWithSubstring(students, substring);

        sortStudentsAlphabetically(students);
        System.out.println("Sorted Student Names:");
        for (StudentOne student : students) {
            System.out.println(student.name);
        }
    }
}
