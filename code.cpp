#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Device {
    string name;
    bool status;
    bool optimized;
    int powerUsage;

    Device(string name) {
        this->name = name;
        status = false;
        optimized = false;
        powerUsage = 0;
    }
};

vector<Device> devices;

void displayOptions() {
    cout << "1. All Devices" << endl;
    cout << "2. Manage Devices" << endl;
    cout << "3. Optimize Devices" << endl;
    cout << "4. Current Status" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayDeviceList() {
    cout << "Devices List:" << endl;
    for (int i = 0; i < devices.size(); i++) {
        cout << i + 1 << ". " << devices[i].name << endl;
    }
}

void addDevice() {
    cout << "Choose a device to add:" << endl;
    cout << "1. Fan" << endl;
    cout << "2. AC" << endl;
    cout << "3. Lights" << endl;
    cout << "4. Curtains" << endl;
    cout << "5. Alarm System" << endl;
    cout << "6. Television" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            devices.push_back(Device("Fan"));
            break;
        case 2:
            devices.push_back(Device("AC"));
            break;
        case 3:
            devices.push_back(Device("Lights"));
            break;
        case 4:
            devices.push_back(Device("Curtains"));
            break;
        case 5:
            devices.push_back(Device("Alarm System"));
            break;
        case 6:
            devices.push_back(Device("Television"));
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
    }

    Device& device = devices.back();

    cout << "Enter device name (or leave blank for suggestion): ";
    cin.ignore();
    getline(cin, device.name);

    if (device.name.empty()) {
        device.name = "Unnamed " + device.name;
        cout << "Suggested name: " << device.name << endl;
    }

    cout << "Device added successfully!" << endl;
}

void removeDevice() {
    if (devices.empty()) {
        cout << "No devices found!" << endl;
        return;
    }

    displayDeviceList();
    cout << "Enter the device number to remove: ";
    int choice;
    cin >> choice;

    if (choice <= 0 || choice > devices.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }

    devices.erase(devices.begin() + choice - 1);
    cout << "Device removed successfully!" << endl;
}

void renameDevice() {
    if (devices.empty()) {
        cout << "No devices found!" << endl;
        return;
    }

    displayDeviceList();
    cout << "Enter the device number to rename: ";
    int choice;
    cin >> choice;

    if (choice <= 0 || choice > devices.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }

    Device& device = devices[choice - 1];
    cout << "Enter new name for the device: ";
    cin.ignore();
    getline(cin, device.name);

    cout << "Device renamed successfully!" << endl;
}

void manageDevices() {
    if (devices.empty()) {
        cout << "No devices found!" << endl;
        return;
    }

    displayDeviceList();
    cout << "Enter the device number to manage (or 0 to exit): ";
    int choice;
    cin >> choice;

    if (choice == 0) {
        return;
    }

    if (choice <= 0 || choice > devices.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }

    Device& device = devices[choice - 1];

    string option;
    do {
        cout << "1. Turn Off" << endl;
        cout << "2. Turn On" << endl;
        cout << "3. Adjust Settings" << endl;
        cout << "Enter your choice (or 'exit' to go back): ";
        cin >> option;

        if (option == "1") {
            device.status = false;
            cout << device.name << " turned off." << endl;
        } else if (option == "2") {
            device.status = true;
            cout << device.name << " turned on." << endl;
        } else if (option == "3") {
            cout << "This device doesn't have adjustable settings." << endl;
        } else if (option != "exit") {
            cout << "Invalid choice!" << endl;
        }
    } while (option != "exit");
}

void optimizeDevices() {
    if (devices.empty()) {
        cout << "No devices found!" << endl;
        return;
    }

    displayDeviceList();
    cout << "Enter the device number to optimize (or 0 to exit): ";
    int choice;
    cin >> choice;

    if (choice == 0) {
        return;
    }

    if (choice <= 0 || choice > devices.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }

    Device& device = devices[choice - 1];

    string option;
    do {
        cout << "1. Optimize Device" << endl;
        cout << "2. Turn Off Optimization" << endl;
        cout << "3. Show Power Usage" << endl;
        cout << "Enter your choice (or 'exit' to go back): ";
        cin >> option;

        if (option == "1") {
            device.optimized = true;
            cout << "Device optimized." << endl;
        } else if (option == "2") {
            device.optimized = false;
            cout << "Optimization turned off." << endl;
        } else if (option == "3") {
            cout << "Power Usage: " << device.powerUsage << " watts." << endl;
        } else if (option != "exit") {
            cout << "Invalid choice!" << endl;
        }
    } while (option != "exit");
}

void currentStatus() {
    cout << "Current Status:" << endl;

    if (devices.empty()) {
        cout << "No devices found!" << endl;
        return;
    }

    for (int i = 0; i < devices.size(); i++) {
        cout << devices[i].name << ": ";
        if (devices[i].status) {
            cout << "ON";
        } else {
            cout << "OFF";
        }

        if (devices[i].optimized) {
            cout << " (Optimized)";
        }

        cout << endl;
    }

    string option;
    do {
        cout << "Enter the device number to control/change status (or 'exit' to go back): ";
        cin >> option;

        if (option == "exit") {
            return;
        }

        int choice;
        stringstream ss(option);
        if (!(ss >> choice) || choice <= 0 || choice > devices.size()) {
            cout << "Invalid choice!" << endl;
            continue;
        }

        Device& device = devices[choice - 1];

        cout << "1. Turn On" << endl;
        cout << "2. Turn Off" << endl;
        cout << "Enter your choice (or 'exit' to go back): ";
        cin >> option;

        if (option == "1") {
            device.status = true;
            cout << device.name << " turned on." << endl;
        } else if (option == "2") {
            device.status = false;
            cout << device.name << " turned off." << endl;
        } else if (option != "exit") {
            cout << "Invalid choice!" << endl;
        }
    } while (option != "exit");
}

int main() {
    int choice;

    do {
        displayOptions();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "1. Add Device" << endl;
                cout << "2. Remove Device" << endl;
                cout << "3. Rename Device" << endl;
                cout << "Enter your choice (or 'exit' to go back): ";
                int option;
                cin >> option;

                if (option == 1) {
                    addDevice();
                } else if (option == 2) {
                    removeDevice();
                } else if (option == 3) {
                    renameDevice();
                } else if (option != 0) {
                    cout << "Invalid choice!" << endl;
                }
                break;
            case 2:
                manageDevices();
                break;
            case 3:
                optimizeDevices();
                break;
            case 4:
                currentStatus();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
