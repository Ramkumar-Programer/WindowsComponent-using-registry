#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;



void EnumerateSubKeys(HKEY RootKey, char* subKey, unsigned int tabs = 0) 
{
 HKEY hKey;
    DWORD cSubKeys;        //Used to store the number of Subkeys
    DWORD maxSubkeyLen;    //Longest Subkey name length
    DWORD cValues;        //Used to store the number of Subkeys
    DWORD maxValueLen;    //Longest Subkey name length
    DWORD retCode;        //Return values of calls
    
 RegOpenKeyEx(RootKey, subKey, 0, KEY_ALL_ACCESS, &hKey);

    RegQueryInfoKey(hKey,            // key handle
                    NULL,            // buffer for class name
                    NULL,            // size of class string
                    NULL,            // reserved
                    &cSubKeys,        // number of subkeys
                    &maxSubkeyLen,    // longest subkey length
                    NULL,            // longest class string 
                    &cValues,        // number of values for this key 
                    &maxValueLen,    // longest value name 
                    NULL,            // longest value data 
                    NULL,            // security descriptor 
                    NULL);            // last write time

    if(cSubKeys>0)
 {
        char currentSubkey[MAX_PATH];

        for(int i=0;i < cSubKeys;i++){
   DWORD currentSubLen=MAX_PATH;

            retCode=RegEnumKeyEx(hKey,    // Handle to an open/predefined key
            i,                // Index of the subkey to retrieve.
            currentSubkey,            // buffer to receives the name of the subkey
            &currentSubLen,            // size of that buffer
            NULL,                // Reserved
            NULL,                // buffer for class string 
            NULL,                // size of that buffer
            NULL);                // last write time

            if(retCode==ERROR_SUCCESS)
   {
                
                printf("(%d) %s\n", i+1, currentSubkey);

                char* subKeyPath = new char[currentSubLen + strlen(subKey)];
                
    EnumerateSubKeys(RootKey, subKeyPath, (tabs + 1));
   }
  }
 }
    else
 {
//   EnumerateValues(hKey, cValues);
 }

 RegCloseKey(hKey); 
}


int main()
{
    //EnumerateSubKeys(HKEY_LOCAL_MACHINE,"SOFTWARE");
    cout << "==============" << endl;
   EnumerateSubKeys(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall");
    return 0;
}