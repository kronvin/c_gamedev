#pragma once
#include <vector>
#include <iostream>
#include <memory>

#include "Container.h"
#include "DrinkProgram.h"


class CoffeeMachine;

class CoffeeMachineState
{
protected:
    CoffeeMachine *m_context;

public:
    virtual ~CoffeeMachineState() {};
    
    void set_context(CoffeeMachine* machine);
};

class SleepState : public CoffeeMachineState
{
    virtual void showMenu();
    virtual void receiveInput();
    virtual void update();
};

class PowerOffRequestState : public CoffeeMachineState
{
    virtual void showMenu();
    virtual void receiveInput();
    virtual void update();

    void powerOn();
    void powerOff();
};

class MainMenuState : public CoffeeMachineState
{
    virtual void showMenu();
    virtual void receiveInput();

};

class ContainersAccessState : public CoffeeMachineState
{
protected:
    CoffeeGrainsContainer* m_graincontainer;
    WaterReservoir* waterreservoir;
    MilkReservoir* milkreservoir;

public:
    virtual void showMenu();
    virtual void receiveInput();
};

class DrinkSelectionState : public CoffeeMachineState
{
public:
    void showMenu();
    int selectDrink();

protected:
    DrinkProgram* m_SelectedDrink = nullptr;
};

class DrinkPreparationState : public CoffeeMachineState
{
protected:
    DrinkSelectionState *m_drinkselection;

public:

    void prepareDrink();
};

class ErrorState : public CoffeeMachineState
{
public:
    enum class ErrorType
    {
        LowWaterError,
        LowMilkError,
        LowGrainError,
        LowTeaLeavesError,
        SpoiledMilkError,
        InappropriateTemperatureError,
        CleaningNeededError
    };

    ErrorState(ErrorType errorType) : m_errorType(errorType) {};

    void displayError();

private:
    ErrorType m_errorType;
};

class CleaningState : CoffeeMachineState
{
    void showCleaningInfo();
    void cleanCoffeeMachine();
};

class CoffeeMachine
{
private:
    CoffeeMachineState *m_state;

public:
    CoffeeMachine(CoffeeMachineState* state) : m_state(nullptr)
    {
        this->changeState(state);
    };

    ~CoffeeMachine() { delete m_state; };

    void changeState(CoffeeMachineState* state);

    bool m_powerOffRequest = false;
    bool isClean = true;

    bool IsBooted() const { return !m_powerOffRequest; }

    void initDefaultDrinks();
    std::vector<std::unique_ptr<DrinkProgram>> drinks;
    int getNumberofDrinks();

    virtual void showMenu();
    virtual void receiveInput();
    virtual void update();
    int getTemperature();
    void setTemperatureLower();

    int m_currentChoice = -1;
    int Temperature = 100;

private:
    friend class DrinkProgram;
    friend class Container;
};