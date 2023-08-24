import java.util.Scanner;

class BankAccount {
    String depositorName;
    long accountNumber;
    String accountType;
    double balance;
    static double rateOfInterest = 4.5; // Example static rate of interest

    public BankAccount() {
        depositorName = "Default Name";
        accountNumber = 0;
        accountType = "Savings";
        balance = 0.0;
    }

    public BankAccount(String name, long accNumber, String accType, double initialBalance) {
        depositorName = name;
        accountNumber = accNumber;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Amount deposited successfully.");
        } else {
            System.out.println("Invalid amount. Deposit failed.");
        }
    }

    void withdraw(double amount) {
        if (balance - amount >= 1000) {
            balance -= amount;
            System.out.println("Amount withdrawn successfully.");
        } else {
            System.out.println("Insufficient balance. Withdrawal failed.");
        }
    }

    void displayDetails() {
        System.out.println("Account Holder: " + depositorName);
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Account Type: " + accountType);
        System.out.println("Balance: " + balance);
    }

    static void displayRateOfInterest() {
        System.out.println("Rate of Interest: " + rateOfInterest + "%");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Welcome to the Bank Account Management System!");

        System.out.println("Do you want to enter account details? (Y/N): ");
        String input = scanner.nextLine();
        BankAccount account;

        if (input.equalsIgnoreCase("Y")) {
            System.out.print("Enter name of depositor: ");
            String name = scanner.nextLine();
            System.out.print("Enter account number: ");
            long accNumber = scanner.nextLong();
            scanner.nextLine();
            System.out.print("Enter account type: ");
            String accType = scanner.nextLine();
            System.out.print("Enter initial balance: ");
            double initialBalance = scanner.nextDouble();
            account = new BankAccount(name, accNumber, accType, initialBalance);
        } else {
            account = new BankAccount();
        }

        int choice;
        do {
            System.out.println("\nBank Account Management System");
            System.out.println("1. Deposit Amount");
            System.out.println("2. Withdraw Amount");
            System.out.println("3. Display Account Details");
            System.out.println("4. Display Rate of Interest");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter amount to deposit: ");
                    double depositAmount = scanner.nextDouble();
                    account.deposit(depositAmount);
                    break;
                case 2:
                    System.out.print("Enter amount to withdraw: ");
                    double withdrawAmount = scanner.nextDouble();
                    account.withdraw(withdrawAmount);
                    break;
                case 3:
                    account.displayDetails();
                    break;
                case 4:
                    BankAccount.displayRateOfInterest();
                    break;
                case 5:
                    System.out.println("Exiting the system. Thank you!");
                    break;
                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        } while (choice != 5);

        scanner.close();
    }
}
