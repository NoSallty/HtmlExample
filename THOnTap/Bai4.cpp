#include <bits/stdc++.h>
#include <vector>
#include <limits>
using namespace std;

struct Flight{
	string flightNumber;
	double ticketPrice;
	int seatCount;
};

vector<Flight> createFlightList() {
    vector<Flight> flights;
    flights.push_back({"VN001", 500000, 150});
    flights.push_back({"VN002", 800000, 200});
    flights.push_back({"VN003", 600000, 180});
    flights.push_back({"VN004", 900000, 220});
    flights.push_back({"VN005", 700000, 190});
    flights.push_back({"VN006", 750000, 170});
    flights.push_back({"VN007", 850000, 210});
    flights.push_back({"VN008", 950000, 230});
    flights.push_back({"VN009", 550000, 160});
    flights.push_back({"VN010", 720000, 175});
    return flights;
}

void displayFlightsAbovePrice(const vector<Flight>& flights, double price, int index = 0) {
    if (index >= flights.size()) {
        return;
    }

    if (flights[index].ticketPrice > price) {
        cout << "Flight Number: " << flights[index].flightNumber << endl;
        cout << "Ticket Price: " << flights[index].ticketPrice << endl;
        cout << "Seat Count: " << flights[index].seatCount << endl;
        cout << endl;
    }

    displayFlightsAbovePrice(flights, price, index + 1);
}

int findMinPriceFlight(const vector<Flight>& flights, int start, int end) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    int leftMin = findMinPriceFlight(flights, start, mid);
    int rightMin = findMinPriceFlight(flights, mid + 1, end);

    return (flights[leftMin].ticketPrice < flights[rightMin].ticketPrice) ? leftMin : rightMin;
}

void displayFlight(const Flight& flight) {
    cout << "Flight Number: " << flight.flightNumber << endl;
    cout << "Ticket Price: " << flight.ticketPrice << endl;
    cout << "Seat Count: " << flight.seatCount << endl;
    cout << endl;
}

void displayCombinations(const vector<Flight>& flights, vector<int>& combination, int start, int k) {
    if (k == 0) {
        for (int i : combination) {
            cout << flights[i].flightNumber << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= flights.size() - k; ++i) {
        combination.push_back(i);
        displayCombinations(flights, combination, i + 1, k - 1);
        combination.pop_back();
    }
}

int main() {
    vector<Flight> flights = createFlightList();

    cout << "Flights with ticket price above 700000:" << endl;
    displayFlightsAbovePrice(flights, 700000);
    cout << endl;

    int minPriceIndex = findMinPriceFlight(flights, 0, flights.size() - 1);
    cout << "Flight with the minimum ticket price:" << endl;
    displayFlight(flights[minPriceIndex]);
    cout << endl;

    cout << "All possible combinations of 4 flights:" << endl;
    vector<int> combination;
    displayCombinations(flights, combination, 0, 4);

    return 0;
}