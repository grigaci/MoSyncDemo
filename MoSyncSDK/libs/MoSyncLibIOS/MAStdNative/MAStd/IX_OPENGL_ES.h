#ifndef IX_OPENGL_ES_H
#define IX_OPENGL_ES_H

#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup OpenGLES */
typedef signed char khronos_int8_t;
/** @ingroup OpenGLES */
typedef unsigned char khronos_uint8_t;
/** @ingroup OpenGLES */
typedef short int khronos_int16_t;
/** @ingroup OpenGLES */
typedef short unsigned int khronos_uint16_t;
/** @ingroup OpenGLES */
typedef long int khronos_intptr_t;
/** @ingroup OpenGLES */
typedef long unsigned int khronos_uintptr_t;
/** @ingroup OpenGLES */
typedef long int khronos_ssize_t;
/** @ingroup OpenGLES */
typedef long unsigned int khronos_usize_t;
/** @ingroup OpenGLES */
typedef int khronos_int32_t;
/** @ingroup OpenGLES */
typedef unsigned int khronos_uint32_t;
/** @ingroup OpenGLES */
typedef long long int khronos_int64_t;
/** @ingroup OpenGLES */
typedef long long unsigned int khronos_uint64_t;
/** @ingroup OpenGLES */
typedef float khronos_float_t;
/** @ingroup OpenGLES */
typedef khronos_uint64_t khronos_utime_nanoseconds_t;
/** @ingroup OpenGLES */
typedef khronos_int64_t khronos_stime_nanoseconds_t;
/** @ingroup OpenGLES */
typedef void GLvoid;
/** @ingroup OpenGLES */
typedef char GLchar;
/** @ingroup OpenGLES */
typedef unsigned int GLenum;
/** @ingroup OpenGLES */
typedef unsigned char GLboolean;
/** @ingroup OpenGLES */
typedef unsigned int GLbitfield;
/** @ingroup OpenGLES */
typedef khronos_int8_t GLbyte;
/** @ingroup OpenGLES */
typedef short int GLshort;
/** @ingroup OpenGLES */
typedef int GLint;
/** @ingroup OpenGLES */
typedef int GLsizei;
/** @ingroup OpenGLES */
typedef khronos_uint8_t GLubyte;
/** @ingroup OpenGLES */
typedef short unsigned int GLushort;
/** @ingroup OpenGLES */
typedef unsigned int GLuint;
/** @ingroup OpenGLES */
typedef khronos_int32_t GLclampx;
/** @ingroup OpenGLES */
typedef khronos_float_t GLfloat;
/** @ingroup OpenGLES */
typedef khronos_float_t GLclampf;
/** @ingroup OpenGLES */
typedef khronos_int32_t GLfixed;
/** @ingroup OpenGLES */
typedef khronos_intptr_t GLintptr;
/** @ingroup OpenGLES */
typedef khronos_ssize_t GLsizeiptr;

/** @ingroup OpenGLES */
IOCTLDEF void glActiveTexture(GLenum texture) {
	(void) maIOCtl(180, texture, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBindBuffer(GLenum target, GLuint buffer) {
	(void) maIOCtl(181, target, buffer, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBindTexture(GLenum target, GLuint texture) {
	(void) maIOCtl(182, target, texture, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBlendFunc(GLenum sfactor, GLenum dfactor) {
	(void) maIOCtl(183, sfactor, dfactor, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage) {
	(void) maIOCtl(184, target, size, (int)data, usage);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void* data) {
	(void) maIOCtl(185, target, offset, size, (int)data);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClear(GLbitfield mask) {
	(void) maIOCtl(186, mask, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	MA_FV _red;
	MA_FV _green;
	MA_FV _blue;
	MA_FV _alpha;
	_red.f = red;
	_green.f = green;
	_blue.f = blue;
	_alpha.f = alpha;
	(void) maIOCtl(187, _red.i, _green.i, _blue.i, _alpha.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClearDepthf(GLclampf depth) {
	MA_FV _depth;
	_depth.f = depth;
	(void) maIOCtl(188, _depth.i, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glClearStencil(GLint s) {
	(void) maIOCtl(189, s, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
	(void) maIOCtl(190, red, green, blue, alpha);
}

/** @ingroup OpenGLES */
IOCTLDEF void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data) {
	(void) maIOCtl(191, target, level, internalformat, width, height, border, imageSize, (int)data);
}

/** @ingroup OpenGLES */
IOCTLDEF void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data) {
	(void) maIOCtl(192, target, level, xoffset, yoffset, width, height, format, imageSize, (int)data);
}

/** @ingroup OpenGLES */
IOCTLDEF void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
	(void) maIOCtl(193, target, level, internalformat, x, y, width, height, border);
}

/** @ingroup OpenGLES */
IOCTLDEF void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
	(void) maIOCtl(194, target, level, xoffset, yoffset, x, y, width, height);
}

/** @ingroup OpenGLES */
IOCTLDEF void glCullFace(GLenum mode) {
	(void) maIOCtl(195, mode, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDeleteBuffers(GLsizei n, const GLuint* buffers) {
	(void) maIOCtl(196, n, (int)buffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDeleteTextures(GLsizei n, const GLuint* textures) {
	(void) maIOCtl(197, n, (int)textures, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDepthFunc(GLenum func) {
	(void) maIOCtl(198, func, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDepthMask(GLboolean flag) {
	(void) maIOCtl(199, flag, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDepthRangef(GLclampf zNear, GLclampf zFar) {
	MA_FV _zNear;
	MA_FV _zFar;
	_zNear.f = zNear;
	_zFar.f = zFar;
	(void) maIOCtl(200, _zNear.i, _zFar.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDisable(GLenum cap) {
	(void) maIOCtl(201, cap, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
	(void) maIOCtl(202, mode, first, count);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void* indices) {
	(void) maIOCtl(203, mode, count, type, (int)indices);
}

/** @ingroup OpenGLES */
IOCTLDEF void glEnable(GLenum cap) {
	(void) maIOCtl(204, cap, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFinish(void) {
	(void) maIOCtl(205, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFlush(void) {
	(void) maIOCtl(206, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFrontFace(GLenum mode) {
	(void) maIOCtl(207, mode, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGenBuffers(GLsizei n, GLuint* buffers) {
	(void) maIOCtl(208, n, (int)buffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGenTextures(GLsizei n, GLuint* textures) {
	(void) maIOCtl(209, n, (int)textures, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetBooleanv(GLenum pname, GLboolean* params) {
	(void) maIOCtl(210, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetBufferParameteriv(GLenum target, GLenum pname, GLint* params) {
	(void) maIOCtl(211, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF GLenum glGetError(void) {
	return (GLenum) maIOCtl(212, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetFloatv(GLenum pname, GLfloat* params) {
	(void) maIOCtl(213, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetIntegerv(GLenum pname, GLint* params) {
	(void) maIOCtl(214, pname, (int)params, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF MAHandle glGetStringHandle(GLenum name) {
	return (MAHandle) maIOCtl(215, name, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat* params) {
	(void) maIOCtl(216, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetTexParameteriv(GLenum target, GLenum pname, GLint* params) {
	(void) maIOCtl(217, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glHint(GLenum target, GLenum mode) {
	(void) maIOCtl(218, target, mode, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsBuffer(GLuint buffer) {
	return (GLboolean) maIOCtl(219, buffer, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsEnabled(GLenum cap) {
	return (GLboolean) maIOCtl(220, cap, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsTexture(GLuint texture) {
	return (GLboolean) maIOCtl(221, texture, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLineWidth(GLfloat width) {
	MA_FV _width;
	_width.f = width;
	(void) maIOCtl(222, _width.i, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPixelStorei(GLenum pname, GLint param) {
	(void) maIOCtl(223, pname, param, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glPolygonOffset(GLfloat factor, GLfloat units) {
	MA_FV _factor;
	MA_FV _units;
	_factor.f = factor;
	_units.f = units;
	(void) maIOCtl(224, _factor.i, _units.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels) {
	(void) maIOCtl(225, x, y, width, height, format, type, (int)pixels);
}

/** @ingroup OpenGLES */
IOCTLDEF void glSampleCoverage(GLclampf value, GLboolean invert) {
	MA_FV _value;
	_value.f = value;
	(void) maIOCtl(226, _value.i, invert, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
	(void) maIOCtl(227, x, y, width, height);
}

/** @ingroup OpenGLES */
IOCTLDEF void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
	(void) maIOCtl(228, func, ref, mask);
}

/** @ingroup OpenGLES */
IOCTLDEF void glStencilMask(GLuint mask) {
	(void) maIOCtl(229, mask, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
	(void) maIOCtl(230, fail, zfail, zpass);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels) {
	(void) maIOCtl(231, target, level, internalformat, width, height, border, format, type, (int)pixels);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
	MA_FV _param;
	_param.f = param;
	(void) maIOCtl(232, target, pname, _param.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexParameterfv(GLenum target, GLenum pname, const GLfloat* params) {
	(void) maIOCtl(233, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexParameteri(GLenum target, GLenum pname, GLint param) {
	(void) maIOCtl(234, target, pname, param);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexParameteriv(GLenum target, GLenum pname, const GLint* params) {
	(void) maIOCtl(235, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels) {
	(void) maIOCtl(236, target, level, xoffset, yoffset, width, height, format, type, (int)pixels);
}

/** @ingroup OpenGLES */
IOCTLDEF void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
	(void) maIOCtl(237, x, y, width, height);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_OPENGL_ES_H
