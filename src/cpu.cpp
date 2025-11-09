#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>
#include <vector>

float getCPUUsage() {
    std::ifstream file("/proc/stat");
    std::string line;
    getline(file, line);
    std::istringstream iss(line);
    std::string cpu;
    long user, nice, system, idle, iowait, irq, softirq;
    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq;
    long idleTime1 = idle + iowait;
    long totalTime1 = user + nice + system + idle + iowait + irq + softirq;
    file.close();

    sleep(1);

    file.open("/proc/stat");
    getline(file, line);
    iss.clear();
    iss.str(line);
    iss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq;
    long idleTime2 = idle + iowait;
    long totalTime2 = user + nice + system + idle + iowait + irq + softirq;

    float cpuPercentage = 100.0 * (1.0 - (float)(idleTime2 - idleTime1) / (totalTime2 - totalTime1));
    return cpuPercentage;
}
