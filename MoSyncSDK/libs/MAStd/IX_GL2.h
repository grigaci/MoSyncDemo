#ifndef IX_GL2_H
#define IX_GL2_H

#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup OpenGLES */
IOCTLDEF void glAttachShader(GLuint program, GLuint shader) {
	(void) maIOCtl(238, program, shader, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBindAttribLocation(GLuint program, GLuint index, const GLchar* name) {
	(void) maIOCtl(239, program, index, (int)name);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBindFramebuffer(GLenum target, GLuint framebuffer) {
	(void) maIOCtl(240, target, framebuffer, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
	(void) maIOCtl(241, target, renderbuffer, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
	MA_FV _red;
	MA_FV _green;
	MA_FV _blue;
	MA_FV _alpha;
	_red.f = red;
	_green.f = green;
	_blue.f = blue;
	_alpha.f = alpha;
	(void) maIOCtl(242, _red.i, _green.i, _blue.i, _alpha.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBlendEquation(GLenum mode) {
	(void) maIOCtl(243, mode, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
	(void) maIOCtl(244, modeRGB, modeAlpha, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	(void) maIOCtl(245, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

/** @ingroup OpenGLES */
IOCTLDEF GLenum glCheckFramebufferStatus(GLenum target) {
	return (GLenum) maIOCtl(246, target, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glCompileShader(GLuint shader) {
	(void) maIOCtl(247, shader, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLuint glCreateProgram(void) {
	return (GLuint) maIOCtl(248, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLuint glCreateShader(GLenum type) {
	return (GLuint) maIOCtl(249, type, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDeleteFramebuffers(GLsizei n, const GLuint* framebuffers) {
	(void) maIOCtl(250, n, (int)framebuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDeleteProgram(GLuint program) {
	(void) maIOCtl(251, program, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDeleteRenderbuffers(GLsizei n, const GLuint* renderbuffers) {
	(void) maIOCtl(252, n, (int)renderbuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDeleteShader(GLuint shader) {
	(void) maIOCtl(253, shader, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDetachShader(GLuint program, GLuint shader) {
	(void) maIOCtl(254, program, shader, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glDisableVertexAttribArray(GLuint index) {
	(void) maIOCtl(255, index, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glEnableVertexAttribArray(GLuint index) {
	(void) maIOCtl(256, index, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
	(void) maIOCtl(257, target, attachment, renderbuffertarget, renderbuffer);
}

/** @ingroup OpenGLES */
IOCTLDEF void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
	(void) maIOCtl(258, target, attachment, textarget, texture, level);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGenerateMipmap(GLenum target) {
	(void) maIOCtl(259, target, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGenFramebuffers(GLsizei n, GLuint* framebuffers) {
	(void) maIOCtl(260, n, (int)framebuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGenRenderbuffers(GLsizei n, GLuint* renderbuffers) {
	(void) maIOCtl(261, n, (int)renderbuffers, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) {
	(void) maIOCtl(262, program, index, bufsize, (int)length, (int)size, (int)type, (int)name);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei* length, GLint* size, GLenum* type, GLchar* name) {
	(void) maIOCtl(263, program, index, bufsize, (int)length, (int)size, (int)type, (int)name);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei* count, GLuint* shaders) {
	(void) maIOCtl(264, program, maxcount, (int)count, (int)shaders);
}

/** @ingroup OpenGLES */
IOCTLDEF int glGetAttribLocation(GLuint program, const GLchar* name) {
	return (int) maIOCtl(265, program, (int)name, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint* params) {
	(void) maIOCtl(266, target, attachment, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetProgramiv(GLuint program, GLenum pname, GLint* params) {
	(void) maIOCtl(267, program, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog) {
	(void) maIOCtl(268, program, bufsize, (int)length, (int)infolog);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint* params) {
	(void) maIOCtl(269, target, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetShaderiv(GLuint shader, GLenum pname, GLint* params) {
	(void) maIOCtl(270, shader, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infolog) {
	(void) maIOCtl(271, shader, bufsize, (int)length, (int)infolog);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision) {
	(void) maIOCtl(272, shadertype, precisiontype, (int)range, (int)precision);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* source) {
	(void) maIOCtl(273, shader, bufsize, (int)length, (int)source);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetUniformfv(GLuint program, GLint location, GLfloat* params) {
	(void) maIOCtl(274, program, location, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetUniformiv(GLuint program, GLint location, GLint* params) {
	(void) maIOCtl(275, program, location, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF int glGetUniformLocation(GLuint program, const GLchar* name) {
	return (int) maIOCtl(276, program, (int)name, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat* params) {
	(void) maIOCtl(277, index, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetVertexAttribiv(GLuint index, GLenum pname, GLint* params) {
	(void) maIOCtl(278, index, pname, (int)params);
}

/** @ingroup OpenGLES */
IOCTLDEF void glGetVertexAttribPointerv(GLuint index, GLenum pname, void* pointer) {
	(void) maIOCtl(279, index, pname, (int)pointer);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsFramebuffer(GLuint framebuffer) {
	return (GLboolean) maIOCtl(280, framebuffer, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsProgram(GLuint program) {
	return (GLboolean) maIOCtl(281, program, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsRenderbuffer(GLuint renderbuffer) {
	return (GLboolean) maIOCtl(282, renderbuffer, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF GLboolean glIsShader(GLuint shader) {
	return (GLboolean) maIOCtl(283, shader, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glLinkProgram(GLuint program) {
	(void) maIOCtl(284, program, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glReleaseShaderCompiler(void) {
	(void) maIOCtl(285, 0, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
	(void) maIOCtl(286, target, internalformat, width, height);
}

/** @ingroup OpenGLES */
IOCTLDEF void glShaderBinary(GLsizei n, const GLuint* shaders, GLenum binaryformat, const void* binary, GLsizei length) {
	(void) maIOCtl(287, n, (int)shaders, binaryformat, (int)binary, length);
}

/** @ingroup OpenGLES */
IOCTLDEF void glShaderSource(GLuint shader, GLsizei count, void* string, const GLint* length) {
	(void) maIOCtl(288, shader, count, (int)string, (int)length);
}

/** @ingroup OpenGLES */
IOCTLDEF void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
	(void) maIOCtl(289, face, func, ref, mask);
}

/** @ingroup OpenGLES */
IOCTLDEF void glStencilMaskSeparate(GLenum face, GLuint mask) {
	(void) maIOCtl(290, face, mask, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass) {
	(void) maIOCtl(291, face, fail, zfail, zpass);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform1f(GLint location, GLfloat x) {
	MA_FV _x;
	_x.f = x;
	(void) maIOCtl(292, location, _x.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform1fv(GLint location, GLsizei count, const GLfloat* v) {
	(void) maIOCtl(293, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform1i(GLint location, GLint x) {
	(void) maIOCtl(294, location, x, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform1iv(GLint location, GLsizei count, const GLint* v) {
	(void) maIOCtl(295, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform2f(GLint location, GLfloat x, GLfloat y) {
	MA_FV _x;
	MA_FV _y;
	_x.f = x;
	_y.f = y;
	(void) maIOCtl(296, location, _x.i, _y.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform2fv(GLint location, GLsizei count, const GLfloat* v) {
	(void) maIOCtl(297, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform2i(GLint location, GLint x, GLint y) {
	(void) maIOCtl(298, location, x, y);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform2iv(GLint location, GLsizei count, const GLint* v) {
	(void) maIOCtl(299, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z) {
	MA_FV _x;
	MA_FV _y;
	MA_FV _z;
	_x.f = x;
	_y.f = y;
	_z.f = z;
	(void) maIOCtl(300, location, _x.i, _y.i, _z.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform3fv(GLint location, GLsizei count, const GLfloat* v) {
	(void) maIOCtl(301, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform3i(GLint location, GLint x, GLint y, GLint z) {
	(void) maIOCtl(302, location, x, y, z);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform3iv(GLint location, GLsizei count, const GLint* v) {
	(void) maIOCtl(303, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	MA_FV _x;
	MA_FV _y;
	MA_FV _z;
	MA_FV _w;
	_x.f = x;
	_y.f = y;
	_z.f = z;
	_w.f = w;
	(void) maIOCtl(304, location, _x.i, _y.i, _z.i, _w.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform4fv(GLint location, GLsizei count, const GLfloat* v) {
	(void) maIOCtl(305, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w) {
	(void) maIOCtl(306, location, x, y, z, w);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniform4iv(GLint location, GLsizei count, const GLint* v) {
	(void) maIOCtl(307, location, count, (int)v);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	(void) maIOCtl(308, location, count, transpose, (int)value);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	(void) maIOCtl(309, location, count, transpose, (int)value);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat* value) {
	(void) maIOCtl(310, location, count, transpose, (int)value);
}

/** @ingroup OpenGLES */
IOCTLDEF void glUseProgram(GLuint program) {
	(void) maIOCtl(311, program, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glValidateProgram(GLuint program) {
	(void) maIOCtl(312, program, 0, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib1f(GLuint indx, GLfloat x) {
	MA_FV _x;
	_x.f = x;
	(void) maIOCtl(313, indx, _x.i, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib1fv(GLuint indx, const GLfloat* values) {
	(void) maIOCtl(314, indx, (int)values, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib2f(GLuint indx, GLfloat x, GLfloat y) {
	MA_FV _x;
	MA_FV _y;
	_x.f = x;
	_y.f = y;
	(void) maIOCtl(315, indx, _x.i, _y.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib2fv(GLuint indx, const GLfloat* values) {
	(void) maIOCtl(316, indx, (int)values, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z) {
	MA_FV _x;
	MA_FV _y;
	MA_FV _z;
	_x.f = x;
	_y.f = y;
	_z.f = z;
	(void) maIOCtl(317, indx, _x.i, _y.i, _z.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib3fv(GLuint indx, const GLfloat* values) {
	(void) maIOCtl(318, indx, (int)values, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	MA_FV _x;
	MA_FV _y;
	MA_FV _z;
	MA_FV _w;
	_x.f = x;
	_y.f = y;
	_z.f = z;
	_w.f = w;
	(void) maIOCtl(319, indx, _x.i, _y.i, _z.i, _w.i);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttrib4fv(GLuint indx, const GLfloat* values) {
	(void) maIOCtl(320, indx, (int)values, 0);
}

/** @ingroup OpenGLES */
IOCTLDEF void glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* ptr) {
	(void) maIOCtl(321, indx, size, type, normalized, stride, (int)ptr);
}

#ifdef __cplusplus
}
#endif

#endif	//IX_GL2_H
