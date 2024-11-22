#pragma once
#include"ObserveList.h"
#include "IObserver.h"

class WeatherData {
private:
    float temperature;
    float humidity;
    float pressure;
    ObserverList observers;

public:
    void registerObserver(IObserver* obs) {
        observers.add(obs);
    }

    void removeObserver(IObserver* obs) {
        observers.remove(obs);
    }

    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notifyObservers();
    }

    void notifyObservers() {
        observers.notify(temperature, humidity, pressure);
    }
};