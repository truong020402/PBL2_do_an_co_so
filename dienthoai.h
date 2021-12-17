#include<iostream>
#include<string.h>
#include<iomanip>//thư viện của setw()
#include<cstring>//thư viện của strcpy()
#include<conio.h>//thư viên của getch()
#include<cctype>
#define MAX 100


using namespace std;


class Dienthoai
{
    protected:
       int ma_dt=0;
       char ten_dt[50]={0};
       char hang_dt[50]={0};
       int gia_tien=0;
       int so_luong=0;
    public:
        Dienthoai();
        void setSoLuong(int SL);
        int getSoLuong();
        void setGiaTien(int gia_tien);
        int getGiaTien();
        void NhapThongTinDienThoai(Dienthoai &dt, int ma_dt);
        void NhapDT(Dienthoai a[], int ma_dt, int n);
        void CapNhatThongTinDienThoai(Dienthoai &dt);
        void CapNhatDienThoaiTheoMa(Dienthoai a[], int ma_dt, int n);
         int XoaTheoMADT(Dienthoai a[], int ma_dt, int n);
        void ShowDienThoai(Dienthoai a[], int n);
        void TimKiemDienThoaiTheoTen(Dienthoai a[],char ten_dt[], int n);
        void ShowHoaDonDT(Dienthoai a[], int n);
        void XuatHoaDonTheoMaDT(Dienthoai a[], int ma_dt,int so_luong, int n);
        void Show1DT(Dienthoai a[], int ma_dt, int n);
         int MaDTLonNhat (Dienthoai a[], int n);
         int DocFile1(Dienthoai a[], char fileName[]);
         int DocFile2(Dienthoai a[], char fileName[]);
        void GhiFile(Dienthoai a[], int n, char fileName[]);
        void inra_(int n);
        void pressAnyKey();
        void MENU();
        ~Dienthoai();

};
Dienthoai :: Dienthoai()
{ 

}
Dienthoai :: ~Dienthoai()
{

}
void Dienthoai :: setSoLuong(int so_luong)
{
    this->so_luong+=so_luong;
}
int Dienthoai ::  getSoLuong()
{
    return so_luong;
}
void Dienthoai :: setGiaTien(int gia_tien)
{
    this->gia_tien=gia_tien;
}
int Dienthoai :: getGiaTien()
{
    return gia_tien;
}
void Dienthoai ::    inra_(int n)
{
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
}
void Dienthoai :: pressAnyKey()
{
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
void Dienthoai :: NhapThongTinDienThoai(Dienthoai &dt, int ma_dt)
{
   cout<<endl<<"Nhap ten dien thoai: ";
   fflush(stdin);
   gets(dt.ten_dt);
   cout<<"Nhap hang dien thoai: ";
   fflush(stdin);
   gets(dt.hang_dt);
   cout<<"Nhap gia dien thoai: ";
   cin>>dt.gia_tien;
   cout<<"Nhap so luong: ";
   cin>>dt.so_luong;
   dt.ma_dt = ma_dt;
}

void Dienthoai :: NhapDT(Dienthoai a[], int ma_dt, int n) {
    inra_(40);
    cout<<"Nhap dien thoai thu: "<<n+1;
    NhapThongTinDienThoai(a[n], ma_dt);
    inra_(40);
}
void Dienthoai :: CapNhatThongTinDienThoai(Dienthoai &dt)
{
   cout<<endl<<"Nhap ten dien thoai: ";
   fflush(stdin);
   gets(dt.ten_dt);
   cout<<"Nhap hang dien thoai: ";
   fflush(stdin);
   gets(dt.hang_dt);
   cout<<"Nhap gia tien dien thoai: ";
   cin>>dt.gia_tien;
   cout<<"Nhap vao so luong: ";
   cin>>dt.so_luong;
}
void Dienthoai :: CapNhatDienThoaiTheoMa(Dienthoai a[], int ma_dt, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].ma_dt == ma_dt) {
            found = 1;
            inra_(40);
            cout<<endl<<"Cap nhat thong tin dien thoai co ma la: " << ma_dt;
            CapNhatThongTinDienThoai(a[i]);
            inra_(40);
            break;
        }
    }
    if (found == 0) {
        cout<<"Dien thoai co ma la "<<ma_dt<<"khong ton tai !!!"; 
    }
}
int Dienthoai :: XoaTheoMADT(Dienthoai a[], int ma_dt, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].ma_dt == ma_dt) {
            found = 1;
            inra_(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout <<endl<< "Da xoa dien thoai co ma la: " << ma_dt;
            inra_(40);
            break;
        }
    }
    if (found == 0) {
        cout<<endl<<"Dien thoai co ma "<<ma_dt<<"khong ton tai !!!";
        return 0;
    } else {
        return 1;
    }
}
void Dienthoai :: ShowDienThoai(Dienthoai a[], int n) 
{
    cout<<endl<<"      +------+------------------+----------------+---------------+------------+"<<endl;
         cout <<"      |"<<" MA"<<"   |"<<" TEN"<<"              |"<<" HANG"<<"           |"<<" GIA"<<"           |"<<" SOLUONG    |";
    cout<<endl<<"      +------+------------------+----------------+---------------+------------+"<<endl;
          cout<<"      |      |                  |                |               |            |";
    for(int i = 0; i < n; i++) 
    {
        // in điện thoại thứ i ra màn hình 

    cout<<endl<<"      |"<<"\t"<<setw(5)<< left << a[i].ma_dt<<"| "<<setw(17)<< left << a[i].ten_dt<<"| "<<setw(15)<< left << a[i].hang_dt<<"| "<<setw(14)<< left << a[i].gia_tien<<"| "<<setw(11)<< left << a[i].so_luong<<"|";
    }
    cout<<endl<<"      +------+------------------+----------------+---------------+------------+"<<endl;

}
void Dienthoai :: TimKiemDienThoaiTheoTen(Dienthoai a[], char ten_dt[], int n) 
{
    Dienthoai aFound[MAX];
    char tenDT[30];
    int found = 0;
    int check=0;
    for(int i = 0; i < n; i++) 
    {
        strcpy(tenDT, a[i].ten_dt);//copy toàn bộ chuỗi sau vào chuỗi trước
        if(strstr(strupr(tenDT), strupr(ten_dt)))//tìm lần xuất hiện đầu tiên của chuỗi sau trong chuỗi trước
        {
            check=1;
            aFound[found] = a[i];
            found++;

        }
    }
    if(check == 1)
    {
        ShowDienThoai(aFound, found);
    }
    else 
    {
        cout<<endl<<"Ten "<<"\""<<strlwr(ten_dt)<<"\""<<" can tim khong co trong danh sach dien thoai !!!"<<endl;
    }
}
void Dienthoai :: ShowHoaDonDT(Dienthoai a[], int n) 
{

    for(int i = 0; i < n; i++) 
    {
        // in điện thoại thứ i ra màn hình 
       cout<<"\n\tMa dien thoai :"<<a[i].ma_dt;
       cout<<"\n\tTen dien thoai :"<<a[i].ten_dt;
       cout<<"\n\tHang dien thoai : "<<a[i].hang_dt;

    }
    
}
void Dienthoai :: XuatHoaDonTheoMaDT(Dienthoai a[], int ma_dt,int so_luong, int n)
{
    Dienthoai BB[MAX];
    int bb = 0;
    int check=0;
    int tongtien=0;
    for(int i = 0; i < n; i++) 
    {
       if (a[i].ma_dt == ma_dt && a[i].so_luong >= so_luong)
        {
            check=1;
            BB[bb] = a[i];
            bb++;
            tongtien=(a[i].gia_tien)*so_luong;

        }
    }
    if(check == 1)
    {
        ShowHoaDonDT(BB, bb);
        cout<<"\n\tSo dien thoai ban mua la: "<<so_luong;
        // cout<<"\n\tTong chi phi phai tra la: "<<tongtien;
    }
    else 
    {
        cout<<endl<<"Ma "<<"\""<<ma_dt<<"\""<<" khong co trong danh sach dien thoai !!!"<<endl;
    }
}
void Dienthoai :: Show1DT(Dienthoai a[], int ma_dt, int n)
{
    Dienthoai CC[MAX];
    int cc = 0;
    int check=0;
    for(int i = 0; i < n; i++) 
    {
       if (a[i].ma_dt == ma_dt)
        {
            check=1;
            CC[cc] = a[i];
            cc++;
        }
    }
    if(check == 1)
    {
        ShowDienThoai(CC , cc);
    }
    else 
    {
        cout<<endl<<"Ma "<<"\""<<ma_dt<<"\""<<" khong co trong danh sach dien thoai !!!"<<endl;
    }
}
int Dienthoai :: MaDTLonNhat (Dienthoai a[], int n) {
    int madtmax = 0;
    if (n > 0) {
      madtmax = a[0].ma_dt;
        for(int i = 0;i < n; i++) {
            if (a[i].ma_dt > madtmax) {
                madtmax = a[i].ma_dt;
            }
        }
    }
    return madtmax;
}
int Dienthoai :: DocFile1(Dienthoai a[], char fileName[]) {
    FILE * fp=NULL;
    int i = 0;
    //Mở file bằng hàm fopen
    fp = fopen (fileName, "r");//mở tệp chế độ đọc
    cout << "Dang doc file: ";
    puts(fileName);
    int soluong=0;
     //Đọc từng dòng trong file cho tới khi gặp EOF
    while (fscanf(fp, "%5d%20s%15s%10d%6d\n", &a[i].ma_dt, a[i].ten_dt, a[i].hang_dt, &a[i].gia_tien, &a[i].so_luong) != EOF)
    {
       soluong += a[i].so_luong;
       i++;
    }
    cout << "So hang dien thoai co san trong file la: "<<i<<endl;
    cout << "So luong dien thoai co san trong file la: " << soluong;
    cout << endl;
    fclose (fp);
    //trả về số hãng điện thoại đọc từ file
    return i;
}
int Dienthoai :: DocFile2(Dienthoai a[], char fileName[]) {
    FILE * fp=NULL;
    int i = 0;
    //Mở file bằng hàm fopen
    fp = fopen (fileName, "r");//mở tệp chế độ đọc
    int soluong=0;
     //Đọc từng dòng trong file cho tới khi gặp EOF
    while (fscanf(fp, "%5d%20s%15s%10d%6d\n", &a[i].ma_dt, a[i].ten_dt, a[i].hang_dt, &a[i].gia_tien, &a[i].so_luong) != EOF)
    {
       soluong += a[i].so_luong;
       i++;
    }
    cout << endl;
    fclose (fp);
    //trả về số lượng điện thoại đọc từ file
    return soluong;
}

void Dienthoai :: GhiFile(Dienthoai a[], int n, char fileName[]) {
    FILE * fp=NULL;
    fp = fopen (fileName,"w");//mở tệp chế độ ghi
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%20s%15s%10d%6d\n", a[i].ma_dt, a[i].ten_dt, a[i].hang_dt, a[i].gia_tien, a[i].so_luong);
    }
    fclose (fp);
}

// menu quản lí tính năng 
void Dienthoai :: MENU()
{
    int key;
    char fileName[] = "DIENTHOAI.txt";
    Dienthoai *dT = new Dienthoai[1000];
    int sohangDT = 0;
    int soluongDT = 0;
    int madtCount = 0;
    
    sohangDT = DocFile1(dT, fileName);
    soluongDT = DocFile2(dT,fileName);
    madtCount = MaDTLonNhat(dT, sohangDT);

    while(true) {
        system("@cls||clear");
        cout << "\t********************QUAN-LI-SAN-PHAM*******************\n";
        cout << "\t**  1. Hien thi danh sach dien thoai.                **\n";
        cout << "\t**  2. Cap nhat thong tin dien thoai theo ma.        **\n";
        cout << "\t**  3. Xoa dien thoai bang ma.                       **\n";
        cout << "\t**  4. Tim kiem dien thoai theo ten.                 **\n";
        cout << "\t**  5. Nhap them dien thoai.                         **\n";
        cout << "\t**  0. Thoat                                         **\n";
        cout << "\t*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                system("@cls||clear");
                if(soluongDT > 0){
                    cout << "\n1. Hien thi danh sach dien thoai.";
                    ShowDienThoai(dT, sohangDT);
                }else{
                    cout << "\nDanh sach dien thoai trong !!!";
                }
                pressAnyKey();
                break;
            case 2:
                system("@cls||clear");
                if(soluongDT> 0) {
                    ShowDienThoai(dT, sohangDT);
                    int madt;
                    cout << "\n2. Cap nhat thong tin dien thoai voi ma. ";
                    cout << "\n Nhap ma dien thoai: "; cin >> madt;
                    CapNhatDienThoaiTheoMa(dT, madt, sohangDT);
                }else{
                    cout << "Danh sach dien thoai trong !!!";
                }
                GhiFile(dT, sohangDT, fileName);
                pressAnyKey();
                break;
            case 3:
                system("@cls||clear");
                if(soluongDT > 0) {
                    ShowDienThoai(dT, sohangDT);
                    int madt;
                    cout << "\n3.Xoa dien thoai theo ma .";
                    cout << "\n Nhap ma dien thoai: "; 
                    cin >> madt;
                    if (XoaTheoMADT(dT, madt, sohangDT) == 1)
                    {
                        sohangDT--;
                    }
                }else{
                    cout << "\nDanh sach dien thoai trong !!!";
                }
                GhiFile(dT, sohangDT, fileName);
                pressAnyKey();
                break;
            case 4:
                system("@cls||clear");
                if(soluongDT > 0) {
                    cout << "\n4. Tim kiem dien thoai theo ten.";
                    char ten[30];
                    cout << "\nNhap ten de tim kiem: "; 
                    fflush(stdin); 
                    gets(ten);
                    TimKiemDienThoaiTheoTen(dT, ten, sohangDT);
                }else{
                    cout << "\nDanh sach dien thoai trong !!!";
                }
                pressAnyKey();
                break;
            case 5:
                system("@cls||clear");
                cout << "\n5.Them dien thoai.";
                madtCount++;
                NhapDT(dT, madtCount, sohangDT);
                cout<<"\nThem dien thoai thanh cong!";
                sohangDT++;
                GhiFile(dT, sohangDT, fileName);
                pressAnyKey();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh !!!";
                getch();
                return ;
            default:
                cout << "\nKhong co chuc nang nay!!";
                cout << "\nHay chon chuc nang khac co trong menu!!";
                pressAnyKey();
                break;
        }
    }
}
