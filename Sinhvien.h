#include<string.h> 
 #include<iostream>

using namespace std;
 
 class Ngaysinh{
	private:
	    int ngay, thang, nam;
	public:
		void nhapns();
		void inns();
};
class Nguoi:public Ngaysinh{
	private:
		string hoten;
		string qq;
		int age;
		bool gt;
	public:
		void nhap();
		void in();
		string getten();
};
class Diem {
	private:
	    float drl;
	    float dtl;
	public:
		void nhapd();
		void ind();
		 float getdrl();
		 float getdtl();
		 void xeploai();
	   
};
class Sinhvien:public Nguoi,public Diem{
	private:
		int ID;
		string nganh;
	public:
	   Sinhvien nhaps(Sinhvien &sv);
	   Sinhvien  ins(Sinhvien sv);
	   string getnganh();
	   void hoanvi(Sinhvien &sv1,Sinhvien &sv2);
	   int getid();
	   //friend Sinhvien nhapds(Sinhvien a[], int &n);
	   //friend Sinhvien inds(Sinhvien a[],int n);
	   
};
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
void Show(List l);
void showNode(Node* k);
void input(List &l);
void sapxepdtl(List l);
void sapxepten(List l);
void timkiemten(List l);
void timkiemid(List l);
void SapXepTheoDRL(List l);
void TimKiemSinhVienChungNganh(List l);
void  addhead(List &l, Node *p);
void addtail(List &l,Node *p);
void menu();
};


	
