#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <string.h>

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT); //needed for output
    _setmode(_fileno(stdin), _O_U16TEXT); //needed for input
    // nh? chuy?n font c?a console sang Consolas (size 16)

    wprintf(L"%ls%ls%ls", L"Chuong tr�nh d?c v� xu?t chu?i ti?ng Vi?t\n\n",
        L"  \"G�\" ti?ng Vi?t b?ng c�ch copy chu?i ti?ng Vi?t ? tr�nh so?n th?o ti?ng Vi?t\n",
        L"n�o d� r?i click ph?i chu?t v�o m�n h�nh console\n\n");

    // nh?p h? t�n
    wchar_t username[40];
    wprintf(L"Nh?p h? t�n c?a b?n: ");
    fgetws(username, 40, stdin);
    username[wcslen(username) - 1] = L'\0';
    getwc(stdin); //comment out this line if fgetws did read the newline character from stdin
    wprintf(L">> Xin ch�o, %ls!\n\n", username);

    // nh?p gi?i t�nh
    wchar_t gender;
    wprintf(L"B?n l� nam hay n?:\n a. Nam\n b. N?\n");
    wscanf(L"%lc", &gender);
    wprintf(L">> Gi?i t�nh: %ls\n\n", gender == L'a' ? L"Nam" : (gender == L'b' ? L"N?" : L"Kh�ng x�c d?nh"));

    // nh?p tu?i
    int age;
    wprintf(L"Nh?p tu?i c?a b?n: ");
    wscanf(L"%d", &age);
    wprintf(L">> Nam nay b?n du?c %d tu?i\n\n", age);


    // luu file ti?ng Vi?t (UTF-8 with BOM)
    FILE* fout = _wfopen(L"userinfo-c.txt", L"w, ccs=UTF-8");
    if (!fout) {
        wprintf(L"Kh�ng th? t?o file userinfo-c.txt\n");
    } else {
        fwprintf(fout, L"%ls\n%lc\n%d\n", username, gender, age);
        fclose(fout);
    }

    // d?c file ti?ng Vi?t (d?nh d?ng UTF-8 with BOM)
    FILE* fin = _wfopen(L"userinfo-c.txt", L"r, ccs=UTF-8");
    if (!fin) {
        wprintf(L"Kh�ng th? d?c file userinfo-c.txt\n");
    }
    else {
        fgetws(username, 40, fin);
        username[wcslen(username) - 1] = L'\0'; //now fgetws works fine
        fwscanf(fin, L"%lc", &gender);
        fwscanf(fin, L"%d", &age);

        wprintf(L"H? t�n: %ls\nGi?i t�nh: %ls\nTu?i: %d\n\n", username,
            gender == L'a' ? L"Nam" : (gender == L'b' ? L"N?" : L"Kh�ng x�c d?nh"), age);

        fclose(fin);
    }


    wprintf(L"Chuong tr�nh k?t th�c.\n");
}
