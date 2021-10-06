#include "Sinhvien.h"
#include<iostream>
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
	cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
	
}
void Nguoi::nhap(){
/*	cout<<"Nhap ho ten :";
	getline(cin, hoten);
	cout<<"Nhap qq";
	getline(cin, qq);*/
	cout<<"nhap tuoi :";
	cin>> age;
	nhapns();
}
void Nguoi:: in(){
/*	cout<<hoten;
	cout<< qq;*/
	cout<<age<<endl;
	inns();
}
void Diem::nhapd(){
	cout<<"Nhap drl:";
	cin>>drl;
	cout<<"Nhap dtl:";
	cin>>dtl;
}
void Diem::ind(){
	cout<<drl<<endl;
	cout<<dtl<<endl;
}
void Sinhvien::nhaps(){
	nhap();
	nhapd();
	cout<<"Nhap ID:";
	cin>>ID;
//	cout<<"Nhap nganh:";
//	getline(cin, nganh);
}
void Sinhvien::ins(){
	in();
	ind();
	cout<<ID<<endl;
	//cout<<nganh<<endl;
}
