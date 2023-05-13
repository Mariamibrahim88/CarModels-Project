#include <bits/stdc++.h>

using namespace std;

class car{
    public:
    int id , model,price;
    char name[20];
    char color[20];
};

void writeRecord(){
fstream f;
f.open("p1.txt",ios::out|ios::app);
car c;

if(f.is_open()){
char ch='Y';
do
{    
cout<<"Enter id : ";
cin>>c.id;
cout<<"Enter model: ";
cin>>c.model;
cout<<"Enter name: ";
cin>>c.name;
cout<<"Enter color: ";
cin>>c.color;
cout<<"Enter price: ";
cin>>c.price;
cout<<"Enter record again (Y/N) : ";
cin>>ch;
f.write((char*)&c,sizeof(c));
}while (ch=='Y');
f.close();
}
else{
    cout<<"cannot open file\n";
}
}
void readRecord(){
     car c;
     int id=0;
    
    ifstream in;
    in.open("p1.txt",ios::in);
     if(in.is_open()){
         
         cout<<"\t\t\t\t"<<"ID"<<"\t"<<setw(10)<<left<<" Name "<<setw(10)<<right<<"Model"<<setw(10)<<right<<" Color "<<setw(10)<<right<<" Price "<<endl;
         
         while (in.read((char*)&c,sizeof(c)))
         {

//            in.read((char*)&c,sizeof(c));
//            if(c.id!=id){
            	cout<<"\t\t\t\t"<<c.id<<"\t"<<setw(10)<<left<<c.name<<setw(10)<<right<<c.model<<setw(10)<<right<<c.color<<setw(10)<<right<<c.price<<endl;
			//}
			//id=c.id;
         }
         
          in.close();
     }else{
        cout<<"cannot open the specified file."<<endl;
     }

}

void searchName(){
	car c;
	char str[20];
    cout<<"Enter the name of car to search  : "; 
    cin>>str;
    bool found=false;
    
    ifstream in;
    in.open("p1.txt",ios::in);
     if(in.is_open()){
 
        while (!in.eof())
        {
            in.read((char*)&c,sizeof(c));
            if(strcmp(c.name,str)==0){           
                found=true;
                break;
            }
        		
           			
	}
	if(found==true){
		cout<<"\t\t\t\t"<<"ID"<<"\t"<<setw(10)<<left<<" Name "<<setw(10)<<right<<"Model"<<setw(10)<<right<<" Color "<<setw(10)<<right<<" Price "<<endl;
        cout<<"\t\t\t\t"<<c.id<<"\t"<<setw(10)<<left<<c.name<<setw(10)<<right<<c.model<<setw(10)<<right<<c.color<<setw(10)<<right<<c.price<<endl;
	}else{
		cout<<"Not found";
	}
}
				
}
	void searchId(){
		car c;
		int id;
    cout<<"Enter  id of car to search  : "; 
    cin>>id;
    bool found=false;
    
    ifstream in;
    in.open("p1.txt",ios::in);
     if(in.is_open()){
 
        while (!in.eof())
        {
            in.read((char*)&c,sizeof(c));
            if(c.id==id){
                found=true;
                break;
            }
            			
	}
	if(found==true){
		cout<<"\t\t\t\t"<<"ID"<<"\t"<<setw(10)<<left<<" Name "<<setw(10)<<right<<"Model"<<setw(10)<<right<<" Color "<<setw(10)<<right<<" Price "<<endl;
        cout<<"\t\t\t\t"<<c.id<<"\t"<<setw(10)<<left<<c.name<<setw(10)<<right<<c.model<<setw(10)<<right<<c.color<<setw(10)<<right<<c.price<<endl;
	}else{
		cout<<"Not found";
	}
}
}
void search (){
	char c;
	cout<<"I: id , N: name"<<endl;
	cout<<"Enter the type of operation you want to search : "<<	endl;
	cin>>c;
	switch (c){
		case 'I':
			searchId();
			break;
		case 'N':
			searchName();
			break;
			
	}
	
}

void updateByID(){
	fstream f;
	bool flag=false;
	car c;
	int id;
	cout<<"enter id of car"<<endl;
	cin>>id;
	f.open("p1.txt",ios::in|ios::out);
	if (f.is_open()) {
	while(!f.eof()){
		f.read((char*)&c,sizeof(c));
		if(c.id==id){
			cout<<"Enter new id to update : "<<" ";
			cin>>c.id;
			int curpos=f.tellg();
			int carsize=sizeof(c);
			f.seekp(curpos-carsize,ios::beg);
			f.write((char*)&c,sizeof(c));
			f.seekg(curpos-carsize,ios::beg);
			f.read((char*)&c,sizeof(c));
			cout<<"ID: "<<c.id<<"\n"<<"Name: "<<c.name<<"\n"<<"Color: "<<c.color<<"\n"<<"Price: "<<c.price<<"\n"<<"Model: "<<c.model<<endl;
			//cout<<c.id<<"\t"<<c.name<<"\t"<<c.color<<"\t"<<c.price<<"\t"<<c.model<<endl;
			flag =true;
			break;
		}
	
	}
	if(!flag){
		cout<<"not found this record";
	}
	
}		
}

void updateByName(){
	fstream f;
	bool flag=false;
	car c;
	int id;
	cout<<"enter id of record to update"<<endl;
	cin>>id;
	f.open("p1.txt",ios::in|ios::out);
	if (f.is_open()) {
	while(!f.eof()){
		f.read((char*)&c,sizeof(c));
		if(c.id==id){
			cout<<"Enter new name to update : "<<" ";
			cin>>c.name;
			int curpos=f.tellg();
			int carsize=sizeof(c);
			f.seekp(curpos-carsize,ios::beg);
			f.write((char*)&c,sizeof(c));
			f.seekg(curpos-carsize,ios::beg);
			f.read((char*)&c,sizeof(c));
			cout<<"ID: "<<c.id<<"\n"<<"Name: "<<c.name<<"\n"<<"Color: "<<c.color<<"\n"<<"Price: "<<c.price<<"\n"<<"Model: "<<c.model<<endl;
			//cout<<c.id<<"\t"<<c.name<<"\t"<<c.color<<"\t"<<c.price<<"\t"<<c.model<<endl;
			flag =true;
			break;
		}
	
	}
	if(!flag){
		cout<<"not found this record";
	}
	
}		
}

void updateByModel(){

	fstream f;
	bool flag=false;
	car c;
	int id;
	cout<<"enter id of record to update"<<endl;
	cin>>id;
	f.open("p1.txt",ios::in|ios::out);
	if (f.is_open()) {
	while(!f.eof()){
		f.read((char*)&c,sizeof(c));
		if(c.id==id){
			cout<<"Enter new model to update : "<<" ";
			cin>>c.model;
			int curpos=f.tellg();
			int carsize=sizeof(c);
			f.seekp(curpos-carsize,ios::beg);
			f.write((char*)&c,sizeof(c));
			f.seekg(curpos-carsize,ios::beg);
			f.read((char*)&c,sizeof(c));
			cout<<"ID: "<<c.id<<"\n"<<"Name: "<<c.name<<"\n"<<"Color: "<<c.color<<"\n"<<"Price: "<<c.price<<"\n"<<"Model: "<<c.model<<endl;
			//cout<<c.id<<"\t"<<c.name<<"\t"<<c.color<<"\t"<<c.price<<"\t"<<c.model<<endl;
			flag =true;
			break;
		}
	
	}
	if(!flag){
		cout<<"not found this record";
	}
	
}		
}



void updateByColor(){
	fstream f;
	bool flag=false;
	car c;
	int id;
	cout<<"enter id of record to update"<<endl;
	cin>>id;
	f.open("p1.txt",ios::in|ios::out);
	if (f.is_open()) {
	while(!f.eof()){
		f.read((char*)&c,sizeof(c));
		if(c.id==id){
			cout<<"Enter new color to update : "<<" ";
			cin>>c.color;
			int curpos=f.tellg();
			int carsize=sizeof(c);
			f.seekp(curpos-carsize,ios::beg);
			f.write((char*)&c,sizeof(c));
			f.seekg(curpos-carsize,ios::beg);
			f.read((char*)&c,sizeof(c));
			cout<<"ID: "<<c.id<<"\n"<<"Name: "<<c.name<<"\n"<<"Color: "<<c.color<<"\n"<<"Price: "<<c.price<<"\n"<<"Model: "<<c.model<<endl;
			//cout<<c.id<<"\t"<<c.name<<"\t"<<c.color<<"\t"<<c.price<<"\t"<<c.model<<endl;
			flag =true;
			break;
		}
	
	}
	if(!flag){
		cout<<"not found this record";
	}
	
}		
}

void updateByPrice(){
	fstream f;
	bool flag=false;
	car c;
	int id;
	cout<<"enter id of record to update"<<endl;
	cin>>id;
	f.open("p1.txt",ios::in|ios::out);
	if (f.is_open()) {
	while(!f.eof()){
		f.read((char*)&c,sizeof(c));
		if(c.id==id){
			cout<<"Enter new price to update : "<<" ";
			cin>>c.price;
			int curpos=f.tellg();
			int carsize=sizeof(c);
			f.seekp(curpos-carsize,ios::beg);
			f.write((char*)&c,sizeof(c));
			f.seekg(curpos-carsize,ios::beg);
			f.read((char*)&c,sizeof(c));
			cout<<"ID: "<<c.id<<"\n"<<"Name: "<<c.name<<"\n"<<"Color: "<<c.color<<"\n"<<"Price: "<<c.price<<"\n"<<"Model: "<<c.model<<endl;
			//cout<<c.id<<"\n"<<c.name<<"\n"<<c.color<<"\n"<<c.price<<"\n"<<c.model<<endl;
			flag =true;
			break;
		}
	
	}
	if(!flag){
		cout<<"not found this record";
	}
	
}		
}


void update (){
	char c;
	cout<<"I: id , N: name , M: model ,C: Color ,P: Price:  "<<endl;
	cout<<"Enter the type of operation you want to update : "<<	endl;
	cin>>c;
	switch (c){
		case 'I':
			updateByID();
			break;
		case 'N':
			updateByName();
			break;
		case'M':
			updateByModel();
			break;
		case'C':
			updateByColor();
			break;
		case'P':
			updateByPrice();
			break;		
			
	}
	}


void UpdateAll(){
	fstream f;
	bool flag=false;
	car c;
	int id;
	cout<<"enter id of record to update"<<endl;
	cin>>id;
	f.open("p1.txt",ios::in|ios::out);
	if (f.is_open()) {
	while(!f.eof()){
		f.read((char*)&c,sizeof(c));
		if(c.id==id){
			cout<<"Enter new id to update : "<<" ";
			cin>>c.id;
			cout<<"Enter new name to update : "<<" ";
			cin>>c.name;
			cout<<"Enter new model to update : "<<" ";
			cin>>c.model;
			cout<<"Enter new color to update : "<<" ";
			cin>>c.color;
			cout<<"Enter new price to update : "<<" ";
			cin>>c.price;
			int curpos=f.tellg();
			int carsize=sizeof(c);
			f.seekp(curpos-carsize,ios::beg);
			f.write((char*)&c,sizeof(c));
			f.seekg(curpos-carsize,ios::beg);
			f.read((char*)&c,sizeof(c));
			cout<<"ID: "<<c.id<<"\n"<<"Name: "<<c.name<<"\n"<<"Color: "<<c.color<<"\n"<<"Price: "<<c.price<<"\n"<<"Model: "<<c.model<<endl;
			flag =true;
			break;
		}
	
	}
	if(!flag){
		cout<<"not found this record";
	}
	
}		
}
	


void DeleteByName(){
	
	ifstream in ("p1.txt",ios::in);
	ofstream out ("p2.txt",ios::out);
	
	
	if (in.is_open())
	{
		car c;
		char str[20];
		//int id=0;
		cout<<"Enter name of car you want to delete : ";
		cin>>str;
		while(in.read((char*)&c,sizeof(c))){
		
			if(strcmp(str,c.name)!=0){
				//id=c.id;
				out.write((char*)&c,sizeof(c));
			}
		}
	}
	in.close();
	out.close();
	remove("p1.txt");
	rename("p2.txt","p1.txt");
}



void DeleteById(){
	
	ifstream in ("p1.txt",ios::in);
	ofstream out ("p2.txt",ios::out);
	
	
	if (in.is_open())
	{
		car c;
		int id;
		cout<<"Enter id of car you want to delete : ";
		cin>>id;
		while(in.read((char*)&c,sizeof(c))){
		
			if(id!=c.id){
				//id=c.id;
				out.write((char*)&c,sizeof(c));
			}
		}
	}
	in.close();
	out.close();
	remove("p1.txt");
	rename("p2.txt","p1.txt");
}


void Delete(){
	char c;
	cout<<"I: id , N: name: "<<endl;
	cout<<"Enter the type of operation you want to delete : "<<	endl;
	cin>>c;
	switch (c){
		case 'I':
			DeleteById();
			break;
		case 'N':
			DeleteByName();	
			
	}
	}

		
void display(){

cout<<"\t\t\t=======================Models Of Cars===================== \n";
     cout<<"\t\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
     cout<<"\t====================================================================================================\n";
     cout<<"\t\t1 : Add new model\t\t\t\t";cout<<"2 : Search for model  \n";
     cout<<"\t\t3 : See all model\t\t\t\t";cout<<"4 : Update  \n";
     cout<<"\t\t5 : Delete \t\t\t\t\t";cout<<"6 : Update All  \n";
     cout<<"\t====================================================================================================\n";
 }
int main(){
	car c;
	display();
	char a; 
	x:
	cout<<"Enter number for operation you want to execute : "<<endl;
	int num;
	cin>>num;
	
	switch(num){
		case 1:
			writeRecord();
			cout<<" Do you want to continue ?? (Y/N)";
			cin>>a;
			if(a=='Y'|| a=='y'){
				goto x;	
			}else{
				exit(0);
			}
			
			break;
		
			
		case 3:
			readRecord();
			cout<<" Do you want to continue ?? (Y/N)";
			cin>>a;
			if(a=='Y'|| a=='y'){
				goto x;	
			}else{
				exit(0);
			}
			break;
			
		case 2:
			search();
			cout<<" Do you want to continue ?? (Y/N)";
			cin>>a;
			if(a=='Y'|| a=='y'){
				goto x;	
			}else{
				exit(0);
			}
			break;
		case 4:
		  update();
		  cout<<" Do you want to continue ?? (Y/N)";
			cin>>a;
			if(a=='Y'|| a=='y'){
				goto x;	
			}else{
				exit(0);
			}	
		      break;
		  
		case 5:
		    Delete();
		    cout<<" Do you want to continue ?? (Y/N)";
			cin>>a;
			if(a=='Y'|| a=='y'){
				goto x;	
			}else{
				exit(0);
			}	
		  break;
		  
		case 6:
		    UpdateAll();
		    cout<<" Do you want to continue ?? (Y/N)";
			cin>>a;
			if(a=='Y'|| a=='y'){
				goto x;	
			}else{
				exit(0);
			}	
		  break; 	   	
			
		default:
		cout<<"Your Operation not exist , please try again "<<endl ;
		goto x;	 		
		
			
	}	
	
}

