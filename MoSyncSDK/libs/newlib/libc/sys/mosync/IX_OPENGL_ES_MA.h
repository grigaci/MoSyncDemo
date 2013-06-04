#ifndef IX_OPENGL_ES_MA_H
#define IX_OPENGL_ES_MA_H

#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup OpenGLES */
#define MA_GL_TEX_IMAGE_2D_OK 0
/** @ingroup OpenGLES */
#define MA_GL_TEX_IMAGE_2D_INVALID_IMAGE -2
/** @ingroup OpenGLES */
#define MA_GL_API_GL2 0
/** @ingroup OpenGLES */
#define MA_GL_API_GL1 1
/** @ingroup OpenGLES */
#define MA_GL_INIT_RES_OK 0
/** @ingroup OpenGLES */
#define MA_GL_INIT_RES_UNAVAILABLE_API -2
/** @ingroup OpenGLES */
#define MA_GL_INIT_RES_ERROR -3
/**
 * Initializes fullscreen OpenGL ES.
 * @param glApi The api you want to use.
 * \returns Any of the following result codes:
 * - #MA_GL_INIT_RES_OK If the OpenGL context was successfully initialized.
 * - #MA_GL_INIT_RES_UNAVAILABLE_API If the OpenGL api version wasn't available.
 * - #MA_GL_INIT_RES_ERROR otherwise.
 */
/** @ingroup OpenGLES */
IOCTLDEF int maOpenGLInitFullscreen(int glApi) {
	return (int) maIOCtl(176, glApi, 0, 0);
}

/**
 * Closes full screen OpenGL ES.
 * \returns <0 on error.
 */
/** @ingroup OpenGLES */
IOCTLDEF int maOpenGLCloseFullscreen(void) {
	return (int) maIOCtl(177, 0, 0, 0);
}

/**
 * Works exactly as glTexImage2D but it uses an image resource instead and
 * figures out pixel formats etc.
 * @param image The handle to the image.
 * \returns Any of the following result codes:
 * - #MA_GL_TEX_IMAGE_2D_OK If the call to the function was successful.
 * - #MA_GL_TEX_IMAGE_2D_INVALID_IMAGE If the image resource handle was invalid or the image was invalid.
 */
/** @ingroup OpenGLES */
IOCTLDEF int maOpenGLTexImage2D(MAHandle image) {
	return (int) maIOCtl(178, image, 0, 0);
}

/**
 * Works exactly as glTexSubImage2D but it uses an image resource instead and
 * figures out pixel formats etc.
 * @param image The handle to the image.
 * \returns Any of the following result codes:
 * - #MA_GL_TEX_IMAGE_2D_OK If the call to the function was successful.
 * - #MA_GL_TEX_IMAGE_2D_INVALID_IMAGE If the image resource handle was invalid or the image was invalid.
 */
/** @ingroup OpenGLES */
IOCTLDEF int maOpenGLTexSubImage2D(MAHandle image) {
	return (int) maIOCtl(179, image, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_OPENGL_ES_MA_H
