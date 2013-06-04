#ifndef MAAPI_H
#define MAAPI_H

/** \file maapi.h
* \brief Syscall declarations. These system calls and low-level
* functions provide access to the basic features of a device. They are
* implemented by the MoSync runtimes in code native to the device.
*


* With these syscalls it should be possible to do most things, although,
* there may still be some functionality missing. If you
* would like a specific function added, please send us a
* <a href="mailto:info@mobilesorcery.com">mail</a>.

* In future versions of MoSync an extension API will be provided
* that will allow you to create your own custom syscalls.


* Some Caveats:
*

* The Runtime expects alignment rules to be followed.
* Writing or reading to unaligned memory will cause a MoSync Panic.

* Some functions may also cause a panic if they are passed incorrect parameters.
* A complete reference of these panics can be found <a href="../panics.html">here</a>.

* The codepage for functions that use strings is platform-dependent beyond 7-bit ASCII.
* Most use Latin-1, but you should still be wary.


* Additional notes:


* There are different types of handles: Connection, Store and Resource.
* They are all represented as positive signed integers.
* When a handle is passed to a function, it must have the proper type.

* Each MoSync program has a Resource array. It is acccessed and manipulated by certain
*  syscalls, but it cannot be accessed directly.
* Each resource (aka Object) is represented by a
* handle. There are different types of resources, for example
* Image, Binary data, Sound or Placeholder. A placeholder object is not a real object, but
* just a handle which you can use to construct new objects dynamically.
* Resources can also be defined at compile time, by using MoSync's resource compiler.
* Placeholders can either be defined at compile time using a resource compiler directive
* or created dynamically at runtime using maCreatePlaceholder().
* See the tutorials, examples and the resource compiler reference documentation for more
* information.

* There is an event queue which contains keypad events and results from asynchronous operations.
* Use maWait() and maGetEvent() to handle it.

* MoSync socket/Bluetooth/HTTP connections are asynchronous. Read all about it \link connApiOverview here\endlink.
*/

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#include "maapi_defs.h"

#ifndef MAPIP
#define _HAVE_STRING_ARCH_strcmp
#define _HAVE_STRING_ARCH_strcpy
#include <memory.h>
#define memset _memset
#define memcpy _memcpy
#include <math.h>
#endif	//MAPIP

#ifdef __cplusplus
extern "C" {
#endif

/** @defgroup PIMAPI PIM API
* @{
*/
/** @defgroup PIMConsts PIM Constants */
/** @defgroup PIMFunctions PIM Functions */
/** @} */ // end of PIMAPI
/**
*MoSync provides Native UI support on Android, iOS and Windows Phone. This means that you can develop
*user interfaces that use each target platform's own widgets.
*We have mapped the different ways of coding UIs to a single API. A few properties/widgets
*are only be available on one platform, but most are available on all three platforms (e.g. Android, iOs and Windows Phone).
*
*All native UI API functions begin with the prefix "maWidget". It is a minimal
*API where widgets with different semantics in the UI can be created: widget
*properties affect widget appearance and behaviour. Some of the widgets can have children.
*
*There are three main types of widget: Screens, Layouts and Views. We
*explain them briefly here. The illustration below shows a typical widget hierarchy:
*
\verbatim
           Screen
              |
        VerticalLayout
        /            \
    EditBox        ListView
                   /      \
            ListViewItem  ListViewItem....
\endverbatim
*
*
*\b See Also
*
*     #NativeUI library.
*
*\b Screens
*
*Screens represent the root of a UI hierarchy. If you're used to iPhone
*programming, a Screen is equivalent to a UIViewController. If you're used to Android
*programming, a Screen is equivalent to an Activity.
*
*For now there are three types of Screens: Screen, TabScreen, StackScreen.
*- \b Screen \n
*   A container for layouts or views. A Screen can have Layouts or Views as children.
*
*- \b TabScreen \n
*   A special kind of screen that displays a tab bar and can have several Screens as children, each one representing a specific tab.
*
*- \b StackScreen \n
*   A special kind of screen that manages navigation and animation between Screens. It manages a stack of screens. Any Screen can be pushed to
*	the StackScreen in order to animate to it. Internally the StackScreen will push the
*	screen onto a stack. When a StackScreen is popped, the stack of screens is popped
*	and the Screen remaining on the stack is animated to and displayed.
*
*To show a screen you use #maWidgetScreenShow. A screen that is shown using this function should NOT have
*have a parent screen (i.e., it should be at the root of a widget hierarchy).
*
*
*\b Layouts
*
*There are different layouts to facilitate dynamic layouts. If you want the same layout
*for different screen sizes these come in handy.
*
*For now there are three different layouts: RelativeLayout, VerticalLayout and
*HorizontalLayout.
*
*- \b RelativeLayout \n
*   A layout that just places its children relative to itself, using the coordinates set on the children ("left" and "top" properties).
*
*- \b VerticalLayout \n
*   A layout that stacks views in the vertical axis.
*
*- \b HorizontalLayout \n
*   A layout that stacks views in the horizontal axis.
*
*All widgets have a set of default properties called "width" and "height". These properties
*specify the actual width and height of the widget. However these values can also be set
*to two different constants:
*
*- #MAW_CONSTANT_WRAP_CONTENT means that the width or height should automatically
*be set to wrap the content. If you set width and height to #MAW_CONSTANT_WRAP_CONTENT on
*a label, the width and height of the widget will automatically be set to the size of the label text.
*
*- #MAW_CONSTANT_FILL_AVAILABLE_SPACE dynamically adapts the size of the widget to
*the parent. If a widget is put inside a RelativeLayout or Screen
*the widget will be stretched to fill the parent.
*
*With vertical and horizontal layouts these constants are more powerful: they mean that the
*width or height should be divided among all
*widgets that have #MAW_CONSTANT_FILL_AVAILABLE_SPACE set. For example, say you have a
*HorizontalLayout that is 320 wide and you add 2 widgets that are 30 pixels wide and then two widgets that
*have #MAW_CONSTANT_FILL_AVAILABLE_SPACE set as the width. These will share the remaining space which
*equals 320-30*2=260. This means that they both will be 130 pixels wide.
*
*
*\b Views
*
*There are many different kinds of Views. They are all leaf-nodes in the UI tree.
*
*Today these views are available:
*
*- \b ActivityIndicator \n
*	Used for displaying the indeterminate progress of a task over time.
*
*- \b Button \n
*  Just a simple click-able button that can have a title.
*
*- \b CameraPreview \n
*	A view that allows users to visualize the camera controller.
*
*- \b CheckBox \n
*  A switch/toggle button.
*
*- \b DatePicker \n
*	A widget that allows the user to select dates.
*
*- \b EditBox \n
*  A text field that can be edited using the virtual keyboard.
*
*- \b GLView \n
*	A widget to draw accelerated graphics using OpenGL for Embedded Systems version 1.0 or 2.0.
*
*- \b Image \n
*	A view that displays an image. The images are loaded from resources and they can be scaled.
*
*- \b ImageButton \n
*	Same as button but can also have an background image instead of the default button style.
*
*- \b Label \n
*	A text label.
*
*- \b ListView \n
*  A scrollable list of ListViewItems.
*
*- \b ListViewItem \n
*	A widget that can be put in a ListView. It has a default layout for placing a text and a icon. But any view can be added to it in order to create a custom appearance.
*
*- \b Map \n
*	A widget that contains a google map (for Android and iOS) or a bing map (for Windows Phone).
*
*- \b NavBar \n
*	A toolbar-like view that can have a back button and a title. A NavBar will automatically appear if you're using a StackScreen. It is only available on iOS for now.
*
*- \b NumberPicker \n
*	A widget that enables the user to select a number from a predefined range. It is only available on iOS for now.
*
*- \b ProgressBar \n
*	Used to display the progress of a task over time.
*
*- \b RadioButton \n
*	Used for single item selection. It is only available on Android for now.
*
*- \b RadioGroup \n
*	Used for grouping RadioButtons. It is only available on Android for now.
*
*- \b RatingBar \n
*	Used to display a rating in stars. It is only available on Android for now.
*
*- \b SearchBar \n
*	Like an editbox on a toolbar with a default look and feel and a button for performing the search.
*
*- \b Slider \n
*	A widget with allows users to set a value by moving an indicator, usually in a horizontal fashion.
*
*- \b TimePicker \n
*	A view for selecting the time of day, in 24 hour mode.
*
*- \b ToggleButton \n
*	Displays checked/unchecked states as a button with a "light" indicator and by default accompanied with the text "ON" or "OFF". It is available on Android, iOS and Windows Phone.
*
*- \b VideoView \n
*	Manages the playback of a movie from a file or a network stream.</li>
*
*- \b WebView \n
*	A powerful widget that renders web content using the same WebKit rendering engines that powers the Safari and Android web browsers. It also runs on Windos Phone.
*
*
*\b Properties
*
*Widget have properties. These can change the appearance or behaviour of the widget. For some
*widgets you can also get properties: for an EditBox, for example, you can get the current text of the
*edit box. See the respective property set in the reference documentation for more information about
*what properties each widget has.
*
*
*\b Events
*
*A UI system is rather useless if you don't connect it with some kind of logic. Whenever something in
*the UI happens, events are sent from the runtime to the MoSync applications. These can be hooked to
*do whatever needs to be done. The top level event is called #EVENT_TYPE_WIDGET. When such an event is
*received, the data pointer of the #MAEvent struct points to a #MAWidgetEventData struct. See
*#MAWidgetEventData for more information about the widget events.
*
*As there aren't any listeners implemented in the Moblet architecture yet, you have to manually extract
*this data. An example of listening for a button event in the customEvent function of a Moblet:
*
*
\code
void customEvent(const MAEvent& event) {
    if(event.type == EVENT_TYPE_WIDGET) {
        MAWidgetEventData* widgetEventData = (MAWidgetEventData*)event.data;
        if(event.widgetHandle == myButtonHandle &&
           widgetEventData->eventType == MAW_EVENT_CLICKED) {
            // do something when the button is pressed.
        }
    }
}
\endcode
*
*
*/
/** @defgroup WidgetAPI Widget API
* @{
*/
/**
* The available widget properties for a #MAW_ACTIVITY_INDICATOR. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetActivityIndicatorProperties Activity Indicator */
/**
* The available widget properties for a #MAW_BUTTON. See of \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetButtonProperties Button */
/**
* The available widget properties for a #MAW_CHECK_BOX. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetCheckBoxProperties Check box */
/**
* The available widget properties for a #MAW_CUSTOM_PICKER. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetCustomPickerProperties CustomPicker */
/**
* The available widget properties for a #MAW_DATE_PICKER. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetDatePickerProperties Date Picker */
/** @defgroup WidgetEditBox Edit box
* @{
*/
/** @defgroup WidgetEditBoxMode Edit box mode */
/** @defgroup WidgetEditBoxType Edit box type */
/** @defgroup WidgetEditBoxFlag Edit box flag */
/** @defgroup WidgetEditBoxAutocorrectionType Edit box autocorrection type */
/**
* The available widget properties for a #MAW_EDIT_BOX. See of \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetEditBoxProperties Edit box properties */
/** @} */ // end of WidgetEditBox
/**
* The available widget properties for a #MAW_GL_VIEW. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetGLViewProperties GL view */
/**
* The available widget properties for a #MAW_HORIZONTAL_LAYOUT. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetHorizontalLayoutProperties Horizontal layout */
/**
* The available widget properties for a #MAW_IMAGE. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetImageProperties Image */
/**
* The available widget properties for a #MAW_IMAGE_BUTTON. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetImageButtonProperties Image button */
/**
* The available widget properties for a #MAW_LABEL. See of \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetLabelProperties Label */
/** @defgroup WidgetListView List View
* @{
*/
/**
* The available list view types.
* Platform: Android, iOS and Windows Phone 7.
*/
/** @defgroup WidgetListViewType List View Type */
/**
* The available list view modes.
* Platform: iOS.
*/
/** @defgroup WidgetListViewMode List View Mode */
/**
* The available list view styles. By default, the MAW_LIST_VIEW_STYLE_SUBTITLE will be set.
* Platform: Windows Phone 7.
*/
/** @defgroup WidgetListViewStyle List View Style */
/**
* The available widget properties for a #MAW_LIST_VIEW.
* See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetListViewProperties List View properties */
/** @} */ // end of WidgetListView
/** @defgroup WidgetListViewItem List View Item
* @{
*/
/**
* The available accessory types for a #MAW_LIST_VIEW_ITEM.
* It appears on the right side of the item.
* Platform: iOS.
*/
/** @defgroup WidgetListViewItemAccessoryType List View Item Accessory Type */
/**
* The available editing style for a #MAW_LIST_VIEW_ITEM.
* Platform: iOS.
*/
/** @defgroup WidgetListViewItemEditStyle List View Item Edit Style */
/**
* The available selection style for a #MAW_LIST_VIEW_ITEM.
* Platform: iOS.
*/
/** @defgroup WidgetListViewItemSelectionStyle List View Item Selection Style */
/**
* The available widget properties for a #MAW_LIST_VIEW_ITEM.
* See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetListViewItemProperties List view item properties */
/** @} */ // end of WidgetListViewItem
/** @defgroup WidgetListViewSection List View Section
* @{
*/
/**
* The available list view section types.
* Platform: Android, iOS and Windows Phone 7.
*/
/** @defgroup WidgetListViewSectionType List View Section Type */
/**
* The available widget properties for a #MAW_LIST_VIEW_SECTION.
*/
/** @defgroup WidgetListViewSectionProperties List View Section Properties */
/** @} */ // end of WidgetListViewSection
/** @defgroup WidgetMap Map
* @{
*/
/**
* Type constants of the map widget.
*/
/** @defgroup WidgetMapType Map types */
/**
* The available widget properties for a #MAW_MAP. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetMapProperties Map properties */
/** @} */ // end of WidgetMap
/**
* The available widget properties for a #MAW_MAP_PIN. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetMapPinProperties Map pin */
/**
* The available widget properties for a #MAW_MODAL_DIALOG. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetModalDialogProperties Modal Dialog */
/**
* The available widget properties for a #MAW_NAV_BAR. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetNavBarProperties Navigation Bar */
/**
* The available widget properties for a #MAW_NUMBER_PICKER. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetNumberPickerProperties Number Picker */
/**
* The available constants for the Android predefined drawables used in OptionsMenu.
* The drawables can be set via \ref maWidgetScreenAddOptionsMenuItem syscall.
* The icons can be found here: http://androiddrawables.com/menu.html .
* Note that only these are supported on WP7:
*	- ADD
*	- CAMERA
*	- CLOSE_CLEAR_CANCEL
*	- DELETE
*	- EDIT
*	- GALLERY
*	- HELP
*	- MORE
*	- PREFERENCES
*	- SAVE
*	- SEARCH
*	- SHARE
*	- UPLOAD
*	- UPLOAD_YOU_TUBE
*/
/** @defgroup OptionsMenuIconConstants Options menu icon */
/**
* The available widget properties for a #MAW_PANORAMA_VIEW. See \ref WidgetProperties "Widget properties" for more properties
*/
/** @defgroup WidgetPanoramaViewProperties Panorama View */
/**
* The available widget properties for a #MAW_PROGRESS_BAR. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetProgressBarProperties Progress bar */
/**
* The available widget properties for a #MAW_RADIO_BUTTON. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetRadioButtonProperties Radio Button */
/**
* The available widget properties for a #MAW_RADIO_GROUP. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetRadioGroupProperties Radio Group */
/**
* The available widget properties for a #MAW_RATING_BAR. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetRatingBarProperties Rating Bar */
/** @defgroup WidgetRelativeLayoutProperties Relative layout */
/**
* The available widget properties for a #MAW_SCREEN. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetScreenProperties Screen */
/**
 * The set of transition types available for a screen transition.
 */
/** @defgroup ScreenTransitionTypes Screen transition types */
/**
* The available widget properties for a #MAW_SEARCH_BAR. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetSearchBarProperties Search bar */
/**
* The available widget properties for a #MAW_SLIDER. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetSliderProperties Slider */
/**
* The available widget properties for a #MAW_STACK_SCREEN. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetStackScreenProperties Stack screen */
/**
* The available widget properties for a #MAW_TAB_SCREEN. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetTabScreenProperties Tab screen */
/**
* The available widget properties for a #MAW_TIME_PICKER. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetTimePickerProperties Time Picker */
/**
* The available widget properties for a #MAW_TOGGLE_BUTTON. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetToggleButtonProperties Toggle button */
/**
* The available widget properties for a #MAW_VERTICAL_LAYOUT. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetVerticalLayoutProperties Vertical layout */
/** @defgroup VideoView Video view
* @{
*/
/**
* The available playback actions for the video view. For more info see \ref WidgetVideoViewProperties.
*/
/** @defgroup VideoViewAction Video view action */
/**
* Events for the video view. When the state of the video view changes an event with one
* of the next constants will be send.
* NOTE: there is a slightly different behaviour depending on the platform:
*  - on iOS the source is loaded into memory when
*  MAW_VIDEO_VIEW_STATE_PLAYING is received.
*	- on Android and WindowsPhone the source is loaded into memory when
*  MAW_VIDEO_VIEW_STATE_SOURCE_READY is received.
*/
/** @defgroup VideoViewEvent Video view event */
/**
* The available widget properties for a #MAW_VIDEO_VIEW. See \ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetVideoViewProperties Video View properties */
/** @} */ // end of VideoView
/**
* The available widget properties for a #MAW_WEB_VIEW.
* See @ref WidgetProperties "Widget properties" for more properties.
*/
/** @defgroup WidgetWebViewProperties Web view */
/** @defgroup WidgetAlignment Widget alignment */
/**
* The available constants for the widget api.
*/
/** @defgroup WidgetConstants Widget constants */
/**
* Widgets can send events for instance when their internal state is changed (like when a
* button is pressed). These are events sent using the MoSync event system \ref maGetEvent.
* When an event is received with the type #EVENT_TYPE_WIDGET the 'data' member of the MAEvent
* struct is a pointer to data of type #MAWidgetEventData.
*/
/** @defgroup WidgetEvent Widget event
* @{
*/
/**
* The available widget event types.
*/
/** @defgroup WidgetEventTypes Widget event types */
/** @} */ // end of WidgetEvent
/**
* The set of functions available for the Widget API.
*/
/** @defgroup WidgetAPIFunctions Widget functions */
/**
* All widgets have a set of properties that can be set. In order to set them, use maWidgetSetProperty(). These properties may change
* things like the visual appearance of the widget or the way it works.
*/
/** @defgroup WidgetProperties Widget properties */
/**
* The available result codes for the widget api.
*/
/** @defgroup WidgetResultCodes Widget result codes */
/**
* The available widget types for maWidgetCreate().
*/
/** @defgroup WidgetTypes Widget types */
/** @defgroup ActionBarErrorCodes Action Bar Error Codes */
/**
* Sets how an item should display in the presence of an Action Bar.
*/
/** @defgroup ActionBarItemDisplayFlag Action Bar Item Display Flag */
/**
* The set of functions available for the Action bar.
* Beginning with Android 3.0 (API level 11), the action bar appears at the top of an activity's window.
* By default, the action bar shows the application icon on the left, followed by the activity title.
* The Action bar is unique per application, therefore all syscalls that relate to the Action Bar will
* be handled on that unique instance.
*
* IMPORTANT NOTE: Available only on Android.
*/
/** @defgroup ActionBarFunctions Action Bar functions */
/** @} */ // end of WidgetAPI
/** @defgroup CameraAPI Camera API
* @{
*/
/** @defgroup CameraResultCodes Camera Result Codes */
/** @defgroup FlashModes Flash Modes */
/** @defgroup FocusModes Focus Modes */
/** @defgroup ImageFormat Image Formats */
/** @defgroup CameraProperties Camera Properties */
/** @defgroup CameraPreviewEvents Camera Preview Events */
/** @defgroup CameraFunctions Camera Functions */
/** @} */ // end of CameraAPI
/** @defgroup OpenGLES OpenGLES */
/** @defgroup SensorAPI Sensor API
* @{
*/
/** @defgroup SensorTypes Sensor Types */
/** @defgroup SensorConsts Sensor Constants */
/** @defgroup SensorFunctions Sensor Functions */
/** @} */ // end of SensorAPI
/** @defgroup NFCAPI NFC API */
/** @defgroup DBAPI Database API */
/** @defgroup AudioAPI Audio API
* @{
*/
/** @defgroup AudioAPIConsts Audio API Constants */
/**
* The Audio API gives the developer more control over playing music and
* and sound effects in MoSync applications.
* The Audio API uses streaming and non-streaming audio sources.
* The streaming could be songs for playing in the background in games.
* The non-streaming sounds should instead be used as sound effects.
* Please consider using short, as in a couple of seconds, samples in MP3
* format instead of WAV due to differences between platforms and WAV
* playback problems on Android.
* @attention The Audio API is only available on Android and iOS!
*/
/** @defgroup AudioAPIFunctions Audio API Functions */
/** @} */ // end of AudioAPI
/** @defgroup AdsAPI Advertising API
* @{
*/
/** @defgroup AdsResultCodes Ads result codes */
/** @defgroup AdsErrorCodes Advertising error codes */
/** @defgroup AdsProperties Advertising Properties */
/** @defgroup AdsConstants Advertising Constants */
/** @defgroup AdsEventTypes Advertising Event Types */
/** @defgroup AdsFunctions Advertising Functions */
/** @} */ // end of AdsAPI
/** @defgroup NotificationAPI Notification API
* @{
*/
/** @defgroup NotificationResultCodes Notification result codes */
/** @defgroup NotificationFlags Notification Flags */
/** @defgroup NotificationDisplayFlags Notification Display Flags */
/** @defgroup NotificationPushTypes Notification Push Types */
/** @defgroup LocalNotificationProperties Local Notification Properties */
/** @defgroup NotificationPushStruct Push Notification Struct */
/** @defgroup NotificationFunctions Notification Functions */
/** @} */ // end of NotificationAPI
/** @defgroup CaptureAPI Capture API
* @{
*/
/** @defgroup CaptureResultCodes Capture result codes */
/** @defgroup CaptureProperties Capture Properties */
/** @defgroup CaptureVideoQuality Capture Video Quality */
/** @defgroup CaptureAction Capture Action */
/** @defgroup CaptureEventType Capture Event type */
/** @defgroup CaptureFlashMode Capture flash mode */
/** @defgroup CaptureFunctions Capture Functions */
/** @} */ // end of CaptureAPI
/** @defgroup PurchaseAPI Purchase API
* @{
*/
/** @defgroup PurchaseResultCodes Purchase Result Codes */
/** @defgroup PurchaseErrorCodes Purchase Error Codes */
/** @defgroup PurchaseEventTypes Purchase Event Types */
/** @defgroup PurchaseStateCodes Purchase State Codes */
/** @defgroup PurchaseReceiptFields Purchase Receipt Fields */
/** @defgroup PurchaseFunctions Purchase Functions */
/** @} */ // end of PurchaseAPI
/** @defgroup OrientationAPI Orientation API
* @{
*/
/** @defgroup OrientationConstants Orientation constants */
/** @defgroup OrientationResultCodes Orientation result codes */
/** @defgroup OrientationFunctions Orientation functions */
/** @} */ // end of OrientationAPI

#ifndef _WCHAR_DEFINED
#define _WCHAR_DEFINED
#ifdef MAPIP
#ifdef __cplusplus
typedef wchar_t wchar;
#else
typedef unsigned short wchar;
typedef wchar wchar_t;
#endif	//__cplusplus
#else	//MAPIP
#if defined(MOSYNC_NATIVE)
#include <stddef.h>
typedef wchar_t wchar;
#else
typedef unsigned short wchar;
#endif // MOSYNC_NATIVE
#endif	//MAPIP
#endif	//_WCHAR_DEFINED

#ifndef _SYSV_TYPES_DEFINED
#define _SYSV_TYPES_DEFINED
typedef unsigned short ushort;
typedef unsigned int uint;
#endif	//_SYSV_TYPES_DEFINED

typedef char* MAString;
typedef wchar* MAWString;
typedef void* MAAddress;
typedef int MAHandle;
typedef int MAExtent;
typedef unsigned char byte;
typedef unsigned long ulong;
typedef long long longlong;
typedef int MAExtensionModule;
typedef int MAExtensionFunction;
/** @ingroup AudioAPI */
typedef int MAAudioData;
/** @ingroup AudioAPI */
typedef int MAAudioInstance;

/// Returns the height of an MAExtent.
#define  EXTENT_Y(e) ((short)(e))

/// Returns the width of an MAExtent.
#define  EXTENT_X(e) ((short)((e) >> 16))

/// Creates an MAExtent.
#define  EXTENT(x, y) ((MAExtent)((((int)(x)) << 16) | ((y) & 0xFFFF)))

/// The image is copied unchanged.
#define TRANS_NONE 0

/// The image is rotated clockwise by 90 degrees.
#define TRANS_ROT90 5

/// The image is rotated clockwise by 180 degrees.
#define TRANS_ROT180 3

/// The image is rotated clockwise by 270 degrees.
#define TRANS_ROT270 6

/// The image is reflected about its vertical center.
#define TRANS_MIRROR 2

/// The image is reflected about its vertical center, then rotated clockwise by 90 degrees.
#define TRANS_MIRROR_ROT90 7

/// The image is reflected about its vertical center, then rotated clockwise by 180 degrees.
#define TRANS_MIRROR_ROT180 1

/// The image is reflected about its vertical center, then rotated clockwise by 270 degrees.
#define TRANS_MIRROR_ROT270 4
/// This handle refers to the back buffer, which is initially black.
#define HANDLE_SCREEN 0

#define HANDLE_LOCAL 0
#define RES_OUT_OF_MEMORY -1
#define RES_BAD_INPUT -2
#define RES_OK 1
#define MAS_CREATE_IF_NECESSARY 1
/// Generic error.
#define STERR_GENERIC -2

/// The storage medium is full.
#define STERR_FULL -3

/// The store does not exist.
#define STERR_NONEXISTENT -5
/// Generic error.
#define CONNERR_GENERIC -2

/// The maximum number of open connections allowed has been reached.
#define CONNERR_MAX -3

/// DNS resolution error.
#define CONNERR_DNS -4

/// Internal error. Please report any occurrences.
#define CONNERR_INTERNAL -5

/** \brief The connection was closed by the remote peer.
*
* Happens when HTTP servers finish sending data.
*/
#define CONNERR_CLOSED -6

/// You attempted to write to a read-only connection.
#define CONNERR_READONLY -7

/// The OS does not trust you enough to let you open this connection.
#define CONNERR_FORBIDDEN -8

/// No operation has been started yet.
#define CONNERR_UNINITIALIZED -9

/// The Content-Length header could not be found.
#define CONNERR_CONLEN -10

/// You supplied a malformed URL.
#define CONNERR_URL -11

/// The protocol is not available.
/// If a Bluetooth function returns this, the Bluetooth chip is turned off.
#define CONNERR_UNAVAILABLE -12

/// You canceled the operation.
#define CONNERR_CANCELED -13

/// The server gave an invalid response.
#define CONNERR_PROTOCOL -14

/// The network connection could not be established.
#define CONNERR_NETWORK -15

/// The requested header could not be found.
#define CONNERR_NOHEADER -16

/// The requested object could not be found.
#define CONNERR_NOTFOUND -17

/// An error occurred during SSL negotiation.
#define CONNERR_SSL -18

/// A download is already in progress.
#define CONNERR_DOWNLOAD_IN_PROGRESS -19

/// There is no active download.
#define CONNERR_NO_ACTIVE_DOWNLOAD -20

#define CONNERR_READER_UNAVAILABLE -21

/// Redirection failed. This occurs when the server does not provide alternative url
/// or if the maximum number of attempts to redirect was exceeded.
#define CONNERR_REDIRECT -22

/**
* If you wish to share the CONNERR codespace,
* use values below this for your own error codes.
*/
#define CONNERR_USER -1000000
#define CONNOP_READ 1
#define CONNOP_WRITE 2
#define CONNOP_CONNECT 7
#define CONNOP_FINISH 11
#define CONNOP_ACCEPT 16
/// The maximum number of open connections allowed.
#define CONN_MAX 32
#define BTADDR_LEN 6
#define CONN_FAMILY_INET4 1
#define CONN_FAMILY_BT 2
#define CONN_FAMILY_INET6 3
#define HTTP_GET 1
#define HTTP_POST 2
#define HTTP_HEAD 3
#define HTTP_PUT 4
#define HTTP_DELETE 5
#define MA_RESOURCE_OPEN 0x1
#define MA_RESOURCE_CLOSE 0x2
#define MAK_UNKNOWN 0
#define MAK_FIRST 0
#define MAK_BACKSPACE 8
#define MAK_TAB 9
#define MAK_CLEAR 12
#define MAK_RETURN 13
#define MAK_PAUSE 19
#define MAK_ESCAPE 27
#define MAK_SPACE 32
#define MAK_EXCLAIM 33
#define MAK_QUOTEDBL 34
#define MAK_POUND 35
#define MAK_HASH 35
#define MAK_GRID 35
#define MAK_DOLLAR 36
#define MAK_AMPERSAND 38
#define MAK_QUOTE 39
#define MAK_LEFTPAREN 40
#define MAK_RIGHTPAREN 41
#define MAK_ASTERISK 42
#define MAK_STAR 42
#define MAK_PLUS 43
#define MAK_COMMA 44
#define MAK_MINUS 45
#define MAK_PERIOD 46
#define MAK_SLASH 47
#define MAK_0 48
#define MAK_1 49
#define MAK_2 50
#define MAK_3 51
#define MAK_4 52
#define MAK_5 53
#define MAK_6 54
#define MAK_7 55
#define MAK_8 56
#define MAK_9 57
#define MAK_COLON 58
#define MAK_SEMICOLON 59
#define MAK_LESS 60
#define MAK_EQUALS 61
#define MAK_GREATER 62
#define MAK_QUESTION 63
#define MAK_AT 64
#define MAK_LEFTBRACKET 91
#define MAK_BACKSLASH 92
#define MAK_RIGHTBRACKET 93
#define MAK_CARET 94
#define MAK_UNDERSCORE 95
#define MAK_BACKQUOTE 96
#define MAK_A 97
#define MAK_B 98
#define MAK_C 99
#define MAK_D 100
#define MAK_E 101
#define MAK_F 102
#define MAK_G 103
#define MAK_H 104
#define MAK_I 105
#define MAK_J 106
#define MAK_K 107
#define MAK_L 108
#define MAK_M 109
#define MAK_N 110
#define MAK_O 111
#define MAK_P 112
#define MAK_Q 113
#define MAK_R 114
#define MAK_S 115
#define MAK_T 116
#define MAK_U 117
#define MAK_V 118
#define MAK_W 119
#define MAK_X 120
#define MAK_Y 121
#define MAK_Z 122
#define MAK_DELETE 127
#define MAK_KP0 256
#define MAK_KP1 257
#define MAK_KP2 258
#define MAK_KP3 259
#define MAK_KP4 260
#define MAK_KP5 261
#define MAK_KP6 262
#define MAK_KP7 263
#define MAK_KP8 264
#define MAK_KP9 265
#define MAK_KP_PERIOD 266
#define MAK_KP_DIVIDE 267
#define MAK_KP_MULTIPLY 268
#define MAK_KP_MINUS 269
#define MAK_KP_PLUS 270
#define MAK_KP_ENTER 271
#define MAK_KP_EQUALS 272
#define MAK_UP 273
#define MAK_DOWN 274
#define MAK_RIGHT 275
#define MAK_LEFT 276
#define MAK_INSERT 277
#define MAK_HOME 278
#define MAK_END 279
#define MAK_PAGEUP 280
#define MAK_PAGEDOWN 281
#define MAK_FIRE 284
#define MAK_SOFTLEFT 285
#define MAK_SOFTRIGHT 286
#define MAK_PEN 291
#define MAK_BACK 292
#define MAK_MENU 293
#define MAK_RSHIFT 303
#define MAK_LSHIFT 304
#define MAK_RCTRL 305
#define MAK_LCTRL 306
#define MAK_RALT 307
#define MAK_LALT 308
#define MAK_SEARCH 309
#define MAKB_LEFT 0x00001
#define MAKB_UP 0x00002
#define MAKB_RIGHT 0x00004
#define MAKB_DOWN 0x00008
#define MAKB_FIRE 0x00010
#define MAKB_SOFTLEFT 0x00020
#define MAKB_SOFTRIGHT 0x00040
#define MAKB_0 0x00080
#define MAKB_1 0x00100
#define MAKB_2 0x00200
#define MAKB_3 0x00400
#define MAKB_4 0x00800
#define MAKB_5 0x01000
#define MAKB_6 0x02000
#define MAKB_7 0x04000
#define MAKB_8 0x08000
#define MAKB_9 0x10000
#define MAKB_ASTERISK 0x20000
#define MAKB_STAR 0x20000
#define MAKB_HASH 0x40000
#define MAKB_POUND 0x40000
#define MAKB_GRID 0x40000
#define MAKB_CLEAR 0x80000
#define EVENT_BUFFER_SIZE 256

/// In milliseconds
#define EVENT_CLOSE_TIMEOUT 2000
/**
* This event is posted when the operating system sends MoSync a command to exit.
* Causes include the OS shutting down and OS-controlled user commands.
* \see maGetEvent()
*/
#define EVENT_TYPE_CLOSE 1

#define EVENT_TYPE_KEY_PRESSED 2
#define EVENT_TYPE_KEY_RELEASED 3

/// Connection
#define EVENT_TYPE_CONN 4

/// Bluetooth discovery
#define EVENT_TYPE_BT 5

#define EVENT_TYPE_POINTER_PRESSED 8
#define EVENT_TYPE_POINTER_RELEASED 9
#define EVENT_TYPE_POINTER_DRAGGED 10

/**
 * While MoSync doesn't have focus, no key events will arrive and the screen will not be updated.
 * If the keypad is locked, no application will have focus.
 * \see maLockKeypad
 */
#define EVENT_TYPE_FOCUS_LOST 13

#define EVENT_TYPE_FOCUS_GAINED 14

/// Has MAEvent::data point to an MALocation.
#define EVENT_TYPE_LOCATION 16

/// MAEvent::state is one of the \link #MA_LPS_AVAILABLE MA_LPS \endlink constants.
#define EVENT_TYPE_LOCATION_PROVIDER 17

/**
* \brief Event which is triggered when an audio has been asychronous prepared
* The MAEvent::audioInstance contains the prepared MAAudioInstance,
* or <0 if a problem happened while preparing.
*/
#define EVENT_TYPE_AUDIO_PREPARED 19

/**
* \brief Event which is triggered when a streaming audio has finished playing
* The MAEvent::audioInstance contains the MAAudioInstance which finished
*/
#define EVENT_TYPE_AUDIO_COMPLETED 20

/** \brief The size of the screen has changed.
* Use maGetScrSize() to get the new size.
*
* If the screen is the current draw target, the clipping rectangle is removed.
* Use maSetClipRect() to reset it.
*/
#define EVENT_TYPE_SCREEN_CHANGED 21

/// Character input. Uses MAEvent::character.
#define EVENT_TYPE_CHAR 22

/** \brief The text box created by maTextBox() was just closed.
* Uses MAEvent::textboxResult and MAEvent::textboxLength.
*/
#define EVENT_TYPE_TEXTBOX 23

/** \brief The home screen became visible.
 * Currently implemented only on Android and Symbian.
 * \see maHomeScreenEventsOn()
 */
#define EVENT_TYPE_HOMESCREEN_SHOWN 24

/** \brief The home screen was hidden because an
 * application came to front.
 * Currently implemented only on Android and Symbian.
 * \see maHomeScreenEventsOn()
 */
#define EVENT_TYPE_HOMESCREEN_HIDDEN 25

/** \brief The screen was turned on (the device
 * went out of sleep state).
 * Currently implemented only on Android.
 * \see maScreenActivateEventsOn()
 */
#define EVENT_TYPE_SCREEN_STATE_ON 26

/** \brief The screen was turned off (the device
 * went into sleep state).
 * Currently implemented only on Android.
 * \see maScreenActivateEventsOn()
 */
#define EVENT_TYPE_SCREEN_STATE_OFF 27

/**
* \brief An event sent from a native widget.
* \par The application can use the MAEvent.data field to access
* widget event data, which is of type MAWidgetEventData.
* For example: \n
* \code MAWidgetEventData* widgetEventData = (MAWidgetEventData*) event.data; \endcode
* \see MAWidgetEventData
*/
#define EVENT_TYPE_WIDGET 28

/** \brief The bluetooth chip was turned off.
* Bluetooth functions will return #CONNERR_UNAVAILABLE.
* Currently implemented only on Android.
*/
#define EVENT_TYPE_BLUETOOTH_TURNED_OFF 29

/** \brief The bluetooth chip was turned on.
* Bluetooth functions will now work normally again.
* Currently implemented only on Android.
*/
#define EVENT_TYPE_BLUETOOTH_TURNED_ON 30

/**
* \brief The ImagePicker dialog was dismissed either by Cancel, either by OK.
*/
#define EVENT_TYPE_IMAGE_PICKER 31

/** \brief SMS result message.
* The field status contains one of the
* This event is sent on Android and iOS.
*/
#define EVENT_TYPE_SMS 32

/**
* \brief Provides data from active sensors.
* \see MAEvent::sensor
* \see maSensorStart()
*/
#define EVENT_TYPE_SENSOR 33

/**
* \brief The maAlert message box was dismissed by one of the available buttons.
* See #EVENT_TYPE_ALERT for the event.
*/
#define EVENT_TYPE_ALERT 34

/** \brief A new NFC tag was received
* A new tag has been received, use maGetNextTag to
* retreive it.
*/
#define EVENT_TYPE_NFC_TAG_RECEIVED 35

/** \brief New tag data was read
* An asynchronous NFC tag read operation was
* completed.
*/
#define EVENT_TYPE_NFC_TAG_DATA_READ 36

/** \brief New tag data was written
* An asynchronous NFC tag write operation was
* completed.
*/
#define EVENT_TYPE_NFC_TAG_DATA_WRITTEN 37

/** \brief A batch operation was performed
*/
#define EVENT_TYPE_NFC_BATCH_OP 38

/** \brief Tag authentication was performed
* An asynchronous NFC tag authentication read was
* completed.
*/
#define EVENT_TYPE_NFC_TAG_AUTH_COMPLETE 39

/**
* \brief Tag was made read only
*  An asynchronous NFC tag read only operation was completed.
*/
#define EVENT_TYPE_NFC_TAG_READ_ONLY 40

/**
* Send by maOptionsBox dialog when one of the option buttons is clicked.
*/
#define EVENT_TYPE_OPTIONS_BOX_BUTTON_CLICKED 41

/**
* \brief Send by a banner ad.
*/
#define EVENT_TYPE_ADS_BANNER 42

/**
* \brief Send when the application receives a local notification.
*/
#define EVENT_TYPE_LOCAL_NOTIFICATION 43

/**
* \brief Send when the application receives a registration result.
* The application tries to register to Apple Push Service, or Google GCM/C2DM Service,
* and the received result ( either success, either fail) is sending this event.
* After this event is received, get the result of the registration request by
* calling maNotificationPushGetRegistration.
*/
#define EVENT_TYPE_PUSH_NOTIFICATION_REGISTRATION 44

/**
* \brief Send when the application receives an unregistration result.
* The application unregistered from Google GCM/C2DM Service, and will not
* receive anymore push messages.
* Platform: Android only.
*/
#define EVENT_TYPE_PUSH_NOTIFICATION_UNREGISTRATION 45

/**
* \brief Send when the application receives a push notification.
*/
#define EVENT_TYPE_PUSH_NOTIFICATION 46

/**
* \brief Send before the Native Image Picker is dismissed.
* This event will contain a MACaptureEventData struct.
*/
#define EVENT_TYPE_CAPTURE 47

/**
* \brief Send by the Purchase API.
* This event will contain a MAPurchaseEventData struct.
*/
#define EVENT_TYPE_PURCHASE 48

/**
* \brief A camera event fired when you get any of the camera preview events
*/
#define EVENT_TYPE_CAMERA_PREVIEW 49

/** \brief The telephone network status changed.
* MAEvent::state is the new state,
* one of the \link #MA_NETWORK_UNKNOWN MA_NETWORK \endlink constants.
*/
#define EVENT_TYPE_NETWORK 50

/**
* \brief Sent when the current screen orientation has changed.
* MAEvent::orientation is the new screen orientation. One of the constants
* \link #MA_SCREEN_ORIENTATION_PORTRAIT MA_SCREEN_ORIENTATION \endlink.
*/
#define EVENT_TYPE_ORIENTATION_DID_CHANGE 51

/**
* \brief Sent just before the current screen orientation starts changing.
* Platform: iOS only.
*/
#define EVENT_TYPE_ORIENTATION_WILL_CHANGE 52

/**
* \brief Used to notify when the snapshot taken via #maCameraSnapshotAsync,
* is completed.
* The events of this type contain the handler for the image data,
* the image size, the \link #MA_IMAGE_REPRESENTATION_UNKNOWN data representation \endlink
* and a return code.
*/
#define EVENT_TYPE_CAMERA_SNAPSHOT 53

/**
* \brief Send by maAlert dialog being canceled by user dimissing it.
*/
#define EVENT_TYPE_ALERT_DISMISSED 54

/**
* \brief Used to notify when an operation of exporting files, from the
* application to the device storages, reached the finish point.
*/
#define EVENT_TYPE_MEDIA_EXPORT_FINISHED 55
/// The MoSync Reference Environment, also known as the Emulator.
#define RUNTIME_MORE 1

/// Java ME
#define RUNTIME_JAVA 2

/// Symbian
#define RUNTIME_SYMBIAN 3

/// Windows CE, also known as Windows Mobile.
#define RUNTIME_WINCE 4
/// Caused by a MoSync Panic. MAPanicReport::code is the panic code.
#define REPORT_PANIC 1

/// Caused by a native exception. MAPanicReport::string describes the exception.
#define REPORT_EXCEPTION 2

/// Caused by a platform-specific error. MAPanicReport::code is valid.
#define REPORT_PLATFORM_CODE 3

/// Caused by a call to maPanic(). MAPanicReport::code and MAPanicReport::string are the
/// parameters from the call.
#define REPORT_USER_PANIC 4

/// Caused by the Close event timeout. Neither code or string are valid.
#define REPORT_TIMEOUT 5
#define MA_EXTENSION_MODULE_UNAVAILABLE -1
#define MA_EXTENSION_FUNCTION_UNAVAILABLE -1
#define FONT_TYPE_SERIF 0
#define FONT_TYPE_SANS_SERIF 1
#define FONT_TYPE_MONOSPACE 2
#define FONT_STYLE_NORMAL 0
#define FONT_STYLE_BOLD 1
#define FONT_STYLE_ITALIC 2
/**
* The available result codes for fonts.
*/
/**
* \brief Indicates that the call to a font syscall was successful.
*/
#define RES_FONT_OK 1

/**
* \brief Indicates that an invalid font handle was passed.
*/
#define RES_FONT_INVALID_HANDLE -1

/**
* \brief Indicates that the index was off the list size.
*/
#define RES_FONT_INDEX_OUT_OF_BOUNDS -2

/**
* \brief Indicates that a default font with that combination does not exist.
*/
#define RES_FONT_NO_TYPE_STYLE_COMBINATION -3

/**
* \brief Indicates that there is no font with that name on the device.
*/
#define RES_FONT_NAME_NONEXISTENT -4

/**
* \brief Indicates that maFontGetCount() was not called first.
*/
#define RES_FONT_LIST_NOT_INITIALIZED -5

/**
* \brief Indicates that the buffer is not big enough to store the font name.
*/
#define RES_FONT_INSUFFICIENT_BUFFER -6

/**
* \brief Indicates that an invalid size was passed.
*/
#define RES_FONT_INVALID_SIZE -7

/**
* \brief Indicates that the font cannot be deleted because it is in use.
*  maFontDelete(handle)  fails with this return code.
*/
#define RES_FONT_DELETE_DENIED -8
#define MA_LOC_NONE 1
#define MA_LOC_INVALID 2
#define MA_LOC_UNQUALIFIED 3
#define MA_LOC_QUALIFIED 4
/**
* Availability status code: the location provider is available.
*/
#define MA_LPS_AVAILABLE 1

/**
* Availability status code: the location provider is temporarily unavailable.
* Temporary unavailability means that the method is unavailable due to reasons
* that can be expected to possibly change in the future and the provider to
* become available. An example is not being able to receive the signal because
* the signal used by the location method is currently being obstructed,
* e.g. when deep inside a building for satellite based methods.
* However, a very short transient obstruction of the signal should not cause
* the provider to toggle quickly between TEMPORARILY_UNAVAILABLE and AVAILABLE.
*/
#define MA_LPS_TEMPORARILY_UNAVAILABLE 2

/**
* Availability status code: the location provider is out of service.
* Being out of service means that the method is unavailable and the implementation
* is not able to expect that this situation would change in the near future.
* An example is when using a location method implemented in an external device and
* the external device is detached.
*/
#define MA_LPS_OUT_OF_SERVICE 3
#define MA_ACCESS_READ 1
#define MA_ACCESS_READ_WRITE 3
/// Beginning of file.
#define MA_SEEK_SET 0

/// Current position.
#define MA_SEEK_CUR 1

/// End of file.
#define MA_SEEK_END 2
/// Don't sort the files.
#define MA_FL_SORT_NONE 0

/// Sort the files by date. See maFileDate().
#define MA_FL_SORT_DATE 1

/// Sort the files by name. Case-sensitive?
#define MA_FL_SORT_NAME 2

/// Sort the files by size. See maFileSize().
#define MA_FL_SORT_SIZE 3
/// Oldest / smallest / A first.
#define MA_FL_ORDER_ASCENDING 0x10000

/// Newest / biggest / Z first.
#define MA_FL_ORDER_DESCENDING 0x20000
/**
 * @brief Indicatest an unknown multimedia type.
 */
#define MA_MEDIA_TYPE_UNKNOWN -1

/**
 * @brief Indicates an image type. This is used in multimedia operations.
 */
#define MA_MEDIA_TYPE_IMAGE 0
/**
 * @brief Indicates that the multimedia operation was successful.
 */
#define MA_MEDIA_RES_OK 0

/**
 * @brief Indicatest that the operation of exporting an image failed.
 */
#define MA_MEDIA_RES_IMAGE_EXPORT_FAILED -2
#define MA_FPROP_IS_BACKED_UP 1
#define MA_FERR_GENERIC -2
#define MA_FERR_NOTFOUND -3
#define MA_FERR_FORBIDDEN -4
#define MA_FERR_RENAME_FILESYSTEM -5
#define MA_FERR_RENAME_DIRECTORY -6
#define MA_FERR_WRONG_TYPE -7

/// The sorting method requested is unsupported on the current platform.
#define MA_FERR_SORTING_UNSUPPORTED -8

#define MA_FERR_NO_SUCH_PROPERTY -9
/**
* Values for the status field in the #EVENT_TYPE_SMS event.
* This event is sent on Android and iOS.
* Note: On iOS platforms the MA_SMS_RESULT_DELIVERED message corresponds
* To the SMS being successfully queued by the system. There is no way to
* know if it was actually delivered.
*/
/// The SMS was sent.
#define MA_SMS_RESULT_SENT 1

/// The SMS was NOT sent.
#define MA_SMS_RESULT_NOT_SENT 2

/// The SMS was delivered.
#define MA_SMS_RESULT_DELIVERED 3

/// The SMS was NOT delivered.
#define MA_SMS_RESULT_NOT_DELIVERED 4
#define MA_NETWORK_UNKNOWN 0
#define MA_NETWORK_NO_SERVICE 1
#define MA_NETWORK_EMERGENCY_ONLY 2
#define MA_NETWORK_SEARCHING 3
#define MA_NETWORK_BUSY 4

/**
* Your operator's home network. Data connections are possible here.
*/
#define MA_NETWORK_HOME 5

#define MA_NETWORK_DENIED 6

/**
* You're abroad. Data connections are possible here, but usually, extremely expensive.
* Avoid making any connections unless you have WLAN access,
* or the user is very sure of the cost.
*/
#define MA_NETWORK_ROAMING 7
/** The default. Connects to the IAP saved by maIapSave(), or,
* if there is no saved IAP, opens the IAP selection dialog.
*/
#define MA_IAP_METHOD_STANDARD 1

/**
* Connects to the WLAN IAP with the highest signal strength.
*/
#define MA_IAP_METHOD_WLAN 2
/// All IAPs except WLAN.
#define MA_IAP_FILTER_NOT_WLAN 1

/// Only WLAN IAPs.
#define MA_IAP_FILTER_WLAN 2

/// All IAPs. This is the default.
#define MA_IAP_FILTER_ALL 3
/**
* @brief A constant that represents the maximum snapshot size.
*/
/** @ingroup CameraAPI */
#define MA_CAMERA_SNAPSHOT_MAX_SIZE -1
/**
* @brief A constant that represents the flash being on.
*/
/** @ingroup CameraAPI */
#define MA_CAMERA_CONST_BACK_CAMERA 0

/**
* @brief A constant that represents the flash being in the automatic mode.
*/
/** @ingroup CameraAPI */
#define MA_CAMERA_CONST_FRONT_CAMERA 1
/**
* @brief A constant that represents successful camera operation.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_OK 1

/**
* @brief A constant that represents a failed camera operation.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_FAILED -2

/**
* @brief A constant that represents a camera failing to start.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_NOT_STARTED -3

/**
* @brief A constant that represents a property not supported by the device.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_PROPERTY_NOTSUPPORTED -4

/**
* @brief A constant that represents an invalid value for that property.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_INVALID_PROPERTY_VALUE -5

/**
* @brief A constant that represents a property value not supported by the device.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_VALUE_NOTSUPPORTED -6

/**
* @brief Another type of camera preview events has aldready been enabled.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_EVENTS_ALREADY_ENABLED -7

/**
* @brief The size of the screen which you want to read from the preview is not
* withing the visual area.
*/
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_INVALID_PREVIEW_SIZE -8

/**
 * @brief Snapshot operation is in progress. Used when trying to restart a
 * camera or when trying to take another snapshot while a snapshot is in progress.
 */
/** @ingroup CameraResultCodes */
#define MA_CAMERA_RES_SNAPSHOT_IN_PROGRESS -9
/**
* @brief A constant that represents the flash being on.
*/
/** @ingroup FlashModes */
#define MA_CAMERA_FLASH_ON "on"

/**
* @brief A constant that represents the flash being in the automatic mode.
*/
/** @ingroup FlashModes */
#define MA_CAMERA_FLASH_AUTO "auto"

/**
* @brief A constant that represents the flash being off.
*/
/** @ingroup FlashModes */
#define MA_CAMERA_FLASH_OFF "off"

/**
* @brief A constant that represents the flash being in the torch mode.
*/
/** @ingroup FlashModes */
#define MA_CAMERA_FLASH_TORCH "torch"
/**
* @brief A constant that represents the focus mode being automatic.
*/
/** @ingroup FocusModes */
#define MA_CAMERA_FOCUS_AUTO "auto"

/**
* @brief A constant that turns the camera to focus to infinity.
*/
/** @ingroup FocusModes */
#define MA_CAMERA_FOCUS_INFINITY "infinity"

/**
* @brief A constant that turns the camera to macro mode.
*/
/** @ingroup FocusModes */
#define MA_CAMERA_FOCUS_MACRO "macro"

/**
* @brief A constant that sets the camera to fixed focus mode.
*/
/** @ingroup FocusModes */
#define MA_CAMERA_FOCUS_FIXED "fixed"
/**
* @brief A constant that represents JPEG image format.
*/
/** @ingroup ImageFormat */
#define MA_CAMERA_IMAGE_JPEG "jpeg"

/**
* @brief A constant that represents RAW image format.
*/
/** @ingroup ImageFormat */
#define MA_CAMERA_IMAGE_RAW "raw"
/**
* @brief An integer constant that represents unknown image format.
*/
/** @ingroup ImageFormat */
#define MA_IMAGE_REPRESENTATION_UNKNOWN -1

/**
* @brief An integer constant that represents RAW image format.
*/
/** @ingroup ImageFormat */
#define MA_IMAGE_REPRESENTATION_RAW 0

/**
* @brief An integer constant that represents JPEG image format.
*/
/** @ingroup ImageFormat */
#define MA_IMAGE_REPRESENTATION_JPEG 1

/**
* @brief An integer constant that represents PNG image format.
*/
/** @ingroup ImageFormat */
#define MA_IMAGE_REPRESENTATION_PNG 2
/**
* @brief Sets the flash mode for the camera.
*
* @validvalue can be one of the #MA_CAMERA_FLASH_ON, #MA_CAMERA_FLASH_OFF, #MA_CAMERA_FLASH_AUTO, #MA_CAMERA_FLASH_TORCH constants
*
* @par Example
* \code
*	maCameraSetProperty(MAW_CAMERA_FLASH_MODE, MA_CAMERA_FLASH_AUTO);
* \endcode
*/
/** @ingroup CameraProperties */
#define MA_CAMERA_FLASH_MODE "flash-mode"

/**
* @brief Sets the focus mode for the camera.
*
* @validvalue can be one of the #MA_CAMERA_FOCUS_AUTO, #MA_CAMERA_FOCUS_INFINITY, #MA_CAMERA_FOCUS_MACRO, #MA_CAMERA_FOCUS_FIXED constants
*
* @par Example
* \code
*	maCameraSetProperty(MAW_CAMERA_FOCUS_MODE, MA_CAMERA_FOCUS_AUTO);
* \endcode
*/
/** @ingroup CameraProperties */
#define MA_CAMERA_FOCUS_MODE "focus-mode"

/**
* @brief Sets the image format for the camera.
*
* @validvalue can be one of the #MA_CAMERA_IMAGE_JPEG, #MA_CAMERA_IMAGE_RAW constants
*
* @par Example
* \code
*	maCameraSetProperty(MAW_CAMERA_IMAGE_FORMAT, MA_CAMERA_IMAGE_JPEG);
* \endcode
*/
/** @ingroup CameraProperties */
#define MA_CAMERA_IMAGE_FORMAT "image-format"

/**
* @brief Sets the zoom level for the camera.
*
* @validvalue an int string that can be between 0 and #MA_CAMERA_MAX_ZOOM
*
* @par Example
* \code
*	maCameraSetProperty(MAW_CAMERA_ZOOM, "1");
* \endcode
*/
/** @ingroup CameraProperties */
#define MA_CAMERA_ZOOM "zoom"

/**
* @brief Provides the information about the maximum supported zoom level on the device.
*
* @getonly
*
*/
/** @ingroup CameraProperties */
#define MA_CAMERA_MAX_ZOOM "max-zoom"

/**
* @brief Indicates that if the device supports zoom or not.
*
* @validvalue the returned value is "true" for support and "false" for lack of support.
*
* @getonly
*/
/** @ingroup CameraProperties */
#define MA_CAMERA_ZOOM_SUPPORTED "zoom-supported"

/**
* @brief Indicates that if the device has a flash or not.
*
* @validvalue the returned value is "true" for support and "false" for lack of support.
*
* @getonly
*/
/** @ingroup CameraProperties */
#define MA_CAMERA_FLASH_SUPPORTED "flash-supported"
/** @ingroup CameraPreviewEvents */
#define MA_CAMERA_PREVIEW_FRAME 1
/** @ingroup CameraPreviewEvents */
#define MA_CAMERA_PREVIEW_AUTO_FOCUS 2
/// The user is allowed to enter any text, including line breaks.
#define MA_TB_TYPE_ANY 0

/// The user is allowed to enter an e-mail address.
#define MA_TB_TYPE_EMAILADDR 1

/// The user is allowed to enter an integer value.
#define MA_TB_TYPE_NUMERIC 2

/// The user is allowed to enter a phone number.
#define MA_TB_TYPE_PHONENUMBER 3

/// The user is allowed to enter a URL.
#define MA_TB_TYPE_URL 4

/// The user is allowed to enter a real number value.
/// This extends #MA_TB_TYPE_NUMERIC by allowing a decimal point.
#define MA_TB_TYPE_DECIMAL 5

/** \brief The user is allowed to enter any text, except for line breaks.
* Unavailable on some platforms.
* In that case, maTextBox() will return #MA_TB_RES_TYPE_UNAVAILABLE.
* You can use #MA_TB_TYPE_ANY instead.
*/
#define MA_TB_TYPE_SINGLE_LINE 100

/** Use this to separate types from flags in the \a constraints parameter.
* This is not a valid type value.
*/
#define MA_TB_TYPE_MASK 0xFFFF
/// The user chose OK.
#define MA_TB_RES_OK 1

/// The user chose Cancel.
#define MA_TB_RES_CANCEL 2

/// The specified type is unavailable on this platform.
#define MA_TB_RES_TYPE_UNAVAILABLE -3
/// Indicates that the text entered is confidential data that should be
/// obscured whenever possible.
/// This implies #MA_TB_FLAG_SENSITIVE.
#define MA_TB_FLAG_PASSWORD 0x10000

/// Indicates that editing is disallowed.
#define MA_TB_FLAG_UNEDITABLE 0x20000

/// Indicates that the text entered is sensitive data that the implementation
/// must never store into a dictionary or table for use in predictive, auto-completing,
/// or other accelerated input schemes. A credit card number is an example of sensitive data.
#define MA_TB_FLAG_SENSITIVE 0x40000

/// Indicates that the text entered does not consist of words that are likely
/// to be found in dictionaries typically used by predictive input schemes.
#define MA_TB_FLAG_NON_PREDICTIVE 0x80000

/// This flag is a hint to the implementation that during text editing,
/// the initial letter of each word should be capitalized.
#define MA_TB_FLAG_INITIAL_CAPS_WORD 0x100000

/// This flag is a hint to the implementation that during text editing,
/// the initial letter of each sentence should be capitalized.
#define MA_TB_FLAG_INITIAL_CAPS_SENTENCE 0x200000
/// A persistent notification that will launch the
/// application when selected.
#define NOTIFICATION_TYPE_APPLICATION_LAUNCHER 1
/// Application will run with screen on (consumes power).
#define MA_WAKE_LOCK_ON 1

/// Turn off the wake lock.
#define MA_WAKE_LOCK_OFF 2
/**
* \brief The toast timeout. Toasts can be displayed using #maToast.
*/
#define MA_TOAST_DURATION_SHORT 0

#define MA_TOAST_DURATION_LONG 1
/**
* Together with the image picker event (\link EVENT_TYPE_IMAGE_PICKER IMAGE_PICKER \endlink),
* this specifies the type of encoding used for the image data returned.
*/
#define MA_IMAGE_PICKER_ITEM_ENCODING_PNG 1

#define MA_IMAGE_PICKER_ITEM_ENCODING_JPEG 2
/**
* Determines what kind of event do we need from the image picker.
*/
#define MA_IMAGE_PICKER_EVENT_RETURN_TYPE_IMAGE_HANDLE 1

#define MA_IMAGE_PICKER_EVENT_RETURN_TYPE_IMAGE_DATA 2
/** @ingroup SensorTypes */
#define SENSOR_TYPE_ACCELEROMETER 1
/** @ingroup SensorTypes */
#define SENSOR_TYPE_MAGNETIC_FIELD 2
/** @ingroup SensorTypes */
#define SENSOR_TYPE_ORIENTATION 3
/** @ingroup SensorTypes */
#define SENSOR_TYPE_GYROSCOPE 4
/** @ingroup SensorTypes */
#define SENSOR_TYPE_PROXIMITY 5
/** @ingroup SensorTypes */
#define SENSOR_TYPE_COMPASS 6
/** @ingroup SensorConsts */
#define SENSOR_RATE_FASTEST 0
/** @ingroup SensorConsts */
#define SENSOR_RATE_GAME -1
/** @ingroup SensorConsts */
#define SENSOR_RATE_NORMAL -2
/** @ingroup SensorConsts */
#define SENSOR_RATE_UI -3
/** @ingroup SensorConsts */
#define SENSOR_ERROR_NONE 0
/** @ingroup SensorConsts */
#define SENSOR_ERROR_NOT_AVAILABLE -1
/** @ingroup SensorConsts */
#define SENSOR_ERROR_INTERVAL_NOT_SET -2
/** @ingroup SensorConsts */
#define SENSOR_ERROR_ALREADY_ENABLED -3
/** @ingroup SensorConsts */
#define SENSOR_ERROR_NOT_ENABLED -4
/** @ingroup SensorConsts */
#define SENSOR_ERROR_CANNOT_DISABLE -5
/** @ingroup SensorConsts */
#define UIDEVICE_ORIENTATION_UNKNOWN 0
/** @ingroup SensorConsts */
#define UIDEVICE_ORIENTATION_PORTRAIT 1
/** @ingroup SensorConsts */
#define UIDEVICE_ORIENTATION_PORTRAIT_UPSIDE_DOWN 2
/** @ingroup SensorConsts */
#define UIDEVICE_ORIENTATION_LANDSCAPE_LEFT 3
/** @ingroup SensorConsts */
#define UIDEVICE_ORIENTATION_LANDSCAPE_RIGHT 4
/** @ingroup SensorConsts */
#define UIDEVICE_ORIENTATION_FACE_UP 5
/** @ingroup SensorConsts */
#define UIDEVICE_ORIENTATION_FACE_DOWN 6
/** @ingroup SensorConsts */
#define SENSOR_PROXIMITY_VALUE_FAR 0
/** @ingroup SensorConsts */
#define SENSOR_PROXIMITY_VALUE_NEAR 1
/**
* A constant indicating there is no NFC support on the device.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NOT_AVAILABLE -1

/**
* A constant indicating NFC is not enabled on the device. (But there is hardware support).
*/
/** @ingroup NFCAPI */
#define MA_NFC_NOT_ENABLED -2

/**
* A constant indicating an invalid tag type.
*/
/** @ingroup NFCAPI */
#define MA_NFC_INVALID_TAG_TYPE -2

/**
* An error code if tag connection is lost.
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_CONNECTION_LOST -3

/**
* An error code if trying to perform I/O on an unconnected
* tag.
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_NOT_CONNECTED -4

/**
* An error code used by maNFCWriteNDEF if maNFCWriteNDEF was
* performed on an NDEF_FORMATTABLE tag and failed.
*/
/** @ingroup NFCAPI */
#define MA_NFC_FORMAT_FAILED -5

/**
* An error code if some general I/O error occurred,
* other than the special case of tag connection being lost.
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_IO_ERROR -127
/**
* Represents an NDEF (NFC Data Exchange Format) tag.
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_TYPE_NDEF 1

/**
* Represents a Mifare Classic tag.
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_TYPE_MIFARE_CL 2

/**
* Represents a Mifare Ultralight tag.
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_TYPE_MIFARE_UL 3

/**
* Represents an NfcA tag (ISO 14443-3A).
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_TYPE_NFC_A 4

/**
* Represents an NfcB tag (ISO 14443-3B).
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_TYPE_NFC_B 5

/**
* Represents an ISO-DEP tag (ISO 14443-4).
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_TYPE_ISO_DEP 6

/**
* Represents an 'abstract' tag that can
* accept requests for formatting it into
* an NDEF tag.
*/
/** @ingroup NFCAPI */
#define MA_NFC_TAG_TYPE_NDEF_FORMATTABLE 128
/**
* Indicates the NDEF message is empty.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_EMPTY 0

/**
* Indicates the NDEF message is of a 'well-known' type;
* it may be further identified using the MA_NFC_NDEF_RTD_*
* constants.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_WELL_KNOWN 1

/**
* Indicates the NDEF message contains mime media;
* use maNFCGetType() to get the mime type.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_MIME_MEDIA 2

/**
* Indicates the NDEF message contains an absolute URI,
* the type conforming to RFC 3986.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_ABSOLUTE_URI 3

/**
* Indicates the type of the NDEF message being 'external'.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_EXTERNAL_TYPE 4

/**
* Indicates the contents of the NDEF message to be of
* an unknown type. The type of the NDEF message should
* be empty.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_UNKNOWN 5

/**
* Constant for chunked NDEF messages.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_UNCHANGED 6

/**
* Reserved constant.
*/
/** @ingroup NFCAPI */
#define MA_NFC_NDEF_TNF_RESERVED 7
/**
* The A key for MiFare Classic authentication
*/
/** @ingroup NFCAPI */
#define MA_NFC_MIFARE_KEY_A 1

/**
* The B key for MiFare Classic authentication
*/
/** @ingroup NFCAPI */
#define MA_NFC_MIFARE_KEY_B 2
/** @ingroup DBAPI */
#define MA_DB_TYPE_NULL 1
/** @ingroup DBAPI */
#define MA_DB_TYPE_INT 2
/** @ingroup DBAPI */
#define MA_DB_TYPE_INT64 3
/** @ingroup DBAPI */
#define MA_DB_TYPE_DOUBLE 4
/** @ingroup DBAPI */
#define MA_DB_TYPE_BLOB 5
/** @ingroup DBAPI */
#define MA_DB_TYPE_DATA 6
/** @ingroup DBAPI */
#define MA_DB_TYPE_TEXT 7
/**
 * Status codes returned by the maDB functions.
 */
/**
 * Success return value.
 */
/** @ingroup DBAPI */
#define MA_DB_OK 0

/**
 * Error return value (-1 reserved for IOCtl not implemented).
 */
/** @ingroup DBAPI */
#define MA_DB_ERROR -2

/**
 * The cursor is beyond the last row
 * when calling #maDBCursorNext.
 */
/** @ingroup DBAPI */
#define MA_DB_NO_ROW -3

/**
 * A database field value was NULL when calling
 * the maDBCursorGetColumn* functions.
 */
/** @ingroup DBAPI */
#define MA_DB_NULL -4
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_DATA_STREAM 1
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_OK 0
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_INVALID_INSTANCE -2
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_INVALID_DATA -3
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_INVALID_FILENAME -4
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_INVALID_FILE -5
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_STREAMING_NOT_SUPPORTED -6
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_VOLUME_OUT_OF_RANGE -7
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_POSITION_OUT_OF_RANGE -8
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_INVALID_SOUND_FORMAT -9
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_OUT_OF_MEMORY -10
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_ALREADY_PREPARED -11
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_PREPARE_FAILED -12
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_IS_PLAYING -13
/** @ingroup AudioAPIConsts */
#define MA_AUDIO_ERR_GENERIC -14
/**
* @brief Indicates that the call was successful.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_OK 0

/**
* @brief Indicates that the call to a maAdsAddBannerToScreen or maAdsRemoveBannerFromScreen received
* an invalid layout handle.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_INVALID_LAYOUT_HANDLE -1

/**
* @brief Indicates that the call to a banner function received an invalid banner handle.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_INVALID_BANNER_HANDLE -2

/**
* @brief Indicates that the call to maAdsBannerSetProperty or maAdsBannerGetProperty received
* an invalid property name.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_INVALID_PROPERTY_NAME -3

/**
* @brief Indicates that the call to maAdsBannerSetProperty or maAdsBannerGetProperty received
* an invalid property value.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_INVALID_PROPERTY_VALUE -4

/**
* @brief Indicates that the call to maAdsBannerSetProperty needs a larger buffer.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_INVALID_STRING_BUFFER_SIZE -5

/**
* @brief Indicates that the call to an Ad syscall was unsuccessful.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_ERROR -6

/**
* @brief Indicates that ads are not supported on current platform.
*/
/** @ingroup AdsResultCodes */
#define MA_ADS_RES_UNSUPPORTED -7
/**
* @brief Indicates that something happened internally: for instance, the Activity may have been destroyed mid-refresh.
* Platform: Android.
*/
/** @ingroup AdsErrorCodes */
#define MA_ADS_ERROR_INTERNAL -1

/**
* @brief Indicates that the ad request is invalid.
* Platform: Android.
*/
/** @ingroup AdsErrorCodes */
#define MA_ADS_ERROR_INVALID_REQUEST -2

/**
* @brief Indicates that the connection to the advertisements server failed.
* Platform: Android, iOS and Windows Phone 7.1.
*/
/** @ingroup AdsErrorCodes */
#define MA_ADS_ERROR_NETWORK -3

/**
* @brief Indicates that no ad was returned due to lack of ad inventory.
* Platform: Android, iOS and Windows Phone 7.1.
*/
/** @ingroup AdsErrorCodes */
#define MA_ADS_ERROR_NO_FILL -4

/**
* @brief Indicates that your application has not been configured to receive advertisements.
* Platform: iOS.
*/
/** @ingroup AdsErrorCodes */
#define MA_ADS_ERROR_CONFIGURATION -5

/**
* @brief Indicates that the banner is visible, but no advertisement is shown.
* Your application must always hide the banner when it does not have an advertisement to display.
* Platform: iOS.
*/
/** @ingroup AdsErrorCodes */
#define MA_ADS_ERROR_NO_CONTENT -6

/**
* @brief Indicates that ad content is not available because the application is not currently active.
* Platform: iOS.
*/
/** @ingroup AdsErrorCodes */
#define MA_ADS_ERROR_APPLICATION_INACTIVE -7
/**
* @brief Gets the height of the ads banner.
* The view will have no size until the ad is loaded.
*
* @validvalue an int.
*
* @getonly
*
* @par Example
* \code
*   char buf[256];
*	maAdsBannerGetProperty(MA_ADS_HEIGHT, buf);
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_HEIGHT "height"

/**
* @brief Gets the width of the ads banner.
* The view will have no size until the ad is loaded.
*
* @validvalue an int.
*
* @getonly
*
* @par Example
* \code
*    char buf[256];
*	maAdsBannerGetProperty(MA_ADS_WIDTH, buf);
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_WIDTH "width"

/**
* @brief Sets whether the banner is visible or not. Layouts ignore invisible widgets.
* The banner is visible by default.
*
* @validvalue A boolean string 'true' or 'false', where true is visible and false is invisible.
*
* @setandget
*
* @par Example
* \code
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_VISIBLE, "false");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_VISIBLE "visible"

/**
* @brief Sets whether the banner is enabled or not. If disabled, the user cannot interact with it.
* Ads are enabled by default.
*
* @validvalue A boolean string 'true' or 'false', where true is enabled and false is disabled.
*
* @setandget
*
* @par Example
* \code
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_ENABLED, "false");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_ENABLED "enabled"

/**
* @brief Sets the devices that are going to receive test ads only.
* You should utilize this property during development to avoid generating false impressions.
* Available only on Android.
*
* @validvalue String that holds the device ID.
*
* @setonly
*
* @par Example
* \code
*   char buf[256];
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_TEST_DEVICE, "E83D20734F72FB3108F104ABC0FFC738"); // My T-Mobile G1 test phone
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_TEST_DEVICE "testDevice"

/**
* @brief Sets the request state of the ads.
* If set to true ads are starting to be requested, if set to false the request for ads is stopped.
* After requesting for content no other property setter will be taken into account.
* @validvalue A boolean string 'true' or 'false'.
* Available only on Android.
*
* @setonly
*
* @par Example
* \code
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_REQUEST_CONTENT, "true");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_REQUEST_CONTENT "requestContent"

/**
* @brief Returns true if the ad is successfully loaded and is ready to be shown.
* Available only on Android.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @getonly
*
* @par Example
* \code
*   char buf[256];
*	maAdsBannerGetProperty(bannerHandle, MA_ADS_IS_READY, buf);
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_IS_READY "isReady"

/**
* @brief Sets the coloration of test ads, specifically the background color.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_COLOR_BG, "0xAAAAFF");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_COLOR_BG "colorBg"

/**
* @brief Sets the coloration of test ads,specifically the gradient background color at top.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_COLOR_BG_TOP, "0xFFFFFF");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_COLOR_BG_TOP "colorBgTop"

/**
* @brief Sets the coloration of test ads, specfiically the border color.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*   char buf[256];
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_COLOR_BORDER, "0xFFFFFF");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_COLOR_BORDER "colorBorder"

/**
* @brief Sets the coloration of test ads, specfiically the link text color.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*   char buf[256];
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_COLOR_LINK, "0xFFFFFF");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_COLOR_LINK "colorLink"

/**
* @brief Sets the coloration of test ads, specfiically the text color.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*   char buf[256];
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_COLOR_TEXT, "0xFFFFFF");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_COLOR_TEXT "colorText"

/**
* @brief Sets the coloration of test ads, specfiically the url color.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*   char buf[256];
*	maAdsBannerSetProperty(bannerHandle, MA_ADS_COLOR_URL, "0xFFFFFF");
* \endcode
*/
/** @ingroup AdsProperties */
#define MA_ADS_COLOR_URL "colorUrl"
/** @ingroup AdsConstants */
#define MA_ADS_SIZE_BANNER 0
/** @ingroup AdsConstants */
#define MA_ADS_SIZE_RECT 1
/** @ingroup AdsConstants */
#define MA_ADS_SIZE_IAB_BANNER 2
/** @ingroup AdsConstants */
#define MA_ADS_SIZE_LEADERBOARD 3
/** @ingroup AdsConstants */
#define MA_ADS_SIZE_WP7_XLARGE 4
/** @ingroup AdsConstants */
#define MA_ADS_SIZE_WP7_XXLARGE 5
/** @ingroup AdsEventTypes */
#define MA_ADS_EVENT_FAILED 0
/** @ingroup AdsEventTypes */
#define MA_ADS_EVENT_LOADED 1
/** @ingroup AdsEventTypes */
#define MA_ADS_EVENT_ON_DISMISS 2
/** @ingroup AdsEventTypes */
#define MA_ADS_EVENT_ON_LEAVE_APPLICATION 3
/**
* @brief Indicates that the call was successful.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_OK 0

/**
* @brief Indicates that the syscall received an invalid local notification handle.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_INVALID_HANDLE -1

/**
* @brief Indicates that the call to maNotificationLocalSetProperty or maNotificationLocalGetProperty received
* an invalid property name.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_INVALID_PROPERTY_NAME -3

/**
* @brief Indicates that the call to maNotificationLocalSetProperty or maNotificationLocalGetProperty received
* an invalid property value.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_INVALID_PROPERTY_VALUE -4

/**
* @brief Indicates that the call to maNotificationLocalGetProperty or maNotificationPushGetData needs a larger buffer.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_INVALID_STRING_BUFFER_SIZE -5

/**
* @brief Indicates that notifications are not supported on current platform.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_UNSUPPORTED -6

/**
* @brief Indicates that maNotficationLocalSetProperty cannot be called after scheduling via
* maNotificationLocalSchedule, or that the call to maNotificationLocalSchedule failed because
* the notification was already scheduled.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_ALREADY_SCHEDULED -7

/**
* @brief Indicates that the call to maNotificationLocalUnschedule failed because the notification
* was not scheduled.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_CANNOT_UNSCHEDULE -8

/**
* @brief Indicates that the call to maNotificationPushRegister was unsuccessful because
* the application is already registered for receiving push notification.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_ALREADY_REGISTERED -9

/**
* @brief Indicates that the call to maNotificationPushUnregister was unsuccessful because
* the application is not registered for receiving push notification.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_NOT_REGISTERED -10

/**
* @brief Indicates that the call to maNotificationPushRegister was unsuccessful because
* the application did not finish processing a previous registration request.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_IN_PROGRESS -11

/**
* @brief Indicates that the call to maNotificationPushRegister was unsuccesfull because the
* device can't read the response, or there was a 500/503 from the server that can be retried later.
* The application should use exponential back off and retry.
* Platform: Android only.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_SERVICE_NOT_AVAILABLE -12

/**
* @brief Indicates that the call to maNotificationPushRegister was unsuccesfull because there is no
* Google account on the phone.
* The application should ask the user to open the account manager and add a Google account.
* Platform: Android only.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_ACCOUNT_MISSING -13

/**
* @brief Indicates that the call to maNotificationPushRegister was unsuccesfull because the password was bad.
* The application should ask the user to enter his/her password, and let user retry manually later.
* Platform: Android only.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_AUTHENTICATION_FAILED -14

/**
* @brief Indicates that the call to maNotificationPushRegister was unsuccesfull because the user has too many
* applications registered.
* The application should tell the user to uninstall some other applications, let user retry manually.
* Platform: Android only.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_TOO_MANY_REGISTRATIONS -15

/**
* @brief Indicates that the call to maNotificationPushRegister was unsuccesfull because the sender account
* is not recognized.
* Platform: Android only.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_INVALID_SENDER -16

/**
* @brief  Indicates that the call to maNotificationPushRegister was unsuccesfull because of incorrect
* phone registration with Google. This phone doesn't currently support GCM/C2DM.
* Platform: Android only.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_PHONE_REGISTRATION_ERROR -17

/**
* @brief Indicates that the call to maNotificationPushGetRegistration needs a larger buffer.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_MESSAGE_BUF_TOO_SMALL -18

/**
* @brief Indicates that the call to maNotificationPushGetRegistration occured before trying to register.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_REGISTRATION_NOT_CALLED -19

/**
* @brief Indicates that the call to an notification syscall was unsuccessful.
*/
/** @ingroup NotificationResultCodes */
#define MA_NOTIFICATION_RES_ERROR -20
/**
* If set, the audio will be repeated until the notification is canceled or the
* notification window is opened.
* Platform: Android only.
*/
/** @ingroup NotificationFlags */
#define MA_NOTIFICATION_FLAG_INSISTENT 4

/**
* Should be set if the notification should not be canceled when the user clicks the
* Clear all button.
* Platform: Android only.
*/
/** @ingroup NotificationFlags */
#define MA_NOTIFICATION_FLAG_NO_CLEAR 32

/**
* Should be set if this notification represents a high-priority event that may be shown to
* the user even if notifications are otherwise unavailable (that is, when the status bar is hidden).
* Platform: Android only.
*/
/** @ingroup NotificationFlags */
#define MA_NOTIFICATION_FLAG_HIGH_PRIORITY 128

/**
* Should be set if the notification should be canceled when it is clicked by the user.
* Platform: Android only.
*/
/** @ingroup NotificationFlags */
#define MA_NOTIFICATION_FLAG_AUTO_CANCEL 16
/**
* For local notifications: if set, the incoming notifications will be displayed to
* the user only if the application is in background.
* @deprecated for local notifications.
* For push notifications: if set, the incoming notifications will be displayed to
* the user only if the application is not in use.
* Note that the received push notification event will always be received regardless
* of this flag.
* This setting is enabled by default.
* Platform: Android only.
*/
/** @ingroup NotificationDisplayFlags */
#define MA_NOTIFICATION_DISPLAY_FLAG_DEFAULT 0

/**
* If set, all the incoming notification will be displayed to the user regardless of
* it's focus state.
* For local notifications: this means that the user will get the notifications when the
* application is in background, but also in foreground.
* For push notifications: this means that the user will get the notifications when the
* application is closed, but also when it's in use.
* Note that the  event will always be received regardless of this flag.
* Platform: Android only.
*/
/** @ingroup NotificationDisplayFlags */
#define MA_NOTIFICATION_DISPLAY_FLAG_ANYTIME 1
/**
* @brief The application accepts notifications that badge the application icon.
* Platform: iOS only.
*/
/** @ingroup NotificationPushTypes */
#define MA_NOTIFICATION_PUSH_TYPE_BADGE 1

/**
* @brief The application accepts alert sounds as notifications.
* Platform: iOS only.
*/
/** @ingroup NotificationPushTypes */
#define MA_NOTIFICATION_PUSH_TYPE_SOUND 2

/**
* @brief The application accepts alert messages as notifications.
* This is the only push notification type that is supported by
* both Android and iOS.
*/
/** @ingroup NotificationPushTypes */
#define MA_NOTIFICATION_PUSH_TYPE_ALERT 4
/**
* @brief Set the number displayed on the application's icon badge.
* Platform: iOS.
*
* @validvalue an int.
*
* @setandget
*
* @par Example
* \code
*   char buf[256];
*	maNotificationLocalGetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_BADGE_NUMBER, buf);
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_BADGE_NUMBER "badge_number"

/**
* @brief Set the date and time when the system should deliver the notification.
* The notification will be fired when the system time is equal to the
* given param time value.
*
* @validvalue an int.
* The date is in seconds(UNIX time - seconds elapsed since January 1, 1970).
* The value should be given according to device system time.
*
* @setandget
*
* @par Example
* \code
*   char buf[256];
*	maNotificationLocalGetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_FIRE_DATE, buf);
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_FIRE_DATE "fire_date"

/**
* @brief Set the message displayed in the notification alert.
* Platform: Android and iOS.
*
* @validvalue an string.
*
* @setandget
*
* @par Example
* \code
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_CONTENT_BODY, "Did you forget something?");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_CONTENT_BODY "content_body"

/**
* @brief Set the title of the action button or slider.
* Platform: iOS.
*
* @validvalue a string.
*
* @setandget
*
* @par Example
* \code
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_ALERT_ACTION, "Show");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_ALERT_ACTION "alert_action"

/**
* @brief Enable/disable the sound played when an alert is displayed.
* Platform: iOS and Android.
* If set to true, it will play the default sound.
*
* @validvalue "true" or "false" strings.
*
* @setandget
*
* @par Example
* \code
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_PLAY_SOUND, "true");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_PLAY_SOUND "play_sound"

/**
* @brief Set the sound to play when an alert is displayed.
* The sound file should be saved in a notifications folder under sdcard storage.
* Note that some devices can only play notification sounds stored in the internal storage,
* in the \system\media\audio\notifications folder.
* Platform: Android.
*
* @validvalue a valid path to an audio file.
*
* @setandget
*
* @par Example
* \code
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_SOUND_PATH, "....");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_SOUND_PATH "soundPath"

/**
* @brief Set the title that goes in the expanded entry of the notification.
* Platform: Android.
*
* @validvalue a string.
*
* @setandget
*
* @par Example
* \code
*     maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_CONTENT_TITLE, "My message");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_CONTENT_TITLE "contentTitle"

/**
* @brief The text that flows by in the status bar when the notification first activates.
* Platform: Android.
*
* @validvalue a string.
*
* @setandget
*
* @par Example
* \code
*     maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_TICKER_TEXT, "You got new message");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_TICKER_TEXT "tickerText"

/**
* @brief Set the flags applied to the local notification.
* Platform: Android.
*
* @validvalue One of the constants:
* - #MA_NOTIFICATION_FLAG_INSISTENT
* - #MA_NOTIFICATION_FLAG_AUTO_CANCEL
* - #MA_NOTIFICATION_FLAG_HIGH_PRIORITY
* - #MA_NOTIFICATION_FLAG_NO_CLEAR.
*
* @setonly
*
* @par Example
* \code
*     maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_FLAG, MA_NOTIFICATION_FLAG_AUTO_CANCEL);
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_FLAG "flag"

/**
* @brief Set the display flag applied to the local notification.
* @deprecated. Not required anymore, since the local notification is received regardless of the applications's state.
* Note the regardless of this flag, the #EVENT_TYPE_LOCAL_NOTIFICATION event will be received.
* Platform: Android.
*
* @validvalue One of the constants:
* - #MA_NOTIFICATION_DISPLAY_FLAG_DEFAULT Which is enabled by default.
* - #MA_NOTIFICATION_DISPLAY_FLAG_ANYTIME.
*
* @setonly
*
* @par Example
* \code
*    // Display the notification even when the application is in foreground.
*    maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_DISPLAY_FLAG, MA_NOTIFICATION_DISPLAY_FLAG_ANYTIME);
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_DISPLAY_FLAG "displayFlag"

/**
* @brief Enable/disable the the default vibration when an alert is displayed.
* Platform: Android only.
* If set to true, it will use the default notification vibrate. This will ignore any given vibrate.
* Using phone vibration requires the VIBRATE permission.
*
* @validvalue "true" or "false" strings.
*
* @setandget
*
* @par Example
* \code
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_VIBRATE, "true");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_VIBRATE "vibrate"

/**
* @brief Set the vibration duration when an alert is displayed.
* Platform: Android only.
* Using phone vibration requires the VIBRATE permission.
*
* @validvalue an int The number of milliseconds to vibrate.
*
* @setonly
*
* @par Example
* \code
*   // Vibrate for 3 seconds.
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_VIBRATE_DURATION, "3000");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_VIBRATE_DURATION "vibrateDuration"

/**
* @brief Enable/Disable the default notification lights.
* This will ignore the #MA_NOTIFICATION_LOCAL_FLASH_LIGHTS_PATTERN.
* Not every color in the spectrum is supported by the device LEDs, and not every device supports the same
* colors, so the hardware estimates to the best of its ability. Green is the most common notification color.
* Platform: Android only.
*
* @validvalue "true" or "false" strings.
*
* @setandget
*
* @par Example
* \code
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_FLASH_LIGHTS, "true");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_FLASH_LIGHTS "flashLights"

/**
* @brief Define your own color and pattern for the lights.
* Not every color in the spectrum is supported by the device LEDs, and not every device supports the same
* colors, so the hardware estimates to the best of its ability. Green is the most common notification color.
* Also, not all Android devices support this feature.
* Platform: Android only.
*
* @validvalue An int array containing 3 values:
* - a value for the ledARGB field (for the color),
* - the ledOffMS field (length of time, in milliseconds, to keep the light off),
* - the ledOnMS (length of time, in milliseconds, to keep the light on).
*  returns #MA_NOTIFICATION_RES_ERROR if the current device doesn't support flashing LED.
* @setonly
*
* @par Example
* \code
* // In this example, the green light repeatedly flashes on for 300 milliseconds and turns off for one second.
*	maNotificationLocalSetProperty(notificationHandle, MA_NOTIFICATION_LOCAL_FLASH_LIGHTS_PATTERN, "0xff00ff00,300,1000");
* \endcode
*/
/** @ingroup LocalNotificationProperties */
#define MA_NOTIFICATION_LOCAL_FLASH_LIGHTS_PATTERN "flashLightsPattern"
/**
* @brief Indicates that the call was successful.
* Platform: Android and iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_OK 0

/**
* @brief The given file name is invalid.
* Platform: iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_FILE_INVALID_NAME -1

/**
* @brief The file already exists.
* Platform: iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_FILE_ALREADY_EXISTS -2

/**
* @brief Indicates that the call to maCaptureSetProperty or maCaptureGetProperty received
* an invalid property name.
* Platform: iOS and Android.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_INVALID_PROPERTY -3

/**
* @brief Indicates that the call to maCaptureSetProperty or maCaptureGetProperty received
* an invalid property value.
* Platform: iOS and Android.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_INVALID_PROPERTY_VALUE -4

/**
* @brief Indicates that the call to maCaptureGetProperty needs a larger buffer.
* Platform: iOS and Android.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_INVALID_STRING_BUFFER_SIZE -5

/**
* @brief Indicates that the call to maCaptureAction received an invalid action type.
* Platform: iOS and Android.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_INVALID_ACTION -6

/**
* @brief Indicates that the call to maCaptureDestroyData received an invalid handle.
* Platform: iOS and Android.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_INVALID_HANDLE -7

/**
* @brief Indicates that capture is not supported on current platform.
* Platform: iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_UNSUPPORTED -8

/**
* @brief Indicates that camera is not available at the moment.
* Platform: iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_CAMERA_NOT_AVAILABLE -9

/**
* @brief Indicates that video recording is not supported.
* Platform: iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_VIDEO_NOT_SUPPORTED -10

/**
* @brief Indicates that camera picture mode is not supported.
* Platform: iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_PICTURE_NOT_SUPPORTED -11

/**
* @brief Indicates that flash mode is not supported.
* Platform: iOS.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_FLASH_NOT_SUPPORTED -12

/**
* @brief Indicates that the recording max duration is not supported.
* Platform: Android.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_MAX_DURATION_NOT_SUPPORTED -13

/**
* @brief Indicates that a call to maCaptureGetProperty was unsuccessfull
* because the property was not previously set.
* Platform: Android.
*/
/** @ingroup CaptureResultCodes */
#define MA_CAPTURE_RES_PROPERTY_VALUE_UNDEFINED -14
/**
* @brief Maximum duration video that should be recorded, in seconds.
* Platform: Android and iOS.
*
* @validvalue Positive integer value.
* Default value is platform specific.
*
* On iOS the maximum duration is by defualt set to 600 seconds.
*
* On Android devices with API level lower than 8
* it returns #MA_CAPTURE_RES_MAX_DURATION_NOT_SUPPORTED.
*
* @setandget
*
* @par Example
* \code
*   char buf[256];
*   sprintf(buf, "%d", 100);
*	maCaptureSetProperty(MA_CAPTURE_MAX_DURATION, buf);
* \endcode
*/
/** @ingroup CaptureProperties */
#define MA_CAPTURE_MAX_DURATION "maxDuration"

/**
* @brief Set the video recording quality.
* Platform: Android and iOS.
* Android: Note that some devices the default camera either does not support low-res video capture,
* or it doesn't understand/process the MediaStore.EXTRA_SIZE_LIMIT correctly.
*
* @validvalue One of the \link #MA_CAPTURE_VIDEO_QUALITY_LOW MA_CAPTURE_VIDEO_QUALITY \endlink constants.
* iOS: Default value is MA_CAPTURE_VIDEO_QUALITY_MEDIUM.
* Android: Default value is MA_CAPTURE_VIDEO_QUALITY_HIGH.
*
* @setandget
*
* @par Example
* \code
*   char buf[256];
*   sprintf(buf, "%d", MA_CAPTURE_VIDEO_QUALITY_HIGH);
*	maCaptureSetProperty(MA_CAPTURE_VIDEO_QUALITY, buf);
* \endcode
*/
/** @ingroup CaptureProperties */
#define MA_CAPTURE_VIDEO_QUALITY "videoQuality"

/**
* @brief Store the recorded movie/taken photo to the user’s Camera Roll album.
* Platform: iOS.
*
* @validvalue "false" or "true".
* Default value: "true".
*
* @setandget
*
* @par Example
* \code
*   char buf[256];
*   sprintf(buf, "%s", "true");
*	maCaptureSetProperty(MA_CAPTURE_CAMERA_ROLL, buf);
* \endcode
*/
/** @ingroup CaptureProperties */
#define MA_CAPTURE_CAMERA_ROLL "cameraRoll"

/**
* @brief Set the flash mode used by the active camera.
* Platform: iOS.
*
* @validvalue One of the \link #MA_CAPTURE_FLASH_AUTO MA_CAPTURE_FLASH \endlink constants.
* Default value: #MA_CAPTURE_FLASH_AUTO.
*
* @setandget
*
* @par Example
* \code
*   char buf[256];
*   sprintf(buf, "%d", MA_CAPTURE_FLASH_OFF);
*	maCaptureSetProperty(MA_CAPTURE_FLASH, buf);
* \endcode
*/
/** @ingroup CaptureProperties */
#define MA_CAPTURE_FLASH "flash"

/**
* @brief Show/hide default camera controls.
* @brief Show/hide default camera controls.
* Platform: iOS.
*
* @validvalue "true" or "false".
* Default value: "true".
*
* @setandget
*
* @par Example
* \code
*   char buf[256];
*   sprintf(buf, "%s", "false");
*	maCaptureSetProperty(MA_CAPTURE_CAMERA_CONTROLS, buf);
* \endcode
*/
/** @ingroup CaptureProperties */
#define MA_CAPTURE_CAMERA_CONTROLS "cameraControls"
/// Use low-quality video recording.
/// Platform: iOS and Android.
/** @ingroup CaptureVideoQuality */
#define MA_CAPTURE_VIDEO_QUALITY_LOW 0

/// The highest-quality video recording supported for the active camera on the device.
/// Platform: iOS and Android.
/** @ingroup CaptureVideoQuality */
#define MA_CAPTURE_VIDEO_QUALITY_HIGH 1

/// Use medium-quality video recording.
/// Platform: iOS only.
/** @ingroup CaptureVideoQuality */
#define MA_CAPTURE_VIDEO_QUALITY_MEDIUM 2
/// Starts video capture.
/// Platform: Android and iOS.
/** @ingroup CaptureAction */
#define MA_CAPTURE_ACTION_RECORD_VIDEO 0

/// Stops recording.
/// Platform: iOS only.
/** @ingroup CaptureAction */
#define MA_CAPTURE_ACTION_STOP_RECORDING 1

/// Starts image capture (takes photo).
/// Platform: Android and iOS.
/** @ingroup CaptureAction */
#define MA_CAPTURE_ACTION_TAKE_PICTURE 2
/// Sent after a image has been taken.
/// Platform: Android and iOS.
/** @ingroup CaptureEventType */
#define MA_CAPTURE_EVENT_TYPE_IMAGE 0

/// Sent after a video has been taken.
/// Platform: Android and iOS.
/** @ingroup CaptureEventType */
#define MA_CAPTURE_EVENT_TYPE_VIDEO 1

/// Sent if the user cancels taking image/video.
/// Platform: iOS and Android.
/** @ingroup CaptureEventType */
#define MA_CAPTURE_EVENT_TYPE_CANCEL 2
/// Specifies that the device should consider ambient light conditions to automatically
/// determine whether or not to use flash illumination.
/// Platform: iOS.
/** @ingroup CaptureFlashMode */
#define MA_CAPTURE_FLASH_AUTO 0

/// Specifies that flash illumination is always on, no matter what the ambient light conditions are.
/// Platform: iOS.
/** @ingroup CaptureFlashMode */
#define MA_CAPTURE_FLASH_ON 1

/// Specifies that flash illumination is always off, no matter what the ambient light conditions are.
/// Platform: iOS.
/** @ingroup CaptureFlashMode */
#define MA_CAPTURE_FLASH_OFF 2
/**
        * \brief No error occurred.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_OK 0

/**
        * \brief Indicates that in app-purchase is not available because the
* API version is not compatible or the user is not eligible to make
* in-app purchases (for example, the user resides in a country that
* prohibits in-app purchases).
* Platform: Android only.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_UNAVAILABLE -1

/**
        * \brief Indicates that there was an error connecting with the Google Play application.
* Platform: Android.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_CONNECTION_ERROR -2

/**
        * \brief Indicates that the #maPurchaseSupported() call failed because the Google Play
* application is out of date and needs to be updated. In this case, you can provide users
* with an error message that contains a link to the Updating Google Play Help topic.
* Platform: Android.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_OUT_OF_DATE -3

/**
        * \brief Returned by the #maPurchaseSupported()  and #maPurchaseGetField()
        * syscalls if purchase is not allowed on the device.
        * Platform: Android and iOS.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_DISABLED -4

/**
        * \brief Returned by the #maPurchaseGetName(), #maPurchaseVerifyReceipt(),
* #maPurchaseGetField() or #maPurchaseDestroy() syscalls if the productHandle is invalid.
* Platform: Android and iOS.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_INVALID_HANDLE -5

/**
        * \brief Returned by the #maPurchaseGetName() syscall if the the given buffer is
        * too small.
* Platform: Android and iOS.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_BUFFER_TOO_SMALL -6

/**
        * \brief Returned by the #maPurchaseGetField() syscall if the receipt has not been
        * received or if the transaction is invalid.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_RECEIPT_NOT_AVAILABLE -7

/**
        * \brief Returned by the #maPurchaseGetField() syscall if the receipt does not
        * contain the given field.
        */
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_INVALID_FIELD_NAME -8

/**
* \bried returned by the #maPurchaseSetPublicKey() syscall if the encoded public key
* is invalid.
*/
/** @ingroup PurchaseResultCodes */
#define MA_PURCHASE_RES_MALFORMED_PUBLIC_KEY -9
/**
        * \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST ,
        * #MA_PURCHASE_EVENT_VERIFY_RECEIPT event types.
        * Sent by the #maPurchaseRequest() and #maPurchaseVerifyReceipt() syscalls
        * if the given product handle is invalid.
        */
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_INVALID_HANDLE -1

/**
        * \brief Possible error code for any of the requests.
        * Indicates that the connection with the App Store / Google Play has failed.
        */
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_CONNECTION_FAILED -2

/**
        * \brief Possible error code for #MA_PURCHASE_STATE_RECEIPT_ERROR.
        * Indicates that response from App Store/ Google Play for verifying
* a receipt cannot be parsed.
* Platform: iOS.
        */
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_CANNOT_PARSE_RECEIPT -3

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST.
* Sent by the #maPurchaseRequest() syscall if the requested product is not valid
* on the App Store/ Google Play.
* Platform: iOS and Android.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_INVALID_PRODUCT -4

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST.
* Sent by the #maPurchaseRequest() syscall if the client is not allowed to perform
* the attempted action.
* Platform: iOS.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_INVALID_CLIENT -5

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST.
* Sent by the #maPurchaseRequest() syscall if the user cancelled the payment request.
* On Android, when the user pressed the back button on the checkout page instead of
* buying the item.
* Platform: iOS and Android.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_CANCELLED -6

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST.
* Sent by the #maPurchaseRequest() syscall if the user is not allowed to authorize payments.
* Platform: iOS.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_NOT_ALLOWED -7

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST.
* Sent by the #maPurchaseRequest() syscall if the user did not previously call #maPurchaseSetPublicKey().
* Platform: Android.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_PUBLIC_KEY_NOT_SET -8

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST.
* Sent by the #maPurchaseRequest() syscall if an unknown or unexpected server error occurred.
* Platform: iOS and Android.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_UNKNOWN -9

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST.
* Sent by the #maPurchaseRequest() syscall if the quantity is not greater than zero.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_INVALID_QUANTITY -10

/**
* \brief Possible error code for #MA_PURCHASE_EVENT_VERIFY_RECEIPT.
* Sent by the #maPurchaseVerifyReceipt() syscall if the product has not been purchased.
* Platform: iOS and Android.
*/
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_NO_RECEIPT -11

/**
        * \brief Possible error code for #MA_PURCHASE_EVENT_REQUEST event type.
        * Sent by the #maPurchaseRequest() syscall if the given product is already owned.
        */
/** @ingroup PurchaseErrorCodes */
#define MA_PURCHASE_ERROR_PRODUCT_ALREADY_OWNED -12
/**
        * \brief Sent by the #maPurchaseCreate() syscall.
        * Check the event state member object to see if the product is valid or if an error occured.
* Platform: Android and iOS.
        */
/** @ingroup PurchaseEventTypes */
#define MA_PURCHASE_EVENT_PRODUCT_CREATE 0

/**
        * \brief Sent by the #maPurchaseRequest syscall after an operation step has been completed
        * or if the operation has failed. Check event's purchaseData struct variable
        * for more information.
* Platform: Android and iOS.
        */
/** @ingroup PurchaseEventTypes */
#define MA_PURCHASE_EVENT_REQUEST 1

/**
        * \brief Sent by the #maPurchaseVerifyReceipt() syscall.
        * Check the event state member object to see if the receipt is valid or not.
        * Platform: Android and iOS.
*/
/** @ingroup PurchaseEventTypes */
#define MA_PURCHASE_EVENT_VERIFY_RECEIPT 2

/**
* \brief Received when the Billing service triggers a refund for your purchase.
* A new product has been created, and the event's productHandle member contains
* a handle to the purchased product.
        * \brief Platform: Android.
        */
/** @ingroup PurchaseEventTypes */
#define MA_PURCHASE_EVENT_REFUNDED 3

/**
        * \brief Sent by the #maPurchaseRestoreTransactions() syscall.
        * A new product has been restored, or the request has failed. The event's
* productHandle member contains a handle to the purchased product.
        * Platform: iOS and Android.
        */
/** @ingroup PurchaseEventTypes */
#define MA_PURCHASE_EVENT_RESTORE 4
/**
* \brief Sent by the #maPurchaseCreate() syscall.
* Assocciated with #MA_PURCHASE_EVENT_PRODUCT_CREATE.
* Indicates that product was validated by the App Store.
* On Android no product validation is done at this moment.
* Platform: iOS and Android.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_PRODUCT_VALID 0

/**
* \brief Sent by the #maPurchaseCreate() syscall.
* Assocciated with #MA_PURCHASE_EVENT_PRODUCT_CREATE.
* Indicates that the product is not valid in the App Store.
* Platform: iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_PRODUCT_INVALID 1

/**
* \brief Sent by the #maPurchaseCreate(), #maPurchaseRequest() and
* #maPurchaseVerifyReceipt() syscalls.
* Assocciated with #MA_PURCHASE_EVENT_PRODUCT_CREATE,
* #MA_PURCHASE_EVENT_REQUEST and #MA_PURCHASE_EVENT_VERIFY_RECEIPT.
* Indicates that purchase is not supported/disabled on the device.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_DISABLED 2

/**
* \brief Sent by the #maPurchaseCreate() syscall.
* Assocciated with #MA_PURCHASE_EVENT_PRODUCT_CREATE.
* Indicates that the given productHandle already exists.
* Use #maCreatePlaceholder() to generate a new one.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_DUPLICATE_HANDLE 3

/**
        * \brief Sent by the #maPurchaseRequest syscall if the operation failed.
        * Check the errorCode variable from event's purchaseData struct for more info.
        */
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_FAILED 0

/**
        * \brief Sent by the #maPurchaseRequest syscall when the transaction has been received by the
        * Apple App Store/Google Play.
        */
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_IN_PROGRESS 1

/**
        * \brief Sent by the #maPurchaseRequest syscall when the transaction has been successfully
        * processed. Your application should provide the content the user purchased.
        */
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_COMPLETED 2

/**
* \brief Sent by the #maPurchaseVerifyReceipt() syscall.
* Assocciated with #MA_PURCHASE_EVENT_VERIFY_RECEIPT.
* Indicates that the receipt has been validated by the App Store / Google Play.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_RECEIPT_VALID 4

/**
* \brief Sent by the #maPurchaseVerifyReceipt() syscall.
* Assocciated with #MA_PURCHASE_EVENT_VERIFY_RECEIPT.
* Indicates that the receipt has been invalidated by the App Store / Google Play.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_RECEIPT_INVALID 5

/**
* \brief Sent by the #maPurchaseVerifyReceipt() syscall.
* Assocciated with #MA_PURCHASE_EVENT_VERIFY_RECEIPT.
* Indicates that an error has occurred while verifying the receipt.
        * Check the event's errorCode member object for more information.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_RECEIPT_ERROR 6

/**
* \brief Sent by the #maPurchaseRestoreTransactions() syscall.
* Associated with #MA_PURCHASE_EVENT_RESTORE.
* Indicates that an error has occured while restoring transactions.
* The error can be one of the following: #MA_PURCHASE_ERROR_CONNECTION_FAILED,
* #MA_PURCHASE_ERROR_PUBLIC_KEY_NOT_SET.
        * Check the event's errorCode member object for more information.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_RESTORE_ERROR -7

/**
* \brief Sent by the #maPurchaseRestoreTransactions() syscall.
* Associated with #MA_PURCHASE_EVENT_RESTORE.
* Indicates that a product has been restored.
* Platform: Android and iOS.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_PRODUCT_RESTORED -8

/**
* \brief Received after a refund was initiated on the server.
* Associated with #MA_PURCHASE_EVENT_REFUNDED.
* Indicates that a product has been refunded.
* Platform: Android.
*/
/** @ingroup PurchaseStateCodes */
#define MA_PURCHASE_STATE_PRODUCT_REFUNDED -9
/**
        * \brief The number of items purchased.
        * Platform: iOS. On Android just one item can be bought at one time.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_QUANTITY "quantity"

/**
        * \brief The product identifier of the item that was purchased.
        * Example: "com.yourapplication.productname".
        * Platform: iOS and Android.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_PRODUCT_ID "product_id"

/**
        * \brief The transaction identifier of the item that was purchased.
        * Platform: iOS and Android.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_TRANSACTION_ID "transaction_id"

/**
        * \brief The date and time this transaction occurred.
        * The date represents the number of seconds that elapsed since 1970-01-01T00:00:00.
        * Platform: iOS and Android.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_PURCHASE_DATE "purchase_date"

/**
        * \brief For a transaction that restores a previous transaction, this holds the original
        * purchase date(in seconds).
        * Platform: iOS.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_ORIGINAL_TRANSACTION_ID "original_transaction_id"

/**
        * \brief A string that the App Store uses to uniquely identify the application that
        * created the payment transaction. If your server supports multiple
        * applications, you can use this value to differentiate between them.
        * Applications that are executing in the sandbox do not yet have an
        * app-item-id assigned to them,so this key is missing from receipts created
        * by the sandbox.
        * Platform: iOS and Android.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_APP_ITEM_ID "app_item_id"

/**
        * \brief An arbitrary number that uniquely identifies a revision of your application.
        * This key is missing in receipts created by the sandbox.
        * Platform: iOS.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_VERSION_EXTERNAL_IDENTIFIER "version_external_identifier"

/**
        * \brief The bundle identifier for the application.
        * Example: "com.yourcompany.yourapplication".
        * Platform: iOS.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_BID "bid"

/**
        * \brief A version number for the application.
        * Platform: iOS.
        */
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_BVRS "bvrs"

/**
* \brief The cost of the product in the local currency.
* Platform: iOS.
*/
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_PRICE "price"

/**
* \brief The localized product title.
* Platform: iOS.
*/
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_TITLE "title"

/**
* \brief The localized product description.
* Platform: iOS.
*/
/** @ingroup PurchaseReceiptFields */
#define MA_PURCHASE_RECEIPT_DESCRIPTION "description"
/// The device is in portrait mode, based on sensor. Depending on user rotation,
/// #MA_SCREEN_ORIENTATION_PORTRAIT_UP or #MA_SCREEN_ORIENTATION_PORTRAIT_UPSIDE_DOWN will be used.
/// Value equals: #MA_SCREEN_ORIENTATION_PORTRAIT_UP | #MA_SCREEN_ORIENTATION_PORTRAIT_UPSIDE_DOWN.
/** @ingroup OrientationConstants */
#define MA_SCREEN_ORIENTATION_PORTRAIT 0x3

/// The device is in portrait mode, with the device held upright and the home button on
/// the bottom.
/** @ingroup OrientationConstants */
#define MA_SCREEN_ORIENTATION_PORTRAIT_UP 0x1

/// The device is in portrait mode but upside down, with the device held upright and the
/// home button at the top.
/** @ingroup OrientationConstants */
#define MA_SCREEN_ORIENTATION_PORTRAIT_UPSIDE_DOWN 0x2

/// The device is in landscape mode, with the device held upright and the home button on
/// the left side.
/** @ingroup OrientationConstants */
#define MA_SCREEN_ORIENTATION_LANDSCAPE_LEFT 0x4

/// The device is in landscape mode, with the device held upright and the home button on
/// the right side.
/** @ingroup OrientationConstants */
#define MA_SCREEN_ORIENTATION_LANDSCAPE_RIGHT 0x8

/// The device is in landscape mode, based on sensor. Depending on user rotation,
/// #MA_SCREEN_ORIENTATION_LANDSCAPE_LEFT or #MA_SCREEN_ORIENTATION_LANDSCAPE_RIGHT will be used.
/** @ingroup OrientationConstants */
#define MA_SCREEN_ORIENTATION_LANDSCAPE 0xC

/// Screen orientation is based on device sensor.
/// Value equals: #MA_SCREEN_ORIENTATION_PORTRAIT| #MA_SCREEN_ORIENTATION_LANDSCAPE.
/** @ingroup OrientationConstants */
#define MA_SCREEN_ORIENTATION_DYNAMIC 0xF
/**
 * Landscape screen orientation.
 * @deprecated Use #maScreenSetSupportedOrientations with #MA_SCREEN_ORIENTATION_LANDSCAPE instead.
 */
/** @ingroup OrientationConstants */
#define SCREEN_ORIENTATION_LANDSCAPE 1

/**
 * Portrait screen orientation.
 * @deprecated Use #maScreenSetSupportedOrientations with #MA_SCREEN_ORIENTATION_PORTRAIT instead.
 */
/** @ingroup OrientationConstants */
#define SCREEN_ORIENTATION_PORTRAIT 2

/**
 * Screen orientation is based on device sensor.
 * @deprecated Use #maScreenSetSupportedOrientations with #MA_SCREEN_ORIENTATION_PORTRAIT instead.
 */
/** @ingroup OrientationConstants */
#define SCREEN_ORIENTATION_DYNAMIC 3
///
/** @ingroup OrientationResultCodes */
#define MA_SCREEN_ORIENTATION_RES_OK 0

///
/** @ingroup OrientationResultCodes */
#define MA_SCREEN_ORIENTATION_RES_NOT_SUPPORTED -1

///
/** @ingroup OrientationResultCodes */
#define MA_SCREEN_ORIENTATION_RES_INVALID_VALUE -2
#define IOCTL_UNAVAILABLE -1
/**
 * \brief A structure representing a two-dimensional point, with coordinates 'x' and 'y'.
 */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAPoint2d {
	int x;
	int y;
} MAPoint2d;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
 * \brief A structure representing a rectangle.
 *
 * The x and y coordinate of the top-left corner are defined by 'left' and 'top'.
 * The dimensions of the rectangle are defined by 'width' and 'height'.
 */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MARect {
	int left;
	int top;
	int width;
	int height;
} MARect;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief Parameters for the maCopyData() function.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MACopyData {
	MAHandle dst;
	int dstOffset;
	MAHandle src;
	int srcOffset;
	int size;
} MACopyData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An address for the protocols TCP or UDP over IPv4.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAConnAddrInet4 {
	int addr;
	int port;
} MAConnAddrInet4;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An address for the protocols TCP or UDP over IPv6.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAConnAddrInet6 {
	int port;
	byte addr[16];
} MAConnAddrInet6;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A Bluetooth device address.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MABtAddr {
	byte a[BTADDR_LEN];
} MABtAddr;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An address for the Bluetooth Serial Port protocol.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAConnAddrBt {
	int port;
	MABtAddr addr;
} MAConnAddrBt;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A connection address.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAConnAddr {
	/// One of the CONN_FAMILY constants
	int family;
	union {

		MAConnAddrInet4 inet4;

		MAConnAddrBt bt;

		MAConnAddrInet6 inet6;
	};
} MAConnAddr;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief Data for a connection event, including an indicator or success or failure.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAConnEventData {
	/// The handle to the connection associated with the event.
	MAHandle handle;

	/// One of the \link #CONNOP_READ CONNOP \endlink constants.
	int opType;

	/// A success value \> 0 or a \link #CONNERR_GENERIC CONNERR \endlink code.
	int result;
} MAConnEventData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A structure containing the sensor type and the data sent to the event.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MASensor {
	int type;
	float values[3];
} MASensor;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An event containing the result of an NFC asynchronous operation
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MANFCEventData {
	/// The handle this event pertains to.
	MAHandle handle;

	/// The result of the asynchronous operation, usually a length if >= 0,
	/// or an error code of < 0.
	int result;

	/// The destination of any read or write operation. Could be a memory
	/// address, a block number, or some other value depending on the operation.
	int dstId;
} MANFCEventData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An event send by a banner widget.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAAdsEventData {
	/// Banner's handle that send the event.
	MAHandle bannerHandle;

	/// One of the \link #MA_ADS_EVENT_FAILED MA_ADS_EVENT \endlink constants.
	int bannerEventType;

	/// If bannerEventType is #\link #MA_ADS_EVENT_FAILED MA_ADS_EVENT_FAILED \endlink
	/// this variable will contain the error code.
	/// One of the \link #MA_ADS_ERROR_INTERNAL MA_ADS_ERROR \endlink constants.
	int bannerErrorCode;
} MAAdsEventData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An event send by the Native Image Picker(Capture API).
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MACaptureEventData {
	/// One of the \link #MA_CAPTURE_EVENT_TYPE_IMAGE MA_CAPTURE_EVENT_TYPE \endlink constants.
	int type;

	/// Handle to a video/image data object.
	/// This value is set only if the event type is MA_CAPTURE_EVENT_TYPE_IMAGE or MA_CAPTURE_EVENT_TYPE_VIDEO.
	MAHandle handle;
} MACaptureEventData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An puchase event struct.
* A MoSync event will contain an struct object of this type only if event type
* is #EVENT_TYPE_PURCHASE.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAPurchaseEventData {
	/**
	* \brief Type of the purchase event.
	* One of the \link MA_PURCHASE_EVENT_REQUEST MA_PURCHASE_EVENT \endlink constants.
	*/
	int type;

	/**
	* \brief State of the purchase.
	* One of the \link MA_PURCHASE_STATE_FAILED MA_PURCHASE_STATE \endlink constants.
	*/
	int state;

	/**
	* \brief Handle to the product that sent the event.
	*/
	MAHandle productHandle;

	/**
	* \brief Reason why the puchase failed.
	* Valid only if the state is #MA_PURCHASE_STATE_FAILED, #MA_PURCHASE_STATE_RECEIPT_INVALID,
	* #MA_PURCHASE_STATE_RECEIPT_ERROR or #MA_PURCHASE_STATE_RESTORE_ERROR.
	* One of the \link MA_PURCHASE_ERROR_INVALID_HANDLE MA_PURCHASE_ERROR \endlink constants.
	*/
	int errorCode;
} MAPurchaseEventData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An event; a message indicating that something has happened, e.g. that a key has been pressed.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAEvent {
	/**
	* One of the \link #EVENT_TYPE_CLOSE EVENT_TYPE \endlink constants.
	*/
	int type;
	union {

		struct {
			/**
			* In KEY events, this will be one of the \link #MAK_UNKNOWN MAK \endlink constants.
			*/
			int key;

			/**
			* In KEY events, this will be the native keycode.
			*/
			int nativeKey;
		};

		/**
		* In CHAR events, this is the Unicode character that was received.
		*/
		uint character;

		struct {
			/**
			* In POINTER events, this will be the location of the pointer.
			*/
			MAPoint2d point;

			/**
			* In POINTER events, this will be the finger triggering the event.
			*/
			int touchId;
		};

		/**
		* In \link #EVENT_TYPE_BT BT \endlink events, this will be a value \>= 0 or
		* one of the \link #CONNERR_GENERIC CONNERR \endlink constants.
		*/
		int state;

		/**
		* Valid only in CONN events.
		*/
		MAConnEventData conn;

		struct {
			/**
			* One of the \link #MA_TB_RES_OK MA_TB_RES \endlink codes.
			*/
			int textboxResult;

			/**
			* The length, in characters, of the finished text.
			* Does not include the terminating zero.
			*/
			int textboxLength;
		};

		struct {
			/**
			 * #EVENT_TYPE_IMAGE_PICKER events, this will be 0 if canceled or 1 if Ok was pressed.
			 */
			int imagePickerState;

			/**
			* #EVENT_TYPE_IMAGE_PICKER event, contains the new handle to the selected image if the image picker
			* event return type was set to @link #MA_IMAGE_PICKER_ITEM_EVENT_RETURN_TYPE_IMAGE_HANDLE @endlink
			* (default value) or the handle to the binary image data if the return type was set to
			* @link #MA_IMAGE_PICKER_ITEM_EVENT_RETURN_TYPE_IMAGE_DATA @endlink.
			* Note: Android VM has some limitations when it comes to creating high resolution images. Therefore, if
			* the user needs to handle the image itself locally and maCreateImageFromData(dataHandle) returns a
			* RES_OUT_OF_MEMORY, use #MA_IMAGE_PICKER_ITEM_EVENT_RETURN_TYPE_IMAGE_HANDLE instead.
			*/
			MAHandle imagePickerItem;

			/**
			* The encoding used for the image. One of the values
			* @link #MA_IMAGE_PICKER_ITEM_ENCODING_PNG MA_IMAGE_PICKER_ITEM_ENCODING_* @endlink
			*/
			int imagePickerEncodingType;
		};

		struct {
			/**
			 * Used in #EVENT_TYPE_CAMERA_SNAPSHOT events.
			 * Holds the place holder for the data object representing the camera snapshot.
			 */
			MAHandle snapshotImageDataHandle;

			/**
			 * Used in #EVENT_TYPE_CAMERA_SNAPSHOT events.
			 * Holds the snapshot size.
			 */
			int snapshotSize;

			/**
			 * Used in #EVENT_TYPE_CAMERA_SNAPSHOT events.
			 * Holds the snapshot data representation.
			 * Possible values are found \link #MA_IMAGE_REPRESENTATION_UNKNOWN here \endlink.
			 */
			int snapshotImageDataRepresentation;

			/**
			 * Used in #EVENT_TYPE_CAMERA_SNAPSHOT events.
			 * Holds the return code of the camera snapshot operation.
			 * It #MA_CAMERA_RES_OK on success, or #MA_CAMERA_RES_FAILED on error
			 */
			int snapshotReturnCode;
		};

		struct {
			/**
			 * Used in #EVENT_TYPE_MEDIA_EXPORT_FINISHED.
			 *
			 * Reprezents the media type.
			 * It can have a value from this set #MA_MEDIA_TYPE_UNKNOWN
			 */
			int mediaType;

			/**
			 * Used in #EVENT_TYPE_MEDIA_EXPORT_FINISHED.
			 *
			 * Reprezents the media handle.
			 */
			MAHandle mediaHandle;

			/**
			 * Used in #EVENT_TYPE_MEDIA_EXPORT_FINISHED.
			 *
			 * The result code of the operation. The possible values belong
			 * to this set #MA_MEDIA_RES_OK
			 */
			int operationResultCode;
		};

		/**
		* #EVENT_TYPE_OPTIONS_BOX_BUTTON_CLICKED event, contains the index of the selected option.
		*/
		int optionsBoxButtonIndex;

		/**
		* #EVENT_TYPE_ALERT event. The index of the selected button.
		* If button1 is pressed, the value is 1.
		* If button2 is pressed, the value is 2.
		* If button3 is pressed, the value is 3.
		*/
		int alertButtonIndex;

		/**
		* In #EVENT_TYPE_SMS events, this will be one of the
		* @link #MA_SMS_RESULT_SENT MA_SMS_RESULT_* @endlink constants.
		*/
		int status;

		/**
		* Valid in \link #EVENT_TYPE_SENSOR SENSOR \endlink events.
		*/
		MASensor sensor;

		/**
		* NFC event data
		*/
		MANFCEventData nfc;

		/**
		* Ads event data.
		*/
		MAAdsEventData adsData;

		/**
		* Local notification's handle that send the event.
		* Valid only if the event type is \link #EVENT_TYPE_LOCAL_NOTIFICATION LOCAL_NOTIFICATION \endlink.
		*/
		MAHandle localNotificationHandle;

		/**
		* Push notification's handle that send the event.
		* Valid only if the event type is \link #EVENT_TYPE_PUSH_NOTIFICATION PUSH_NOTIFICATION \endlink.
		*/
		MAHandle pushNotificationHandle;

		/**
		* Store the result for a capture action.
		* Valid only if the event type is \link #EVENT_TYPE_CAPTURE CAPTURE \endlink.
		*/
		MACaptureEventData captureData;

		/**
		* Used by custom events. See invididual event descriptions.
		*/
		void* data;

		/**
		* Contains the prepared audio instance.
		* Valid only if the event type is \link #EVENT_TYPE_AUDIO_PREPARED AUDIO_PREPARED \endlink
		* or \link #EVENT_TYPE_AUDIO_COMPLETED AUDIO_COMPLETED \endlink.
		*/
		MAAudioInstance audioInstance;

		/**
		* Contains purchase related data.
		* Valid only if the event type is \link #EVENT_TYPE_PURCHASE PURCHASE \endlink.
		*/
		MAPurchaseEventData purchaseData;

		/**
		* Contains the new orientation when a #EVENT_TYPE_ORIENTATION_DID_CHANGE event is sent.
		*/
		int orientation;
	};
} MAEvent;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A MoSync Panic or other unrecoverable error.
*
* In MoSync Debug builds, when such an error occurs, the runtime writes
* an instance of this structure to a Store named "panic.report".
*
* The length of that instance may be greater than sizeof(MAPanicReport),
* because of the variable-length string that may appear at its end.
* The member \a string can, then, be longer than the one byte that is declared.
*
* To properly read an instance of this struct from a store, you should allocate a
* chunk of memory whose size is equal to the size of the store, then read the entire store
* into that chunk of memory. Then you should make a pointer of type MAPanicReport and point it
* to the chunk. Then you can read normally, using that pointer.
*
* \see maOpenStore()
* \see maPanic()
* \see malloc()
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAPanicReport {
	/// The type of MoSync runtime that wrote the report. A \link #RUNTIME_MORE RUNTIME \endlink constant.
	int runtimeId;

	/**
	* The type report. Specifies whether the members \a code and \a string are valid.
	* A \link #REPORT_PANIC REPORT \endlink constant.
	*/
	int reportType;

	/// The time the report was generated. The format is unix time. \see maTime()
	int time;

	/**
	* The value of the MoSync instruction pointer at the time the report was generated.
	* \< 0 if the MoSync core was inaccessible.
	*/
	int ip;

	int code;

	char string[1];
} MAPanicReport;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief Information about a Bluetooth device.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MABtDevice {
	///in (pointer), out (buffer)
	char* name;

	///in, the length of the buffer pointed to by a name.
	int nameBufSize;

	///out, the length of the name, excluding the terminating zero.
	int actualNameLength;

	///out
	MABtAddr address;
} MABtDevice;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A Universally Unique Identifier.
*
* Common Bluetooth UUID values can be found in MAUtil/mauuid.h.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAUUID {
	int i[4];
} MAUUID;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief Information about an MABtService object.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MABtServiceSize {
	/**
	* The buffer size neccesary to contain the full name,
	* or <0 if the service has no name.
	*/
	int nameBufSize;

	/**
	* The number of UUIDs associated with the service.
	*/
	int nUuids;
} MABtServiceSize;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief Information about a Bluetooth service.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MABtService {
	/**
	* The port number for the service.
	* \see maConnect()
	*/
	int port;

	/**
	* Pointer to a buffer that receives the service's human-readable name.
	*/
	char* name;

	/**
	* The size of the buffer being pointed to by \a name.
	*/
	int nameBufSize;

	/**
	* Pointer to a buffer that receives the UUIDs associated with the service.
	* The buffer must be large enough to contain the number of UUIDs reported
	* by the last call to maBtGetNextServiceSize().
	*/
	MAUUID* uuids;
} MABtService;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A geographical location specified by latitude and longitude, horizontal and vertical accuracy, and altitude.
*
* Only if \a state equals #MA_LOC_QUALIFIED do the other members contain valid data.
*
* Coordinates are in the WGS84 datum.
*
* The horizontal accuracy is the RMS (root mean square) of east accuracy
* (latitudinal error in meters, 1-sigma standard deviation), north accuracy
* (longitudinal error in meters, 1-sigma).
*
* The vertical accuracy is in meters in vertical direction
* (orthogonal to ellipsoid surface, 1-sigma standard deviation).
*
* Accuracy values may be NaN, if accuracy is unknown.
*
* \see maLocationStart()
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MALocation {
	/**
	* The validity of the coordinates.
	* One of the \link #MA_LOC_NONE MA_LOC \endlink constants.
	*/
	int state;

	double lat;

	double lon;

	double horzAcc;

	double vertAcc;

	float alt;
} MALocation;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief A structure containing information about the native framebuffer, including color format and resolution.
*
* The 'sizeInBytes' field is the amount of bytes that should be used to allocate the offscreen framebuffer (a backbuffer).
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAFrameBufferInfo {
	int sizeInBytes;
	int bytesPerPixel;
	int bitsPerPixel;
	int redMask;
	int redShift;
	int redBits;
	int greenMask;
	int greenShift;
	int greenBits;
	int blueMask;
	int blueShift;
	int blueBits;
	int width;
	int height;
	int pitch;
	int supportsGfxSyscalls;
} MAFrameBufferInfo;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief The camera format, in pixels.
*/
/** @ingroup CameraFunctions */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MA_CAMERA_FORMAT {
	int width;
	int height;
} MA_CAMERA_FORMAT;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/** @ingroup DBAPI */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MADBBlob {
	MAAddress data;
	int size;
} MADBBlob;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/** @ingroup DBAPI */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MADBText {
	MAString addr;
	/// Length in bytes of the string pointed to by \a addr.
	/// May be \< 0, in which case the string is null-terminated.
	int length;
} MADBText;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/// Input value for maDBExecSQLParams().
/** @ingroup DBAPI */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MADBValue {
	union {
		int i;
		double d;
		MADBBlob blob;
		MAHandle dataHandle;
		MADBText text;
		longlong i64;
	};
		/// One of the MA_DB_TYPE_ constants.
		int type;
} MADBValue;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* \brief An push notification event.
*/
/** @ingroup NotificationPushStruct */
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAPushNotificationData {
	/// A bit mask specifying the types of notifications.
	/// The bit mask is created using \link #MA_NOTIFICATION_PUSH_TYPE_BADGE
	/// MA_NOTIFICATION_PUSH_TYPE \endlink type values.
	/// Specific to iOS. On Android it will be #MA_NOTIFICATION_PUSH_TYPE_ALERT.
	int type;

	/// The  buffer that will contain the message displayed in the notification alert,
	/// or the notification content on Android.
	/// This buffer will be filled only if the type is MA_NOTIFICATION_PUSH_TYPE_ALERT.
	/// Platform: iOS and Android.
	MAString alertMessage;

	/// The size of the buffer that will contain the notification alert message.
	int alertMessageSize;

	/// The address to a buffer that will contain the name of the file containing
	/// the sound to play when an alert is displayed.
	/// This buffer will be filled only if the type is MA_NOTIFICATION_PUSH_TYPE_SOUND.
	/// Platform: iOS only.
	MAString soundFileName;

	/// The size of the buffer that will contain the sound filename.
	int soundFileNameSize;

	/// Will contain the number to display as the application’s icon badge.
	/// This value will be set only if the type is MA_NOTIFICATION_PUSH_TYPE_BADGE.
	/// Platform: iOS only.
	int badgeIcon;
} MAPushNotificationData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* Compares the runtime's interface version with yours,
* using a hash of the interface's contents.
*
* If the versions do not match, a MoSync Panic is generated.
*
* This function returns the runtime's hash. However, if there is
* a version mismatch, syscall and IOCTL numbers may differ between the runtime and
* your version of the header files, causing a different function than this to be called.
*
* The hash appears as a 32-bit random number, so it is very unlikely that the return
* value from any other function is the same as the runtime's hash.
*
* Therefore, you should always compare the return value from this function to your hash
* and exit your program, preferably using maPanic(), if they don't match.
*
* \param hash Your hash. Pass #MAIDL_HASH.
* \returns The runtime's hash.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maCheckInterfaceVersion(int hash);

/**
* Shuts down the system. This function does not return.
* \param result Passed to the operating system, where applicable. Ignored otherwise.
*/
void ATTRIBUTE(noreturn, maExit(int result));

/**
* Displays a message to the user, then shuts down the system.
* This function does not return.
* \param result Passed to the operating system, where applicable. Ignored otherwise.
* \param message The message should be short, not more than 40 characters,
* to ensure its visibility on all screen sizes.
* \see MAPanicReport
*/
void ATTRIBUTE(noreturn, maPanic(int result, const char* message));

/**
* Sets \a size bytes, starting at \a dst, to the specified value, interpreted as an unsigned char.
* \returns \a dst.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void* memset(void* dst, int val, ulong size);

/**
* Copies the values of \a size bytes from the location pointed by \a src directly to the memory
* block pointed by \a dst.
*
* The underlying type of the objects pointed by both the source and destination pointers are
* irrelevant for this function; The result is a binary copy of the data.
*
* The function does not check for any terminating null character in source - it always copies
* exactly \a size bytes.
*
* To avoid overflows, the size of the arrays pointed by both the destination and source
* parameters, shall be at least \a size bytes, and should not overlap (for overlapping memory
* blocks, memmove() is a safe approach).
* \returns \a dst.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void* memcpy(void* dst, const void* src, ulong size);

/**
* Compares the C string \a str1 to the C string \a str2.
*
* This function starts comparing the first character of each string.
* If they are equal to each other, it continues with the following pairs until the
* characters differ or until a terminanting null-character is reached.
*
* \returns An integral value indicating the relationship between the strings:
* A zero value indicates that both strings are equal.
* A value greater than zero indicates that the first character that does not match
* has a greater value in \a str1 than in \a str2. A value less than zero indicates the opposite.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int strcmp(const char* str1, const char* str2);

/**
* Copies the C string pointed by \a src into the array pointed by \a dst,
* including the terminating null character.
*
* To avoid overflows, the size of the array pointed by \a dst shall be long
* enough to contain the same C string as \a src (including the terminating null
* character), and should not overlap in memory with \a src.
* \returns \a dst.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
#endif

/**
* Returns \a a + \a b.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double __adddf3(double a, double b);

/**
* Returns \a a - \a b.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double __subdf3(double a, double b);

/**
* Returns \a a * \a b.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double __muldf3(double a, double b);

/**
* Returns \a a / \a b.
* If \a b == 0, a <a href="../panics.html">MoSync Panic</a> is thrown.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double __divdf3(double a, double b);

/**
* Returns -\a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double __negdf2(double a);

/**
* Returns the integer part of \a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int __fixdfsi(double a);

/**
* Returns the unsigned integer part of \a a. Negative values become zero.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
uint __fixunsdfsi(double a);

/**
* Returns the double representation of \a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double __floatsidf(int a);

/**
* Returns the double representation of \a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double __extendsfdf2(float a);

/**
* Returns \>0 if \a a \> \a b, 0 if \a a == \a b and \<0 if \a a \< \a b.
* If either argument is Not a Number, the result is undefined.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int dcmp(double a, double b);

/**
* Returns \a a + \a b.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
float __addsf3(float a, float b);

/**
* Returns \a a - \a b.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
float __subsf3(float a, float b);

/**
* Returns \a a * \a b.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
float __mulsf3(float a, float b);

/**
* Returns \a a / \a b.
* If \a b == 0, a <a href="../panics.html">MoSync Panic</a> is thrown.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
float __divsf3(float a, float b);

/**
* Returns -\a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
float __negsf2(float a);

/**
* Returns the integer part of \a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int __fixsfsi(float a);

/**
* Returns the unsigned integer part of \a a. Negative values become zero.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
uint __fixunssfsi(float a);

/**
* Returns the float representation of \a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
float __floatsisf(int a);

/**
* Returns the float representation of \a a.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
float __truncdfsf2(double a);

/**
* Returns \>0 if \a a \> \a b, 0 if \a a == \a b and \<0 if \a a \< \a b.
* If either argument is Not a Number, the result is undefined.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int fcmp(float a, float b);

/**
* Returns the sine of \a x.
* \param x An angle in radians.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double sin(double x);

/**
* Returns the cosine of \a x.
* \param x An angle in radians.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double cos(double x);

/**
* Returns the tangent of \a x.
* \param x An angle in radians.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double tan(double x);

/**
* Returns the square root of \a x.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
double sqrt(double x);

/**
* Sets the color used by drawing functions. Returns previous color. Initial color is 0 (black).
* \param rgb A color in RGB8 format (0xRRGGBB). The top byte is ignored.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maSetColor(int rgb);

/**
* Sets the clipping rectangle for the current draw target.
* The screen and every drawable image each maintains a clipping rectangle.
* Drawing operations have no effect outside the clipping rectangle.
* The default clipping rectangle covers the entire draw target, so that
* clipping occurs at the draw target's edges.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maSetClipRect(int left, int top, int width, int height);

/**
* Returns the clipping rectangle for the current draw target.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maGetClipRect(MARect* out);

/**
* Draws a single pixel using the current color.
* \see maSetColor()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maPlot(int posX, int posY);

/**
* Draws a line using the current color.
* \see maSetColor()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maLine(int startX, int startY, int endX, int endY);

/**
* Draws a filled rectangle using the current color.
* Width and height must be greater than zero.
* \see maSetColor()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maFillRect(int left, int top, int width, int height);

/**
* Draws a filled triangle strip using the current color.
* \param points A pointer to an array of \a count MAPoint2d:s representing the
* vertices of the strip.
* \param count The count of vertices in the strip. Must be at least 3.
* \see maSetColor()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maFillTriangleStrip(const MAPoint2d* points, int count);

/**
* Draws a filled triangle fan using the current color.
* \param points A pointer to an array of \a count MAPoint2d:s representing the
* vertices of the fan.
* \param count The count of vertices in the fan. Must be at least 3.
* \see maSetColor()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maFillTriangleFan(const MAPoint2d* points, int count);

/**
* Returns the size in pixels of Latin-1 text as it would appear on-screen.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAExtent maGetTextSize(const char* str);

/**
* Returns the size in pixels of Unicode text as it would appear on-screen.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAExtent maGetTextSizeW(const wchar* str);

/**
* Draws Latin-1 text using the current color.
* The coordinates are the top-left corner of the text's bounding box.
* \see maSetColor()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maDrawText(int left, int top, const char* str);

/**
* Draws Unicode text using the current color.
* The coordinates are the top-left corner of the text's bounding box.
* \see maSetColor()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maDrawTextW(int left, int top, const wchar* str);

/**
* Copies the back buffer to the physical screen.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maUpdateScreen(void);

/**
* Normally, a phone's backlight turns itself off after
* a few seconds of the user not pressing any keys.
* To avoid this behaviour, call this function periodically.
* As the timeout period is different for every device, and sometimes even user-configurable,
* it's recommended that you call this function at least once every 500 milliseconds
* to ensure that the light stays on at all times.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maResetBacklight(void);

/**
* Returns the screen size.
* Returns the screen size.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAExtent maGetScrSize(void);

/**
* Draws an image.
* It it placed on the draw target with the top left corner according to the parameters.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maDrawImage(MAHandle image, int left, int top);

/**
* Draws an image.
* The source is an array of ints that represent pixels in ARGB format.
* \param dstPoint The top-left point on the draw target.
* \param src The address to the source image.
* \param srcRect The portion of the source image to be drawn.
* \param scanlength The width, in pixels, of the image represented by the source array.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maDrawRGB(const MAPoint2d* dstPoint, const void* src, const MARect* srcRect, int scanlength);

/**
* Draws a portion of an image using a transformation.
* \param image The source image.
* \param srcRect The portion of the source image to be drawn.
* Must not exceed the bounds of the source image.
* \param dstPoint The top-left point on the draw target.
* \param transformMode One of the \link #TRANS_NONE TRANS \endlink constants.
* \see maDrawImage
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maDrawImageRegion(MAHandle image, const MARect* srcRect, const MAPoint2d* dstPoint, int transformMode);

/**
* Returns the size of an image.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAExtent maGetImageSize(MAHandle image);

/**
* Copies an image into an array of ints that represent pixels in little-endian ARGB format.
* The destination rectangle is defined as { 0,0, \a srcRect.width, \a srcRect.height }.
* Parts of the destination array that are outside the destination rectangle are not modified.
* If \a srcRect is outside the bounds of the source image,
* or if \a srcRect.width is greater than \a scanlength, a MoSync Panic is thrown.
* \param image The handle to the source image.
* \param dst The address of the destination array.
* \param scanlength The width of the image, in pixels, represented by the destination array.
* \param srcRect The portion of the source image to be copied.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maGetImageData(MAHandle image, void* dst, const MARect* srcRect, int scanlength);

/**
* Sets the current draw target.
* The handle must be a drawable image or #HANDLE_SCREEN, which represents the back buffer.
* The initial draw target is the back buffer.
* If an image is set as draw target, its object handle goes into flux, which prevents
* its destruction or use as a source in maDrawImage. When a different draw target is set,
* the image's handle is restored. Returns the the previously set draw target.
* \see maCreateDrawableImage()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAHandle maSetDrawTarget(MAHandle image);

/**
 * Finds the label resource with the specified \a name and returns its index.
 * If it is not found, -1 is returned.
 */
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maFindLabel(const char* name);

/**
* Creates an image object using encoded data from a data object.
* All platforms support the PNG format. Some platforms may also support JPEG and/or GIF.
* \param placeholder The placeholder for the image object that is to be created.
* \param data The data object that holds the encoded data.
* \param offset The offset in the data object where the encoded data begins.
* \param size The size in bytes of the encoded data.
* \returns #RES_OK if succeded and #RES_OUT_OF_MEMORY or #RES_BAD_INPUT if failed.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maCreateImageFromData(MAHandle placeholder, MAHandle data, int offset, int size);

/**
* Creates an image object using raw ARGB data.
* \param placeholder The placeholder for the image object that is to be created.
* \param src Address of the raw data. 4 bytes per pixel, format 0xAARRGGBB.
* \param size The size in pixels of the image, constructed using the EXTENT() macro.
* \param alpha Non-zero if the resulting image should have an alpha channel, zero otherwise.
* \returns #RES_OK if succeded and #RES_OUT_OF_MEMORY if failed.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maCreateImageRaw(MAHandle placeholder, const void* src, MAExtent size, int alpha);

/**
* Creates a drawable image of the specified size. A drawable image has no alpha channel,
* which is to say, no transparency.
* Its initial contents are undefined, so you should draw onto the entire surface to
* be sure what will happen when you draw this image onto something else.
* \param placeholder The resource handle of the new image.
* \param width Width, in pixels, of the new image. Must be \> 0.
* \param height Height, in pixels, of the new image. Must be \> 0.
* \see maSetDrawTarget()
* \returns #RES_OK if succeded and #RES_OUT_OF_MEMORY if failed.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maCreateDrawableImage(MAHandle placeholder, int width, int height);

/**
* Creates a data object of the specified \a size, in bytes. Its initial contents are undefined.
* \returns #RES_OK if succeded and #RES_OUT_OF_MEMORY if failed.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maCreateData(MAHandle placeholder, int size);

/**
*	Creates a new placeholder and returns the handle to it.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAHandle maCreatePlaceholder(void);

/**
* Releases a handle returned by maCreatePlaceholder().
* If the handle refers to an object, such as an image or a data object,
* that object is destroyed, as if maDestroyObject() had been called.
*
* The released handle may be reused by the system
* and returned by future calls to maCreatePlaceholder(),
* or by other system functions that allocate resources dynamically.
*
* This function is preferred to maDestroyObject(), unless you need
* to reuse the handle.
*
* Attempting to destroy a handle that has already been released,
* or was not returned by maCreatePlaceholder(), will cause a MoSync Panic.
*
* @param handle The handle to be released.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maDestroyPlaceholder(MAHandle handle);

/**
* Destroys an object of any type. The handle becomes a placeholder.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maDestroyObject(MAHandle handle);

/**
* Returns the size, in bytes, of a data object.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maGetDataSize(MAHandle data);

/**
* Reads \a size bytes from a data object, starting at \a offset,
* into memory pointed to by \a dst.
* \warning Do not attempt to read zero bytes or out of bounds;
* it is not supported and will result in a MoSync Panic.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maReadData(MAHandle data, void* dst, int offset, int size);

/**
* Writes \a size bytes to a data object, starting at \a offset,
* from memory pointed to by \a src.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maWriteData(MAHandle data, const void* src, int offset, int size);

/**
* Copies \a size bytes from data object \a src to \a dst, at the specified offsets.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maCopyData(const MACopyData* params);

/**
* Opens a permanent data store, optionally creates one if it doesn't exist already.
*
* Returns a Store MAHandle on success.
* Returns #STERR_NONEXISTENT if !(flags & #MAS_CREATE_IF_NECESSARY) and the store does not exist.
* Returns another \link #STERR_GENERIC STERR \endlink code if the store could not be opened
* for another reason.
*
* \param name The name of the store. A store name must have from 1 to 32 characters,
* and must not contain any of the following characters: "/\\:;?*'
* \param flags A combination of \link #MAS_CREATE_IF_NECESSARY MAS \endlink flags, or zero.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAHandle maOpenStore(const char* name, int flags);

/**
* Writes the contents of a data object to a store. Destroys any data previously in the store.
* Returns \> 0 on success, #STERR_FULL if the storage system is full,
* or another \link #STERR_GENERIC STERR \endlink code if the write failed for another reason.
* \param store The store to write to.
* \param data The data object to read from.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maWriteStore(MAHandle store, MAHandle data);

/**
* Creates a data object and copies the contents of a store to it.
* Use maGetDataSize to get the size of the data.
* \param store The store to read from.
* \param placeholder The placeholder handle where a data object will be created.
* \returns RES_OK if succeded and RES_OUT_OF_MEMORY if failed.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maReadStore(MAHandle store, MAHandle placeholder);

/**
* Closes a store. Also deletes that store if \a _delete is non-zero.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maCloseStore(MAHandle store, int _delete);

/**
* Asynchronously opens a connection using the specified URL.
* A URL takes the following form:
* <tt>\<protocol\>://\<address\>[:\<port\>]\<parameters\></tt>\n
* The following protocols are supported:
*
* <tt>socket</tt>, which is TCP. It has no parameters.
*
* <tt>datagram</tt>, which is UDP. It has no parameters.
* Datagrams may arrive corrupted, out-of-order, duplicated, or not at all.
*
* <tt>ssl</tt>, which is an encrypted TCP connection. It has no parameters.
*
* <tt>http</tt>, which is HTTP/1.0 GET. When using HTTP, you need not specify the port;
* it defaults to port 80.
*
* Its parameters is the document path (for example, "/index.html").
* You must specify a path, or this function will fail with #CONNERR_URL.
* The minimal path ("/") is acceptable.
*
* Writing to a http connection is not allowed.
*
* <tt>https</tt>, which is an encrypted HTTP GET. It has the same parameters as <tt>http</tt>.
*
* <tt>btspp</tt>, which is Bluetooth Serial Port. It has no parameters.
*\n
*\n
* For the <tt>socket</tt> and <tt>http</tt> protocols, \a \<address\> can be either a decimal,
* dot-delimited (.) IPv4 address or a standard Domain Name,
* while \a \<port\> is a decimal number from 1 to 65535.
*
* In the <tt>socket</tt> protocol, certain ports are protected on certain platforms and
* cannot be used, most notably port 80 on Java ME. In this case, use http instead.
*
* On a few devices, using ports numbered below 1024 may cause system crashes.
* Therefore, it is advisable to use ports above 1024 if you can choose.
*
* On some J2ME devices, connections to port 443 (except from https) is not
* allowed and might cause a system exception.
*
* For the <tt>btspp</tt> protocol, \a \<address\> is 12 hexadecimal digits and
* \<port\> is a decimal number from 1 to 30.
*
* Example TCP url: <tt>socket://www.example.com:23</tt>
*
* Example UDP url: <tt>datagram://www.example.com:53</tt>
*
* Example SSL url: <tt>ssl://www.example.com:22</tt>
*
* Example HTTP url: <tt>http://www.example.com/directory/document.html</tt>
*
* Example HTTPS url: <tt>https://www.google.com</tt>
*
* Example Bluetooth url: <tt>btspp://001dbe15e455:9</tt>
*
* You can also use MAUtil::BluetoothConnection to connect via Bluetooth service uuid.
*
* To find useful Bluetooth addresses, use the Bluetooth discovery API.
* See maBtStartDeviceDiscovery().
*
*
* The result of the operation will be delivered in a CONN event, with
* MAConnEventData::opType set to #CONNOP_CONNECT.
*
* The success value is \> 0. For the <tt>http</tt> protocol,
* the success value is the HTTP response code.
*
*
* When you're done with the connection, maConnClose() must be called to free
* the resources associated with the handle. This must be done even if
* the connect operation failed.
*
* There is a limit of #CONN_MAX open connection handles at any time, so if you keep
* opening connections without closing them, you'll eventually receive the
* #CONNERR_MAX error code instead of new connection handles.
*
*
* Alternatively, this function can be called with one of these url types to
* create a Server Connection:\n
* <tt>socket://[:\<port\>]</tt>, for TCP.\n
* <tt>btspp://localhost:\<uuid\>[;name=\<YourServiceName\>]</tt>, for Bluetooth.\n
* \<uuid\> is a 32-digit hexadecimal number. It will be used to create the
* service record. Its MAUUID representation can be used by clients to search for
* this service.
*
* Example Bluetooth server url:
* <tt>btspp://localhost:0000110100001000800000805F9B34FB;name=Serial Port</tt>
*
* Server connections are created synchronously; no CONN event is generated,
* and as soon as this function returns, it's done.
*
* A server connection can not be read from or written to, but it can be closed.
* You can also use it in calls to maAccept() and maConnGetAddr().
*
*
* Alternatively, you can use this url type to create an unbound UDP connection:
* <tt>datagram://[:\<port\>]</tt>\n
*
* Such connections must use maConnReadFrom() and maConnWriteTo().
* None of the other Read or Write functions will work, because they require a binding to a remote socket.
*
* Like server connections, unbound UDP connections are created synchronously; no CONN event is generated.
*
*
* \returns The connecting handle \>0, or one of the \link #CONNERR_GENERIC CONNERR \endlink values.
* \see maGetEvent()
* \see \ref connApiOverview
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAHandle maConnect(const char* url);

/**
* Closes a connection, freeing any resources associated with the handle.
*
* Cancels any active operations on the connection.
* Such operations will finish with #CONNERR_CANCELED.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maConnClose(MAHandle conn);

/**
* Asynchronously reads at least one and at most \a size bytes from a connection to memory.
*
* The result of the operation will be delivered in a CONN event, with
* MAConnEventData::opType set to #CONNOP_READ.
* The success value is the number of bytes read.
*
* Datagrams may be bigger than the receiving buffer. In that case,
* \todo #CONNERR_MSGSIZE will be signaled, and the buffer is filled with
* the first part of the datagram. The rest of the datagram is lost.
*
* \see maGetEvent
* \see \ref connApiOverview
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maConnRead(MAHandle conn, void* dst, int size);

/**
* Asynchronously writes \a size bytes to a connection from memory.
*
* The result of the operation will be delivered in a CONN event, with
* MAConnEventData::opType set to #CONNOP_WRITE.
* The success value is \> 0.
*
* \warning The source data must remain available until the operation is complete,
* so if it was dynamically allocated, don't free it too early.
* \see maGetEvent
* \see \ref connApiOverview
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maConnWrite(MAHandle conn, const void* src, int size);

/**
* Asynchronously reads at least one and at most \a size bytes from a connection to
* a data object, starting at the specified offset.
* During the read, the data object being written to will be in flux.
* Any attempt to access it will result in a Panic.
*
* The result of the operation will be delivered in a CONN event, with
* MAConnEventData::opType set to #CONNOP_READ.
* The success value is is the number of bytes read.
*
* \see maGetEvent
* \see \ref connApiOverview
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maConnReadToData(MAHandle conn, MAHandle data, int offset, int size);

/**
* Asynchronously writes \a size bytes to a connection from a data object,
* starting at the specified offset.
* During the write, the data object being read from will be in flux.
* Any attempt to access it will result in a Panic.
*
* The result of the operation will be delivered in a CONN event, with
* MAConnEventData::opType set to #CONNOP_WRITE.
* The success value is \> 0.
*
* \see maGetEvent
* \see \ref connApiOverview
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maConnWriteFromData(MAHandle conn, MAHandle data, int offset, int size);

/**
* Like maConnRead(), except it only works for unbound datagram connections,
* it can read messages from any sender,
* and it will save the source address.
*
* \param src When the read operation completes, the address of the sender will be written here.
* Therefore, the object being pointed to must remain valid for the duration of the operation.
* Don't use a local variable.
*
* \see maConnRead
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maConnReadFrom(MAHandle conn, void* dst, int size, MAConnAddr* src);

/**
* Like maConnWrite(), except it only works for unbound datagram connections,
* and it can send messages to any address.
*
* \param dst The destination address of the datagram being sent.
* The object being pointed to is NOT required to remain valid after this function returns.
* You may use a local variable.
*
* \see maConnWrite
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maConnWriteTo(MAHandle conn, const void* src, int size, const MAConnAddr* dst);

/**
* Retrieves the address of a connection. On server connections,
* you'll get the local address. On normal connections, you'll get the remote address.
*
* You can pass #HANDLE_LOCAL to retrieve the local address.
* In that case, you must set MAConnAddr::family before calling this function,
* to tell it which address to retrieve. Also, the port member is not set.
*
* \returns \< 0 on error.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maConnGetAddr(MAHandle conn, MAConnAddr* addr);

/**
* Creates an unfinished HTTP/1.0 connection. You cannot read from this connection
* until it's been Finished. Before then, you can set request headers. After,
* you can get response headers.

* POST connections are special; they let you write to the connection before
* it's Finished. The first write causes the underlying TCP connection to be
* established and request headers transmitted. After the first write has
* begun, you may no longer set request headers.

* \param url An HTTP or HTTPS URL. See maConnect() for the exact form.
* \param method #HTTP_GET, #HTTP_POST, #HTTP_HEAD, #HTTP_PUT or #HTTP_DELETE.
* \returns An unfinished HTTP connection handle \>0, or a
* \link #CONNERR_GENERIC CONNERR \endlink value.
* \see maHttpFinish
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
MAHandle maHttpCreate(const char* url, int method);

/**
* Sets a request header of an HTTP connection.
*
* Overwrites any existing header with the same key. The keys is case-insensitive.
*
* If the connection's method is #HTTP_POST, it must not have been written to.
* \param conn An unfinished HTTP connection handle.
* \param key The name of the header.
* \param value The new value of the header.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maHttpSetRequestHeader(MAHandle conn, const char* key, const char* value);

/**
* Stores an HTTP response header in the specified buffer.
*
* The buffer may be too small to contain the header and the terminating zero;
* in that case, the buffer will not be filled
* and you should create a bigger buffer and call this function again.
* Use the return value to determine how long the buffer needs to be.
*
* \param conn A finished HTTP connection handle.
* \param key The name of the header. Case-insensitive.
* \param buffer A string buffer.
* \param bufSize The size of the buffer, in bytes.
* \returns The length of the header value, excluding the terminating zero, or
* #CONNERR_NOHEADER if the header doesn't exist.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maHttpGetResponseHeader(MAHandle conn, const char* key, char* buffer, int bufSize);

/**
* Asynchronously finishes an HTTP connection. This entails making the
* underlying TCP connection and sending request headers, unless that has
* already been done by a #HTTP_POST write, and receiving the response headers.
*
* The result of the operation will be delivered in a CONN event, with
* MAConnEventData::opType set to #CONNOP_FINISH.
* The success value is the HTTP response code.
*
* \param conn An unfinished HTTP connection handle.
* \see maGetEvent
* \see \ref connApiOverview
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maHttpFinish(MAHandle conn);

/**
* Loads a new object array from the a data object. The old object array is overwritten,
* except where the new array has SKIP objects. In those cases, the old objects are saved.
* Returns zero on error, \>0 on success. On error, the old object array remains unchanged.
* \param data The data object containing new resources, in the format of a MoSync
* compiled resource file.
* \note There must not be any UBIN objects in the new array,
* except those of the old array that were SKIP'd.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maLoadResources(MAHandle data);

/**
* Loads a specific resource in the given placeholder.
* \param handle The handle of the resource that needs to be loaded
* \param placeholder The placeholder where to load the resource from handle.
* \param flag One of the MA_RESOURCE_OPEN, MA_RESOURCE_CLOSE,
* MA_RESOURCE_OPEN|MA_RESOURCE_CLOSE to control the resource binary.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maLoadResource(MAHandle handle, MAHandle placeholder, int flag);

#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maCountResources(void);

/**
* Loads a new program from the a data object, closes the running program, and starts the new one.
* The format of the data object is a MoSync program file concatenated with a resource file.
* If this function returns, there was an error.
*
* \param data The data object containing the new program.
* \param reload If non-zero, the original program will be reloaded after the new program has
* exited. If zero, MoSync will exit when the loaded program exists, unless that program,
* or one of its sub-programs, calls this function with \a reload set to non-zero.
*
* \note A program that was loaded with this function cannot be reloaded; instead, it will
* always be the very first program in the chain that is reloaded.
* \note The stored reload flag is or'd with the one provided to each call to this function.
* It is also reset when the reload occurs.
* \note Thus, if one program loads another with reload on, and the loaded program loads another
* with reload off, the original program will still be reloaded when the last one exits.
* Should the original program decide to exit after being reloaded, it will not be reloaded again.
*
* \note The \link #EVENT_TYPE_CLOSE close event \endlink will disable the reload mechanism.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maLoadProgram(MAHandle data, int reload);

/**
* Returns a bitmask consisting of \link #MAKB_LEFT MAKB \endlink flags describing the current
* key state.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maGetKeys(void);

/**
* There is a FIFO buffer that contains up to #EVENT_BUFFER_SIZE events.
* Each event has a type. Some types have additional data.
*
* This function retrieves the next event, unless the queue is empty.
* Use maWait() to wait until more events are available.
* \param event Pointer to an MAEvent struct that will be filled with the next event.
*
* When the \link #EVENT_TYPE_CLOSE Close event \endlink is posted,
* you must call maExit as soon as possible, or
* your program will be forcibly terminated. The timeout is device-dependent, but
* never longer than #EVENT_CLOSE_TIMEOUT milliseconds.
*
* After the Close event has been posted, most syscalls will stop working,
* returning default values and doing nothing.
* Only the following groups of functions are guaranteed to remain operational:
* Memory management, math, Resource management, Store, time, logging, maExit() and maPanic().
*
* \note Not all platforms have the capability to generate a Close event.
* You must always provide another way for the user to exit your application.
*
* \returns \> 0 on success, or zero if the buffer is empty.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maGetEvent(MAEvent* event);

/**
* Suspends execution until there is an event in the buffer,
* or \a timeout milliseconds have passed. A timeout <= 0 is considered infinite.
* Timer accuracy is platform-specific, but should be better than 20 ms.
*
* Use this function rather than idle loops to save CPU/battery power.
* \see maGetEvent()
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maWait(int timeout);

/**
* Returns the number of seconds that have passed since
* 00:00:00, Jan 1st, 1970, UTC, according to the device clock.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maTime(void);

/**
* Returns the number of seconds that have passed since
* 00:00:00, Jan 1st, 1970, local time, according to the device clock.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maLocalTime(void);

/**
* Returns the number of milliseconds that has passed since some unknown point in time.
* Accuracy is platform-specific, but should be better than 20 ms.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maGetMilliSecondCount(void);

/**
* Returns an approximation to the amount of memory currently available for
* allocating new objects, measured in bytes.
*
* There may be more memory available than reported by this function. Conversely,
* in the time between calling this function and allocating an object, another program
* may have allocated an object of its own, decreasing the available memory.
*
* The amount of memory required to allocate any specific object is device-dependent.
*
* When using this function to determine whether or not to allocate an object, always
* leave some memory alone for use by the system,
* preferably about 10% of the device's total memory, as reported by maTotalObjectMemory().
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maFreeObjectMemory(void);

/**
* Returns the total amount of memory available to MoSync, measured in bytes.
* May change over time, even as the program is running.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maTotalObjectMemory(void);

/**
* Switches on the vibrator for the requested number of milliseconds,
* or switches it off if the requested duration is zero.
* A call to this function will override the previous call.
* Returns non-zero if the operation was allowed, zero if it wasn't.\n
* \n
* On devices which has no vibrator, this function will always return zero.
* The user may turn vibration off in phone settings. In that case, calling this function
* with a duration of zero may return non-zero, but a non-zero duration will return zero.
* In any case, the only way to conclusively determine if vibration is currently supported
* or not is to call this function with a duration of at least 1(one) ms.
* On iPhone the argument won't be taken into account.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maVibrate(int ms);

/**
* Starts playing a sound.
*
* If a sound was already playing, it is stopped.
*
* The sound data is formatted as follows: \<mime type\>\<null terminator byte\>\<encoded data\>.
*
* The .media directive in the MoSync resource compiler creates this formatting.
*
* If you download or generate sound clips dynamically, you'll have to take care
* of the formatting yourself, or use a library that does it for you,
* for example MAUtil::AudioDownloader.
*
* To play .media resources, use offset 0 and maGetDataSize().
*
* Do not touch the resource while it's playing, or there will be... trouble.
*
* \returns \>= 0 on success and \< 0 on failure.
*
* \param sound_res The data object in which the sound is stored.
* \param offset The offset in the data object where the mime type and sound data is stored.
* \param size The size of mime type string and sound data.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maSoundPlay(MAHandle sound_res, int offset, int size);

/**
* Stops any sound started with maSoundPlay().
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maSoundStop(void);

/**
* Returns \> 0 if sound is playing, zero if it's not.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maSoundIsPlaying(void);

/**
* Returns the volume, in the range 0-100, used by the sound engine.
* The initial volume is 100.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
int maSoundGetVolume(void);

/**
* Sets the volume, which is a value in the range 0-100. All other values will be clamped
* to the allowed range.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
void maSoundSetVolume(int vol);

/**
* Invokes an extension function. Normally you don't call this function directly.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
longlong maExtensionFunctionInvoke(int function, int a, int b, int c MA_IOCTL_ELLIPSIS);

/**
* These functions are available only on certain platforms.
* Returns -1 if the function is not available.
*/
#if defined(__arm__) && !defined(MAPIP) && !defined(MOSYNC_NATIVE)
inline
#endif
longlong maIOCtl(int function, int a, int b, int c MA_IOCTL_ELLIPSIS);


/**
* Loads an extension module. Normally you don't call this function directly.
*/
IOCTLDEF MAExtensionModule maExtensionModuleLoad(const char* id, int hash) {
	return (MAExtensionModule) maIOCtl(1, (int)id, hash, 0);
}

/**
* Loads an extension function. Normally you don't call this function directly.
*/
IOCTLDEF MAExtensionFunction maExtensionFunctionLoad(MAExtensionModule module, int index) {
	return (MAExtensionFunction) maIOCtl(2, module, index, 0);
}

IOCTLDEF int maExtensionFunctionInvoke2(MAExtensionFunction fn, int numargs, int ptrs) {
	return (int) maIOCtl(3, fn, numargs, ptrs);
}

/**
* Returns a handle to one of the default fonts of the device, in the style and size you specify.
* \param 'type' The type of the font, can be FONT_TYPE_[SANS_SERIF,SERIF,MONOSPACE].
* \param 'style' The style of the font, can be FONT_STYLE_[NORMAL,BOLD,ITALIC].
* \param 'size' The size of the font.
* \return The handle to the font, RES_FONT_NO_TYPE_STYLE_COMBINATION, or RES_FONT_INVALID_SIZE.
*/
IOCTLDEF MAHandle maFontLoadDefault(int type, int style, int size) {
	return (MAHandle) maIOCtl(4, type, style, size);
}

/**
* Sets the font to be used with maDrawText and maDrawTextW, and returns the handle
* to the previous font.
* \param 'font' an MAHandle for a font object.
* \return The handle to the previous font, or RES_FONT_INVALID_HANDLE.
*/
IOCTLDEF MAHandle maFontSetCurrent(MAHandle font) {
	return (MAHandle) maIOCtl(5, font, 0, 0);
}

/**
* Returns the number of fonts that are available in the system.
* \return Number of fonts.
* \see maFontGetName.
*/
IOCTLDEF int maFontGetCount(void) {
	return (int) maIOCtl(6, 0, 0, 0);
}

/**
* Copies the font postscript name of the given index to the buffer.
* You must have first called maFontGetCount() at least once before calling this function.
* \param 'index' A 0-based index to the font.
* \param 'buffer' An empty char buffer that will receive the font name.
* \param 'bufferLen' The size of the buffer.
* \return The number of bytes copied (with terminating NULL) or RES_FONT_INDEX_OUT_OF_BOUNDS
* or RES_FONT_INSUFFICIENT_BUFFER or RES_FONT_LIST_NOT_INITIALIZED.
* \see maFontGetCount, maFontLoadWithName.
*/
IOCTLDEF int maFontGetName(int index, char* buffer, int bufferLen) {
	return (int) maIOCtl(7, index, (int)buffer, bufferLen);
}

/**
* Returns a handle to a font with the specific postscript name and size.
* \param 'postScriptName' The postscript name of the font.
* \param 'size' The size of the font.
* \return Handle to the font, RES_FONT_NAME_NONEXISTENT, or RES_FONT_INVALID_SIZE.
*/
IOCTLDEF MAHandle maFontLoadWithName(const char* postScriptName, int size) {
	return (MAHandle) maIOCtl(8, (int)postScriptName, size, 0);
}

/**
* Deletes a loaded font
* \param 'font' A font handle
* \return RES_FONT_OK, RES_FONT_INVALID_HANDLE, or RES_FONT_DELETE_DENIED.
*/
IOCTLDEF int maFontDelete(MAHandle font) {
	return (int) maIOCtl(9, font, 0, 0);
}

/**
 * Sends the current call stack to the report pipe. Returns 0 if succeeded.
 */
IOCTLDEF int maReportCallStack(void) {
	return (int) maIOCtl(10, 0, 0, 0);
}

/**
* Dumps a string, an int, and the current call stack to the log file. Returns 0 if succeeded.
*/
IOCTLDEF int maDumpCallStackEx(const char* str, int data) {
	return (int) maIOCtl(11, (int)str, data, 0);
}

/**
* Protects a piece of the data memory.
* Any attempt to write to that piece of memory will raise a panic.
* \param 'start' The start address of the memory piece to protect.
* \param 'length' The length of the memory piece to protect.
*/
IOCTLDEF void maProtectMemory(const void* start, int length) {
	(void) maIOCtl(12, (int)start, length, 0);
}

/**
* Unprotects a piece of the data memory.
* \param 'start' The start address of the memory piece to unprotect.
* \param 'length' The length of the memory piece to unprotect.
*/
IOCTLDEF void maUnprotectMemory(const void* start, int length) {
	(void) maIOCtl(13, (int)start, length, 0);
}

/**
* Toggles memory protection.
* \param 'enable' If 1 turns on memory protection, if 0 turns of memory protection.
*/
IOCTLDEF void maSetMemoryProtection(int enable) {
	(void) maIOCtl(14, enable, 0, 0);
}

/**
* Returns if memory protection is enabled or not.
* \returns '1' if memory protection is turned on, '0' if it is turned off.
*/
IOCTLDEF int maGetMemoryProtection(void) {
	return (int) maIOCtl(15, 0, 0, 0);
}

/**
* Returns the percentage of battery power remaining. This is an integer between 0 and 100.
* Currently only available on some Symbian and Windows Mobile phones.
*/
IOCTLDEF int maGetBatteryCharge(void) {
	return (int) maIOCtl(16, 0, 0, 0);
}

/**
* Calls on the operating system to lock the phone's keypad.
* Returns \> 0 if successful.
*/
IOCTLDEF int maLockKeypad(void) {
	return (int) maIOCtl(26, 0, 0, 0);
}

/**
* Calls on the operating system to unlock the phone's keypad.
* Returns \> 0 if successful.
*/
IOCTLDEF int maUnlockKeypad(void) {
	return (int) maIOCtl(27, 0, 0, 0);
}

/**
* Returns \> 0 if the phone's keypad is locked by the operating system, zero otherwise.
*/
IOCTLDEF int maKeypadIsLocked(void) {
	return (int) maIOCtl(28, 0, 0, 0);
}

/**
* Writes data to the MoSync system log file.
* Useful only for debugging purposes.
*/
IOCTLDEF int maWriteLog(const void* src, int size) {
	return (int) maIOCtl(29, (int)src, size, 0);
}

/**
* Starts a device discovery operation.
*
* \param names Set this to non-zero to retrieve the names of remote devices.
* This takes extra time, so set it to zero for faster scanning.
*
* \note On Windows, due to a bug in the Microsoft Bluetooth stack,
* newly discovered devices may appear without names.
* Re-scanning should make the devices' names appear properly.
* A workaround is planned for a future release of MoSync.
*
* \returns 0 on success, \< 0 on failure.
*
* \see maBtGetNewDevice
* \see maBtCancelDiscovery
* \see EVENT_TYPE_BT
*/
IOCTLDEF int maBtStartDeviceDiscovery(int names) {
	return (int) maIOCtl(30, names, 0, 0);
}

/**
* Fills an MABtDevice structure with information about a device.
* Removes the data from an internal queue filled by maBtStartDeviceDiscovery().
*
* If the \a names parameter of maBtStartDeviceDiscovery() was zero,
* all members of \a d except \a address are ignored and unchanged.
*
* The space needed to store the device name and its terminating zero
* may be greater than a nameBufSize. In that case, the copy is truncated.
* The maximum length of a device name according to the Bluetooth 2.0 specification
* is 248 bytes, excluding the terminating zero. However, it's recommended that you
* don't provide buffers larger than what your application has a use for.
*
* Note that you need to fill the MABtDevice structure before passing it
* as a parameter, otherwise you will get memory access problems.
*
* \returns 1 if successful, zero if the queue is empty.
*/
IOCTLDEF int maBtGetNewDevice(MABtDevice* d) {
	return (int) maIOCtl(31, (int)d, 0, 0);
}

/**
* Starts a service discovery operation.
* Takes a device address and the UUID of the service class to search for.
* For example, pass #RFCOMM_PROTOCOL_MAUUID and you'll get all connectable services.
* Pass #SerialPort_Service_MAUUID and you'll get only that type of service.
*
* \see maBtGetNextServiceSize
* \see maBtGetNewService
* \see maBtCancelDiscovery
* \see EVENT_TYPE_BT
*
* \returns 0 on success, \< 0 on failure.
*
* \note Service discovery is not supported on Android. Use MAUtil::BluetoothConnection
* to connect via service UUID. That method is cross-platform.
*/
IOCTLDEF int maBtStartServiceDiscovery(const MABtAddr* address, const MAUUID* uuid) {
	return (int) maIOCtl(32, (int)address, (int)uuid, 0);
}

/**
* Fills an MABtServiceSize structure with meta-data about the next service.
* Does not remove the service from the queue.
* \returns \> 0 on success, or zero if the queue is empty.
* \see maBtStartServiceDiscovery
* \see maBtGetNewService
*/
IOCTLDEF int maBtGetNextServiceSize(MABtServiceSize* dst) {
	return (int) maIOCtl(33, (int)dst, 0, 0);
}

/**
* Fills an MABtService structure with information about the next service.
* Removes the data from the internal queue filled by maBtStartServiceDiscovery().
* \returns \> 0 on success, or zero if the queue is empty.
* \see maBtGetNextServiceSize
*/
IOCTLDEF int maBtGetNewService(MABtService* dst) {
	return (int) maIOCtl(34, (int)dst, 0, 0);
}

/**
* Cancels any active discovery operation.
* If an operation was canceled, its last BT event will have the state #CONNERR_CANCELED.
* This is an asynchronous operation. If this function returns 1,
* it is not safe to start another discovery before
* you've received the #CONNERR_CANCELED event.
* \see maBtStartDeviceDiscovery
* \see maBtStartServiceDiscovery
* \see EVENT_TYPE_BT
* \returns 0 if there was no active operation, 1 if there was.
*/
IOCTLDEF int maBtCancelDiscovery(void) {
	return (int) maIOCtl(35, 0, 0, 0);
}

/**
* Starts collecting location information.
* Does nothing if collection is already active.
* May cause a system popup asking for the user's permission.
*
* \link #EVENT_TYPE_LOCATION LOCATION events \endlink will be generated as the
* estimated location is updated.
*
* \link #EVENT_TYPE_LOCATION_PROVIDER LOCATION_PROVIDER events \endlink will be generated
* when the location provider state changes.
*
* \returns MA_LPS_AVAILABLE on success, 0 if collection was already active, or
* MA_LPS_OUT_OF_SERVICE if the location provider is out of service, or
* \< 0 on error.
*
* \note <b>The location API is experimental, not fully tested.
* It may not work as advertised.</b>
*
* In particular, it is unsupported on the MoSync Emulator.
* Implementation details are likely to change in the future.
*/
IOCTLDEF int maLocationStart(void) {
	return (int) maIOCtl(38, 0, 0, 0);
}

/**
* Stops collecting location information, and stops generating events.
* Does nothing if collection is not active.
*
* \note \link #EVENT_TYPE_LOCATION Location events \endlink that are generated before
* this function returns may remain in the event queue afterwards.
*
* \returns 0.
*/
IOCTLDEF int maLocationStop(void) {
	return (int) maIOCtl(39, 0, 0, 0);
}

/**
* Requests that the operating system handle (for example, display or install) the indicated URL.
*
* If the platform has the appropriate capabilities and resources available,
* it SHOULD bring the appropriate application to the foreground and let the user
* interact with the content, while keeping the MoSync application running in the background.
* If the platform does not have appropriate capabilities or resources available,
* it MAY wait to handle the request until after the MoSync application exits.
* In this case, when the requesting MoSync application exits, the platform MUST then bring
* the appropriate application (if one exists) to the foreground to let the user
* interact with the content.
*
* The URL can be of the form <tt>http://\<address\></tt>, in which case the usual response is
* to launch the built-in web browser.
*
* The URL can also be of the form <tt>tel:\<number\></tt>, in which case the request is
* interpreted as a request to initiate a voice call to the specified number.
*
* If the URL refers to a packaged application
* (a .JAR file on Java platforms, .SIS on Symbian or .CAB on Windows Mobile),
* the request is interpreted as a request to install that application.
*
* The application being requested can be an update of the calling application.
* In that case, the calling application must always exit before the request can be processed.
*
* \param url The URL for the platform to load.
* An empty string or NULL cancels any pending requests.
*
* \returns \> 0 if maExit() must be called before the request can be processed.
* 0 if the request is being processed.
* \< 0 if the request could not be processed.
* Specifically, the error code #IOCTL_UNAVAILABLE means that the protocol
* of the request is not supported on the platform.
*/
IOCTLDEF int maPlatformRequest(const char* url) {
	return (int) maIOCtl(40, (int)url, 0, 0);
}

/**
* Opens a file handle.
* If the file exists, the file will be accessible according to the mode specified.
* If the file does not exist, a handle will still be returned and
* maFileExists() will return false.
* The file may then be created by calling maFileCreate().
*
* Directories may be opened with this function. They cannot be read or written,
* but they can be created and deleted, and their existence can be queried.
* Directory paths must end with a slash('/').
*
* Attempting to open an existing directory without ending its path with a slash will fail.
* Likewise, attempting to open an existing file while ending its path with a slash will also fail.
* Either case will return #MA_FERR_WRONG_TYPE.
*
* \note To avoid memory leaks, all opened handles should be closed using maFileClose().
*
* \note To find valid file paths, use maFileListStart().
*
* \param path The absolute path to the file.
* \param mode The access mode. Either #MA_ACCESS_READ or #MA_ACCESS_READ_WRITE.
* Directories also use these access modes. #MA_ACCESS_READ lets you see if the directory exists.
* #MA_ACCESS_READ_WRITE also lets you create or delete it.
* \returns The new file handle, or \< 0 on error.
*
* \note If any maFile function other than maFileOpen() fails,
* the state of the file handle becomes boundedly undefined.
* This means that any operation on it, other than maFileClose(), may fail.
*/
IOCTLDEF MAHandle maFileOpen(const char* path, int mode) {
	return (MAHandle) maIOCtl(41, (int)path, mode, 0);
}

/**
* Returns 1 if the file exists, 0 if it doesn't, or \< 0 on error.
*/
IOCTLDEF int maFileExists(MAHandle file) {
	return (int) maIOCtl(42, file, 0, 0);
}

/**
* Closes a file handle. Returns 0. Panics on error.
*/
IOCTLDEF int maFileClose(MAHandle file) {
	return (int) maIOCtl(43, file, 0, 0);
}

/**
* Creates a file or directory, given an file handle opened with #MA_ACCESS_READ_WRITE.
* The file must not exist prior to calling this function.
* After creation, the file will be accessible for writing and reading.
* Returns 0 on success, or \< 0 on error.
*/
IOCTLDEF int maFileCreate(MAHandle file) {
	return (int) maIOCtl(44, file, 0, 0);
}

/**
* Deletes a file or directory.
* The file must exist prior to calling this function.
* If it's a directory, it must be empty.
* Returns 0 on success, or \< 0 on error.
*/
IOCTLDEF int maFileDelete(MAHandle file) {
	return (int) maIOCtl(45, file, 0, 0);
}

/**
* Returns the size of the file, or \< 0 on error.
* \note MoSync cannot handle files larger than 2 GiB (2^31 - 1 bytes).
* \param file A file handle. The file must exist and must not be a directory.
*/
IOCTLDEF int maFileSize(MAHandle file) {
	return (int) maIOCtl(46, file, 0, 0);
}

/**
* Returns the number of free bytes on the file system on which \a file resides.
* Note that due to file system overhead, it is not possible to use all of
* this space for file data.
* Returns \< 0 on error.
*/
IOCTLDEF int maFileAvailableSpace(MAHandle file) {
	return (int) maIOCtl(47, file, 0, 0);
}

/**
* Returns the total size, in bytes, of the file system on which \a file resides.
* Returns \< 0 on error.
*/
IOCTLDEF int maFileTotalSpace(MAHandle file) {
	return (int) maIOCtl(48, file, 0, 0);
}

/**
* Returns the date/time when the file was last modified, or \< 0 on error.
* The time format is Unix UTC.
* \see maTime()
*/
IOCTLDEF int maFileDate(MAHandle file) {
	return (int) maIOCtl(49, file, 0, 0);
}

/**
* Renames a file.
*
* If \a newName does not contain a slash,
* the file stays in its original directory.
*
* If \a newName does contain a slash, it must be a complete pathname,
* and the file is moved to that path. The new path must be on the same file system
* as the original path. If it is not, this function fails with #MA_FERR_RENAME_FILESYSTEM.
* Moving a file to another directory is not supported on Java ME. If it is attempted,
* this function fails with #MA_FERR_RENAME_DIRECTORY.
*
* \returns 0 on success, or \< 0 on error.
*/
IOCTLDEF int maFileRename(MAHandle file, const char* newName) {
	return (int) maIOCtl(50, file, (int)newName, 0);
}

/**
* Truncates the file.
*
* If \a offset is less than the file's current size,
* the file's new size is equal to the offset. All data after the offset is discarded.
*
* If \a offset is equal to the file's current size, this function does nothing.
*
* If \a offset is greater than the file's current size,
* this function MAY increase the size of the file.
* You can determine if it did so by calling maFileSeek() with #MA_SEEK_END.
*
* If the file's current position is greater than \a offset, it is reset
* to be equal to \a offset.
*
* The file must exist prior to calling this function.
* Returns 0 on success, or \< 0 on error.
*/
IOCTLDEF int maFileTruncate(MAHandle file, int offset) {
	return (int) maIOCtl(51, file, offset, 0);
}

/**
* Writes from memory to file.
* \param file Target file.
* \param src Source memory address.
* \param len Length, in bytes, of the data to be written.
* \returns 0 on success, or \< 0 on error.
*/
IOCTLDEF int maFileWrite(MAHandle file, const void* src, int len) {
	return (int) maIOCtl(52, file, (int)src, len);
}

/**
* Writes from a data object to file.
* \param file Target file.
* \param data Source data object.
* \param offset Offset from the start of the data object.
* \param len Length, in bytes, of the data to be written.
* \returns 0 on success, or \< 0 on error.
*/
IOCTLDEF int maFileWriteFromData(MAHandle file, MAHandle data, int offset, int len) {
	return (int) maIOCtl(53, file, data, offset, len);
}

/**
* Reads exactly \a len bytes from file to memory.
* \param file Source file.
* \param src Target memory address.
* \param len Length, in bytes, of the data to be read.
* \returns 0 on success, or \< 0 on error. If \a len bytes is not available, #MA_FERR_GENERIC is returned.
*/
IOCTLDEF int maFileRead(MAHandle file, void* dst, int len) {
	return (int) maIOCtl(54, file, (int)dst, len);
}

/**
* Reads exactly \a len bytes from file to a data object.
* \param file Source file.
* \param data Target data object.
* \param offset Offset from the start of the data object.
* \param len Length, in bytes, of the data to be read.
* \returns 0 on success, or \< 0 on error. If \a len bytes is not available, #MA_FERR_GENERIC is returned.
*/
IOCTLDEF int maFileReadToData(MAHandle file, MAHandle data, int offset, int len) {
	return (int) maIOCtl(55, file, data, offset, len);
}

/**
* Returns the file's current position, or \< 0 on error.
* \param file A file handle. The file must exist and must not be a directory.
*/
IOCTLDEF int maFileTell(MAHandle file) {
	return (int) maIOCtl(56, file, 0, 0);
}

/**
* Sets the file's position.
* \param file A file handle. The file must exist and must not be a directory.
* \param offset The offset of the new position,
* relative to the position specified by \a whence.
* \param whence One of the \link #MA_SEEK_SET MA_SEEK \endlink constants.
* \returns The new position, or \< 0 on error.
*/
IOCTLDEF int maFileSeek(MAHandle file, int offset, int whence) {
	return (int) maIOCtl(57, file, offset, whence);
}

/**
* Creates a listing of names of files and directories, or file systems.
* Call maFileListNext() repeatedly to retrieve the names. Call maFileListClose() to
* free the resources used.
*
* It is often useful to begin by listing the file systems.
*
* \param path The full path to a directory, or the empty string,
* which specifies that the root file systems should be listed.
* Which root file systems are listed vary between platforms.
* \param filter A string to match names with. May include an asterisk ('*') wildcard
* to represent 0 or more characters. Ignored if \a path is empty.
* \param sorting One of the \link #MA_FL_SORT_DATE MA_FL_SORT \endlink flags,
* OR'd with one of the \link #MA_FL_ORDER_ASCENDING MA_FL_ORDER \endlink flags.
* #MA_FL_SORT_NONE must not be combined with an
* \link #MA_FL_ORDER_ASCENDING MA_FL_ORDER \endlink flag.
* \note Sorting is not supported on JavaME. If it is attempted,
* this function will fail with #MA_FERR_SORTING_UNSUPPORTED.
*
* \returns A File Listing handle, or \< 0 on error.
*/
IOCTLDEF MAHandle maFileListStart(const char* path, const char* filter, int sorting) {
	return (MAHandle) maIOCtl(58, (int)path, (int)filter, sorting);
}

/**
* Writes the name of the next file in the list to the specified buffer.
*
* The buffer may be too small to contain the name and the terminating zero;
* in that case, the internal list pointer remains unchanged,
* the buffer will not be filled,
* and you should allocate a bigger buffer and call this function again.
* You may call this function with NULL and 0 to simply retrieve the length of the name.
*
* If the name ends with a slash('/'), it is a directory.
*
* \returns The length of the name, excluding the terminating zero,
* or 0 if there are no more files, or \< 0 on error.
*/
IOCTLDEF int maFileListNext(MAHandle list, char* nameBuf, int bufSize) {
	return (int) maIOCtl(59, list, (int)nameBuf, bufSize);
}

/**
* Closes a file listing, freeing its resources.
*
* \returns 0.
*/
IOCTLDEF int maFileListClose(MAHandle list) {
	return (int) maIOCtl(60, list, 0, 0);
}

/**
* Sets the properties of a file
*
*/
IOCTLDEF int maFileSetProperty(const char* path, int property, int value) {
	return (int) maIOCtl(61, (int)path, property, value);
}

/**
 * Saves an images in the photo gallery of the device.
 *
 * Notifications of this operation are available via
 * #MAUtil::MediaExportListener.
 *
 * \param imageHandle handle of the image that needs to be exported to the
 * device.
 * \param imageName the name that the image will have after is saved.
 * Note: This argument is ignored on iOS.
 *
 * \return #MA_MEDIA_RES_OK if the input was correct and the operation started
 * or #MA_MEDIA_RES_IMAGE_EXPORT_FAILED otherwise.
 */
IOCTLDEF int maSaveImageToDeviceGallery(MAHandle imageHandle, const char* imageName) {
	return (int) maIOCtl(62, imageHandle, (int)imageName, 0);
}

/**
* Sends a text SMS. Since this may cost money for the user,
* some platforms ask the user for permission,
* by displaying a modal Yes/No message box.
*
* \param dst The phone number to send the message to.
* \param msg The message to send. Only printable 7-bit ASCII characters are guaranteed
* to arrive unaltered. 8-bit Latin-1 characters should work in most cases.
*
* \returns 0 on success. A \link #CONNERR_GENERIC CONNERR \endlink code \< 0 on error.
* #CONNERR_FORBIDDEN if the user denied permission, and CONNERR_UNAVAILABLE if the
* device cannot send SMS messages.
*
* \note Will create a text file on PC platforms, instead of sending anything.
*/
IOCTLDEF int maSendTextSMS(const char* dst, const char* msg) {
	return (int) maIOCtl(63, (int)dst, (int)msg, 0);
}

/**
 * Get frame buffer info. Use info.sizeInBytes to allocate memory for framebuffer.
 * \param info A pointer to an MAFrameBufferInfo structure, which the information will be written to.
 * \returns \<=0 on error.
 */
IOCTLDEF int maFrameBufferGetInfo(MAFrameBufferInfo* info) {
	return (int) maIOCtl(81, (int)info, 0, 0);
}

/**
 * Pass a pointer to your framebuffer here. Each time an maUpdateScreen is performed,
 * this piece of memory will be copied to the actual screen memory.
 * \param data A pointer to the custom framebuffer.
 * \returns \<=0 on error.
 */
IOCTLDEF int maFrameBufferInit(const void* data) {
	return (int) maIOCtl(82, (int)data, 0, 0);
}

/**
 * Close the framebuffer. The graphics sub-system will be set to use the standard framebuffer.
 * \returns \<=0 on error.
 */
IOCTLDEF int maFrameBufferClose(void) {
	return (int) maIOCtl(83, 0, 0, 0);
}

/**
* Asynchronously accepts and opens a remote connection to a service.
*
* When a connection is accepted, a CONN event with #CONNOP_ACCEPT will be generated.
* If the accept was successful, MAConnEventData::result will be a handle to the new,
* normal connection. MAConnEventData::handle will be the server connection specified
* in the call to this function.
*
* To accept another connection after such an event, call this function again.
*
* \param serv A server connection, opened with maConnect.
* \returns \< 0 on error, \> 0 on success.
* \see maConnect
* \see maGetEvent
*/
IOCTLDEF int maAccept(MAHandle serv) {
	return (int) maIOCtl(87, serv, 0, 0);
}

/**
* Sends the application to the background, unless it's already there.
* Generates a \link #EVENT_TYPE_FOCUS_LOST FOCUS_LOST \endlink event.
* \note Only available on multi-tasking operating systems.
*/
IOCTLDEF int maSendToBackground(void) {
	return (int) maIOCtl(88, 0, 0, 0);
}

/**
* Brings the application to the foreground, unless it's already there.
* Generates a \link #EVENT_TYPE_FOCUS_LOST FOCUS_GAINED \endlink event.
* \note Only available on multi-tasking operating systems.
*/
IOCTLDEF int maBringToForeground(void) {
	return (int) maIOCtl(89, 0, 0, 0);
}

/**
* Retrieves the value of a Java System Property, or a MoSync System Property.
*
* There are a few MoSync System Properties. They are unavailable on some devices.
* "mosync.imei" and "mosync.imsi" is the device's IMEI and IMSI number, respectively.
* The format of these numbers is not specified. It varies from device to device.
*
* "mosync.iso-639-1" and "mosync.iso-639-2" is the current language used by the system's UI.
* Multi-language applications should use this to determine which language to use.
*
* "mosync.winmobile.locale.SABBREVLANGNAME" is a windows mobile specific property.
* See http://msdn.microsoft.com/en-us/library/dd373831%28VS.85%29.aspx.
*
* See http://www.loc.gov/standards/iso639-2/php/code_list.php -
* The official list of valid ISO-639 codes (online).
*
* "mosync.device" is a description of the device. May include vendor, model name
* and firmware version.
* The format of this description is not specified. It varies from device to device.
*
* "mosync.device.name" is the name of the device. Usually set by the user.
*
* "mosync.device.UUID" is the Unique identifier of the device. Not available on iOS platform.
*
* "mosync.device.OS" is the operating system or platform that the device is using.
* It might contain version detail as well.
*
* "mosync.device.OS.version" is the the version of the operating system that is running on the device.
* It might contain minor revision information, e.g. 2.1Update-1.
*
* "mosync.network.type" it the type of the current active network connection.
* It can one of the following four values: "none", "wifi", "mobile", or "unknown".
*
* "mosync.path.local" is the absolute path to the local file system,
* on devices that have a local file system. The returned path has a
* trailing slash character ('/').
*
* \param key The property's key.
* \param buf A buffer where the value should be written.
* \param size The size of the buffer, in bytes.
* \returns The length of the value, including the terminating zero.
* If this is greater than \a size, the value will not have been copied to be buffer.
* In that case, you can make a bigger buffer and try again.
* If the property did not exist (System.getProperty() returned null),
* -2 will be returned.
*/
IOCTLDEF int maGetSystemProperty(const char* key, char* buf, int size) {
	return (int) maIOCtl(91, (int)key, (int)buf, size);
}

/**
* Normally, when the first Internet connection is made in a Symbian application,
* the user must choose an Internet Access Point.
*
* This function saves the ID of the active IAP for this application.
* It will be used automatically the next time the application is started.
*
* \returns 1 if the ID was successfully saved. 0 if there is no active IAP. \< 0 on error.
* \note Implemented only on Symbian.
*/
IOCTLDEF int maIapSave(void) {
	return (int) maIOCtl(92, 0, 0, 0);
}

/**
* Removes any saved IAP ID for this application.
* The next time the application is started,
* or the next time an Internet connection is made after a call to maIapShutdown(),
* the user will have to select a new IAP.
* \returns 1 if the ID was successfully removed. 0 if there was no saved ID. \< 0 on error.
* \note Implemented only on Symbian.
* \see maIapSave()
*/
IOCTLDEF int maIapReset(void) {
	return (int) maIOCtl(93, 0, 0, 0);
}

/**
* Shuts down the active IAP.
* This has the effect of calling maConnClose() on all existing connections.
* \returns 1 if the IAP was successfully shut down. 0 if there was no active IAP. \< 0 on error.
* \note Implemented only on Symbian.
* \see maIapSave()
*/
IOCTLDEF int maIapShutdown(void) {
	return (int) maIOCtl(94, 0, 0, 0);
}

/**
* Returns the current telephone network status.
* This is one of the \link #MA_NETWORK_UNKNOWN MA_NETWORK \endlink constants.
* #MA_NETWORK_HOME and #MA_NETWORK_ROAMING are the most interesting ones;
* all the others are variants of "not connected".
* Returns \< 0 on error.
* \see #EVENT_TYPE_NETWORK
* \note Implemented only on Symbian, 3rd edition and later.
*/
IOCTLDEF int maNetworkStatus(void) {
	return (int) maIOCtl(95, 0, 0, 0);
}

/**
* Decides how IAP connection attempts should work.
*
* IAP connection attempts are made asynchronously by maConnect(),
* if there is no active IAP.
*
* This setting is reset to default when the application starts.
* \param type One of the \link #MA_IAP_METHOD_STANDARD MA_IAP_METHOD \endlink constants.
* \returns \< 0 on error.
* \note Implemented only on Symbian, 3rd edition and later.
*/
IOCTLDEF int maIapSetMethod(int type) {
	return (int) maIOCtl(96, type, 0, 0);
}

/**
* Decides which IAPs are visible in the IAP selection dialog.
* This setting is reset to default when the application starts.
* \param filter One of the \link #MA_IAP_FILTER_NOT_WLAN MA_IAP_FILTER \endlink constants.
* \returns \< 0 on error.
* \note Implemented only on Symbian, 3rd edition and later.
*/
IOCTLDEF int maIapSetFilter(int filter) {
	return (int) maIOCtl(97, filter, 0, 0);
}

/**
* Returns the number of different output formats supported by the current device's camera.
* \< 0 if there is no camera support.
* 0 if there is camera support, but the format is unknown.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraFormatNumber(void) {
	return (int) maIOCtl(144, 0, 0, 0);
}

/**
* Stores an output format in \a fmt.
* \a index must be \>= 0 and \< the number returned by maCameraFormatNumber().
* \returns 0.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraFormat(int index, MA_CAMERA_FORMAT* fmt) {
	return (int) maIOCtl(145, index, (int)fmt, 0);
}

/**
* Starts a fullscreen viewfinder.
* Returns 1 if the viewfinder was started, 0 if it was already running or \< 0 on error.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraStart(void) {
	return (int) maIOCtl(146, 0, 0, 0);
}

/**
* Stops the viewfinder.
* Returns 1 if the viewfinder was stopped, 0 if it was not running or \< 0 on error.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraStop(void) {
	return (int) maIOCtl(147, 0, 0, 0);
}

/**
* Adds a previewWidget to the camera controller in devices that support native UI.
* Returns 1 for success, \< 0 on error.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraSetPreview(MAHandle widgetHandle) {
	return (int) maIOCtl(148, widgetHandle, 0, 0);
}

/**
* Selects a Camera from the available ones.
* Returns 1 for success, \< 0 on error.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraSelect(int cameraNumber) {
	return (int) maIOCtl(149, cameraNumber, 0, 0);
}

/**
* Returns the number of available Camera on the device.
* Returns 1 for success, \< 0 on error.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraNumber(void) {
	return (int) maIOCtl(150, 0, 0, 0);
}

/**
* Requires the viewfinder to be active.
* Takes a snapshot using the specified format. The snapshot is
* stored as a new data object in the supplied placeholder.
* Returns 0 on success, or \< 0 on error.
*
* Note: Since MoSync 3.3 the usage of ths syscall is deprecated
* and the use of #maCameraSnapshotAsync is recommended.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraSnapshot(int formatIndex, MAHandle placeholder) {
	return (int) maIOCtl(151, formatIndex, placeholder, 0);
}

/**
* Requires the viewfinder to be active.
* Triggers the reading of the camera buffer into dataPlaceholder according
* to the specified sizeIndex.
* The snapshot data will be passed via #EVENT_TYPE_CAMERA_SNAPSHOT event.
*
* \param dataPlaceholder a valid placeholder where the snapshot data
* will be written.
* \param sizeIndex snapshot size index. See #maCameraFormatNumber().
* \return #MA_CAMERA_RES_OK on success, or #MA_CAMERA_RES_FAILED on error.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraSnapshotAsync(MAHandle dataPlaceholder, int sizeIndex) {
	return (int) maIOCtl(152, dataPlaceholder, sizeIndex, 0);
}

/**
* Starts or stops recording video.
* \a stopStartFlag indicates the operation.
* 1 for start recording and 0 for stop recording.
* Returns 1 for success, \< 0 on error.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraRecord(int stopStartFlag) {
	return (int) maIOCtl(153, stopStartFlag, 0, 0);
}

/**
* Sets a specified property on the Selected Camera.
*
* \param property A string representing which property to set.
* \param value The value which will be assigned to the property.
*
* \returns 1 for success and <0 for failure.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraSetProperty(const char* property, const char* value) {
	return (int) maIOCtl(154, (int)property, (int)value, 0);
}

/**
* retrives a specified property on the Selected Camera.
*
* \param property A string representing which property to set.
* \param value A buffer that will hold the value of the property, represented as a string.
* \param bufSize Size of the buffer.
*
* \returns 1 for success and <0 for failure.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraGetProperty(const char* property, char* value, int bufSize) {
	return (int) maIOCtl(155, (int)property, (int)value, bufSize);
}

/**
* Retrieves the underlying camera preview size. This can be different
* from the preview view so before enabling preview events it's
* important that you check the true size.
*
* \returns the size as an EXTENT, <0 on failure.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraPreviewSize(void) {
	return (int) maIOCtl(156, 0, 0, 0);
}

/**
* Enables events for accessing data during camera preview.
* Only one preview event may be used at the same time.
*
* \param previewEventType One of the CameraPreviewEvents
* \param previewBuffer An int buffer in which the data will stored
* \param previewArea The rectangle of the preview in which we will get data
*
* \return 1 on success and <0 on failure
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraPreviewEventEnable(int previewEventType, void* previewBuffer, const MARect* previewArea) {
	return (int) maIOCtl(157, previewEventType, (int)previewBuffer, (int)previewArea);
}

/**
* Turns off the current preview event
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraPreviewEventDisable(void) {
	return (int) maIOCtl(158, 0, 0, 0);
}

/**
* Function that informs the runtime that it's ready to get
* the next preview event.
* This is because the preview sends a lot of events and if it
* take some time to process the image the event cue should get
* filled with events.
*/
/** @ingroup CameraFunctions */
IOCTLDEF int maCameraPreviewEventConsumed(void) {
	return (int) maIOCtl(159, 0, 0, 0);
}

/**
* Shows the virtual keyboard.
*/
IOCTLDEF int maShowVirtualKeyboard(void) {
	return (int) maIOCtl(160, 0, 0, 0);
}

/**
* Displays a NativeUI text box, with
* "OK" and "Cancel" buttons (or equivalent command items
* if the OS uses other input methods).
* The user can enter text using the native input system.
*
* This function returns immediately, leaving the text box on-screen.
* While the text box is active, it will consume all key events.
* Other events, like networking, will still be handled normally.
*
* When the user activates one of the command items ("OK" or "Cancel"),
* a number of things will happen in order:
*
* The box's text will be copied to the buffer specified by \a outText.
* The text box will disappear.
* An event (#EVENT_TYPE_TEXTBOX) will be posted.
*
* The text box will allow input of up to (\a maxSize - 1) characters, but no more.
* Additional keypresses at that point may be ignored, or may cause an error message,
* at the discretion of the underlying implementation.
*
* \returns \>= 0 on success, \< 0 on error.
*
* \param title The box's title.
* \param inText When the text box is created, it is populated with this string.
* \param outText Pointer to a buffer. When the text box closes, the contents
* are copied to this buffer.
* \param maxSize The size of the buffer, in characters. Includes the terminating zero.
* \param constraints Rules for how text is entered into the box.
* Must be exactly one of the \link #MA_TB_TYPE_ANY MA_TB_TYPE \endlink constants, or'd with zero or more of the
* \link #MA_TB_FLAG_PASSWORD MA_TB_FLAG \endlink constants.
* \note Some combinations of constraint types and flags are useless or invalid.
*/
IOCTLDEF int maTextBox(const wchar* title, const wchar* inText, wchar* outText, int maxSize, int constraints) {
	return (int) maIOCtl(161, (int)title, (int)inText, (int)outText, maxSize, constraints);
}

/**
* Make MoSync send key-events for the specified key, even when
* the application does not have focus.
* Can only capture one key at a time.
* @param keyCode The \link #MAK_UNKNOWN MAK \endlink code for the key to capture.
* @return \< 0 on error.
* \see maKeyCaptureStop()
*/
IOCTLDEF int maKeyCaptureStart(int keyCode) {
	return (int) maIOCtl(162, keyCode, 0, 0);
}

/**
* Stops any key capture in progress.
* @returns \< 0 on error.
* \see maKeyCaptureStart()
*/
IOCTLDEF int maKeyCaptureStop(void) {
	return (int) maIOCtl(163, 0, 0, 0);
}

/**
 * Turn on sending of HomeScreen events. Off by default.
 * @return \< 0 on error.
 * \see #EVENT_TYPE_HOMESCREEN_SHOWN
 * \see #EVENT_TYPE_HOMESCREEN_HIDDEN
 * \see maHomeScreenEventsOff()
 */
IOCTLDEF int maHomeScreenEventsOn(void) {
	return (int) maIOCtl(164, 0, 0, 0);
}

/**
 * Turn off sending of HomeScreen events. Off by default.
 * @return \< 0 on error.
 */
IOCTLDEF int maHomeScreenEventsOff(void) {
	return (int) maIOCtl(165, 0, 0, 0);
}

/**
* Add shortcut icon to the device home screen.
* Available on Android only.
* @param name The name (label) of the shortcut to add.
* @return \< 0 on error.
*/
IOCTLDEF int maHomeScreenShortcutAdd(const char* name) {
	return (int) maIOCtl(166, (int)name, 0, 0);
}

/**
* Remove shortcut icon from the device home screen.
* Available on Android only.
* @param name The name (label) of the shortcut to remove.
* @return \< 0 on error.
*/
IOCTLDEF int maHomeScreenShortcutRemove(const char* name) {
	return (int) maIOCtl(167, (int)name, 0, 0);
}

/**
 * Add a notification item.
 * @deprecated use #maNotificationLocalCreate instead.
 * Note that there can only be one notification of type
 * #NOTIFICATION_TYPE_APPLICATION_LAUNCHER. Additional notification
 * types may be added in the future. This syscall is available
 * on Android only.
 *
 * @param type The #NOTIFICATION_TYPE_APPLICATION_LAUNCHER constant.
 * @param id The id of the notification. The id must be unique within
 * the application.
 * @param title Title of the notification.
 * @param text String to be displayed as part of the notification.
 * @return \< 0 on error or if the syscall is not available on the
 * current platform.
 */
IOCTLDEF int maNotificationAdd(int type, int id, const char* title, const char* text) {
	return (int) maIOCtl(168, type, id, (int)title, (int)text);
}

/**
 * Remove a notification item.
 * @deprecated use maNotificationDestroy instead.
 * Currently implemented only on Android.
 * @param id The id of the notification.
 * @return \< 0 on error.
 */
IOCTLDEF int maNotificationRemove(int id) {
	return (int) maIOCtl(169, id, 0, 0);
}

/**
 * Enable/disable fullscreen mode.
 * Currently implemented only on Android.
 * @param fullscreen 1 for fullscreen on, 0 for fullscreen off.
 * @return \< 0 on error.
 */
IOCTLDEF int maScreenSetFullscreen(int fullscreen) {
	return (int) maIOCtl(170, fullscreen, 0, 0);
}

/**
* Registers this application for autostart on device reboot.
* Applications started this way start in the background;
* invisible to the user, unless they check the list of running applications.
* \returns 1 on success, 0 if already registered, \< 0 on error.
*/
IOCTLDEF int maAutostartOn(void) {
	return (int) maIOCtl(171, 0, 0, 0);
}

/**
* Removes autostart registration for this application.
* \returns 1 on success, 0 if already unregistered, \< 0 on error.
*/
IOCTLDEF int maAutostartOff(void) {
	return (int) maIOCtl(172, 0, 0, 0);
}

/**
 * Turn on sending of screen state events. Off by default.
 * Currently implemented only on Android.
 * @return \< 0 on error.
 * \see #EVENT_TYPE_SCREEN_STATE_ON
 * \see #EVENT_TYPE_SCREEN_STATE_OFF
 * \see maHomeScreenEventsOff()
 */
IOCTLDEF int maScreenStateEventsOn(void) {
	return (int) maIOCtl(173, 0, 0, 0);
}

/**
 * Turn off sending of screen state events. Off by default.
 * Currently implemented only on Android.
 * @return \< 0 on error.
 */
IOCTLDEF int maScreenStateEventsOff(void) {
	return (int) maIOCtl(174, 0, 0, 0);
}

/**
 * Lock device to be "awake". This means that the device
 * won't go to sleep while the app is running.
 * @param flag MA_WAKE_LOCK_ON or MA_WAKE_LOCK_OFF
 * @return \>0 on success, \< 0 on error (-1 if not available).
 */
IOCTLDEF int maWakeLock(int flag) {
	return (int) maIOCtl(175, flag, 0, 0);
}

/**
 * Logs information about the state of all current resources.
 */
IOCTLDEF void maReportResourceInformation(void) {
	(void) maIOCtl(424, 0, 0, 0);
}

/**
 * @deprecated use #maAlert instead.
 * Displays a message to the user.
 * \param title The title of the message box shown
 * \param message The message should be short, not more than 40 characters,
 * to ensure its visibility on all screen sizes.
 */
IOCTLDEF void maMessageBox(const char* title, const char* message) {
	(void) maIOCtl(425, (int)title, (int)message, 0);
}

/**
* Displays a message to the user.
* It contains optional title, message and 3 buttons for selection.
* On Android the buttons point to a positive, negative or neutral action.
* When one of the buttons are clicked the alert is automatically dismissed.
* When a selection is made a #EVENT_TYPE_ALERT event is sent with the button index.
* \param title The title of the message box shown.
* \param message The message should be short, not more than 40 characters,
* to ensure its visibility on all screen sizes.
* \param button1 The text on the first button. On Android it indicates a positive selection.
* \param button2 The text on the second button. On Android it indicates a neutral selection.
* \param button3 The text on the third button. On Android it indicates that a negative selection.
*/
IOCTLDEF void maAlert(const char* title, const char* message, const char* button1, const char* button2, const char* button3) {
	(void) maIOCtl(426, (int)title, (int)message, (int)button1, (int)button2, (int)button3);
}

/**
* \brief A toast is a view containing a quick little message for the user.
* A toast provides simple feedback about an operation in a small popup.
* It only fills the amount of space required for the message and the current
* activity remains visible and interactive.
* For example, navigating away from an email before you send it triggers a
* "Draft saved" toast to let you know that you can continue editing later.
* Toasts automatically disappear after a timeout, and do not handle any user interaction.
* Toast are available only on Android.
*
* \param message The message in the toast.
* \param duration One of the next constants:
* - #MA_TOAST_DURATION_SHORT
* - #MA_TOAST_DURATION_LONG
*/
IOCTLDEF int maToast(const char* message, int duration) {
	return (int) maIOCtl(427, (int)message, duration, 0);
}

/**
* Displays an image picker to the user.
* It's display depends on the platform.
* Note: when a selection is made a #EVENT_TYPE_IMAGE_PICKER event is sent.
*/
IOCTLDEF void maImagePickerOpen(void) {
	(void) maIOCtl(428, 0, 0, 0);
}

/**
* Displays an image picker to the user and sets the event return type.
* It's display depends on the platform.
* Note: when a selection is made a #EVENT_TYPE_IMAGE_PICKER event is sent.
* \param eventType One of the next constants:
* - #MA_IMAGE_PICKER_EVENT_RETURN_TYPE_IMAGE_HANDLE
* - #MA_IMAGE_PICKER_EVENT_RETURN_TYPE_IMAGE_DATA
*/
IOCTLDEF void maImagePickerOpenWithEventReturnType(int eventReturnType) {
	(void) maIOCtl(429, eventReturnType, 0, 0);
}

/**
* Displays a special kind of dialog that has a list of possible choices.
* The list of options is displayed as buttons on iOS, and as text views on Android.
* By clicking any option the dialog gets dismissed and a #EVENT_TYPE_OPTIONS_BOX_BUTTON_CLICKED event is sent back.
*
* \param title The dialog title.
* \param destructiveButtonTitle The destructive button text. This is an iOS specific feature: it has different color than the other options,
* and it indicates that it's action has destructive behaviour. On Android it is treated and it looks like a normal option.
* \param cancelButtonTitle The dialog's Cancel button text. If left empty, the dialog is not cancelable.
* \param otherButtonTitles The address to the buffer that stores the list of options.
* \param otherButtonTitlesSize The size of the buffer, in bytes.
*/
IOCTLDEF void maOptionsBox(const wchar* title, const wchar* destructiveButtonTitle, const wchar* cancelButtonTitle, const void* otherButtonTitles, int otherButtonTitlesSize) {
	(void) maIOCtl(430, (int)title, (int)destructiveButtonTitle, (int)cancelButtonTitle, (int)otherButtonTitles, otherButtonTitlesSize);
}

/**
* \brief Enables a sensor and starts sending events if the sensor is available.
* If the sensor is already enabled this call will have no effect.
* \param sensor       The sensor which should be enabled.
* One of the \link #SENSOR_TYPE_ACCELEROMETER SENSOR_TYPE \endlink constants.
* \param interval     Time interval in which a sensor update shall be triggered.
* Can be one of the \link #SENSOR_RATE_FASTEST SENSOR_RATE \endlink constants or a time interval in milliseconds.
* \return    #SENSOR_ERROR_NONE  on success.
*            #SENSOR_ERROR_NOT_AVAILABLE if this sensor wasn't available.
*            #SENSOR_ERROR_INTERVAL_NOT_SET if the interval wasn't set, could be due to platform limitations.
*            #SENSOR_ERROR_ALREADY_ENABLED if the sensor already was enabled.
* \see #EVENT_TYPE_SENSOR
*/
/** @ingroup SensorFunctions */
IOCTLDEF int maSensorStart(int sensor, int interval) {
	return (int) maIOCtl(431, sensor, interval, 0);
}

/**
* \brief Disables a sensor so that it doesn't send any further events.
* \param sensor    The sensor which should be disabled.
* One of the \link #SENSOR_TYPE_ACCELEROMETER SENSOR_TYPE \endlink constants.
* \return    #SENSOR_ERROR_NONE on success.
*            #SENSOR_ERROR_NOT_ENABLED if this sensor wasn't enabled.
*            #SENSOR_ERROR_CANNOT_DISABLE if there was a problem disabling the sensor.
* \see #EVENT_TYPE_SENSOR
*/
/** @ingroup SensorFunctions */
IOCTLDEF int maSensorStop(int sensor) {
	return (int) maIOCtl(432, sensor, 0, 0);
}

/**
* Start listening to NFC events.
* \return MA_NFC_NOT_ENABLED if NFC is not enabled on this device,
* MA_NFC_NOT_AVAILABLE if NFC is not at all available, or
* 0 otherwise.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCStart(void) {
	return (int) maIOCtl(433, 0, 0, 0);
}

/**
* Stop listening to NFC events.
*/
/** @ingroup NFCAPI */
IOCTLDEF void maNFCStop(void) {
	(void) maIOCtl(434, 0, 0, 0);
}

/**
* Reads the next available tag.
* @return A zero handle if no tag currently available
*/
/** @ingroup NFCAPI */
IOCTLDEF MAHandle maNFCReadTag(MAHandle nfcContext) {
	return (MAHandle) maIOCtl(435, nfcContext, 0, 0);
}

/**
* Destroys the tag. Clients are responsible for calling
* this function for every corresponding maNFCReadTag.
*/
/** @ingroup NFCAPI */
IOCTLDEF void maNFCDestroyTag(MAHandle tagHandle) {
	(void) maIOCtl(436, tagHandle, 0, 0);
}

/**
* Connects to a tag, enabling further I/O operations to be
* performed on it.
*/
/** @ingroup NFCAPI */
IOCTLDEF void maNFCConnectTag(MAHandle tagHandle) {
	(void) maIOCtl(437, tagHandle, 0, 0);
}

/**
* Closes I/O operations for a tag, disabling further I/O operations to be
* performed on it.
*/
/** @ingroup NFCAPI */
IOCTLDEF void maNFCCloseTag(MAHandle tagHandle) {
	(void) maIOCtl(438, tagHandle, 0, 0);
}

/**
* Determines whether a tag is of a certain type.
* Use the constants prefixed with MA_NFC_TAG_TYPE_ to
* see the available tag types.
* \return > 0 if the tag is a the specified type, 0 if it is not,
* and MA_NFC_INVALID_TAG_TYPE if the tag type is not supported
* by this platform.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCIsType(MAHandle tagHandle, int type) {
	return (int) maIOCtl(439, tagHandle, type, 0);
}

/**
* To be able to call functions tag require the tag to be of
* a certain type (see maNFCIsType), the tag received
* must be converted to the proper type (see MA_NFC_TAG_TYPE_*
* constants).
* All typed tags returned by this function will be destroyed
* when the tag used to produce them is destroyed. Ie no
* explicit destruction of typed tags is necessary (but allowed).
* \return A handle if the type was convertable to the specified
* type.
*/
/** @ingroup NFCAPI */
IOCTLDEF MAHandle maNFCGetTypedTag(MAHandle tagHandle, int type) {
	return (MAHandle) maIOCtl(440, tagHandle, type, 0);
}

/**
* Starts a batch operation. No NFC I/O operations will be performed
* until maBatchCommit has been called.
* Note that only one active batch per tag is allowed.
* \param The tag on which to perform the batch operation.
* \return A non-zero value if a batch is already started for this tag or if a batch
* could not be started, 0 otherwise.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCBatchStart(MAHandle tagHandle) {
	return (int) maIOCtl(441, tagHandle, 0, 0);
}

/**
* Asynchronously performs all operations since the last call to maNFCBatchStart. The event
* delivered will be of the EVENT_TYPE_NFC_BATCH_OP type and
* with an MANFCEventData containing the tag's handle.
* \param The handle to the tag that is in batch mode.
*/
/** @ingroup NFCAPI */
IOCTLDEF void maNFCBatchCommit(MAHandle tagHandle) {
	(void) maIOCtl(442, tagHandle, 0, 0);
}

/**
* Cancels all operations of the current batch.
* \param The handle to the tag that is in batch mode.
*/
/** @ingroup NFCAPI */
IOCTLDEF void maNFCBatchRollback(MAHandle tagHandle) {
	(void) maIOCtl(443, tagHandle, 0, 0);
}

/**
* Sends a message to a tag. The response will come as
* an EVENT_TYPE_NFC_TAG_DATA_READ event, with the
* handle set to the handle passed into this method
* and the result field set to the number of bytes
* actually read.
* \param tag The tag to communicate with.
* \param src The data to send.
* \param len The length of the data to send.
* \return 0 if the tag can be transceived to, < 0 otherwise.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCTransceive(MAHandle tag, const void* src, int srcLen, void* dst, int* dstLen) {
	return (int) maIOCtl(444, tag, (int)src, srcLen, (int)dst, (int)dstLen);
}

/**
* Makes a tag read-only (this operation cannot be reverted).
* The response will come as an EVENT_TYPE_NFC_TAG_READ_ONLY event, with the
* handle set to the handle passed into this method.
* \param tag The tag to make read only.
* \return MA_NFC_INVALID_TAG_TYPE if the handle given as argument
* cannot be made read-only.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCSetReadOnly(MAHandle tag) {
	return (int) maIOCtl(445, tag, 0, 0);
}

/**
* Checks whether a tag is read-only.
* \param tag The tag to check for read/write permissions.
* \return MA_NFC_INVALID_TAG_TYPE if this operation is
* not applicable, a value > 0 if it is read-only, or
* 0 if it is read-only.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCIsReadOnly(MAHandle tag) {
	return (int) maIOCtl(446, tag, 0, 0);
}

/**
* Returns the capacity/size of a tag.
* \param tag The tag to get the size from.
* \return The size of the tag, or -1 if unknown.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetSize(MAHandle tag) {
	return (int) maIOCtl(447, tag, 0, 0);
}

/**
* Returns the (serial) id a tag. This id may or may
* not be unique depending on the underlying technology.
* The serial id may also be empty.
* \param tag The tag to read from.
                * \param dst Where the result should be written to.
                * \param len The maximum length to write.
* \return The number of bytes of the id.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetId(MAHandle tag, void* dst, int len) {
	return (int) maIOCtl(448, tag, (int)dst, len);
}

/**
* Reads an NDEF message from the given tag, which must
* be of the MA_NFC_TAG_TYPE_NDEF type.
* The response will come a an EVENT_TYPE_NFC_TAG_DATA_READ
* event with the handle set to the handle passed into this method
* and the result field set to 0 on success and a value < 0 on error.
* After receiving the event, clients may call
* maNFCGetNDEFMessage() to get the actual message.
* If the handle is not an NDEF tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCReadNDEFMessage(MAHandle tag) {
	return (int) maIOCtl(449, tag, 0, 0);
}

/**
* Writes an NDEF message to the given tag, which must
* be of the MA_NFC_TAG_TYPE_NDEF or MA_NFC_TAG_TYPE_NDEF_FORMATTABLE type.
* The response will come a an EVENT_TYPE_NFC_TAG_DATA_WRITE
* event with the handle set to the handle passed into this method,
* the result field set to 0 on success and a value < 0 on error,
* and the dstId field set to the ndefMessage written.
* If the handle is not an NDEF tag, MA_NFC_INVALID_TAG_TYPE will be returned.
* \param tag The tag handle to write to
* \param ndefMessage The message to write
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCWriteNDEFMessage(MAHandle tag, MAHandle ndefMessage) {
	return (int) maIOCtl(450, tag, ndefMessage, 0);
}

/**
* Creates a new NDEF message, to be used primarily by
* \code maNFCWriteDefMessage. \endcode
* \param recordCount The number of records in the created message
* \return The handle to the created NDEF message; clients are
* responsible for destroying the message.
*/
/** @ingroup NFCAPI */
IOCTLDEF MAHandle maNFCCreateNDEFMessage(int recordCount) {
	return (MAHandle) maIOCtl(451, recordCount, 0, 0);
}

/**
* Gets the NDEF message from a tag, which must
* be of the MA_NFC_TAG_TYPE_NDEF type.
* If the handle is not an NDEF tag, MA_NFC_INVALID_TAG_TYPE will be returned.
* (Please note the difference between an NDEF \b tag and an NDEF \b message.)
* \return The handle to the NDEF message, which
* may be subsequently used in NDEF specfic functions,
* or the zero handle if the tag has no NDEF message
* associated with it (in which case, clients may call
* maNFCReadNDEFMessage).
* IMPORTANT: Once the tag has been destroyed OR if
* maNFCReadNDEFMessage is called, any NDEF messages
* previously returned by this function
* will be destroyed with it and cannot
* be used.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetNDEFMessage(MAHandle tag) {
	return (int) maIOCtl(452, tag, 0, 0);
}

/**
* \return A handle to the ith NDEF record of an NDEF message.
* If the handle is not an NDEF message, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF MAHandle maNFCGetNDEFRecord(MAHandle ndefMessage, int ix) {
	return (MAHandle) maIOCtl(453, ndefMessage, ix, 0);
}

/**
* \return The number of NDEF records in an NDEF message.
* If the handle is not an NDEF message, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetNDEFRecordCount(MAHandle ndefMessage) {
	return (int) maIOCtl(454, ndefMessage, 0, 0);
}

/**
* Reads the variable length id of an NDEF record.
* \param ndefRecord the handle to the record to read from.
* \param dst Where the result should be written to.
* \param len The maximum length to write.
* \return The number of bytes written.
* If the handle is not an NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetNDEFId(MAHandle ndefRecord, void* dst, int len) {
	return (int) maIOCtl(455, ndefRecord, (int)dst, len);
}

/**
* Reads the variable length payload of an NDEF record.
* \param ndefRecord the handle to the record to read from.
* \param dst Where the result should be written to.
* \param len The maximum length to write.
* \return The number of bytes written.
* If the handle is not an NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetNDEFPayload(MAHandle ndefRecord, void* dst, int len) {
	return (int) maIOCtl(456, ndefRecord, (int)dst, len);
}

/**
* Returns the 3-bit TNF of an NDEF record.
* If the handle is not an NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetNDEFTnf(MAHandle ndefRecord) {
	return (int) maIOCtl(457, ndefRecord, 0, 0);
}

/**
* Returns the variable length type field of an NDEF record.
* \param ndefRecord the handle to the record to read from.
* \param dst Where the result should be written to.
* \param len The maximum length to write.
* \return The number of bytes written.
* If the handle is not an NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetNDEFType(MAHandle ndefRecord, void* dst, int len) {
	return (int) maIOCtl(458, ndefRecord, (int)dst, len);
}

/**
* Sets the variable length id of an NDEF record.
* If the handle is not an NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCSetNDEFId(MAHandle ndefRecord, const void* dst, int len) {
	return (int) maIOCtl(459, ndefRecord, (int)dst, len);
}

/**
* Sets the variable length payload of an NDEF record.
* If the handle is not NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCSetNDEFPayload(MAHandle ndefRecord, const void* dst, int len) {
	return (int) maIOCtl(460, ndefRecord, (int)dst, len);
}

/**
* Sets the 3-bit TNF of an NDEF record,
* If the handle is not NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCSetNDEFTnf(MAHandle ndefRecord, int tnf) {
	return (int) maIOCtl(461, ndefRecord, tnf, 0);
}

/**
* Returns the variable length type field of an NDEF record.
* If the handle is not NDEF message record, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCSetNDEFType(MAHandle ndefRecord, const void* dst, int len) {
	return (int) maIOCtl(462, ndefRecord, (int)dst, len);
}

/**
* Authenticates a MIFARE Classic tag using the A or B key. Authentication must take place
* before reading/writing to a certain sector.
* The operation is asyncronous and will result in an EVENT_TYPE_NFC_TAG_AUTH_COMPLETE
* event, unless part of a batch operation.
* \param tagHandle The tag to authenticate
* \param keyType Either MA_NFC_MIFARE_KEY_A or MA_NFC_MIFARE_KEY_B.
* \param sectorIndex The sector to authenticate
* \param keySrc The address to the key to authenticate with
* \param keyLen The length of the key to authenticate with
* If the handle is not a Mifare Classic tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCAuthenticateMifareSector(MAHandle tagHandle, int keyType, int sectorIndex, const void* keySrc, int keyLen) {
	return (int) maIOCtl(463, tagHandle, keyType, sectorIndex, (int)keySrc, keyLen);
}

/**
* \return The number of sectors of a MIFARE Classic tag.
* If the handle is not a Mifare Classic tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetMifareSectorCount(MAHandle tagHandle) {
	return (int) maIOCtl(464, tagHandle, 0, 0);
}

/**
* Returns the number of blocks in a sector of a MIFARE Classic tag.
* \param sector The sector to get the number of blocks in.
* \return The number of blocks in a given sector.
* If the handle is not a Mifare Classic tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCGetMifareBlockCountInSector(MAHandle tagHandle, int sector) {
	return (int) maIOCtl(465, tagHandle, sector, 0);
}

/**
* Returns the first block of a sector of a MIFARE Classic tag.
* \param sector The sector of which to get the first block.
* \return The index of the first block of the sector is returned.
* If the handle is not a Mifare Classic tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCMifareSectorToBlock(MAHandle tagHandle, int sector) {
	return (int) maIOCtl(466, tagHandle, sector, 0);
}

/**
* Reads a number of blocks of a MIFARE Classic tag.
* The operation is asyncronous and will result in an EVENT_TYPE_NFC_TAG_READ
* event, unless part of a batch operation.
* \param firstBlock The first block to read from.
* \param dst The memory address to write to.
* \param len The number of bytes to read. Several blocks may be read, depending
* on len (A block is 16 bytes).
* If the handle is not a Mifare Classic tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCReadMifareBlocks(MAHandle tagHandle, int firstBlock, void* dst, int len) {
	return (int) maIOCtl(467, tagHandle, firstBlock, (int)dst, len);
}

/**
* Writes a number of blocks to a MIFARE Classic tag.
* The operation is asyncronous and will result in an EVENT_TYPE_NFC_TAG_WRITE
* event, unless part of a batch operation.
* \param firstBlock The first block to write to.
* \param dst The memory address to read from.
* \param len The number of bytes to write. Several blocks may be written, depending
* on len (A block is 16 bytes).
* If the handle is not a Mifare Classic tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCWriteMifareBlocks(MAHandle tagHandle, int firstBlock, const void* dst, int len) {
	return (int) maIOCtl(468, tagHandle, firstBlock, (int)dst, len);
}

/**
* Reads a number of blocks of a MIFARE Ultralight tag.
* The operation is asyncronous and will result in an EVENT_TYPE_NFC_TAG_READ
* event, unless part of a batch operation.
* \param firstBlock The first block to read from.
* \param dst The memory address to write to.
* \param len The number of bytes to read. Several pages may be read, depending
* on len (A page is 16 bytes).
* If the handle is not a Mifare Ultralight tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCReadMifarePages(MAHandle tagHandle, int firstPage, void* dst, int len) {
	return (int) maIOCtl(469, tagHandle, firstPage, (int)dst, len);
}

/**
* Writes a number of blocks of a MIFARE Ultralight tag.
* The operation is asyncronous and will result in an EVENT_TYPE_NFC_TAG_WRITE
* event, unless part of a batch operation.
* \param firstBlock The first block to write to.
* \param dst The memory address to read from.
* \param len The number of bytes to write. Several pages may be written, depending
* on len (A page is 16 bytes).
* If the handle is not a Mifare Ultralight tag, MA_NFC_INVALID_TAG_TYPE will be returned.
*/
/** @ingroup NFCAPI */
IOCTLDEF int maNFCWriteMifarePages(MAHandle tagHandle, int firstPage, const void* dst, int len) {
	return (int) maIOCtl(470, tagHandle, firstPage, (int)dst, len);
}

/**
 * Open a database file. The database is created if it does not exist.
 * \note The application needs file read/write permissions to
 * access database files.
 * @param path Absolute path to the database file.
 * @return Handle to the database >0 on success, #MA_DB_ERROR on error.
 */
/** @ingroup DBAPI */
IOCTLDEF MAHandle maDBOpen(const char* path) {
	return (MAHandle) maIOCtl(471, (int)path, 0, 0);
}

/**
 * Close a database.
 * @param databaseHandle Handle to the database.
 * @return #MA_DB_OK on success, #MA_DB_ERROR on error.
 */
/** @ingroup DBAPI */
IOCTLDEF int maDBClose(MAHandle databaseHandle) {
	return (int) maIOCtl(472, databaseHandle, 0, 0);
}

/**
 * Executes an SQL statement. If the statement returns a
 * query result, a cursor handle is returned.
 * If a query result is empty, #MA_DB_OK is returned.
 * @param databaseHandle Handle to the database.
 * @param sql The SQL statement.
 * @return #MA_DB_ERROR on error, #MA_DB_OK on success,
 * > 0 if there is a cursor to a query result, in this
 * case the return value is the cursor handle.
 */
/** @ingroup DBAPI */
IOCTLDEF MAHandle maDBExecSQL(MAHandle databaseHandle, const char* sql) {
	return (MAHandle) maIOCtl(473, databaseHandle, (int)sql, 0);
}

/**
 * @copydoc maDBExecSQL()
 *
 * @param params Array of values to bind to parameters.
 * Parameters are specified by question marks (?) in the SQL statement.
 *
 * If this function returns a cursor, any text or blob values being
 * pointed to by elements of the array must remain valid until the
 * cursor has been destroyed by maDBCursorDestroy().
 *
 * The array itself does not need to remain valid after this
 * function returns.
 *
 * @param paramCount Number of elements in the array pointed to
 * by \a params.
 *
 * This function is available on iOS, Android, and in MoRE.
 */
/** @ingroup DBAPI */
IOCTLDEF MAHandle maDBExecSQLParams(MAHandle databaseHandle, const char* sql, const MADBValue* params, int paramCount) {
	return (MAHandle) maIOCtl(474, databaseHandle, (int)sql, (int)params, paramCount);
}

/**
 * Destroys a cursor. You must call this function
 * when you are done with the cursor to release
 * its resources.
 * @param cursorHandle Handle to the cursor.
 * @return #MA_DB_OK on success, #MA_DB_ERROR on error.
 */
/** @ingroup DBAPI */
IOCTLDEF int maDBCursorDestroy(MAHandle cursorHandle) {
	return (int) maIOCtl(475, cursorHandle, 0, 0);
}

/**
 * Move the cursor to the next row in the result set.
 * Note that you must call this function before retrieving
 * column data. The initial position of the cursor is
 * before the first row in the result set. If the result
 * set is empty, this function will return #MA_DB_NO_ROW.
 * @param cursorHandle Handle to the cursor.
 * @return #MA_DB_OK if successfully moved to next row,
 * #MA_DB_NO_ROW if there are no more rows in the result set,
 * #MA_DB_ERROR on error.
 */
/** @ingroup DBAPI */
IOCTLDEF int maDBCursorNext(MAHandle cursorHandle) {
	return (int) maIOCtl(476, cursorHandle, 0, 0);
}

/**
 * Get the column value at the current row pointed to
 * by the cursor as a data object. Use this function for
 * blob data or text data.
 * @param cursorHandle Handle to the cursor.
 * @param columnIndex Index of the column to retrieve value from.
 * First column has index zero.
 * @param placeholder Handle created with maCreatePlaceholder.
 * A data object will be created with the column data, and the handle
 * will refer to that data.
 * @return #MA_DB_OK on success, #MA_DB_NULL if the column value
 * is NULL, #MA_#MA_DB_ERROR on error.
 */
/** @ingroup DBAPI */
IOCTLDEF int maDBCursorGetColumnData(MAHandle cursorHandle, int columnIndex, MAHandle placeholder) {
	return (int) maIOCtl(477, cursorHandle, columnIndex, placeholder);
}

/**
 * Get the column value at the current row pointed to
 * by the cursor as a text data buffer. Use this function for
 * text data.
 * @param cursorHandle Handle to the cursor.
 * @param columnIndex Index of the column to retrieve value from.
 * First column has index zero.
 * @param buffer Pointer to buffer to receive the data.
 * The result is NOT zero terminated.
 * @param bufferSize Max size of the buffer.
 * @return The actual length of the data, if the actual length
 * returned is > bufferSize, data was not copied (buffer too small),
 * returns #MA_DB_ERROR on other errors, returns #MA_DB_NULL if the
 * column value is NULL.
 */
/** @ingroup DBAPI */
IOCTLDEF int maDBCursorGetColumnText(MAHandle cursorHandle, int columnIndex, void* buffer, int bufferSize) {
	return (int) maIOCtl(478, cursorHandle, columnIndex, (int)buffer, bufferSize);
}

/**
 * Get the column value at the current row pointed to
 * by the cursor as an int value.
 * @param cursorHandle Handle to the cursor.
 * @param columnIndex Index of the column to retrieve value from.
 * First column has index zero.
 * @param value Pointer to int to receive the value.
 * @return #MA_DB_OK on success, #MA_DB_NULL if the column value
 * is NULL, #MA_#MA_DB_ERROR on error.
 */
/** @ingroup DBAPI */
IOCTLDEF int maDBCursorGetColumnInt(MAHandle cursorHandle, int columnIndex, int* value) {
	return (int) maIOCtl(479, cursorHandle, columnIndex, (int)value);
}

/**
 * Get the column value at the current row pointed to
 * by the cursor as a double value.
 * @param cursorHandle Handle to the cursor.
 * @param columnIndex Index of the column to retrieve value from.
 * First column has index zero.
 * @param value Pointer to double to receive the value.
 * @return #MA_DB_OK on success, #MA_DB_NULL if the column value
 * is NULL, #MA_#MA_DB_ERROR on error.
 */
/** @ingroup DBAPI */
IOCTLDEF int maDBCursorGetColumnDouble(MAHandle cursorHandle, int columnIndex, double* value) {
	return (int) maIOCtl(480, cursorHandle, columnIndex, (int)value);
}

/**
* @brief Creates a MAAudioData handle from a MoSync resource.
* @param mime The mime string for the resource. Can be NULL
* @param data The binary resource
* @param offset The offset in the binary file to where the data starts
* @param length The length of the data to use
* @param flags MA_AUDIO_DATA_STREAM means that the audio should be streamed
*	either from disk or over HTTP. This is only for music playback,
*	sound effects should have the flag set to 0.
* @attention Windows Phone only supports wave-files (see remarks here: http://msdn.microsoft.com/en-us/library/microsoft.xna.framework.audio.soundeffect.fromstream.aspx).
* @return A MAAudioData handle or <0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF MAAudioData maAudioDataCreateFromResource(const char* mime, MAHandle data, int offset, int length, int flags) {
	return (MAAudioData) maIOCtl(481, (int)mime, data, offset, length, flags);
}

/**
* @brief Creates a MAAudioData handle from an URL or file path.
* @param mime The mime string for the resource. Can be NULL
* @param url The URL to the resource file. Accepts 'http://' or 'http://' for
*	streaming from internet. Without protcol file is assumed.
* @param flags MA_AUDIO_DATA_STREAM means that the audio should be streamed
*	either from disk or over HTTP. This is only for music playback,
*	sound effects should have this flag set to 0.
* @return A MAAudioData handle or <0 on error.
* @attention iOS Only supports loading local files.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF MAAudioData maAudioDataCreateFromURL(const char* mime, const char* url, int flags) {
	return (MAAudioData) maIOCtl(482, (int)mime, (int)url, flags);
}

/**
* @brief Destroys a MAAudioData handle and releases used memory
*
* @param audioData The MAAudioData handle.
* @return MA_AUDIO_ERR_OK on success or <0 on fail.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioDataDestroy(MAAudioData audioData) {
	return (int) maIOCtl(483, audioData, 0, 0);
}

/**
* @brief Creates a MAAudioInstance handle from a MAAudioData handle.
*
* @param audioData The MAAudioData handle
*
* @return A MAAudioInstance handle or <0 on error.
*
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF MAAudioInstance maAudioInstanceCreate(MAAudioData audioData) {
	return (MAAudioInstance) maIOCtl(484, audioData, 0, 0);
}

/**
* @brief Creates an MAAudioInstance that can be fed samples dynamically.
*
* @param sampleRate  The samplerate of the audio instance.
* @param numChannels Number of channels for the audio instance (1 means mono, 2 means stereo).
* @param bufferSize  The size of the underlying sample buffer (in samples).
*
* @return A MAAudioInstance handle or <0 on error.
*
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF MAAudioInstance maAudioInstanceCreateDynamic(int sampleRate, int numChannels, int bufferSize) {
	return (MAAudioInstance) maIOCtl(485, sampleRate, numChannels, bufferSize);
}

/**
* @brief Submits a buffer of samples to a dynamic MAAudioInstance
*
* @param instanceThe handle to the MAAudioInstance
* @param bufferA pointer to the samples that should be submitted. Each sample must be a signed 16-bit short. When using more than one channel, the samples should be interleaved.
* @param numBytesThe number of bytes to read.
* @return <0 on error.
*
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioSubmitBuffer(MAAudioInstance instance, const void* buffer, int numBytes) {
	return (int) maIOCtl(486, instance, (int)buffer, numBytes);
}

/**
* @brief Gets the pending buffer count for the dynamic MAAudioInstance
*
* @param instanceThe handle to the MAAudioInstance
* @return <0 on error, otherwise the pending buffer count.
*
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioGetPendingBufferCount(MAAudioInstance instance) {
	return (int) maIOCtl(487, instance, 0, 0);
}

/**
* @brief Destroys a MAAudioInstance handle releases used memory
* @param audioInstance The MAAudioInstance handle
* @return MA_AUDIO_ERR_OK on success,
*	<0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioInstanceDestroy(MAAudioInstance audioInstance) {
	return (int) maIOCtl(488, audioInstance, 0, 0);
}

/**
* @brief Returns the lenght in milliseconds for this instance.
* @param audio The MAAudioInstance handle
* @return The lenght in milliseconds,
*	<0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioGetLength(MAAudioInstance audio) {
	return (int) maIOCtl(489, audio, 0, 0);
}

/**
* @brief Sets the number of loops this instance will play
*
* @param audio The MAAudioInstance handle
* @param loops 0 means play once,
*	>0 means loop 'loops' times,
* -1 means loop forever.
* @return MA_AUDIO_ERR_OK on success, <0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioSetNumberOfLoops(MAAudioInstance audio, int loops) {
	return (int) maIOCtl(490, audio, loops, 0);
}

/**
* @brief Prepares an MAAudioInstance before playback.
* If prepared asynchronous the call will return directly, but the
* MAAudioInstance will not be ready for playback until
* an EVENT_TYPE_AUDIO_PREPARED event has been sent.
* If synchronous the call will block execution until finished
* and the MAAudioInstance will be ready directly.
* @attention If a streaming audio is already playing and a new one is being prepared,
* on some platforms the playing audio will stop.
*
* @param audio The MAAudioInstance handle
* @param async 0 if synchronus, 1 if asynchronous
* @return MA_AUDIO_ERR_OK on success
*	MA_AUDIO_ERR_INVALID_INSTANCE on invalid audio instance
*	MA_AUDIO_ERR_ALREADY_PREPARED on already prepared audio instance
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioPrepare(MAAudioInstance audio, int async) {
	return (int) maIOCtl(491, audio, async, 0);
}

/**
* @brief Plays the current MAAudioInstance.
* @attention If the audio hasn't been prepared, on Android, it will be synchrounous
*	prepared before playing, this means that there might be a delay before
*	this call returns. Always make sure that your audio has been properly
*	prepared before playing.
* @param audio The MAAudioInstance handle.
* @return MA_AUDIO_ERR_OK on success, <0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioPlay(MAAudioInstance audio) {
	return (int) maIOCtl(492, audio, 0, 0);
}

/**
* @brief Sets the current position in milliseconds.
* @param audio The MAAudioInstance handle.
* @param milliseconds The number of milliseconds from the start.
* @return MA_AUDIO_ERR_OK on success,
*	<0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioSetPosition(MAAudioInstance audio, int milliseconds) {
	return (int) maIOCtl(493, audio, milliseconds, 0);
}

/**
* @brief Gets the current position in milliseconds.
* @param audio The MAAudioInstance handle.
* @return The current playing position in milliseconds,
*	<0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioGetPosition(MAAudioInstance audio) {
	return (int) maIOCtl(494, audio, 0, 0);
}

/**
* @brief Sets the volume for this MAAudioInstance.
* @param audio The MAAudioInstance handle.
* @return MA_AUDIO_ERR_OK on success,
*	<0 on error
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioSetVolume(MAAudioInstance audio, float volume) {
	MA_FV _volume;
	_volume.f = volume;
	return (int) maIOCtl(495, audio, _volume.i, 0);
}

/**
* @brief Pauses the MAAudioInstance if it's playing.
* It will stay prepared, so the sound can be resumed at any time using maAudioPlay.
* @param audio The MAAudioInstance handle.
* @return MA_AUDIO_ERR_OK on success, <0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioPause(MAAudioInstance audio) {
	return (int) maIOCtl(496, audio, 0, 0);
}

/**
* @brief Stops the the audio instance and sets the position to the beginning.
* The audio instance might be unprepared, meaning all it's prepared buffers might
* be released.
* @param audio The MAAudioInstance handle.
* @return MA_AUDIO_ERR_OK on success, <0 on error.
*/
/** @ingroup AudioAPIFunctions */
IOCTLDEF int maAudioStop(MAAudioInstance audio) {
	return (int) maIOCtl(497, audio, 0, 0);
}

/**
* Enable panics for programmer errors.
* Such panics are enabled by default, but can be disabled by maSyscallPanicsDisable().
* If a panic is raised a message will be displayed to the user and the program will be shut down.
* \return #RES_OK.
*/
IOCTLDEF int maSyscallPanicsEnable(void) {
	return (int) maIOCtl(498, 0, 0, 0);
}

/**
* Disable panics for programmer errors.
* Some errors, such as feeding invalid parameters to certain syscalls,
* can be prevented by the programmer. By default, these errors cause a MoSync Panic.
* After this function is called,
* if such an error occurs in a syscall, an error code will be returned by the syscall and the
* program will continue running.
* Panics can be re-enabled by maSyscallPanicsEnable().
* \return #RES_OK.
*/
IOCTLDEF int maSyscallPanicsDisable(void) {
	return (int) maIOCtl(499, 0, 0, 0);
}

/**
* \brief Creates a new banner.
* \param bannerSize One of the MA_ADS_SIZE_ constants. Only for Android and WP7.1 platforms.
* \param publisherID Only for Android and WP 7.1 platforms.
* This param is ignored on iOS platform.
*
* \note A banner is a widget type object.
* For more info see Widget API.
*
* \returns
*  - #MA_ADS_RES_UNSUPPORTED if ads are not supported on current system.
*  - #MA_ADS_RES_ERROR if a error occurred while creating the banner widget.
*  - a handle to a new banner widget(the handle value is >= 0).
*/
/** @ingroup AdsFunctions */
IOCTLDEF int maAdsBannerCreate(int bannerSize, const char* publisherID) {
	return (int) maIOCtl(500, bannerSize, (int)publisherID, 0);
}

/**
* \brief Destroy a banner.
*
* \param bannerHandle Handle to a banner.
*
* \returns One of the next constants:
* - #MA_ADS_RES_OK if no error occurred.
* - #MA_ADS_RES_INVALID_BANNER_HANDLE if the banner handle is invalid.
*/
/** @ingroup AdsFunctions */
IOCTLDEF int maAdsBannerDestroy(MAHandle bannerHandle) {
	return (int) maIOCtl(501, bannerHandle, 0, 0);
}

/**
* \brief Add a banner to a layout widget.
*
* \param bannerHandle Handle to a banner.
* \param layoutHandle Handle to a layout.
*
* \returns One of the next constants:
* - #MA_ADS_RES_OK if no error occurred.
* - #MA_ADS_RES_INVALID_BANNER_HANDLE if the banner handle is invalid.
* - #MA_ADS_RES_INVALID_LAYOUT_HANDLE if the layout handle is invalid.
*/
/** @ingroup AdsFunctions */
IOCTLDEF int maAdsAddBannerToLayout(MAHandle bannerHandle, MAHandle layoutHandle) {
	return (int) maIOCtl(502, bannerHandle, layoutHandle, 0);
}

/**
* \brief Remove a banner from a layout widget.
*
* \param bannerHandle Handle to a banner.
* \param layoutHandle Handle to a layout.
*
* \returns One of the next constants:
* - #MA_ADS_RES_OK if no error occurred.
* - #MA_ADS_RES_INVALID_BANNER_HANDLE if the banner handle is invalid.
* - #MA_ADS_RES_INVALID_LAYOUT_HANDLE if the layout handle is invalid.
*/
/** @ingroup AdsFunctions */
IOCTLDEF int maAdsRemoveBannerFromLayout(MAHandle bannerHandle, MAHandle layoutHandle) {
	return (int) maIOCtl(503, bannerHandle, layoutHandle, 0);
}

/**
* \brief Set a banner property.
*
* \param bannerHandle Handle to the banner.
* \param property A string representing which property to set.
* \param value The value that will be assigned to the property.
*
* \returns One of the next result codes:
* - #MA_ADS_RES_OK if no error occurred.
* - #MA_ADS_RES_INVALID_BANNER_HANDLE if the banner handle is invalid.
* - #MA_ADS_RES_INVALID_PROPERTY_NAME if the property name is not valid.
* - #MA_ADS_RES_INVALID_PROPERTY_VALUE if the property value is not valid.
*/
/** @ingroup AdsFunctions */
IOCTLDEF int maAdsBannerSetProperty(MAHandle bannerHandle, const char* property, const char* value) {
	return (int) maIOCtl(504, bannerHandle, (int)property, (int)value);
}

/**
* \brief Retrieves a specified property from the given banner.
*
* \param bannerHandle Handle to the banner.
* \param property A string representing for which property to get the value.
* \param value A buffer that will hold the value of the property, represented as a string.
* \param bufSize Size of the buffer.
*
* \returns One of the next result codes:
* - #MA_ADS_RES_OK if no error occurred.
* - #MA_ADS_RES_INVALID_BANNER_HANDLE if the banner handle is invalid.
* - #MA_ADS_RES_INVALID_PROPERTY_NAME if the property name is not valid.
* - #MA_ADS_RES_INVALID_STRING_BUFFER_SIZE if the buffer size was to small.
*/
/** @ingroup AdsFunctions */
IOCTLDEF int maAdsBannerGetProperty(MAHandle bannerHandle, const char* property, char* value, int bufSize) {
	return (int) maIOCtl(505, bannerHandle, (int)property, (int)value, bufSize);
}

/**
* \brief Creates a new local notification object.
*
* \returns
*  - #MA_NOTIFICATION_RES_UNSUPPORTED if the notifications are not supported on current system.
*  - #MA_NOTIFICATION_RES_ERROR if a error occurred while creating the notification object.
*  - a handle to a new local notification object(the handle value is >= 0).
*/
/** @ingroup NotificationFunctions */
IOCTLDEF MAHandle maNotificationLocalCreate(void) {
	return (MAHandle) maIOCtl(506, 0, 0, 0);
}

/**
* \brief Destroy a local notification object.
*
* \param notificationHandle Handle to a local notification object.
*
* \returns One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_INVALID_HANDLE if the notificationHandle is invalid.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationLocalDestroy(MAHandle notificationHandle) {
	return (int) maIOCtl(507, notificationHandle, 0, 0);
}

/**
* \brief Set a local notification property.
*
* \param notificationHandle Handle to the local notification object.
* \param property A string representing which property to set.
* \param value The value that will be assigned to the property.
*
* \returns One of the next result codes:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_INVALID_HANDLE if the notificationHandle is invalid.
* - #MA_NOTIFICATION_RES_INVALID_PROPERTY_NAME if the property name is not valid.
* - #MA_NOTIFICATION_RES_INVALID_PROPERTY_VALUE if the property value is not valid.
* - #MA_NOTIFICATION_RES_ALREADY_SCHEDULED if the notification is scheduled.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationLocalSetProperty(MAHandle notificationHandle, const char* property, const char* value) {
	return (int) maIOCtl(508, notificationHandle, (int)property, (int)value);
}

/**
* \brief Retrieves a specified property from the given notification object.
*
* \param notificationHandle Handle to the notification object.
* \param property A string representing for which property to get the value.
* \param value A buffer that will hold the value of the property, represented as a string.
* \param bufSize Size of the buffer.
*
* \returns One of the next result codes:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_INVALID_HANDLE if the notificationHandle is invalid.
* - #MA_NOTIFICATION_RES_INVALID_PROPERTY_NAME if the property name is not valid.
* - #MA_NOTIFICATION_RES_INVALID_STRING_BUFFER_SIZE if the buffer size was to small.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationLocalGetProperty(MAHandle notificationHandle, const char* property, char* value, int bufSize) {
	return (int) maIOCtl(509, notificationHandle, (int)property, (int)value, bufSize);
}

/**
* \brief Schedules a local notification for delivery at its encapsulated date and time.
* The local notification is displayed regardless of the applications's state.
* By default, the notifications are displayed to the user only if the application is
* in background. But on Android you can configure this by setting the
* #MA_NOTIFICATION_LOCAL_DISPLAY_FLAG property.
*
* \param notificationHandle Handle to a local notification object.
*
* \returns One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_INVALID_HANDLE if the notificationHandle is invalid.
* - #MA_NOTIFICATION_RES_ALREADY_SCHEDULED if the notification was already scheduled.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationLocalSchedule(MAHandle notificationHandle) {
	return (int) maIOCtl(510, notificationHandle, 0, 0);
}

/**
* \brief Cancels the delivery of the specified scheduled local notification.
* Calling this method also programmatically dismisses the notification if
* it is currently displaying an alert.
*
* \param notificationHandle Handle to a local notification object.
*
* \returns One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_INVALID_HANDLE if the notificationHandle is invalid.
* - #MA_NOTIFICATION_RES_CANNOT_UNSCHEDULE if the notification was not scheduled.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationLocalUnschedule(MAHandle notificationHandle) {
	return (int) maIOCtl(511, notificationHandle, 0, 0);
}

/**
* \brief Registers the current application for receiving push notifications.
* Note that on Android you might want to store the registrationID that you receive,
* and call this again only if it expires at some point.
* On Android: if the registration is succesfful, the application receives a registration ID.
* The application should store this ID for later use. Note that Google may periodically refresh
* the registration ID, so you should design your application with the understanding that this
* syscall  may be called multiple times.
* \param pushNotificationTypes A bit mask specifying the types of notifications
* the application accepts.
* See \link #MA_NOTIFICATION_PUSH_TYPE_BADGE MA_NOTIFICATION_PUSH_TYPE_ \endlink
* for valid bit-mask values.
* On Android platform this param is ignored.
* \param senderId Your projectId obtained from here:
* http://developer.android.com/guide/google/gcm/gs.html#create-proj
* For old applications, this param was set as the ID of the account
* authorized to send messages to the application, typically the email
* address of an account set up by the application's developer.
* Even though setting the senderId as the accountID was deprecated, old
* Android applications still support it.
* On iOS platform this param is ignored.
*
* Example: maNotificationPushRegister(
* PUSH_NOTIFICATION_TYPE_BADGE | PUSH_NOTIFICATION_TYPE_ALERT, "yoursenderId_here");
*
* \returns One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_ALREADY_REGISTERED if the application is already registered for
* receiving push notifications.
* - #MA_NOTIFICATION_RES_UNSUPPORTED if notifications are not supported on current platform.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushRegister(MAHandle pushNotificationTypes, const char* senderId) {
	return (int) maIOCtl(512, pushNotificationTypes, (int)senderId, 0);
}

/**
* \brief Unregister application for push notifications.
*
* \returns One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_NOT_REGISTERED if the application was not registered for receiving
* push notification.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushUnregister(void) {
	return (int) maIOCtl(513, 0, 0, 0);
}

/**
* \brief Gets the latest push notification registration response.
* \param registrationMesssage The registrationID if the registration was successfull, or the error messsage otherwise.
* \param registrationMessageSize Size of the buffer.
* \returns  One of the next constants:
* - #MA_NOTIFICATION_RES_OK if the application registered successfully.
* - #MA_NOTIFICATION_RES_REGISTRATION_NOT_CALLED if maNotificationPushRegister was not called.
* - #MA_NOTIFICATION_RES_REGISTRATION_MESSAGE_BUF_TOO_SMALL if the buffer is too small.
* - #MA_NOTIFICATION_RES_ERROR if registration has failed.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushGetRegistration(char* registrationMesssage, int registrationMessageSize) {
	return (int) maIOCtl(514, (int)registrationMesssage, registrationMessageSize, 0);
}

/**
* \brief Fills pushNotificationData struct with the values for a given push notification.
* Note: Call maNotificationPushDestroy() in order to destroy the push notification object.
*
* \param pushNotificationHandle Handle to a given push notification.
* \param pushNotificationData A struct that will contain the values for a given push notification.
*
* \return One of the next contants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_INVALID_HANDLE if the pushNotificationHandle is invalid.
* - #MA_NOTIFICATION_RES_INVALID_STRING_BUFFER_SIZE if at least one of the buffers from
* pushNotificationData are too small.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushGetData(MAHandle pushNotificationHandle, MAPushNotificationData* pushNotificationData) {
	return (int) maIOCtl(515, pushNotificationHandle, (int)pushNotificationData, 0);
}

/**
* \brief Destroy a push notification object.
*
* \param notificationHandle Handle to a push notification object.
*
* \returns One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_INVALID_HANDLE if the notificationHandle is invalid.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushDestroy(MAHandle notificationHandle) {
	return (int) maIOCtl(516, notificationHandle, 0, 0);
}

/**
* \brief Set the number currently set as the badge of the application icon in Springboard.
* Platform: iOS only.
*
*\param applicationIconBadgeNumber Set to zero to hide the badge number. The default is zero.
* If this value is negative the syscall will do nothing.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF void maNotificationSetIconBadge(int applicationIconBadgeNumber) {
	(void) maIOCtl(517, applicationIconBadgeNumber, 0, 0);
}

/**
* \brief Get the number currently set as the badge of the application icon in Springboard.
* Platform: iOS only.
*
*\return The number displayed as the badge of the application.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationGetIconBadge(void) {
	return (int) maIOCtl(518, 0, 0, 0);
}

/**
* \brief Set the ticker text in the notification status bar for incoming push notifications.
* This call does not alter already received notifications.
* Platform: Android only.
*
* \param tickerText The text that flows by in the status bar when the notification first activates.
* \return One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_ERROR.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushSetTickerText(const char* tickerText) {
	return (int) maIOCtl(519, (int)tickerText, 0, 0);
}

/**
* \brief Set the  message title in the notification area for incoming push notifications.
* This call does not alter already received notifications.
* Platform: Android only.
*
* \param messageTitle The title that goes in the expanded entry of the notification.
* \return One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_ERROR.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushSetMessageTitle(const char* messageTitle) {
	return (int) maIOCtl(520, (int)messageTitle, 0, 0);
}

/**
* \brief Set the display flags applied to the incoming push notifications.
* Note that regardless of this setting, the #EVENT_TYPE_PUSH_NOTIFICATION event
* will be received for each incoming notification.
* #MA_NOTIFICATION_DISPLAY_FLAG_DEFAULT is enabled by default.
* Platform: Android only.
* \param displayFlag One of the constants:
* - #MA_NOTIFICATION_DISPLAY_FLAG_DEFAULT Which is enabled by default.
* - #MA_NOTIFICATION_DISPLAY_FLAG_ANYTIME.
* \return One of the next constants:
* - #MA_NOTIFICATION_RES_OK if no error occurred.
* - #MA_NOTIFICATION_RES_ERROR if push notifications are not supported,
* or the input value is not valid.
*/
/** @ingroup NotificationFunctions */
IOCTLDEF int maNotificationPushSetDisplayFlag(int displayFlag) {
	return (int) maIOCtl(521, displayFlag, 0, 0);
}

/**
* \brief Sets the properties to the Native Image Picker.
* \param property A string representing which property to set.
*  One of the \link #MA_CAPTURE_VIDEO_QUALITY MA_CAPTURE \endlink constants.
* \param value The value that will be assigned to the property.
*
* \returns One of the next constants:
*  - #MA_CAPTURE_RES_OK if no error occurred.
*  - #MA_CAPTURE_RES_INVALID_PROPERTY if the property name is not valid.
*  - #MA_CAPTURE_RES_INVALID_PROPERTY_VALUE if the property value is not valid.
*  - #MA_CAPTURE_RES_MAX_DURATION_NOT_SUPPORTED if the duration limit is not supported ( Android only).
*/
/** @ingroup CaptureFunctions */
IOCTLDEF int maCaptureSetProperty(const char* property, const char* value) {
	return (int) maIOCtl(522, (int)property, (int)value, 0);
}

/**
* \brief Retrieves the properties from the Native Image Picker.
*
* \param property A string representing which property to get.
*  One of the \link #MA_CAPTURE_VIDEO_QUALITY MA_CAPTURE \endlink constants.
* \param value A buffer that will hold the value of the property, represented as a string.
* \param bufSize Size of the buffer.
*
* \returns One of the next constants:
* - #MA_CAPTURE_RES_OK if no error occurred.
* - #MA_CAPTURE_RES_INVALID_PROPERTY if the property name is not valid.
* - #MA_CAPTURE_RES_INVALID_STRING_BUFFER_SIZE if the buffer size was to small.
* - #MA_CAPTURE_RES_PROPERTY_VALUE_UNDEFINED if the property was not previously set ( Android only).
* - #MA_CAPTURE_RES_MAX_DURATION_NOT_SUPPORTED if the duration limit is not supported ( Android only).
*/
/** @ingroup CaptureFunctions */
IOCTLDEF int maCaptureGetProperty(const char* property, char* value, int bufSize) {
	return (int) maIOCtl(523, (int)property, (int)value, bufSize);
}

/**
* \brief Performs a capture action.
*
* The specified action is performed and the result is delivered
* asynchronously in an \link #EVENT_TYPE_CAPTURE event. The content
* of the event is an #MACaptureEventData data structure. The type
* field contains the type of capture event (#MA_CAPTURE_EVENT_TYPE_IMAGE,
* #MA_CAPTURE_EVENT_TYPE_VIDEO, #MA_CAPTURE_EVENT_TYPE_CANCEL), and the
* handle field contains a handle to the capture object. Save a
* captured image using function #maCaptureWriteImage. Access a
* captured video using function #maCaptureGetVideoPath. Free the capture
* object using function #maCaptureDestroyData.
*
* Note: The image format for #MA_CAPTURE_EVENT_TYPE_IMAGE is JPEG on Android
* and PNG on iOS.
*
* Platforms: Android an iOS.
*
* \param action One of the \link #MA_CAPTURE_ACTION_TAKE_PICTURE MA_CAPTURE_ACTION \endlink constants.
*
* \returns One of the next constants:
*  - #MA_CAPTURE_RES_OK if no error occurred.
*  - #MA_CAPTURE_RES_INVALID_ACTION if the given action is invalid.
*  - #MA_CAPTURE_RES_CAMERA_NOT_AVAILABLE if camera is not available at the moment.
*  - #MA_CAPTURE_RES_VIDEO_NOT_SUPPORTED if video recording is not supported.
*  - #MA_CAPTURE_RES_PICTURE_NOT_SUPPORTED if camera picture mode is not supported.
*/
/** @ingroup CaptureFunctions */
IOCTLDEF int maCaptureAction(int action) {
	return (int) maIOCtl(524, action, 0, 0);
}

/**
* \brief Save a image data object to a file.
* \param handle Handle to an image data object.
* \param fullPath A buffer containing the a full path where the file will be created.
* \param fullPathBufSize The size of the fullPath buffer.
*
* \returns One of the next constants:
*  - #MA_CAPTURE_RES_OK if no error occurred.
*  - #MA_CAPTURE_RES_INVALID_HANDLE if the given handle was invalid.
*  - #MA_CAPTURE_RES_FILE_INVALID_NAME if the fullPath param is invalid.
*  - #MA_CAPTURE_RES_FILE_ALREADY_EXISTS if the file already exists.
*/
/** @ingroup CaptureFunctions */
IOCTLDEF int maCaptureWriteImage(MAHandle handle, const char* fullPath, int fullPathBufSize) {
	return (int) maIOCtl(525, handle, (int)fullPath, fullPathBufSize);
}

/**
* \brief Get full path to a taken picture.
* Available on Android only.
* \param handle Handle to an image data object.
* \param buffer Will contain the full path of the image file.
* \param bufferSize Maximum size of the buffer.
*
* \returns One of the next constants:
*  - #MA_CAPTURE_RES_OK if no error occurred.
*  - #MA_CAPTURE_RES_INVALID_HANDLE if the given handle was invalid.
*  - #MA_CAPTURE_RES_INVALID_STRING_BUFFER_SIZE if the buffer size was to small.
*/
/** @ingroup CaptureFunctions */
IOCTLDEF int maCaptureGetImagePath(MAHandle handle, char* buffer, int bufferSize) {
	return (int) maIOCtl(526, handle, (int)buffer, bufferSize);
}

/**
* \brief Get full path to a recorded video.
* \param handle Handle to a video data object.
* \param buffer Will contain the full path to the video file.
* \param bufferSize Maximum size of the buffer.
*
* \returns One of the next constants:
*  - #MA_CAPTURE_RES_OK if no error occurred.
*  - #MA_CAPTURE_RES_INVALID_HANDLE if the given handle was invalid.
*  - #MA_CAPTURE_RES_INVALID_STRING_BUFFER_SIZE if the buffer size was to small.
*/
/** @ingroup CaptureFunctions */
IOCTLDEF int maCaptureGetVideoPath(MAHandle handle, char* buffer, int bufferSize) {
	return (int) maIOCtl(527, handle, (int)buffer, bufferSize);
}

/**
* \brief Destroys a image/video data object.
* \param handle Handle to a image/video data object.
*
* \returns One of the next constants:
*  - #MA_CAPTURE_RES_OK if no error occurred.
*  - #MA_CAPTURE_RES_INVALID_HANDLE if the given handle was invalid.
*/
/** @ingroup CaptureFunctions */
IOCTLDEF int maCaptureDestroyData(MAHandle handle) {
	return (int) maIOCtl(528, handle, 0, 0);
}

/**
* \brief Check if in app purchase is supported/enabled on a device.
* It does not trigger any asynchronous responses.
* Platform: Android and iOS.
*
* \returns One of the next result codes:
* - #MA_PURCHASE_RES_OK if purchase is supported/allowed on the device.
* - #MA_PURCHASE_RES_DISABLED if purchase is not allowed/enabled.
* - #MA_PURCHASE_RES_UNAVAILABLE if purchase is not supported on the device.
* - #MA_PURCHASE_RES_OUT_OF_DATE if GooglePlay application is out of date.
* - #MA_PURCHASE_RES_CONNECTION_ERROR if there was an error connecting with the GooglePlay application.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF int maPurchaseSupported(void) {
	return (int) maIOCtl(529, 0, 0, 0);
}

/**
* \brief Create a product object asynchronously.
* The product is validated only on iOS. On the other hand, on Android the validation
* will be done during a maPurchaseRequest.
*
* A #EVENT_TYPE_PURCHASE will be sent after calling this syscall.
* The event will contain a MAPurchaseEventData struct object. The type member object
* contained by the struct will be #MA_PURCHASE_EVENT_PRODUCT_CREATE. The state member
* object can have one of the following values:
* - #MA_PURCHASE_STATE_PRODUCT_VALID
*	- on iOS if the product was validated by the App Store,
*	- on Android if the product was validated on Google Play.
    * - #MA_PURCHASE_STATE_PRODUCT_INVALID the product is not valid.
    * - #MA_PURCHASE_STATE_DISABLED purchase is not supported/disabled on the device.
    * - #MA_PURCHASE_STATE_DUPLICATE_HANDLE the given productHandle already exists.
* Use #maCreatePlaceholder() to generate a new one.
*
* \param productHandle A valid handle that will be used to indetify the new product.
* It must be unique. It is highly recommended to create it using #maCreatePlaceholder().
* \param productID String that identifies the product. This string must be used by the
* App Store / Google Play to identify the product.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF void maPurchaseCreate(MAHandle productHandle, const char* productID) {
	(void) maIOCtl(530, productHandle, (int)productID, 0);
}

/**
* Set your Google Play public key to the application. This enables the application
* to verify the signature of the transaction information that is returned from Google Play.
* Must be set in order to be able to request purchases.
* Platform: Android.
*
* \param developerPublicKey Base64-encoded public key, that can be found on the Google
* Play publisher account page, under Licensing & In-app Billing panel in Edit Profile.
*
* \returns One of the next result codes:
* - #MA_PURCHASE_RES_OK if the key was set.
* - #MA_PURCHASE_RES_MALFORMED_PUBLIC_KEY if the key is invalid.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF int maPurchaseSetPublicKey(const char* developerPublicKey) {
	return (int) maIOCtl(531, (int)developerPublicKey, 0, 0);
}

/**
* Request the user to purchase a product.
* The system will handle the proccess of purchasing.
* Note: if there are other requests in progress, the requests will be queued.
* If the product is restored on iOS platform it cannot be purchased again.
*
* A #EVENT_TYPE_PURCHASE will be sent after calling this syscall.
* The event will contain a MAPurchaseEventData struct object. The type member object
* contained by the struct is #MA_PURCHASE_EVENT_REQUEST. The state member object can
* have one of the following values:
    * - #MA_PURCHASE_STATE_DISABLED purchase is not supported/disabled on the device.
* - #MA_PURCHASE_STATE_FAILED if the operation has failed. Check the errorCode member object
* for more information about the reason.
* - #MA_PURCHASE_STATE_IN_PROGRESS indicates that the transaction has been received by
* the App Store / Google Play.
* - #MA_PURCHASE_STATE_COMPLETED indicates that the transaction has been successfully processed.
*
* \param productHandle Handle to the product to be purchased.
* \param quantity How many products to be purchased. Must be a value greater than zero.
* This param is ignored on Android, as any purchase request can handle only one item.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF void maPurchaseRequest(MAHandle productHandle, int quantity) {
	(void) maIOCtl(532, productHandle, quantity, 0);
}

/**
* Verify if the receipt came from Apple App Store / Google Play.
* Make sure that the product is purchased before calling this syscall.
*
* A #EVENT_TYPE_PURCHASE will be sent after calling this syscall.
* The event will contain a MAPurchaseEventData struct object. The type member object
* contained by the struct is #MA_PURCHASE_EVENT_VERIFY_RECEIPT .The state member object
* can have one of the following values:
    * - #MA_PURCHASE_STATE_DISABLED purchase is not supported/disabled on the device.
* - #MA_PURCHASE_STATE_RECEIPT_VALID indicates that the transaction has been validated
* by the App Store / Google Play.
* - #MA_PURCHASE_STATE_RECEIPT_INVALID indicates that the transaction is invalid.
* - #MA_PURCHASE_STATE_RECEIPT_ERROR indicates that an error occurred while verifying
* the receipt. Check the errorCode member object for more information about the reason.
    *
* \param productHandle Handle to the product that has been purchased.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF void maPurchaseVerifyReceipt(MAHandle productHandle) {
	(void) maIOCtl(533, productHandle, 0, 0);
}

/**
* Get a field value contained by the receipt.
* Make sure that the given product has a valid receipt.
* Call the maPurchaseVerifyReceipt() syscall and wait for a #MA_PURCHASE_STATE_RECEIPT_VALID
* purchase state.
*
* \param productHandle Handle to the product that has been purchased.
* \param property The name of the field.
* \param buffer Will be filled with the filed value.
* \param bufferSize The maximum size of the buffer, in bytes.
* \return The number of written bytes into buffer(a value greater than zero), or one
* of the following error codes(a value smaller that zero):
* - #MA_PURCHASE_RES_INVALID_HANDLE if the productHandle is invalid.
* - #MA_PURCHASE_RES_RECEIPT_NOT_AVAILABLE if the product has not been purchased.
* - #MA_PURCHASE_RES_DISABLED if purchase is not allowed/enabled.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF int maPurchaseGetField(MAHandle productHandle, const char* property, char* buffer, int bufferSize) {
	return (int) maIOCtl(534, productHandle, (int)property, (int)buffer, bufferSize);
}

/**
* Set the store url used for verifing the receipe on iOS platform.
* Platform: iOS.
* \param url Store url.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF void maPurchaseSetStoreURL(const char* url) {
	(void) maIOCtl(535, (int)url, 0, 0);
}

/**
* Get product id using a product handle.
*
* \param productHandle Handle to the given product.
* \param buffer Will contain the product id.
* \param bufferSize Maximum size of the buffer.
* \return In case of error:
* - #MA_PURCHASE_RES_INVALID_HANDLE if productHandle is invalid.
* - #MA_PURCHASE_RES_BUFFER_TOO_SMALL if the given handle is too small.
* In case of success returns the number of written bytes.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF int maPurchaseGetName(MAHandle productHandle, char* buffer, int bufferSize) {
	return (int) maIOCtl(536, productHandle, (int)buffer, bufferSize);
}

/**
* Restore transactions that were previously finished so that you can process them again.
* For example, your application would use this to allow a user to unlock previously purchased
* content onto a new device.
*
* A #EVENT_TYPE_PURCHASE will be sent after calling this syscall.
* The event will contain a #MAPurchaseEventData struct object. The type member object
* contained by the struct will be #MA_PURCHASE_EVENT_RESTORE. The state member object
* can have one of the following values:
    * - #MA_PURCHASE_STATE_RESTORE_ERROR indicates that an error ocurred while restoring the
    * products. Check the struct errorCode member object to see why it failed.
* - #MA_PURCHASE_STATE_PRODUCT_RESTORED indicates that a product has been restored.
* The productHandle member object will contain a handle to the new product.
* Make sure you destroy the product and after done working with it.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF void maPurchaseRestoreTransactions(void) {
	(void) maIOCtl(537, 0, 0, 0);
}

/**
* Destroy a product object.
*
* \param productHandle Handle to the product to destroy.
* \return One of the following values:
* - #MA_PURCHASE_RES_OK if product has been detroyed.
* - #MA_PURCHASE_RES_INVALID_HANDLE if the productHandle is invalid.
*/
/** @ingroup PurchaseFunctions */
IOCTLDEF int maPurchaseDestroy(MAHandle productHandle) {
	return (int) maIOCtl(538, productHandle, 0, 0);
}

/**
 * @deprecated Use #maScreenSetSupportedOrientations instead.
 * Set the screen orientation.
 * Currently implemented only on Android and Windows Phone.
 * @param orientation One of the \link #SCREEN_ORIENTATION_LANDSCAPE
 * #SCREEN_ORIENTATION_PORTRAIT #SCREEN_ORIENTATION_DYNAMIC \endlink
 * constants.
 * @return \< 0 on error.
 */
/** @ingroup OrientationFunctions */
IOCTLDEF int maScreenSetOrientation(int orientation) {
	return (int) maIOCtl(539, orientation, 0, 0);
}

/**
* Set supported screen orientations.
* Currently implemented on iOS, WindowsPhone 7.1 and Android.
* @param orientations A bitmask consisting of flags describing the supported screen orientations.
* The bitmask can be created using \link #MA_SCREEN_ORIENTATION_PORTRAIT MA_SCREEN_ORIENTATION \endlink
* values.
* @return One of the next constants:
* - #MA_SCREEN_ORIENTATION_RES_OK
* - #MA_SCREEN_ORIENTATION_RES_NOT_SUPPORTED
* - #MA_SCREEN_ORIENTATION_RES_INVALID_VALUE
*/
/** @ingroup OrientationFunctions */
IOCTLDEF int maScreenSetSupportedOrientations(int orientations) {
	return (int) maIOCtl(540, orientations, 0, 0);
}

/**
* Get supported screen orientations.
* Currently implemented on iOS, WindowsPhone 7.1 and Android.
* @return A bitmask consisting of flags describing the supported screen orientations.
* The bitmask is created using \link #MA_SCREEN_ORIENTATION_PORTRAIT MA_SCREEN_ORIENTATION \endlink
* values.
*/
/** @ingroup OrientationFunctions */
IOCTLDEF int maScreenGetSupportedOrientations(void) {
	return (int) maIOCtl(541, 0, 0, 0);
}

/**
* Get current screen orientation.
* Currently implemented on iOS, WindowsPhone 7.1 and Android.
* @return One of the \link #MA_SCREEN_ORIENTATION_PORTRAIT MA_SCREEN_ORIENTATION \endlink constants.
*/
/** @ingroup OrientationFunctions */
IOCTLDEF int maScreenGetCurrentOrientation(void) {
	return (int) maIOCtl(542, 0, 0, 0);
}

#ifdef __cplusplus
}
#endif

#ifndef MAPIP
#undef memset
#undef memcpy
#endif	//MAPIP

#endif	//MAAPI_H
