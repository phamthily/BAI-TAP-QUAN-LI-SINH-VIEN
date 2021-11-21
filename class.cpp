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
