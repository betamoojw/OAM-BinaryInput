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

#ifdef OPENKNX_BIN_OUT_TCA_WIRE
    OPENKNX_BIN_OUT_TCA_WIRE.setSDA(OPENKNX_BIN_OUT_TCA_SDA);
    OPENKNX_BIN_OUT_TCA_WIRE.setSCL(OPENKNX_BIN_OUT_TCA_SCL);
    OPENKNX_BIN_OUT_TCA_WIRE.begin();
    OPENKNX_BIN_OUT_TCA_WIRE.setClock(400000);
    
    if (tca.begin())
    {
        tca.pinMode8(0, 0x00);
        tca.pinMode8(1, 0x00);

        logDebugP("TCA9555 setup done with address %u", tca.getAddress());
    }
    else
        logDebugP("TCA9555 not found at address %u", tca.getAddress());
#endif

    logInfoP("BinaryInput module ready.");
    logIndentDown();
}

void BinaryInputModule::loop()
{
#ifdef OPENKNX_BIN_OUT_TCA_WIRE
    bool debugOutput = delayCheck(debugOutTimer, 1000);

    for (uint8_t i = 0; i < OPENKNX_BI_GPIO_COUNT; i++) {
        bool inputActive = digitalRead(_gpioPins[i]) == OPENKNX_BI_ONLEVEL;
        tca.write1(i, inputActive);

        if (debugOutput)
            logDebugP("IN %u (%u): %u", i, _gpioPins[i], inputActive);
    }

    if (debugOutput) {
        debugOutTimer = delayTimerInit();
        logDebugP("");
    }
#endif
}

void BinaryInputModule::processInputKo(GroupObject& ko)
{
    uint16_t asap = ko.asap();

    uint8_t channel = BI_KoCalcChannel(asap);
    if (channel == -1)
        return;

}

BinaryInputModule openknxBinaryInputModule;