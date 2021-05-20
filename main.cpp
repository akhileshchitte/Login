#include<iostream>
#include<istream>
#include<fstream>


using namespace std;
int main();
void login()
{
    int count;
    string user,pass,u,p;
    cout<<"please enter the following details"<<endl;
    cout<<"USERNAME :";
    cin>>user;
    cout<<"PASSWORD :";
    cin>>pass;

    ifstream input("database.txt");
    while(input>>u>>p)
    {
        if(u==user && p==pass)

        {
            count=1;
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\n Hello "<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
        main();
    }
}
void registr()
{

    string reguser,regpass,ru,rp;
    cout<<"Enter the username :";
    cin>>reguser;
    cout<<"\nEnter the password :";
    cin>>regpass;

    ofstream reg("database.txt",ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    cout<<"\nRegistration Sucessful\n";
    main();


}

void forgot()
{
    int ch;
    cout<<"Forgotten ? We're here for help\n";
    cout<<"1.Search your id by username"<<endl;
    cout<<"2.Search your id by password"<<endl;
    cout<<"3.Main menu"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int count=0;
            string searchuser,su,sp;
            cout<<"\nEnter your remembered username :";
            cin>>searchuser;

            ifstream searchu("database.txt");
            while(searchu>>su>>sp)
            {
                if(su==searchuser)
                {
                    count=1;
                }
            }
            searchu.close();
            if(count==1)
            {
                cout<<"\n\nHurray, account found\n";
                cout<<"\nYour password is "<<sp;
                cin.get();
                cin.get();

                main();
            }
            else
            {
                cout<<"\nSorry, Your userID is not found in our database\n";
                cout<<"\nPlease kindly contact your system administrator for more details \n";
                cin.get();
                cin.get();
                main();
            }
            break;
        }
        case 2:
        {
            int count=0;
            string searchpass,su2,sp2;
            cout<<"\nEnter the remembered password :";
            cin>>searchpass;

            ifstream searchp("database.txt");
            while(searchp>>su2>>sp2)
            {
                if(sp2==searchpass)
                {
                    count=1;
                }
            }
            searchp.close();
            if(count==1)
            {
                cout<<"\nYour password is found in the database \n";
                cout<<"\nYour Id is : "<<su2;
                cin.get();
                cin.get();
                main();

            }
            else
            {
                cout<<"Sorry, We cannot found your password in our database \n";
                cout<<"\nkindly contact your administrator for more information\n";
                cin.get();
                cin.get();
                main();
            }

            break;
        }

        case 3:
        {
            cin.get();
            main();
        }
        default:
            cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
            forgot();
    }
}
int main()
{
    int choice;
    cout<<"***********************************************************************\n\n";
    cout<<"                      Welcome to login page                               \n\n";
    cout<<"*******************        MENU        ********************************\n\n";
    cout<<"1.LOGIN\n";
    cout<<"2.REGISTER\n";
    cout<<"3.FORGOT PASSWORD (or) USERNAME\n";
    cout<<"4.Exit\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    cout<<endl;
    switch(choice)
    {
        case 1:
            login();
            break;
        case 2:
            registr();
            break;
        case 3:
            forgot();
            break;
        case 4:

            cout<<"Thanks for using this program\n";
            break;
        default:
            cout<<"Wrong Choice Entered\n"<<endl;
            main();
    }

}