import java.util.Scanner;

class Stack {
    private int max_size;
    private int[] stack;
    private int tos;  // Top of stack

    public Stack(int max_size) {
        this.max_size = max_size;
        stack = new int[max_size];
        tos = -1;  // Top of stack initialized to -1
    }

    public void push(int value) {
        if (tos == max_size - 1) {
            System.out.println("Stack overflow! Cannot push element.");
        } else {
            tos++;
            stack[tos] = value;
            System.out.println("Pushed " + value + " onto the stack.");
        }
    }

    public void pop() {
        if (tos == -1) {
            System.out.println("Stack underflow! Cannot pop element.");
        } else {
            int popped = stack[tos];
            tos--;
            System.out.println("Popped " + popped + " from the stack.");
        }
    }

    public void display() {
        if (tos == -1) {
            System.out.println("Stack is empty.");
        } else {
            System.out.println("Stack contents:");
            for (int i = tos; i >= 0; i--) {
                System.out.println(stack[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the maximum size of the stack: ");
        int max_size = scanner.nextInt();
        Stack stack = new Stack(max_size);

        while (true) {
            System.out.println("\nSelect an option:");
            System.out.println("1. Push an element");
            System.out.println("2. Pop an element");
            System.out.println("3. Display stack");
            System.out.println("4. Exit");
            
            int choice = scanner.nextInt();
            
            if (choice == 1) {
                System.out.print("Enter the element to push: ");
                int element = scanner.nextInt();
                stack.push(element);
            } else if (choice == 2) {
                stack.pop();
            } else if (choice == 3) {
                stack.display();
            } else if (choice == 4) {
                System.out.println("Exiting...");
                break;
            } else {
                System.out.println("Invalid choice! Please select a valid option.");
            }
        }

        scanner.close();
    }
}
