#include "Originator.h"
#include "CareTaker.h"
#include <iostream>

int main() {
	Originator originator;
	CareTaker careTaker;
    originator.setState("State #1");
    originator.setState("State #2");
    careTaker.add(originator.saveStateToMemento());
    originator.setState("State #3");
    careTaker.add(originator.saveStateToMemento());
    originator.setState("State #4");

    std::cout << "Current State: " << originator.getState() << std::endl;
    originator.getStateFromMemento(careTaker.get(0));
    std::cout << "First saved State: " << originator.getState() << std::endl;
    originator.getStateFromMemento(careTaker.get(1));
    std::cout << "Second saved State: " << originator.getState() << std::endl;
}