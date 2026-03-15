#include "BinaryInputModule.h"

const std::string BinaryInputModule::name()
{
    return "BinaryInput";
}

const std::string BinaryInputModule::version()
{
    return MAIN_Version;
}

void BinaryInputModule::setup(bool configured)
{
    logInfoP("Setup binary input module");
    logIndentUp();

    for (uint8_t i = 0; i < OPENKNX_BI_GPIO_COUNT; i++)
    {
        openknx.gpio.pinMode(_gpioPins[i], INPUT_PULLUP);
        openknx.gpio.pinMode(_statusPins[i], OUTPUT, true, LOW);
    }

    logInfoP("BinaryInput module ready.");
    logIndentDown();
}

void BinaryInputModule::loop(bool configured)
{
    bool debugOutput = delayCheck(debugOutTimer, 1000);

    for (uint8_t i = 0; i < OPENKNX_BI_GPIO_COUNT; i++) {
        bool inputActive = openknx.gpio.digitalRead(_gpioPins[i]) == OPENKNX_BI_ONLEVEL;
        openknx.gpio.digitalWrite(_statusPins[i], inputActive);

        if (debugOutput)
            logDebugP("IN %u (%u): %u", i, _gpioPins[i], inputActive);
    }

    if (debugOutput) {
        debugOutTimer = delayTimerInit();
        logDebugP("");
    }
}

BinaryInputModule openknxBinaryInputModule;