#include <fstream>
#include <string>
#include <iostream>

float getMemoryUsage() {
    std::ifstream file("/proc/meminfo");
    std::string key;
    long total = 0, available = 0;

    while (file >> key) {
        if (key == "MemTotal:") file >> total;
        else if (key == "MemAvailable:") {
            file >> available;
            break;
        }
    }
    return 100.0 * (float)(total - available) / total;
}
