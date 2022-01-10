#include <iostream>
#include <unistd.h>
#include <ctime>
#include <chrono>
#include "stdio.h"
#include "fstream"

using namespace std;

int main() {
    for (int i = 0; i < 50; ++i) {
        ofstream myfile;
        myfile.open ("../cpu_temperature.txt", ios_base::app);

        for (int i = 0; i < 2; ++i) {
            FILE* fcputemp = fopen("/sys/class/thermal/thermal_zone5/temp","r");
            int cputemp;
            while(!feof(fcputemp)){
                fscanf(fcputemp, "%d", &cputemp);
            }
            cputemp = cputemp/1000;
            fclose(fcputemp);

            time_t now = time(0);
            tm *datetime = localtime(&now);

            myfile << "Time: "<< datetime->tm_hour << ":" << datetime->tm_min << ":" << datetime->tm_sec << " - " << cputemp << " C\n";
            sleep(2);
        }
        myfile.close();
        sleep(120);
    }
}
