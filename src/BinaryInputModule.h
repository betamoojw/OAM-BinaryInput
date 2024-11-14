#pragma once
#include "OpenKNX.h"
#include "hardware.h"

#ifdef OPENKNX_BIN_OUT_TCA_WIRE
  #include "TCA9555.h"
#endif

#define INIT_RESET_TIMEOUT 1000
#define LED_RESET_TIMEOUT 1000

class BinaryInputModule : public OpenKNX::Module
{
  public:
    void loop() override;
    void setup() override;

    const std::string name() override;
    const std::string version() override;

    void processInputKo(GroupObject &ko) override;
    //bool processCommand(const std::string cmd, bool diagnoseKo);

  private:
    //void runTestMode();

    uint32_t debugOutTimer = 0;

    const uint8_t _gpioPins[OPENKNX_BI_GPIO_COUNT] = {OPENKNX_BI_GPIO_PINS};

#ifdef OPENKNX_BIN_OUT_TCA_WIRE
    TCA9555 tca = TCA9555(OPENKNX_BIN_OUT_TCA_ADDR, &OPENKNX_BIN_OUT_TCA_WIRE);
#endif
};

extern BinaryInputModule openknxBinaryInputModule;