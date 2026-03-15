#pragma once
#include "OpenKNX.h"
#include "hardware.h"

#define INIT_RESET_TIMEOUT 1000
#define LED_RESET_TIMEOUT 1000

class BinaryInputModule : public OpenKNX::Module
{
  public:
    void setup(bool configured) override;
    void loop(bool configured) override;

    const std::string name() override;
    const std::string version() override;

  private:
    //void runTestMode();

    uint32_t debugOutTimer = 0;

    const uint16_t _gpioPins[OPENKNX_BI_GPIO_COUNT] = {OPENKNX_BI_GPIO_PINS};
    const uint16_t _statusPins[OPENKNX_BI_GPIO_COUNT] = {OPENKNX_BI_STATUS_PINS};
};

extern BinaryInputModule openknxBinaryInputModule;