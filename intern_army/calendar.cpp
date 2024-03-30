#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Event {
    string date;
    string time;
    string description;
};


void addEvent(vector<Event>& events) {
    Event newEvent;
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> newEvent.date;
    cout << "Enter time (HH:MM): ";
    cin >> newEvent.time;
    cin.ignore(); 
    cout << "Enter description: ";
    getline(cin, newEvent.description);
    events.push_back(newEvent);
    cout << "Event added successfully!\n";
}


void editEvent(vector<Event>& events) {
    int index;
    cout << "Enter index of event to edit: ";
    cin >> index;
    if (index >= 0 && index < events.size()) {
        Event& event = events[index];
        cout << "Enter new date (MM/DD/YYYY): ";
        cin >> event.date;
        cout << "Enter new time (HH:MM): ";
        cin >> event.time;
        cin.ignore(); // Ignore newline character
        cout << "Enter new description: ";
        getline(cin, event.description);
        cout << "Event edited successfully!\n";
    } else {
        cout << "Invalid index!\n";
    }
}

void deleteEvent(vector<Event>& events) {
    int index;
    cout << "Enter index of event to delete: ";
    cin >> index;
    if (index >= 0 && index < events.size()) {
        events.erase(events.begin() + index);
        cout << "Event deleted successfully!\n";
    } else {
        cout << "Invalid index!\n";
    }
}


void displayEvents(const vector<Event>& events) {
    cout << "Events:\n";
    for (size_t i = 0; i < events.size(); ++i) {
        const Event& event = events[i];
        cout << i << ". Date: " << event.date << ", Time: " << event.time << ", Description: " << event.description << '\n';
    }
    
}

int main() {
    vector<Event> events;
    int option;

    do {
        cout << "Calendar/Planner Application\n";
        cout << "1. Add Event\n";
        cout << "2. Edit Event\n";
        cout << "3. Delete Event\n";
        cout << "4. View Events\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1:
                addEvent(events);
                break;
            case 2:
                editEvent(events);
                break;
            case 3:
                deleteEvent(events);
                break;
            case 4:
                displayEvents(events);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (option != 5);

    return 0;
}
