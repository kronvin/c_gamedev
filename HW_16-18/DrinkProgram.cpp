
#include <iostream>﻿
#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include <chrono>
#include <thread>

DrinkProgram::DrinkProgram(DrinkProgram* m_drink, CoffeeMachine& context) : m_context(context) {}

void DrinkProgram::ShowError(DrinkProgramStatus m_status)
{
    switch (m_status)
    {
    case DrinkProgramStatus::Success:
        break;
    case DrinkProgramStatus::LowWater:
        m_context.changeState(new ErrorState(ErrorState::ErrorType::LowWaterError));
        break;
    case DrinkProgramStatus::LowMilk:
        m_context.changeState(new ErrorState(ErrorState::ErrorType::LowMilkError));
        break;
    case DrinkProgramStatus::LowGrain:
        m_context.changeState(new ErrorState(ErrorState::ErrorType::LowGrainError));
        break;
    case DrinkProgramStatus::LowTeaLeaves:
        m_context.changeState(new ErrorState(ErrorState::ErrorType::LowTeaLeavesError));
        break;
    case DrinkProgramStatus::CleanNeeded:
        m_context.changeState(new ErrorState(ErrorState::ErrorType::CleaningNeededError));
        break;
    case DrinkProgramStatus::InappropriateTemperature:
        m_context.changeState(new ErrorState(ErrorState::ErrorType::InappropriateTemperatureError));
        break;
    }
}

DrinkProgramStatus DrinkProgram::prepare()
{
    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Drink... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    return DrinkProgramStatus::Success;

};

void Espresso::showInfo()
{
    std::cout << "Espresso: volume - 50ml, calories - 0\n";
}

DrinkProgramStatus Espresso::prepare()
{
    if (m_waterreservoir.getVolume() < waterVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_graincontainer.getVolume() < grainVolume)
    {
        return DrinkProgramStatus::LowGrain;
    }
    else if (m_context.getTemperature() != temperature)
    {
        return DrinkProgramStatus::InappropriateTemperature;
    };
    
    DrinkProgramStatus status = DrinkProgram::prepare();

    m_waterreservoir.setVolume(m_waterreservoir.getVolume(), waterVolume);
    m_graincontainer.setVolume(m_graincontainer.getVolume(), grainVolume);
    m_context.setTemperatureLower();

    std::cout << "Your Espresso is ready!\n";
    return DrinkProgramStatus::Success;
};

void Cappuccino::showInfo()
{
    std::cout << "Cappuccino: volume - 200ml, calories - 150\n";
};

DrinkProgramStatus Cappuccino::prepare()
{
    if (m_waterreservoir.getVolume() < waterVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_graincontainer.getVolume() < grainVolume)
    {
        return DrinkProgramStatus::LowGrain;
    }
    else if (m_context.getTemperature() != temperature)
    {
        return DrinkProgramStatus::InappropriateTemperature;
    }
    else if (m_milkreservoir.getVolume() < milkVolume)
    {
        return DrinkProgramStatus::LowMilk;
    }

    DrinkProgramStatus status = DrinkProgram::prepare();

    m_waterreservoir.setVolume(m_waterreservoir.getVolume(), waterVolume);
    m_graincontainer.setVolume(m_graincontainer.getVolume(), grainVolume);
    m_milkreservoir.setVolume(m_graincontainer.getVolume(), milkVolume);
    m_context.setTemperatureLower();

    std::cout << "Your Cappuccino is ready!\n";
    return DrinkProgramStatus::Success;
};

void Latte::showInfo()
{
    std::cout << "Latte: volume - 250ml, calories - 200\n";
}

DrinkProgramStatus Latte::prepare()
{
    if (m_waterreservoir.getVolume() < waterVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_graincontainer.getVolume() < grainVolume)
    {
        return DrinkProgramStatus::LowGrain;
    }
    else if (m_context.getTemperature() != temperature)
    {
        return DrinkProgramStatus::InappropriateTemperature;
    }
    else if (m_milkreservoir.getVolume() < milkVolume)
    {
        return DrinkProgramStatus::LowMilk;
    }

    DrinkProgramStatus status = DrinkProgram::prepare();

    m_waterreservoir.setVolume(m_waterreservoir.getVolume(), waterVolume);
    m_graincontainer.setVolume(m_graincontainer.getVolume(), grainVolume);
    m_milkreservoir.setVolume(m_graincontainer.getVolume(), milkVolume);
    m_context.setTemperatureLower();

    std::cout << "Your Latte is ready!\n";
    return DrinkProgramStatus::Success;
};

void BlackTea::showInfo()
{
    std::cout << "Black tea: volume - 250ml, calories - 0\n";
}

DrinkProgramStatus BlackTea::prepare()
{
    if (m_waterreservoir.getVolume() < waterVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_context.getTemperature() != temperature)
    {
        return DrinkProgramStatus::InappropriateTemperature;
    }
    else if (m_tealeavescontainer.getVolume() < teaLeavesVolume)
    {
        return DrinkProgramStatus::LowTeaLeaves;
    }

    DrinkProgramStatus status = DrinkProgram::prepare();

    m_waterreservoir.setVolume(m_waterreservoir.getVolume(), waterVolume);
    m_graincontainer.setVolume(m_tealeavescontainer.getVolume(), teaLeavesVolume);
    m_context.setTemperatureLower();

    std::cout << "Your Black Tea is ready!\n";
    return DrinkProgramStatus::Success;
};

void GreenTea::showInfo()
{
    std::cout << "Green Tea: volume - 250ml, calories - 0\n";
}

DrinkProgramStatus GreenTea::prepare()
{
    if (m_waterreservoir.getVolume() < waterVolume)
    {
        return DrinkProgramStatus::LowWater;
    }
    else if (m_context.getTemperature() != temperature)
    {
        return DrinkProgramStatus::InappropriateTemperature;
    }
    else if (m_tealeavescontainer.getVolume() < teaLeavesVolume)
    {
        return DrinkProgramStatus::LowTeaLeaves;
    }

    DrinkProgramStatus status = DrinkProgram::prepare();

    m_waterreservoir.setVolume(m_waterreservoir.getVolume(), waterVolume);
    m_graincontainer.setVolume(m_tealeavescontainer.getVolume(), teaLeavesVolume);
    m_context.setTemperatureLower();

    std::cout << "Your Grean Tea is ready!\n";
    return DrinkProgramStatus::Success;
};