#include <algorithm>
#include <iostream>

using namespace std;

// Fungsi untuk memeriksa apakah bilangan adalah bilangan prima
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

// Fungsi untuk mencari nilai di array menggunakan linear search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    int array_A[n];
    int array_B[m];

    // Input array A
    for (int i = 0; i < n; i++) {
        cin >> array_A[i];
    }

    // Input array B
    for (int i = 0; i < m; i++) {
        cin >> array_B[i];
    }

    int results[n + m];    // Menggunakan array untuk hasil
    int result_count = 0;  // Counter untuk hasil

    // Cari nilai yang memenuhi syarat
    for (int i = 0; i < n; i++) {
        // index pada array A harus merupakan bilangan prima (syarat ke-2)
        if (isPrime(i)) {
            int index = linearSearch(array_B, m, array_A[i]);
            // Nilai tersebut ditemukan di array A dan B (syarat ke-1)
            if (index != -1) {
                // Index pada array B harus merupakan bilangan ganjil
                if (index % 2 == 1) results[result_count++] = array_A[i];
            }
        }
    }

    // Urutkan hasil pencarian
    sort(results, results + result_count);

    // Cetak hasil pencarian

    // Jika tidak ada bilangan yang memenuhi syarat
    if (result_count == 0) {
        cout << "TIDAK ADA" << endl;
    } else {
        // Cetak bilangan yang memenuhi syarat dipisahkan oleh spasi
        for (int i = 0; i < result_count; i++) {
            cout << results[i] << " ";
        }
        // Sebenarnya tidak terlalu dibutuhkan, hanya saja saya risih dengan tanda "%" setelah result jika tidak membuat baris baru jadi terbiasa menambahkan ini.
        cout << "\n";
    }

    return 0;
}