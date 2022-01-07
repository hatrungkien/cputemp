#include <iostream>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include "stdio.h"
#include "fstream"

using namespace std;

int main() {
    ofstream myfile;
    myfile.open ("../cpu_temperature.txt");

    for (int i = 0; i < 30; ++i) {
        FILE* fcputemp = fopen("/sys/class/thermal/thermal_zone1/temp","r");
        int cputemp;
        while(!feof(fcputemp)){
            fscanf(fcputemp, "%d", &cputemp);
        }
        cputemp = cputemp/1000;
        fclose(fcputemp);

        time_t now = time(0);
        tm *datetime = localtime(&now);

        myfile << "Time: "<< 5+datetime->tm_hour << ":" << 30+datetime->tm_min << ":" << datetime->tm_sec << " - " << cputemp << " C\n";
        sleep(120);
    }
    myfile.close();
}