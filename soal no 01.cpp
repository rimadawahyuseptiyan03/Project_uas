#include <iostream>

using namespace std;

double mencarideterminan(int data[3][3]) {
	int determinan = (data[0][0] * data[1][1] * data[2][2] 
					+ data[0][1] * data[1][2] * data[2][0]
					+ data[0][2] * data[1][0] * data[2][1])
					- (data[2][0] * data[1][1] *data[0][2] 
					+ data[2][1] * data[1][2] * data[0][0] 
					+ data[2][2] * data[1][0] * data[0][1]);
	return determinan;
}

void mencariKofaktor(int data[3][3], int kofaktor[3][3]) {
    kofaktor[0][0] = data[1][1] * data[2][2] - data[1][2] * data[2][1];
    kofaktor[0][1] = -(data[1][0] * data[2][2] - data[1][2] * data[2][0]);
    kofaktor[0][2] = data[1][0] * data[2][1] - data[1][1] * data[2][0];

    kofaktor[1][0] = -(data[0][1] * data[2][2] - data[0][2] * data[2][1]);
    kofaktor[1][1] = data[0][0] * data[2][2] - data[0][2] * data[2][0];
    kofaktor[1][2] = -(data[0][0] * data[2][1] - data[0][1] * data[2][0]);

    kofaktor[2][0] = data[0][1] * data[1][2] - data[0][2] * data[1][1];
    kofaktor[2][1] = -(data[0][0] * data[1][2] - data[0][2] * data[1][0]);
    kofaktor[2][2] = data[0][0] * data[1][1] - data[0][1] * data[1][0];
}
bool mencariInvers(int data[3][3], double invers[3][3]) {
    double determinan = mencarideterminan(data);
     if (determinan == 0) {
        cout << "Matriks tidak memiliki invers karena determinan = 0" << endl;
        return false;
     }
     else {
        int kofaktor[3][3];
        mencariKofaktor(data, kofaktor);
      
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                invers[i][j] = (double)kofaktor[j][i] / determinan;
            }
        }
        return true;
     }
}


int main() {
    int data[3][3] =
    { 4,2,8,
     2,1,5,
     3,2,4 };
   

    cout << "matrik awal = " << endl;
    for (int i = 0; i < 3; i++) {
        for (int  j= 0; j < 3; j++){
            cout << data[i][j] << ", ";
        }
        cout << endl;
    }

    //MENCARI INVERS
    double invers[3][3];
    cout << mencariInvers(data,invers);

    cout << "nilai invers matrik  = " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << invers[i][j] << ", ";
        }
        cout << endl;
    }

	return 0; 
}