#include <iostream>
#include <iomanip>

using std::cout; using std::cin; using std::endl;

void getScore(int &, int);
void calcAverage(int (&arr)[5]);
int findLowest(int (&arr)[5]);

int main(){

    int scores[5];

    for(int i = 0; i < 5; i++) {
        getScore(scores[i], i);
    }

    cout << endl << "--Scores entered--" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Score " << i+1 << " is : " << scores[i] << endl;
    }
    
    calcAverage(scores);

    return 0;
}

void getScore(int &score, int count) {
    
    do {
        cout << endl << "Enter score number " << count+1 << " (Must be between 0-100) ";
        cin >> score;
    }while((score < 0) || (score > 100));
}

void calcAverage(int (&scores)[5]) {

    int lowestIdx;
    double avg, sum = 0;

    lowestIdx = findLowest(scores);

    // Gets sum without the lowest score
    for(int i = 0; i < 5; i++) {
        sum += (scores[i] != scores[lowestIdx]) ? scores[i] : 0;
    }

    avg = sum / 4;

    cout << endl << "--Calculating average--" << endl;
    cout << "The avg of the top 4 scores is: " << std::fixed << std::setprecision(2) << avg << endl << endl;
}

// Will return the index of the lowest score to the calling function
int findLowest(int (&scores)[5]) {

    int lowestIdx = 0;

    for(int i = 1; i < 5; i++) {
        lowestIdx = (scores[i] < scores[lowestIdx]) ? i : lowestIdx;
    }

    cout << endl << "--Dropped score--" << endl;
    cout << "The dropped score will be score " << lowestIdx+1 << ": " << scores[lowestIdx] << endl;

    return lowestIdx;
}