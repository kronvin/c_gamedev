#include "CoffeeMachine.h"

int CoffeeMachine::getTemperature()
{
    return Temperature;
}

void CoffeeMachine::setTemperatureLower()
{
    Temperature -= 5;
}

int CoffeeMachine::getNumberofDrinks()
{
    int number = drinks.size();
    return number;
}

void CoffeeMachine::initDefaultDrinks()
{
    drinks.push_back(std::make_unique<Espresso>());
    drinks.push_back(std::make_unique<Cappuccino>());
    drinks.push_back(std::make_unique<Latte>());
    drinks.push_back(std::make_unique<BlackTea>());
    drinks.push_back(std::make_unique<GreenTea>());
}

void CoffeeMachine::changeState(CoffeeMachineState* state)
{
    std::cout << "Coffee machine transition to " << typeid(*state).name() << " .\n";

    if (this->m_state != nullptr)
    {
        delete this->m_state;
        this->m_state = state;
        this->m_state->set_context(this);
    }
}

void CoffeeMachineState::set_context(CoffeeMachine* machine)
{
    this->m_context = machine;
};

void SleepState::showMenu()
{
    std::cout << "The coffe machine is sleeping. Press any key to wake up\n";
}

void SleepState::receiveInput()
{
    char userinput = 0;
    std::cin >> userinput;

    if (userinput)
    {
        this->update();
    }
};

void SleepState::update()
{
    this->m_context->changeState(new MainMenuState);
};

void MainMenuState::showMenu()
{
    std::cout << "\n1. Prepare Drink\n";
    std::cout << "2. Access Containers\n";
    std::cout << "3. Power off\n";
};

void MainMenuState::receiveInput()
{
    std::cout << "Please select what do you want to do:\n";
    int userinput = 0;
    std::cin >> userinput;
    userinput -= 1;

    switch (userinput)
    {
    case 1:
        this->m_context->changeState(new DrinkSelectionState);
        break;
    case 2:
        this->m_context->changeState(new ContainersAccessState);
        break;
    case 3:
        this->m_context->changeState(new PowerOffRequestState);
        break;
    default:
        std::cout << "Invalid input. Please try again.\n";
        break;
    }
};

void ContainersAccessState::showMenu()
{
    std::cout << "\n1. Access grain container\n";
    std::cout << "2. Access water reservoir\n";
    std::cout << "3. Access milk reservoir\n";
};

void ContainersAccessState::receiveInput()
{
    std::cout << "Please select which container do you want to access:\n";
    int userinput = 0;
    std::cin >> userinput;
    userinput -= 1;

    switch (userinput)
    {
    case 1:
        m_graincontainer->showOperations();
        break;
    case 2:
        waterreservoir->showOperations();
        break;
    case 3:
        milkreservoir->showOperations();
        break;
    default:
        std::cout << "Invalid input. Please try again.\n";
        break;
    }
}

void DrinkSelectionState::showMenu()
{
    std::cout << std::endl;
    for (int i = 0; i < drinks.size(); i++)
    {
        std::cout << i + 1 << ". ";
        drinks[i]->showInfo();
        std::cout << std::endl;
    }
};

int DrinkSelectionState::selectDrink()
{
    std::cout << "Please select a drink to prepare:\n";
    int selectedDrink = 0;
    std::cin >> selectedDrink;
    selectedDrink -= 1;

    this->m_context->changeState(new DrinkPreparationState);
};

void DrinkPreparationState::prepareDrink()
{
    if (m_drinkselection->selectDrink() <= 0 || m_drinkselection->selectDrink() >= m_context->getNumberofDrinks())
    {
        std::cout << "Incorrect input. Please try again.\n";
        this->m_context->changeState(new DrinkSelectionState);
    }

    //selecteddrink.prepare()
};

void ErrorState::displayError()
{
    switch (m_errorType)
    {
    case ErrorType::LowWaterError:
        std::cout << "Low water. Please fill water container.\n Redirecting to container acsess menu ... \n";
        this->m_context->changeState(new ContainersAccessState);
    case ErrorType::LowMilkError:
        std::cout << "Low milk. Please fill milk container.\n Redirecting to container acsess menu ... \n";
        this->m_context->changeState(new ContainersAccessState);
    case ErrorType::LowGrainError:
        std::cout << "Low grain beans. Please fill grain container.\n Redirecting to container acsess menu ... \n";
        this->m_context->changeState(new ContainersAccessState);
    case ErrorType::LowTeaLeavesError:
        std::cout << "Low tea leaves. Please fill tea leaves container.\n Redirecting to container acsess menu ... \n";
        this->m_context->changeState(new ContainersAccessState);
    case ErrorType::SpoiledMilkError:
        std::cout << "Milk is spoiled. Please clean milk container and fill it with fresh milk.\n Redirecting to container acsess menu ... \n";
        this->m_context->changeState(new ContainersAccessState);
    case ErrorType::InappropriateTemperatureError:
        std::cout << "Temperature is imbalanced. Balancing temperature...\n";
        //to add - delay//
        //to add temperature control//
        std::cout << "Temperature now is " << m_context->getTemperature() << " degrees. You may prepare your drink.\n Redirecting to drink selection menu...";
    case ErrorType::CleaningNeededError:
        this->m_context->changeState(new CleaningState); //to investigate
    }
};


void CleaningState::showCleaningInfo()
{
    std::cout << "Attention! Cleaning needed. Please wait until cleaning is done...\n";
    //to add - delay//
    std::cout << "Thank you for your patience. Cleaning is completed. Redirecting to main menu...\n";
};

void CleaningState::cleanCoffeeMachine()
{

};

void PowerOffRequestState::showMenu()
{
    std::cout << "Grrrrrr.... Bye-bye... (Cool animation's playing)\n\n\n";
    m_powerOffRequest = true; //to investigate
};


void PowerOffRequestState::update()
{

};








void CoffeeMachine::powerOn()
{
    if (m_currentChoice == 1)
    {
        std::cout << "\nGrrrr... Self diagnostics... Checking water level...\n";

        if (m_waterReservoir.getVolume() <= 0.0f)
        {
            m_currentState = CoffeeMachineState::LowWaterError;
        }
        else
        {
            m_currentState = CoffeeMachineState::MainMenu;
        }
    }
}


