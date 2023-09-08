import java.util.Scanner;

class Employee {
    String Ename;
    int Eid;
    double Basic, DA, gross_Sal, IT, net_sal;

    // Default constructor
    public Employee() {
        Ename = "Default Employee";
        Eid = 0;
        Basic = 0.0;
    }

    // Parameterized constructor
    public Employee(String name, int id, double basic) {
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
    }
}

class FullTimeEmp extends Employee {
    double bonus, deductions;

    public FullTimeEmp(String name, int id, double basic, double bonus, double deductions) {
        super(name, id, basic);
        this.bonus = bonus;
        this.deductions = deductions;
    }


    void compute_net_sal() {
        DA = 0.52 * Basic;
        gross_Sal = Basic + DA + bonus - deductions;
        IT = 0.3 * gross_Sal;
        net_sal = gross_Sal - IT;
    }


    void display() {
        super.display();
        System.out.println("Bonus: " + bonus);
        System.out.println("Deductions: " + deductions);
    }
}

class PartTimeEmp extends Employee {
    int hoursWorked;
    static final double hourlyRate = 10.0; // Adjust the hourly rate as needed

    public PartTimeEmp(String name, int id, int hoursWorked) {
        super(name, id, 0); // Part-time Employees have zero basic salary
        this.hoursWorked = hoursWorked;
    }


    void compute_net_sal() {
        Basic = hoursWorked * hourlyRate;
        DA = 0.52 * Basic;
        gross_Sal = Basic + DA;
        IT = 0.3 * gross_Sal;
        net_sal = gross_Sal - IT;
    }


    void display() {
        super.display();
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Hourly Rate: " + hourlyRate);
    }
}

