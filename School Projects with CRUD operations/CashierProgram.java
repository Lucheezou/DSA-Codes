import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class SAGUINSIN_CashierProgram {
    
   static ArrayList<String> item = new ArrayList<>(Arrays.asList("Pancit Canton","Yakisoba"
    ,"Corn Chips","Potato Chips","Lemon Juice","Apple Juice","Instant Beef Mami", "Instant Chicken Mami"
    ,"Canned Sardines", "Canned Tuna", "Canned Beef", "Choco Biscuit"));
    
   static ArrayList<Double> itemPrice = new ArrayList<>(Arrays.asList(9.25,10.35,6.00,9.75,22.00,21.65,
    7.50,7.50,18.00,21.75,24.50,65.25));
    
   static int productID[] = {121123, 121456, 121789, 122123, 122789, 123123, 123789, 124123, 124456, 
   124789, 125123, 125789};
    
   static ArrayList<Integer> cart = new ArrayList<>();
   static ArrayList<Integer> quantity = new ArrayList<>();
        
  static void listItems()  
  {
  
  System.out.println("----------------------------------------");
  System.out.println("|           List of Products            |");
  System.out.println("----------------------------------------");
  System.out.println("ProductID  Name                    Price");
  for (int i = 0; i < productID.length;i++){
  System.out.println(productID[i]+  "     "  + String.format("%-24s", item.get(i))  + String.format("%,.2f", itemPrice.get(i)));
  }
  
  Scanner input = new Scanner(System.in);
  System.out.println("Go back to menu? (Y/N)");
  String choice = input.nextLine();

 if ("Y".equals(choice))
 {
 menu();
 }
 
 else if ("N".equals(choice))
      {
      System.exit(0);
      }
  
  else
 {
  System.out.println("INVALID OPTION... TERMINATING");
  System.exit(0);
 }
  }
     
      
       
            
  
  static void checkout()
  {
  
   System.out.println("----------------------------------------------------------------");
   System.out.println("|                         RECEIPT                               |");
   System.out.println("----------------------------------------------------------------");
   System.out.println("ProductID   Name                    Quantity                    Price per Quantity                    Total Price");
   int position = 0;
   for (int i = 0; i < cart.size(); i++)
   {
    
    int elem = cart.get(i);
    for (int j = 0; j < productID.length; j++) 
    {
    if (elem == productID[j])
    {
    position = j;
    }
    }
    double totalprice = itemPrice.get(position) * quantity.get(i);
    System.out.println(elem + "      " + String.format("%-24s", item.get(position)) + String.format("%-28s",quantity.get(i))
        + String.format("%-38s", itemPrice.get(position)) + totalprice);
   }
   System.out.println("----------------------------------------------------------------");
   double total = 0;
   for (int i = 0; i < cart.size(); i++)
   {
       
    for (int j = 0; j < productID.length; j++) 
    {
    if (cart.get(i) == productID[j])
    {
    position = j;
    }
    }
       
   total = total + itemPrice.get(position)* quantity.get(i);
   }
   System.out.println("TOTAL:                                                      " + String.format("%,.2f", total));
   cart.clear();
   quantity.clear();
   Scanner input = new Scanner(System.in);
   
   System.out.println("Exit? Enter \"Y\" to exit. \"N\" to go back to the Menu");
   String choice = input.nextLine();



 if ("Y".equals(choice))
      {
      System.exit(0);
      }
 
if ("N".equals(choice))
      {
      menu();
      }
      
else
      {
      System.out.println("INVALID OPTION... TERMINATING");
      System.exit(0);
      }
      
  }
  
  
  static void addcart()
  {    

       int cartitem;
       Scanner input = new Scanner(System.in);
       System.out.println("Enter Product ID to be added into cart: (Enter '0' if proceed to checkout)");
       cartitem = input.nextInt();
       
               
       if (cartitem == 0)
       {
           checkout();
           return;
       }
               
       for (int i = 0; i < productID.length; i++)
       {
           if (cartitem == productID[i])
           {
            if (cart.contains(cartitem))
            {
            int position = cart.indexOf(cartitem);
            quantity.set(position, quantity.get(position) + 1);
            System.out.println("Added Quantity");
            addcart();
            }
            
            else
            {
            cart.add(cartitem);
            quantity.add(1);
            System.out.println("Added");
            addcart();
            }
            
           }
       
       }
       System.out.println("Please Enter a Valid ProductID : ");
       addcart();
       
  }
  
   static void menu(){
        int choice;
        Scanner input = new Scanner(System.in);
        
        System.out.println("-----------");
        System.out.println("|   MENU   |");
        System.out.println("-----------");
        System.out.println("1. View List of Items");
        System.out.println("2. Add Items to Cart");
        System.out.println("3. Exit");
        System.out.println("Choice : ");
        choice = input.nextInt();
        
while(choice > 3 || choice < 1 )
{
System.out.println("Please input a valid number: ");
choice = input.nextInt();
}
        
  switch(choice) {
  case 1:
    listItems();
    break;
  case 2:
    addcart();
    break;
  case 3:
    System.exit(0);
    break;
}
        
        
    }
    
    public static void main(String[] args) {
        menu();

    }
    
    
}
