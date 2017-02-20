#include "app_controller.h"

AppController::AppController() :
    tempSampler(500),
    saver(30000,5000)
{
    View::StandardBackgroundColor = SilverColor;
    mainScene.show();
    
    tempSampler.setCallback(this, &AppController::sampleTemp);
}


void AppController::sampleTemp()
{
    int milCel = IApplicationContext::Instance->Temperature->ReadMilliCelcius();
    tempFilter.append(milCel);
    
    mainScene.setTemp(tempFilter.value());
}




void AppController::monoWakeFromReset()
{
    int milCel = IApplicationContext::Instance->Temperature->ReadMilliCelcius();
    tempFilter.clear(milCel);
    tempSampler.Start();
    saver.undim();
}

void AppController::monoWillGotoSleep()
{
    saver.deactivate();
}

void AppController::monoWakeFromSleep()
{
    int milCel = IApplicationContext::Instance->Temperature->ReadMilliCelcius();
    tempFilter.clear(milCel);

    saver.undim();

    sampleTemp();
    mainScene.scheduleRepaint();
}
