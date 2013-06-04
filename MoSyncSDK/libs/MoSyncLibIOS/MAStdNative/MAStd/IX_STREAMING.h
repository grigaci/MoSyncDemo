#ifndef IX_STREAMING_H
#define IX_STREAMING_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* Has MAEvent::data point to a MAStreamEventData.
*/
#define EVENT_TYPE_STREAM 15
/// A connection to the streaming server has been established.
#define STREAMEVENT_OPEN_COMPLETE 1

/// After this event, you can retrieve information about the stream.
#define STREAMEVENT_PREPARE_COMPLETE 2

/// The stream reached its end.
#define STREAMEVENT_PLAY_COMPLETE 3

/// Also known as buffering.
#define STREAMEVENT_LOADING_STARTED 4

/// After this event, the stream is actually playing.
#define STREAMEVENT_LOADING_COMPLETE 5

#define STREAMEVENT_UNKNOWN_EVENT 6
/**
* \brief Event data associated with an audio stream.
*/
typedef struct
#ifdef __GNUC__
	__attribute((packed,aligned(4)))
#elif defined(_MSC_VER)
#pragma pack(push, 4)
#elif !defined(SYMBIAN)
#error Unsupported compiler!
#endif
 MAStreamEventData {
	/// One of the \link #STREAMEVENT_OPEN_COMPLETE STREAMEVENT \endlink constants.
	int event;

	/// The stream associated with the event.
	MAHandle stream;

	/**
	* Positive values denote progress. Negative values denote errors. Zero is not used.
	* \todo Define all possible values. They're currently platform-specific.
	*/
	int result;
} MAStreamEventData;
#ifdef _MSC_VER
#pragma pack(pop)
#endif

/**
* Starts playing sound streamed from the specified connection.
* The connection is made inaccessible for ordinary operations.
* Causes STREAM events when the state of the streaming changes.
* The connection is closed when the sound stops.
* \returns \> 0 on successful start, \< 0 on error.
* \param conn A readable connection, opened with maConnect() or maHttpCreate().
* HTTP connections must be Finished to be readable.
* \param mimeType The MIME type of the sound stream.
* It can sometimes be retrieved from the HTTP "Content-Type" header.
*/
IOCTLDEF int maSoundPlayConn(MAHandle conn, const char* mimeType) {
	return (int) maIOCtl(71, conn, (int)mimeType, 0);
}

/**
* Top-left corner, auto-starts playing.
* Causes \link #EVENT_TYPE_STREAM STREAM \endlink events.
* Only one stream is allowed at a time.
* \param url An RTSP url.
* \returns A Stream MAHandle \>0, if successful in starting the operation.
* #IOCTL_UNAVAILABLE if the function is unavailable. \<= -2 on other errors.
* \todo Define error codes.
*/
IOCTLDEF MAHandle maStreamVideoStart(const char* url) {
	return (MAHandle) maIOCtl(72, (int)url, 0, 0);
}

/**
* Returns the size, in pixels, of the video stream. \<0 if the length cannot be determined.
*
* Will only work after #STREAMEVENT_PREPARE_COMPLETE has been received for the stream.
*/
IOCTLDEF MAExtent maStreamVideoSize(MAHandle stream) {
	return (MAExtent) maIOCtl(73, stream, 0, 0);
}

/**
* Sets the screen rectangle that the video stream should be shown in.
* The default rectangle is in the top-left corner of the screen,
* and has the same size as the source video.
*
* Will only work after #STREAMEVENT_PREPARE_COMPLETE has been received for the stream.
*
* If the video is playing when you call this function, the picture frame may go black
* for a second while the system reorders itself.
*
* Whether the video is stretched or clipped to fit in the specified rectangle
* depends on the combination platform/codec.
* There should be a list; we don't have one yet.
* Symbian always stretches.
* I suspect most Java platforms stretches too, but I'm not sure.
*
* \returns #IOCTL_UNAVAILABLE if the function is unavailable. \<= -2 on other errors.
*/
IOCTLDEF int maStreamVideoSetFrame(MAHandle stream, const MARect* rect) {
	return (int) maIOCtl(74, stream, (int)rect, 0);
}

/**
* Returns the length of the stream, in milliseconds. \<0 if the length cannot be determined.
*
* Will only work after #STREAMEVENT_PREPARE_COMPLETE has been received for the stream.
*/
IOCTLDEF int maStreamLength(MAHandle stream) {
	return (int) maIOCtl(75, stream, 0, 0);
}

/**
* Returns the current playing time position of the stream, in milliseconds.
* Returns \<0 if the position cannot be determined.
*
* Will only work after #STREAMEVENT_PREPARE_COMPLETE has been received for the stream.
*/
IOCTLDEF int maStreamPos(MAHandle stream) {
	return (int) maIOCtl(76, stream, 0, 0);
}

/**
* Sets the playing time position in the stream.
* The provided position is clamped to the length of the stream.
* For some platform/media combinations, setting the position is not very accurate.
* The return value will indicate the actual position set.
*
* Will only work after #STREAMEVENT_PREPARE_COMPLETE has been received for the stream.
*
* \param stream A valid stream handle.
* \param pos A position, in milliseconds.
* \returns \<0 on error.
*/
IOCTLDEF int maStreamSetPos(MAHandle stream, int pos) {
	return (int) maIOCtl(77, stream, pos, 0);
}

/**
* Pauses the stream. Does nothing if the stream is already paused.
*/
IOCTLDEF int maStreamPause(MAHandle stream) {
	return (int) maIOCtl(78, stream, 0, 0);
}

/**
* Resumes the stream. Does nothing if the stream is already playing.
*/
IOCTLDEF int maStreamResume(MAHandle stream) {
	return (int) maIOCtl(79, stream, 0, 0);
}

/**
* Closes the stream, releasing resources and rendering the handle invalid.
*/
IOCTLDEF int maStreamClose(MAHandle stream) {
	return (int) maIOCtl(80, stream, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_STREAMING_H
