import java.util.*;

class building{
    private double squareFootage;
    private int stories;

    void setSquareFootage(double squareFootage){
        this.squareFootage=squareFootage;
    }

    void setStories(int stories){
        this.stories=stories;
    }

    double getSquareFootage(){
        return this.squareFootage;
    }

    int getStories(){
        return this.stories;
    }
}

class house extends building{
    private int bedrooms;
    private int bathrooms;

    void setBedrooms(int bedrooms){
        this.bedrooms=bedrooms;
    }

    void setBathrooms(int bathrooms){
        this.bathrooms=bathrooms;
    }

    int getBedrooms(){
        return this.bedrooms;
    }

    int getBathrooms(){
        return this.bathrooms;
    }
}

class school extends house{
    private int classrooms;
    private String gradeLevel;

    void setClasrooms(int classrooms){
        this.classrooms=classrooms;
    }

    void setGradeLevel(String gradeLevel){
        this.gradeLevel=gradeLevel;
    }

    int getClassrooms(){
        return classrooms;
    }

    String getGradeLevel(){
        return gradeLevel;
    }

    void display(int choice){
        System.out.println("\nDisplaying Entered Data: \n");
        System.out.println("Square Footage: " + getSquareFootage());
        System.out.println("Stories: " + getStories());

        if(choice==1){
            System.out.println("Bedrooms: " + getBedrooms());
            System.out.println("Bathrooms: " + getBathrooms());
        }
        else if(choice==2){
            System.out.println("Classrooms: " + getClassrooms());
            System.out.println("Grade Level: " + getGradeLevel());
        }
    }
}


class q4{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        school obj = new school();

        System.out.println("Enter the following Details: \n");
        System.out.print("Square Footage: ");
        double squareFootage = sc.nextDouble();
        obj.setSquareFootage(squareFootage);

        System.out.print("Stories: ");
        int stories = sc.nextInt();
        obj.setStories(stories);

        System.out.println("\nSelect the correct option:");
        System.out.println("1. House");
        System.out.println("2. School");
        System.out.print("Option: ");
        int choice = sc.nextInt();

        if(choice==1){
            System.out.print("\nBedrooms: ");
            int bedrooms = sc.nextInt();
            obj.setBedrooms(bedrooms);

            System.out.print("Bathrooms: ");
            int bathroms = sc.nextInt();
            obj.setBathrooms(bathroms);
        }

        else if (choice==2){
            System.out.print("\nClassrooms: ");
            int classrooms = sc.nextInt();
            obj.setClasrooms(classrooms);

            System.out.print("Grade Level: ");
            sc.nextLine();
            String gradeLevel = sc.nextLine();
            obj.setGradeLevel(gradeLevel);
        }

        obj.display(choice);

        sc.close();
    }
}