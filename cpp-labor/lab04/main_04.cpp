#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Point.h"
#include "PointSet.h"

using namespace std;

int main() {

    /*
     * ///Orai feladat
     * //Definíció - üres dinamikus tömb
     vector<int> v;
     v.reserve(16); //ha tudjuk, hogy az elejen, hogy mennyit foglaljon le
     cout <<"Size: " <<  v.size() << endl;
     cout <<"Capacity: " <<  v.capacity() << endl;
     //Feltöltés: új elem hozzáadása: push_back VAGY emplace_back
     for( int i=0; i<10; ++i ){
         v.push_back( rand()%100 );
         cout <<"Size: " <<  v.size() << endl;
         cout <<"Capacity: " <<  v.capacity() << endl;
     }
     //Kiíratás
     for(int i=0; i<v.size(); ++i ){
         cout<<v[ i ]<<" ";
     }
     cout<< endl<< "-----------------" << endl;

     sort(v.begin(), v.end(), [](int a,int b){
         return a>b; //forditott
     });
     //sort(v.begin(), v.end(), greater<int>()); //csokkeno sorrendbe teszi
     for(int i=0; i<v.size(); ++i ){
         cout<<v[ i ]<<" ";
     }
     cout<<endl;

     */

//    Point p1;
//    Point p2(2,2);
//    cout << p1.distanceTo(p2) << endl;

    int n = 2;
    cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
    cout<< fixed;
    for( int i= 0; i<12; ++i ){
        PointSet pSet( n );
        cout<<setw(6)<<n<<" ";
        cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
        //cout << endl;
        cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
        cout<<setw(10) << pSet.numDistances()<<" ";
        cout<<setw(16) << pSet.numDistinctDistances()<<endl;
        n = n << 1;
    }


    return 0;
}