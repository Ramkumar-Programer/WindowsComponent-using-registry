#include <windows.h>
#include <iostream>

using namespace std;
int main()
{
    BOOL deletekey;
    deletekey = RegDeleteKey(HKEY_LOCAL_MACHINE, "Software\\Test\\Product\\SmartId");

    if(ERROR_SUCCESS != deletekey)
    {
        cout << "Detele has a an error" << GetLastError() << endl;
    }
    else{
        cout << "Deleted succussfully" << endl;
    }

}