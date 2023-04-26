//Mohaned Hassanin 2200000776
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Function prototype for displaying time in hh:mm am/pm format
void put_time(int time);

// Define a struct to represent a flight, with departure and arrival times in minutes since midnight
struct flight {
    int departure;
    int arrival;
};

int main() {
    // Define an array of flights, with departure and arrival times in minutes since midnight
    struct flight flights[] = {
        { 480, 616 },  // 8:00 a.m. - 10:16 a.m.
        { 679, 811 },  // 11:19 a.m. - 1:31 p.m.
        { 767, 900 },  // 12:47 p.m. - 3:00 p.m.
        { 840, 1008 }, // 2:00 p.m. - 4:08 p.m.
        { 945, 1175 }, // 3:45 p.m. - 5:55 p.m.
        { 1140, 1220 },// 7:00 p.m. - 9:20 p.m.
        { 1185, 1438 } // 9:45 p.m. - 11:58 p.m.
    };

    // Determine the number of flights in the array
    int n = sizeof(flights) / sizeof(struct flight);

    // Prompt the user to enter a time in 24-hour format (hh:mm)
    int hour, minute;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    // Convert the input time into minutes since midnight
    int time = hour * 60 + minute;

    // Find the flight with the departure time closest to the input time
    int min_diff = abs(time - flights[0].departure); // Initialize minimum difference to the difference between the input time and the first flight's departure time
    int closest = 0; // Initialize the index of the closest flight to the first flight
    for (int i = 1; i < n; i++) {
        int diff = abs(time - flights[i].departure); // Calculate the difference between the input time and the departure time of the current flight
        if (diff < min_diff) { // If the current flight's departure time is closer to the input time than the previous closest flight's departure time
            min_diff = diff; // Update the minimum difference
            closest = i; // Update the index of the closest flight
        }
    }

    // Display the closest flight's departure and arrival times
    printf("Closest departure time is ");
    put_time(flights[closest].departure);
    printf(", arriving at ");
    put_time(flights[closest].arrival);
    printf(".\n");

    return 0;
}

// Function definition for displaying time in hh:mm am/pm format
void put_time(int time) {
    int hour = time / 60; // Convert minutes to hours
    int minute = time % 60; // Calculate the remainder after dividing by 60 to get the minutes
    if (hour < 12) {
        printf("%d:%02d a.m.", hour == 0 ? 12 : hour, minute); // If the hour is less than 12, display as am
    }
    else {
        printf("%d:%02d p.m.", hour == 12 ? 12 : hour - 12, minute); // If the hour is 12 or greater, display as pm
    }
}