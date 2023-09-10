import java.util.*;
public class EmpMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of Employees: ");
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        Employee[] Employees = new Employee[N];
        for (int i = 0; i < N; i++) {
            System.out.println("Enter details for Employee " + (i + 1));
            System.out.print("Enter Employee Name: ");
            String name = scanner.nextLine();
            System.out.print("Enter Employee ID: ");
            int id = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            System.out.println("Is this Employee Full-Time or Part-Time? (F/P): ");
            char EmployeeType = scanner.nextLine().charAt(0);

            if (EmployeeType == 'F' || EmployeeType == 'f') {
                System.out.print("Enter Basic Salary: ");
                double basic = scanner.nextDouble();
                System.out.print("Enter Bonus: ");
                double bonus = scanner.nextDouble();
                System.out.print("Enter Deductions: ");
                double deductions = scanner.nextDouble();
                Employees[i] = new FullTimeEmp(name, id, basic, bonus, deductions);
            } else if (EmployeeType == 'P' || EmployeeType == 'p') {
                System.out.print("Enter Hours Worked: ");
                int hoursWorked = scanner.nextInt();
                Employees[i] = new PartTimeEmp(name, id, hoursWorked);
            } else {
                System.out.println("Invalid input. Please enter 'F' for Full-Time or 'P' for Part-Time.");
                i--;
            }

            scanner.nextLine(); // Consume the newline character
        }
        scanner.close();

        System.out.println("Employee Details and Net Salaries:");
        for (Employee Employee : Employees) {
            Employee.compute_net_sal();
            Employee.display();
        }
    }
}
