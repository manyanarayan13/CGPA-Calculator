# Student Management System

A comprehensive C-based system that combines CGPA calculation and bus tracking functionality for educational institutions.

## Overview

This Student Management System provides two main features:
1. **CGPA Calculator**: Calculate cumulative grade point average based on grades and credit hours
2. **Bus Tracking System**: Real-time bus location tracking, route management, and passenger management for campus transportation

## Features

### CGPA Calculator
- **Simple Grade Input**: Enter grades (A, B, C, D, F) and credit hours
- **Automatic Calculation**: Real-time CGPA computation
- **Grade Point Conversion**: Standardized 4.0 scale conversion

### Bus Tracking System
- **Real-time Bus Tracking**: Monitor bus locations and status
- **Route Management**: Predefined campus and city routes
- **Passenger Management**: Board passengers and track destinations
- **Multiple Bus Support**: Track multiple buses simultaneously
- **Status Updates**: Monitor bus operational status (Running/Stopped/Maintenance)
- **Route Information**: Detailed stop information with estimated travel times

## Installation

To install and run the Student Management System:

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/manyanarayan13/CGPA-Calculator.git
   cd CGPA-Calculator
   ```

2. **Build the System**:
   ```bash
   make
   ```

3. **Run the Application**:
   ```bash
   ./student_system
   ```

## Usage

### Main Menu
When you run the system, you'll see:
```
=== STUDENT MANAGEMENT SYSTEM ===
1. CGPA Calculator
2. Bus Tracking System
3. Exit
```

### CGPA Calculator
- Choose option 1 from the main menu
- Enter credit hours for each subject (3 subjects)
- Enter grades (A, B, C, D, F) for each subject
- View your calculated CGPA

### Bus Tracking System
Choose option 2 from the main menu to access:

#### Available Options:
1. **Display All Buses** - View all registered buses with current status
2. **Display All Routes** - Show available routes with stops and timing
3. **Track Bus Location** - Get real-time location of a specific bus
4. **Add New Bus** - Register a new bus in the system
5. **Add New Route** - Create a new route with stops
6. **Update Bus Status** - Change bus operational status
7. **Board Passenger** - Register passenger boarding
8. **Display Passengers** - View all passengers in the system
9. **Simulate Bus Movement** - Move buses to next stops

#### Default Routes:
- **Campus Loop**: Main Gate → Library → Student Center → Engineering Building → Dormitories
- **City Center**: Campus → Shopping Mall → City Center → Train Station

## System Requirements

- GCC compiler
- Make utility
- Linux/Unix environment

## Building from Source

```bash
# Clean previous builds
make clean

# Build the system
make

# Run tests (optional)
make run
```

## File Structure

```
├── main.c              # Main program with menu system
├── bus_tracking.h      # Bus tracking system header
├── bus_tracking.c      # Bus tracking implementation
├── cgpa.c             # Original CGPA calculator (standalone)
├── Makefile           # Build configuration
└── README.md          # This file
```

## Development

The system is written in C and follows modular design principles:
- **main.c**: Contains the main menu and CGPA calculator integration
- **bus_tracking.h/c**: Complete bus tracking system implementation
- **Makefile**: Automated build system

## Contributing

Feel free to contribute to this project by:
- Adding new features
- Improving existing functionality
- Fixing bugs
- Enhancing documentation

## License

This project is open source. Feel free to use and modify as needed for educational purposes.
