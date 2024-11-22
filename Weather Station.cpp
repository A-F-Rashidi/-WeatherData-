#include <iostream>
#include <string>
#include "IObserver.h"
#include "ObserveList.h"
#include "WeatherData .h"
using namespace std;
class CurrentConditionsDisplay : public IObserver {
public:
    void update(float temperature, float humidity, float pressure) override {
        cout << "Current conditions: " << "Temperature: " << temperature << ", Humidity: " << humidity<< ", Pressure: " << pressure << endl;
    }
};

class StatisticsDisplay : public IObserver {
private:
    float maxTemp = -10000;
    float minTemp = 10000;
    float tempSum = 0;
    int readings = 0;

public:
    void update(float temperature, float humidity, float pressure) override {
        tempSum += temperature;
        maxTemp = max(maxTemp, temperature);
        minTemp = min(minTemp, temperature);
        readings++;

        cout << "Statistics: "
            << "Avg Temp: " << (tempSum / readings)
            << ", Max Temp: " << maxTemp
            << ", Min Temp: " << minTemp << endl;
    }
};

int main() {
    WeatherData weatherData;

    CurrentConditionsDisplay currentDisplay;
    StatisticsDisplay statsDisplay;

    weatherData.registerObserver(&currentDisplay);
    weatherData.registerObserver(&statsDisplay);

    weatherData.setMeasurements(30.5, 65.0, 1013.0);
    weatherData.setMeasurements(32.0, 70.0, 1012.0);

    weatherData.removeObserver(&currentDisplay);
    weatherData.setMeasurements(28.5, 60.0, 1011.0);

    return 0;
}