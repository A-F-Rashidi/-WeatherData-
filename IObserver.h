#pragma once
class IObserver {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~IObserver() {}
};