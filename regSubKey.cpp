#include <windows.h>
#include <iostream>

using namespace std;
int main()
{
    LONG lReg;
    HKEY key;
    DWORD dwData = 1234;
    
    lReg = RegCreateKeyExA(
        HKEY_LOCAL_MACHINE,                    // hkey
        "Software\\Test\\Product\\SmartId",    // subkey to create
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,                // this key is not volatile that means if the system is restart the value will not delete
        KEY_ALL_ACCESS,                         // giving all the access to key
        NULL,

        &key,                                   // receives a handle to open or create a key
        NULL
        );

    if (lReg!= ERROR_SUCCESS)
    {
        cout << "Reg created failed " << GetLastError() << endl;
    }
    else{
        cout << "successfully created" << endl; 
    }


    lReg = RegSetValueEx(
        key,
        "NewFile",
        NULL,
        REG_DWORD,
        (LPBYTE)&dwData,
        sizeof(dwData)
    );

    if (lReg!= ERROR_SUCCESS)
    {
        cout << "Reg created failed " << GetLastError() << endl;
    }
    else{
        cout << "successfully created" << endl; 
    }

    RegCloseKey(key);
    return 0;

}