#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;

    // Input n
    cout << "Masukan n: ";
    cin >> n;

    // Menggunakan STL untuk membuat struktur data stack karena diperbolehkan di soal
    stack<int> st;
    // Deklarasikan variable untuk menyimpan angka dan inisialisasi dengan bilangan 1 sebagai bilangan ganjil terkecil
    int num = 1;
    while (st.size() < n) {
        // Push angka kedalam stack
        st.push(num);
        // Karena num diawali dengan angka 1 maka setiap ditambahkan dengan 2 akan selalu bilangan ganjil juga, sehingga tidak perlu melakukan pengecekan seperti num % 2 == 1 yang hanya akan memperlambat waktu eksekusi
        num += 2;
    }

    // Cetak kekuatan angka ganjil yang ditemukan
    cout << "Bilangan ganjil yang ada di stack: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << "\n";
    
    return 0;
}