#include<iostream>
#include<iostream>
#include<vector>

using namespace std;

class bankaccount{
    private:
        string name;
        int accountnum;
        double balance;
    public:
        bankaccount(string n,int ac,double bal){
            name = n;
            accountnum = ac;
            balance = bal;
        }
        string getName(){
            return name;
        }
        int getaccountnum(){
            return accountnum;
        }
        double getbalance(){
            return balance;
        }
        void deposit(double amount){
        	balance=balance+amount;
        }
        void withdraw(double amount){
        	if(balance >=amount){
        		cout<<"\t\t\t Successfully Withdrawn"<<endl;
        		balance=balance-amount;
        	}else{
        		cout<<"\t\t\tInsufficient balance"<<endl;
        	}
        }
};

class bankmanagement{
	private:
   		vector<bankaccount>accounts;
   	public:
   		void addaccount(string name,int accountnum,double balance){
   			accounts.push_back(bankaccount(name,accountnum,balance));
   		}
   		void showallaccounts(){
   			cout<<"\t\t\t All account holders"<<endl;
   			for(int i=0;i<accounts.size();i++){
   				cout<<"Name :"<<accounts[i].getName()<<", Account number :"<<accounts[i].getaccountnum()<<", Balance :"<<accounts[i].getbalance()<<endl;
   			}
   		}
   		void searchaccount(int account){
   			cout<<"\t\t\tAccount holder "<<endl;
   			for(int i=0;i<accounts.size();i++){
   				if(accounts[i].getaccountnum()==account){
   					cout<<"Name :"<<accounts[i].getName()<<", Account number :"<<accounts[i].getaccountnum()<<", Balance :"<<accounts[i].getbalance()<<endl;
   				}
   		}
   	}
   	bankaccount* findaccount(int accountnum){
   		for(int i=0;accounts.size();i++){
   			if(accounts[i].getaccountnum()==accountnum){
   				return &accounts[i];
   			}
   		}
   	}
};

int main(){
    bankmanagement bank;
    int choice;
    char opt;
    do {
    	system("clear");
	    cout<<"\t\t\t Bank Mnanagement System"<<endl;
	    cout<<"\t\t\t\t Main Menu"<<endl;
	    cout<<"\t\t\t 1.Create New Account"<<endl;
	    cout<<"\t\t\t 2. Show all accounts"<<endl;
	    cout<<"\t\t\t 3. Search Account"<<endl;
	    cout<<"\t\t\t 4. Deposit Money"<<endl;
	    cout<<"\t\t\t 5. Withdraw Money"<<endl;
	    cout<<"\t\t\t 6.EXIT"<<endl;
	    cout<<"\t\t\t----------------------------------"<<endl;
	    cout<<"\t\t\t Enter your choice:";
	    cin>>choice;
	    switch(choice){
	    	case 1:{
	    		string name;
	    		int accountnum;
	    		double balance;

	    		cout<<"\t\t\t Enter Name :";
	    		cin>>name;
	    		cout<<"\t\t\t Enter account number :";
	    		cin>>accountnum;
	    		cout<<"\t\t\t Enter Initial Balance :";
	    		cin>>balance;
	    		bank.addaccount(name,accountnum,balance);
	    		cout<<"\t\t\t Account created succesfully"<<endl;

	    		break;
    		}
    	    case 2:{
    			bank.showallaccounts();
    			break;
    		}
    		case 3:{
    			int accountnum;
    			cout<<"Enter account number :";
    			cin>>accountnum;
    			bank.searchaccount(accountnum);
    			break;
    		}
    	case 4:{
    		int accountnum;
    		double amount;
    		cout<<"\t\t\t Enter account number to deposit money :";
    		cin>>accountnum;
    		bankaccount* account = bank.findaccount(accountnum);
    		if(account!=NULL){
    			cout<<"\t\t\tEnter amount to deposit :";
    			cin>>amount;
    			account -> deposit(amount);
    			cout<<"\t\t\t"<<amount<<" deposited successfully"<<endl;

    		}else{
    			cout<<"\t\t\t Account not found"<<endl;
    		}
    		break;
    	}
	    case 5:{
	    	int accountnum;
	    		double amount;
	    		cout<<"\t\t\t Enter account number to withdraw money :";
	    		cin>>accountnum;
	    		bankaccount* account = bank.findaccount(accountnum);
	    		if(account!=NULL){
	    			cout<<"\t\t\tEnter amount to withdraw :";
	    			cin>>amount;
	    			account -> withdraw(amount);
	    			cout<<"\t\t\t"<<amount<<" Withdrawn successfully"<<endl;

	    		}else{
	    			cout<<"\t\t\t Account not found"<<endl;
	    		}
	    		break;

	    }
	    case 6:{
	        exit(1);
	        break;
	    }
    }
    cout<<"\t\t\t Do you want to continue ?[Y/N]";
    cin>>opt;

    }while(opt =='Y' || opt =='y');
}
