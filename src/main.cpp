#include <iostream>
#include <unistd.h>
#include "cpu.h"
#include "memory.h"
#include "process.h"

#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"


int main() {
    while (true) {
        system("clear");
        std::cout << CYAN << "=== SYSTEM MONITOR TOOL ===" << RESET << "\n";
        std::cout << "CPU Usage: " 
                  << (getCPUUsage() > 75 ? RED : getCPUUsage() > 40 ? YELLOW : GREEN)
                  << getCPUUsage() << " %" << RESET << "\n";
        std::cout << "Memory Usage: " << YELLOW << getMemoryUsage() << " %" << RESET << "\n";

        printf("\n%-8s %-25s %-20s\n", "PID", "Process Name", "Memory");
        auto processes = getProcesses();
        for (size_t i = 0; i < 10 && i < processes.size(); ++i) {
            printf("%-8d %-25s %-20s\n",
                     processes[i].pid,
                     processes[i].name.c_str(),
                     processes[i].mem.c_str());

        }
        sleep(2);
    }
}
