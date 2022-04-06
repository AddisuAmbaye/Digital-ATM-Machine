#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
/*mini project in ATM.
which performs the following tasks....check balance , cash withdrawl ,user details , update mobile number .*/

class atm{
private:
       int long account_number ;
	   int pin_number ;
	   string mobile_number ;
	   string name ;
	   double balance;

public:

void setData(long account_number_a, int pin_number_a,string mobile_number_a,string name_a, double balance_a)
{
account_number = account_number_a;
pin_number = pin_number_a;
mobile_number = mobile_number_a;
name = name_a;
balance = balance_a;

}

 long getAccount_No(){

    return account_number;
}

int getPIN_No(){

	return pin_number;
}
string getMobile_No(){

	return mobile_number;
}
string getName(){

	return name;
}
double getBalance(){

	return balance;
}

 void setmobile_no(string previous_mobile_no,string new_mobile_number){
	 if(previous_mobile_no == mobile_number){
		 mobile_number = new_mobile_number;
		 cout<<" your mobile number is successfully updated."<<endl;
		 _getch();
	 }
      else
	  {
			cout << endl << "Incorrect !!! Old Mobile no";
			_getch();			  //getch is to hold the screen ( untill user press any key )
		}
 }  
 void cashWithdraw(int amount_a){
     if(amount_a > 0 && amount_a < balance){
	 balance -= amount_a;
	 cout<<"Please collect your cash."<<endl;
	 cout<<"Your current balance is: "<<balance<<endl;
	 _getch();
	 }
	 else {
		 cout<<"Invalid input or insufficent balance."<<endl;
		 _getch();
	 }


}
 
};


int main(){

int choice = 0, enterPIN;
long enterAccount_number;
system("cls");
atm user1;

user1.setData(1000777,3609,"0977721388","Addis Ambaye",1031123);

do
 { 
	system("cls");
	     cout<<"......Welcome to CBE ATM....."<<endl;
	     cout<<"Enter your account number."<<endl;
		 cin>>enterAccount_number;
		 cout<<"Enter your pin number:"<<endl;
		 cin>>enterPIN;
	if((enterAccount_number == user1.getAccount_No()) && (enterPIN == user1.getPIN_No()))
		 
   {
			  do
			  {
			int amount = 0;
			string oldMobileNumber,newMobileNumber;
			system("cls");
		 cout<<"Select from the options."<<endl;	
		 cout<<"press 1: to check your balance."<<endl;
		 cout<<"press 2: to withdraw cash."<<endl;
		 cout<<"press 3: to see user detail."<<endl;
		 cout<<"press 4: to update mobile number."<<endl;
		 cout<<"press 5: to Exit."<<endl;
		 cin>>choice;
	

		 switch(choice){
			 case 1: 
				 cout<<"Your balance is "<<user1.getBalance()<<endl;
				 _getch();
				 break;
			 case 2:
			     cout<<"Enter the amount you want to withdraw from the bank."<<endl;
				 cin>>amount;
			     user1.cashWithdraw(amount);
				 break;
			 case 3:
			      cout<<"*****user details are*******"<<endl;
			      cout<<endl<<"NAME : "<< user1.getName();
				  cout<<endl<<"ACCOUNT NUMBER : "<< user1.getAccount_No();
				  cout<<endl<<"MOBILE NUMBER : "<< user1.getMobile_No();
				  cout<<endl<<"YOUR BALANCE IS : "<<user1.getBalance();
				  _getch();
				  break;
			case 4: 
			     cout<<"Enter old mobile number."<<endl;
				 cin>>oldMobileNumber;
				 cout<<"Enter new mobile number."<<endl;
				 cin>>newMobileNumber;
				 user1.setmobile_no(oldMobileNumber,newMobileNumber);
				 break;
			case 5: 
			     exit(0);
				 
		    default:
			      cout<<"Enter valid Data !!!"<<endl;
			      	 	  	 	 
			 }

			  }while(1);
			  
            }
	
		
   else
   {
		cout<<"Enter account again or Invalid PIN number.";
	   }	 

		 
		
   }
    while(1);
	return 0;
}	




