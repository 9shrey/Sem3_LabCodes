import java.util.*;
class Mixer {
    List<Integer> arr = new ArrayList<>();
    void accept() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int prev = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            if (num > prev) {
                arr.add(num);
                prev = num;
            } else {
                System.out.println("Please enter elements in ascending order.");
                i--;
            }
        }
    }
    Mixer mix(Mixer A) {
        Mixer result = new Mixer();
        int i = 0, j = 0;
        while (i < arr.size() && j < A.arr.size()) {
            if (arr.get(i) < A.arr.get(j)) {
                result.arr.add(arr.get(i++));
            } else if (arr.get(i) > A.arr.get(j)) {
                result.arr.add(A.arr.get(j++));
            } else {
                result.arr.add(arr.get(i++));
                j++;
            }
        }
        while (i < arr.size()) {
            result.arr.add(arr.get(i++));
        }
        while (j < A.arr.size()) {
            result.arr.add(A.arr.get(j++));
        }
        return result;
    }
    void display() {
        System.out.print("Merged array: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        Mixer mixer1 = new Mixer();
        Mixer mixer2 = new Mixer();

        System.out.println("Enter elements for Mixer 1:");
        mixer1.accept();

        System.out.println("Enter elements for Mixer 2:");
        mixer2.accept();

        Mixer mergedMixer = mixer1.mix(mixer2);

        System.out.println("Mixer 1:");
        mixer1.display();

        System.out.println("Mixer 2:");
        mixer2.display();

        System.out.println("Merged Mixer:");
        mergedMixer.display();
    }
}
