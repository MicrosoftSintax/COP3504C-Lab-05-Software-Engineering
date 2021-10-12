#include <iostream>
#include <chrono>
#include <cmath>
#include "StringData.h"
#include <string>

using namespace std;

int linearSearch(vector<string> dataset, string element)
{
    for(int i = 0; i < dataset.size(); i++){

        if(dataset[i] == (element)){

            return i;
        }
    }
    return -1;
}

int binarySearch(vector<string> dataset , string element)
{
    int endPoint = (dataset.size())-1;
    int middlePoint = endPoint / 2;
    int beginPoint = 0;

    int howManyTimes = (int) (log(dataset.size()) / log(2));

    for(int i = 0; i < howManyTimes + 1; i++){

        if(dataset[middlePoint].compare(element) == 0){

            return middlePoint;
        }
        else if(dataset[middlePoint].compare(element) > 0){

            endPoint = middlePoint;
            middlePoint = beginPoint + (endPoint - beginPoint)/2;
        }
        else{

            beginPoint = middlePoint;
            middlePoint = beginPoint + (endPoint - beginPoint) / 2;
        }

    }

    return -1;
}


int main() {

    vector <string> data= getStringData();

    string elements [3]  = {"not_here", "mzzzz", "aaaaa"};

    //Searches for "not_here", "mzzzz", and "aaaaa" in that order

    for(int i=0; i<3; i++){

        auto starttime = std::chrono::system_clock::now();

        linearSearch(data, elements[i]);

        auto stoptime = std::chrono::system_clock::now();

        std::chrono::duration<double> finalTime = stoptime - starttime;

        cout << "The linear search for " << elements[i] <<  " took " << finalTime.count()  << " milliseconds to complete" << endl ;



        starttime = std::chrono::system_clock::now();

        binarySearch(data, elements[i]);

        stoptime = std::chrono::system_clock::now();

        finalTime = stoptime - starttime;

        cout << "The binary search for "  << elements[i] << " took " << finalTime.count()  << " milliseconds to complete" << endl << endl;


    }


}




