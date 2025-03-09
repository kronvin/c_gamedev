# Coffee Machine Emulator Project

> Note: This code is not fully completed. Will be updated later

## Main points

* Coffee Machine has different states:
    * PowerOffRequestState - state to prepare for turning power off. Only has one function to turn off power
    * SleepState - state in which machine is not turned off but also isn't fully active (idle state). User has to press any key to access machine's functions
    * MainMenuState - Menu to switch between maintenance states and drink access states
    * ContainerAccessState - allows user to access water container, milk container, coffee grain container, tea leaves container 
    * DrinkSelectionState - user may choose preferable drink to prepare
    * DrinkPreparationState - user cannot affect the machine while it in this state
    * ErrorState - have a number of errors which may appear during usage of machine
    * CleaningState - automatic cleaning
    
* Main purpose - Code presented shoul cover all possible use cases of coffee machine and give detailed information about errors.

## CoffeeMachine

Contains main CoffeeMachine class
Contains CoffeeMachineState class and its subclasses. By user's input or error appear states of coffee machine may change each other.

Directly connected to Containers and Drink program to access information from them

## Drink Program

Contains DrinkProgram class and its subclasses:
* Espresso
* Cappuccino
* Latte
* BlackTea
* GreenTea

Each subclass contains information about volume of ingredients needed and updates information about their volume in containers.

Each Drink Preparation lowers the coffee machine temperature by 5 degrees. Each DrinkProgram class also has information about temperature needed for preparation and calls an error once temperature is inappropriate.

## Container

Contains Container class and its subclasses:
* WaterReservoir
* CoffeeGrainContainer
* MilkReservoir
* TeaLeavesContainer

Each subclass contains information abot maximum an current volume of ingredients.

Milk container also have the spoiling timer which defines when milk will be spoiled. 
