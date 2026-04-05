#include "EngineClass.hpp"

// NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
Engine** Engine::container = nullptr;

int Engine::getId() const {
    return id;
}

bool Engine::isOrdered() const {
    return ordered;
}

Engine::Engine() : id(0), ordered(false) {
    std::cout << "Engine()" << std::endl;
}

Engine::Engine(int inputId, bool inputOrder) : id(inputId), ordered(inputOrder) {
    std::cout << "Engine()" << std::endl;
}

Engine::Engine(const Engine& other) : id(other.id), ordered(other.ordered) {
    std::cout << "Engine()" << std::endl;
}

Engine::~Engine() {
    std::cout << "~Engine()" << std::endl;
}

Engine::Engine(Engine&& other) noexcept : id(other.id), ordered(other.ordered) {
    other.id = 0;
    other.ordered = false;
}

Engine& Engine::operator=(Engine&& other) noexcept {
    if (this != &other) {
        id = other.id;
        ordered = other.ordered;
        other.id = 0;
        other.ordered = false;
    }
    return *this;
}

Engine& Engine::operator=(const Engine& other) {
    if (this != &other) {
        id = other.id;
        ordered = other.ordered;
    }
    return *this;
}

void Engine::print() {
    if (!container) {
        std::cout << "Контейнер пустой" << std::endl;
        return;
    }

    std::cout << "Engine" << std::endl;
    for (int i{0}; i < countContainer; ++i) {
        if (container[i]) {
            std::cout << "Двигатель " << i << ": ID = " << container[i]->getId();
            container[i]->show();
            std::cout << std::endl;
        }
    }
}

void Engine::resizeContainer(int newSize) {
    Engine** newContainer = new Engine*[newSize];

    for (int i{0}; i < countContainer; ++i) {
        newContainer[i] = container[i];
    }

    for (int i{countContainer}; i < newSize; ++i) {
        newContainer[i] = nullptr;
    }

    delete[] container;
    container = newContainer;
    sizeContainer = newSize;
}

void Engine::add(Engine* engine) {
    if (!container) {
        sizeContainer = 4;
        container = new Engine*[sizeContainer];
        for (int i{0}; i < sizeContainer; ++i) {
            container[i] = nullptr;
        }
    }

    if (countContainer > sizeContainer / 2) {
        resizeContainer(sizeContainer * 2);
    } else if (countContainer > 0 && countContainer <= sizeContainer / 2 && sizeContainer > 4) {
        resizeContainer(sizeContainer / 2);
    }

    container[countContainer++] = engine;
}

void Engine::remove(int removeId) {
    if (!container) {
        std::cout << "Контейнер пустой" << std::endl;
        return;
    }

    for (int i{0}; i < countContainer; ++i) {
        if (container[i] && container[i]->getId() == removeId) {
            delete container[i];

            for (int j{i}; j < countContainer - 1; ++j) {
                container[j] = container[j + 1];
            }

            countContainer--;
            std::cout << "Двигатель ID " << removeId << " удален." << std::endl;
            return;
        }
    }

    std::cout << "Двигатель с ID " << removeId << " не найден." << std::endl;
}

void Engine::clear() {
    if (!container) return;

    for (int i{0}; i < countContainer; ++i) {
        delete container[i];
    }

    delete[] container;
    container = nullptr;
    countContainer = 0;

    std::cout << "Все двигатели удалены" << std::endl;
}
