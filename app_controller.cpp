#include "app_controller.h"

AppController::AppController() :
    saver(30000,10000)
{
    View::StandardBackgroundColor = SilverColor;
    mainScene.show();
    
    //tempSampler.setCallback(this, &AppController::sampleTemp);
}


void AppController::sampleTemp()
{
    wait_ms(30);
    int milCel = IApplicationContext::Instance->Temperature->ReadMilliCelcius();
    tempFilter.append(milCel);
    
    mainScene.setTemp(tempFilter.value());
}


void AppController::monoWakeFromReset()
{
    sampleTemp();
    saver.undim();
}

void AppController::monoWillGotoSleep()
{
    saver.deactivate();
}

void AppController::monoWakeFromSleep()
{
    saver.undim();
    sampleTemp();
    mainScene.scheduleRepaint();
}
