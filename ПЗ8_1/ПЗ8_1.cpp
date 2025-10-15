#include <iostream>
#include <limits>

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif

using namespace std;

void printAll(const int* a, int n) {
    wcout << L"Блок 1. Усі елементи: ";
    for (int i = 0; i < n; ++i) wcout << a[i] << (i + 1 == n ? L'\n' : L' ');
}

void printReverse(const int* a, int n) {
    wcout << L"Блок 2. Усі елементи у зворотному порядку: ";
    for (int i = n - 1; i >= 0; --i) wcout << a[i] << (i == 0 ? L'\n' : L' ');
}

void printEvenValues(const int* a, int n) {
    wcout << L"Блок 3. Парні за значенням: ";
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            if (!first) wcout << L' ';
            wcout << a[i];
            first = false;
        }
    }
    wcout << L'\n';
}

void printEveryOther(const int* a, int n) {
    wcout << L"Блок 4. Елементи через 1 (індекси 0,2,4,...): ";
    for (int i = 0; i < n; i += 2) wcout << a[i] << (i + 2 >= n ? L'\n' : L' ');
}

void printUntilMinusOne(const int* a, int n) {
    wcout << L"Блок 5. До першого -1 (включно не друкуємо): ";
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) break;
        if (!first) wcout << L' ';
        wcout << a[i];
        first = false;
    }
    wcout << L'\n';
}

int main() {
#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif
    ios::sync_with_stdio(false);
    wcin.tie(nullptr);

    int n;
    wcout << L"Введіть розмір масиву (1..1000): ";
    if (!(wcin >> n) || n < 1 || n > 1000) {
        wcout << L"Некоректний розмір.\n";
        return 0;
    }

    int* a = new int[n];

    wcout << L"Введіть " << n << L" цілих чисел: ";
    for (int i = 0; i < n; ++i) wcin >> a[i];

    printAll(a, n);
    printReverse(a, n);
    printEvenValues(a, n);
    printEveryOther(a, n);
    printUntilMinusOne(a, n);

    delete[] a;

    wcout << L"\nНатисніть Enter, щоб вийти...";
    wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
    wcin.get();
    
    return 0;
}
