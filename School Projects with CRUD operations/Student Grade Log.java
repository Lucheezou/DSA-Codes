
import java.util.Scanner;  
import java.util.ArrayList;

public class MidtermACT2_SAMSON {
     
    static double quiz = 0.25,attendance = 0.1,exam = 0.35,project = 0.30;
    static int numberofStudents = 0;
   
    public static int computeTotalgrade(int myQuiz,int myAttendance,int myExam,int myProject)
    {
        
       return (int)((quiz*myQuiz)+(attendance*myAttendance)+(exam*myExam)+(project*myProject));
    }
    
    public static void increaseStudentCount()
    {
        numberofStudents++;
    }
    public static String getString()
     {
       String name;   
       Scanner userInput = new Scanner(System.in);
       name = userInput.nextLine() ;
       return name;
     }
     
    public static int getInt()
     {
       int value;   
       Scanner userInput = new Scanner(System.in);
       value = userInput.nextInt();
       return value;
     }
     
    
   public static void main(String []args) {
       
       
       
      
       
       String proceed;
     ArrayList<String> studentName = new ArrayList<String>();
     ArrayList<String> studentProgram = new ArrayList<String>();
     ArrayList<String> studentCourse = new ArrayList<String>();
     ArrayList<Integer> studentQuiz = new ArrayList<Integer>();
     ArrayList<Integer> studentAttendance = new ArrayList<Integer>();
     ArrayList<Integer> studentExam = new ArrayList<Integer>();
     ArrayList<Integer> studentProject = new ArrayList<Integer>();
     ArrayList<Integer> studentTotal = new ArrayList<Integer>();
     
     
  
     
     
     
  do {
     
      Scanner userInput = new Scanner(System.in);
     
      System.out.println("Enter Name : ");
      studentName.add(getString());   
      while (studentName.get(numberofStudents).trim().isEmpty() || studentName.get(numberofStudents).isEmpty())
          {
              
              System.out.println("Name Cannot be Blank!");
              System.out.println("Enter Name : ");
          studentName.set(numberofStudents,getString());   
          }
      
      
      
      System.out.println("Enter Program : ");
      studentProgram.add(userInput.nextLine()); 
      while (studentProgram.get(numberofStudents).trim().isEmpty() || studentProgram.get(numberofStudents).isEmpty())
          {
              
              System.out.println("Program Cannot be Blank!");
              System.out.println("Enter Program : ");
          studentProgram.set(numberofStudents,getString());   
          }
      
      System.out.println("Enter Course : ");
      studentCourse.add(userInput.nextLine()); 
      while (studentCourse.get(numberofStudents).trim().isEmpty() || studentCourse.get(numberofStudents).isEmpty())
          {
              
              System.out.println("Course Cannot be Blank!");
              System.out.println("Enter Course : ");
          studentCourse.set(numberofStudents,getString());   
          }
      
      System.out.println("Enter Grade For ");
      System.out.println("Quiz : ");
      int myQuiz = getInt();
      while (myQuiz > 95 || myQuiz < 65)
      {
     
              
      if (myQuiz > 95)
      {
      System.out.println("Error! Grade can't be higher than 95");
      System.out.println("Enter Grade For Quiz : "); 
      myQuiz = getInt();
      }
                
     else if (myQuiz < 65)
     {
      System.out.println("Error! Grade can't be lower than 65");
      System.out.println("Enter Grade For Quiz : ");
     
       myQuiz = getInt();
      }
     
    }
      studentQuiz.add(myQuiz);
           
      System.out.println("Attendance : ");
      int myAttendance = getInt();
      while (myAttendance > 95 || myAttendance < 65)
      {
          if (myAttendance > 95)
          {
      System.out.println("Error! Grade can't be higher than 95");
      System.out.println("Enter Grade For Attendance : ");       
      myAttendance = getInt();
          }
          
          
          
          else if (myAttendance < 65)
          {
      System.out.println("Error! Grade can't be lower than 65");
      System.out.println("Enter Grade For Attendance ");      
       myAttendance = getInt();
          }
     
      }
      
      studentAttendance.add(myAttendance);
    
      System.out.println("Exam : ");
      int myExam = getInt();
      while (myExam > 95 || myExam < 65)
      {
          if (myExam > 95)
          {
      System.out.println("Error! Grade can't be higher than 95");
      System.out.println("Enter Grade For Exam : ");       
      myExam = getInt();
          }
          
          
          
          else if (myExam < 65)
          {
      System.out.println("Error! Grade can't be lower than 65");
      System.out.println("Enter Grade For Exam ");      
      myExam = getInt();
          }
     
      }
      
      studentExam.add(myExam);
      
      
      
      System.out.println("Project : ");
      int myProject = userInput.nextInt();
      while (myProject > 95 || myProject < 65)
      {
          if (myProject > 95)
          {
      System.out.println("Error! Grade can't be higher than 95");
      System.out.println("Enter Grade For Project : ");       
      myProject = getInt();
          }
          
          
          
          else if (myProject < 65)
          {
      System.out.println("Error! Grade can't be lower than 65");
      System.out.println("Enter Grade For Project ");      
      myProject = getInt();
          }
     
      }
     
      studentProject.add(myProject);
      
     
        
      
     
     studentTotal.add(computeTotalgrade(myQuiz,myAttendance,myExam,myProject));
     increaseStudentCount();  
     
     System.out.println("Do you want to compute another student's grades?");
     proceed = getString();
    
    
     while (proceed.equalsIgnoreCase("NO") == false && proceed.equalsIgnoreCase("YES") == false){
     System.out.println("Please enter YES or NO : ");
     proceed = getString();
     if (proceed.equalsIgnoreCase("NO") == true){}
     }
     }    
     while (proceed.equalsIgnoreCase("YES") == true);
     
     
     for (int i = 0; i < numberofStudents ;i++)
     {System.out.println("=======================================");
     System.out.println("Student Name : " + studentName.get(i));
     System.out.println("Program : "+studentProgram.get(i));
     System.out.println("Course : "+studentCourse.get(i));
     System.out.println("Grades : Quiz - 25% = "+studentQuiz.get(i)+"|Attendance - 10% = "+studentAttendance.get(i) 
             +"|Exam - 35% = "+studentExam.get(i)+"|Project - 30% = "+studentProject.get(i)+
             "\n---------------------------------------- ");
     System.out.println("Quiz : "+  String.format("%.0f",quiz*studentQuiz.get(i)) + "%");
     System.out.println("Attendance : "+ String.format("%.0f",attendance*studentAttendance.get(i)) + "%");
     System.out.println("Exam : "+ String.format("%.0f",exam*studentExam.get(i)) + "%");
     System.out.println("Project : "+ String.format("%.0f",project*studentProject.get(i)) + "%");
     System.out.print("Total  : "+ studentTotal.get(i) + "%");
     if (studentTotal.get(i) >= 77 && studentTotal.get(i) <= 79) {
    System.out.print(" - FAIR");
} else if (studentTotal.get(i) >= 80 && studentTotal.get(i) <=82) {
    System.out.println(" - SATISFACTORY");
} else if (studentTotal.get(i) >= 83 && studentTotal.get(i) <=85) {
    System.out.println(" - GOOD");
} else if (studentTotal.get(i) >= 86 && studentTotal.get(i) <=88) {
    System.out.println(" - VERY SATISFACTORY");
} else if (studentTotal.get(i) >= 89 && studentTotal.get(i) <=91) {
    System.out.println(" - VERY GOOD");
} else if (studentTotal.get(i) >= 92 && studentTotal.get(i) <=95) {
    System.out.println(" - EXCELLENT");
}
     if (studentTotal.get(i) <= 74) {
    System.out.println(" - FAILED");
 }
     else if (studentTotal.get(i) >= 75 && studentTotal.get(i) <=86) {
    System.out.println(" - PASSED");
}
    System.out.println("=======================================");
     }
     
}}