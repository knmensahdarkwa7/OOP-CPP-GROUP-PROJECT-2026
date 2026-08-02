#include <iostream>

using namespace std;
void librarianDashboard(Librarian &lib){int choice;
do{
        cout<<"n\LIBRARIAN DASHBOARD"<<endl;

        cout<<"1.Add Book "<<endl;
        cout<<"2.Remove Book "<<endl;
        cout<<"3.Search Book "<<endl;
        cout<<"4.Issue Book "<<endl;
        cout<<"5.Return Book "<<endl;
        cout<<"6.Calculate Fine "<<endl;
        cout<<"7.View all Users"<<endl;
        cout<<"0.Exit"<<endl;
        cout<< " Enter Choice: ";
        cin>>choice;


}
while(choice!=0);
}

