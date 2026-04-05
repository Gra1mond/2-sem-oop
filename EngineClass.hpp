#pragma once

#include <iostream>

class Engine {
 private:
    static Engine** container;
    inline static int countContainer = 0;
    inline static int sizeContainer = 0;

 private:
    int id;
    bool ordered;

 public:
    static void print();
    static void remove(int removeId);
    static void clear();
    static void resizeContainer(int newSize);
    static void add(Engine* engine);

    virtual void show() = 0;

    Engine();
    Engine(int inputId, bool inputOrder);
    Engine(const Engine& other);
    Engine(Engine&& other) noexcept;
    Engine& operator=(const Engine& other);
    Engine& operator=(Engine&& other) noexcept;

    virtual ~Engine();

    [[nodiscard]] int getId() const;
    [[nodiscard]] bool isOrdered() const;
};

// ======================= InternalCombustionEngine =======================

class InternalCombustionEngine : public Engine {
 private:
    int power;
    int price;

 public:
    void show() override;

    InternalCombustionEngine();
    InternalCombustionEngine(int inputPower, int inputPrice);
    InternalCombustionEngine(const InternalCombustionEngine& other);
    InternalCombustionEngine(InternalCombustionEngine&& other) noexcept = default;

    InternalCombustionEngine& operator=(const InternalCombustionEngine& other);
    InternalCombustionEngine& operator=(InternalCombustionEngine&& other) noexcept = default;

    ~InternalCombustionEngine() override;
};

// ======================= DieselEngine =======================

class DieselEngine : public InternalCombustionEngine {
 private:
    double maxTorque;

 public:
    void show() override;

    DieselEngine();
    DieselEngine(double inputMaxTorque);
    DieselEngine(const DieselEngine& other);
    DieselEngine(DieselEngine&& other) noexcept = default;

    DieselEngine& operator=(const DieselEngine& other);
    DieselEngine& operator=(DieselEngine&& other) noexcept = default;

    ~DieselEngine() override;
};

// ======================= TurbojetEngine =======================

class TurbojetEngine : public Engine {
 private:
    bool turbinePower;

 public:
    void show() override;

    TurbojetEngine();
    TurbojetEngine(bool inputTurbinePower);
    TurbojetEngine(const TurbojetEngine& other);
    TurbojetEngine(TurbojetEngine&& other) noexcept = default;

    TurbojetEngine& operator=(const TurbojetEngine& other);
    TurbojetEngine& operator=(TurbojetEngine&& other) noexcept = default;

    ~TurbojetEngine() override;
};
