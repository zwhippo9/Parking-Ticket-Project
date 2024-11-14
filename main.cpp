//this program uses a list of classes to act as a police officer (myself) giving a ticket to a specific car (make and model) defined in the program performing a parking violation. The program will ask the user how many minuted the car has been parked and calculate the fine based on the amount of time parked.



#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//for parked car
class ParkedCar {
public:
  string make;
  string model;
  string color;
  string licenseNumber;
  int minutesParked;

//set values for the car
  ParkedCar(string mk = "Mazda", string ml = "Mazda6", string co = "Blue", string ln = "A1600EZ", int mn = 0)
    : make(mk), model(ml), color(co), licenseNumber(ln), minutesParked(mn) {}

     int getMinutesParked() const { return minutesParked; }
};

//class for meter
class ParkingMeter {
public:  
  int minutesPurchased;

//set values for the meter
  ParkingMeter(int mn = 60) : minutesPurchased(mn) {}
  int getMinutesPurchased() const { return minutesPurchased; }
};

//class for officer
class PoliceOfficer {
public:
  string name;
  string badgeNumber;

//set values for the officer
  PoliceOfficer(string n = "Zachary Whippo", string bn = "B93546") : name(n), badgeNumber(bn) {}

  void issueTicket(const ParkedCar& car, const ParkingMeter& meter);
};

//class for ticket
class ParkingTicket {
public:
  ParkedCar car;
  ParkingMeter meter;
  PoliceOfficer officer;
  double fineAmount;  

  ParkingTicket(const ParkedCar& c, const ParkingMeter& m, const PoliceOfficer& o)
    : car(c), meter(m), officer(o) {
    fineAmount = calculateFine();
}

  double calculateFine() const{
    int overparkedMinutes = car.getMinutesParked() - meter.getMinutesPurchased();
    if (overparkedMinutes <= 0) return 0.0;

    int hoursOver = static_cast<int>(ceil(overparkedMinutes / 60.0));
    double fine = 25.0 + (hoursOver - 1) * 10.0;
    return fine;
  }

  void generateTicker() const {
    cout << "Parking Ticket" << endl;
    cout << "Officer: " <<officer.name << " | Badge Number: " << officer.badgeNumber << endl;
      cout << "Licence Plate:" << car.licenseNumber << endl;
      cout << "Make: " << car.make << " | Model: " << car.model << " | Color: " << car.color << endl;
      cout << "Minutes: " << meter.getMinutesPurchased() << " | Minutes Parked: " << car.getMinutesParked() << endl;
      cout << "Fine: $" << fineAmount << endl;
  }
};

void PoliceOfficer::issueTicket(const ParkedCar& car, const ParkingMeter& meter) {
    if (car.getMinutesParked() > meter.getMinutesPurchased()) {
        ParkingTicket ticket(car, meter, *this);
        ticket.generateTicker();
    } else {
        cout << "No parking violation" << endl;
  }
}

int main() {
    int minutesParked;

  //ask for minutes parked
  cout << "How long has the car been parked?: ";
  cin >> minutesParked;

  ParkedCar car("Mazda", "Mazda6", "Blue", "A1600EZ", minutesParked);
  ParkingMeter meter;
  PoliceOfficer officer;

  //give ticket 
  officer.issueTicket(car, meter);

  return 0;
}
  
