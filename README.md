# System Monitor Tool

A console-based system monitor written in C++ that reads data from the Linux `/proc` filesystem.

## Features
- Real-time CPU usage (%)
- Real-time memory usage (%)
- Lists top processes (PID, name, memory)
- Refreshes automatically (every 2 seconds)

## Project Structure
system_monitor/
├── src/
│ ├── main.cpp
│ ├── cpu.cpp
│ ├── memory.cpp
│ └── process.cpp
├── include/
│ ├── cpu.h
│ ├── memory.h
│ └── process.h
├── Makefile
└── README.md

bash
Copy code

## Build (WSL / Linux)
Open a terminal in the project root and run:
```bash
make
./monitor