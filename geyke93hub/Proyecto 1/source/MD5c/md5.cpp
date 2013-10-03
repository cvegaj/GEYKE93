#include "md5.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
  char* mensaje;

  MD5 md5 ;

  cout<<"Digite el mensaje que quiere encriptar"<<"\n";
  cin>>mensaje;


  puts( md5.digestString( mensaje ) ) ;

        // print the digest for a binary file on disk.
        //puts( md5.digestFile( "C:\\WINDOWS\\notepad.exe" ) ) ;
  return 0;
}
