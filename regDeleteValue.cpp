#include <windows.h>
#include <iostream>

using namespace std;
int main()
{
    HKEY key;
    BOOL deletekey;
    RegOpenKey(HKEY_LOCAL_MACHINE, "HARDWARE\\Description\\System\\CentralProcessor\\0", &key); 
    deletekey = RegDeleteValueA(key, "NewValue");

    if(ERROR_SUCCESS != deletekey)
    {
        cout << "Detele has a an error" << GetLastError() << endl;
    }
    else{
        cout << "Deleted succussfully" << endl;
    }

}