
#include"hoadon.h"

int main()
{
    Dienthoai A;
    Khachhang B;
    Hoadon C;
    int key;

   while (true)
  {
    system("@cls||clear");
    cout << "\t\t+-------------------MENUQUANLI------------------+\n";
    cout << "\t\t|       1. Quan li san pham.                    |\n";
    cout << "\t\t|       2. Quan li khach hang.                  |\n";
    cout << "\t\t|       3. Quan li hoa don.                     |\n";
    cout << "\t\t|       0. Thoat.                               |\n";
    cout << "\t\t+-----------------------------------------------+\n";
    cout << "\tNhap chuc nang co trong menu: ";
    cin >> key;
    switch (key)
    {
    case 1:
      system("cls");
      A.MENU();
      A.pressAnyKey();
      break;
    case 2:
      system("cls");
      B._MENU();
      A.pressAnyKey();
      break;
    case 3:
      system("cls");
      C.MENU();
      A.pressAnyKey();
      break;
    case 0:
      cout << "\nBan da chon thoat chuong trinh !!!";
      exit(0);
    default:
      cout << "\nLua chon Khong hop le!!";
      cout << "\nMoi nhap lai!!";
      A.pressAnyKey();
      break;
    }
  }
  return 0;
}
