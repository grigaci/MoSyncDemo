// File: mosync-constants.js.
// This is a generated file, do not edit.

// Start of JavaScript constants.

/**
* @brief Sets if the indicator is still on or off.
* If set to false, it doesn't delete the widget just dismisses it.
* @validvalue A boolean string 'true' or 'false'.
*
* @setonly
*
* @par Example
* \code
*	// The activity is done. Now this widget is dismissed.
*	maWidgetSetProperty(activityIndicatorHandle, MAW_ACTIVITY_INDICATOR_IN_PROGRESS, "false");
* \endcode
*/
mosync.MAW_ACTIVITY_INDICATOR_IN_PROGRESS = "inProgress";

/**
* @brief Sets or gets the text that is displayed in the label.
*
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example set
* \code
*	maWidgetSetProperty(buttonHandle, MAW_BUTTON_TEXT, "My button");
* \endcode
*
* @par Example get
* \code
*	char textBuffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(buttonHandle, MAW_BUTTON_TEXT, textBuffer, BUFFER_SIZE);
*	if (result > 0)
*	{
*	// Do something with the label text.
*	}
* \endcode
*/
mosync.MAW_BUTTON_TEXT = "text";

/**
* @brief Sets the vertical alignment of the text inside the button. If the widget's height is WRAP_CONTENT this property has no effect.
*
* @validvalue One of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(buttonHandle, MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_BUTTON_TEXT_VERTICAL_ALIGNMENT = "textVerticalAlignment";

/**
* @brief Sets the horizontal alignment of the text inside the button. If the widget's width is WRAP_CONTENT this property has no effect.
*
* @validvalue Takes one of the constants #MAW_ALIGNMENT_LEFT, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_RIGHT.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(buttonHandle, MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_BUTTON_TEXT_HORIZONTAL_ALIGNMENT = "textHorizontalAlignment";

/**
* @brief Sets the font color of the button's text.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(buttonHandle, MAW_BUTTON_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_BUTTON_FONT_COLOR = "fontColor";

/**
* @brief Sets the font size in points of the button's text.
*
* @validvalue A float that specifies the number of pixels on Android
* and WP7, and number of points on iOS.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(buttonHandle, MAW_BUTTON_FONT_SIZE, "13.0");
* \endcode
*/
mosync.MAW_BUTTON_FONT_SIZE = "fontSize";

/**
* @brief Sets the typeface and style in which the text should be displayed.
*
* @validvalue A font handle received from loading fonts using
* #maFontGetName and #maFontLoadWithName syscalls.
*
* @setonly
*
* @par Example
* \code
*	int nrFonts = maFontGetCount();
*	 char buf[256];
*	 // Get first font name.
*	 maFontGetName(1, buf, 256);
*	 // Load that font for size 10.
*	 int fontHandle = maFontLoadWithName(buf, 10);
*	 // Set that font to the label.
*	maWidgetSetProperty(buttonHandle, MAW_BUTTON_FONT_HANDLE, toString(fontHandle));
* \endcode
*/
mosync.MAW_BUTTON_FONT_HANDLE = "fontHandle";

/**
* @brief Set or get the checked state of the checkbox.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @par Example
* \code
*	maWidgetSetProperty(checkBoxHandle, MAW_CHECK_BOX_CHECKED, "true");
* \endcode
*/
mosync.MAW_CHECK_BOX_CHECKED = "checked";

/**
* @brief Sets or gets the custom picker items row height in pixels.
* All its items should have the same height.
* Should be set before the widget is drawn on the screen.
* Default value it's the height of the widget.
* Platform: iOS and Android.
* @validvalue A positive integer value.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(customPickerHandle, MAW_CUSTOM_PICKER_ROW_HEIGHT, "30");
* \endcode
*/
mosync.MAW_CUSTOM_PICKER_ROW_HEIGHT = "rowHeight";

/**
* @brief Sets or gets the custom picker items row width in pixels.
* All its items should have the same width.
* Should be set before the widget is drawn on the screen.
* Platform: iOS and Android.
* @validvalue A positive integer value.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(customPickerHandle, MAW_CUSTOM_PICKER_ROW_WIDTH, "100");
* \endcode
*/
mosync.MAW_CUSTOM_PICKER_ROW_WIDTH = "rowWidth";

/**
* @brief Reload all its items.
* Platform: iOS.
*
* @validvalue Empty string.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(customPickerHandle, MAW_CUSTOM_PICKER_RELOAD_DATA, "");
* \endcode
*/
mosync.MAW_CUSTOM_PICKER_RELOAD_DATA = "reloadData";

/**
* @brief Show/hide the selection indicator.
* Platform: iOS.
*
* @validvalue A boolean string 'true' for displaying hte indicator, 'false' otherwise.
* Default value is 'false'.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(customPickerHandle, MAW_CUSTOM_PICKER_SELECTION_INDICATOR, "true");
* \endcode
*/
mosync.MAW_CUSTOM_PICKER_SELECTION_INDICATOR = "selectionIndicator";

/**
* @brief Sets of gets the selected item.
* Platform: iOS and Android.
*
* @validvalue A positive integer that represents the index of the item.
* By default the first item is selected and it has index zero.
* If the widget has no children, #MAW_RES_ERROR will be returned.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(customPickerHandle, MAW_CUSTOM_PICKER_SELECTED_ITEM_INDEX, "1");
* \endcode
*/
mosync.MAW_CUSTOM_PICKER_SELECTED_ITEM_INDEX = "selectedItemIndex";

/**
* @deprecated use MAX_DATE_YEAR, MAX_DATE_MONTH and MAX_DATE_DAY instead
* @brief Sets or gets  maximal date supported by this DatePicker in seconds since January 1, 1970 00:00:00.
* NOTE: On Android the default maximal date is 12/31/2100.
* NOTE: The property can be set on iOS only.
* @validvalue A long int that specifies the upper range of this date picker.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MAX_DATE, "1291939200");
*	// Now the maximum date isthe 10th of December 2010.
* \endcode
*/
mosync.MAW_DATE_PICKER_MAX_DATE = "maxDate";

/**
* @brief Sets or gets the year of the maximal date supported by this DatePicker.
* Note: On Android the default maximal date year is 2100.
* Note: On Windows Phone 7 and iOS the default maximal date year is 9999.
* @validvalue An int that specifies the value of the year of the maximal date
* for this date picker.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MAX_DATE_YEAR, "2999");
* \endcode
*/
mosync.MAW_DATE_PICKER_MAX_DATE_YEAR = "maxdateyear";

/**
* @brief Sets or gets the month of the maximal date supported by this DatePicker.
* @validvalue An int that specifies the value of the month of the maximal date for
* this date picker. The value must be a number between 1 and 12.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MAX_DATE_MONTH, "12");
* \endcode
*/
mosync.MAW_DATE_PICKER_MAX_DATE_MONTH = "maxdatemonth";

/**
* @brief Sets or gets the day of the maximal date supported by this DatePicker.
* @validvalue An int that specifies the value of the day of the maximal date for
* this date picker. This number must be a valid day of the month specified with
* the MAX_DATE_MONTH property.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MAX_DATE_DAY, "31");
* \endcode
*/
mosync.MAW_DATE_PICKER_MAX_DATE_DAY = "maxdateday";

/**
* @deprecated use MIN_DATE_YEAR, MIN_DATE_MONTH and MIN_DATE_DAY instead
* @brief Sets or gets  minimal date supported by this DatePicker in seconds since January 1, 1970 00:00:00
* Note: On Android the default minimal date is 01/01/1900.
* @validvalue A long int that specifies the minimal supported date.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MIN_DATE, "946684800");
*	// Now the minimum date is the 1st of January 2000.
* \endcode
*/
mosync.MAW_DATE_PICKER_MIN_DATE = "minDate";

/**
* @brief Sets or gets the year of the minimal date supported by this DatePicker.
* Note: On Android the default minimal date year  is 1900.
* Note: On Windows Phone 7 and iOS the default minimal date year is 1.
* @validvalue An int that specifies the value of the year of the minimal date
* for this date picker.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MIN_DATE_YEAR, "1830");
* \endcode
*/
mosync.MAW_DATE_PICKER_MIN_DATE_YEAR = "mindateyear";

/**
* @brief Sets or gets the month of the minimal date supported by this DatePicker.
* @validvalue An int that specifies the value of the month of the minimal date for
* this date picker. The value must be a number between 1 and 12.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MIN_DATE_MONTH, "1");
* \endcode
*/
mosync.MAW_DATE_PICKER_MIN_DATE_MONTH = "mindatemonth";

/**
* @brief Sets or gets the day of the minimal date supported by this DatePicker.
* @validvalue An int that specifies the value of the day of the minimal date for
* this date picker. This number must be a valid day of the month specified with
* the MIN_DATE_MONTH property.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(datePickerHandle, MAW_DATE_PICKER_MIN_DATE_DAY, "1");
* \endcode
*/
mosync.MAW_DATE_PICKER_MIN_DATE_DAY = "mindateday";

/**
* @brief Sets or gets the currently displayed year.
*
* @validvalue An int that specifies a valid year.
*
* @setandget
*
* @par Example
* \code
*	char yearBuffer[BUFFER_SIZE];
*	int getStatus = maWidgetGetProperty(datePickerHandle, MAW_DATE_PICKER_YEAR, yearBuffer, BUFFER_SIZE);
*	if(getStatus == MAW_RES_OK)
*	{
*	// Do something with the year.
*	}
* \endcode
*/
mosync.MAW_DATE_PICKER_YEAR = "year";

/**
* @brief Sets or gets the currently displayed month.
*
* @validvalue An int that specifies a valid month.
*
* @setandget
*
* @par Example
* \code
*	char monthBuffer[BUFFER_SIZE];
*	int getStatus = maWidgetGetProperty(datePickerHandle, MAW_DATE_PICKER_MONTH, monthBuffer, BUFFER_SIZE);
*	if(getStatus == MAW_RES_OK)
*	{
*	// Do something with the month.
*	}
* \endcode
*/
mosync.MAW_DATE_PICKER_MONTH = "month";

/**
* @brief Sets or gets the currently displayed day of month.
*
* @validvalue An int that specifies a valid day of month.
*
* @setandget
*
* @par Example
* \code
*	char dayBuffer[BUFFER_SIZE];
*	int getStatus = maWidgetGetProperty(datePickerHandle, MAW_DATE_PICKER_DAY_OF_MONTH, dayBuffer, BUFFER_SIZE);
*	if(getStatus == MAW_RES_OK)
*	{
*	// Do something with the day.
*	}
* \endcode
*/
mosync.MAW_DATE_PICKER_DAY_OF_MONTH = "dayOfMonth";

/**
* The input text will be single line.
* Default value.
* Platform: iOS.
*/
mosync.MAW_EDIT_BOX_MODE_SINGLE_LINE = 0;

/**
* The input text will be multi line.
* Platform: iOS.
*/
mosync.MAW_EDIT_BOX_MODE_MULTI_LINE = 1;

/**
* The user is allowed to enter any text, including line breaks.
* On iOS platform the #MAW_EDIT_BOX_MODE property must be set to
* #MAW_EDIT_BOX_MODE_MULTI_LINE in order to have a multi line edit box.
*/
mosync.MAW_EDIT_BOX_TYPE_ANY = 0;

/**
* The user is allowed to enter an e-mail address.
*/
mosync.MAW_EDIT_BOX_TYPE_EMAILADDR = 1;

/**
* The user is allowed to enter an integer value.
*/
mosync.MAW_EDIT_BOX_TYPE_NUMERIC = 2;

/**
* The user is allowed to enter a phone number.
*/
mosync.MAW_EDIT_BOX_TYPE_PHONENUMBER = 3;

/**
* The user is allowed to enter a URL.
*/
mosync.MAW_EDIT_BOX_TYPE_URL = 4;

/**
* The user is allowed to enter a real number value.
* This extends #MAW_EDIT_BOX_TYPE_NUMERIC by allowing a decimal point.
*/
mosync.MAW_EDIT_BOX_TYPE_DECIMAL = 5;

/**
* The user is allowed to enter any text, except for line breaks.
* Unavailable on some platforms.
*/
mosync.MAW_EDIT_BOX_TYPE_SINGLE_LINE = 6;

/**
* Indicates that the text entered is confidential data that should be
* obscured whenever possible. This implies #MAW_EDIT_BOX_FLAG_SENSITIVE.
* On iOS this flag works only if edit box mode is #MAW_EDIT_BOX_MODE_SINGLE_LINE.
*/
mosync.MAW_EDIT_BOX_FLAG_PASSWORD = 0;

/**
* Indicates that the text entered is sensitive data that the implementation
* must never store into a dictionary or table for use in predictive, auto-completing,
* or other accelerated input schemes. A credit card number is an example of sensitive data.
* Only for Android platform.
*/
mosync.MAW_EDIT_BOX_FLAG_SENSITIVE = 1;

/**
* This flag is a hint to the implementation that during text editing,
* the initial letter of each word should be capitalized.
* Not available on Windows Phone 7.1.
*/
mosync.MAW_EDIT_BOX_FLAG_INITIAL_CAPS_WORD = 2;

/**
* This flag is a hint to the implementation that during text editing,
* the initial letter of each sentence should be capitalized.
* Input flag not available on Windows Phone 7.1 but the edit box
* type 'ANY' does this by default.
*/
mosync.MAW_EDIT_BOX_FLAG_INITIAL_CAPS_SENTENCE = 3;

/**
* Capitalize all characters automatically.
* Not available on Windows Phone 7.1.
*/
mosync.MAW_EDIT_BOX_FLAG_INITIAL_CAPS_ALL_CHARACTERS = 4;

/**
* System's default value.
* Usually, this value it can be turned on/off from settings.
* Default value.
* Platform: iOS.
*/
mosync.MAW_EDIT_BOX_AUTOCORRECTION_TYPE_DEFAULT = 0;

/**
* Enable auto-correction behavior.
* Platform: iOS.
*/
mosync.MAW_EDIT_BOX_AUTOCORRECTION_TYPE_ENABLE = 1;

/**
* Disable auto-correction behavior.
* Platform: iOS.
*/
mosync.MAW_EDIT_BOX_AUTOCORRECTION_TYPE_DISABLE = 2;

/**
* @brief Set or get the text entered in the edit box.
*
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example set
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_TEXT, "My label");
* \endcode
*
* @par Example get
* \code
*	char textBuffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(editBoxHandle, MAW_EDIT_BOX_TEXT, textBuffer, BUFFER_SIZE);
*	if (result > 0)
*	{
*	// Do something with the edit box text
*	}
* \endcode
*/
mosync.MAW_EDIT_BOX_TEXT = "text";

/**
* @brief Set a text in the edit box that acts as a placeholder when an edit box is empty.
*
* @validvalue A null-terminated string.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_PLACEHOLDER, "Enter text...");
* \endcode
*/
mosync.MAW_EDIT_BOX_PLACEHOLDER = "placeholder";

/**
* @brief Shows or hides the virtual keyboard. If shown the focus will be set to this widget.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_SHOW_KEYBOARD, "true");
* \endcode
*/
mosync.MAW_EDIT_BOX_SHOW_KEYBOARD = "showKeyboard";

/**
* @brief Specifies what editing mode the edit box should have.
* On iOS this property works only if check box mode is #MAW_EDIT_BOX_MODE_SINGLE_LINE.
* @deprecated use #MAW_EDIT_BOX_INPUT_FLAG instead.
* @validvalue Either 'password' or 'text'.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_EDIT_MODE, "password");
* \endcode
*/
mosync.MAW_EDIT_BOX_EDIT_MODE = "editMode";

/**
* @brief Specifies what editing mode the edit box should have.
* Those flags are mutual exclusive, so the previous value is always ignored.
*
* @validvalue One of the values #MAW_EDIT_BOX_TYPE_ANY, #MAW_EDIT_BOX_TYPE_EMAILADDR,
* #MAW_EDIT_BOX_TYPE_NUMERIC, #MAW_EDIT_BOX_TYPE_PHONENUMBER, #MAW_EDIT_BOX_TYPE_URL,
* #MAW_EDIT_BOX_TYPE_DECIMAL, #MAW_EDIT_BOX_TYPE_SINGLELINE.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_INPUT_MODE, toString(MAW_EDIT_BOX_NUMERIC);
* \endcode
*/
mosync.MAW_EDIT_BOX_INPUT_MODE = "inputMode";

/**
* @brief Specifies the editing flags applied to the edit box.
* Those flags are mutual exclusive, so the previous value is always ignored.
*
* @validvalue One of the values #MAW_EDIT_BOX_FLAG_PASSWORD,
* #MAW_EDIT_BOX_FLAG_SENSITIVE, #MAW_EDIT_BOX_FLAG_INITIAL_CAPS_ALL_CHARACTERS,
* #MAW_EDIT_BOX_FLAG_INITIAL_CAPS_WORD, #MAW_EDIT_BOX_FLAG_INITIAL_CAPS_SENTENCE.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_INPUT_FLAG, toString(MAW_EDIT_BOX_FLAG_PASSWORD));
* \endcode
*/
mosync.MAW_EDIT_BOX_INPUT_FLAG = "inputFlag";

/**
* @brief Sets the font color of the edit box's text.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_EDIT_BOX_FONT_COLOR = "fontColor";

/**
* @brief Set the number of lines.
* Makes the edit box exactly this many lines tall. Note that setting this value
* overrides any other (minimum / maximum) number of lines or height setting.
* A single line edit box will set this value to 1.
* This property will automatically set MAW_EDIT_BOX_TYPE_ANY input mode, so that
* the edit box will become multiline.
* Available on Android only.
*
* @validvalue A positive integer.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_LINES_NUMBER, "2");
* \endcode
*/
mosync.MAW_EDIT_BOX_LINES_NUMBER = "linesNumber";

/**
* @brief Makes the edit box at most this many lines tall.
* Setting this value overrides any other (maximum) height setting.
* Available on Android only.
*
* @validvalue A positive integer.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_MAX_LINES, "2");
* \endcode
*/
mosync.MAW_EDIT_BOX_MAX_LINES = "maxLines";

/**
* @brief Makes the edit box at least this many lines tall.
* Setting this value overrides any other (minimum) height setting.
* Available on Android only.
*
* @validvalue A positive integer.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_MIN_LINES, "1");
* \endcode
*/
mosync.MAW_EDIT_BOX_MIN_LINES = "minLines";

/**
* @brief Sets or gets the maximum input lenght of the edit box.
* Setting this value enables multiline input mode by default.
* Available on Android, iOS and Windows Phone.
*
* @validvalue A positive integer.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_MAX_LENGTH, "10");
* \endcode
*/
mosync.MAW_EDIT_BOX_MAX_LENGTH = "maxLength";

/**
* @brief Sets the font color of the placeholder text when an edit box is empty.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_PLACEHOLDER_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_EDIT_BOX_PLACEHOLDER_FONT_COLOR = "placeholderFontColor";

/**
* @brief Sets or gets the edit box mode.
* Changing this value on iOS platform will reset all widget's properties, because
* the widget will be replaced with a new one.
* It is recommended to set this value after creating the widget, and before adding it
* to a layout.
* Platform: iOS.
*
* @validvalue #MAW_EDIT_BOX_MODE_SINGLE_LINE will set the mode to single line, or
* MAW_EDIT_BOX_MULTI_LINE will set the mode to multi line.
*
* @setandget
*
* @par Example
* \code
*   char buffer[BUFFER_SIZE];
*   sprintf(buffer, "%d", MAW_EDIT_BOX_MODE_MULTI_LINE);
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_MODE, buffer);
* \endcode
*/
mosync.MAW_EDIT_BOX_MODE = "mode";

/**
* @brief Sets or gets the autocorrection type.
* Enable/disable the auto correction during typing. With auto correction enabled,
* the text object tracks unknown words and suggests a more suitable replacement candidate to the user,
* replacing the typed text automatically unless the user explicitly overrides the action.
* The default value is #MAW_EDIT_BOX_AUTOCORRECTION_TYPE_DEAFULT.
* Platform: iOS.
*
* @validvalue #MAW_EDIT_BOX_AUTOCORRECTION_TYPE_DEFAULT, #MAW_EDIT_BOX_AUTOCORRECTION_TYPE_ENABLE
* or #MAW_EDIT_BOX_AUTOCORRECTION_TYPE_DISABLE.
*
* @setandget
*
* @par Example
* \code
*   char buffer[BUFFER_SIZE];
*   sprintf(buffer, "%d", MAW_EDIT_BOX_AUTOCORRECTION_TYPE_YES;
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_AUTOCORRECTION_TYPE, buffer);
* \endcode
*/
mosync.MAW_EDIT_BOX_AUTOCORRECTION_TYPE = "autoCorrectionType";

/**
* @brief Sets or gets the horizontal alignment of the text inside the edit box.
* The default value is #MAW_ALIGNMENT_LEFT.
* Platform: iOS.
*
* @validvalue #MAW_ALIGNMENT_LEFT, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_RIGHT.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(editBoxHandle, MAW_EDIT_BOX_TEXT_HORIZONTAL_ALIGNMENT,
*                       MAW_ALIGNMENT_RIGHT);
* \endcode
*/
mosync.MAW_EDIT_BOX_TEXT_HORIZONTAL_ALIGNMENT = "textHorizontalAlignment";

/**
* @brief Property that tells the gl view that it should be redrawn.
*
* @validvalue The value isn't taken into account.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(glViewHandle, MAW_GL_VIEW_INVALIDATE, "");
* \endcode
*/
mosync.MAW_GL_VIEW_INVALIDATE = "invalidate";

/**
* @brief Property that tells the gl view that all following gl calls will apply to this view.
*
* @validvalue The value isn't taken into account.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(glViewHandle, MAW_GL_VIEW_BIND, "");
* \endcode
*/
mosync.MAW_GL_VIEW_BIND = "bind";

/**
* @brief Sets how the children in the layout should be aligned in the vertical axis.
*
* @validvalue One of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(horizontalLayoutHandle, MAW_HORIZONTAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_HORIZONTAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT = "childVerticalAlignment";

/**
* @brief Sets how the children in the layout should be aligned in the horizontal axis.
*
* @validvalue One of the constants #MAW_ALIGNMENT_LEFT, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_RIGHT.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(horizontalLayoutHandle, MAW_HORIZONTAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_HORIZONTAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT = "childHorizontalAlignment";

/**
* @brief Sets the top padding.
*
* @validvalue The top padding in pixels.
*
* @setonly
*
* @par Example
* \code
*  // Set a 50px top padding.
*	maWidgetSetProperty(horizontalLayoutHandle, MAW_HORIZONTAL_LAYOUT_PADDING_TOP, "50");
* \endcode
*/
mosync.MAW_HORIZONTAL_LAYOUT_PADDING_TOP = "paddingTop";

/**
* @brief Sets the left padding.
*
* @validvalue The left padding in pixels.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(horizontalLayoutHandle, MAW_HORIZONTAL_LAYOUT_PADDING_LEFT, "50");
* \endcode
*/
mosync.MAW_HORIZONTAL_LAYOUT_PADDING_LEFT = "paddingLeft";

/**
* @brief Sets the right padding.
*
* @validvalue The right padding in pixels.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(horizontalLayoutHandle, MAW_HORIZONTAL_LAYOUT_PADDING_RIGHT, "50");
* \endcode
*/
mosync.MAW_HORIZONTAL_LAYOUT_PADDING_RIGHT = "paddingRight";

/**
* @brief Sets the bottom padding.
*
* @validvalue The bottom padding in pixels.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(horizontalLayoutHandle, MAW_HORIZONTAL_LAYOUT_PADDING_BOTTOM, "50");
* \endcode
*/
mosync.MAW_HORIZONTAL_LAYOUT_PADDING_BOTTOM = "paddingBottom";

/**
* Sets or gets the image that will be displayed.
* Setting this property will change #MAW_IMAGE_PATH property value to an empty string.
*
* @validvalue MoSync handle to an uncompressed image resource.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(buttonHandle, MAW_IMAGE_IMAGE, toString(R_MY_IMAGE));
* \endcode
*/
mosync.MAW_IMAGE_IMAGE = "image";

/**
* Sets or gets a path to a image file that will be displayed by the widget.
* Setting this property will change #MAW_IMAGE_IMAGE property value to zero.
*
* @validvalue A valid path to an image file.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(imageHandle, MAW_IMAGE_PATH, "file_path.png");
* \endcode
*/
mosync.MAW_IMAGE_PATH = "imagePath";

/**
* @brief Specifies what type of scaling should be applied to the image.
*
* @validvalue Either 'none', 'scaleXY' or 'scalePreserveAspect'. Default 'none'.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(imageHandle, MAW_IMAGE_SCALE_MODE, "scaleXY");
* \endcode
*/
mosync.MAW_IMAGE_SCALE_MODE = "scaleMode";

/**
* @brief Sets or gets the text that is displayed in the label.
* Note: It is not available on Android, as native image buttons do not have text attached.
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example set
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_TEXT, "My button");
* \endcode
*
* @par Example get
* \code
*	char textBuffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_TEXT, textBuffer, BUFFER_SIZE);
*	if (result > 0)
*	{
*	// Do something with the label text.
*	}
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_TEXT = "text";

/**
* @brief Sets the vertical alignment of the text inside the button. If the widget's height is WRAP_CONTENT this property has no effect.
*
* @validvalue One of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_TEXT_VERTICAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_TEXT_VERTICAL_ALIGNMENT = "textVerticalAlignment";

/**
* @brief Sets the horizontal alignment of the text inside the button. If the widget's height is WRAP_CONTENT this property has no effect.
*
* @validvalue Takes one of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_TEXT_HORIZONTAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_TEXT_HORIZONTAL_ALIGNMENT = "textHorizontalAlignment";

/**
* @brief Sets the font color of the button's text.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_FONT_COLOR = "fontColor";

/**
* @brief Sets the font size in points of the button's text.
*
* @validvalue A float that specifies the number of pixels on Android
* and WP7, and number of points on iOS.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_FONT_SIZE, "13.0");
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_FONT_SIZE = "fontSize";

/**
* Sets or gets the background image. This will be scaled to fit the whole widget (not keeping the aspect).
* Setting this property will change #MAW_IMAGE_BUTTON_BACKGROUND_IMAGE_PATH property
* value to an empty string.
*
* @validvalue MoSync handle to an uncompressed image resource.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_BACKGROUND_IMAGE, toString(R_MY_IMAGE));
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_BACKGROUND_IMAGE = "backgroundImage";

/**
* Sets or gets the foreground image of the button. This won't be scaled at all.
* Setting this property will change #MAW_IMAGE_BUTTON_IMAGE_PATH property
* value to an empty string.
*
* @validvalue MoSync handle to an uncompressed image resource.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_IMAGE, toString(R_MY_IMAGE));
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_IMAGE = "image";

/**
* Sets or gets a path to a image file that will be displayed by the widget
* as a foreground image.
* Setting this property will change #MAW_IMAGE_BUTTON_IMAGE property value to zero.
*
* @validvalue A valid path to an image file.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_IMAGE_PATH, "file_path.png");
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_IMAGE_PATH = "imagePath";

/**
* Sets or gets a path to a image file that will be displayed by the widget
* as a background image.
* Setting this property will change #MAW_IMAGE_BUTTON_BACKGROUND_IMAGE property value to zero.
*
* @validvalue A valid path to an image file.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_BACKGROUND_IMAGE_PATH, "file_path.png");
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_BACKGROUND_IMAGE_PATH = "backgroundImagePath";

/**
* @brief Sets the typeface and style in which the text should be displayed.
*
* @validvalue A font handle received from loading fonts using
* #maFontGetName and #maFontLoadWithName syscalls.
* Note: It is not available on Android, as native image buttons do not have text attached.
* @setonly
*
* @par Example
* \code
*	int nrFonts = maFontGetCount();
*	 char buf[256];
*	 // Get first font name.
*	 maFontGetName(1, buf, 256);
*	 // Load that font for size 10.
*	 int fontHandle = maFontLoadWithName(buf, 10);
*	 // Set that font to the label.
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_FONT_HANDLE, toString(fontHandle));
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_FONT_HANDLE = "fontHandle";

/**
* Sets or gets the image that will be displayed by the widget
* after user clicks on it. On iOS platform this property is named highlighted state.
* If this property is set when the user taps on the widget, its background image will
* be replaced by the image set here.
* Setting this property will reset the #MAW_IMAGE_BUTTON_PRESSED_IMAGE_PATH value.
*
* @validvalue A valid image handle.
*
* @setandget
*
* @par Example
* \code
* char buffer[BUFFER_SIZE];
* sprintf(buffer, "%d", handle);
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_PRESSED_IMAGE, buffer);
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_PRESSED_IMAGE = "pressedImage";

/**
* Sets or gets a path to a image file that will be displayed by the widget
* after user clicks on it. On iOS platform this property is named highlighted state.
* If this property is set when the user taps on the widget, its background image will
* be replaced by the image set here.
* Setting this property will reset the #MAW_IMAGE_BUTTON_PRESSED_IMAGE value.
*
* @validvalue A valid path to an image file.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(imageButtonHandle, MAW_IMAGE_BUTTON_PRESSED_IMAGE_PATH, "file_path.png");
* \endcode
*/
mosync.MAW_IMAGE_BUTTON_PRESSED_IMAGE_PATH = "pressedImagePath";

/**
* @brief Sets or gets the text that is displayed in the label.
*
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example set
* \code
*	maWidgetSetProperty(labelHandle, MAW_LABEL_TEXT, "My label");
* \endcode
*
* @par Example get
* \code
*	char textBuffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(labelHandle, MAW_LABEL_TEXT, textBuffer, BUFFER_SIZE);
*	if (result > 0)
*	{
*	// Do something with the label text.
*	}
* \endcode
*/
mosync.MAW_LABEL_TEXT = "text";

/**
* @brief Sets the vertical alignment of the text inside the label. If the widget's height is WRAP_CONTENT this property has no effect.
*
* @validvalue One of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(labelHandle, MAW_LABEL_TEXT_VERTICAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_LABEL_TEXT_VERTICAL_ALIGNMENT = "textVerticalAlignment";

/**
* @brief Sets the horizontal alignment of the text inside the label. If the widget's height is WRAP_CONTENT this property has no effect.
*
* @validvalue Takes one of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(labelHandle, MAW_LABEL_TEXT_HORIZONTAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_LABEL_TEXT_HORIZONTAL_ALIGNMENT = "textHorizontalAlignment";

/**
* @brief Sets the font color of the label's text.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(labelHandle, MAW_LABEL_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_LABEL_FONT_COLOR = "fontColor";

/**
* @brief Sets the font size in points of the label's text.
*
* @validvalue A float that specifies the number of pixels on Android
* and WP7, and number of points on iOS.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(labelHandle, MAW_LABEL_FONT_SIZE, "13.0");
* \endcode
*/
mosync.MAW_LABEL_FONT_SIZE = "fontSize";

/**
* @brief Sets the typeface and style in which the text should be displayed.
*
* @validvalue A font handle received from loading fonts using
* #maFontGetName and #maFontLoadWithName syscalls.
*
* @setonly
*
* @par Example
* \code
*	int nrFonts = maFontGetCount();
*	 char buf[256];
*	 // Get first font name.
*	 maFontGetName(1, buf, 256);
*	 // Load that font for size 10.
*	 int fontHandle = maFontLoadWithName(buf, 10);
*	 // Set that font to the label.
*	maWidgetSetProperty(labelHandle, MAW_LABEL_FONT_HANDLE, toString(fontHandle));
* \endcode
*/
mosync.MAW_LABEL_FONT_HANDLE = "fontHandle";

/**
* @brief Sets the maximum number of lines used for rendering text.
* To remove any maximum limit, and use as many lines as needed, set the value of this property to 0.
*
* @validvalue An integer that specifies the maximum number of lines.
*
* @setandget.
*
* @par Example
* \code
*	maWidgetSetProperty(labelHandle, MAW_LABEL_MAX_NUMBER_OF_LINES, "3");
* \endcode
*/
mosync.MAW_LABEL_MAX_NUMBER_OF_LINES = "maxNumberOfLines";

/**
* @brief A plain table view.
* All section headers or footers are not displayed.
* Platform: Android, iOS and Windows Phone 7.
* Default value for list view.
*/
mosync.MAW_LIST_VIEW_TYPE_DEFAULT = 0;

/**
* @brief A plain table view.
* Any section headers or footers are displayed as inline separators.
* On iOS section headers or footers float when the table view is scrolled.
* Platform: iOS, Android and Windows Phone 7.
*/
mosync.MAW_LIST_VIEW_TYPE_ALPHABETICAL = 1;

/**
* @brief A table view whose sections present distinct groups of rows.
* The section headers and footers do not float.
* Platform: iOS, Android and Windows Phone 7.
*/
mosync.MAW_LIST_VIEW_TYPE_SEGMENTED = 2;

/**
* @brief List items cannot be edited.
* Platform: iOS.
* Default value for the list view.
*/
mosync.MAW_LIST_VIEW_MODE_DISPLAY = 0;

/**
* @brief List items can be edited.
* For more information see \link #WidgetListViewItemProperties
* List View Item Properties \endlink.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_MODE_EDIT = 1;

/**
* @brief Every list view item will contain an image, a title and a subtitle.
* Platform: Windows Phone 7.
* Default value for list view.
*/
mosync.MAW_LIST_VIEW_STYLE_SUBTITLE = 0;

/**
* @brief Every list view item will contain an image and a title.
* Platform: Windows Phone 7.
*/
mosync.MAW_LIST_VIEW_STYLE_NO_SUBTITLE = 1;

/**
* @brief Set or get the list type.
* Set this property before adding the list to the screen/layout.
* Platform: Android, iOS and Windows Phone 7.
*
* @validvalue One of the \link #MAW_LIST_VIEW_TYPE_DEFAULT MAW_LIST_VIEW_TYPE \endlink constants.
* Default value is \link #MAW_LIST_VIEW_TYPE_DEFAULT MAW_LIST_VIEW_TYPE_DEFAULT \endlink.
*
* @setandget
*
* @par Example
* \code
*	char buffer[124];
*	sprintf(buffer, "%d", MAW_LIST_VIEW_TYPE_ALPHABETICAL);
*	maWidgetSetProperty(listHandle, MAW_LIST_VIEW_TYPE, buffer);
* \endcode
*/
mosync.MAW_LIST_VIEW_TYPE = "type";

/**
* @brief Set or get the list style.
* This property should be set before the list contains any children.
* Platform: Windows Phone 7.
*
* @validvalue One of the \link #MAW_LIST_VIEW_STYLE MAW_LIST_VIEW_STYLE \endlink constants.
* Default value is \link #MAW_LIST_VIEW_STYLE_SUBTITLE MAW_LIST_VIEW_STYLE_SUBTITLE \endlink.
*
* @setandget
*
* @par Example
* \code
*	char buffer[124];
*	sprintf(buffer, "%d", MAW_LIST_VIEW_STYLE_NO_SUBTITLE);
*	maWidgetSetProperty(listHandle, MAW_LIST_VIEW_STYLE, buffer);
* \endcode
*/
mosync.MAW_LIST_VIEW_STYLE = "style";

/**
* @brief Set or get the list mode.
* Platform: iOS.
*
* @validvalue One of the \link #MAW_LIST_VIEW_MODE_DISPLAY
* MAW_LIST_VIEW_MODE \endlink constants.
* Default value is \link #MAW_LIST_VIEW_MODE_DISPLAY MAW_LIST_VIEW_MODE_DISPLAY \endlink.
*
* @setandget
*
* @par Example
* \code
*	char buffer[124];
*	sprintf(buffer, "%d", MAW_LIST_VIEW_MODE_EDIT);
*	maWidgetSetProperty(listHandle, MAW_LIST_VIEW_MODE, buffer);
* \endcode
*/
mosync.MAW_LIST_VIEW_MODE = "mode";

/**
* @brief Reload all its items.
* Platform: iOS, Android and Windows Phone 7.
*
* @validvalue Empty string.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listHandle, MAW_LIST_VIEW_RELOAD_DATA, "");
* \endcode
*/
mosync.MAW_LIST_VIEW_RELOAD_DATA = "reload_data";

/**
* @brief Enable/disable item selection.
* If you don't want to allow the user to select any item set this property to false.
* Platform: iOS, Android and Windows Phone 7.
*
* @validvalue "true" or "false".
* Default value is "true".
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(listHandle, MAW_LIST_VIEW_ALLOW_SELECTION, "false");
* \endcode
*/
mosync.MAW_LIST_VIEW_ALLOW_SELECTION = "allowselection";

/**
* @brief Enforces the focus on the list. Generally needed when for some reason the list looses it's focus.
*
* @validvalue None needed.
*
* Platform: Android.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listViewHandle, MAW_LIST_VIEW_REQUEST_FOCUS, "");
* \endcode
*/
mosync.MAW_LIST_VIEW_REQUEST_FOCUS = "requestFocus";

/**
* @brief The item does not have any accessory type.
* This is the default value.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_NONE = 0;

/**
* @brief The item has an accessory control shaped like a regular chevron.
* It is intended as a disclosure indicator.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_DISCLOSURE = 1;

/**
* @brief The item has an accessory control that is a blue button with a chevron image as content.
* It is intended for configuration purposes.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_DETAIL = 2;

/**
* @brief The cell has a check mark on its right side.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_CHECKMARK = 3;

/**
* @brief The item has no editing control.
* This is the default value.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_EDIT_STYLE_NONE = 0;

/**
* @brief The item has the delete editing control.
* This control is a red circle enclosing a minus sign.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_EDIT_STYLE_DELETE = 1;

/**
* @brief The item has the insert editing control.
* This control is a green circle enclosing a plus sign.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_EDIT_STYLE_INSERT = 2;

/**
* @brief The item has no distinct style for when it is selected.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_SELECTION_STYLE_NONE = 0;

/**
* @brief The item has a blue background for selected state.
* This is the default value.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_SELECTION_STYLE_BLUE = 1;

/**
* @brief Then item has a gray background for selected state.
* Platform: iOS.
*/
mosync.MAW_LIST_VIEW_ITEM_SELECTION_STYLE_GRAY = 2;

/**
* @brief Sets the text part of the list view item. If there is an icon the text will be placed to the right of it, otherwise near the left edge.
*
* @validvalue A null-terminated string.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listViewItemHandle, MAW_LIST_VIEW_ITEM_TEXT, "My label");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_TEXT = "text";

/**
* @brief Sets the subtitle part of the list view item. The subtitle will be placed bellow the item text.
*
* Platform: Windows Phone 7.
*
* @validvalue A null-terminated string.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listViewItemHandle, MAW_LIST_VIEW_ITEM_SUBTITLE, "subtitle");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_SUBTITLE = "subtitle";

/**
* @brief Sets an icon of the list view item that is placed to the left of the text.
*
* @validvalue MoSync handle to an uncompressed image resource.
*
* @par Example
* \code
*	maWidgetSetProperty(listViewItemHandle, MAW_LIST_VIEW_ITEM_ICON, toString(R_MY_ICON));
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_ICON = "icon";

/**
* @brief Sets the type of list item displayed. Provides the corresponding icon in the right side of the list view.
*
* @note Only available for iOS.
*
* @validvalue One of "none", "hasChildren", "hasDetails" or "isChecked".
*
* @par Example
* \code
*	maWidgetSetProperty(listViewItemHandle, MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE, "hasChildren");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE = "accessoryType";

/**
* @brief Sets the font color of the text part.
*
* @validvalue  A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example set the font color to red.
* \code
*	maWidgetSetProperty(listViewItemHandle, MAW_LIST_VIEW_ITEM_FONT_COLOR, "0xFF0000");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_FONT_COLOR = "fontColor";

/**
* @brief Sets the font size in points of the text part.
*
* @validvalue A float that specifies the number of pixels on Android
* and WP7, and number of points on iOS.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listViewItemHandle, MAW_LIST_VIEW_ITEM_FONT_SIZE, "13.0");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_FONT_SIZE = "fontSize";

/**
* @brief Sets the typeface and style in which the text should be displayed.
*
* @validvalue A font handle received from loading fonts using
* #maFontGetName and #maFontLoadWithName syscalls.
*
* @setonly
*
* @par Example
* \code
*	int nrFonts = maFontGetCount();
*	 char buf[256];
*	 // Get first font name.
*	 maFontGetName(1, buf, 256);
*	 // Load that font for size 10.
*	 int fontHandle = maFontLoadWithName(buf, 10);
*	 // Set that font to the list view item.
*	maWidgetSetProperty(listViewItemHandle, MAW_LIST_VIEW_ITEM_FONT_HANDLE, toString(fontHandle));
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_FONT_HANDLE = "fontHandle";

/**
* @brief Set or get the edit value.
* If an item is editable it means that the user can insert or delete a cell.
* In order to have those options the segmented list must be in edit mode.
*
* Platform: iOS.
*
* @validvalue "false" or "true" string values.
* Default value is "true".
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_EDIT, "true");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_EDIT = "edit";

/**
* @brief Set the title of the delete-confirmation button.
* The table view displays the "Delete" button when the user attempts to delete a row,
* either by swiping the row or tapping the red minus icon in editing mode.
*
* Platform: iOS.
*
* @validvalue A string.
* Default value is "Delete".
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_DELETE_BUTTON_TITLE, "Remove");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_DELETE_BUTTON_TITLE = "deleteButtonTitle";

/**
* @brief Check if the item is currently showing the delete-confirmation button.
* When users tap the deletion control (the red circle to the left of the cell),
* the cell displays a "Delete" button on the right side of the cell.
*
* Platform: iOS.
*
* @validvalue "true" of "false".
*
* @getonly
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	maWidgetGetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_IS_SHOWING_DELETE_CONFIRMATION,
*	buffer, BUFFER_SIZE);
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_IS_SHOWING_DELETE_CONFIRMATION = "isShowingDeleteConfirmation";

/**
* @brief Set the selected state of the item.
*
* Platform: iOS.
*
* @validvalue "true" to animate the transition between selected states,
* "false" to make the transition immediate.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_SET_SELECTED, "true");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_SET_SELECTED = "setSelected";

/**
* @brief Set the unselected state of the item.
*
* Platform: iOS.
*
* @validvalue "true" to animate the transition between selected states,
* "false" to make the transition immediate.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_SET_UNSELECTED, "true");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_SET_UNSELECTED = "setUnselected";

/**
* @brief Check if the item is selected.
*
* Platform: iOS and Android.
*
* @validvalue "true" if the item is selected, "false" otherwise.
*
* @getonly
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	maWidgetGetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_IS_SELECTED,
*	buffer, BUFFER_SIZE);
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_IS_SELECTED = "isSelected";

/**
* @brief Set the highlighted state of the item.
*
* Platform: iOS.
*
* @validvalue "true" to animate the transition between highlighted states,
* "false" to make the transition immediate.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_SET_HIGHLIGHTED, "true");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_SET_HIGHLIGHTED = "setHighlighted";

/**
* @brief Set the unhighlighted state of the item.
*
* Platform: iOS.
*
* @validvalue "true" to animate the transition between highlighted states,
* "false" to make the transition immediate.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_SET_UNHIGHLIGHTED,
*	"true");
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_SET_UNHIGHLIGHTED = "setUnhighlighted";

/**
* @brief Check if the item is highlighted.
*
* Platform: iOS.
*
* @validvalue "true" if the item is highlighted, "false" otherwise.
*
* @getonly
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	maWidgetGetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_IS_SELECTED,
*	buffer, BUFFER_SIZE);
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_IS_HIGHLIGHTED = "isHighlighted";

/**
* @brief Set or get the type of standard accessory used by the item(normal state).
* The accessory view appears in the right side of the item in the table view’s normal state.
*
* Platform: iOS.
*
* @validvalue One of the \link MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE
* MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_NONE \endlink values.
*
* @setandget
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	sprintf(buffer, "%d", MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_CHECKMARK);
*	maWidgetSetProperty(listItemHandle, MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE, buffer);
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_INT = "accessoryTypeInt";

/**
* @brief Set or get the type of standard accessory used by the item(editing state).
* The accessory view appears in the right side of the item in the table view’s editing state.
*
* Platform: iOS.
*
* @validvalue One of the \link MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE
* MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_NONE \endlink values.
*
* @setandget
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	sprintf(buffer, "%d", MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_CHECKMARK);
*	maWidgetSetProperty(listItemHandle,
*	   MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_EDIT_STATE buffer);
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_ACCESSORY_TYPE_EDIT = "accessoryTypeEditState";

/**
* @brief Set or get the editing style of an item.
* This applies only for the editing state.
*
* Platform: iOS.
*
* @validvalue One of the \link MAW_LIST_VIEW_ITEM_EDIT_STYLE
* MAW_LIST_VIEW_ITEM_EDIT_STYLE_NONE \endlink values.
*
* @setandget
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	sprintf(buffer, "%d", MAW_LIST_VIEW_ITEM_EDIT_STYLE_INSERT);
*	maWidgetSetProperty(listItemHandle,
*	   MAW_LIST_VIEW_ITEM_EDITING_STYLE, buffer);
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_EDITING_STYLE = "editingStyle";

/**
* @brief Set or get the background color constant for an item when it's selected.
*
* Platform: iOS.
*
* @validvalue One of the \link MAW_LIST_VIEW_ITEM_SELECTION_STYLE
* MAW_LIST_VIEW_ITEM_SELECTION_STYLE_NONE \endlink values.
*
* @setandget
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	sprintf(buffer, "%d", MAW_LIST_VIEW_ITEM_SELECTION_STYLE_GRAY);
*	maWidgetSetProperty(listItemHandle,
*	   MAW_LIST_VIEW_ITEM_SELECTION_STYLE, buffer);
* \endcode
*/
mosync.MAW_LIST_VIEW_ITEM_SELECTION_STYLE = "selectionStyle";

/**
* @brief A section that presents a group of rows, that correspond to the same #MAW_LIST_VIEW_SECTION_TITLE.
* Platform: iOS, Android and Windows Phone 7.
*/
mosync.MAW_LIST_VIEW_SECTION_TYPE_ALPHABETICAL = 1;

/**
* @brief A section that presents a group of rows, specifically list view items.
* Header and footer information can be set to segmented sections.
* Platform: iOS, Android and Windows Phone 7.
*/
mosync.MAW_LIST_VIEW_SECTION_TYPE_SEGMENTED = 2;

/**
* @brief Set or get the list section type.
* Set this property before adding list view items and adding it to the list.
* Platform: Android and iOS.
*
* @validvalue One of the \link #MAW_LIST_VIEW_SECTION_TYPE_ALPHABETICAL MAW_LIST_VIEW_TYPE \endlink constants.
*
* @setandget
*
* @par Example
* \code
*   char buffer[124];
*   sprintf(buffer, "%d", MAW_LIST_VIEW_TYPE_SEGMENTED);
*   maWidgetSetProperty(listHandle, MAW_LIST_VIEW_TYPE, buffer);
*	sprintf(buffer, "%d", MAW_LIST_VIEW_SECTION_TYPE_SEGMENTED);
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_TYPE, buffer);
*   maWidgetAddChild(listHandle, listSectionHandle);
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_TYPE = "type";

/**
* @brief Set or get section title.
* Section title will appear on the right side of the list.
* This preview letter is available only for list views of alphabetical type.
*
* Platform: iOS, Android and Windows Phone 7.
*
* @validvalue A string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_TITLE, "A");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_TITLE = "title";

/**
* @brief Set or get section header text.
* Section text will appear above the section items.
*
* Platform: iOS, Android and Windows Phone 7.
*
* @validvalue A string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_HEADER, "Header text");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_HEADER = "header";

/**
* @brief Set or get section footer text.
* Section text will appear below the section items.
*
* Platform: iOS, Android and Windows Phone 7.
*
* @validvalue A string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_FOOTER, "Footer text");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_FOOTER = "footer";

/**
* @brief Set the section header background color.
* Default value is 0xBEBEBE (grey).
*
* Platform: Android and Windows Phone 7.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_HEADER_BACKGROUND, "0xff0000");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_HEADER_BACKGROUND = "headerBackground";

/**
* @brief Set the section footer background color.
* Default value is 0xBEBEBE (grey).
*
* Platform: Android and Windows Phone 7.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_FOOTER_BACKGROUND, "0xff0000");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_FOOTER_BACKGROUND = "footerBackground";

/**
* @brief Sets the font color of the header.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_HEADER_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_HEADER_FONT_COLOR = "headerFontColor";

/**
* @brief Sets the font color of the footer.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_FOOTER_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_FOOTER_FONT_COLOR = "footerFontColor";

/**
* @brief Sets the font size in points of the header.
* Default value is 20.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue A float that specifies the number of pixels on Android.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_HEADER_FONT_SIZE, "13.0");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_HEADER_FONT_SIZE = "headerFontSize";

/**
* @brief Sets the font size in points of the footer.
* Default value is 15.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue A float that specifies the number of pixels on Android.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_FOOTER_FONT_SIZE, "13.0");
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_FOOTER_FONT_SIZE = "footerFontSize";

/**
* @brief Sets the typeface and style in which the header should be displayed.
*
* @validvalue A font handle received from loading fonts using
* #maFontGetName and #maFontLoadWithName syscalls.
*
* Platform: Android and Windows Phone 7.
*
* @setonly
*
* @par Example
* \code
*	int nrFonts = maFontGetCount();
*	 char buf[256];
*	 // Get first font name.
*	 maFontGetName(1, buf, 256);
*	 // Load that font for size 10.
*	 int fontHandle = maFontLoadWithName(buf, 10);
*	 // Set that font to the header.
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_HEADER_FONT_HANDLE, toString(fontHandle));
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_HEADER_FONT_HANDLE = "headerFontHandle";

/**
* @brief Sets the typeface and style in which the footer should be displayed.
*
* @validvalue A font handle received from loading fonts using
* #maFontGetName and #maFontLoadWithName syscalls.
*
* Platform: Android and Windows Phone 7.
*
* @setonly
*
* @par Example
* \code
*	int nrFonts = maFontGetCount();
*	 char buf[256];
*	 // Get first font name.
*	 maFontGetName(1, buf, 256);
*	 // Load that font for size 10.
*	 int fontHandle = maFontLoadWithName(buf, 10);
*	 // Set that font to the header.
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_FOOTER_FONT_HANDLE, toString(fontHandle));
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_FOOTER_FONT_HANDLE = "footerFontHandle";

/**
* @brief Sets the horizontal alignment of the text inside the header.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue Takes one of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_HEADER_HORIZONTAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_HEADER_HORIZONTAL_ALIGNMENT = "headerHorizontalAlignment";

/**
* @brief Sets the horizontal alignment of the text inside the footer.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue Takes one of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_FOOTER_HORIZONTAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_FOOTER_HORIZONTAL_ALIGNMENT = "footerHorizontalAlignment";

/**
* @brief Sets the vertical alignment of the text inside the header.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue One of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_HEADER_VERTICAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_HEADER_VERTICAL_ALIGNMENT = "headerVerticalAlignment";

/**
* @brief Sets the vertical alignment of the text inside the footer.
*
* Platform: Android and Windows Phone 7.
*
* @validvalue One of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(listSectionHandle, MAW_LIST_VIEW_SECTION_FOOTER_VERTICAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_LIST_VIEW_SECTION_FOOTER_VERTICAL_ALIGNMENT = "footerVerticalAlignment";

/**
* Road map type (landforms not visible).
*/
mosync.MAW_MAP_TYPE_ROAD = 0;

/**
* Sattelite map type (landforms visible).
*/
mosync.MAW_MAP_TYPE_SATELLITE = 1;

/**
* @brief The api key used to access the full features of the google map.
* The iOS platform doesn't require a key.
*
* @validvalue A string containing a google maps key. For further details on how to
* obtain this key go to "https://developers.google.com/maps/documentation/android/mapkey".
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_API_KEY_GOOGLE, "a_valid_google_key");
* \endcode
*/
mosync.MAW_MAP_API_KEY_GOOGLE = "api_key_google";

/**
* @brief The api key used to access the full features of the bing map (on windows phone platform).
*
* @validvalue A string containing a bing maps key. For further details on how to
* obtain this key go to "http://msdn.microsoft.com/en-us/library/ff428642.aspx".
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_API_KEY_BING, "a_valid_bing_key");
* \endcode
*/
mosync.MAW_MAP_API_KEY_BING = "api_key_bing";

/**
* @brief Set or get the map type.
*
* @validvalue One of the two values: MAW_MAP_TYPE_SATELLITE or MAW_MAP_TYPE_ROAD.
*
* @setandget
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_TYPE, MAW_MAP_TYPE_SATELLITE);
*	char mapType[BUF_SIZE];
*	maWidgetGetProperty(mapHandle, MAW_MAP_TYPE, mapType, BUF_SIZE);
* \endcode
*/
mosync.MAW_MAP_TYPE = "type";

/**
* @brief Sets and gets the zoom level of the map.
*
* @validvalue A integer value between 0 and 21.
*
* @setandget
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_ZOOM_LEVEL, "4");
*	maWidgetSetProperty(mapHandle, MAW_MAP_ZOOM_LEVEL);
*	char zoomLevel[BUF_SIZE];
*	maWidgetGetProperty(mapHandle, MAW_MAP_ZOOM_LEVEL, zoomLevel, BUF_SIZE);
* \endcode
*/
mosync.MAW_MAP_ZOOM_LEVEL = "zoom_level";

/**
* @brief Disables/enables the interaction between the user and the map.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @setandget
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_INTERRACTION_ENABLED, "true");
*	char interractionEnabled[BUF_SIZE];
*	maWidgetGetProperty(mapHandle, MAW_MAP_INTERRACTION_ENABLED, interractionEnabled, BUF_SIZE);
* \endcode
*/
mosync.MAW_MAP_INTERRACTION_ENABLED = "interraction_enabled";

/**
* @brief Set the map center latitude coordinate.
*
* @validvalue A double value between -90.0 and 90.0.
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_CENTER_LATITUDE, "43.232544");
*	maWidgetSetProperty(mapHandle, MAW_MAP_CENTER_LATITUDE, "-12.42324");
* \endcode
*/
mosync.MAW_MAP_CENTER_LATITUDE = "center_latitude";

/**
* @brief Set the map center longitude coordinate.
*
* @validvalue A double value between -180.0 and 180.0.
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_CENTER_LONGITUDE, "80.43352");
*	maWidgetSetProperty(mapHandle, MAW_MAP_CENTER_LONGITUDE, "-54.56442");
* \endcode
*/
mosync.MAW_MAP_CENTER_LONGITUDE = "center_longitude";

/**
* @brief Set the map zoom level value.
*
* @validvalue A double value between 0 and 21.
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_CENTER_ZOOM_LEVEL, "12");
*	maWidgetSetProperty(mapHandle, MAW_MAP_CENTER_ZOOM_LEVEL, "3");
* \endcode
*/
mosync.MAW_MAP_CENTER_ZOOM_LEVEL = "center_zoom_level";

/**
 * @brief Property used to center the map.
 *
 * @validvalue A boolean string: "true" or "false".
 *
 * @setonly
 * @par Example
 * \code
 *	 maWidgetSetProperty(mapHandle, MAW_MAP_CENTERED, "true"); // centers the map on the already set map center
 * \endcode
 */
mosync.MAW_MAP_CENTERED = "centered";

/**
 * @brief Property used to specify the upper left corner latitude of the visible area.
 *
 * @validvalue A double value between -90.0 and 90.0.
 *
 * @setandget
 * @par Example
 * \code
 *	 maWidgetSetProperty(mapHandle, MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LATITUDE, "-34.34234");
 * \endcode
 */
mosync.MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LATITUDE = "visible_area_upper_left_corner_latitude";

/**
 * @brief Property used specify the upper left corner longitude of the visible area.
 *
 * @validvalue A double value between -180.0 and 180.0.
 *
 * @setandget
 * @par Example
 * \code
 *	 maWidgetSetProperty(mapHandle, MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LONGITUDE, "134.312");
 * \endcode
 */
mosync.MAW_MAP_VISIBLE_AREA_UPPER_LEFT_CORNER_LONGITUDE = "visible_area_upper_left_corner_longitude";

/**
 * @brief Property used specify the lower right corner latitude of the visible area.
 *
 * @validvalue A double value between -90.0 and 90.0.
 *
 * @setandget
 * @par Example
 * \code
 *	 maWidgetSetProperty(mapHandle, MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LATITUDE, "43.2322");
 * \endcode
 */
mosync.MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LATITUDE = "visible_area_lower_right_corner_latitude";

/**
 * @brief Property used specify the lower right corner longitude of the visible area.
 *
 * @validvalue A double value between -180.0 and 180.0.
 *
 * @setandget
 * @par Example
 * \code
 *	 maWidgetSetProperty(mapHandle, MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LONGITUDE, "-100.2324");
 * \endcode
 */
mosync.MAW_MAP_VISIBLE_AREA_LOWER_RIGHT_CORNER_LONGITUDE = "visible_area_lower_right_corner_longitude";

/**
* @brief Used to center the map on a previously set visible area.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAP_CENTERED_ON_VISIBLE_AREA, "true");
* \endcode
*/
mosync.MAW_MAP_CENTERED_ON_VISIBLE_AREA = "centered_on_visible_area";

/**
* @brief Set the map pin latitude coordinate.
*
* @validvalue A double value between -90.0 and 90.0.
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_PIN_LATITUDE, "43.232544");
*	maWidgetSetProperty(mapHandle, MAW_MAP_PIN_LATITUDE, "-12.42324");
* \endcode
*/
mosync.MAW_MAP_PIN_LATITUDE = "latitude";

/**
* @brief Set the map pin longitude coordinate.
*
* @validvalue A double value between -180.0 and 180.0.
*
* @setonly
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_PIN_LONGITUDE, "80.43352");
*	maWidgetSetProperty(mapHandle, MAW_MAP_PIN_LONGITUDE, "-124.56442");
* \endcode
*/
mosync.MAW_MAP_PIN_LONGITUDE = "longitude";

/**
* @brief Set the map pin text.
*
* @validvalue A string value.
*
* @setandget
* @par Example
* \code
*	maWidgetSetProperty(mapHandle, MAW_MAP_PIN_TEXT, "Cluj");
* \endcode
*/
mosync.MAW_MAP_PIN_TEXT = "text";

/**
* @brief Sets or gets the title.
* If the property receives am empty string then the title bar becomes invisible.
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(dialogHandle, MAW_MODAL_DIALOG_TITLE, "MyDialog");
* \endcode
*/
mosync.MAW_MODAL_DIALOG_TITLE = "title";

/**
* @brief Sets the origin arrow position for a popover dialog.
* Note: This property is only available on the iPad.
*
* @validvalue One of the five MAW_CONSTANT_ARROW_ values, or a bitwise or combination of them.
*
* @setonly
*
* @par Example
* \code
*	// Allow the popover to use any arrow
*	maWidgetSetProperty(dialogHandle, MAW_MODAL_DIALOG_ARROW_POSITION, MAW_CONSTANT_ARROW_ANY);
* \endcode
*/
mosync.MAW_MODAL_DIALOG_ARROW_POSITION = "arrowPosition";

/**
* @brief Allow or prohibits the user from dismissing a popover dialog by tapping outside of it.
* Note: This property is only available on the iPad.
*
* @validvalue "true"or "false".
*
* @setonly
*
* @par Example
* \code
*	// Prohibit the user from dismissing the popover
*	maWidgetSetProperty(dialogHandle, MAW_MODAL_DIALOG_USER_CAN_DISMISS, "false");
* \endcode
*/
mosync.MAW_MODAL_DIALOG_USER_CAN_DISMISS = "userCanDismiss";

/**
* @brief Sets or gets the title.
*
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(navBarHandle, MAW_NAV_BAR_TITLE, "MyScreen");
* \endcode
*/
mosync.MAW_NAV_BAR_TITLE = "title";

/**
* Sets the icon of the nav bar. This won't be scaled at all.
*
* @validvalue MoSync handle to an uncompressed image resource. The size of the image should be small enough to fit in the nav bar.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(navBarHandle, MAW_NAV_BAR_ICON, toString(R_MY_IMAGE));
* \endcode
*/
mosync.MAW_NAV_BAR_ICON = "icon";

/**
* @brief Sets the text for the back button.
* This can be set only when the navigation bar was
* attached to a screen that is not part of a stack screen.
* Note: this is available only on iOS.
* On Android the back behavior is handled by the device's back button.
*
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(navBarHandle, MAW_NAV_BAR_BACK_BTN, "Home");
* \endcode
*/
mosync.MAW_NAV_BAR_BACK_BTN = "backBtn";

/**
* @brief Sets the font color of the title.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(navBarHandle, MAW_NAV_BAR_TITLE_FONT_COLOR, "0xff0000");
* \endcode
*/
mosync.MAW_NAV_BAR_TITLE_FONT_COLOR = "titleFontColor";

/**
* @brief Sets the font size in points of the title.
*
* @validvalue A float that specifies the number of pixels on Android
* and WP7, and number of points on iOS.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(navBarHandle, MAW_NAV_BAR_TITLE_FONT_SIZE, "13.0");
* \endcode
*/
mosync.MAW_NAV_BAR_TITLE_FONT_SIZE = "titleFontSize";

/**
* @brief Sets the typeface and style in which the title should be displayed.
*
* @validvalue A font handle received from loading fonts using
* #maFontGetName and #maFontLoadWithName syscalls.
*
* @setonly
*
* @par Example
* \code
*	int nrFonts = maFontGetCount();
*	 char buf[256];
*	 // Get first font name.
*	 maFontGetName(1, buf, 256);
*	 // Load that font for size 10.
*	 int fontHandle = maFontLoadWithName(buf, 10);
*	 // Set that font to the label.
*	maWidgetSetProperty(navBarHandle, MAW_NAV_BAR_TITLE_FONT_HANDLE, toString(fontHandle));
* \endcode
*/
mosync.MAW_NAV_BAR_TITLE_FONT_HANDLE = "titleFontHandle";

/**
* @brief Sets or gets the current value for the number picker.
* If the value is less than MAW_NUMBER_PICKER_MIN_VALUE property value, the current value is set to min.
* If the value is greater than MAW_NUMBER_PICKER_MAX_VALUE value, the current value is set to max.
*
* @validvalue A valid int.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(numberPickerHandle, MAW_NUMBER_PICKER_VALUE, "50");
* \endcode
*/
mosync.MAW_NUMBER_PICKER_VALUE = "value";

/**
* @brief Sets or gets the min value of the picker.
*
* @validvalue An int that specifies the minimum value.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(numberPickerHandle, MAW_NUMBER_PICKER_MIN_VALUE, "0");
* \endcode
*/
mosync.MAW_NUMBER_PICKER_MIN_VALUE = "minValue";

/**
* @brief Sets or gets the max value of the picker.
*
* @validvalue An int that specifies the maximum value.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(numberPickerHandle, MAW_NUMBER_PICKER_MAX_VALUE, "100");
* \endcode
*/
mosync.MAW_NUMBER_PICKER_MAX_VALUE = "maxValue";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_ADD = "17301555";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_AGENDA = "17301556";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_ALWAYS_LANDSCAPE_PORTRAIT = "17301557";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_CALL = "17301558";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_CAMERA = "17301559";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_CLOSE_CLEAR_CANCEL = "17301560";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_COMPASS = "17301561";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_CROP = "17301562";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_DAY = "17301563";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_DELETE = "17301564";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_DIRECTIONS = "17301565";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_EDIT = "17301566";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_GALLERY = "17301567";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_HELP = "17301568";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_INFO_DETAILS = "17301569";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_MANAGE = "17301570";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_MAPMODE = "17301571";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_MONTH = "17301572";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_MORE = "17301573";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_MY_CALENDAR = "17301574";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_MYLOCATION = "17301575";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_MYPLACES = "17301576";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_PREFERENCES = "17301577";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_RECENT_HISTORY = "17301578";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_REPORT_IMAGE = "17301579";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_REVERT = "17301580";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_ROTATE = "17301581";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SAVE = "17301582";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SEARCH = "17301583";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SEND = "17301584";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SET_AS = "17301585";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SHARE = "17301586";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SLIDESHOW = "17301587";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SORT_ALPHABETICALLY = "17301660";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_SORT_BY_SIZE = "17301661";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_TODAY = "17301588";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_UPLOAD = "17301589";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_UPLOAD_YOU_TUBE = "17301590";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_VIEW = "17301591";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_WEEK = "17301592";

mosync.MAW_OPTIONS_MENU_ICON_CONSTANT_ZOOM = "17301593";

/**
* @copydoc #MAW_SCREEN_TITLE
*/
mosync.MAW_PANORAMA_VIEW_TITLE = "title";

/**
* @brief Sets or gets the currently shown screen to the screen with the given index.
*
* @validvalue A 0-indexed tab number.
*
* @setandget
*
* @par Example set
* \code
*	maWidgetSetProperty(panoramaViewHandle, MAW_PANORAMA_VIEW_CURRENT_SCREEN, "1");
* \endcode
*
* @par Example get
* \code
*	char currentScreenBuffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(
*	panoramaViewHandle,
*	MAW_PANORAMA_VIEW_CURRENT_SCREEN,
*	currentScreenBuffer,
*	BUFFER_SIZE);
*	if (result > 0)
*	{
*	// Do something with current screen.
*	}
* \endcode
*/
mosync.MAW_PANORAMA_VIEW_CURRENT_SCREEN = "currentScreen";

/**
 * @brief Sets or gets the background image of the view.
 *
 * @validvalue MoSync handle to an uncompressed image resource. The size of the image should be large enough to fill the space used by the panorama
 *
 * @setandget
 *
 * @par Example
 * \code
 *	maWidgetSetProperty(panoramaViewHandle, MAW_PANORAMA_VIEW_BACKGROUND_IMAGE, toString(R_MY_IMG));
 * \endcode
 */
mosync.MAW_PANORAMA_VIEW_BACKGROUND_IMAGE = "backgroundImage";

/**
* @brief Check if a panorama view is shown.
*
* @validvalue "true" if the panorama is visible, "false" otherwise.
*
* @getonly
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(panoramaHandle, MAW_PANORAMA_VIEW_IS_SHOWN,
*                                    buffer, BUFFER_SIZE);
*	if(result == MAW_RES_OK && strcmp(buffer, "true") == 0)
*	{
*	// Panorama view is visible.
*	}
* \endcode
*/
mosync.MAW_PANORAMA_VIEW_IS_SHOWN = "isShown";

/**
* @brief Sets or gets the range of the progress bar to 0..max.
*
* @validvalue An positive integer that specifies the upper range of this progress bar.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(progressBarHandle, MAW_PROGRESS_BAR_MAX, "100");
* \endcode
*/
mosync.MAW_PROGRESS_BAR_MAX = "max";

/**
* @brief Set or gets the current progress to the specified value.
*
* @validvalue An int that specifies the new progress, between 0 and max value. See \ref MAW_PROGRESS_BAR_MAX.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(progressBarHandle, MAW_PROGRESS_BAR_PROGRESS, "10");
* \endcode
*/
mosync.MAW_PROGRESS_BAR_PROGRESS = "progress";

/**
* @brief Increase the progress bar's progress by the specified amount.
*
* @validvalue An int that specifies the amount by which the progress must be increased.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(progressBarHandle, MAW_PROGRESS_BAR_INCREMENT_PROGRESS, "20");
* \endcode
*/
mosync.MAW_PROGRESS_BAR_INCREMENT_PROGRESS = "incrementProgress";

/**
* @brief Get the checked state of the radio button.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @getonly
*
* @par Example
* \code
*	char state[BUFFER_SIZE];
*	maWidgetGetProperty(radioButtonHandle, MAW_RADIO_BUTTON_CHECKED, state, BUFFER_SIZE);
* \endcode
*/
mosync.MAW_RADIO_BUTTON_CHECKED = "checked";

/**
* @brief Change the checked state of the view to the inverse of its current state.
* If the radio button is already checked, this method will not toggle the radio button.
*
* @validvalue No neccessary value needed.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(radioButtonHandle, MAW_RADIO_BUTTON_TOGGLE, "");
* \endcode
*/
mosync.MAW_RADIO_BUTTON_TOGGLE = "toggle";

/**
* @brief Set or get the text to display.
*
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(radioButtonHandle, MAW_RADIO_BUTTON_TEXT, "Option A");
* \endcode
*/
mosync.MAW_RADIO_BUTTON_TEXT = "text";

/**
* @brief Specifies the text color of the radio button.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_RADIO_BUTTON_TEXT_COLOR, "0xff0000"); // Red
* \endcode
*/
mosync.MAW_RADIO_BUTTON_TEXT_COLOR = "textcolor";

/**
* @brief Add the radio buttons grouped in this widget.
* This is the only widget type that accepts Radio Buttons as children.
*
* @validvalue An int specifying the radio button handle.
*
* @setonly
*
* @par Example
* \code
*	// Attach two radio buttons to this group.
*	maWidgetSetProperty(radioGroupHandle, MAW_RADIO_GROUP_ADD_VIEW, "3");
*	maWidgetSetProperty(radioGroupHandle, MAW_RADIO_GROUP_ADD_VIEW, "4");
* \endcode
*/
mosync.MAW_RADIO_GROUP_ADD_VIEW = "addview";

/**
* @brief Clear the selection.
* When the selection is cleared, no radio button in this group is selected and
* #MAW_RADIO_GROUP_SELECTED returns -1.
*
* @validvalue No neccessary value needed.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(radioGroupHandle, MAW_RADIO_GROUP_CLEAR_CHECK, "");
* \endcode
*/
mosync.MAW_RADIO_GROUP_CLEAR_CHECK = "clearcheck";

/**
* @brief Set or get the selected radio button in this group.
* Upon empty selection, get property returns -1.
* Setting -1 as the selection identifier clears the selection; such an operation
* is equivalent to invoking #MAW_RADIO_GROUP_CLEAR_CHECK.
*
* @validvalue A valid radio button handle.
*
* @setandget
*
* @par Example
* \code
*	char buttonHandle[BUF_SIZE];
*	maWidgetGetProperty(radioGroupHandle, MAW_RADIO_GROUP_SELECTED, buttonHandle, BUF_SIZE);
* \endcode
*/
mosync.MAW_RADIO_GROUP_SELECTED = "selected";

/**
* @brief Set or get the number of stars to show.
* Usually, the default stars number is 5.
* @validvalue An int that specifies the number of stars to show.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(ratingBarHandle, MAW_RATING_BAR_NUM_STAR, "4");
* \endcode
*/
mosync.MAW_RATING_BAR_NUM_STAR = "numstar";

/**
* @brief Set or get the current rating (number of stars filled).
*
* @validvalue A float that specifies the number of stars filled.
*
* @setandget
* @par Example
* \code
*	maWidgetSetProperty(ratingBarHandle, MAW_RATING_BAR_RATING, "3.0");
* \endcode
*/
mosync.MAW_RATING_BAR_RATING = "rating";

/**
* @brief Set or get the step size (granularity) of this rating bar.
* By default the granularity is 0.5.
* @validvalue A float that specifies the step size.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(ratingBarHandle, MAW_RATING_BAR_GRANULARITY, "1.0");
* \endcode
*/
mosync.MAW_RATING_BAR_GRANULARITY = "granularity";

/**
* @brief Sets the isScrollable boolean
*
* @validvalue "true" or "false", for "true" the layout will become scrollable otherwise it will become unscrollable
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_RELATIVE_LAYOUT_SCROLLABLE, "true");
* \endcode
*/
mosync.MAW_RELATIVE_LAYOUT_SCROLLABLE = "scrollable";

/**
* @brief Sets the content offset. The layout will be scrolled to the given coordinate.
* Platform: iOS.
*
* @validvalue Two int values separated by dash "-". The first int value represents the x coord and
* the second value represents the y coord.
* If the value is not as described the content offset will not be set and syscall will return
* #MAW_RES_INVALID_PROPERTY_VALUE.
* The default value is (0,0).
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_RELATIVE_LAYOUT_SCROLLABLE, "30-30");
* \endcode
*/
mosync.MAW_RELATIVE_LAYOUT_CONTENT_OFFSET = "contentOffset";

/**
* @brief Sets the title of a screen. The screen title is used by tab screen to display a text on the tab indicator.
*
* @validvalue Null terminated string. The length of the string should be short enough to fit in a tab indicator.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(screenHandle, MAW_SCREEN_TITLE, "My title");
* \endcode
*/
mosync.MAW_SCREEN_TITLE = "title";

/**
* @brief Sets an icon for a screen. The icon is used by a tab screen to display an icon on the tab indicator.
*
* @validvalue MoSync handle to an uncompressed image resource. The size of the image should be small enough to fit in a tab indicator.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(screenHandle, MAW_SCREEN_ICON, toString(R_MY_ICON));
* \endcode
*/
mosync.MAW_SCREEN_ICON = "icon";

/**
* @brief Remove the options menu from this screen.
* The options menu can be added by calling \ref maWidgetScreenAddOptionsMenuItem for each item.
*
* @validvalue No value needed.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(screenHandle, MAW_SCREEN_REMOVE_OPTIONS_MENU, "");
* \endcode
*/
mosync.MAW_SCREEN_REMOVE_OPTIONS_MENU = "removeoptionsmenu";

/**
* @brief Check if a screen is shown.
*
* @validvalue "true" if the screen is visible, "false" otherwise.
*
* @getonly
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(screenHandle, MAW_SCREEN_IS_SHOWN, buffer, BUFFER_SIZE);
*	if(result == MAW_RES_OK && strcmp(buffer, "true") == 0)
*	{
*	// Screen is visible.
*	}
* \endcode
*/
mosync.MAW_SCREEN_IS_SHOWN = "isShown";

/**
 * \brief A direct transition, no animation is involved. This is the default type.
 */
mosync.MAW_TRANSITION_TYPE_NONE = 0;

/**
 * \brief A transition that flips a view around its vertical axis from left to right.
 * The left side of the view moves toward the front and right side toward the back.
 *
 * Platform: iOS (4.0 and later).
 */
mosync.MAW_TRANSITION_TYPE_FLIP_FROM_LEFT = 1;

/**
 * \brief A transition that flips a view around its vertical axis from right to left.
 * The right side of the view moves toward the front and left side toward the back.
 *
 * Platform: iOS (4.0 and later).
 */
mosync.MAW_TRANSITION_TYPE_FLIP_FROM_RIGHT = 2;

/**
 * \brief A transition that curls a view up from the bottom.
 *
 * Platform: iOS (4.0 and later).
 */
mosync.MAW_TRANSITION_TYPE_CURL_UP = 3;

/**
 * \brief A transition that curls a view down from the top.
 *
 * Platform: iOS (4.0 and later).
 */
mosync.MAW_TRANSITION_TYPE_CURL_DOWN = 4;

/**
 * \brief A transition that dissolves from one view to the next.
 *
 * Platform: iOS (5.0 and later).
 *
 * \Note Not yet available!
 */
mosync.MAW_TRANSITION_TYPE_CROSS_DISSOLVE = 5;

/**
 * \brief A transition that flips a view around its horizontal axis from top to bottom.
 * The top side of the view moves toward the front and the bottom side toward the back.
 *
 * Platform: iOS (5.0 and later).
 *
 * \Note Not yet available!
 */
mosync.MAW_TRANSITION_TYPE_FLIP_FROM_TOP = 6;

/**
 * \brief A transition that flips a view around its horizontal axis from bottom to top.
 * The bottom side of the view moves toward the front and the top side toward the back.
 *
 * Platform: iOS (5.0 and later).
 *
 * \Note Not yet available!
 */
mosync.MAW_TRANSITION_TYPE_FLIP_FROM_BOTTOM = 7;

/**
 * \brief A transition that will show the next screen by sliding it from right to left.
 *
 * Platform: Android, Windows Phone 7.
 */
mosync.MAW_TRANSITION_TYPE_SLIDE_LEFT = 8;

/**
 * \brief A transition that will show the next screen by sliding it from left to right.
 *
 * Platform: Android, Windows Phone 7.
 */
mosync.MAW_TRANSITION_TYPE_SLIDE_RIGHT = 9;

/**
 * \brief A transition that will show the next screen by fading it in to the current one.
 *
 * Platform: Android.
 */
mosync.MAW_TRANSITION_TYPE_FADE_IN = 10;

/**
 * \brief A transition that will remove the current screen by fading it out.
 *
 * Platform: Android.
 */
mosync.MAW_TRANSITION_TYPE_FADE_OUT = 11;

/**
 * \brief A transition that will show the next screen by swiveling it in (full screen).
 *
 * Platform: Windows Phone 7.
 */
mosync.MAW_TRANSITION_TYPE_SWIVEL_IN = 12;

/**
 * \brief A transition that will show the next screen by swiveling it out (full screen).
 *
 * Platform: Windows Phone 7.
 */
mosync.MAW_TRANSITION_TYPE_SWIVEL_OUT = 13;

/**
 * \brief A transition that will remove the current screen using a tunstile forward movement.
 *
 * Platform: Windows Phone 7.
 */
mosync.MAW_TRANSITION_TYPE_TURNSTILE_FORWARD = 14;

/**
 * \brief A transition that will show the next screen using a tunstile backward movement.
 *
 * Platform: Windows Phone 7.
 */
mosync.MAW_TRANSITION_TYPE_TURNSTILE_BACKWARD = 15;

/**
 * \brief A custom screen transition defined thru the Screen transitions properties.
 *
 * \note This type is not supported at this moment.
 * The Api and behavior of a custom screen transition is yet TBD.
 *
 * Platform: None.
 */
mosync.MAW_TRANSITION_TYPE_CUSTOM = 16;

/**
* @brief Set or get the current text of the search bar.
*
* @validvalue A null-terminated string.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(searchBarHandle, MAW_SEARCH_BAR_TEXT, "My search query");
* \endcode
*/
mosync.MAW_SEARCH_BAR_TEXT = "text";

/**
* @brief Set a text in the search bar that acts as a placeholder when an edit box is empty.
*
* @validvalue A null-terminated string.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(searchBarHandle, MAW_SEARCH_BAR_PLACEHOLDER, "Search...");
* \endcode
*/
mosync.MAW_SEARCH_BAR_PLACEHOLDER = "placeholder";

/**
* @brief Shows or hides the virtual keyboard. If shown the focus will be set to this widget.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(searchBarHandle, MAW_SEARCH_BAR_SHOW_KEYBOARD, "true");
* \endcode
*/
mosync.MAW_SEARCH_BAR_SHOW_KEYBOARD = "showKeyboard";

/**
* @brief Sets or gets the range of the slider to 0..max.
*
* @validvalue An positive integer that specifies the upper range of this slider.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(sliderHandle, MAW_SLIDER_MAX, "100");
* \endcode
*/
mosync.MAW_SLIDER_MAX = "max";

/**
* @brief Set or gets the current value to the slider.
*
* @validvalue An int that specifies the new value, between 0 and max value. See \ref MAW_SLIDER_MAX.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(sliderHandle, MAW_SLIDER_VALUE, "10");
* \endcode
*/
mosync.MAW_SLIDER_VALUE = "value";

/**
* @brief Increase the current value of the slider by the specified amount.
*
* @validvalue An int that specifies the amount by which the slider value must be increased.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(sliderHandle, MAW_SLIDER_INCREASE_VALUE, "20");
* \endcode
*/
mosync.MAW_SLIDER_INCREASE_VALUE = "increaseValue";

/**
* @brief Decreases the current value of the slider by the specified amount.
*
* @validvalue An int that specifies the amount by which the slider value must be decreased.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(sliderHandle, MAW_SLIDER_DECREASE_VALUE, "20");
* \endcode
*/
mosync.MAW_SLIDER_DECREASE_VALUE = "decreaseValue";

/**
* @copydoc #MAW_SCREEN_TITLE
*/
mosync.MAW_STACK_SCREEN_TITLE = "title";

/**
* @copydoc #MAW_SCREEN_ICON
*/
mosync.MAW_STACK_SCREEN_ICON = "icon";

/**
* @brief Specifies whether the back button automatically should pop the stack screen.
*
* This can have different behaviors on different platforms, on iPhone the UI back button is disabled, on Android the stack screen ignores back button events.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(stackScreenHandle, MAW_STACK_SCREEN_BACK_BUTTON_ENABLED, "false");
* \endcode
*/
mosync.MAW_STACK_SCREEN_BACK_BUTTON_ENABLED = "backButtonEnabled";

/**
* @brief Check if a stack screen is shown.
*
* @validvalue "true" if the stack screen is visible, "false" otherwise.
*
* @getonly
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(stackScreenHandle, MAW_STACK_SCREEN_IS_SHOWN,
*                                    buffer, BUFFER_SIZE);
*	if(result == MAW_RES_OK && strcmp(buffer, "true") == 0)
*	{
*	// Stack screen is visible.
*	}
* \endcode
*/
mosync.MAW_STACK_SCREEN_IS_SHOWN = "isShown";

/**
* @brief Stack screen's push transition type.
*
* Type of the animated transition used when pushing a screen from the current screen stack.
*
* Note: This property is available only Android and Windows Phone. On iOS the native navigation animation is used when pushing a screen.
*
* @validvalue A transition type from the set of available screen transitions found \link #MAW_TRANSITION_TYPE_NONE here \endlink.
*
* @par Example
* \code
*	char buf[32];
* sprintf(buf, "%d", MAW_TRANSITION_TYPE_FADE_IN);
*	maWidgetSetProperty(stackScreenHandle, MAW_STACK_SCREEN_PUSH_TRANSITION_TYPE, buf);
* \endcode
*/
mosync.MAW_STACK_SCREEN_PUSH_TRANSITION_TYPE = "pushTransitionType";

/**
* @brief Stack screen's pop transition type.
*
* Type of the animated transition used when popping a screen from the current screen stack.
*
* Note: This property is available only Android and Windows Phone. On iOS the native navigation animation is used when popping a screen.
*
* @validvalue A transition type from the set of available screen transitions found \link #MAW_TRANSITION_TYPE_NONE here \endlink.
*
* @par Example
* \code
*	char buf[32];
* sprintf(buf, "%d", MAW_TRANSITION_TYPE_FADE_OUT);
*	maWidgetSetProperty(stackScreenHandle, MAW_STACK_SCREEN_POP_TRANSITION_TYPE, buf);
* \endcode
*/
mosync.MAW_STACK_SCREEN_POP_TRANSITION_TYPE = "popTransitionType";

/**
* @brief Stack screen's push transition duration.
*
* Duration of the animated transition used when pushing a screen from the current screen stack.
*
* Note: This property is available only on Android. On iOS the native navigation animation is used when pushing a screen
* and on Windows Phone is ignored due to the constant duration of the native screen transitions.
*
* @validvalue A positive number representing a time interval in milliseconds.
*
* @par Example
* \code
*	char buf[32];
* sprintf(buf, "%d", 300);
*	maWidgetSetProperty(stackScreenHandle, MAW_STACK_SCREEN_PUSH_TRANSITION_DURATION, buf);
* \endcode
*/
mosync.MAW_STACK_SCREEN_PUSH_TRANSITION_DURATION = "pushTransitionDuration";

/**
* @brief Stack screen's pop transition duration.
*
* Duration of the animated transition used when popping a screen from the current screen stack.
*
* Note: This property is available only on Android. On iOS the native navigation animation is used when popping a screen
* and on Windows Phone is ignored due to the constant duration of the native screen transitions.
*
* @validvalue A positive number representing a time interval in milliseconds.
*
* @par Example
* \code
*	char buf[32];
* sprintf(buf, "%d", 300);
*	maWidgetSetProperty(stackScreenHandle, MAW_STACK_SCREEN_POP_TRANSITION_DURATION, buf);
* \endcode
*/
mosync.MAW_STACK_SCREEN_POP_TRANSITION_DURATION = "popTransitionDuration";

/**
* @copydoc MAW_SCREEN_TITLE
*/
mosync.MAW_TAB_SCREEN_TITLE = "title";

/**
* @copydoc MAW_SCREEN_ICON
*/
mosync.MAW_TAB_SCREEN_ICON = "icon";

/**
* @brief Sets or gets the currently open tab to the tab with the given index.
*
* @validvalue A 0-indexed tab number.
*
* @setandget
*
* @par Example set
* \code
*	maWidgetSetProperty(tabScreenHandle, MAW_TAB_SCREEN_CURRENT_TAB, "1");
* \endcode
*
* @par Example get
* \code
*	char currentTabBuffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(
*	tabScreenHandle,
*	MAW_WEB_VIEW_CURRENT_TAB,
*	currentTabBuffer,
*	BUFFER_SIZE);
*	if (result > 0)
*	{
*	// Do something with current tab.
*	}
* \endcode
*/
mosync.MAW_TAB_SCREEN_CURRENT_TAB = "currentTab";

/**
* @brief Check if a tab screen is shown.
*
* @validvalue "true" if the tab screen is visible, "false" otherwise.
*
* @getonly
*
* @par Example
* \code
*	char buffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(tabScreenHandle, MAW_TAB_SCREEN_IS_SHOWN,
*                                    buffer, BUFFER_SIZE);
*	if(result == MAW_RES_OK && strcmp(buffer, "true") == 0)
*	{
*	// Tab screen is visible.
*	}
* \endcode
*/
mosync.MAW_TAB_SCREEN_IS_SHOWN = "isShown";

/**
* @brief Sets or gets the current hour in 24h mode( in the range: 0-23 ).
*
* @validvalue An int that specifies the current hour.
*
* @setandget
*
* @par Example
* \code
*	// Set hour to 20, that is 8PM.
*	maWidgetSetProperty(timePickerHandle, MAW_TIME_PICKER_CURRENT_HOUR, "20");
* \endcode
*/
mosync.MAW_TIME_PICKER_CURRENT_HOUR = "currentHour";

/**
* @brief Sets or gets the current minute (0-59).
*
* @validvalue An int that specifies the current minute.
*
* @setandget
*
* @par Example
* \code
*	char buf[BUFFER_SIZE];
*	maWidgetGetProperty(timePickerHandle, MAW_TIME_PICKER_CURRENT_MINUTE, buf, BUFFER_SIZE);
*	// Do something with the minute.
* \endcode
*/
mosync.MAW_TIME_PICKER_CURRENT_MINUTE = "currentMinute";

/**
* @brief Set or get the checked state of the toggle button.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @par Example
* \code
*	maWidgetSetProperty(toggleButtonHandle, MAW_TOGGLE_BUTTON_CHECKED, "true");
* \endcode
*/
mosync.MAW_TOGGLE_BUTTON_CHECKED = "checked";

/**
* @brief Sets how the children in the layout should be aligned in the vertical axis.
*
* @validvalue One of the constants #MAW_ALIGNMENT_TOP, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_BOTTOM.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_VERTICAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_VERTICAL_LAYOUT_CHILD_VERTICAL_ALIGNMENT = "childVerticalAlignment";

/**
* @brief Sets how the children in the layout should be aligned in the horizontal axis.
*
* @validvalue One of the constants #MAW_ALIGNMENT_LEFT, #MAW_ALIGNMENT_CENTER or #MAW_ALIGNMENT_RIGHT.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_VERTICAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT, MAW_ALIGNMENT_CENTER);
* \endcode
*/
mosync.MAW_VERTICAL_LAYOUT_CHILD_HORIZONTAL_ALIGNMENT = "childHorizontalAlignment";

/**
* @brief Sets the top padding.
*
* @validvalue The top padding in pixels.
*
* @setonly
*
* @par Example
* \code
*  // Set a 50px top padding.
*	maWidgetSetProperty(verticalLayoutHandle, MAW_VERTICAL_LAYOUT_PADDING_TOP, "50");
* \endcode
*/
mosync.MAW_VERTICAL_LAYOUT_PADDING_TOP = "paddingTop";

/**
* @brief Sets the left padding.
*
* @validvalue The left padding in pixels.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_VERTICAL_LAYOUT_PADDING_LEFT, "50");
* \endcode
*/
mosync.MAW_VERTICAL_LAYOUT_PADDING_LEFT = "paddingLeft";

/**
* @brief Sets the right padding.
*
* @validvalue The right padding in pixels.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_VERTICAL_LAYOUT_PADDING_RIGHT, "50");
* \endcode
*/
mosync.MAW_VERTICAL_LAYOUT_PADDING_RIGHT = "paddingRight";

/**
* @brief Sets the bottom padding.
*
* @validvalue The bottom padding in pixels.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_VERTICAL_LAYOUT_PADDING_BOTTOM, "50");
* \endcode
*/
mosync.MAW_VERTICAL_LAYOUT_PADDING_BOTTOM = "paddingBottom";

/**
* @brief Sets the isScrollable boolean
*
* @validvalue "true" or "false", for "true" the layout will become scrollable otherwise it will become unscrollable
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(verticalLayoutHandle, MAW_VERTICAL_LAYOUT_SCROLLABLE, "true");
* \endcode
*/
mosync.MAW_VERTICAL_LAYOUT_SCROLLABLE = "scrollable";

/**
* @brief Play the video.
*/
mosync.MAW_VIDEO_VIEW_ACTION_PLAY = 1;

/**
* @brief Pause the video.
*/
mosync.MAW_VIDEO_VIEW_ACTION_PAUSE = 2;

/**
* @brief Stop the video.
*/
mosync.MAW_VIDEO_VIEW_ACTION_STOP = 3;

/**
* @brief The video is playing.
*/
mosync.MAW_VIDEO_VIEW_STATE_PLAYING = 1;

/**
* @brief The video is paused.
*/
mosync.MAW_VIDEO_VIEW_STATE_PAUSED = 2;

/**
* @brief The video is stopped.
*/
mosync.MAW_VIDEO_VIEW_STATE_STOPPED = 3;

/**
* @brief The video has finished playing.
*/
mosync.MAW_VIDEO_VIEW_STATE_FINISHED = 4;

/**
* @brief The source is ready to be played.
* NOTE: On Android this event is received after loading url/path.
*	On iOS this event is received after PLAYING event is received.
*	On WindowsPhone this event is received after media loding has finished
*/
mosync.MAW_VIDEO_VIEW_STATE_SOURCE_READY = 5;

/**
* @brief Playback is temporarily interruped(maybe there's no data in the buffer).
* NOTE: On WindowsPhone 7 this occurs when an error is encountered.
*/
mosync.MAW_VIDEO_VIEW_STATE_INTERRUPTED = 6;

/**
* @brief Sets the video path.
* Note: available on Android and Windows Phone.
* @validvalue Any valid path.
*
* @setonly
*
* @par Example
* \code
*	// Set the video path.
*	maWidgetSetProperty(videoViewHandle, MAW_VIDEO_VIEW_PATH, "\data\Video1.wav");
* \endcode
*/
mosync.MAW_VIDEO_VIEW_PATH = "path";

/**
* @brief Sets the video url.
*
* @validvalue Any valid streaming url.
*
* @setonly
*
* @par Example
* \code
*	// Set the video path.
*	maWidgetSetProperty(videoViewHandle, MAW_VIDEO_VIEW_URL, "www.example.com/play.m3u8");
* \endcode
*/
mosync.MAW_VIDEO_VIEW_URL = "url";

/**
* @brief Start,pause or stop the video playback.
*
* @validvalue MAW_VIDEO_WIDGET_ACTION_PLAY, MAW_VIDEO_WIDGET_ACTION_PAUSE or MAW_VIDEO_WIDGET_ACTION_STOP constants.
*
* @setonly
*
* @par Example
* \code
*	// Start the playback.
*	maWidgetSetProperty(videoViewHandle, MAW_VIDEO_WIDGET_ACTION, toString(MAW_VIDEO_WIDGET_ACTION_PLAY));
* \endcode
*/
mosync.MAW_VIDEO_VIEW_ACTION = "action";

/**
* @brief Seeks into the video.
*
* @validvalue A valid integer for milliseconds.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(videoViewHandle, MAW_VIDEO_VIEW_SEEK_TO, "10000");
* \endcode
*/
mosync.MAW_VIDEO_VIEW_SEEK_TO = "seekTo";

/**
* @brief Gets the video file duration.
*
* NOTE: On Android this value can be retrieved after MAW_VIDEO_VIEW_STATE_SOURCE_READY is received.
*	On iOS this value can be retrieved after MAW_VIDEO_STATE_PLAYING is received.
* @validvalue An integer representing the total media duration in milliseconds.
*
* @getonly
*
* @par Example
* \code
*	char buf[BUFFER_SIZE];
*	maWidgetGetProperty(videoViewHandle, MAW_VIDEO_VIEW_DURATION, buf, BUFFER_SIZE);
*	// Do something with the duration.
* \endcode
*/
mosync.MAW_VIDEO_VIEW_DURATION = "duration";

/**
* @brief Gets the buffer percentage of the played video file.
*
* @validvalue An int.
*
* @getonly
*
* @par Example
* \code
*	char buf[BUFFER_SIZE];
*	maWidgetGetProperty(videoViewHandle, MAW_VIDEO_VIEW_BUFFER_PERCENTAGE, buf, BUFFER_SIZE);
*	// Do something with the percentage.
* \endcode
*/
mosync.MAW_VIDEO_VIEW_BUFFER_PERCENTAGE = "bufferPercentage";

/**
* @brief Gets the current position in the video file.
*
* @validvalue An integer representing the current media position in seconds.
*
* @getonly
*
* @par Example
* \code
*	char buf[BUFFER_SIZE];
*	maWidgetGetProperty(videoViewHandle, MAW_VIDEO_VIEW_CURRENT_POSITION, buf, BUFFER_SIZE);
*	// Do something with the position.
* \endcode
*/
mosync.MAW_VIDEO_VIEW_CURRENT_POSITION = "currentPosition";

/**
* @brief Show/hide video control.
* Default value is "true"(video control is shown).
* Platform: iOS.
*
* @validvalue "true" show the video control, "false" hide the video control.
*
* @setandget
*
* @par Example
* \code
*	char buf[BUFFER_SIZE];
*	maWidgetGetProperty(videoViewHandle, MAW_VIDEO_VIEW_CONTROL, buf, BUFFER_SIZE);
* \endcode
*/
mosync.MAW_VIDEO_VIEW_CONTROL = "control";

/**
* @brief Set or get the currently displayed url in the web view.
*
* You can also use this property to evaluate JavaScript in the WebView,
* by using a url that starts with "javascript:" followed by the
* JavaScript code.
*
* Note that if the url is a non-local url that will cause data to
* be downloaded over the network, you need to set "Internet Access"
* permissions for the application.
*
* @validvalue Any valid URL.
*
* @setandget
*
* @par Example
* @code
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_URL, "http://www.mosync.com/");
* @endcode
*
* @code
*	maWidgetSetProperty(
*	webViewHandle,
*	MAW_WEB_VIEW_URL,
*	"javascript:document.body.innerHTML= '<p>Hello World</p>'");
* @endcode
*/
mosync.MAW_WEB_VIEW_URL = "url";

/**
* @brief Set the currently displayed HTML data in the web view.
*
* @validvalue Any valid HTML data.
*
* @setonly
*
* @par Example
* @code
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_HTML, "<h1>Hello World</h1>");
* @endcode
*/
mosync.MAW_WEB_VIEW_HTML = "html";

/**
* @brief Set the base URL used by the web-view when loading relative paths.
* The value of this URL is used when setting the #MAW_WEB_VIEW_URL and
* #MAW_WEB_VIEW_HTML properties. The default value for this property points to
* the Assets folder in the local file system ("file://pathToLocalFileSystem/Assets/").
*
* @note Use: #maGetSystemProperty ("mosync.path.local.url") to find the baseURL
* for the local file system.
*
* @validvalue Any valid URL schema.
*
* @setandget
*/
mosync.MAW_WEB_VIEW_BASE_URL = "baseUrl";

/**
* @brief Set the pattern used to "soft hook" urls, to get notified
* when pages are being loaded.
*
* When this pattern matches a url that is being requested
* to load in the WebView, event #MAW_EVENT_WEB_VIEW_HOOK_INVOKED
* is sent, and the page loads NORMALLY.
*
* Note that when receiving event #MAW_EVENT_WEB_VIEW_HOOK_INVOKED
* you MUST deallocate the urlData handle of the event by calling
* maDestroyPlaceholder on the handle. Destory the handle when you are
* done reading the url data, to avoid that memory will get used up.
*
* The pattern is a url pattern specified using regular expression
* syntax, according to the ICU regular expression standard, using
* complete match. For example, the ".*" matching expression is used
* to match any url string. To match all HTTP requests, use the
* pattern "http://.*". To match all requests for a specific domain,
* use a pattern like ".*google.com.*". For further infomation, see:
* http://userguide.icu-project.org/strings/regexp
* When typing a C-string with a pattern that contains a matching
* expression with a backslash, make sure to escape the backslash,
* for example "\B" should be "\\B".
*
* By setting the pattern to an empty string, the soft hook mechanism
* is turned off, and #MAW_EVENT_WEB_VIEW_HOOK_INVOKED is not sent.
*
* Both "soft" hooks and "hard" hooks can be enabled simultaneously,
* but only one hook pattern can be used for each type of hook. When
* setting a new hook pattern, the old hook is replaced.
*
* Note that urls opened using maWidgetSetProperty with the property
* MAW_WEB_VIEW_URL are NOT hooked. This way of loading a page is
* excluded from the hook mechanism to prevent "loops" when loading
* pages.
*
* @validvalue A string with a url pattern.
*
* @setonly
*
* @par Example
* @code
*	// Hook all urls.
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_SOFT_HOOK, ".*");
*
*	// Hook no urls.
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_SOFT_HOOK, "");
*
*	// Hook urls that start with "mosync:".
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_SOFT_HOOK, "mosync://.*");
* @endcode
*/
mosync.MAW_WEB_VIEW_SOFT_HOOK = "softHook";

/**
* @brief Set the pattern used to "hard hook" urls, to get notified
* and prevent loading of pages.
*
* Hard hooks are useful for communicating events from a WebView,
* for example by setting document.location to a url string in
* JavaScript. Example: document.location = 'mosync://ExitApp'
* The application can then examine the url data and take action
* depending on the url content.
*
* When this pattern matches a url that is being requested
* to load in the WebView, event #MAW_EVENT_WEB_VIEW_HOOK_INVOKED
* is sent, and page loading is ABORTED.
*
* Note that when receiving event #MAW_EVENT_WEB_VIEW_HOOK_INVOKED
* you MUST deallocate the urlData handle of the event by calling
* maDestroyPlaceholder on the handle. Destory the handle when you are
* done reading the url data, to avoid that memory will get used up.
*
* The pattern is a url pattern specified using regular expression
* syntax, according to the ICU regular expression standard, using
* complete match. For example, the ".*" matching expression is used
* to match any url string. To match all HTTP requests, use the
* pattern "http://.*". To match all requests for a specific domain,
* use a pattern like ".*google.com.*". For further infomation, see:
* http://userguide.icu-project.org/strings/regexp
* When typing a C-string with a pattern that contains a matching
* expression with a backslash, make sure to escape the backslash,
* for example "\B" should be "\\B".
*
* By setting the pattern to an empty string, the soft hook mechanism
* is turned off, and #MAW_EVENT_WEB_VIEW_HOOK_INVOKED is not sent.
*
* Both "soft" hooks and "hard" hooks can be enabled simultaneously,
* but only one hook pattern can be used for each type of hook. When
* setting a new hook pattern, the old hook is replaced.
*
* The "hard" hook property takes precedence over the "soft" hook
* property. When both properties are set,
* #MAW_EVENT_WEB_VIEW_HOOK_INVOKED is sent once, for the
* "hard" hook type.
*
* Note that urls opened using maWidgetSetProperty with the property
* MAW_WEB_VIEW_URL are NOT hooked. This way of loading a page is
* excluded from the hook mechanism to prevent "loops" when loading
* pages.
*
* @validvalue A string with a url pattern.
*
* @setonly
*
* @par Example
* @code
*	// Hook urls that start with "mosync:".
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_HARD_HOOK, "mosync://.*");
* @endcode
*/
mosync.MAW_WEB_VIEW_HARD_HOOK = "hardHook";

/**
* @brief Property to get a new url whenever the webview changes the url.
* See #MAW_EVENT_WEB_VIEW_URL_CHANGED.
*
* @deprecated Use event #MAW_EVENT_WEB_VIEW_HOOK_INVOKED
*
* @validvalue Any valid URL.
*
* @getonly
*
* @par Example
* @code
*	char urlBuffer[BUFFER_SIZE];
*	int result = maWidgetGetProperty(
*	  webViewHandle,
*	  MAW_WEB_VIEW_NEW_URL,
*	  urlBuffer,
*	  BUFFER_SIZE);
*	if (result > 0)
*	{
*	// Do something with URL.
*	}
* @endcode
*/
mosync.MAW_WEB_VIEW_NEW_URL = "newurl";

/**
* @brief Sets or gets whether the horizontal scrollbar should be drawn or not.
* Available only on Android for the moment.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_HORIZONTAL_SCROLLBAR_ENABLED, "true");
* \endcode
*/
mosync.MAW_WEB_VIEW_HORIZONTAL_SCROLL_BAR_ENABLED = "horizontalScrollBarEnabled";

/**
* @brief Sets or gets whether the vertical scrollbar should be drawn or not.
* The scrollbar is drawn by default.
* Available only on Android for the moment.
*
* @validvalue A boolean string 'true' or 'false'.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_VERTICAL_SCROLLBAR_ENABLED, "false");
* \endcode
*/
mosync.MAW_WEB_VIEW_VERTICAL_SCROLL_BAR_ENABLED = "verticalScrollBarEnabled";

/**
* @brief Enable or disable the zoom controls of the web view.
*
* @validvalue "true" to enable, "false" to disable.
*
* @setonly
*
* @par Example
* @code
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_ENABLE_ZOOM, "true");
* @endcode
*/
mosync.MAW_WEB_VIEW_ENABLE_ZOOM = "enableZoom";

/**
* @brief Navigate forward or back the browsing history.
*
* @validvalue "back" or "forward".
*
* @setonly
*
* @par Example
* @code
*	maWidgetSetProperty(webViewHandle, MAW_WEB_VIEW_NAVIGATE, "back");
* @endcode
*/
mosync.MAW_WEB_VIEW_NAVIGATE = "navigate";

/**
* @brief Constant that represents a left aligned widget.
*/
mosync.MAW_ALIGNMENT_LEFT = "left";

/**
* @brief Constant that represents a right aligned widget.
*/
mosync.MAW_ALIGNMENT_RIGHT = "right";

/**
* @brief Constant that represents a center aligned widget.
*/
mosync.MAW_ALIGNMENT_CENTER = "center";

/**
* @brief Constant that represents a top aligned widget.
*/
mosync.MAW_ALIGNMENT_TOP = "top";

/**
* @brief Constant that represents a bottom aligned widget.
*/
mosync.MAW_ALIGNMENT_BOTTOM = "bottom";

/**
* @brief A handle to the MoSync canvas screen. Use maWidgetScreenShow with this handle to show the initial mosync canvas.
*/
mosync.MAW_CONSTANT_MOSYNC_SCREEN_HANDLE = 0;

/**
* @brief If set to the width or height of a widget and the parent is either a vertical or horizontal layout it tries to fill the available space in that dimension. If there are multiple widgets specified with this constant, the space will then be shared equally. If the parent isn't a horizontal or vertical layout it just resizes the child to the size of its parent.
*/
mosync.MAW_CONSTANT_FILL_AVAILABLE_SPACE = -1;

/**
* @brief If set to the width or height of a widget it will be as big as its content in that dimension.
*/
mosync.MAW_CONSTANT_WRAP_CONTENT = -2;

/**
* @brief Loading a page has started. Used in
* #MAW_EVENT_WEB_VIEW_CONTENT_LOADED.
*/
mosync.MAW_CONSTANT_STARTED = 1;

/**
* @brief Loading a page is done. Used in
* #MAW_EVENT_WEB_VIEW_CONTENT_LOADED.
*/
mosync.MAW_CONSTANT_DONE = 2;

/**
* @brief Loading a page has stopped (aborted). Used in
* #MAW_EVENT_WEB_VIEW_CONTENT_LOADED.
*/
mosync.MAW_CONSTANT_STOPPED = 3;

/**
* @brief Loading a page has failed. Used in
* #MAW_EVENT_WEB_VIEW_CONTENT_LOADED.
*/
mosync.MAW_CONSTANT_ERROR = -1;

/**
* @brief The hook type is a soft hook. Used in
* #MAW_EVENT_WEB_VIEW_HOOK_INVOKED.
*/
mosync.MAW_CONSTANT_SOFT = 5;

/**
* @brief The hook type is a hard hook. Used in
* #MAW_EVENT_WEB_VIEW_HOOK_INVOKED.
*/
mosync.MAW_CONSTANT_HARD = 6;

/**
* @brief The hook type is a message sendt from JavaScript.
* Used in #MAW_EVENT_WEB_VIEW_HOOK_INVOKED.
* This type of hook does not use any hook pattern, it is
* always sent from the browser, using a platform specific
* method (which is abstracted away in the libraries).
*/
mosync.MAW_CONSTANT_MESSAGE = 7;

/**
* @brief The popover arrow should point up. Used in
* #MAW_MODAL_DIALOG_ARROW_POSITION.
*/
mosync.MAW_CONSTANT_ARROW_UP = 1;

/**
* @brief The popover arrow should point down. Used in
* #MAW_MODAL_DIALOG_ARROW_POSITION.
*/
mosync.MAW_CONSTANT_ARROW_DOWN = 2;

/**
* @brief The popover arrow should point left. Used in
* #MAW_MODAL_DIALOG_ARROW_POSITION.
*/
mosync.MAW_CONSTANT_ARROW_LEFT = 4;

/**
* @brief The popover arrow should point right. Used in
* #MAW_MODAL_DIALOG_ARROW_POSITION.
*/
mosync.MAW_CONSTANT_ARROW_RIGHT = 8;

/**
* @brief The popover arrow can point anywhere. Used in
* #MAW_MODAL_DIALOG_ARROW_POSITION.
*/
mosync.MAW_CONSTANT_ARROW_ANY = 15;

/**
* @brief A pointer pressed event has occurred.
*/
mosync.MAW_EVENT_POINTER_PRESSED = 2;

/**
* @brief A pointer released event has occurred.
*/
mosync.MAW_EVENT_POINTER_RELEASED = 3;

/**
* @brief This event is not used and has been deprecated.
*
* @deprecated Use #MAW_EVENT_WEB_VIEW_CONTENT_LOADING.
*/
mosync.MAW_EVENT_CONTENT_LOADED = 4;

/**
* @brief Sent when something is clicked.
*/
mosync.MAW_EVENT_CLICKED = 5;

/**
* @brief Sent when an item in a list view is clicked.
*/
mosync.MAW_EVENT_ITEM_CLICKED = 6;

/**
* @brief Sent when a tab widget has changed to a new tab.
*/
mosync.MAW_EVENT_TAB_CHANGED = 7;

/**
* @brief Sent when an GLView has been initialized and is ready for setup.
*/
mosync.MAW_EVENT_GL_VIEW_READY = 8;

/**
 * @brief Sent when the URL of a web view changes
 * @deprecated Use event #MAW_EVENT_WEB_VIEW_HOOK_INVOKED.
 */
mosync.MAW_EVENT_WEB_VIEW_URL_CHANGED = 9;

/**
 * @brief Sent when a screen has been popped from a stack screen.
 */
mosync.MAW_EVENT_STACK_SCREEN_POPPED = 10;

/**
 * @brief Sent when the progress level has been changed.
 * This includes changes that were initiated by the user through a touch gesture,
 * or arrow key/trackball as well as changes that were initiated programmatically.
 */
mosync.MAW_EVENT_SLIDER_VALUE_CHANGED = 11;

/**
 * @brief Sent when the user changes\d the date in a Date Picker.
 */
mosync.MAW_EVENT_DATE_PICKER_VALUE_CHANGED = 12;

/**
 * @brief Sent when the user changes\d the time in a Time Picker.
 */
mosync.MAW_EVENT_TIME_PICKER_VALUE_CHANGED = 13;

/**
 * @brief Sent when the user changes\d the value in a Number Picker.
 */
mosync.MAW_EVENT_NUMBER_PICKER_VALUE_CHANGED = 14;

/**
 * @brief Sent from the Video View when the state of the video has changed.
 */
mosync.MAW_EVENT_VIDEO_STATE_CHANGED = 15;

/**
 * @brief Sent from the Edit box when it gains focus(the user selects the widget).
 * The virtual keyboard is shown.
 */
mosync.MAW_EVENT_EDIT_BOX_EDITING_DID_BEGIN = 16;

/**
 * @brief Sent from the Edit box when it loses focus.
 * The virtual keyboard is hidden.
 */
mosync.MAW_EVENT_EDIT_BOX_EDITING_DID_END = 17;

/**
 * @brief Sent from the Edit box when the text was changed.
 */
mosync.MAW_EVENT_EDIT_BOX_TEXT_CHANGED = 18;

/**
 * @brief Sent from the Edit box when the return button was pressed.
 * On iOS platform the virtual keyboard is not closed after receiving this event.
 * The virtual keyboard can be hided by setting the MAW_EDIT_BOX_SHOW_KEYBOARD to "false".
 * This event is send only if the edit box mode is #MAW_EDIT_BOX_SINGLE_LINE.
 * Not available on Windows Phone 7.1
 */
mosync.MAW_EVENT_EDIT_BOX_RETURN = 19;

/**
* @brief A WebView widget reports status of loading
* page content. Event parameter status is set to one
* of the following values:
*	#MAW_CONSTANT_STARTED
*	#MAW_CONSTANT_DONE
*	#MAW_CONSTANT_STOPPED
*	#MAW_CONSTANT_ERROR
*/
mosync.MAW_EVENT_WEB_VIEW_CONTENT_LOADING = 20;

/**
* @brief A web view hook has captured a url.
*
* The event parameter hookType is set to
* the type of hook, one of:
*	#MAW_CONSTANT_SOFT
*	#MAW_CONSTANT_HARD
*
* Event parameter urlData is a handle to the url that
* has been captured.
*
* Use syscall maGetDataSize to get the size of the url data
* and maReadData to access the data.
*
* NOTE: When you get this message you have ownership
* of the url data handle and you have the responsibility to
* deallocate it using maDestroyPlaceholder.
*
* To get this event, you need to register a hook pattern, using
* maWidgetSetProperty with the properties #MAW_WEB_VIEW_SOFT_HOOK
* and/or #MAW_WEB_VIEW_HARD_HOOK.
*/
mosync.MAW_EVENT_WEB_VIEW_HOOK_INVOKED = 21;

/**
* Send by a Dialog widget when when a user dismisses a popover by tapping outside of it.
* It will not be sent if it was dismissed by calling #maWidgetModalDialogHide().
* Available only on the iPad.
*/
mosync.MAW_EVENT_DIALOG_DISMISSED = 22;

/**
* Send by current screen just before it begins rotating.
* Platform: iOS.
*/
mosync.MAW_EVENT_SCREEN_ORIENTATION_WILL_CHANGE = 23;

/**
* Send by current screen after it finishes rotating.
* Platform: iOS, Android and Windows Phone 7.1
*/
mosync.MAW_EVENT_SCREEN_ORIENTATION_DID_CHANGE = 24;

/**
* @brief Send when the value in a Rating Bar.
*/
mosync.MAW_EVENT_RATING_BAR_VALUE_CHANGED = 25;

/**
* @brief Send when one of the radio buttons in a radio group is selected.
*/
mosync.MAW_EVENT_RADIO_GROUP_ITEM_SELECTED = 26;

/**
* @brief Send whenthe radio button state is changed.
*/
mosync.MAW_EVENT_RADIO_BUTTON_STATE_CHANGED = 27;

/**
* @brief Send when the Options Menu is being closed (either by the user canceling
* the menu with the back/menu button, or when an item is selected).
*/
mosync.MAW_EVENT_OPTIONS_MENU_CLOSED = 28;

/**
* @brief Send when an item in your options menu is selected.
*/
mosync.MAW_EVENT_OPTIONS_MENU_ITEM_SELECTED = 29;

/**
* @brief Sent when the zoom level of a map widget has changed (if the user zoomed in or out).
*/
mosync.MAW_EVENT_MAP_ZOOM_LEVEL_CHANGED = 30;

/**
* @brief Sent when the visible region on the map has changed (if the user scrolled/draged the map).
*/
mosync.MAW_EVENT_MAP_REGION_CHANGED = 31;

/**
 * @brief Sent when a map pin is clicked by the user.
 */
mosync.MAW_EVENT_MAP_PIN_CLICKED = 32;

/**
* @brief Sent by a ListView when an item is about to be selected.
* The listItemIndex member from MAWidgetEventData struct will contain the item index
* that is about to be selected.
* Available only on iOS.
*/
mosync.MAW_EVENT_ITEM_WILL_SELECT = 33;

/**
* @brief Sent by a Segmented or Alphabetical ListView when an item is selected.
* The event will contain the sectionIndex and the sectionItemIndex coresponding to the
* selected item.
* Available on Windows Phone 7, Android and iOS.
*/
mosync.MAW_EVENT_SEGMENTED_LIST_ITEM_CLICKED = 34;

/**
* @brief Sent by a Segmented ListViewItem when its insert button is clicked.
* The event will contain the sectionIndex and the sectionItemIndex coresponding of the
* item. Insert button is visible only in editing mode and if its editing style is
* #MAW_LIST_VIEW_ITEM_EDIT_STYLE_INSERT.
* Available on iOS.
*/
mosync.MAW_EVENT_SEGMENTED_LIST_ITEM_INSERT_BTN = 35;

/**
* @brief Sent by a Segmented ListViewItem when its delete button is clicked.
* The event will contain the sectionIndex and the sectionItemIndex coresponding of the
* item. The delete button is visible only in editing mode and if its editing style is
* #MAW_LIST_VIEW_ITEM_EDIT_STYLE_DELETE.
* Available on iOS.
*/
mosync.MAW_EVENT_SEGMENTED_LIST_ITEM_DELETE_BTN = 36;

/**
* @brief Sent by a CustomPicker when user selects an item.
* The event will contain the selected item index in customPickerItemIndex.
* Available on iOS.
*/
mosync.MAW_EVENT_CUSTOM_PICKER_ITEM_SELECTED = 37;

/**
* @brief Send when the home item from the Action Bar is selected.
* Available on Android.
*/
mosync.MAW_EVENT_ACTION_BAR_UP_ITEM_SELECTED = 38;

/**
* @brief Send when an item from the Action Bar is selected.
* Available on Android.
*/
mosync.MAW_EVENT_ACTION_BAR_MENU_ITEM_SELECTED = 39;

/**
* The available widget properties for all widgets.
*/
/**
* @brief Sets or gets the horizontal distance from the parent widget in a RelativeLayout.
*
* @validvalue A positive integer in number of pixels.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_LEFT, "100");
* \endcode
*/
mosync.MAW_WIDGET_LEFT = "left";

/**
* @brief Specifies the vertical distance from the parent widget in a RelativeLayout.
*
* @validvalue A positive integer in number of pixels.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_TOP, "100");
* \endcode
*/
mosync.MAW_WIDGET_TOP = "top";

/**
* @brief Sets or gets the width of a widget.
*
* @validvalue A positive integer in pixles, or any of the constants #MAW_CONSTANT_FILL_AVAILABLE_SPACE, #MAW_CONSTANT_WRAP_CONTENT.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_WIDTH, "100");
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_WIDTH, MAW_CONSTANT_FILL_AVAILABLE_SPACE);
* \endcode
*/
mosync.MAW_WIDGET_WIDTH = "width";

/**
* @brief Sets or gets the height of a widget.
*
* @validvalue A positive integer in pixles, or any of the constants #MAW_CONSTANT_FILL_AVAILABLE_SPACE, #MAW_CONSTANT_WRAP_CONTENT.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_HEIGHT, "100");
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_HEIGHT, MAW_CONSTANT_FILL_AVAILABLE_SPACE);
* \endcode
*/
mosync.MAW_WIDGET_HEIGHT = "height";

/**
* @brief Sets the transparency of the widget background.
* On Android this property is available for the moment only on Layouts and ImageWidget widgets.
*
* @validvalue A float between 0.0 and 1.0, where 0.0 is fully transparent and 1.0 is opaque.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_ALPHA, "0.0"); // Not visible
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_ALPHA, "0.5"); // Half visible
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_ALPHA, "1.0"); // Fully visible
* \endcode
*/
mosync.MAW_WIDGET_ALPHA = "alpha";

/**
* @brief Specifies the background color of a widget.
*
* @validvalue A hexadecimal value 0xRRGGBB, where R, G and B are the red, green and blue components respectively.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_BACKGROUND_COLOR, "0xff0000"); // Red
* \endcode
*/
mosync.MAW_WIDGET_BACKGROUND_COLOR = "backgroundColor";

/**
* @brief Sets whether the widget is visible or not. Layouts ignore invisible widgets.
*
* @validvalue A boolean string 'true' or 'false', where true is visible and false is invisible.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_VISIBLE, "false");
* \endcode
*/
mosync.MAW_WIDGET_VISIBLE = "visible";

/**
* @brief Sets whether the widget is enabled or not. If not, the widget is grayed out.
*
* Widgets are enabled by default.
*
* @validvalue A boolean string 'true' or 'false', where true is enabled and false is disabled.
*
* @setandget
*
* @par Example
* \code
*	maWidgetSetProperty(buttonHandle, MAW_WIDGET_ENABLED, "false");
* \endcode
*/
mosync.MAW_WIDGET_ENABLED = "enabled";

/**
* @brief Specifies the background gradient of a widget.
* Currently implemented only on Android.
*
* @validvalue Two hexadecimal values 0xRRGGBB, where R, G and B are the red, green and blue components respectively,
* separated by comma.
*
* @setonly
*
* @par Example
* \code
*	maWidgetSetProperty(widgetHandle, MAW_WIDGET_BACKGROUND_GRADIENT,  "0x27408B,0xCAE1FF");
* \endcode
*/
mosync.MAW_WIDGET_BACKGROUND_GRADIENT = "backgroundGradient";

/**
* @brief Indicates that the call to a widget syscall was successful.
*/
mosync.MAW_RES_OK = 0;

/**
* @brief Indicates that the call to a widget syscall was unsuccessful.
*/
mosync.MAW_RES_ERROR = -2;

/**
* @brief Indicates that the call to maWidgetSetProperty or maWidgetGetProperty received an invalid property name.
*/
mosync.MAW_RES_INVALID_PROPERTY_NAME = -2;

/**
* @brief Indicates that the call to maWidgetSetProperty or maWidgetGetProperty received an invalid property value.
*/
mosync.MAW_RES_INVALID_PROPERTY_VALUE = -3;

/**
* @brief Indicates that the call to a widget function received an invalid handle.
*/
mosync.MAW_RES_INVALID_HANDLE = -4;

/**
* @brief Indicates that the call maWidgetCreate received an invalid type name.
*/
mosync.MAW_RES_INVALID_TYPE_NAME = -5;

/**
* @brief Indicates that the call to maWidgetInsertChild received an invalid index.
*/
mosync.MAW_RES_INVALID_INDEX = -6;

/**
* @brief Indicates that the call maWidgetGetProperty needs a larger buffer.
*/
mosync.MAW_RES_INVALID_STRING_BUFFER_SIZE = -7;

/**
* @brief Indicates that maWidgetScreenShow received an invalid (non-screen) widget handle.
*/
mosync.MAW_RES_INVALID_SCREEN = -8;

/**
* @brief Indicates that the caller tried to add a widget to a non-layout.
*/
mosync.MAW_RES_INVALID_LAYOUT = -9;

/**
* @brief Indicates that the caller tried to remove a visible root widget (screen) and the MoSync view will become visible.
*/
mosync.MAW_RES_REMOVED_ROOT = -10;

/**
* @brief Indicates that a syscall tried to access a feature that is not supported by the current framework version.
*/
mosync.MAW_RES_FEATURE_NOT_AVAILABLE = -11;

/**
* @brief Indicates that a syscall tried to add a dialog to a parent, which cannot be done because dialogs are in fact
* containers for other widgets.
*/
mosync.MAW_RES_CANNOT_INSERT_DIALOG = -12;

/**
* \brief Indicates that the screen transition is not available on current platform.
 */
mosync.MAW_RES_INVALID_SCREEN_TRANSITION_TYPE = -13;

/**
 * \brief Indicates that the screen transition duration is invalid.
 */
mosync.MAW_RES_INVALID_SCREEN_TRANSITION_DURATION = -14;

/**
* @brief A screen is the root of all widgets currently visible on a screen. See \ref WidgetScreenProperties "Screen properties" for the properties available.
*/
mosync.MAW_SCREEN = "Screen";

/**
* @brief A tab screen is a special type of screen that can have any number of sub-screens each switchable using a tab bar. See \ref WidgetTabScreenProperties "Tab screen properties" for the properties available.
*/
mosync.MAW_TAB_SCREEN = "TabScreen";

/**
* @brief A stack screen is a special type of screen that manages navigation
* between a set of screens.
*
* The screen stack can be pushed or popped. Pushing a given screen will hide
* the current screen and display the pushed screen. Popping a screen hides
* the current screen and shows the previous screen in the stack. See
* maWidgetStackScreenPush() and maWidgetStackScreenPop().
*
* Navigation between the screens in the stack is handled according to the
* norm on the specific platform. On iPhone a navigation bar is added to each
* pushed screen that can be used to go back, while on Android there is no
* extra UI added and the back button is used to go back to the previous screen.
* See \ref WidgetStackScreenProperties "Stack screen properties" for the
* properties available.
*/
mosync.MAW_STACK_SCREEN = "StackScreen";

/**
* @brief A button is a widget that represent a physical button that can be pressed. See \ref WidgetButtonProperties "Button properties" for the properties available.
*/
mosync.MAW_BUTTON = "Button";

/**
* @brief An image is a widget that can be used to display an image. See \ref WidgetImageProperties "Image properties" for the properties available.
*/
mosync.MAW_IMAGE = "Image";

/**
* @brief An image button is a button that will also affect the appearance of the background image when pressed. See \ref WidgetImageButtonProperties "Image button properties" for the properties available.
*/
mosync.MAW_IMAGE_BUTTON = "ImageButton";

/**
* @brief A label is a widget that can be used to display static non-editable text. See \ref WidgetLabelProperties "Label properties" for the properties available.
*/
mosync.MAW_LABEL = "Label";

/**
* @brief An editbox is an editable label. See \ref WidgetEditBoxProperties "Editbox properties" for the properties available.
*/
mosync.MAW_EDIT_BOX = "EditBox";

/**
* @brief A list view is a vertical list of widgets that is also scrollable.
* When creating a list view object the #MAW_LIST_VIEW_TYPE property must be immediately set.
*/
mosync.MAW_LIST_VIEW = "ListView";

/**
* @brief A list view item is a special kind of layout compatible with the list view. That has a predefined common layout for adding text, an icon etc. See \ref WidgetListViewItemProperties "List view item properties" for the properties available.
*/
mosync.MAW_LIST_VIEW_ITEM = "ListViewItem";

/**
 * @brief A check box is a widget that acts like a physical switch. When pressed it will toggle its internal state that can either be checked or non-checked. See \ref WidgetCheckBoxProperties "Check box properties" for the properties available.
 * If you want to display it with a "light" indicator, as it is on iOS use a Toggle Button instead.

 */
mosync.MAW_CHECK_BOX = "CheckBox";

/**
 * @brief A horizontal layout is a layout that stacks widgets in the horizontal axis. See \ref WidgetHorizontalLayoutProperties "Horizontal layout properties" for the properties available.
 */
mosync.MAW_HORIZONTAL_LAYOUT = "HorizontalLayout";

/**
 * @brief A vertical layout is a layout that stacks widgets in the vertical axis. See \ref WidgetVerticalLayoutProperties "Vertical layout properties" for the properties available.
 */
mosync.MAW_VERTICAL_LAYOUT = "VerticalLayout";

/**
 * @brief A relative layout is a layout that layouts widgets relative to its coordinate system. See \ref WidgetRelativeLayoutProperties "Relative layout properties" for the properties available.
 */
mosync.MAW_RELATIVE_LAYOUT = "RelativeLayout";

/**
 * @brief A search bar is a special kind of edit box that is used for searching. See \ref WidgetSearchBarProperties "Search bar properties" for the properties available.
 */
mosync.MAW_SEARCH_BAR = "SearchBar";

/**
 * @brief A nav bar is an iphone specific widget that shows a nav bar with an optional title and back button. See \ref WidgetNavBarProperties "Nav bar properties" for the properties available.
 * See \ref WidgetNavBarProperties "Navigation Bar properties" for the properties available.
 */
mosync.MAW_NAV_BAR = "NavBar";

/**
 * @brief A GL view is a widget that is used to display graphics rendered by the GPU using OpenGL|ES 1.0/1.1 calls. See \ref WidgetGLViewProperties "GL view properties" for the properties available.
 */
mosync.MAW_GL_VIEW = "GLView";

/**
 * @brief A GL view is a widget that is used to display graphics rendered by the GPU using OpenGL|ES 2.0 calls. See \ref WidgetGLViewProperties "GL view properties" for the properties available.
 */
mosync.MAW_GL2_VIEW = "GL2View";

/**
 * @brief A Camera preview widget is a widget that can bound to a camera and contain the live veiw data from the camera.
 */
mosync.MAW_CAMERA_PREVIEW = "CameraPreview";

/**
 * @brief A web view is a widget used to render web pages. See \ref WidgetWebViewProperties "Web view properties" for the properties available.
 */
mosync.MAW_WEB_VIEW = "WebView";

/**
 * @brief A progress bar is a visual indicator of progress in some operation.
 * Displays a bar to the user representing how far the operation has progressed.
 * A progress bar can also be made indeterminate, when the length of the task is unknown.
 *
 * See \ref WidgetProgressBarProperties "Progress bar properties" for the properties available.
 */
mosync.MAW_PROGRESS_BAR = "ProgressBar";

/**
 * @brief An activity indicator is a visual indicator of progress in some operation.
 * It shows a cyclic animation without an indication of progress.
 * It is used when the length of the task is unknown.
 *
 * See \ref WidgetActivityIndicatorProperties "Activity Indicator properties" for the properties available.
 */
mosync.MAW_ACTIVITY_INDICATOR = "ActivityIndicator";

/**
 * @brief A Slider is an extension of ProgressBar that adds a draggable thumb.
 * The user can touch the thumb and drag left or right to set the current progress level.
 *
 * See \ref WidgetSliderProperties "Slider properties" for the properties available.
 */
mosync.MAW_SLIDER = "Slider";

/**
 * @brief A Date Picker is a widget for selecting a date. The date can be selected by a year, month, and day spinners.
 * The minimal and maximal date from which dates to be selected can be customized.
 * The picker is initialized with the current system date.
 *
 * See \ref WidgetDatePickerProperties "Date Picker properties" for the properties available.
 */
mosync.MAW_DATE_PICKER = "DatePicker";

/**
 * @brief A Time Picker is a widget for selecting time of day, in 24 hour mode.
 * The hour and each minute digit can be controlled by vertical spinners.
 * The hour can be entered by keyboard input.
 * Availabe only on iOS for the moment.
 * See \ref WidgetTimePickerProperties "Time Picker properties" for the properties available.
 */
mosync.MAW_TIME_PICKER = "TimePicker";

/**
 * @brief A Number Picker is a widget that enables the user to select a number from a predefined range.
 * Available on iOS, WindowsPhone and Android.
 * See \ref WidgetNumberPickerProperties "Number Picker properties" for the properties available.
 */
mosync.MAW_NUMBER_PICKER = "NumberPicker";

/**
 * @brief A Video View displays a video file.
 * By default, it has attached a controller view that typically contains the buttons like
 * "Play/Pause", "Rewind", "Fast Forward" and a progress slider.
 * See \ref WidgetVideoViewProperties "Video View properties" for the properties available.
 */
mosync.MAW_VIDEO_VIEW = "VideoView";

/**
 * @brief A Toggle Button is a widget that acts like a physical switch. Displays checked/unchecked states as a button with a "light" indicator and by default accompanied with the text "ON" or "OFF".
 * It is available on Android, iOS and Windows Phone 7.
 * When pressed it will toggle its internal state that can either be checked or non-checked. See \ref WidgetToggleButtonProperties "Toggle button properties" for the properties available.
 */
mosync.MAW_TOGGLE_BUTTON = "ToggleButton";

/**
* @brief A dialog is a sort of modal view, that can look different depending on the platform.
* A Dialog gets visible only after calling maWidgetModalDialogShow().
* On Android it is a modal alert dialog.
* On iPad it is a PopoverController, and on iPhone it is a modal view.
* On Windows Phone, it's a Popup having inside a StackPanel which contains all the controls added to the dialog view.
* When a Dialog widget is created it is empty, it has no content. Any type of widget can be added inside it via #maWidgetAddChild syscalls.
* To show a Dialog call #maWidgetModalDialogShow(), to dismiss it call: #maWidgetModalDialogHide(), and to delete it call #maWidgetDestroy.
* See \ref WidgetModalDialogProperties "Modal Dialog properties" for the properties available.
*/
mosync.MAW_MODAL_DIALOG = "ModalDialog";

/**
* @brief A panorama control is a Windows Phone 7 specific control. The paroramaView is a screen container
*	 which may contain more then one screen. A screen can spann over the hardware screen width.
*	 In order to enable this you will have to set the width property of a screen to a certain value.
*	 For more information regarding this control please check the following link:
*	 http://msdn.microsoft.com/en-us/library/ff941104(v=vs.92).aspx
*
* Available only on Windows Phone 7
* See \ref WidgetPanoramaViewProperties "Panorama View properties" for the properties available
*/
mosync.MAW_PANORAMA_VIEW = "PanoramaView";

/**
* @brief A radio button available only on Android. A radio button can only have a \ref MAW_RADIO_GROUP parent.
* Checking one radio button that belongs to a radio group unchecks any previously checked radio button within the same group.
* Initially, all of the radio buttons are unchecked.
* While it is not possible to uncheck a particular radio button, the radio group can be cleared to remove the checked state.
* See \ref WidgetRadioButtonProperties "Radio Button properties" for the properties available.
*/
mosync.MAW_RADIO_BUTTON = "RadioButton";

/**
* \brief A radio group is available only on Android.
* This class is used to create a multiple-exclusion scope for a set of the \link #MAW_RADIO_BUTTON RADIO_BUTTONS \endlink .
* See \ref WidgetRadioGroupProperties "Radio Group properties" for the properties available.
*/
mosync.MAW_RADIO_GROUP = "RadioGroup";

/**
* @brief A RatingBar is an extension of Slider and ProgressBar that shows a rating in stars.
* The user can touch/drag or use arrow keys to set the rating when using the default size RatingBar.
* When using a RatingBar that supports user interaction, placing widgets to the left or right of the
* RatingBar is discouraged.
* See \ref WidgetRatingBarProperties "Rating Bar properties" for the properties available.
*/
mosync.MAW_RATING_BAR = "RatingBar";

/**
* @brief The map widget will contain the google map (on iOS and Android) and the bing map (on Windows Phone)
* controls and will allow the user to interract with the map.
* See \ref WidgetMapProperties "Map properties" for the properties available.
*/
mosync.MAW_MAP = "Map";

/**
 * @brief A map pin can pe placend on the map at a given set of coordinates and responds to click events.
 * See \ref WidgetMapPinProperties "Map pin properties" for the properties available.
 */
mosync.MAW_MAP_PIN = "MapPin";

/**
* @brief A list section widget is used to group one or more #MAW_LIST_VIEW_ITEM widgets.
* Only #MAW_LIST_VIEW_ITEM objects can be added to this list widget.
* None of the widget's properties applies to this widget, as it only acts like a widget container.
* When creating a list section the #MAW_LIST_VIEW_SECTION_TYPE property must be immediately set.
* See \ref WidgetListViewSectionProperties for the available properties.
* Platform: iOS and Android.
*/
mosync.MAW_LIST_VIEW_SECTION = "ListViewSection";

/**
* @brief A spinning-wheel widget used to shown one or more items(layout widgets).
* Only #MAW_HORIZONTAL_LAYOUT, #MAW_RELATIVE_LAYOUT or #MAW_VERTICAL_LAYOUT objects
* can be added as children.
* Platform: Android, iOS and WP7.
*/
mosync.MAW_CUSTOM_PICKER = "CustomPicker";

/**
* Indicates that the #maActionBarAddMenuItem() or #maActionBarSetIcon() calls failed because they pointed to an invalid icon,
*/
mosync.MAW_RES_ACTION_BAR_INVALID_ICON = -1;

/**
* Indicates that the #maActionBarAddMenuItem() call failed because the displayFlag was invalid.
*/
mosync.MAW_RES_ACTION_BAR_INVALID_FLAG = -2;

/**
* Indicates that an action bar related syscall failed because the platform does not support it.
*/
mosync.MAW_RES_ACTION_BAR_NOT_AVAILABLE = -3;

/**
* Indicates that an action bar related syscall failed because it is not enabled.
*/
mosync.MAW_RES_ACTION_BAR_DISABLED = -4;

/**
* Show this item as a button in an Action Bar if the system decides there is room for it.
*/
mosync.MAW_ACTION_BAR_ITEM_SHOW_IF_ROOM = 1;

/**
* Always show this item as a button in an Action Bar.
* Use sparingly! If too many items are set to always show in the Action Bar it can crowd it
* and degrade the user experience on devices with smaller screens.
* A good rule of thumb is to have no more than 2 items set to always show at a time.
*/
mosync.MAW_ACTION_BAR_ITEM_SHOW_ALWAYS = 2;

/**
* When this item is in the action bar, always show it with a text label even if it also has an icon specified.
*/
mosync.MAW_ACTION_BAR_ITEM_SHOW_WITH_TEXT = 4;

/**
* This item's action view collapses to a normal menu item.
* When expanded, the action view temporarily takes over a larger segment of its container.
*/
mosync.MAW_ACTION_BAR_ITEM_SHOW_COLLAPSE_ACTION_VIEW = 8;

// End of JavaScript constants.
