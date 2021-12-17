#include "dienthoai.h"
#include "khachhang.h"
#include <fstream>
#include "string"
#include<iostream>
#define HoaDon "HoaDon.dat"
class Date
{
private:
  int ngay;
  int thang;
  int nam;

public:
  Date(int ngay, int thang, int nam);
  ~Date();
  void NhapDate();
  void XuatDate();
};
Date ::Date(int ngay = 0, int thang = 0, int nam = 0)
{
  this->ngay = ngay;
  this->thang = thang;
  this->nam = nam;
}
Date ::~Date()
{
}
void Date ::NhapDate()
{
    cout << endl;
   cout << "Nhap vao ngay: ";
   cin >> ngay;
   cout << endl;
   while (ngay < 1 || ngay > 31 || !cin.good())
   {
     fputs("\033[A\033[2K", stdout);
     rewind(stdout);
     cin.clear();
     cin.ignore(1024, '\n');
     cout << "\nBan da nhap sai ngay , vui long nhap lai: ";
     cin >> ngay;
   }

   if (ngay == 31)
   {
     cout << endl;
     cout<< "Nhap vao thang: ";
     cin >> thang;
     cout << endl;
     while (thang != 1 && thang != 3 && thang != 5 && thang != 7 && thang != 8 && thang != 10 && thang != 12 || !cin.good())
     {
       fputs("\033[A\033[2K", stdout);
       rewind(stdout);
       cin.clear();
       cin.ignore(1024, '\n');
       cout << "\nBan da nhap sai thang , vui long nhap lai: ";
       cin >> thang;
     }
   }
   else if (ngay == 28)
   {
     cout << endl;
     cout<< "Nhap vao thang: ";
     cin >> thang;
     cout << endl;
     while (thang != 2 || !cin.good())
     {
       fputs("\033[A\033[2K", stdout);
       rewind(stdout);
       cin.clear();
       cin.ignore(1024, '\n');
       cout << "\n da nhap sai thang , vui long nhap lai: ";
       cin >> thang;
     }
   }
   else
   {
     cout << endl;
     cout<< "Nhap vao thang: ";
     cin >> thang;
     cout << endl;
     while (thang < 1 || thang > 12 || !cin.good())
     {
       fputs("\033[A\033[2K", stdout);
       rewind(stdout);
       cin.clear();
       cin.ignore(1024, '\n');
       cout << "\nBan da nhap sai thang , vui long nhap lai: ";
       cin >> thang;
     }
   }
    cout << endl;
     cout<< "Nhap vao nam: ";
     cin >> nam;
     cout << endl;
     while (nam != 2021 || !cin.good())
     {
       fputs("\033[A\033[2K", stdout);
       rewind(stdout);
       cin.clear();
       cin.ignore(1024, '\n');
       cout << "\nBan da nhap sai nam , vui long nhap lai: ";
       cin >> nam;
     }
}
void Date ::XuatDate()
{
  cout << "\n\tNgay mua hang la: " << ngay << "/" << thang << "/" << nam;
}
class Hoadon : public Dienthoai, public Khachhang, public Date
{
private:
  Date date;
  Khachhang Kh;
  Dienthoai dT;

public:
  int DocFileHoaDon(Hoadon hd[]);
  void GhiFileHoaDon(Hoadon &hd);
  void XuatHoaDon(Hoadon hd[], int n);
  void MENU();
};
int Hoadon ::DocFileHoaDon(Hoadon hd[])
{
  int i = 0;
  fstream g(HoaDon, ios::binary | ios::in);
  if (!g)
    return i;
  while (g.good())
  {
    g.read(reinterpret_cast<char *>(&hd[i]), sizeof(Hoadon));
    if (g.eof())
      break;
    i++;
  }
  g.close();

  return i;
}
void Hoadon::GhiFileHoaDon(Hoadon &hd)
{
  fstream f(HoaDon, ios::binary | ios::out | ios::app);
  {
    f.write(reinterpret_cast<char *>(&hd), sizeof(Hoadon));
  }
  f.close();
}
void Hoadon ::MENU()
{
  char fileName[] = "DIENTHOAI.txt";
  Dienthoai *dT = new Dienthoai[1000];
  int sohangDT = 0;
  int madtCount = 0;
  sohangDT = DocFile1(dT, fileName);
  int m = sohangDT;
  madtCount = MaDTLonNhat(dT, sohangDT);

  Khachhang *Kh = new Khachhang[100];
  int soluongKh = 0;
  soluongKh = _docFileKh(Kh);
  int n = soluongKh;
  int key;
  int tmp;     //chọn khách hàng
  int maDT;    //chọn điện thoại
  int soluong; //số lượng muốn mua

  Hoadon *hd = new Hoadon[100];
  int soluongHD = 0;
  soluongHD = DocFileHoaDon(hd);

  while (true)
  {
    system("@cls||clear");
    cout << endl;
    cout << "\t*******************QUAN-LI-HOA-DON*********************\n";
    cout << "\t**  1. Tao hoa don.                                  **\n";
    cout << "\t**  2. Xuat hoa don.                                 **\n";
    cout << "\t**  0. Thoat                                         **\n";
    cout << "\t*******************************************************\n";
    cout << "Nhap tuy chon: ";
    cin >> key;
    switch (key)
    {
    case 1:
      system("@cls||clear");
      _xuatKh(Kh, n);
      cout << "\n\tChon khach hang de tao hoa don: ";
      cin >> tmp;
      while (tmp < 1 || tmp > n)
      {
        cout << "\n\tKhach hang khong co ma nay,vui long nhap lai: ";
        cin >> tmp;
      }
      _xuat1Kh(Kh[tmp - 1]);
      //////////////////////////
      cout << "\n                   DANH SACH DIEN THOAI\n";

      ShowDienThoai(dT, sohangDT);
      cout << "\n\tChon dien thoai de tao hoa don: ";
      cin >> maDT;
      cout << endl;
      while (maDT < 1 || maDT > m)
      {
        fputs("\033[A\033[2K", stdout);
        rewind(stdout);
        cout << "\n\tSan pham khong co ma nay,vui long nhap lai: ";
        cin >> maDT;
      }
      Show1DT(dT, maDT, sohangDT);
      cout << "\nBan muon mua bao nhieu cai dien thoai: ";
      cin >> soluong;
      cout << endl;
      while (soluong > dT[maDT - 1].getSoLuong())
      {
        fputs("\033[A\033[2K", stdout);
        rewind(stdout);
        cout << "\nSo luong da qua gioi han , vui long nhap lai: ";
        cin >> soluong;
      }

      cout << "\nNhap ngay de tao hoa don:\n";
      date.NhapDate();

      Dienthoai::pressAnyKey();
      break;
    case 2:
      system("@cls||clear");
      cout << "\n-----------------------------------------\n";
      _xuatHDkhachhang(Kh[tmp - 1]);
      XuatHoaDonTheoMaDT(dT, maDT, soluong, sohangDT);
      Kh[tmp - 1]._muaSp(dT[maDT - 1].getGiaTien() * soluong);
      date.XuatDate();
      cout << "\n-----------------------------------------\n";
      char K;
      cout << "\nNhan \"Y\" de xac nhan mua dien thoai, N de quay lai: ";
      fflush(stdin);
      cin >> K;
      if (K == 'y' || K == 'Y')
      {
        Kh[tmp - 1].setDiemTichLuy((dT[maDT - 1].getGiaTien() * soluong) / 1000);
        dT[maDT - 1].setSoLuong(-soluong);
        _capnhatKh(Kh, soluongKh);
        GhiFile(dT, sohangDT, fileName);
      }
      else if (K == 'n' || K == 'N')
      {
        getch();
        return;
      }
      else
      {
        cout << "\nBan da nhap sai , vui long nhap lai: ";
        cin >> K;
      }
      Dienthoai ::pressAnyKey();
      break;
    case 0:
      system("@cls||clear");
      cout << "\nBan da chon thoat chuong trinh !!!";
      getch();
      return;
    default:
      cout << "\nKhong co chuc nang nay!!";
      cout << "\nHay chon chuc nang khac co trong menu!!";
      Dienthoai ::pressAnyKey();
      break;
    }
  }
}
