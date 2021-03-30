#include <bits/stdc++.h>
#define USHORT unsigned short
#define UCHAR unsigned char
using namespace std;

int main()
{
    FILE *fptr;
    fptr = fopen("C:\\Users\\user\\Desktop\\test3.pcap", "rb");
    unsigned char* buffer = new unsigned char;
    int byteCount = 0;
    register unsigned long int sum = 0;
    register unsigned short *arr = new unsigned short;
    cout<<"\n  00  01  02  03  04  05  06  07      08  09  0A  0B  0C  0D  0E  0F\n";
    cout<<"  ..............................      ..............................\n\n  ";
    cout << setfill('0') << uppercase;
    fread(buffer, 1, 54, fptr);
    while(byteCount < 20){
        byteCount += 2;
        *arr = 0;
        fread(buffer, 1, 1, fptr);
        register unsigned short val1 = ((unsigned short)(*buffer) & 0x00FF);
        // *arr = ((unsigned short)(*buffer) & 0x00FF);
        *arr |= val1;
        cout<<hex<<setw(2)<<val1<<"  ";
        *arr = *arr << 8;
        fread(buffer, 1, 1, fptr);
        register unsigned short val2 = ((unsigned short)(*buffer) & 0x00FF);
        *arr |= val2;
        cout<<hex<<setw(2)<<val2<<"  ";
        sum += *arr;
        if(sum & 0xFFFF0000){
            sum &= (0x0000FFFF);
            sum++;
        }
        if(byteCount % 8 == 0){
            if(byteCount % 16 == 0){
                cout<<"\n  ";
            }
            else{
                cout<<"    ";
            }
        }
        if(byteCount == 20){
            break;
        }
    }
    cout<<"\n\n  ..............................      ..............................\n\n  ";
    register unsigned long result = (sum & 0x0000FFFF);
    cout<<"CheckSum :\t"<<hex<<(result&0x0000FFFF)<<"\n  ";
    cout<<endl;
    fclose(fptr);
    return 0;
}
