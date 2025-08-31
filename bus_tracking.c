#include "bus_tracking.h"

// Global variables
Bus buses[MAX_BUSES];
Route routes[MAX_ROUTES];
Passenger passengers[MAX_PASSENGERS];
int bus_count = 0;
int route_count = 0;
int passenger_count = 0;

void initialize_bus_system() {
    // Initialize some default routes
    if (route_count == 0) {
        // Route 1: Campus Loop
        strcpy(routes[0].route_name, "Campus Loop");
        routes[0].route_id = 1;
        strcpy(routes[0].stops[0], "Main Gate");
        strcpy(routes[0].stops[1], "Library");
        strcpy(routes[0].stops[2], "Student Center");
        strcpy(routes[0].stops[3], "Engineering Building");
        strcpy(routes[0].stops[4], "Dormitories");
        routes[0].num_stops = 5;
        routes[0].estimated_time[0] = 0;
        routes[0].estimated_time[1] = 5;
        routes[0].estimated_time[2] = 12;
        routes[0].estimated_time[3] = 18;
        routes[0].estimated_time[4] = 25;
        
        // Route 2: City Center
        strcpy(routes[1].route_name, "City Center");
        routes[1].route_id = 2;
        strcpy(routes[1].stops[0], "Campus");
        strcpy(routes[1].stops[1], "Shopping Mall");
        strcpy(routes[1].stops[2], "City Center");
        strcpy(routes[1].stops[3], "Train Station");
        routes[1].num_stops = 4;
        routes[1].estimated_time[0] = 0;
        routes[1].estimated_time[1] = 15;
        routes[1].estimated_time[2] = 30;
        routes[1].estimated_time[3] = 45;
        
        route_count = 2;
        
        // Initialize some default buses
        buses[0].bus_id = 101;
        strcpy(buses[0].driver_name, "John Smith");
        buses[0].route_id = 1;
        buses[0].current_stop = 0;
        buses[0].passenger_count = 0;
        buses[0].capacity = 40;
        strcpy(buses[0].status, "Running");
        buses[0].last_update_time = time(NULL);
        
        buses[1].bus_id = 102;
        strcpy(buses[1].driver_name, "Sarah Johnson");
        buses[1].route_id = 2;
        buses[1].current_stop = 1;
        buses[1].passenger_count = 15;
        buses[1].capacity = 35;
        strcpy(buses[1].status, "Running");
        buses[1].last_update_time = time(NULL);
        
        bus_count = 2;
    }
}

void display_bus_menu() {
    printf("\n=== BUS TRACKING SYSTEM ===\n");
    printf("1. Display All Buses\n");
    printf("2. Display All Routes\n");
    printf("3. Track Bus Location\n");
    printf("4. Add New Bus\n");
    printf("5. Add New Route\n");
    printf("6. Update Bus Status\n");
    printf("7. Board Passenger\n");
    printf("8. Display Passengers\n");
    printf("9. Simulate Bus Movement\n");
    printf("0. Return to Main Menu\n");
    printf("Enter your choice: ");
}

void add_bus() {
    if (bus_count >= MAX_BUSES) {
        printf("Maximum number of buses reached!\n");
        return;
    }
    
    Bus new_bus;
    printf("Enter Bus ID: ");
    scanf("%d", &new_bus.bus_id);
    
    // Check if bus ID already exists
    if (find_bus_by_id(new_bus.bus_id) != -1) {
        printf("Bus with ID %d already exists!\n", new_bus.bus_id);
        return;
    }
    
    printf("Enter Driver Name: ");
    scanf(" %[^\n]", new_bus.driver_name);
    
    printf("Enter Route ID: ");
    scanf("%d", &new_bus.route_id);
    
    if (find_route_by_id(new_bus.route_id) == -1) {
        printf("Route with ID %d does not exist!\n", new_bus.route_id);
        return;
    }
    
    printf("Enter Bus Capacity: ");
    scanf("%d", &new_bus.capacity);
    
    new_bus.current_stop = 0;
    new_bus.passenger_count = 0;
    strcpy(new_bus.status, "Running");
    new_bus.last_update_time = time(NULL);
    
    buses[bus_count] = new_bus;
    bus_count++;
    
    printf("Bus added successfully!\n");
}

void add_route() {
    if (route_count >= MAX_ROUTES) {
        printf("Maximum number of routes reached!\n");
        return;
    }
    
    Route new_route;
    printf("Enter Route ID: ");
    scanf("%d", &new_route.route_id);
    
    // Check if route ID already exists
    if (find_route_by_id(new_route.route_id) != -1) {
        printf("Route with ID %d already exists!\n", new_route.route_id);
        return;
    }
    
    printf("Enter Route Name: ");
    scanf(" %[^\n]", new_route.route_name);
    
    printf("Enter number of stops (max %d): ", MAX_STOPS);
    scanf("%d", &new_route.num_stops);
    
    if (new_route.num_stops > MAX_STOPS) {
        new_route.num_stops = MAX_STOPS;
    }
    
    for (int i = 0; i < new_route.num_stops; i++) {
        printf("Enter stop %d name: ", i + 1);
        scanf(" %[^\n]", new_route.stops[i]);
        printf("Enter estimated time (minutes from start): ");
        scanf("%d", &new_route.estimated_time[i]);
    }
    
    routes[route_count] = new_route;
    route_count++;
    
    printf("Route added successfully!\n");
}

void track_bus_location() {
    int bus_id;
    printf("Enter Bus ID to track: ");
    scanf("%d", &bus_id);
    
    int bus_index = find_bus_by_id(bus_id);
    if (bus_index == -1) {
        printf("Bus with ID %d not found!\n", bus_id);
        return;
    }
    
    Bus *bus = &buses[bus_index];
    int route_index = find_route_by_id(bus->route_id);
    
    if (route_index == -1) {
        printf("Route not found for this bus!\n");
        return;
    }
    
    Route *route = &routes[route_index];
    
    printf("\n=== BUS TRACKING INFO ===\n");
    printf("Bus ID: %d\n", bus->bus_id);
    printf("Driver: %s\n", bus->driver_name);
    printf("Route: %s (ID: %d)\n", route->route_name, route->route_id);
    printf("Current Stop: %s\n", route->stops[bus->current_stop]);
    printf("Passengers: %d/%d\n", bus->passenger_count, bus->capacity);
    printf("Status: %s\n", bus->status);
    
    time_t current_time = time(NULL);
    int time_diff = (int)(current_time - bus->last_update_time);
    printf("Last Update: %d seconds ago\n", time_diff);
    
    if (bus->current_stop < route->num_stops - 1) {
        printf("Next Stop: %s\n", route->stops[bus->current_stop + 1]);
        int next_time = route->estimated_time[bus->current_stop + 1] - route->estimated_time[bus->current_stop];
        printf("Estimated time to next stop: %d minutes\n", next_time);
    } else {
        printf("Bus has reached the final stop.\n");
    }
}

void update_bus_status() {
    int bus_id;
    printf("Enter Bus ID to update: ");
    scanf("%d", &bus_id);
    
    int bus_index = find_bus_by_id(bus_id);
    if (bus_index == -1) {
        printf("Bus with ID %d not found!\n", bus_id);
        return;
    }
    
    printf("Current status: %s\n", buses[bus_index].status);
    printf("Enter new status (Running/Stopped/Maintenance): ");
    scanf(" %[^\n]", buses[bus_index].status);
    
    buses[bus_index].last_update_time = time(NULL);
    printf("Bus status updated successfully!\n");
}

void display_all_buses() {
    if (bus_count == 0) {
        printf("No buses registered in the system.\n");
        return;
    }
    
    printf("\n=== ALL BUSES ===\n");
    printf("%-8s %-20s %-10s %-15s %-12s %-10s\n", 
           "Bus ID", "Driver", "Route ID", "Current Stop", "Passengers", "Status");
    printf("------------------------------------------------------------------------\n");
    
    for (int i = 0; i < bus_count; i++) {
        int route_index = find_route_by_id(buses[i].route_id);
        char current_stop_name[MAX_NAME_LENGTH] = "Unknown";
        
        if (route_index != -1 && buses[i].current_stop < routes[route_index].num_stops) {
            strcpy(current_stop_name, routes[route_index].stops[buses[i].current_stop]);
        }
        
        char passenger_info[20];
        sprintf(passenger_info, "%d/%d", buses[i].passenger_count, buses[i].capacity);
        
        printf("%-8d %-20s %-10d %-15s %-12s %-10s\n",
               buses[i].bus_id,
               buses[i].driver_name,
               buses[i].route_id,
               current_stop_name,
               passenger_info,
               buses[i].status);
    }
}

void display_all_routes() {
    if (route_count == 0) {
        printf("No routes registered in the system.\n");
        return;
    }
    
    printf("\n=== ALL ROUTES ===\n");
    for (int i = 0; i < route_count; i++) {
        printf("\nRoute ID: %d\n", routes[i].route_id);
        printf("Route Name: %s\n", routes[i].route_name);
        printf("Stops: ");
        for (int j = 0; j < routes[i].num_stops; j++) {
            printf("%s", routes[i].stops[j]);
            if (j < routes[i].num_stops - 1) printf(" -> ");
        }
        printf("\n");
        printf("Estimated Times: ");
        for (int j = 0; j < routes[i].num_stops; j++) {
            printf("%d min", routes[i].estimated_time[j]);
            if (j < routes[i].num_stops - 1) printf(" -> ");
        }
        printf("\n");
    }
}

void board_passenger() {
    if (passenger_count >= MAX_PASSENGERS) {
        printf("Maximum number of passengers reached!\n");
        return;
    }
    
    int bus_id;
    printf("Enter Bus ID: ");
    scanf("%d", &bus_id);
    
    int bus_index = find_bus_by_id(bus_id);
    if (bus_index == -1) {
        printf("Bus with ID %d not found!\n", bus_id);
        return;
    }
    
    if (buses[bus_index].passenger_count >= buses[bus_index].capacity) {
        printf("Bus is at full capacity!\n");
        return;
    }
    
    Passenger new_passenger;
    new_passenger.passenger_id = passenger_count + 1;
    printf("Enter Passenger Name: ");
    scanf(" %[^\n]", new_passenger.name);
    new_passenger.bus_id = bus_id;
    new_passenger.boarding_stop = buses[bus_index].current_stop;
    
    int route_index = find_route_by_id(buses[bus_index].route_id);
    if (route_index != -1) {
        printf("Available destination stops:\n");
        for (int i = buses[bus_index].current_stop + 1; i < routes[route_index].num_stops; i++) {
            printf("%d. %s\n", i, routes[route_index].stops[i]);
        }
        printf("Enter destination stop number: ");
        scanf("%d", &new_passenger.destination_stop);
        
        if (new_passenger.destination_stop <= buses[bus_index].current_stop || 
            new_passenger.destination_stop >= routes[route_index].num_stops) {
            printf("Invalid destination stop!\n");
            return;
        }
    } else {
        printf("Route information not available.\n");
        return;
    }
    
    passengers[passenger_count] = new_passenger;
    passenger_count++;
    buses[bus_index].passenger_count++;
    
    printf("Passenger boarded successfully!\n");
}

void display_passengers() {
    if (passenger_count == 0) {
        printf("No passengers in the system.\n");
        return;
    }
    
    printf("\n=== ALL PASSENGERS ===\n");
    printf("%-5s %-20s %-8s %-15s %-15s\n", 
           "ID", "Name", "Bus ID", "Boarding Stop", "Destination");
    printf("---------------------------------------------------------------\n");
    
    for (int i = 0; i < passenger_count; i++) {
        int bus_index = find_bus_by_id(passengers[i].bus_id);
        if (bus_index != -1) {
            int route_index = find_route_by_id(buses[bus_index].route_id);
            if (route_index != -1) {
                printf("%-5d %-20s %-8d %-15s %-15s\n",
                       passengers[i].passenger_id,
                       passengers[i].name,
                       passengers[i].bus_id,
                       routes[route_index].stops[passengers[i].boarding_stop],
                       routes[route_index].stops[passengers[i].destination_stop]);
            }
        }
    }
}

int find_bus_by_id(int bus_id) {
    for (int i = 0; i < bus_count; i++) {
        if (buses[i].bus_id == bus_id) {
            return i;
        }
    }
    return -1;
}

int find_route_by_id(int route_id) {
    for (int i = 0; i < route_count; i++) {
        if (routes[i].route_id == route_id) {
            return i;
        }
    }
    return -1;
}

void simulate_bus_movement() {
    printf("Simulating bus movement...\n");
    
    for (int i = 0; i < bus_count; i++) {
        if (strcmp(buses[i].status, "Running") == 0) {
            int route_index = find_route_by_id(buses[i].route_id);
            if (route_index != -1) {
                // Move bus to next stop
                buses[i].current_stop = (buses[i].current_stop + 1) % routes[route_index].num_stops;
                buses[i].last_update_time = time(NULL);
                
                printf("Bus %d moved to stop: %s\n", 
                       buses[i].bus_id, 
                       routes[route_index].stops[buses[i].current_stop]);
                
                // Check if any passengers need to get off
                for (int j = 0; j < passenger_count; j++) {
                    if (passengers[j].bus_id == buses[i].bus_id && 
                        passengers[j].destination_stop == buses[i].current_stop) {
                        printf("Passenger %s got off at %s\n", 
                               passengers[j].name,
                               routes[route_index].stops[buses[i].current_stop]);
                        buses[i].passenger_count--;
                    }
                }
            }
        }
    }
}