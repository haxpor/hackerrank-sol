/**
 * Solution of Attending Workshops problem on hackerrank.com
 * There is partial part of locked code, so remove it when you upload the solution to the website.
 *
 */

#include <bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int startTime;
    int duration;
    int endTime;
};

struct Available_Workshops
{
    int n;
    Workshop* workshops;
};

static Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Available_Workshops* awss = new Available_Workshops();
    awss->n = n;
    awss->workshops = new Workshop[n];

    Workshop* wsPtr = awss->workshops;

    for (int i=0; i<n; ++i)
    {
        wsPtr[i].startTime = start_time[i];
        wsPtr[i].duration = duration[i];
        wsPtr[i].endTime = start_time[i] + duration[i];
    }

    return awss;
}

static int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int size = ptr->n;
    Workshop* wkPtr = ptr->workshops;
    std::sort(wkPtr, wkPtr + size, [](const Workshop& a, const Workshop& b) { return a.endTime < b.endTime; });

    int maxWorkshops = 1;
    Workshop prevWorkshop = wkPtr[0];
    for (int i=1; i<size; ++i)
    {
        if (prevWorkshop.endTime <= wkPtr[i].startTime)
        {
            ++maxWorkshops;
            prevWorkshop = wkPtr[i];
        }
    }

    return maxWorkshops;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
