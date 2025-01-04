#include "BinaryInputModule.h"
#include "Logic.h"
#include "GpioBinaryInputModule.h"
#include "VirtualButtonModule.h"
#include "FileTransferModule.h"

void setup()
{
    const uint8_t firmwareRevision = 0;
    openknx.init(firmwareRevision);
    openknx.addModule(1, openknxLogic);
    openknx.addModule(2, openknxBinaryInputModule);
    openknx.addModule(3, openknxVirtualButtonModule);
    openknx.addModule(5, openknxGpioBinaryInputModule);
    openknx.addModule(9, openknxFileTransferModule);
    openknx.setup();

    //openknxGpioBinaryInputModule.setup();
    //openknxBinaryInputModule.setup();
}

void loop()
{
    openknx.loop();

    //openknxGpioBinaryInputModule.loop();
    //openknxBinaryInputModule.loop();
}