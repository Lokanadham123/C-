#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class medicine
{
	char med[30];
	public:
		medicine(){ }
		void Adding_med();
		void See_med();
		void Searching_med();
		void deleting();
		void updating();
};                                      
void medicine::Adding_med()
{
	int n,i;
	cout<<"how many u want to enter : ";
	cin>>n;
	ofstream f1;
	f1.open("medi.txt",ios::app);
	for(i=0;i<n;i++)
	{
		cout<<"enter medicine : ";
		cin>>med;
		f1<<med<<endl;
	}
}
void medicine::See_med()
{
	ifstream f2;
	f2.open("medi.txt");
	string str;

		while(!f2.eof())
		{
			getline(f2,str);
			cout<<str<<endl;
		}
		f2.close();
}
void medicine::Searching_med()
{
	int z=0;
	string line,search;
	cin>>search;
	ifstream f3("medi.txt");
	if(f3.is_open())
	{
		while(!f3.eof())
		{
			getline(f3,line);
			if(search==line)
			{
				cout<<"Medicine is available"<<endl;
				z=1;
			}
			
		}
		if(z!=1)
		{
			cout<<"out of stock";
		}
		f3.close();
	}
}
void medicine::deleting()
{
	
	string line,del;
	cout<<"enter the name of the medicine which u want to delete : ";
	cin>>del;
	ifstream fin("medi.txt");
	ofstream fout("text.txt");
		while(!fin.eof())
		{
			getline(fin,line);
			if(del==line)
			{
				cout<<"Medicine is available in stock"<<" ("<<line<<")"<<" and deleted"<<endl;
			}
			else 
			fout<<line<<endl;
		}
		fin.close();
		fout.close();
		remove("medi.txt");
		rename("text.txt","medi.txt");
}
void medicine::updating()
{
	string line,update,up;
	cout<<"enter which medicine u want to update : ";
	cin>>update;
	ifstream fin("medi.txt");
	ofstream fout("text.txt");
		while(!fin.eof())
		{
			getline(fin,line);
			if(update==line)
			{
				cout<<"enter the medicine name : ";
				cin>>up;
				fout<<up<<endl;
				cout<<"Medicine is available"<<" ("<<line<<")"<<" and updated"<<endl;
			}
			else 
			fout<<line<<endl;
		}
		fin.close();
		fout.close();
		remove("medi.txt");
		rename("text.txt","medi.txt");
}
main()
{
	medicine o;
		int choose;
		cout<<"You want to add more medicines press 1"<<endl;
		cout<<"you want to see how many medicines are in the file press 2"<<endl;
		cout<<"you want to search medicine press 3"<<endl<<endl;
		cout<<"If you want to delete medicine press 4"<<endl;
		cout<<"If you want to update medicine name press 5"<<endl<<endl;
		cout<<"choice : ";
		cin>>choose;
		switch(choose)
		{
			case 1:
				o.Adding_med();
				break;
			case 2:
				o.See_med();
				break;
			case 3:
				o.Searching_med();
				break;
			case 4:
				o.deleting();
				break;
			case 5:
				o.updating();
				break;
			default:
				cout<<"choice not available"<<endl;
	
		}
}
