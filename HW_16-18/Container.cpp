#include "Container.h"
#include <iostream>
#include <chrono>
#include <thread>

void Container::setVolume(double m_Volume, double drinkVolume)
{
    m_Volume -= drinkVolume;
}

void CoffeeGrainsContainer::showOperations()
{
    std::cout << "\n--- Current grain level: " << getVolume() << "kg out of " << MaxVolume << "kg max ---\n";
    std::cout << "1. Add grains\n";
    std::cout << "2. Back to main\n";
}

void CoffeeGrainsContainer::receiveInput()
{
    std::cout << "Choice: ";
    std::cin >> m_Operation;

    if (m_Operation >= 3)
    {
        std::cout << "Invalid input. Please select 1 or 2.\n";
        CoffeeGrainsContainer::showOperations();
    }
}

void CoffeeGrainsContainer::update()
{
    switch (m_Operation)
    {
    case 1:
    {
        float newVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << MaxVolume << "kg) ";
        std::cin >> newVolume;

        if (newVolume + m_Volume > MaxVolume)
        {
            std::cout << "Impossible to add more!\n";
            m_Volume = MaxVolume;
        }

        m_Volume = std::min(newVolume, MaxVolume);

        std::cout << std::endl;
        break;
    }
    case 2:
    default:
        break;
    }
}

void WaterReservoir::showOperations()
{
    std::cout << "\n--- Current water level: " << getVolume() << "l out of " << MaxVolume << "l max ---\n";
    std::cout << "1. Empty reservoir\n";
    std::cout << "2. Fill up with water\n";
    std::cout << "3. Back to main\n";
};

void WaterReservoir::receiveInput()
{
    std::cout << "Choice: ";
    std::cin >> m_Operation;

    if (m_Operation >= 4)
    {
        std::cout << "Invalid input. Please select 1, 2 or 3.\n";
        WaterReservoir::showOperations();
    }
}

void WaterReservoir::update()
{
    switch (m_Operation)
    {
    case 1:
        m_Volume = 0.0f;
        break;
    case 2:
    {
        float newVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << MaxVolume << "l) ";
        std::cin >> newVolume;

        if (newVolume + m_Volume > MaxVolume)
        {
            std::cout << "Impossible to add more!\n";
            m_Volume = MaxVolume;
        }

        m_Volume = std::min(newVolume, MaxVolume);

        std::cout << std::endl;
        break;
    }
    case 3:
    default:
        break;
    }
}

void MilkReservoir::showOperations()
{
    if (isSpoiled == true)
    {
        std::cout << "Attention! Milk is spoiled. Please empty container and fill it with fresh milk.\n";
    }

    std::cout << "\n--- Current milk level: " << getVolume() << "l out of " << MaxVolume << "l max ---\n";
    std::cout << "1. Empty reservoir\n";
    std::cout << "2. Fill up with milk\n";
    std::cout << "3. Back to main\n";
    std::cout << "4. Check milk status\n";
};

void MilkReservoir::receiveInput()
{
    std::cout << "Choice: ";
    std::cin >> m_Operation;

    if (m_Operation >= 4)
    {
        std::cout << "Invalid input. Please select 1, 2 or 3.\n";
        MilkReservoir::showOperations();
    }
};

void MilkReservoir::update()
{
    switch (m_Operation)
    {
    case 1:
        m_Volume = 0.0f;
        break;
    case 2:
    {
        float newVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << MaxVolume << "l) ";
        std::cin >> newVolume;

        if (newVolume + m_Volume > MaxVolume)
        {
            std::cout << "Impossible to add more!\n";
            m_Volume = MaxVolume;
        }
        else if (isSpoiled == true)
        {
            std::cout << "You can't add fresh milk to spoiled milk. Please empty container first\n";
            break;
        };

        m_Volume = std::min(newVolume, MaxVolume);
        isSpoiled = false;

        std::thread([this]()
            {
                std::this_thread::sleep_for(std::chrono::seconds(spoilTime));
                isSpoiled = true;
            }
        ).detach();

        std::cout << std::endl;
        break;
    }
    default:
        break;
    }
};

