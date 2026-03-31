#pragma once
#include<iostream>
class Engine{
private:
    static Engine** container;
    static int countContainer;
    static int sizeContainer;
protected:
    int id;
    bool ordered;
public:
    static void print();
    static void remove(int removeId);
    static void clear();
    static void resizeContainer(int newSize);
    static void add(Engine* engine);

    virtual void show();

    Engine();
    Engine(int inputId,bool inputOrder);
    Engine(const Engine& other); 
    virtual ~Engine();
};

class InternalCombustionEngine:public Engine{
protected:
    int power;
    int price;
public:
    void show() override;
    InternalCombustionEngine();
    InternalCombustionEngine(int inputPower,int inputPrice);
    InternalCombustionEngine(const InternalCombustionEngine& other);
    virtual ~InternalCombustionEngine();
};

class DieselEngine:public InternalCombustionEngine{
protected:
    double maxTorque; 
public:
    void show() override;
    DieselEngine();
    DieselEngine(double inputMaxTorque);
    DieselEngine(const DieselEngine& other);
    ~DieselEngine() override;
};

class TurbojetEngine:public Engine{
protected:
    bool turbinePower;
public:
    void show() override;
    TurbojetEngine();
    TurbojetEngine(double inptTurbinePower);
    TurbojetEngine(const TurbojetEngine& other);
    ~TurbojetEngine() override;
};