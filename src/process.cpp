#include <dirent.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include "process.h"

std::vector<Process> getProcesses() {
    std::vector<Process> processes;
    DIR* dir = opendir("/proc");
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            std::string pid = entry->d_name;
            std::ifstream nameFile("/proc/" + pid + "/comm");
            std::string name;
            getline(nameFile, name);

            std::ifstream statusFile("/proc/" + pid + "/status");
            std::string line, mem;
            while (getline(statusFile, line)) {
                if (line.find("VmRSS:") != std::string::npos) {
                    mem = line;
                    break;
                }
            }
            processes.push_back({stoi(pid), name, mem});
        }
    }
    closedir(dir);
    return processes;
}
