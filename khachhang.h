#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <stdbool.h>
using namespace std;
#define FileKh "FileKh.dat"
class Khachhang
{
private:
  char ten[50], _sdt[12], _diachi[60];
  int _diemtichluy;

public:
  static int _soluongKh;
  Khachhang();
  friend ostream &operator<<(ostream &out, Khachhang a);
  friend istream &operator>>(istream &in, Khachhang &a);
  friend bool operator==(Khachhang a, Khachhang b);
  Khachhang &operator=(const Khachhang &Kh);
  void setDiemTichLuy(int n);
  int getDiemTichLuy();
  int _docFileKh(Khachhang Kh[]);
  void _ghiFileKh(Khachhang &Kh);
  void _suaKh(Khachhang Kh[], const int &n);
  void _xoaKh(Khachhang Kh[], int &n);
  void _xuatKh(Khachhang Kh[], const int &n);
  void _capnhatKh(Khachhang Kh[], const int &n);
  void _sapxepKh(Khachhang Kh[]);
  bool _locKhtheodiem(int, int);
  bool _locKhtheochuoi(char A[], char B[]);
  void _timkiemKh(Khachhang Kh[]);
  void _xuatKhtheo(Khachhang Kh[]);
  void _MENU();
  void _hoanviKh(Khachhang &a, Khachhang &b);
  void _khungtren();
  void _khungduoi();
  void _xuat1Kh(Khachhang Kh);
  void pressAnyKey();
  void _muaSp(const int &n);
  void _chuahoatenKh(char A[]);
  void _xuatHDkhachhang(Khachhang Kh);
  void _kiemtraten(char A[], bool &kt);
  void _kiemtraso(char A[], bool &kt);
  ~Khachhang()
  {
  }

  void xuat();
};
Khachhang::Khachhang()
{
  _diemtichluy = 0;
}
int Khachhang::_soluongKh = 0;
// da nang hoa toan tu nhap
istream &operator>>(istream &in, Khachhang &a)
{
  fflush(stdin);
  cout << "Nhap ten Khach hang: ";
  cin.getline(a.ten, 50);
  printf("\n");
  bool kt = true;
  while (kt)
  {
    if (strlen(a.ten) < 2)
    {
      kt = true;
      fputs("\033[A\033[2K", stdout);
      rewind(stdout);
      printf("Ten nhap vao khong hop le! Moi nhap lai: ");
      fflush(stdin);
      cin.getline(a.ten, 50);
    }
    else
    {
      for (int i = 0; i < strlen(a.ten); i++)
      {
        if (((int)a.ten[i] > 64 && (int)a.ten[i] < 91) || ((int)a.ten[i] > 96 && (int)a.ten[i] < 123) || (a.ten[i] == ' ') || a.ten[i] == '.')
          kt = false;
        else
        {
          kt = true;
          fputs("\033[A\033[2K", stdout);
          rewind(stdout);
          printf("Ten nhap vao khong hop le! Moi nhap lai: ");
          fflush(stdin);
          cin.getline(a.ten, 50);
        }
        if (kt)
          break;
      }
    }
  }
  char tam[2];
  tam[0] = a.ten[0];
  strupr(tam);
  a.ten[0] = tam[0];
  for (int i = 1; i < strlen(a.ten); i++)
  {
    if ((a.ten[i - 1] == ' ' && a.ten[i] != ' '))

    {
      tam[0] = a.ten[i];
      strupr(tam);
      a.ten[i] = tam[0];
    }
  }
  cout << "Nhap so dien thoai: ";
  cin.getline(a._sdt, 12);
  kt = true;
  printf("\n");
  while (kt)
  {
    if (strlen(a._sdt) < 2)
    {
      kt = true;
      fputs("\033[A\033[2K", stdout);
      rewind(stdout);
      printf("So dien thoai vua nhap vao khong hop le! Moi nhap lai: ");
      fflush(stdin);
      cin.getline(a._sdt, 12);
    }
    else
    {
      for (int i = 0; i < strlen(a._sdt); i++)
      {
        if ((int)a._sdt[i] > 47 && (int)a._sdt[i] < 58 && strlen(a._sdt) == 10 && a._sdt[0] == '0')
          kt = false;
        else
        {
          kt = true;
          fputs("\033[A\033[2K", stdout);
          rewind(stdout);
          printf("So dien thoai vua nhap vao khong hop le! Moi nhap lai: ");
          fflush(stdin);
          cin.getline(a._sdt, 12);
        }
        if (kt)
          break;
      }
    }
  }
  cout << "Nhap dia chi Khach hang: ";

  cin.getline(a._diachi, 60);
  kt = true;
  while (kt)
  {
    if (strlen(a._diachi) < 2)
    {
      kt = true;
      fputs("\033[A\033[2K", stdout);
      rewind(stdout);
      printf("Dia chi nhap vao khong hop le! Moi nhap lai: ");
      fflush(stdin);
      cin.getline(a._diachi, 60);
    }
    else
      kt = false;
  }
  char tam1[2];
  tam1[0] = a._diachi[0];
  strupr(tam1);
  a._diachi[0] = tam1[0];
  for (int i = 1; i < strlen(a._diachi); i++)
  {
    if ((a._diachi[i - 1] == ' ' && a._diachi[i] != ' '))
    {
      tam1[0] = a._diachi[i];
      strupr(tam1);
      a._diachi[i] = tam1[0];
    }
  }
  return in;
}

// kiem tra so dien thoai
void Khachhang::_kiemtraso(char A[], bool &kt)
{

  for (int i = 0; i < strlen(A); i++)
  {
    if ((int)A[i] > 47 && (int)A[i] < 58 && strlen(A) == 10 && A[0] == '0')
      kt = false;
    else
    {
      kt = true;
      fputs("\033[A\033[2K", stdout);
      rewind(stdout);
      printf("So dien thoai vua nhap vao khong hop le! Moi nhap lai: ");
      fflush(stdin);
      cin.getline(A, 12);
    }
    if (kt)
      break;
  }
}

// ham kiem tra ten
void Khachhang::_kiemtraten(char A[], bool &kt)
{
  for (int i = 0; i < strlen(A); i++)
  {
    if (((int)A[i] > 64 && (int)A[i] < 91) || ((int)A[i] > 96 && (int)A[i] < 123) || (A[i] == ' ') || A[i] == '.')
      kt = false;
    else
    {
      kt = true;
      fputs("\033[A\033[2K", stdout);
      rewind(stdout);
      printf("Ten nhap vao khong hop le! Moi nhap lai: ");
      fflush(stdin);
      cin.getline(A, 50);
    }
    if (kt)
      break;
  }
}

// ham chuan hoa ten
void Khachhang::_chuahoatenKh(char A[])
{
  char tmp[2];
  tmp[0] = A[0];
  strupr(tmp);
  A[0] = tmp[0];
  for (int i = 1; i < strlen(A); i++)
  {
    if ((A[i - 1] == ' ' && A[i] != ' '))
    {
      tmp[0] = A[i];
      strupr(tmp);
      A[i] = tmp[0];
    }
  }
}
// da nang hoa toan tu xuat
ostream &operator<<(ostream &out, Khachhang a)
{
  out << "| " << left << setw(18) << a.ten;
  out << "| " << left << setw(14) << a._sdt;
  out << "| " << left << setw(22) << a._diachi;
  out << "| " << left << setw(8) << a._diemtichluy;
  if (a._diemtichluy < 10000)
  {
    out << left << setw(14) << "| Than Thiet ";
  }
  else if (a._diemtichluy < 20000)
    out << left << setw(14) << "|     Bac    ";
  else
    out << left << setw(14) << "|    Vang    ";
  out << "|";
  return out;
}
void Khachhang ::setDiemTichLuy(int n)
{
  _diemtichluy += n;
}
int Khachhang ::getDiemTichLuy()
{
  return _diemtichluy;
}
// mua san pham
void Khachhang::_muaSp(const int &n)
{
  int giam;
  if (this->_diemtichluy < 10000)
    giam = 0;
  else if (this->_diemtichluy < 20000)
    giam = n * 2 / 100;
  else
    giam = (n * 4 / 100) < 1000 ? (n * 4 / 100) : 1000;
  cout << "\n\tTong tien: " << n << " (VND)" << endl;
  cout << "\n\tSo tien duoc giam: " << giam << " (VND)" << endl;
  cout << "\n\tSo tien phai tra: " << n - giam << " (VND)" << endl;
  _diemtichluy += (n - giam) / 1000;
}
// gan hai KH
Khachhang &Khachhang::operator=(const Khachhang &Kh)
{
  if (strlen(Kh.ten) != 0)
    strcpy(this->ten, Kh.ten);
  if (strlen(Kh._sdt) != 0)
    strcpy(this->_sdt, Kh._sdt);
  if (strlen(Kh._diachi) != 0)
    strcpy(this->_diachi, Kh._diachi);
  this->_diemtichluy = Kh._diemtichluy;
  return *this;
}

// sua thong tin KH
void Khachhang::_suaKh(Khachhang Kh[], const int &n)
{

  int tmp;
  do
  {
    system("@cls||clear");
    _xuatKh(Kh, n);
    cout << "\n\tMoi chon so thu tu cua khach hang can sua: ";
    cin >> tmp;
    if (tmp < 1 || tmp > n)
    {
      cout << "\n \tSo thu tu ban nhap khong hop le!\n";
      cout << " \tNhan enter de nhap lai! ";
      getch();
    }
  } while (tmp < 1 || tmp > n);
  system("@cls||clear");
  cout << "\n \tBan chac chan sua khach hang: " << endl;
  _xuat1Kh(Kh[tmp - 1]);
  Khachhang t = Kh[tmp - 1];
  cout << "\n\n\tChon y de sua chon n de quay lai: ";
  char i;
  fflush(stdin);
  cin >> i;
  if ('y' == i)
  {
    Khachhang Kh1;
    cout << "\tChu y: nhap enter de bo qua thong tin khong can sua!\n";
    fflush(stdin);
    cout << "Nhap ten Khach hang: ";
    cin.getline(Kh1.ten, 50);
    printf("\n");
    bool kt = true;
    while (kt)
    {
      if (strlen(Kh1.ten) < 2)
      {
        kt = false;
      }
      else
      {
        _kiemtraten(Kh1.ten, kt);
      }
    }
    _chuahoatenKh(Kh1.ten);
    cout << "Nhap so dien thoai: ";
    cin.getline(Kh1._sdt, 12);
    kt = true;
    printf("\n");
    while (kt)
    {
      if (strlen(Kh1._sdt) < 2)
      {
        kt = false;
      }
      else
      {
        _kiemtraso(Kh1._sdt, kt);
      }
    }
    cout << "Nhap dia chi Khach hang: ";

    cin.getline(Kh1._diachi, 60);
    printf("\n");

    _chuahoatenKh(Kh1._diachi);
    t = Kh1;
    cout << "\n\tKhach hang duoc sua thanh:\n";
    _xuat1Kh(t);
    cout << "\n\n\tChon y de xac nhan chon n de thoat: ";
    fflush(stdin);

    cin >> i;
    if ('y' == i || 'Y' == i)
    {
      Kh[tmp - 1] = Kh1;
      _capnhatKh(Kh, n);
    }
  }
  return;
}

// loc KH theo ten, std, dia chi
bool Khachhang::_locKhtheochuoi(char A[], char B[])
{
  char *ptr;
  ptr = strstr(A, B);
  if (ptr != NULL)
    return true;
  return false;
}

// xap xep KH theo diem tich luy
void Khachhang::_sapxepKh(Khachhang Kh[])
{
  int i, j;
  Khachhang last;
  for (i = 1; i < _soluongKh; i++)
  {
    last = Kh[i];
    j = i;
    while ((j > 0) && (Kh[j - 1]._diemtichluy < last._diemtichluy))
    {
      Kh[j] = Kh[j - 1];
      j--;
      Kh[j] = last;
    }
  }
}

// hoan vi khach hang
void Khachhang::_hoanviKh(Khachhang &a, Khachhang &b)
{
  Khachhang tmp;
  tmp = a;
  a = b;
  b = tmp;
}

// xuat khach hang theo dieu kien
void Khachhang::_xuatKhtheo(Khachhang Kh[])
{
  system("@cls||clear");
  int key = 0;
  do
  {
    cout << "\n\n\t\tChon 1 de xuat tat ca khach hang. ";
    cout << "\n\t\tChon 2 de xuat khach hang theo dia chi.";
    cout << "\n\t\tChon 3 de xuat khach hang theo diem tich luy. ";
    cout << "\n\t\tChon 0 de quay lai!";
    cout << "\n\n\t\tMoi nhap lua chon: ";
    cin >> key;
    if (key < 0 || key > 3)
    {
      cout << "\n\t\tLua chon khong hop le moi nhap lai!";
      getch();
      system("@cls||clear");
    }
  } while (key < 0 || key > 3);
  if (key == 0)
  {
    return;
  }
  else if (key == 1)
  {
    cout << "\n\t\t\t\tDANH SACH KHACH HANG\n\n";
    _xuatKh(Kh, _soluongKh);
  }
  else if (key == 2)
  {
    char valua[20];
    fflush(stdin);
    cout << "\nMoi nhap dia chi khach hang can xuat.";
    cin.getline(valua, 20);

    bool j = false;
    for (int i = 0; i < _soluongKh; i++)
    {
      if (_locKhtheochuoi(Kh[i]._diachi, valua))
        j = true;
    }
    if (j)
    {
      cout << "\n\t\t\tDanh sach khach hang co dia chi \"" << valua << "\"\n\n";
      _khungtren();
      for (int i = 0; i < _soluongKh; i++)
      {
        if (_locKhtheochuoi(Kh[i].ten, valua))
        {
          cout << "| ";
          cout << setw(3) << i + 1 << " ";
          cout << Kh[i] << endl;
        }
      }
      _khungduoi();

      pressAnyKey();
    }
    else
    {
      cout << "\t\tKhong tim thay khach hang co dia chi \"" << valua << "\" !\n\n";
      pressAnyKey();
    }
  }
  // pressAnyKey();
}

// tim kiem Khach hang
void Khachhang::_timkiemKh(Khachhang Kh[])
{
  system("@cls||clear");
  int key = 0;
  do
  {
    cout << "\n\t\tChon 1 de tim kiem theo ten. ";
    cout << "\n\t\tChon 2 de tim kiem theo so dien thoai.";
    cout << "\n\t\tChon 0 de quay lai!";
    cout << "\n\n\t\tMoi nhap lua chon: ";
    cin >> key;
    if (key < 0 || key > 2)
    {
      cout << "\n\t\tLua chon khong hop le moi nhap lai!";
      getch();
      system("@cls||clear");
    }
  } while (key < 0 || key > 2);
  if (key == 0)
  {
    return;
  }
  else if (key == 1)
  {
    char valua[20];
    fflush(stdin);
    cout << "\nMoi nhap ten khach hang can tim:";
    cin.getline(valua, 20);
    _chuahoatenKh(valua);
    bool j = false;
    for (int i = 0; i < _soluongKh; i++)
    {
      if (_locKhtheochuoi(Kh[i].ten, valua))
        j = true;
    }
    if (j)
    {
      cout << "\n\t\t\tDanh sach khach hang co ten \"" << valua << "\"\n\n";
      _khungtren();
      for (int i = 0; i < _soluongKh; i++)
      {
        if (_locKhtheochuoi(Kh[i].ten, valua))
        {
          cout << "| ";
          cout << setw(3) << i + 1 << " ";
          cout << Kh[i] << endl;
        }
      }
      _khungduoi();

      pressAnyKey();
    }
    else
    {
      cout << "\t\tKhong tim thay khach hang co ten \"" << valua << "\"\n\n";
      pressAnyKey();
    }
  }
  else if (key == 2)
  {
    char valua[20];
    fflush(stdin);
    cout << "\nMoi nhap sdt khach hang can tim:";
    cin.getline(valua, 20);

    bool j = false;
    for (int i = 0; i < _soluongKh; i++)
    {
      if (_locKhtheochuoi(Kh[i]._sdt, valua))
        j = true;
    }
    if (j)
    {
      cout << "\n\t\t\tDanh sach khach hang co so dien thoai  \"" << valua << "\"\n\n";
      _khungtren();
      for (int i = 0; i < _soluongKh; i++)
      {
        if (_locKhtheochuoi(Kh[i]._sdt, valua))
        {
          cout << "| ";
          cout << setw(3) << i + 1 << " ";
          cout << Kh[i] << endl;
        }
      }
      _khungduoi();
      pressAnyKey();
    }
    else
    {
      cout << "\t\tKhong tim thay khach hang co sdt \"" << valua << "\"\n\n";
      pressAnyKey();
    }
  }
}

// cap nhat khach hang
void Khachhang::_capnhatKh(Khachhang Kh[], const int &n)
{
  fstream f(FileKh, ios::binary | ios::out);

  for (int i = 0; i < n; i++)
    f.write(reinterpret_cast<char *>(&Kh[i]), sizeof(Khachhang));
  f.close();
}

// khung tren
void Khachhang::_khungtren()
{
  cout << "+-----------------------------------------------------------------------------------------+\n";
  cout << left << setw(4) << "| STT ";
  cout << left << setw(20) << "|      HO TEN    ";
  cout << left << setw(16) << "| SO DIEN THOAI";
  cout << left << setw(24) << "|        DIA CHI    " << setw(10) << "| DIEM TL" << setw(14) << "|   HANG KH";
  cout << "|" << endl;
  cout << left << setw(4) << "|-----+";
  cout << left << setw(20) << "-------------------+";
  cout << left << setw(16) << "---------------+";
  cout << left << setw(24) << "-----------------------+" << setw(10) << "---------+" << setw(13) << "-------------";
  cout << "|" << endl;
}

// khung duoi
void Khachhang::_khungduoi()
{
  cout << left << setw(4) << "+-----+";
  cout << left << setw(20) << "-------------------+";
  cout << left << setw(16) << "---------------+";
  cout << left << setw(24) << "-----------------------+" << setw(10) << "---------+" << setw(13) << "-------------";
  cout << "+" << endl;
}

// xuat khach hang
void Khachhang::_xuatKh(Khachhang Kh[], const int &n)
{
  _khungtren();
  for (int i = 0; i < n; i++)
  {
    cout << "| ";
    cout << setw(3) << i + 1 << " ";
    cout << Kh[i] << endl;
  }
  _khungduoi();
}
void Khachhang ::_xuatHDkhachhang(Khachhang Kh)
{
  cout << "\n\tTen khach hang: " << Kh.ten;
  cout << "\n\tSo dien thoai la: " << Kh._sdt;
  cout << "\n\tDia chi khach hang: " << Kh._diachi;
  cout << "\n\tDiem tich luy la: " << Kh._diemtichluy;
  cout << "\n\tHang khach hang: ";
  if (Kh._diemtichluy < 10000)
  {
    cout << "Than Thiet ";
  }
  else if (Kh._diemtichluy < 20000)
    cout << "Bac";
  else
    cout << "Vang";
}
// xuat 1 khach hang
void Khachhang::_xuat1Kh(Khachhang Kh)
{
  cout << "_____________________________________________________________________________________\n";
  cout << left << setw(20) << "|      HO TEN    ";
  cout << left << setw(16) << "| SO DIEN THOAI";
  cout << left << setw(24) << "|        DIA CHI    " << setw(10) << "| DIEM TL" << setw(14) << "|   HANG KH";
  cout << "|" << endl;
  cout << left << setw(20) << "|-------------------+";
  cout << left << setw(16) << "---------------+";
  cout << left << setw(24) << "-----------------------+" << setw(10) << "---------+" << setw(13) << "-------------";
  cout << "|" << endl;
  cout << Kh << endl;
  cout << left << setw(20) << "+-------------------+";
  cout << left << setw(16) << "---------------+";
  cout << left << setw(24) << "-----------------------+" << setw(10) << "---------+" << setw(13) << "-------------";
  cout << "+" << endl;
}

// xoa Kh
void Khachhang::_xoaKh(Khachhang *Kh, int &_soluongKh)
{

  int tmp;
  do
  {
    system("@cls||clear");
    _xuatKh(Kh, _soluongKh);
    cout << "\n\tMoi chon so thu tu cua khach hang can xoa: ";
    cin >> tmp;
    if (tmp < 1 || tmp > _soluongKh)
    {
      cout << "\n \tSo thu tu ban nhap khong hop le!\n";
      cout << " \tNhan enter de nhap lai! ";
      getch();
    }
  } while (tmp < 1 || tmp > _soluongKh);
  system("@cls||clear");
  cout << "\n \tBan chac chan xoa khach hang: " << endl;
  _xuat1Kh(Kh[tmp - 1]);
  cout << "\n\tChon y de xoa chon n de quay lai: ";
  char i;
  fflush(stdin);
  cin >> i;
  if ('y' == i)
  {
    for (i = tmp - 1; i < _soluongKh; i++)
      Kh[i] = Kh[i + 1];
    _soluongKh--;
    _capnhatKh(Kh, _soluongKh);
  }
  return;
}
//?
bool operator==(Khachhang a, Khachhang b)
{
  if (a._sdt == b._sdt || a.ten == b.ten)
    return true;
  return false;
}

// doc file Kh
int Khachhang::_docFileKh(Khachhang Kh[])
{
  int i = 0;
  fstream g(FileKh, ios::binary | ios::in);
  if (!g)
    return i;
  while (g.good())
  {
    //tang phan tu mang khach hang len 1 chua lam
    g.read(reinterpret_cast<char *>(&Kh[i]), sizeof(Khachhang));
    if (g.eof())
      break;
    i++;
  }
  g.close();

  return i;
}

// ghi file Kh
void Khachhang::_ghiFileKh(Khachhang &Kh)
{
  fstream f(FileKh, ios::binary | ios::out | ios::app);
  {
    if (!f)
      cout << "ko the ghi file! ";
    f.write(reinterpret_cast<char *>(&Kh), sizeof(Khachhang));
  }
  f.close();
}
//
void Khachhang::pressAnyKey()
{
  cout << "\n\nBam phim bat ky de tiep tuc...";
  getch();
  system("@cls||clear");
}

// ham MENU
void Khachhang::_MENU()
{
  int key;

  Khachhang *Kh = new Khachhang[100];

  int tmp;

  _soluongKh = _docFileKh(Kh);
  cout << _soluongKh << endl;

  while (true)
  {
    system("@cls||clear");
    _soluongKh = _docFileKh(Kh);
    _sapxepKh(Kh);
    cout << "\n\n\t\t*************************MENU**************************\n";
    cout << "\t\t**  1. Nhap them Khach hang.                         **\n";
    cout << "\t\t**  2. Hien thi danh sach Khach hang.                **\n";
    cout << "\t\t**  3. Tim kiem khach hang.                          **\n";
    cout << "\t\t**  4. Sua thong tin khach hang.                     **\n";
    cout << "\t\t**  5. Xoa khanh hang.                               **\n";
    cout << "\t\t**  0. Thoat                                         **\n";
    cout << "\t\t*******************************************************\n";
    cout << "\n\tNhap tuy chon: ";
    cin >> key;
    switch (key)
    {
    case 1:
      system("@cls||clear");
      _soluongKh++;
      cin >> Kh[_soluongKh - 1];
      _ghiFileKh(Kh[_soluongKh - 1]);
      // sap xep
      pressAnyKey();
      break;
    case 2:
      system("@cls||clear");
      if (_soluongKh > 0)
      {

        cout << "\n\t\t\t\tDANH SACH KHACH HANG\n\n";
        _xuatKh(Kh, _soluongKh);
      }
      else
      {
        cout << "\nDanh sach khach hang trong!!!";
      }
      pressAnyKey();
      break;
    case 3:
      system("@cls||clear");
      _timkiemKh(Kh);
      break;
    case 4:
      system("@cls||clear");
      if (_soluongKh > 0)
      {
        _suaKh(Kh, _soluongKh);
      }
      else
      {
        cout << "\nDanh sach khach hang trong!!!";
      }
      pressAnyKey();
      break;
    case 5:
      system("@cls||clear");
      if (_soluongKh > 0)
      {
        _xoaKh(Kh, _soluongKh);
      }
      else
      {
        cout << "\nDanh sach khach hang trong!!!";
      }
      pressAnyKey();
      break;
    case 0:
      return;

    default:
      cout << "\nLua chon Khong hop le!!";
      cout << "\nMoi nhap lai!!";
      pressAnyKey();
      break;
    }
  }
}
