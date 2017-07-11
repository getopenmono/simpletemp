#ifndef app_controller_h
#define app_controller_h

#include <mono.h>
#include "main_view_controller.h"

class AppController : public mono::IApplication {
protected:

    MainViewController mainScene;
    mono::io::RunningAverageFilter<1> tempFilter;
    PowerSaver saver;

public:

    AppController();

    void sampleTemp();


    void monoWakeFromReset();
    void monoWillGotoSleep();
    void monoWakeFromSleep();

};

#endif /* app_controller_h */
