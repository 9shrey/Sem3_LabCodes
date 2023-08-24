import java.util.Scanner;
class EMPLOYEE {
    String Ename;
    int Eid;
    double Basic,DA,gross_Sal,IT,net_sal;
    void read() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Employee Name: ");
        Ename = scanner.nextLine();
        System.out.print("Enter Employee ID: ");
        Eid = scanner.nextInt();
        System.out.print("Enter Basic Salary: ");
        Basic = scanner.nextDouble();
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
        System.out.print("Enter the number of employees: ");
        int N = scanner.nextInt();
        EMPLOYEE[] employees = new EMPLOYEE[N];
        for (int i = 0; i < N; i++) {
            employees[i] = new EMPLOYEE();
            System.out.println("Enter details for Employee " + (i + 1));
            employees[i].read();
            employees[i].compute_net_sal();
        }
        System.out.println("Employee Details and Net Salaries:");
        for (EMPLOYEE employee : employees) {
            employee.display();
        }
    }
}
