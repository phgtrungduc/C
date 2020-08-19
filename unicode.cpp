#include <fcntl.h> //_O_U16TEXT
#include <io.h>    //_setmode()
#include <stdio.h>
#include <string.h>

int wmain(int argc, wchar_t* argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT); //needed for output
    _setmode(_fileno(stdin), _O_U16TEXT); //needed for input
    // nh? chuy?n font c?a console sang Consolas (size 16)

    wprintf(L"%ls%ls%ls", L"Chuong trình d?c và xu?t chu?i ti?ng Vi?t\n\n",
        L"  \"Gõ\" ti?ng Vi?t b?ng cách copy chu?i ti?ng Vi?t ? trình so?n th?o ti?ng Vi?t\n",
        L"nào dó r?i click ph?i chu?t vào màn hình console\n\n");

    // nh?p h? tên
    wchar_t username[40];
    wprintf(L"Nh?p h? tên c?a b?n: ");
    fgetws(username, 40, stdin);
    username[wcslen(username) - 1] = L'\0';
    getwc(stdin); //comment out this line if fgetws did read the newline character from stdin
    wprintf(L">> Xin chào, %ls!\n\n", username);

    // nh?p gi?i tính
    wchar_t gender;
    wprintf(L"B?n là nam hay n?:\n a. Nam\n b. N?\n");
    wscanf(L"%lc", &gender);
    wprintf(L">> Gi?i tính: %ls\n\n", gender == L'a' ? L"Nam" : (gender == L'b' ? L"N?" : L"Không xác d?nh"));

    // nh?p tu?i
    int age;
    wprintf(L"Nh?p tu?i c?a b?n: ");
    wscanf(L"%d", &age);
    wprintf(L">> Nam nay b?n du?c %d tu?i\n\n", age);


    // luu file ti?ng Vi?t (UTF-8 with BOM)
    FILE* fout = _wfopen(L"userinfo-c.txt", L"w, ccs=UTF-8");
    if (!fout) {
        wprintf(L"Không th? t?o file userinfo-c.txt\n");
    } else {
        fwprintf(fout, L"%ls\n%lc\n%d\n", username, gender, age);
        fclose(fout);
    }

    // d?c file ti?ng Vi?t (d?nh d?ng UTF-8 with BOM)
    FILE* fin = _wfopen(L"userinfo-c.txt", L"r, ccs=UTF-8");
    if (!fin) {
        wprintf(L"Không th? d?c file userinfo-c.txt\n");
    }
    else {
        fgetws(username, 40, fin);
        username[wcslen(username) - 1] = L'\0'; //now fgetws works fine
        fwscanf(fin, L"%lc", &gender);
        fwscanf(fin, L"%d", &age);

        wprintf(L"H? tên: %ls\nGi?i tính: %ls\nTu?i: %d\n\n", username,
            gender == L'a' ? L"Nam" : (gender == L'b' ? L"N?" : L"Không xác d?nh"), age);

        fclose(fin);
    }


    wprintf(L"Chuong trình k?t thúc.\n");
}
