public class MyEmployee {
    private int empId;
    private String firstName;
    private String lastName;

    public MyEmployee(int empId, String firstName, String lastName) {
        this.empId = empId;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public String formatEmployeeName() {
        String formattedFirstName = capitalizeEachWord(firstName);
        String formattedLastName = capitalizeEachWord(lastName);
        return formattedFirstName + " " + formattedLastName;
    }

    public String generateEmail() {
        String email = firstName.toLowerCase().charAt(0) + lastName.toLowerCase() + "@example.com";
        return email;
    }

    private String capitalizeEachWord(String input) {
        String[] words = input.toLowerCase().split(" ");
        StringBuilder result = new StringBuilder();

        for (String word : words) {
            if (!word.isEmpty()) {
                result.append(Character.toUpperCase(word.charAt(0))).append(word.substring(1)).append(" ");
            }
        }

        return result.toString().trim();
    }

    public static void main(String[] args) {
        int empId = 1;
        String firstName = "JOHN";
        String lastName = "DOE";
        MyEmployee employee = new MyEmployee(empId, firstName, lastName);

        String formattedName = employee.formatEmployeeName();
        String email = employee.generateEmail();

        System.out.println("Formatted Name: " + formattedName);
        System.out.println("Generated Email: " + email);
    }
}