import java.util.*;

class StackException {
    int max_size;
    int[] stack;
    int tos;

    public StackException(int max_size) {
        this.max_size = max_size;
        stack = new int[max_size];
        tos = -1;
    }

    public void push(int value) {
        try {
            if (tos < max_size - 1) {
                stack[++tos] = value;
                System.out.println("Pushed " + value + " onto the stack.");
            } else {
                throw new ArrayIndexOutOfBoundsException();
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Stack Overflow!");
        }
    }

    public void pop() {
        try {
            if (tos >= 0) {
                int popped = stack[tos--];
                System.out.println("Popped " + popped + " from the stack.");
            } else {
                throw new ArrayIndexOutOfBoundsException();
            }
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Stack Underflow!");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the maximum size of the stack: ");
        int max_size = scanner.nextInt();
        StackException stack = new StackException(max_size);

        while (true) {
            System.out.println("\nSelect an option:");
            System.out.println("1. Push an element");
            System.out.println("2. Pop an element");
            System.out.println("3. Exit");

            int choice = scanner.nextInt();

            if (choice == 1) {
                System.out.print("Enter the element to push: ");
                int element = scanner.nextInt();
                stack.push(element);
            } else if (choice == 2) {
                stack.pop();
            } else if (choice == 3) {
                System.out.println("Exiting...");
                break;
            } else {
                System.out.println("Invalid choice! Please select a valid option.");
            }
        }

        scanner.close();
    }
}
