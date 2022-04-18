#include <iostream>
#include<fstream>
#include <string>
using namespace std;
int second_menu(int a){
	if (a==1){
			cout<<" <<<< SANDWICHES >>>>  \n";
			cout<<"   name          |  price |   time  |\n";
			cout<<"  _______________|________|_________|\n\n";
			cout<<" 1 double_berger |  85000 |  10 min |\n\n";
			cout<<" 2 ham_berger    |  80000 |  10 min |\n\n";
			cout<<" 3 chiz_berger   |  70000 |  10 min |\n\n";
			cout<<" 4 hot_doge      |  60000 |  10 min |\n";
			cout<<"  _______________|________|_________|\n";
	}else if (a==2){
			cout<<" <<<< PIZZA >>>> \n";
			cout<<"   name          |  price |   time  |\n";
			cout<<"  _______________|________|_________|\n\n";
			cout<<" 1 peprooni      | 90000  |  10 min |\n\n";
			cout<<" 2 sabzijat      | 50000  |  10 min |\n\n";
			cout<<" 3 mexican       | 40000  |  10 min |\n";
			cout<<"  _______________|________|_________|\n";
	}else if (a==3){
			cout<<" <<<<  DESER  >>>>  \n";
			cout<<"   name           | price |   time  |\n";
			cout<<"  ________________|_______|_________|\n\n";
			cout<<" 1 Coconut_pie    | 85000 |  10 min |\n\n";
			cout<<" 2 Chocolate_cake | 60000 |  10 min |\n\n";
			cout<<" 3 Apple_pie      | 50000 |  10 min |\n";
			cout<<"  ________________|_______|_________|\n";
	}
	return 0;
}

int first_menu(){
	system("cls");
	
	cout<< "\n <<<<<  Hi Welcom  >>>>> \n";
	
	cout<<" ____________________________________________________\n\n";
	
	cout<<" 1 SANDWICH   \n";
	
	cout<<" ____________________________________________________\n\n";
	
	cout<<" 2 PIZZA      \n";
	
	cout<<" ____________________________________________________\n\n";
	
	cout<<" 3 DESER      \n";
	
	cout<<" ____________________________________________________\n\n";
	return 0;
	
}

int orders(){
	string name ;
	cout<<"what is your name :";
	cin>> name ;
	first_menu();
	
	int number1,number2;
	
	cout<<"\n Wichone you want : ";
	
	cin>>number1;
	
	system("cls");
	
	second_menu(number1);
	
	cout <<"\n from the top wichone you want : ";
	int payed;
	cin>>number2;
	cout<<" ____________________________________________________\n\n";
	cout <<"for paying inter 1 :";
	cin>>payed;
	
	string foodsection[3]={"Sandwich ","Pizza    ","Deser    "};
	
	string foods[3][4]={
	{"double_berger  85000 10min ","ham_berger     80000 10min ","chiz_berger    70000 10min ","hot_doge       60000 10min "},
	{"peprooni       90000 10min ","sabzijat       50000 10min ","mexican        40000 10min ",""},
	{"Coconut_pie    85000 10min ","Chocolate_cake 60000 10min ","Apple_pie      50000 10min ",""}};
	
	
	string paying="not payed";
	if(payed==1){
			
		paying="payed    ";
	}

	fstream ofs("orddata.txt",ios::app);
	ofs<<name<<" " <<foodsection[number1-1]<<" "<< foods[number1-1][number2-1] <<" "<<paying<<"  "<<"not ready"<<endl;
	ofs.close();
	
	return 0;
}
void client_menu(){
	system("cls");
	cout<<"your name : ";
	
	string cname;
	
	cin>>cname;

	
	system("cls");
	int a=cname.length(),i=0;
	fstream myfile;
	
	myfile.open("orddata.txt",ios::in);
	string ch;
	
	cout<<"Ready:\n***\n";
	
	while (1) {
		getline(myfile,ch);
		if (myfile.eof())
			break;
			
		if (ch.find(cname)!= string::npos && ch.find("    ready")!=string::npos){
			cout << ch<<endl;
			cout<<"________________________________________________________________________\n\n";
		}

	}
	myfile.close();
	myfile.open("orddata.txt",ios::in);
	cout<<"Not Ready :\n***\n";
	while (1) {
		getline(myfile,ch);
		if (myfile.eof())
			break;
			
		if (ch.find(cname)!= string::npos && ch.find("not ready")!= string::npos){
			cout << ch<<endl;
			cout<<"________________________________________________________________________\n\n";
		}

	}
	myfile.close();
	
	

	
}
int manager(){
	system("cls");
	
	string data[100];
	
	fstream myfile;
	myfile.open("orddata.txt",ios::in);
	string ch;
	int a;
	cout<<"Ready:\n\n";
	int i=0;
	while (1) {
		
		getline(myfile,ch);
		
	
		if (myfile.eof()){
			break;
		}
		if (ch.find("    ready")!= string::npos){
			data[i]=ch;
			
			i++;		
			
			cout << ch<<endl;
			
			cout<<"________________________________________________________________________\n\n";
		}

	}
	myfile.close();
	
	
	fstream mfile;
	mfile.open("orddata.txt",ios::in);
	cout<<"Not Ready :\n\n";
	while (1) {

		getline(mfile,ch);
		
		if (mfile.eof())
			break;
			
		if (ch.find("not ready")!= string::npos){
			data[i]=ch;
			
			i++;		
			
			cout << ch<<endl;
			
			cout<<"________________________________________________________________________\n\n";
		}

	}
	mfile.close();
	
	
	string cname,fname;
	
	cout <<"if a food is ready enter name of prson and the food : ";
	
	cin>>cname;
	if(cname=="no"){
		return 0;
	}
	cin>>fname;
	int index;
	string sub_str="    ready";
	
//	clear data bace

	std::ofstream filee;
	filee.open("orddata.txt", std::ofstream::out | std::ofstream::trunc);
	filee.close();
	
//	new data on data bace
	fstream ofs("orddata.txt",ios::app);

	for (int j=0 ;j<=i;j++){
		
		size_t found = data[j].find(cname);
		
		size_t f = data[j].find(fname);
		
    	if (found != string::npos&& f != string::npos){
    		
    		if((index = data[j].find("not ready")) != string::npos) {   
    		
      			data[j] = data[j].replace (index, sub_str.length(), sub_str); 
			}
        }
        ofs<<data[j]<<endl;
	}
	ofs.close();	
}
int main(){
	int log;
	
	while (1){
		cout<<"\n_________________________________________________________________\n";
		cout << "\n\nenter the related number \n| manager_menu=0 |\n| client_menu=1  |\n| order=2        |\n| finish work =5 | : ";	
		cin >>log;
		system("cls");
		
		if (log == 0){
			int pas;
			cout<<"password : ";
			cin>>pas;
			if(pas==12){
			
				manager();
			}else{
				cout<<"wrong pass\n";
			}
			
		}else if (log == 1){
			client_menu();
			
		}else if(log ==2 ){
			orders();
			
		}else if(log == 5){
		
			int a;
			cout <<"Are You sure? yes=1 no=0 : ";
			cin>>a;
			if (a==1){
				break;
			}
		}else {
			cout <<"wrong page\n";
		}
				
	}
	cout <<"bye....";
	return 0;
		
}
