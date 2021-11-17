#include <iostream>
#include <vector>
#include <cmath>

/*
    Bu haftaki görev vector kullanımı ile ilgili.

    İstatistikte, veri değerlerinin koleksiyonu genellikle dağılım olarak nitelendirilmektedir. İstatistiksel analizin öncelikli hedefi tüm veri setini, bir bütün olarak dağılımın özelliklerini ifade eden özet değişkenlere sıkıştırmanın yollarını bulmaktır.

    Bunlardan en yaygını ortalama değerdir. Bu görevde vektör içindeki dataların ortalama değerini veren bir fonksiyon yazmanızı bekliyoruz.

    double mean(Vector<double> data);
    Bonus : Bir diğer istatistiksel ölçüt standart sapmadır. Standart sapmanın formülü için tıklayın

    Vektör içindeki dataların standart sapmasını veren bir fonksiyon yazmanızı bekliyoruz.

    double stddev(Vector<double> data);
*/

using namespace std;

// Function prototypes
double meanv(vector<double> data);
double stddev(vector<double> data);

int main(){

    // Take the data
    vector<double> data;

    int x; // The amount of data
    cout << "How much items does the data have? ";
    cin >> x;

    for(int i = 0; i < x; i++){
        double t;
        cout << "Element " << i << ": ";
        cin >> t;

        data.push_back(t);
    }

    // Calculate mean value and standart deviation
    double meanValue = meanv(data);
    double standDev = stddev(data);

    cout << "Mean value of the data is " << meanValue << "\n";
    cout << "Standart deviation of the data is " << standDev;

    return 0;
}

// Mean value function
double meanv(vector<double> data){

    double sum = 0;

    // Calculate the sum of the elements
    for(int i = 0; i < data.size(); i++){
        sum = sum + data[i];
    }

    // Divide the sum to the number of the elements
    double mean = sum/data.size();

    return mean;
}

// Standart deviation function
double stddev(vector<double> data){

    // Find mean value of the data
    double mean = meanv(data);

    // Find the variance
    double variance = 0;
    
    for(int i = 0; i < data.size(); i++){
        variance = variance + (mean - data[i]) * (mean - data[i]);
    }

    variance = variance / (data.size() - 1);

    variance = sqrt(variance);

    return variance;
}