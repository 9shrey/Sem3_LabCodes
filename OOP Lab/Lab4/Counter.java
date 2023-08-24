public class Counter {
    private static int count = 0;  // Static data member to count the number of objects
    
    public Counter() {
        count++;  // Increment count whenever a new object is created
    }
    
    public static void showCount() {
        System.out.println("Number of objects created: " + count);
    }
    
    public static void main(String[] args) {
        Counter c1 = new Counter();
        Counter c2 = new Counter();
        Counter c3 = new Counter();
        
        Counter.showCount();  // Display the number of objects created
    }
}

