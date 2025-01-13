#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

double mencarimean(int data[], int panjangdata) {
    int jumlahdata =0;
    for (int i = 0; i < panjangdata; i++) {
        jumlahdata += data[i];
    }
    double mean = (double)jumlahdata / panjangdata;
    return mean;
}

double mencariMedian(int data[], int panjangdata) {
    sort(data, data + panjangdata);  
    if (panjangdata % 2 == 0) {
       
        double mediangenap = (data[panjangdata / 2 - 1] + data[panjangdata / 2]) / 2.0;
        return mediangenap;
    }
    else {
        double medianganjil = data[(panjangdata +1)/ 2];
        return medianganjil;
    }
}

double mencariStandarddeviasi(int data[], int panjangdata, double mean) {
    double total = 0;
    for (int i = 0; i < panjangdata; i++) {
        total += pow(data[i] - mean, 2);
    }
    double StandardDeviasi = sqrt(total / panjangdata);
    return StandardDeviasi;
}

int main() {
    int nomor[] = { 1,2,3,4,5,6,7, };
    int data[] = { 92, 65, 74, 80, 80, 70, 78 };
    string nama[] = { "Toni","Ani","Budi","Cintia","Lisa","Senku","Mariadi"};

    int panjangdata = sizeof(data) / sizeof(data[0]);

    cout << "No\tNama\t\tNilai" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < panjangdata; i++) {
        cout << nomor[i] << "\t" << nama[i] << "\t\t" << data[i] << endl;
    }
    cout << "-----------------------------" << endl;

    // Mencari mean
    double mean = mencarimean(data, panjangdata);
    cout << "Nilai mean adalah = " << mean << endl;
    // mencari median
    double median = mencariMedian(data, panjangdata);
    cout << "Nilai median adalah = " << median << endl;
    //mencari standard deviasi
    double standardeviasi = mencariStandarddeviasi(data, panjangdata, mean);
    cout << "Nilai standartdeviasi adalah = " << standardeviasi << endl;

    return 0;
}