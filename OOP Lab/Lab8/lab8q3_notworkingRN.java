import java.text.SimpleDateFormat;
import java.util.*;
class Stu extends Exception{
    private static int registrationCounter = 0;
    private int registrationNumber;
    private String fullName;
    private Date dateOfJoining;

    public Stu(String fullName, Date dateOfJoining) {
        registrationCounter++;
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(dateOfJoining);
        int yearOfJoining = calendar.get(Calendar.YEAR);
        this.registrationNumber = yearOfJoining * 100 + registrationCounter;
        this.fullName = fullName;
        this.dateOfJoining = dateOfJoining;
        try{
            if((registrationNumber%100)>03){
                throw new Stu("Seats are Filled!");
            }
            else{
                System.out.println("Seats are not Filled");
            }
        }
        catch(Stu de){
            System.out.println("Caught the exception:"+de.getMessage());  
        }
    }
    public Stu(String s){
        super(s);
    }
}
class lab8q3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Stu[] St = new Stu[5];
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter Full Name: ");
            String fullName = sc.nextLine();

            System.out.print("Enter Date of Joining (YYYY-MM-DD): ");
            String dateOfJoiningStr = sc.nextLine();
            SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
            Date dateOfJoining = null;
            try {
                dateOfJoining = dateFormat.parse(dateOfJoiningStr);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }
}
