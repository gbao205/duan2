#include<iostream>
#include<random> // để lấy rand
#include<ctime> // để lấy time(NULL)
#include<conio.h> // để lấy getch()
#include<windows.h>// để lấy system("cls")
#include<algorithm>
#include<string>
using namespace std;


// random vị trí số trong ô
void tron(int p[3][3]){
    srand(time(NULL));
for( int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        p[i][j] = rand() % 9 + 0;
    }
}
int b[9]={};
int i=0;
while( i < 3){
    int j = 0;
    while( j < 3){
        if(b[p[i][j]] == 0){
            b[p[i][j]]++;
            j++;
        }
        else{
            p[i][j] = rand() % 9 + 0;
           
        }
   }
   i++;
}
 }
 //hàm điều khiển chương trình
int dieukhien(int &h,int &c,int &buocdoi,int p[3][3]){
   char t;
    int x;
    int i , j , s , g;
    buocdoi=0;
 // vòng lập cần thiết để chuyển phím nhập từ bàn phím về mã ascii
  while(1) 
    {
        t = getch();    
        x = t;
        
            if( x == 13)//điều kiện khóa ô đã chọn
            {
                while(1){
                t=getch();    
                x=t;
                if( x == 72 ){ // đổi với ô ở phía trên 
                    if( h > 0 && p[h-1][c] == 0 ) {
                               swap(p[h][c] , p[h-1][c]);
                               buocdoi--;
                               break;
                               break;}
                    else {
                        break;
                        break;}}
                              
                else{       
                        if(x == 80)//đổi với ô ở phía dưới 
                        {
                            if(h < 2 && p[h+1][c] == 0) {
                               swap(p[h][c],p[h+1][c]);
                               buocdoi--;
                               break;
                               break;
                            }
                               else {
                                    break;
                                    break;}}
                        else{     
                             if(x == 75)//đổi với ô ở phía bên trái 
                             {  
                                if(c > 0 && p[h][c-1] == 0) {
                               swap(p[h][c],p[h][c-1]);
                               buocdoi--;
                                break;
                                break;}
                                else {
                                    break;
                                    break;}}
                         else{    
                            if(x == 77)// đổi với ô ở phía bên phải 
                            {
                                if(c < 2  && p[h][c+1] == 0) {
                                    swap(p[h][c],p[h][c+1]);
                                        buocdoi--;
                                        break;
                                        break;}
                                        else {
                                            break;
                                            break;}}
}}}}}
else 
            cout<<"";
            {if(x == 72 && h > 0) { // di chuyển lên
                h--;
                break; }
            if(x == 80 && h < 2) {
                h++;
                break;}//di chuyển xuống
            if(x == 75 && c > 0) {
                c--;
                break;}//di chuyển qua trái
            if(x == 77 && c < 2) {
                c++;
                break;} // di chuyển qua phải
       }}
       
}
 //dùng để tạo ra bảng puzzle
void xuat(int v,int z,int p[3][3]){
  system("cls");// xóa những phần dư thừa
    for(int i = 0;i < 3;i++){
    cout<<"=====================\n";
    for(int j = 0;j < 3;j++){
        if(i == v && j == z && p[i][j] != 0) 
            cout<<" ||"<<p[i][j]<<"|| ";
            else
             {if (p[i][j] != 0){
                 cout<<" | "<<p[i][j]<<" | ";
            }else
                 {if(i == v && j == z && p[i][j] == 0)
                    cout<<" ||"<<" "<<"|| ";
                    else
                    {
                         cout<<" | "<<" "<<" | ";
                    }
                    }
    }}
    cout<<"\n";
}cout<<"=====================\n";
}
//hàm kiểm tra xem liệu có giải được hay không
int kiemtra(int p[3][3]){
    int b[9]={0,0,1,2,3,4,5,6,7};
    int s=0;
         for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    s+= b[p[i][j]];
                    for(int z = p[i][j] + 1; z <= 8; z++)
                        { 
                            if(b[z]>0 && p[i][j] != 0)
                                { b[z]--;
                                }
                        }  
                       }
                }

if(s % 2 == 0) return 1;
return 0;
}
int main(){
    int a[3][3]={};
    int h = 0;
    int buoc;
    int buocdoi;
    string play;
    int choose;
    cout<<"\nYeu cau: Dua cac so ve thu tu tu nho den lon, tu trai sang phai.\n";
    cout<<"\nCach choi: Dung phim Enter de chon so, dung phim dieu huong de di chuyen o."<<"\n";
    again:
    cout<<"\nVui long chon cap do (nhap vao so tuy vao cap do muon chon): \n1: De\n2: Trung binh\n3: Kho\nNhap so: \n";
    cin>>choose;
    if(choose == 1){
        buoc=100;
    }
    else if (choose == 2)
    {
        buoc=50;
    }
    else if (choose == 3)
    {
        buoc=35;
    }
    else{
        cout<<"Loi! Vui long nhap lai\n";
        goto again;
    }
    int c = 0, o = 1, dem = 0;
    char t;
    lai:
    tron(a);
    if(kiemtra(a) == 0){
        goto lai;
    }
    xuat(h,c,a);
    cout<<"So buoc cua ban:"<<buoc<<"\n";
    while(1)
    {
    dieukhien(h,c,buocdoi,a);
    xuat(h,c,a);
    buoc+=buocdoi;
    for (int i = 0; i < 3; i++)//vòng lập kiểm tra cấc số đã nằm đúng vị trí chưa
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == o)
            {
                dem++;
            } 
            if (i == 2 && j == 1)
            {
                break;
                break;
            }
            
            o++;
        }
        if (dem == 8)
        {   
            cout<<"You Win\n";
            cout<<"Ban co muon choi tiep (yes/no)?: ";
            cin>>play;
            if(play == "yes")
                {
                    goto again;//dùng để chương trình quay lại vị trí again
                }
            else return 0;
        }
    }
    dem = 0;
    o = 1;
    cout<<"So buoc cua ban:"<<buoc<<"\n";
    if(buoc == 0){
        cout<<"You lose!\n";
        cout<<"Ban co muon choi tiep (yes/no)?: ";
            cin>>play;
            if(play == "yes")
                {
                    goto again;//dùng để chương trình quay lại vị trí again
                }
            else return 0;
        
    }
  }   
getch();
return 0;}
