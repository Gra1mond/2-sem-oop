#pragma once
#include<iostream>
#include<cstring>
class Planet {
private:
    char* name;       
    double diameter;
    bool hasLife;
    int satellites;
public:
    Planet(const char* name, double diameter, bool hasLife, int satellites);
    Planet();
    Planet(const Planet&);
    Planet(Planet&&);
    Planet& operator=(const Planet&);
    Planet& operator=(Planet&&);
    ~Planet();  
    bool getHasLife() const { return hasLife; }
    const char* getName() const { return name; }

    bool operator==(const Planet& other) const;
    bool operator<(const Planet& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Planet& p);
    friend std::istream& operator>>(std::istream& in, Planet& p);
};

Planet::Planet() : name(nullptr), diameter(0), hasLife(false), satellites(0) {}

Planet::Planet(const char* n, double diameter, bool hasLife, int satellites)
    : diameter(diameter), hasLife(hasLife), satellites(satellites) {
    if (n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else {
        name = nullptr;
    }
}

Planet::Planet(const Planet& other){
    this->diameter = other.diameter;
    this->hasLife = other. hasLife;
    this->satellites = other.satellites;
    if(other.name){
        name = new char[strlen(other.name)+1];
        strcpy(name,other.name);
    }else{
        name = nullptr;
    }
}

Planet::Planet(Planet&& other){
    this->diameter = other.diameter;
    this->hasLife = other. hasLife;
    this->satellites = other.satellites;
    name = other.name;

    other.diameter = 0;
    other.satellites = 0;
    other.hasLife = false;
    other.name = nullptr;
}

Planet& Planet::operator=(Planet&& other) {
    if (this != &other) {
        delete[] name;
        name = other.name;
        diameter = other.diameter;
        hasLife = other.hasLife;
        satellites = other.satellites;
        other.name = nullptr;
    }
    return *this;
}

Planet& Planet::operator=(const Planet& other){
    if(this!=&other){
        delete[] name;
        diameter = other.diameter;
        satellites = other.satellites;
        hasLife = other.hasLife;
        
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }
    return *this;
}

bool Planet::operator==(const Planet& other) const {
    if (name == nullptr || other.name == nullptr)
        return name == other.name;
    return diameter == other.diameter &&
           satellites == other.satellites &&
           hasLife == other.hasLife &&
           strcmp(name, other.name) == 0;
}

bool Planet::operator<(const Planet& other) const {
      if (name == nullptr) return other.name != nullptr;
      if (other.name == nullptr) return false;
      return strcmp(name, other.name) < 0;
}

std::ostream& operator<<(std::ostream& out, const Planet& p) {
    out << p.name << " "
        << p.diameter << " "
        << (p.hasLife ? "yes" : "no") << " "  
        << p.satellites;
    return out;
}

std::istream& operator>>(std::istream& in, Planet& p) {
    char buf[256];

    if (&in == &std::cin) std::cout << "Название: ";
    in >> buf;
    delete[] p.name;
    p.name = new char[strlen(buf) + 1];
    strcpy(p.name, buf);

    do {
        if (&in == &std::cin) std::cout << "Диаметр (>0): ";
        in >> p.diameter;
    } while (&in == &std::cin && p.diameter <= 0);

    if (&in == &std::cin) std::cout << "Наличие жизни (yes/no): ";
    char life[4];
    in >> life;
    p.hasLife = (strcmp(life, "yes") == 0);

    do {
        if (&in == &std::cin) std::cout << "Количество спутников (>=0): ";
        in >> p.satellites;
    } while (&in == &std::cin && p.satellites < 0);

    return in;
}

Planet::~Planet() {
    delete[] name;
    name = nullptr;
}