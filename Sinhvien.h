class Ngaysinh{
	private:
	    int ngay, thang, nam;
	public:
		void nhapns();
		void inns();
};
class Nguoi:public Ngaysinh{
	private:
		/*string hoten;
		string qq;*/
		int age;
	public:
		void nhap();
		void in();
};
class Diem {
	private:
	    float drl;
	    float dtl;
	public:
		void nhapd();
		void ind();
};
class Sinhvien:public Diem, public Nguoi{
	private:
		int ID;
		//string nganh;
	public:
	   void nhaps();
	   void ins();	
};
