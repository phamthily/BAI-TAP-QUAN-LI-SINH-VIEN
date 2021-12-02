#include<string.h> 
#include<iostream>
#include<fstream>
#include<iomanip>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
using namespace std;
 
 class Ngaysinh{
	private:
	    int ngay, thang, nam;
	public:
		Ngaysinh();
		~Ngaysinh();
		void nhapns();
		void inns();
		int getter_Ngay();
		int getter_Thang();
		int getter_Nam();
		void setter_Ngay( int ngay);
		void setter_Thang( int thang);
		void setter_Nam( int nam);
		void Docfilengaysinh(ifstream &filein , Ngaysinh &ns);
		void Ghifilengaysinh(ofstream &fileout,Ngaysinh ns);
};
int Ngaysinh:: getter_Ngay(){
		   return ngay;
}
void Ngaysinh:: setter_Ngay( int ngay){
		   this->ngay = ngay;
}
int Ngaysinh::getter_Thang(){
		   return thang;
}
void Ngaysinh:: setter_Thang(int thang){
		  this->thang = thang;
}
int Ngaysinh:: getter_Nam(){
		   return nam;
}
void Ngaysinh::setter_Nam(int nam){
		  this->nam = nam;
}
Ngaysinh::Ngaysinh(){
	ngay=thang=nam=0;
}
Ngaysinh::~Ngaysinh(){
    ngay=thang=nam=0;
}
class Nguoi:public Ngaysinh{
	private:
		string hoten;
		string qq;
		int age;
		string gt;
	public:
		Nguoi();
		~Nguoi();
		void nhap();
		void in();
		string getten();
		
		void Docfilenguoi(ifstream &filein , Nguoi  &ng);
		void Ghifilenguoi(ofstream &fileout ,Nguoi ng);
};
Nguoi::Nguoi(){
    this->hoten=" ";
	this->qq=" ";
	this->gt=" ";
	this->age=0;	
}
Nguoi::~Nguoi(){
	this->hoten=" ";
	this->qq=" ";
	this->gt=" ";
	this->age=0;
}

string Nguoi::getten(){
	return hoten;
}
class Diem {
	private:
	    float drl;
	    float dtl;
	public:
		Diem();
		~Diem();
		void nhapd();
		void ind();
		float getdrl();
		float getdtl();
		void xeploai();
	    void Docfilediem(ifstream &filein , Diem &d);
	    void Ghifilediem(ofstream &fileout,Diem d);
};
Diem::Diem(){
	this->drl=0;
	this->dtl=0;
}
Diem::~Diem(){
    this->drl=0;
	this->dtl=0;	
}
float Diem::getdrl(){
	return drl;
}
float Diem::getdtl(){
	return dtl;
}
class Sinhvien:public Nguoi,public Diem{
	private:
		int ID;
		string nganh;
	public:
		Sinhvien();
		~Sinhvien();
	   Sinhvien nhaps(Sinhvien &sv);
	   Sinhvien  ins(Sinhvien sv);
	   string getnganh();
	   void hoanvi(Sinhvien &sv1,Sinhvien &sv2);
	   int getid();
	   void Docfilesv(ifstream &filein , Sinhvien &Sv);
	   void Ghifilesv(ofstream &fileout,Sinhvien Sv);
};
string Sinhvien::getnganh(){
	return nganh; 
}
int Sinhvien:: getid(){
    return ID;	
}
Sinhvien::Sinhvien(){
	this->ID=0;
	this->nganh=" ";
}
Sinhvien::~Sinhvien(){
	this->ID=0;
	this->nganh=" ";
}
struct Node{
	Sinhvien data;
     struct Node *Next;
};
class List:public Sinhvien{
	private:
	   Node* head;
	   Node* tail;
	public:
       void KhoitaoList(List &l);
       Node* createNode(Sinhvien x);
       void  addhead(List &l, Node *p);
       void addtail(List &l,Node *p);
       void Show(List l);
       void showNode(Node* k);
       void input(List &l);
       void sapxepdtl(List l);
       void sapxepten(List l);
       void SapXepTheoDRL(List l);
       void SapXep(List l);
       void timkiemten(List l);
       void timkiemid(List l);
       void TimKiem(List l);
       void TimKiemSinhVienChungNganh(List l);
       void update(List l);
       void themsv(List &l);
       void xoatheoten(List l);
       void xoatheoID(List l);
       void Xoa(List l);
       void deleteList(List &l);
       void DocFile(ifstream &filein, List &l);
       void GhiFile(ofstream &fileout,List l);
       void pressAnyKey();
       void menu();
       void Menu();
};
void Ngaysinh:: nhapns(){
	cout<<"Nhap ngay :";
	cin>>ngay;
	cout<<"Nhap thang :";
	cin>>thang;
	cout<<"Nhap nam :";
	cin>>nam;
	int ngaymax;
	if (nam<0 || thang<0 || thang> 12 || ngay<0 || ngay> 31){
        	cout<<"Ngay sinh khong hop le. Moi ban nhap lai!!"<<endl;
		nhapns();
    	}else{
        	switch (thang){
            	case 1:case 3: case 5: case 7:case 8:case 10:case 12:
             	 ngaymax=31;
             	 break;
		case 2:
                if((nam%4==0 && nam%100!=0)||(nam%400==0))
                    ngaymax=29;
                else 
                    ngaymax=28;
                break;
		 case 4:case 6:case 9:case 11:
                ngaymax=30;
                break;
	 }
        if (ngay<=ngaymax){
            cout<<"Ngay hop le !"<<endl;
        }
}
void Ngaysinh:: inns(){
	cout<<setw(2)<<left<<ngay<<"/"<<setw(2)<<left<<thang<<"/"<<setw(18)<<left<<nam;
}
void Nguoi::nhap(){
	fflush(stdin);
	cout<<"Nhap ho ten :";
	getline(cin,hoten);
	fflush(stdin);
	cout<<"Nhap que quan :";
	getline(cin,qq);
	cout<<"Nhap tuoi :";
	cin>>age;
	cout<<"Nhap gioi tinh :";
	fflush(stdin);
	getline(cin,gt);

	
}
void Nguoi:: in(){
		cout<<setw(30)<<left<<hoten<<setw(21)<<left<<qq<<setw(16)<<left<<gt<<setw(12)<<left<<age	;inns();
}
void Diem::nhapd(){
	
	cout<<"Nhap drl:";
	cin>>drl;
	cout<<"Nhap dtl:";
	cin>>dtl;
}

void Diem::ind(){
   cout<<setw(23)<<left<<drl<<setw(17)<<left<<dtl;
}
Sinhvien Sinhvien::nhaps(Sinhvien &sv){
	
	sv.nhap();
	sv.nhapns();
	sv.nhapd();
	cout<<"Nhap ID:";
	cin>>sv.ID;
	fflush(stdin);
	cout<<"Nhap nganh:";
    getline(cin,sv.nganh);
    return sv;
}
Sinhvien Sinhvien::ins(Sinhvien sv){
	sv.in();
	sv.ind();
	cout<<setw(10)<<left<<sv.ID<<setw(20)<<left<<sv.nganh;
	return sv;
}
void List::KhoitaoList(List &l){
	l.head=NULL;
	l.tail=NULL;
}
Node* List:: createNode(Sinhvien v){
	Node* p=new Node;
	if(p==NULL){
		cout<<"khong the tao them ";
		return 0;
	}
	p->data = v;
    p->Next = NULL;
    return p;
	    
}
void List:: addhead(List &l, Node *p)
{
     if(l.head==NULL)
     {
          l.head=p;
          l.tail=p;
     }
     else
     {
          p->Next=l.head;
          l.head=p;
     }
}
void List:: addtail(List &l,Node *p)
{
    if(l.tail==NULL)
    addhead(l,p);
    else
    {
        l.tail->Next=p;
        l.tail=p;
    }
}
void List:: input(List &l){
	Sinhvien x;
	int n;
	
	cout<<"nhap so luong sinh vien :";
	cin>>n;
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<endl;
		cout<<"Nhap sinh vien thu :"<<i<<endl;
		cout<<endl<<"************************"<<endl;
	nhaps(x);
	Node *p=createNode(x);
	addtail(l,p);
    }
}

void  List::timkiemten(List l){
	int d=0,i=1;
	Node *p=l.head;
    string ten;
    
    if(p==NULL)
        cout<<"Danh sach rong!";
    else{
    fflush(stdin);
    cout<<"Nhap ten can tim :";
    getline(cin,ten); 
    for(Node *p=l.head;p!=NULL;p=p->Next){
    	if((ten==p->data.getten())){
    		showNode(p);
    	   cout<<setw(4)<<left<<i;ins(p->data);i++;
    	    
    	    d++;
        }
	}
	if(d==0) {
		cout<<"Khong tim thay sinh vien nao !"<<endl;
        }
    }
}
void  List::timkiemid(List l){
	
    int id,i=1;
    Node *p=l.head;
    
    int d=0;
    if(p==NULL)
        cout<<"danh sach rong!";
    else{
	cout<<"Nhap ID can tim  :";
    cin>>id;
    for(Node *p=l.head;p!=NULL;p=p->Next){
    	if(id==p->data.getid()){
    		showNode(p);
    	   cout<<setw(4)<<left<<i;ins(p->data);i++;
    	    
    	    d++;
    	    }
	}
    if(d==0) {
		
		    cout<<"Khong tim thay sinh vien nao !"<<endl;
        }
    }
}
void List::TimKiemSinhVienChungNganh(List l){
	string Nganh;
	int i=1;
	Node*p=l.head;
	int dem=0;
    if(p==NULL)
	   	cout<<"danh sach rong!"<<endl;
	else{
	fflush(stdin);
    cout<<"Nhap nganh hoc can tim :";
    getline(cin,Nganh);
    for(Node *p=l.head;p!=NULL;p=p->Next){
    	if((Nganh==p->data.getnganh())){
    	     showNode(p);
    	     cout<<setw(4)<<left<<i;ins(p->data);
    	    }
    	    dem++;
    	    i++;
		} 
		
		if(dem==0){
	    cout<<"Khong tim thay sinh vien nao !"<<endl;
   		}
   	}
}

void List::update(List l){
	
	Node*p=l.head;
    int id;
    int d=0;
    if(p==NULL)
        cout<<"Danh sach rong!";
    else{
	
    cout<<"Nhap ID can tim de sua thong tin :";
    cin>>id;
    for(Node *p=l.head;p!=NULL;p=p->Next){
    	if((id==p->data.getid())){
    	   nhaps(p->data) ;
    	   Show(l);
    	   d++;
    	    }
		}
    if(d==0) {
		
		    cout<<"Khong tim thay sinh vien nao !"<<endl;
        }
	}
}
void List:: themsv(List &l){
    int n;
	Sinhvien sv;
	cout<<endl;
	cout<<"Nhap thong tin sinh vien can them :"<<endl;
	nhaps(sv);
    Node* p=createNode(sv);
	addtail(l,p);
	cout<<"Danh sach sinh vien sau khi them:"<<endl;
	Show(l);
	cout<<endl;		
}


void Sinhvien::hoanvi(Sinhvien &sv1, Sinhvien &sv2){
	Sinhvien t=sv1;
             sv1=sv2;
             sv2=t;
}
void List::sapxepten(List l){
    Node* p=l.head;
    if(p==NULL)
     	cout<<"Danh sach rong!";
    else{
	
	for(Node *p=l.head;p!=NULL;p=p->Next){
	    for(Node *q=p->Next;q!=NULL;q=q->Next){
		    if(p->data.getten() > q->data.getten()){
			    hoanvi(p->data,q->data);
			}
		}				
	}
     Show(l);}
     
}
void List::sapxepdtl(List l){
	Node*p=l.head;
	if(p==NULL)
	    cout<<"Danh sach rong";
	else{
	
	for(Node *p=l.head;p!=NULL;p=p->Next){
	    for(Node *q=p->Next;q!=NULL;q=q->Next){
		    if(p->data.getdtl() < q->data.getdtl()){
			    hoanvi(p->data,q->data);
			}
		}				
	}cout<<"Danh sach sinh vien da sap xep theo diem tich luy "<<endl;
     Show(l);
     }
}
void List::SapXepTheoDRL(List l){
	Node*p=l.head;
	if(p==NULL)
       cout<<"Danh sach rong!";
	else{
	
	for(Node *p=l.head;p!=NULL;p=p->Next){
	    for(Node *q=p->Next;q;q=q->Next){
		    if(p->data.getdrl()<q->data.getdrl()){
			    hoanvi(p->data,q->data);
			}
		}				
	} 
	 cout<<"Danh sach sinh vien da sap xep theo diem ren luyen  "<<endl;
     Show(l);}
}



void List::xoatheoID(List l){
	int id;
	
	Node *pDel = l.head;
	 if(pDel == NULL){
		 cout <<"Danh sach rong!";
	 }else{
	 	cout <<"Nhap ID sinh vien can xoa:";
	    cin >>id;
		 Node *pPre = NULL;
		 while (pDel != NULL){
			 if(pDel->data.getid() == id){
				 break;
			 }
			 pPre =pDel;
			 pDel =pDel->Next;
		 }
		 if(pDel == NULL){
			 cout <<"Khong tim thay du lieu !"<<endl;
		 }else{
			 if(pDel == l.head){
				 l.head= l.head->Next;
				 pDel->Next= NULL;
				 delete pDel;
				 pDel = NULL;
			 }
			 else{
				 pPre->Next=pDel->Next;
				 pDel->Next=NULL;
				 delete pDel;
				 pDel =NULL;
			 }
		 }
	 cout <<"Danh sach sau khi xoa"<<endl;
	 Show(l);
	 
	 }
	 
	 	
}
				
void List::xoatheoten(List l){
	string ten;
    
     Node *pDel = l.head;
	 if(pDel == NULL){
		 cout <<"Danh sach rong!";
	 }else{
	 	fflush(stdin);
        cout<<"Nhap ten can tim :";
        getline(cin,ten);
		 Node *pPre = NULL;
		 while (pDel != NULL){
			 if(pDel->data.getten() == ten){
				 break;
			 }
			 pPre =pDel;
			 pDel =pDel->Next;
		 }
		 if(pDel == NULL){
			 cout <<"Khong tim thay du lieu !";
		 }else{
			 if(pDel == l.head){
				 l.head= l.head->Next;
				 pDel->Next= NULL;
				 delete pDel;
				 pDel = NULL;
			 }
			 else{
				 pPre->Next=pDel->Next;
				 pDel->Next=NULL;
				 delete pDel;
				 pDel =NULL;
			 }
		 }
	 cout <<"Danh sach sau khi xoa"<<endl;
	 Show(l);
	 
	 }   
}
void Ngaysinh::Docfilengaysinh(ifstream &filein , Ngaysinh &ns){
	int ngay;
	filein>>ns.ngay;
	filein.ignore(1);
	int thang;
	filein>>ns.thang;
	filein.ignore(1);
	int nam;
	filein>>ns.nam;

}
void Ngaysinh::Ghifilengaysinh(ofstream &fileout,Ngaysinh ns){
	fileout<<setw(2)<<left <<ns.ngay<<"/";
	
	fileout<<setw(2)<<left<<ns.thang<<"/";

	fileout<<setw(4)<<left<<ns.nam<<"|";
}
void Nguoi::Docfilenguoi(ifstream &filein , Nguoi  &ng){
	getline(filein,ng.hoten,',');
	getline(filein,ng.qq,',');
	filein>>ng.age;
	filein.ignore(2);
	getline(filein,ng.gt,',');
	Docfilengaysinh(filein,ng);
}
void Nguoi::Ghifilenguoi(ofstream &fileout, Nguoi ng){
	fileout<<"|"<<setw(23)<<left << ng.hoten << "|";
	fileout<<setw(12)<<right << ng.qq <<"|" ;
	fileout<<setw(7)<<right<< ng.age <<"|" ;
	fileout<<setw(10)<<right<<ng.gt <<"|";
	Ghifilengaysinh(fileout, ng);
}
void Diem::Docfilediem(ifstream &filein , Diem &d){
	float drl;
	filein>>d.drl;
	filein.ignore(2);
	float dtl;
	filein>>d.dtl;
}
void Diem::Ghifilediem(ofstream &fileout, Diem d){
	fileout <<setw(5)<<right<<d.drl<<"|" ;
	fileout<<setw(5)<<right<<d.dtl<<"|";
}
void Sinhvien::Docfilesv(ifstream &filein , Sinhvien &Sv){	
	Docfilenguoi(filein,Sv);
	filein.ignore(2);
    Docfilediem(filein,Sv);
    filein.ignore(2);
    int ID;
    filein>>Sv.ID;
    filein.ignore(2);
    getline(filein,Sv.nganh,'.');
    string t;
    getline(filein,t);	
}
void Sinhvien::Ghifilesv(ofstream &fileout, Sinhvien Sv){
	Ghifilenguoi(fileout, Sv);
	Ghifilediem(fileout, Sv);
	fileout <<setw(5)<<right<< Sv.ID <<"|" <<setw(9)<<Sv.nganh<<"|";
	
}
void List::DocFile(ifstream &filein, List &l){
	while(!filein.eof() ){
	     Sinhvien sv;
		 Docfilesv(filein, sv);
		 Node *p=createNode(sv);
		 addtail(l,p);
		
		 }	 
	}	
void List::GhiFile(ofstream &fileout, List l){
	fileout<<"\n";
	fileout<<setw(56)<<"DANH SACH SINH VIEN"<<"\n";
	fileout<<" ----------------------------------------------------------------------------------------------"<<"\n";
   fileout<<"|"<<setw(23)<<left<<"     Ho va Ten "<<"|"<<setw(12)<<left <<"  Que Quan "<<"|"
	<<setw(7)<<left <<"  Tuoi"<<"|"<<setw(10)<<left <<"Gioi Tinh"<<"|"<<setw(10)<<"Ngay sinh"
			<<"|"<<setw(5)<<right<<" DRL "<<"|"<<setw(5)<<right<<" DTL "<<"|"<<setw(5)<<right
			<<"ID  "<<"|"<<setw(9)<<right<<" Nganh  " <<"|"<<"\n";
	fileout<<" ----------------------------------------------------------------------------------------------"<<"\n";
	for(Node *p=l.head;p!=NULL;p=p->Next){
		
		Ghifilesv(fileout, p->data);
		fileout<<"\n";
		fileout<<" ----------------------------------------------------------------------------------------------"<<"\n";
		//fileout<<endl;
		
			}
		
	}
	void List::Show(List l){
	int n;
	int i=1;
	Sinhvien x;
	cout<<setw(100)<<"DANH SACH SINH VIEN "<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<left<<"STT"<<setw(30)<<left<<"Ho va ten"<<setw(17)<<left<<"Que quan"<<setw(18)<<left<<"Gioi tinh"<<setw(14)<<left<<"Tuoi"<<setw(19)<<left<<"Ngay sinh"<<setw(23)<<left<<"Diem ren luyen"<<setw(22)<<left<<"Diem tich luy"<<setw(11)<<left<<"ID"<<setw(21)<<left<<"Nganh"<<endl;
	cout<<"****************************************************************************************************************************************************************************"<<endl;
	for(Node *p=l.head;p!=NULL;p=p->Next){
	     cout<<setw(4)<<left<<i;ins(p->data);
	     cout<<endl;
	   i++;
	}

	cout<<"****************************************************************************************************************************************************************************"<<endl;

}
void List:: showNode(Node* k){
	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<setw(4)<<left<<"STT"<<setw(30)<<left<<"Ho va ten"<<setw(17)<<left<<"Que quan"<<setw(18)<<left<<"Gioi tinh"<<setw(14)<<left<<"Tuoi"<<setw(19)<<left<<"Ngay sinh"<<setw(23)<<left<<"Diem ren luyen"<<setw(22)<<left<<"Diem tich luy"<<setw(11)<<left<<"ID"<<setw(21)<<left<<"Nganh"<<endl;
	cout<<"****************************************************************************************************************************************************************************"<<endl;
	

}

void List::deleteList(List &l){
	Node *p=NULL;
	while(l.head!=NULL){
		p=l.head;
		l.head=l.head->Next;
		delete p;
	}
}
void List::pressAnyKey(){
    cout << "\n\nBam phim bat ky de tiep tuc...";
     getch();
     system("cls");
   
}
void List::SapXep(List l){
	
	int t1=1	,c;
	while(t1){
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(110)<<right<<"|                   MENU SAP XEP                |"<<endl;
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(110)<<right<<"|                                               |"<<endl;
		cout<<setw(110)<<right<<"|   1. Sap xep sinh vien theo ten.              |"<<endl;
		cout<<setw(110)<<right<<"|   2. Sap xep sinh vien theo diem tich luy.    |"<<endl;
		cout<<setw(110)<<right<<"|   3. Sap xep sinh vien theo diem ren luyen.   |"<<endl;
		cout<<setw(110)<<right<<"|                                               |"<<endl;
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(75)<<right<<"Nhap lua chon:";
		cin>>c;
		switch(c){
			case 1:
			cout<<"\n1 .Danh sach sinh vien sap xep sinh vien theo ten "<<endl;
            	sapxepten(l);
            	pressAnyKey();
                break;
			case 2:
            	cout<<"\n2. Danh sach sinh vien sap xep sinh vien theo diem tich luy. "<<endl;
            	sapxepdtl(l);
            	pressAnyKey();
                break;
			case 3:
				cout<<"\n3. Sap xep sinh vien theo diem ren luyen."<<endl;
            	SapXepTheoDRL(l); 
            	pressAnyKey();
            	break;
            case 0:
                cout << "\nBan da chon thoat tuy chon!";
                getch();
                return ;
			default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;			
		}
	}
	
}
void List::TimKiem(List l){
	int t1=1	,c;
	Node*p=l.head;
	while(t1){
		cout <<"\n\n";
cout<<setw(94)<<right<<"		     @@@@@@@@@@*              "<<"\n";  
cout<<setw(100)<<right<<"           @@& %@,    ,@@,           "<<"\n";     
cout<<setw(100)<<right<<"          @@, ,         @@           "<<"\n";     
cout<<setw(100)<<right<<"          @@*           @@           "<<"\n";     
cout<<setw(100)<<right<<"           @@@        #@@            "<<"\n";     
cout<<setw(100)<<right<<"              @@@@@@@@  @@@@@        "<<"\n";      
cout<<setw(100)<<right<<"                         @@@@@#      "<<"\n";     
cout<<setw(100)<<right<<"                           *@@@#     "<<"\n";  
cout<<"\n";
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(110)<<right<<"|                   MENU TIM KIEM               |"<<endl;
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(110)<<right<<"|                                               |"<<endl;
		cout<<setw(110)<<right<<"|   1. Tim kiem sinh vien theo ten.             |"<<endl;
		cout<<setw(110)<<right<<"|   2. Tim kiem sinh vien theo ID.              |"<<endl;
		cout<<setw(110)<<right<<"|   3. Tim kiem sinh vien chung nganh.          |"<<endl;
		cout<<setw(110)<<right<<"|   0. Thoat                                    |"<<endl;
		cout<<setw(110)<<right<<"|                                               |"<<endl;
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(75)<<right<<"Nhap lua chon:";
		cin>>c;
		switch(c){
			case 1:
            	cout<<"\n1. Tim kiem sinh vien theo ten.   "<<endl;	
                timkiemten(l);
            	pressAnyKey();
                break;
            case 2:
            	cout<<"\n2. Tim kiem sinh vien theo ID. "<<endl;
                timkiemid(l);
                
            	pressAnyKey();
                break;
			case 3:
            	cout<<"\n3. Tim kiem sinh vien chung nganh"<<endl;	
          		TimKiemSinhVienChungNganh(l);	
            	
            	pressAnyKey();
            	break;
            case 0:
                cout << "\nBan da chon thoat tuy chon!";
                getch();
                return ;
			default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;			
		}
	}
	
}
void List::Xoa(List l){
	int t1=1	,c;
	Node*p=l.head;
	while(t1){
		
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(110)<<right<<"|                    MENU XOA                   |"<<endl;
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(110)<<right<<"|                                               |"<<endl;
		cout<<setw(110)<<right<<"|   1. Xoa sinh vien theo ten.                  |"<<endl;
		cout<<setw(110)<<right<<"|   2. Xoa sinh vien theo ID.                   |"<<endl;
		cout<<setw(110)<<right<<"|   0. Thoat                                    |"<<endl;
		cout<<setw(110)<<right<<"|                                               |"<<endl;
		cout<<setw(110)<<right<<"-------------------------------------------------"<<endl;
		cout<<setw(75)<<right<<"Nhap lua chon:";
		cin>>c;
		switch(c){
			case 1:
            	cout<<"\n1.	Xoa sinh vien theo ten.   "<<endl;	
               	xoatheoten(l);
            	pressAnyKey();
                break;
            case 2:
            	cout<<"\n2. Xoa	sinh vien theo ID. "<<endl;	
               	xoatheoID(l);
            	pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat tuy chon!";
                getch();
                return ;
			default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;			
		}
	}
}

void List:: menu(){
	List l;
	Sinhvien sv;
	Node*p=l.head;
	KhoitaoList(l);
	ifstream filein;
	ofstream fileout;
	filein.open("SINHVIEN.TXT",ios::in);
    fileout.open("SINHVIEN1.TXT",ios::out);
		int key,t=1;
	while(t){ 
		system("cls");
		cout <<"\n\n"  ;  
cout<<setw(130)<<right<<"        @@@@@@.       @@@@@@                  @@@@@@  @@@@@@                 "<<"\n";            
cout<<setw(130)<<right<<"      /@@@@@,       @@@@@@                  @@@@@@  @@@@@@                   "<<"\n";         
cout<<setw(130)<<right<<"      @@@@@,       *@@@@@                  @@@@@@  &@@@@@                    "<<"\n" ;          
cout<<setw(130)<<right<<"     @@@@@@@@@@@@@@@@@@@     @@@@@@@@@@   ,@@@@@   @@@@@    @@@@@@@@@@       "<<"\n";      
cout<<setw(130)<<right<<"    @@@@@@@@@@@@@@@@@@@   @@@@@   @@@@@#  @@@@@   @@@@@  /@@@@@@@@@@@@@      "<<"\n";        
cout<<setw(130)<<right<<"   @@@@@@        @@@@@@  @@@@@@@@@@@@@@  @@@@@   @@@@@  @@@@@     @@@@@      "<<"\n";       
cout<<setw(130)<<right<<"  @@@@@@        @@@@@@  @@@@@           @@@@@   @@@@@  @@@@@@    @@@@@       "<<"\n";      
cout<<setw(130)<<right<<" @@@@@@        @@@@@@   @@@@@@@@@@@@.  @@@@@   @@@@@.  /@@@@@@@@@@@@         "<<"\n";      
cout<<setw(130)<<right<<"@@@@@#       @@@@@@      @@@@@@@@.   @@@@@@  @@@@@@     (@@@@@@*             "<<"\n";        
 cout <<"\n\n"  ;                                                                                       
        cout <<setw(105)<<right<<"CHUONG TRINH QUAN LY SINH VIEN C++\n";
        cout <<setw(115)<<right<< "------------------------------------------------------\n";
        cout <<setw(115)<<right<< "|                         MENU                       |\n";
        cout <<setw(115)<<right<< "------------------------------------------------------\n";
        cout <<setw(115)<<right<< "**                                                  **\n";
        cout <<setw(115)<<right<< "**  1. Nhap danh sach sinh vien.                    **\n";
        cout <<setw(115)<<right<< "**  2. Sap xep sinh vien.                           **\n";
        cout <<setw(115)<<right<< "**  3. Tim kiem sinh vien.                          **\n";
        cout <<setw(115)<<right<< "**  4. Them mot sinh vien vao danh sach.            **\n";
        cout <<setw(115)<<right<< "**  5. Cap nhat sinh vien.                          **\n";
        cout <<setw(115)<<right<< "**  6. Xoa sinh vien.                               **\n";
        cout <<setw(112)<<right<< "**  7. Hien thi danh sach cac sinh vien.	        **\n";
        cout <<setw(112)<<right<< "**  8. Doc file sinh vien.      	                **\n";
        cout <<setw(108)<<right<< "**  9. Ghi danh sach sinh vien vao file txt.	**\n";
        cout <<setw(115)<<right<< "**  0. Thoat.                                       **\n";
        cout <<setw(115)<<right<< "**                                                  **\n";
        cout <<setw(115)<<right<< "******************************************************\n";
        cout <<setw(75)<<right<< "Nhap tuy chon: ";
        fflush(stdin);
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1.Nhap danh sach sinh vien."<<endl;
                input(l);
                cout<<"Nhap danh sach thanh cong. "<<endl;
                Show(l);
                system("pause"); // lenh dung man hinh, thay cho press anykey
                break;
            case 2:
            	cout<<"\n2.Sap xep sinh vien."<<endl;
            	SapXep(l);
            	pressAnyKey();
                break;
          case 3:
            	cout<<"\n3.Tim kiem sinh vien."<<endl;
            	TimKiem(l);
            	pressAnyKey();
                break;
            case 4:
                cout<<"\n4. Them mot sinh vien vao danh sach. "<<endl;
                if(p == NULL){
            		cout <<"Danh sach hien dang rong!"<<endl;
            		themsv(l);
            	}
				else{
            		themsv(l);
				}
            	pressAnyKey();
                break;
            case 5:
            	cout<<"\n5. Cap nhat sinh vien."<<endl;
                update(l);	
            	pressAnyKey();
                break;
		  case 6:
				cout<<"\n6. Xoa sinh vien."<<endl;
            	Xoa(l);
            	pressAnyKey();
            	break;
            case 7:
            	cout<<"\n7. Hien thi danh sach sinh vien. "<<endl;
            	if(p == NULL){
            		cout<<"Danh sach cua ban dang rong! "<<endl;
            		
            	}
            	else{	
            		Show(l);
            	}		
            	pressAnyKey();
            	break;
             case 8:
            	cout<<"\n8. Doc file sinh vien tu file txt."<<endl;
				DocFile(filein,l);
				Show(l);
            	pressAnyKey();
            	break;
            case 9:
                cout<<"\n9. Ghi file sinh vien."<<endl;
                GhiFile(fileout,l);
                fileout.close();
                cout<<"Ghi file thanh cong";
            	pressAnyKey();
            	break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return ;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
    
filein.close();

}

int main(){
	system("color b0");

    List l;
    l.menu();
	system("pause");
	return 0;
}

