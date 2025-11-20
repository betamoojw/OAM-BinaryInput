#include "BinaryInputModule.h"
#include "Logic.h"
#include "GpioBinaryInputModule.h"
#include "VirtualButtonModule.h"
#include "FileTransferModule.h"
#include "MeterModule.h"
#include "FunctionBlocksModule.h"

void setup()
{
    const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);
    openknx.addModule(1, openknxLogic);
    openknx.addModule(2, openknxBinaryInputModule);
    openknx.addModule(3, openknxVirtualButtonModule);
    openknx.addModule(5, openknxGpioBinaryInputModule);
    openknx.addModule(7, openknxMeterModule);
    openknx.addModule(8, openknxFunctionBlocksModule);
    openknx.addModule(9, openknxFileTransferModule);
    openknx.setup();

}

void loop()
{
    openknx.loop();
}