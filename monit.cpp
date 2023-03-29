#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/resource.h>

using namespace std;

int main()
{
    while (true) {
        
        rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        cout << "CPU : " << usage.ru_utime.tv_sec + usage.ru_stime.tv_sec << " seconds" << endl;

        
        struct statvfs fs_info;
        statvfs("/", &fs_info);
        unsigned long long total_memory = (unsigned long long)fs_info.f_blocks * (unsigned long long)fs_info.f_frsize;
        unsigned long long free_memory = (unsigned long long)fs_info.f_bfree * (unsigned long long)fs_info.f_frsize;
        unsigned long long used_memory = total_memory - free_memory;
        cout << "Mem : " << used_memory / 1024 << " KB" << endl;

        
        double loadavg[3];
        getloadavg(loadavg, 3);
        cout << "AVG : " << loadavg[0] << " " << loadavg[1] << " " << loadavg[2] << endl;

        // Sleep for one second
        sleep(1);
    }

    return 0;
}
