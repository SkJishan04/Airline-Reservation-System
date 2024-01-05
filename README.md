# Airline-Reservation-System

This is a simple console-based Airline Reservation System implemented in C. The program allows users to make reservations, cancel reservations, print all passenger reservations, show the number of reservations, and save the details to a file.

## Usage

1. **Reservation:** Users can make a reservation by providing their name, passport number, and email. The system assigns a seat number to each reservation.

    - Time Complexity: O(n), where n is the number of existing reservations. The program iterates through the linked list to find the last node.

2. **Cancel Reservation:** Users can cancel a reservation by entering their passport number. The corresponding booking will be deleted.

    - Time Complexity: O(n), where n is the number of existing reservations. The program searches the linked list to find the reservation with the given passport number.

3. **Print All Reservations:** Displays details of all passengers who have made reservations, including their name, passport number, email, and assigned seat number.

    - Time Complexity: O(n), where n is the number of existing reservations. The program iterates through the linked list to print all reservations.

4. **Show Number of Reservations:** Provides information on the total number of reservations made and the number of reservations remaining.

5. **Save to File:** Saves passenger details to a file named "AIRLINE RESERVATION."

    - Time Complexity: O(n), where n is the number of existing reservations. The program iterates through the linked list to write reservation details to the file.

## How to Run

Compile the code and run the executable to interact with the Airline Reservation System. Follow the on-screen instructions to perform various operations.

```bash
gcc airline_reservation.c -o airline_reservation
./airline_reservation
