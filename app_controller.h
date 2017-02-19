#ifndef app_controller_h
#define app_controller_h

#include <mono.h>
#include "main_view_controller.h"
#include "running_average_filter.h"

class AppController : public mono::IApplication {
protected:
    
    MainViewController mainScene;
    Timer tempSampler;
    io::RunningAverageFilter<4, int> tempFilter;
    PowerSaver saver;
    
public:

    AppController();
    
    void sampleTemp();
    

    void monoWakeFromReset();
    void monoWillGotoSleep();
    void monoWakeFromSleep();

};

#endif /* app_controller_h */
