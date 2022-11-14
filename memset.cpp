#include <stdio.h>

int getAddr(std::any data){
    return &data;                       // returns the address of the first byte of data
}

int * getAllAdresses(std::any data){
    
    int max = sizeof(data);             // maximum memory address of data
    int min = &data;                    // starting of data
    int * addresses[max];               // 

    for (int i = 0; i != max; i++){     
        addresses[i]=min+i;             // [0] ─> 0x33, [1] ─> 0x34 etc.
    }  
    return addresses;
}

bool memread(int addr){                 // read the data stored at a certain address
    return true;                        
}

bool memset(int addr, std::any data){
    return true;
}



/*
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "almost every programmer should know memset!";
  memset (str,'-',6);

    C++:    memset (starting value of data, char data, how many bytes to be filled)
    LION:   memorySet(address, value (1 byte)) or memorySet(adress start, )


  puts (str);
  return 0;
}


*/
