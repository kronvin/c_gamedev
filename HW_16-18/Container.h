#pragma once

class Container
{
public:
    virtual void showOperations();
    virtual void receiveInput();
    virtual void update();

    float getVolume() const { return m_Volume; }
    void setVolume(double m_Volume, double drinkVolume);
    void useIngredient(float Volume) { m_Volume -= Volume; }

protected:

    int m_Operation = -1;

private:

    float m_Volume;
    const float MaxVolume;
};

class CoffeeGrainsContainer : public Container
{
public:
    void showOperations() override;
    void receiveInput() override;
    void update() override;

private:
    float m_Volume = 0.0f;
    const float MaxVolume = 1.0f;
};

class TeaLeavesContainer : public Container
{
private:
    float m_Volume = 0.0f;
    const float MaxVolume = 0.7f;
};

class WaterReservoir : public Container
{
public:
    void showOperations() override;
    void receiveInput() override;
    void update() override;

private:
    float m_Volume = 0.0f;
    const float MaxVolume = 2.0f;
};

class MilkReservoir : public Container
{
public:
    void showOperations() override;
    void receiveInput() override;
    void update() override;

private:
    float m_Volume = 0.0f;
    const float MaxVolume = 2.0f;
    bool isSpoiled;
    int spoilTime;
};