#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include <string>

struct Process {
    int pid;
    std::string name;
    std::string mem;
};

std::vector<Process> getProcesses();

#endif
