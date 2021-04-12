#include <iostream>
#include <windows.h>

using namespace std;

class Light
{
private:
    bool open;
public:
    Light();
    void toggle();
    bool isOpen();
};

Light::Light()
{
    open = false;
}


void Light::toggle()
{
    open = !open;
}

bool Light::isOpen()
{
    return open;
}

class TrafficLight
{
private:
    Light red, green;
public:
    TrafficLight();
    void switchLights();
    bool isGreen();
    
};

TrafficLight::TrafficLight()
{
    //Red is open 
    red.toggle();
}

void TrafficLight::switchLights()
{
    red.toggle();
    green.toggle();
    cout << (red.isOpen() ? "Red" : "Green") << endl;
    
}

bool TrafficLight::isGreen()
{
    return green.isOpen();
}

class Intersection
{
private:
    TrafficLight trafficLights[4];
    size_t greenDuration;
    size_t safetyDuration;
public:
    Intersection(size_t greenDuration);
    void switchTrafficLights();
    void operate();
};

Intersection::Intersection(size_t greenDuration)
{
    safetyDuration = 1;
    this->greenDuration = greenDuration;
    trafficLights[0].switchLights();
    trafficLights[2].switchLights();
}


void Intersection::switchTrafficLights()
{
    
    if(trafficLights[0].isGreen())
    {
        trafficLights[0].switchLights();
        trafficLights[2].switchLights();
        Sleep(safetyDuration * 1000);
        trafficLights[1].switchLights();
        trafficLights[3].switchLights();
    }
    else
    {
        trafficLights[1].switchLights();
        trafficLights[3].switchLights();
        Sleep(safetyDuration * 1000);
        trafficLights[0].switchLights();
        trafficLights[2].switchLights();
    }
    
}

void Intersection::operate()
{
    while(1)
    {
        switchTrafficLights();
        Sleep(greenDuration * 1000);
    }
}


int main()
{
    Intersection intersection(5);
    intersection.operate();
    return 0;
}
