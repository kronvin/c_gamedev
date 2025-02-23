#pragma once
#include "Container.h"

enum class DrinkType
{
    Espresso,
    Cappuccino,
    Latte,
    GreenTea,
    BlackTea,

};

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    LowMilk,
    LowGrain,
    LowTeaLeaves,
    CleanNeeded,
    InappropriateTemperature,

    Count
};

WaterReservoir& m_waterreservoir;
MilkReservoir& m_milkreservoir;
CoffeeGrainsContainer& m_graincontainer;
TeaLeavesContainer& m_tealeavescontainer;

class DrinkProgram
{
public:
    DrinkProgram(DrinkProgram *m_drink, class CoffeeMachine& context);

    virtual void showInfo();
    virtual DrinkProgramStatus prepare();
    void ShowError(DrinkProgramStatus m_status);

    class CoffeeMachine& m_context;

private:

    float waterVolume = 0.0f;
    double grainVolume = 0.000;
    float milkVolume = 0.00f;
    int temperature = 0;

};

class Espresso : public DrinkProgram
{
public:
    void showInfo() override;
    DrinkProgramStatus prepare() override;

protected:
    float waterVolume = 0.05f;
    double grainVolume = 0.008;
    int temperature = 100;
};

class Cappuccino : public DrinkProgram
{
public:
    void showInfo() override;
    DrinkProgramStatus prepare() override;

protected:
    float waterVolume = 0.05f;
    double grainVolume = 0.008;
    float milkVolume = 0.15f;
    int temperature = 80;
};

class Latte : public DrinkProgram
{
public:
    void showInfo() override;
    DrinkProgramStatus prepare() override;

protected:
    float waterVolume = 0.05f;
    double grainVolume = 0.008;
    float milkVolume = 0.2f;
    int temperature = 80;
};

class BlackTea : public DrinkProgram
{
public:
    void showInfo() override;
    DrinkProgramStatus prepare() override;

protected:
    float waterVolume = 0.25f;
    double teaLeavesVolume = 0.007;
    int temperature = 100;
};

class GreenTea : public DrinkProgram
{
public:
    void showInfo() override;
    DrinkProgramStatus prepare() override;

protected:
    float waterVolume = 0.25f;
    double teaLeavesVolume = 0.005;
    int temperature = 90;
};

