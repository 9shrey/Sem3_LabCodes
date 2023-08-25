//Credits: Keshav added Default Call
import java.util.Scanner;

class EMPLOYEENEW {
    String Ename;
    int Eid;
    double Basic, DA, gross_Sal, IT, net_sal;

    // Default constructor
    public EMPLOYEENEW() {
        Ename = "Default Employee";
        Eid = 0;
        Basic = 0.0;
    }

    // Parameterized constructor
    public EMPLOYEENEW(String name, int id, double basic) {
        Ename = name;
        Eid = id;
        Basic = basic;
    }

    void compute_net_sal() {
        DA = 0.52 * Basic;
        gross_Sal = Basic + DA;
        IT = 0.3 * gross_Sal;
        net_sal = gross_Sal - IT;
    }

    void display() {
        System.out.println("Employee ID: " + Eid);
        System.out.println("Employee Name: " + Ename);
        System.out.println("Basic Salary: " + Basic);
        System.out.println("DA: " + DA);
        System.out.println("Gross Salary: " + gross_Sal);
        System.out.println("Income Tax: " + IT);
        System.out.println("Net Salary: " + net_sal);
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        EMPLOYEENEW defaultEmployee = new EMPLOYEENEW();
        System.out.println("Default Employee Details:");
        defaultEmployee.display();
        System.out.println("\nEid and Basic");
        defaultEmployee.compute_net_sal();
        
        System.out.print("Enter the number of employees: ");
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        EMPLOYEENEW[] employees = new EMPLOYEENEW[N];
        for (int i = 0; i < N; i++) {
            System.out.println("Enter details for Employee " + (i + 1));
            System.out.print("Enter Employee Name: ");
            String name = scanner.nextLine();
            System.out.print("Enter Employee ID: ");
            int id = scanner.nextInt();
            System.out.print("Enter Basic Salary: ");
            double basic = scanner.nextDouble();

            employees[i] = new EMPLOYEENEW(name, id, basic);
            employees[i].compute_net_sal();

            scanner.nextLine(); // Consume the newline character
        }
        scanner.close();

        System.out.println("Employee Details and Net Salaries:");
        for (EMPLOYEENEW employee : employees) {
            employee.display();
        }
    }
}
