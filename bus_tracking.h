#ifndef BUS_TRACKING_H
#define BUS_TRACKING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUSES 10
#define MAX_ROUTES 5
#define MAX_STOPS 20
#define MAX_PASSENGERS 50
#define MAX_NAME_LENGTH 50

// Bus structure
typedef struct {
    int bus_id;
    char driver_name[MAX_NAME_LENGTH];
    int route_id;
    int current_stop;
    int passenger_count;
    int capacity;
    char status[20]; // "Running", "Stopped", "Maintenance"
    int last_update_time;
} Bus;

// Route structure
typedef struct {
    int route_id;
    char route_name[MAX_NAME_LENGTH];
    char stops[MAX_STOPS][MAX_NAME_LENGTH];
    int num_stops;
    int estimated_time[MAX_STOPS]; // Time in minutes from start
} Route;

// Passenger structure
typedef struct {
    int passenger_id;
    char name[MAX_NAME_LENGTH];
    int bus_id;
    int boarding_stop;
    int destination_stop;
} Passenger;

// Function declarations
void initialize_bus_system();
void display_bus_menu();
void add_bus();
void add_route();
void track_bus_location();
void update_bus_status();
void display_all_buses();
void display_all_routes();
void board_passenger();
void display_passengers();
int find_bus_by_id(int bus_id);
int find_route_by_id(int route_id);
void simulate_bus_movement();

// Global arrays
extern Bus buses[MAX_BUSES];
extern Route routes[MAX_ROUTES];
extern Passenger passengers[MAX_PASSENGERS];
extern int bus_count;
extern int route_count;
extern int passenger_count;

#endif