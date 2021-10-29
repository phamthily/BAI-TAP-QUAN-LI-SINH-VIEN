#include "Sinhvien.h"
#include<iostream>
#include<string.h>

using namespace std;

void Ngaysinh:: nhapns(){
	cout<<"Nhap ngay :";
	cin>>ngay;
	cout<<"Nhap thang :";
	cin>>thang;
	cout<<"Nhap nam :";
	cin>>nam;
}
void Ngaysinh:: inns(){
	cout<<"Ngay sinh :"<<ngay<<"/"<<thang<<"/"<<nam<<endl;
	
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
	cout<<"Nhap gioi tinh( 0 Nam , 1 Nu) :";
	cin>>gt;

	
}
void Nguoi:: in(){
	cout<<"Ho va ten: "<<hoten<<endl;
	cout<<"Que quan:"<< qq<<endl;
	cout<<"Tuoi:"<<age<<endl;
	if(gt==0)
	   cout<<"Nam"<<endl;
	else
	   cout<<"Nu"<<endl;
}
void Diem::nhapd(){
	
	cout<<"Nhap drl:";
	cin>>drl;
	cout<<"Nhap dtl:";
	cin>>dtl;
}

void Diem::ind(){
	
	cout<<"Diem ren luyen: "<<drl<<endl;
	cout<<"Diem tich luy:"<<dtl<<endl;
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
	sv.inns();
	sv.ind();
	cout<<"ID :"<<sv.ID<<endl;
	cout<<"Nganh :"<<sv.nganh<<endl;
	return sv;
}
/*Sinhvien nhapds(Sinhvien a[],int &n){

	cout<<"Nhap so luong sinh vien :";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Nhap sinh vien thu :"<<i+1<<endl;
		
		a[i].nhaps();
	}
}
Sinhvien inds(Sinhvien a[],int n){
	
	for(int i=0;i<n;i++){
		cout<<"Thong tin sinh vien thu :"<<i+1<<endl;
        a[i].ins();
	}
}*/
void  List::timkiemten(List l){
	//Sinhvien x;
    string ten;
    fflush(stdin);
    cout<<"Nhap ten can tim :";
    getline(cin,ten);
    for(Node *p=l.head;p!=NULL;p=p->Next){
    	if((ten==p->data.getten())){
    	    ins(p->data);
    	    }
		else if(p==NULL)
		   	cout<<"danh sach rong!"<<endl;
		else 
		    cout<<"Khong tim thay sinh vien nao !"<<endl;
    	
    }
}
void  List::timkiemid(List l){
	//Sinhvien x;
    int id;
    
    cout<<"Nhap ID can tim :";
    cin>>id;
    for(Node *p=l.head;p!=NULL;p=p->Next){
    	if((id==p->data.getid())){
    	    ins(p->data);
    	    }
		else if(p==NULL)
		   	cout<<"danh sach rong!"<<endl;
		else 
		    cout<<"Khong tim thay sinh vien nao !"<<endl;
    	
    }
}
int Sinhvien:: getid(){
    return ID;	
}
float Diem::getdrl(){
	return drl;
}
float Diem::getdtl(){
	return dtl;
}
string Sinhvien::getnganh(){
	return nganh; 
}
string Nguoi::getten(){
	return hoten;
}
void Sinhvien::hoanvi(Sinhvien &sv1, Sinhvien &sv2){
	Sinhvien t=sv1;
             sv1=sv2;
             sv2=t;
}
void List::sapxepdtl(List l){
	for(Node *p=l.head;p!=NULL;p=p->Next){
	    for(Node *q=p->Next;q;q=q->Next){
		    if(p->data.getten()>q->data.getten()){
			    hoanvi(p->data,q->data);
			}
		}				
	}cout<<"Danh sach sinh vien da sap xep theo ho ten "<<endl;
     Show(l);
}
void List::sapxepten(List l){
	for(Node *p=l.head;p!=NULL;p=p->Next){
	    for(Node *q=p->Next;q;q=q->Next){
		    if(p->data.getdtl()>q->data.getdtl()){
			    hoanvi(p->data,q->data);
			}
		}				
	}cout<<"Danh sach sinh vien da sap xep theo diem tich luy "<<endl;
     Show(l);
}
void List::SapXepTheoDRL(List l){
	for(Node *p=l.head;p!=NULL;p=p->Next){
	    for(Node *q=p->Next;q;q=q->Next){
		    if(p->data.getdrl()<q->data.getdrl()){
			    hoanvi(p->data,q->data);
			}
		}				
	}cout<<"Danh sach sinh vien da sap xep theo diem ren luyen  "<<endl;
     Show(l);
}
void List::TimKiemSinhVienChungNganh(List l){
	string nganh;
    
    cout<<"Nhap nganh hoc can tim :";
    cin>>nganh;
    for(Node *p=l.head;p!=NULL;p=p->Next){
    	if((nganh==p->data.getnganh())){
    	    ins(p->data);
    	    }
		else if(p==NULL)
		   	cout<<"danh sach cua ban rong!"<<endl;
		else 
		    cout<<"Khong tim thay sinh vien nao cung nganh !"<<endl;
    	
    }
	
}
void Diem::xeploai() {
	if(drl>=90 && dtl>=3.2)
	    cout<<"Xep loai xuat sac ";
	else if(drl>=80 && dtl>=3.0)
	    cout<<"Xep loai gioi";
	else if(drl>=70 && dtl>=2.5)
	    cout<<"Xep loai kha ";
	else if(drl>=60 && dtl>=1.0)
	    cout<<"Xep loai trung binh";   
	else 
	    cout<<"Xep loai yeu";
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
void List:: input(List &l){
	Sinhvien x;
	int n;
	
	cout<<"nhap so luong sinh vien :";
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cout<<"Nhap sinh vien thu :"<<i<<endl;
	nhaps(x);
	Node *p=createNode(x);
	addtail(l,p);
}
}
void List::Show(List l){
	
	int n;
	int i=1;
	Sinhvien x;
	cout<<"DANH SACH SINH VIEN "<<endl;
	cout<<"******************************************"<<endl;
	for(Node *p=l.head;p!=NULL;p=p->Next){
		cout<<"Sinh vien thu :"<<i<<endl;
	ins(p->data);
	
	if(p!=l.tail)
	   cout<<"*------------------------------------"<<endl;
	   i++;
	}
	cout<<"*******************************************"<<endl;
}
void List:: showNode(Node* k){
	Sinhvien x;
	cout<<"===========================SV========================="<<endl;
	ins(x);
}
void List:: addhead(List &l, Node *p)
{
     if(l.head==NULL)
     {
          l.head=p;
          l.tail=l.head;
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
        p->Next=l.tail->Next;
        l.tail->Next=p;
        l.tail=p;
    }
}
void List:: menu(){
	List l;
	Sinhvien sv;
	int n;
	
	KhoitaoList(l);
	input(l);
	Show(l);
	sapxepdtl(l);
	sapxepten(l);
	timkiemten(l);
	timkiemid(l);
	SapXepTheoDRL(l);
	TimKiemSinhVienChungNganh(l);
	return ;
}



