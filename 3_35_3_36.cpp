# include <iostream>
# include <string.h>
# include <string>
# include <cstring>
# include <limits>
using namespace std;

int num_accounts; // number of accounts

// class deceleration

class ATM {
private:
       char account_name[100];
	   char  card_number[10];
	   float amount;
public:
	   void create_new_account();
       void deposit(char number1[10],float money1);
       void transfer(char sending[10],char receiving[10],float money2);
	   void withdrawal(char number2[10],float money3);
       void print_acc_data();
};

  ATM acc [100]; // Global Array of Objects of 100 Accounts



       void options()
       {
		   cout<<"1----create new account"<<endl;
	       cout<<"2----deposit"<<endl;
	       cout<<"3----transfer to another account"<<endl;
	       cout<<"4----withdrawal"<<endl;
	       cout<<"5----exit"<<endl;
	   }


// implementation of member functions


	   void ATM :: create_new_account(){

l1:
          cout<<"please, enter the account name : ";
          cin.ignore();
          cin.getline(account_name,100);
          char name[100];
          for(int i = 0 ; i < 100 ; i++){
            name[i] = account_name[i];
          }
          for (int i = 0 ; i < num_accounts ; i++)
          {
              if(strcmp(acc[i].account_name,name)==0){
                cout << "error, This name is already exist"<<endl;
                goto l1;
              }
          }
		   if(strlen(account_name) > 100){
			   cout<<"You exceeded the number of characters in the name "<<endl;
			   goto l1;}

		    for(int i = 0 ; i < strlen(account_name) ; i++){
			   if (!((account_name[i] >= 65 && account_name[i] <= 90)||(account_name[i] >= 97 && account_name[i] <= 122)||(account_name[i] == 32)))
			{
				cout<<"invalid name, enter characters only"<<endl<<endl;
				goto l1;}}

l2:
           cout<<"please, enter the card number (10 numbers only) : ";
		   cin.getline(card_number,11);

		   char card[11];
		   for (int i = 0 ; i < 10 ; i++)
           {
               card[i] = card_number[i];
           }
           for (int i = 0 ; i < num_accounts ; i++)
           {
               if (strcmp(acc[i].card_number,card)==0)
               {
                   cout << "error , this Card number is already exist"<<endl;
                   goto l2;
               }
           }

		   for(int i = 0 ; i < strlen(card_number) ; i++){
				if (!((card_number[i] >= 47 && card_number[i] <= 57) || (card_number[i]==32)))
			{
				cout<<"invalid number, enter digits only"<<endl<<endl;
				goto l2;}
			}


		   if (strlen(card_number) != 10)
		   {
			   cout<<"error, the Card number is less than 10 numbers"<<endl;
			   goto l2;}

          bool found = false;

	      for(int i = 0 ; i < 10 ; i++){
		     if(card_number[0] == card_number[i+1])
			    found = true;
	           }
	         if(found)
		       {  cout<<"error , you enter repeated digits"<<endl;
                  goto l2;}

		   amount = 0;

	   }





	   void ATM :: deposit(char number1[11],float money1){

		   int i,loc = 0;
		   for( i = 0 ; i <= num_accounts ; i++){
			  if(strcmp((acc[i].card_number),number1) == 0)
				   loc = i; break;}

           acc[loc].amount += 1.01 * money1;
		   acc[loc].print_acc_data();
		   options();
	   }





	   void ATM :: withdrawal(char number2[11],float money3){

		   int i,loc = 0;

		   for( i = 0 ; i <= num_accounts ; i++){

			   if (strcmp(acc[i].card_number,number2) == 0)
		    	loc = i;
		   }

           acc[loc].amount -= 1.03 * money3;
		   acc[loc].print_acc_data();
		   options();
	   }




          void ATM :: transfer(char sending[11] , char receiving[11] , float money2){
	           int i,loc1 = 0;
		        for( i = 0 ; i <= num_accounts ; i++){
			       if (strcmp(acc[i].card_number,sending) == 0)
				     loc1 = i;}
                      int k,loc2 = 0;

		            for( k = 0 ; k <= num_accounts ; k++){
			         if (strcmp(acc[k].card_number,receiving) == 0)
				      loc2 = k;}

		   acc[loc1].amount -= money2;
		   acc[loc1].amount -= 0.015*money2;

		   acc[loc2].amount += money2;
	       acc[loc2].amount -= 0.015*money2;

		   acc[loc1].print_acc_data();
		   acc[loc2].print_acc_data();
		   options();
	   }



	   void ATM :: print_acc_data(){
		   cout << "Name : " << account_name << endl;
	       cout << "Card Number : " << card_number <<endl;
		   cout << "Amount : " << amount << endl;
	   }




   int main(){

        int choice;
        options();
        int exit = 0;

	   while (!exit) {
l3:
		   cout << "please enter the number of operation : ";
		       cin >> choice;

	    switch (choice){


		   case 1:{             // create new account

			   if (num_accounts == 100){
 				   cout<<"max number of accounts"<<endl;
 				   exit = 1; break;
			       }

			       acc[num_accounts].create_new_account();
				   acc[num_accounts].print_acc_data();
				   num_accounts ++; // Increment number of accounts
                   options();

				   break;
                 }


	       case 2:{             // Deposit Money in Account
			   float money1;
			   char number1[11];

l4:
               cout<<"please enter the card number(10 numbers) : ";

			   cin.ignore();

			   cin.getline(number1,11);

		     for(int i = 0 ; i < strlen(number1) ; i++){
				if (!((number1[i] >= 47 && number1[i] <= 57))){
			   cout<<"invalid number,enter digits only"<<endl<<endl;
				goto l4;}
			    }
		   if (strlen(number1)<10)
		   {
			   cout<<"error, your no of digits less than 10"<<endl;
			   goto l4;}
		   if (strlen(number1)>10)
		   {
			   cout<<"error, you no of digits greater than 10"<<endl;
			   goto l4;}
l7:
			   cout << "please, enter the amount to be deposited : ";
               cin >> money1;
                if (money1 <= 0)
                {
                    cout << "error, the money you entered meaningless"<<endl;
                    goto l7;
                }
				   acc[num_accounts].deposit(number1,money1);

				   break;
                }


		   case 3:{         // transfer money from Sending Account to Receiving Account
		       float money2;
			   char sending[11], receiving[11];
l5:
               cout<<"please enter the sending account(10 numbers) : ";
			   cin.ignore();
			   cin.getline(sending,11);

              for(int i = 0 ; i < strlen(sending) ; i++){
				if (!((sending[i]>=47&&sending[i]<=57)||(sending[i]==32)))
			      {
			    	cout<<"invalid number,enter digits only"<<endl<<endl;
			    	goto l5;}
		           	}

		        if (strlen(sending)<10)
		          {
                    cout<<"error, you no of digits less than 10"<<endl;
                    goto l5;}

                if (strlen(sending)>10)
		          {
                    cout<<"error, you no of digits greater than 10"<<endl;
                    goto l5;}


l6:
                cout<<"please enter the receiving account(10 numbers) : ";

                cin.getline(receiving,11);

             for(int i = 0 ; i < strlen(receiving) ; i++){
                if (!((receiving[i] >= 47 && receiving[i] <= 57)||(receiving[i] == 32)))
			      {
				    cout<<"invalid number,enter digits only"<<endl<<endl;
			    	goto l6;}
             }
		   if (strlen(receiving)<10)
		     {
			   cout<<"error, you no of digits less than 10"<<endl;
			   goto l6;}
		   if (strlen(receiving)>10)
		     {
			   cout<<"error, you no of digits greater than 10"<<endl;
               goto l6;}
l8:
		   cout<<"please enter the amount of money to be transferred : ";
		   cin>>money2;
               if (money2 <= 0)
                {
                    cout << "error, the money you entered meaningless"<<endl;
                    goto l8;
                }
			       acc[num_accounts].transfer(sending,receiving,money2);

				   break;
		              }


           case 4:{      // Withdrawal  Money From an Account
			   char number2[11];float money3;
			   cout<<"please enter the account number(10 numbers) : ";

			   cin.ignore(1,'\n');
			   cin.getline(number2,11);

l9:
		       cout<<"please enter the amount of money to be withdrawn :  ";
		       cin>>money3;
               if (money3 <= 0)
                {
                    cout << "error, the money you entered meaningless"<<endl;
                    goto l9;
                }
			       acc[num_accounts].withdrawal(number2,money3);

				   break;
				  }


           case 5:{
			       exit = 1;

			       break;
		          }


		   default:{
			        cout<<"wrong choice, please choose valid operation"<<endl;
			        goto l3;
				   }
	       }

	}
     return 0;
}
