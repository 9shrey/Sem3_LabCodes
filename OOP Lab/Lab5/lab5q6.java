import java.util.*;
public class FormatNumberWithCommas {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Give input: ");
        String input = sc.nextLine(); // Replace with your input string
        String formattedNumber = formatNumber(input);
        System.out.println("Input String: " + input);
        System.out.println("Output String: " + formattedNumber);
    }
    public static String formatNumber(String input) {
        int length = input.length();
        StringBuilder formattedNumber = new StringBuilder();
        int commaPosition = length % 3;
        if (commaPosition == 0) {
            commaPosition = 3;
        }
        for (int i = 0; i < length; i++) {
            formattedNumber.append(input.charAt(i));
            if (i == commaPosition - 1 && i != length - 1) {
                formattedNumber.append(",");
                commaPosition += 3;
            }
        }
        return formattedNumber.toString();
    }
}
