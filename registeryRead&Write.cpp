#include <iostream>
#include <windows.h>
using namespace std;


void registry_read(LPCTSTR subkey, LPCTSTR name, DWORD type)
{
    HKEY key;                                                                  // handle 
    TCHAR value[255];                                                         // value of registry is store in it
    DWORD value_length = 255;                                                 // length of the value
    RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);                             // to open the registry using hkey and subkey then in store in key

    RegQueryValueEx(
        key,                                                                  // key from the regopenkey
        name,                                                                 // name of file
        NULL, 
        &type,                                                                // type of the file
        (LPBYTE)&value,                                                       // fetching the value and store in this value
        &value_length                                                         // lenght of the value 
    );   

    RegCloseKey(key);
    std::cout << value << std:: endl;                                         // printing the value
}


void registry_write (LPCTSTR subkey, LPCTSTR name, DWORD type, const char* value)
{
    HKEY key;
    RegOpenKey(HKEY_LOCAL_MACHINE, subkey, &key);                             // opening the key 
    RegSetValueEx(
        key,                                                                  // key from the regopenkey
        name,                                                                 // name of the  file
        0,                                                                    // reserved must be zero
        type,                                                                 // type of the file
        (LPBYTE)value,                                                        // value assign to the file
        strlen(value)*sizeof(char)                                            // size of the file
        );
    RegCloseKey(key);
}


int main()
{
    registry_read("SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{DB1815C1-AC6F-4775-809F-4DD2A2AC1DC1}", "DisplayName", REG_SZ);             // function calling
    //registry_write("HARDWARE\\Description\\System\\CentralProcessor\\0", "NewValue", REG_SZ, "Content2");
    return 0;
}
