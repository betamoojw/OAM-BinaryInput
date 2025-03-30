#include "BinaryInputModule.h"

const std::string BinaryInputModule::name()
{
    return "BinaryInput";
}

const std::string BinaryInputModule::version()
{
    return MAIN_Version;
}

void BinaryInputModule::setup()
{
    logInfoP("Setup binary input module");
    logIndentUp();

    for (uint8_t i = 0; i < OPENKNX_BI_GPIO_COUNT; i++)
    {
        openknxGPIOModule.pinMode(_gpioPins[i], INPUT);
        openknxGPIOModule.pinMode(_statusPins[i], OUTPUT, true, LOW);
    }

    logInfoP("BinaryInput module ready.");
    logIndentDown();
}

void BinaryInputModule::loop()
{
    bool debugOutput = delayCheck(debugOutTimer, 1000);

    for (uint8_t i = 0; i < OPENKNX_BI_GPIO_COUNT; i++) {
        bool inputActive = openknxGPIOModule.digitalRead(_gpioPins[i]) == OPENKNX_BI_ONLEVEL;
        openknxGPIOModule.digitalWrite(_statusPins[i], inputActive);

        if (debugOutput)
            logDebugP("IN %u (%u): %u", i, _gpioPins[i], inputActive);
    }

    if (debugOutput) {
        debugOutTimer = delayTimerInit();
        logDebugP("");
    }
}

void BinaryInputModule::processInputKo(GroupObject& ko)
{
    uint16_t asap = ko.asap();

    uint8_t channel = BI_KoCalcChannel(asap);
    if (channel == -1)
        return;

}

BinaryInputModule openknxBinaryInputModule;