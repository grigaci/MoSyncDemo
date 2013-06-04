#ifndef IX_GUIDO_H
#define IX_GUIDO_H

#ifdef __cplusplus
extern "C" {
#endif

/// Has MAEvent::ked::key be the identifier for the TTS session, as returned by maStartSpeaking().
#define EVENT_TYPE_TTS 6
/**
* Starts reading a text using TextToSpeech. If TTS is already active,
* the old text is aborted.
*
* The system copies the text; it doesn't have to be kept in memory
* for the duration of the speech.
*
* Only the Gui-Do platform supports TTS.
*
* \warning Bug: Do not call this immediately when the program starts.
* The sound stream takes some time to initialize,
* and if this is called before the initialization is done,
* an Unhandled Symbian Error (-11) will occur.
*
* \returns A unique identifier for the TTS session.
* TTS events will have a copy of this identifier.
*/
IOCTLDEF int maStartSpeaking(const char* text) {
	return (int) maIOCtl(17, (int)text, 0, 0);
}

/**
* Aborts TTS.
*/
IOCTLDEF int maStopSpeaking(void) {
	return (int) maIOCtl(18, 0, 0, 0);
}

/**
* Returns \> 0 if TTS is active, zero otherwise.
*/
IOCTLDEF int maIsSpeaking(void) {
	return (int) maIOCtl(19, 0, 0, 0);
}

/**
* Sets the volume of TTS. Returns the previous volume.
* The volume ranges from 0 to 100. Illegal input values will be capped.
* The default volume is 100.
*/
IOCTLDEF int maSetSpeechVolume(int volume) {
	return (int) maIOCtl(20, volume, 0, 0);
}

/**
* I'm guessting these range from 0 to 100, but I'm not sure.
* Try-see if the original values reflect anything interesting.
*/
IOCTLDEF int maSetSpeechSpeed(int speed) {
	return (int) maIOCtl(21, speed, 0, 0);
}

IOCTLDEF int maSetSpeechPitch(int pitch) {
	return (int) maIOCtl(22, pitch, 0, 0);
}

/**
* Returns the hyperbolic sine of x.
* \param x An angle in radians.
*/
IOCTLDEF double sinh(double x) {
	MA_DV _result;
	MA_DV _x;
	_x.d = x;
	_result.ll = maIOCtl(23, _x.hi, _x.lo, 0);
	return _result.d;
}

/**
* Returns the hyperbolic cosine of x.
* \param x An angle in radians.
*/
IOCTLDEF double cosh(double x) {
	MA_DV _result;
	MA_DV _x;
	_x.d = x;
	_result.ll = maIOCtl(24, _x.hi, _x.lo, 0);
	return _result.d;
}

/**
* Returns the hyperbolic arc tangent of x.
*/
IOCTLDEF double atanh(double x) {
	MA_DV _result;
	MA_DV _x;
	_x.d = x;
	_result.ll = maIOCtl(25, _x.hi, _x.lo, 0);
	return _result.d;
}

#ifdef __cplusplus
}
#endif

#endif	//IX_GUIDO_H
