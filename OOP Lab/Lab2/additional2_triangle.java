public class triangle {
    public static void main(String[] args) {
        int rows = 10;
        int[][] A = new int[rows][];

        // Initialize the array and compute values
        for (int i = 0; i < rows; i++) {
            A[i] = new int[i + 1];
            for (int j = 0; j <= i; j++) {
                A[i][j] = i + j;
            }
        }

        // Print the triangular array
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }
}
