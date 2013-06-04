#ifndef IX_GL_OES_FRAMEBUFFER_OBJECT_H
#define IX_GL_OES_FRAMEBUFFER_OBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsRenderbufferOES(GLuint renderbuffer) {
	return (GLboolean) maIOCtl(409, renderbuffer, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glBindRenderbufferOES(GLenum target, GLuint renderbuffer) {
	return (GLvoid) maIOCtl(410, target, renderbuffer, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glDeleteRenderbuffersOES(GLsizei n, const GLuint* renderbuffers) {
	return (GLvoid) maIOCtl(411, n, (int)renderbuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glGenRenderbuffersOES(GLsizei n, GLuint* renderbuffers) {
	return (GLvoid) maIOCtl(412, n, (int)renderbuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glRenderbufferStorageOES(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	return (GLvoid) maIOCtl(413, target, internalformat, width, height);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glGetRenderbufferParameterivOES(GLenum target, GLenum pname, GLint* params) {
	return (GLvoid) maIOCtl(414, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsFramebufferOES(GLuint framebuffer) {
	return (GLboolean) maIOCtl(415, framebuffer, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glBindFramebufferOES(GLenum target, GLuint framebuffer) {
	return (GLvoid) maIOCtl(416, target, framebuffer, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glDeleteFramebuffersOES(GLsizei n, const GLuint* framebuffers) {
	return (GLvoid) maIOCtl(417, n, (int)framebuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glGenFramebuffersOES(GLsizei n, GLuint* framebuffers) {
	return (GLvoid) maIOCtl(418, n, (int)framebuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLenum glCheckFramebufferStatusOES(GLenum target) {
	return (GLenum) maIOCtl(419, target, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glFramebufferRenderbufferOES(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	return (GLvoid) maIOCtl(420, target, attachment, renderbuffertarget, renderbuffer);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glFramebufferTexture2DOES(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	return (GLvoid) maIOCtl(421, target, attachment, textarget, texture, level);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glGetFramebufferAttachmentParameterivOES(GLenum target, GLenum attachment, GLenum pname, GLint* params) {
	return (GLvoid) maIOCtl(422, target, attachment, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF GLvoid glGenerateMipmapOES(GLenum target) {
	return (GLvoid) maIOCtl(423, target, 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_GL_OES_FRAMEBUFFER_OBJECT_H
