#include <X11/IntrinsicP.h>
#ifdef sun
#include <X11/ObjectP.h>        /* why don't they just use X from mit!?! */
#include <X11/RectObjP.h>
#endif
#include <X11/StringDefs.h>
#include <X11/Wc/WcCreate.h>
#include <X11/Wc/WcCreateP.h>
#include <X11/Misc/ListTree.h>

#include <X11/Misc/Misc.h>

void RegisterMisc ( app )
    XtAppContext app;
{
    ONCE_PER_XtAppContext( app );

#define RCO( name, func  )  WcRegisterConstructor ( app, name, func  )

 RCO( "XmCreateScrolledListTree", XmCreateScrolledListTree);

#define RCP( name, class )  WcRegisterClassPtr    ( app, name, class )

 RCP( "listtreeWidgetClass", listtreeWidgetClass);
}
