class CurrentDate extends Exception{
    int day,month,year;
    public CurrentDate(){
        this.day=day;
        this.month=month;
        this.year=year;
    }
    public CurrentDate(String s){
        super(s);
    }
    public void createDate(int day,int month,int year){
        try{
            if( day<0 || day>31 ){
                throw new CurrentDate("Day Invalid!");
            }
            else if(month<0 || month>12){
                throw new CurrentDate("Month Invalid");
            }
            else{
                System.out.println("Date created->"+day+":"+month+":"+year+"\n");
            }
        }
        catch(CurrentDate de){
            System.out.println("Caught the exception:"+de.getMessage());  
        }
    }
}
class lab8q2{
    public static void main(String[] args){
        CurrentDate cd = new CurrentDate();
        cd.createDate(2,3,4);
        cd.createDate(23,21,2004);
        cd.createDate(43,3,3025);
        cd.createDate(43,34,3029); 
    }
}
