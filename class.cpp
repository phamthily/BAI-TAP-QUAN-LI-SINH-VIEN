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
       void pressAnyKey();
       void sapxepdtl(List l);
       void sapxepten(List l);
       void SapXepTheoDRL(List l);
       void timkiemten(List l);
       void timkiemid(List l);
       void update(List l);
       void TimKiemSinhVienChungNganh(List l);
       void  addhead(List &l, Node *p);
       void addtail(List &l,Node *p);
       void themsv(List &l);
       void xoatheoten(List l);
       void xoatheoID(List l);
       void menu();
       void Menu();
       void SapXep(List l);
       void TimKiem(List l);
       void Xoa(List l);
       void deleteList(List &l);
       void DocFile(ifstream &filein, List &l);
       void GhiFile(ofstream &fileout,List l);
};
