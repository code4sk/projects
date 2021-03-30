#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

long int checkSum();

int main() {

   char* Byte = new char;
   unsigned short* buffer = new unsigned short;
   int   byteCount = 0, flag = 0;
    //u_short a;

   ifstream binFile("C:\\Users\\user\\Desktop\\test3.pcap", ios::in | ios::binary); // open input file in binary mode
   if ( binFile.fail() ) {
      cout << "Unable to find file: " << "C:\\Users\\asus\\Documents\\xyz.pcap" << endl;
      return 1;
   }

   cout << "Hex dump of file " << "C:\\Users\\asus\\Documents\\xyz.pcap"<< ":" << endl << endl;
   const string colHeader = "  00  01  02  03  04  05  06  07      08  09  0A  0B  0C  0D  0E  0F";
   const string Delimiter = "  ------------------------------------------------------------------";
   cout << colHeader << endl;
   cout << Delimiter << endl;

   binFile.read(Byte,54 );                   // grab first byte of file
   cout << setfill('0') << uppercase;       // set fill character to handle single-digit hex values
                                            //     and display upper hex digits in upper-case
   while ( byteCount < 20) {                      // continue until input stream fails
        if(flag == 0){
            flag = 1;
             binFile.read(Byte, 1);
            continue;
        }
      cout << "  " << hex << setw(2)        // write in hex mode, with separation
           << (short(*Byte) & 0x00FF);      // cast char to short (for two-byte value)
                                            // mask upper byte of short with zeros
      byteCount+=2;
      if (byteCount % 8 == 0) {
         if (byteCount % 16 == 0)
            cout << endl;
         else
            cout << "    ";
      }
      binFile.read(Byte, 2);                 // grab next byte of file
   }
   cout << endl;
   cout << Delimiter << endl;
   cout << colHeader << endl;

   binFile.close();
   return 0;
}
