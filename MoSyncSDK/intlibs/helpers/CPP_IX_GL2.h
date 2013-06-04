#ifndef IX_GL2_DEFS_H
#define IX_GL2_DEFS_H

/** \brief A hash of the abstract representation of the API described in this file.
 * Identifiers, declarations and definitions are included in the calculation of the hash,
 * but documentation is not.
 */
#define MAIDL_HASH ((int)0x28c5d5c8)

#ifndef DONT_WANT_IX_GL2_TYPEDEFS
#endif
#define maExtensionFunctionInvoke_IX_GL2_caselist \

#define maExtensionFunctionInvoke_IX_GL2_syscall_caselist \

#undef ARG_NO_4
#define ARG_NO_4 SYSCALL_THIS->GetValidatedStackValue(0 VSV_ARGPTR_USE)
#undef ARG_NO_5
#define ARG_NO_5 SYSCALL_THIS->GetValidatedStackValue(4 VSV_ARGPTR_USE)
#undef ARG_NO_6
#define ARG_NO_6 SYSCALL_THIS->GetValidatedStackValue(8 VSV_ARGPTR_USE)
#undef ARG_NO_7
#define ARG_NO_7 SYSCALL_THIS->GetValidatedStackValue(12 VSV_ARGPTR_USE)
#undef ARG_NO_8
#define ARG_NO_8 SYSCALL_THIS->GetValidatedStackValue(16 VSV_ARGPTR_USE)
#undef ARG_NO_9
#define ARG_NO_9 SYSCALL_THIS->GetValidatedStackValue(20 VSV_ARGPTR_USE)
#undef ARG_NO_10
#define ARG_NO_10 SYSCALL_THIS->GetValidatedStackValue(24 VSV_ARGPTR_USE)
#define maIOCtl_IX_GL2_caselist \
maIOCtl_glAttachShader_case(glAttachShader) \
maIOCtl_glBindAttribLocation_case(glBindAttribLocation) \
maIOCtl_glBindFramebuffer_case(glBindFramebuffer) \
maIOCtl_glBindRenderbuffer_case(glBindRenderbuffer) \
maIOCtl_glBlendColor_case(glBlendColor) \
maIOCtl_glBlendEquation_case(glBlendEquation) \
maIOCtl_glBlendEquationSeparate_case(glBlendEquationSeparate) \
maIOCtl_glBlendFuncSeparate_case(glBlendFuncSeparate) \
maIOCtl_glCheckFramebufferStatus_case(glCheckFramebufferStatus) \
maIOCtl_glCompileShader_case(glCompileShader) \
maIOCtl_glCreateProgram_case(glCreateProgram) \
maIOCtl_glCreateShader_case(glCreateShader) \
maIOCtl_glDeleteFramebuffers_case(glDeleteFramebuffers) \
maIOCtl_glDeleteProgram_case(glDeleteProgram) \
maIOCtl_glDeleteRenderbuffers_case(glDeleteRenderbuffers) \
maIOCtl_glDeleteShader_case(glDeleteShader) \
maIOCtl_glDetachShader_case(glDetachShader) \
maIOCtl_glDisableVertexAttribArray_case(glDisableVertexAttribArray) \
maIOCtl_glEnableVertexAttribArray_case(glEnableVertexAttribArray) \
maIOCtl_glFramebufferRenderbuffer_case(glFramebufferRenderbuffer) \
maIOCtl_glFramebufferTexture2D_case(glFramebufferTexture2D) \
maIOCtl_glGenerateMipmap_case(glGenerateMipmap) \
maIOCtl_glGenFramebuffers_case(glGenFramebuffers) \
maIOCtl_glGenRenderbuffers_case(glGenRenderbuffers) \
maIOCtl_glGetActiveAttrib_case(glGetActiveAttrib) \
maIOCtl_glGetActiveUniform_case(glGetActiveUniform) \
maIOCtl_glGetAttachedShaders_case(glGetAttachedShaders) \
maIOCtl_glGetAttribLocation_case(glGetAttribLocation) \
maIOCtl_glGetFramebufferAttachmentParameteriv_case(glGetFramebufferAttachmentParameteriv) \
maIOCtl_glGetProgramiv_case(glGetProgramiv) \
maIOCtl_glGetProgramInfoLog_case(glGetProgramInfoLog) \
maIOCtl_glGetRenderbufferParameteriv_case(glGetRenderbufferParameteriv) \
maIOCtl_glGetShaderiv_case(glGetShaderiv) \
maIOCtl_glGetShaderInfoLog_case(glGetShaderInfoLog) \
maIOCtl_glGetShaderPrecisionFormat_case(glGetShaderPrecisionFormat) \
maIOCtl_glGetShaderSource_case(glGetShaderSource) \
maIOCtl_glGetUniformfv_case(glGetUniformfv) \
maIOCtl_glGetUniformiv_case(glGetUniformiv) \
maIOCtl_glGetUniformLocation_case(glGetUniformLocation) \
maIOCtl_glGetVertexAttribfv_case(glGetVertexAttribfv) \
maIOCtl_glGetVertexAttribiv_case(glGetVertexAttribiv) \
maIOCtl_glGetVertexAttribPointerv_case(glGetVertexAttribPointerv) \
maIOCtl_glIsFramebuffer_case(glIsFramebuffer) \
maIOCtl_glIsProgram_case(glIsProgram) \
maIOCtl_glIsRenderbuffer_case(glIsRenderbuffer) \
maIOCtl_glIsShader_case(glIsShader) \
maIOCtl_glLinkProgram_case(glLinkProgram) \
maIOCtl_glReleaseShaderCompiler_case(glReleaseShaderCompiler) \
maIOCtl_glRenderbufferStorage_case(glRenderbufferStorage) \
maIOCtl_glShaderBinary_case(glShaderBinary) \
maIOCtl_glShaderSource_case(glShaderSource) \
maIOCtl_glStencilFuncSeparate_case(glStencilFuncSeparate) \
maIOCtl_glStencilMaskSeparate_case(glStencilMaskSeparate) \
maIOCtl_glStencilOpSeparate_case(glStencilOpSeparate) \
maIOCtl_glUniform1f_case(glUniform1f) \
maIOCtl_glUniform1fv_case(glUniform1fv) \
maIOCtl_glUniform1i_case(glUniform1i) \
maIOCtl_glUniform1iv_case(glUniform1iv) \
maIOCtl_glUniform2f_case(glUniform2f) \
maIOCtl_glUniform2fv_case(glUniform2fv) \
maIOCtl_glUniform2i_case(glUniform2i) \
maIOCtl_glUniform2iv_case(glUniform2iv) \
maIOCtl_glUniform3f_case(glUniform3f) \
maIOCtl_glUniform3fv_case(glUniform3fv) \
maIOCtl_glUniform3i_case(glUniform3i) \
maIOCtl_glUniform3iv_case(glUniform3iv) \
maIOCtl_glUniform4f_case(glUniform4f) \
maIOCtl_glUniform4fv_case(glUniform4fv) \
maIOCtl_glUniform4i_case(glUniform4i) \
maIOCtl_glUniform4iv_case(glUniform4iv) \
maIOCtl_glUniformMatrix2fv_case(glUniformMatrix2fv) \
maIOCtl_glUniformMatrix3fv_case(glUniformMatrix3fv) \
maIOCtl_glUniformMatrix4fv_case(glUniformMatrix4fv) \
maIOCtl_glUseProgram_case(glUseProgram) \
maIOCtl_glValidateProgram_case(glValidateProgram) \
maIOCtl_glVertexAttrib1f_case(glVertexAttrib1f) \
maIOCtl_glVertexAttrib1fv_case(glVertexAttrib1fv) \
maIOCtl_glVertexAttrib2f_case(glVertexAttrib2f) \
maIOCtl_glVertexAttrib2fv_case(glVertexAttrib2fv) \
maIOCtl_glVertexAttrib3f_case(glVertexAttrib3f) \
maIOCtl_glVertexAttrib3fv_case(glVertexAttrib3fv) \
maIOCtl_glVertexAttrib4f_case(glVertexAttrib4f) \
maIOCtl_glVertexAttrib4fv_case(glVertexAttrib4fv) \
maIOCtl_glVertexAttribPointer_case(glVertexAttribPointer) \

#define maIOCtl_IX_GL2_syscall_caselist \
maIOCtl_syscall_case(glAttachShader) \
maIOCtl_syscall_case(glBindAttribLocation) \
maIOCtl_syscall_case(glBindFramebuffer) \
maIOCtl_syscall_case(glBindRenderbuffer) \
maIOCtl_syscall_case(glBlendColor) \
maIOCtl_syscall_case(glBlendEquation) \
maIOCtl_syscall_case(glBlendEquationSeparate) \
maIOCtl_syscall_case(glBlendFuncSeparate) \
maIOCtl_syscall_case(glCheckFramebufferStatus) \
maIOCtl_syscall_case(glCompileShader) \
maIOCtl_syscall_case(glCreateProgram) \
maIOCtl_syscall_case(glCreateShader) \
maIOCtl_syscall_case(glDeleteFramebuffers) \
maIOCtl_syscall_case(glDeleteProgram) \
maIOCtl_syscall_case(glDeleteRenderbuffers) \
maIOCtl_syscall_case(glDeleteShader) \
maIOCtl_syscall_case(glDetachShader) \
maIOCtl_syscall_case(glDisableVertexAttribArray) \
maIOCtl_syscall_case(glEnableVertexAttribArray) \
maIOCtl_syscall_case(glFramebufferRenderbuffer) \
maIOCtl_syscall_case(glFramebufferTexture2D) \
maIOCtl_syscall_case(glGenerateMipmap) \
maIOCtl_syscall_case(glGenFramebuffers) \
maIOCtl_syscall_case(glGenRenderbuffers) \
maIOCtl_syscall_case(glGetActiveAttrib) \
maIOCtl_syscall_case(glGetActiveUniform) \
maIOCtl_syscall_case(glGetAttachedShaders) \
maIOCtl_syscall_case(glGetAttribLocation) \
maIOCtl_syscall_case(glGetFramebufferAttachmentParameteriv) \
maIOCtl_syscall_case(glGetProgramiv) \
maIOCtl_syscall_case(glGetProgramInfoLog) \
maIOCtl_syscall_case(glGetRenderbufferParameteriv) \
maIOCtl_syscall_case(glGetShaderiv) \
maIOCtl_syscall_case(glGetShaderInfoLog) \
maIOCtl_syscall_case(glGetShaderPrecisionFormat) \
maIOCtl_syscall_case(glGetShaderSource) \
maIOCtl_syscall_case(glGetUniformfv) \
maIOCtl_syscall_case(glGetUniformiv) \
maIOCtl_syscall_case(glGetUniformLocation) \
maIOCtl_syscall_case(glGetVertexAttribfv) \
maIOCtl_syscall_case(glGetVertexAttribiv) \
maIOCtl_syscall_case(glGetVertexAttribPointerv) \
maIOCtl_syscall_case(glIsFramebuffer) \
maIOCtl_syscall_case(glIsProgram) \
maIOCtl_syscall_case(glIsRenderbuffer) \
maIOCtl_syscall_case(glIsShader) \
maIOCtl_syscall_case(glLinkProgram) \
maIOCtl_syscall_case(glReleaseShaderCompiler) \
maIOCtl_syscall_case(glRenderbufferStorage) \
maIOCtl_syscall_case(glShaderBinary) \
maIOCtl_syscall_case(glShaderSource) \
maIOCtl_syscall_case(glStencilFuncSeparate) \
maIOCtl_syscall_case(glStencilMaskSeparate) \
maIOCtl_syscall_case(glStencilOpSeparate) \
maIOCtl_syscall_case(glUniform1f) \
maIOCtl_syscall_case(glUniform1fv) \
maIOCtl_syscall_case(glUniform1i) \
maIOCtl_syscall_case(glUniform1iv) \
maIOCtl_syscall_case(glUniform2f) \
maIOCtl_syscall_case(glUniform2fv) \
maIOCtl_syscall_case(glUniform2i) \
maIOCtl_syscall_case(glUniform2iv) \
maIOCtl_syscall_case(glUniform3f) \
maIOCtl_syscall_case(glUniform3fv) \
maIOCtl_syscall_case(glUniform3i) \
maIOCtl_syscall_case(glUniform3iv) \
maIOCtl_syscall_case(glUniform4f) \
maIOCtl_syscall_case(glUniform4fv) \
maIOCtl_syscall_case(glUniform4i) \
maIOCtl_syscall_case(glUniform4iv) \
maIOCtl_syscall_case(glUniformMatrix2fv) \
maIOCtl_syscall_case(glUniformMatrix3fv) \
maIOCtl_syscall_case(glUniformMatrix4fv) \
maIOCtl_syscall_case(glUseProgram) \
maIOCtl_syscall_case(glValidateProgram) \
maIOCtl_syscall_case(glVertexAttrib1f) \
maIOCtl_syscall_case(glVertexAttrib1fv) \
maIOCtl_syscall_case(glVertexAttrib2f) \
maIOCtl_syscall_case(glVertexAttrib2fv) \
maIOCtl_syscall_case(glVertexAttrib3f) \
maIOCtl_syscall_case(glVertexAttrib3fv) \
maIOCtl_syscall_case(glVertexAttrib4f) \
maIOCtl_syscall_case(glVertexAttrib4fv) \
maIOCtl_syscall_case(glVertexAttribPointer) \

#undef ARG_NO_4
#define ARG_NO_4 SYSCALL_THIS->GetValidatedStackValue(0 VSV_ARGPTR_USE)
#undef ARG_NO_5
#define ARG_NO_5 SYSCALL_THIS->GetValidatedStackValue(4 VSV_ARGPTR_USE)
#undef ARG_NO_6
#define ARG_NO_6 SYSCALL_THIS->GetValidatedStackValue(8 VSV_ARGPTR_USE)
#undef ARG_NO_7
#define ARG_NO_7 SYSCALL_THIS->GetValidatedStackValue(12 VSV_ARGPTR_USE)
#undef ARG_NO_8
#define ARG_NO_8 SYSCALL_THIS->GetValidatedStackValue(16 VSV_ARGPTR_USE)
#undef ARG_NO_9
#define ARG_NO_9 SYSCALL_THIS->GetValidatedStackValue(20 VSV_ARGPTR_USE)
#undef ARG_NO_10
#define ARG_NO_10 SYSCALL_THIS->GetValidatedStackValue(24 VSV_ARGPTR_USE)
#define maIOCtl_glAttachShader 238
#define maIOCtl_glAttachShader_case(func) \
case 238: \
{ \
GLuint _program = (GLuint)a; \
GLuint _shader = (GLuint)b; \
func(_program, _shader); \
return 0; \
} \

#define maIOCtl_glBindAttribLocation 239
#define maIOCtl_glBindAttribLocation_case(func) \
case 239: \
{ \
GLuint _program = (GLuint)a; \
GLuint _index = (GLuint)b; \
const GLchar* _name = GVMR(c, GLchar); \
func(_program, _index, _name); \
return 0; \
} \

#define maIOCtl_glBindFramebuffer 240
#define maIOCtl_glBindFramebuffer_case(func) \
case 240: \
{ \
GLenum _target = (GLenum)a; \
GLuint _framebuffer = (GLuint)b; \
func(_target, _framebuffer); \
return 0; \
} \

#define maIOCtl_glBindRenderbuffer 241
#define maIOCtl_glBindRenderbuffer_case(func) \
case 241: \
{ \
GLenum _target = (GLenum)a; \
GLuint _renderbuffer = (GLuint)b; \
func(_target, _renderbuffer); \
return 0; \
} \

#define maIOCtl_glBlendColor 242
#define maIOCtl_glBlendColor_case(func) \
case 242: \
{ \
MA_FV _red_dv; \
_red_dv.i = a; \
GLclampf _red = _red_dv.f; \
MA_FV _green_dv; \
_green_dv.i = b; \
GLclampf _green = _green_dv.f; \
MA_FV _blue_dv; \
_blue_dv.i = c; \
GLclampf _blue = _blue_dv.f; \
MA_FV _alpha_dv; \
_alpha_dv.i = ARG_NO_4; \
GLclampf _alpha = _alpha_dv.f; \
func(_red, _green, _blue, _alpha); \
return 0; \
} \

#define maIOCtl_glBlendEquation 243
#define maIOCtl_glBlendEquation_case(func) \
case 243: \
{ \
GLenum _mode = (GLenum)a; \
func(_mode); \
return 0; \
} \

#define maIOCtl_glBlendEquationSeparate 244
#define maIOCtl_glBlendEquationSeparate_case(func) \
case 244: \
{ \
GLenum _modeRGB = (GLenum)a; \
GLenum _modeAlpha = (GLenum)b; \
func(_modeRGB, _modeAlpha); \
return 0; \
} \

#define maIOCtl_glBlendFuncSeparate 245
#define maIOCtl_glBlendFuncSeparate_case(func) \
case 245: \
{ \
GLenum _srcRGB = (GLenum)a; \
GLenum _dstRGB = (GLenum)b; \
GLenum _srcAlpha = (GLenum)c; \
GLenum _dstAlpha = (GLenum)ARG_NO_4; \
func(_srcRGB, _dstRGB, _srcAlpha, _dstAlpha); \
return 0; \
} \

#define maIOCtl_glCheckFramebufferStatus 246
#define maIOCtl_glCheckFramebufferStatus_case(func) \
case 246: \
{ \
GLenum _target = (GLenum)a; \
return func(_target); \
} \

#define maIOCtl_glCompileShader 247
#define maIOCtl_glCompileShader_case(func) \
case 247: \
{ \
GLuint _shader = (GLuint)a; \
func(_shader); \
return 0; \
} \

#define maIOCtl_glCreateProgram 248
#define maIOCtl_glCreateProgram_case(func) \
case 248: \
{ \
return func(); \
} \

#define maIOCtl_glCreateShader 249
#define maIOCtl_glCreateShader_case(func) \
case 249: \
{ \
GLenum _type = (GLenum)a; \
return func(_type); \
} \

#define maIOCtl_glDeleteFramebuffers 250
#define maIOCtl_glDeleteFramebuffers_case(func) \
case 250: \
{ \
GLsizei _n = (GLsizei)a; \
const GLuint* _framebuffers = GVMR(b, GLuint); \
func(_n, _framebuffers); \
return 0; \
} \

#define maIOCtl_glDeleteProgram 251
#define maIOCtl_glDeleteProgram_case(func) \
case 251: \
{ \
GLuint _program = (GLuint)a; \
func(_program); \
return 0; \
} \

#define maIOCtl_glDeleteRenderbuffers 252
#define maIOCtl_glDeleteRenderbuffers_case(func) \
case 252: \
{ \
GLsizei _n = (GLsizei)a; \
const GLuint* _renderbuffers = GVMR(b, GLuint); \
func(_n, _renderbuffers); \
return 0; \
} \

#define maIOCtl_glDeleteShader 253
#define maIOCtl_glDeleteShader_case(func) \
case 253: \
{ \
GLuint _shader = (GLuint)a; \
func(_shader); \
return 0; \
} \

#define maIOCtl_glDetachShader 254
#define maIOCtl_glDetachShader_case(func) \
case 254: \
{ \
GLuint _program = (GLuint)a; \
GLuint _shader = (GLuint)b; \
func(_program, _shader); \
return 0; \
} \

#define maIOCtl_glDisableVertexAttribArray 255
#define maIOCtl_glDisableVertexAttribArray_case(func) \
case 255: \
{ \
GLuint _index = (GLuint)a; \
func(_index); \
return 0; \
} \

#define maIOCtl_glEnableVertexAttribArray 256
#define maIOCtl_glEnableVertexAttribArray_case(func) \
case 256: \
{ \
GLuint _index = (GLuint)a; \
func(_index); \
return 0; \
} \

#define maIOCtl_glFramebufferRenderbuffer 257
#define maIOCtl_glFramebufferRenderbuffer_case(func) \
case 257: \
{ \
GLenum _target = (GLenum)a; \
GLenum _attachment = (GLenum)b; \
GLenum _renderbuffertarget = (GLenum)c; \
GLuint _renderbuffer = (GLuint)ARG_NO_4; \
func(_target, _attachment, _renderbuffertarget, _renderbuffer); \
return 0; \
} \

#define maIOCtl_glFramebufferTexture2D 258
#define maIOCtl_glFramebufferTexture2D_case(func) \
case 258: \
{ \
GLenum _target = (GLenum)a; \
GLenum _attachment = (GLenum)b; \
GLenum _textarget = (GLenum)c; \
GLuint _texture = (GLuint)ARG_NO_4; \
GLint _level = (GLint)ARG_NO_5; \
func(_target, _attachment, _textarget, _texture, _level); \
return 0; \
} \

#define maIOCtl_glGenerateMipmap 259
#define maIOCtl_glGenerateMipmap_case(func) \
case 259: \
{ \
GLenum _target = (GLenum)a; \
func(_target); \
return 0; \
} \

#define maIOCtl_glGenFramebuffers 260
#define maIOCtl_glGenFramebuffers_case(func) \
case 260: \
{ \
GLsizei _n = (GLsizei)a; \
GLuint* _framebuffers = GVMR(b, GLuint); \
func(_n, _framebuffers); \
return 0; \
} \

#define maIOCtl_glGenRenderbuffers 261
#define maIOCtl_glGenRenderbuffers_case(func) \
case 261: \
{ \
GLsizei _n = (GLsizei)a; \
GLuint* _renderbuffers = GVMR(b, GLuint); \
func(_n, _renderbuffers); \
return 0; \
} \

#define maIOCtl_glGetActiveAttrib 262
#define maIOCtl_glGetActiveAttrib_case(func) \
case 262: \
{ \
GLuint _program = (GLuint)a; \
GLuint _index = (GLuint)b; \
GLsizei _bufsize = (GLsizei)c; \
GLsizei* _length = GVMR(ARG_NO_4, GLsizei); \
GLint* _size = GVMR(ARG_NO_5, GLint); \
GLenum* _type = GVMR(ARG_NO_6, GLenum); \
GLchar* _name = GVMR(ARG_NO_7, GLchar); \
func(_program, _index, _bufsize, _length, _size, _type, _name); \
return 0; \
} \

#define maIOCtl_glGetActiveUniform 263
#define maIOCtl_glGetActiveUniform_case(func) \
case 263: \
{ \
GLuint _program = (GLuint)a; \
GLuint _index = (GLuint)b; \
GLsizei _bufsize = (GLsizei)c; \
GLsizei* _length = GVMR(ARG_NO_4, GLsizei); \
GLint* _size = GVMR(ARG_NO_5, GLint); \
GLenum* _type = GVMR(ARG_NO_6, GLenum); \
GLchar* _name = GVMR(ARG_NO_7, GLchar); \
func(_program, _index, _bufsize, _length, _size, _type, _name); \
return 0; \
} \

#define maIOCtl_glGetAttachedShaders 264
#define maIOCtl_glGetAttachedShaders_case(func) \
case 264: \
{ \
GLuint _program = (GLuint)a; \
GLsizei _maxcount = (GLsizei)b; \
GLsizei* _count = GVMR(c, GLsizei); \
GLuint* _shaders = GVMR(ARG_NO_4, GLuint); \
func(_program, _maxcount, _count, _shaders); \
return 0; \
} \

#define maIOCtl_glGetAttribLocation 265
#define maIOCtl_glGetAttribLocation_case(func) \
case 265: \
{ \
GLuint _program = (GLuint)a; \
const GLchar* _name = GVMR(b, GLchar); \
return func(_program, _name); \
} \

#define maIOCtl_glGetFramebufferAttachmentParameteriv 266
#define maIOCtl_glGetFramebufferAttachmentParameteriv_case(func) \
case 266: \
{ \
GLenum _target = (GLenum)a; \
GLenum _attachment = (GLenum)b; \
GLenum _pname = (GLenum)c; \
GLint* _params = GVMR(ARG_NO_4, GLint); \
func(_target, _attachment, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetProgramiv 267
#define maIOCtl_glGetProgramiv_case(func) \
case 267: \
{ \
GLuint _program = (GLuint)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_program, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetProgramInfoLog 268
#define maIOCtl_glGetProgramInfoLog_case(func) \
case 268: \
{ \
GLuint _program = (GLuint)a; \
GLsizei _bufsize = (GLsizei)b; \
GLsizei* _length = GVMR(c, GLsizei); \
GLchar* _infolog = GVMR(ARG_NO_4, GLchar); \
func(_program, _bufsize, _length, _infolog); \
return 0; \
} \

#define maIOCtl_glGetRenderbufferParameteriv 269
#define maIOCtl_glGetRenderbufferParameteriv_case(func) \
case 269: \
{ \
GLenum _target = (GLenum)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_target, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetShaderiv 270
#define maIOCtl_glGetShaderiv_case(func) \
case 270: \
{ \
GLuint _shader = (GLuint)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_shader, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetShaderInfoLog 271
#define maIOCtl_glGetShaderInfoLog_case(func) \
case 271: \
{ \
GLuint _shader = (GLuint)a; \
GLsizei _bufsize = (GLsizei)b; \
GLsizei* _length = GVMR(c, GLsizei); \
GLchar* _infolog = GVMR(ARG_NO_4, GLchar); \
func(_shader, _bufsize, _length, _infolog); \
return 0; \
} \

#define maIOCtl_glGetShaderPrecisionFormat 272
#define maIOCtl_glGetShaderPrecisionFormat_case(func) \
case 272: \
{ \
GLenum _shadertype = (GLenum)a; \
GLenum _precisiontype = (GLenum)b; \
GLint* _range = GVMR(c, GLint); \
GLint* _precision = GVMR(ARG_NO_4, GLint); \
func(_shadertype, _precisiontype, _range, _precision); \
return 0; \
} \

#define maIOCtl_glGetShaderSource 273
#define maIOCtl_glGetShaderSource_case(func) \
case 273: \
{ \
GLuint _shader = (GLuint)a; \
GLsizei _bufsize = (GLsizei)b; \
GLsizei* _length = GVMR(c, GLsizei); \
GLchar* _source = GVMR(ARG_NO_4, GLchar); \
func(_shader, _bufsize, _length, _source); \
return 0; \
} \

#define maIOCtl_glGetUniformfv 274
#define maIOCtl_glGetUniformfv_case(func) \
case 274: \
{ \
GLuint _program = (GLuint)a; \
GLint _location = (GLint)b; \
GLfloat* _params = GVMR(c, GLfloat); \
func(_program, _location, _params); \
return 0; \
} \

#define maIOCtl_glGetUniformiv 275
#define maIOCtl_glGetUniformiv_case(func) \
case 275: \
{ \
GLuint _program = (GLuint)a; \
GLint _location = (GLint)b; \
GLint* _params = GVMR(c, GLint); \
func(_program, _location, _params); \
return 0; \
} \

#define maIOCtl_glGetUniformLocation 276
#define maIOCtl_glGetUniformLocation_case(func) \
case 276: \
{ \
GLuint _program = (GLuint)a; \
const GLchar* _name = GVMR(b, GLchar); \
return func(_program, _name); \
} \

#define maIOCtl_glGetVertexAttribfv 277
#define maIOCtl_glGetVertexAttribfv_case(func) \
case 277: \
{ \
GLuint _index = (GLuint)a; \
GLenum _pname = (GLenum)b; \
GLfloat* _params = GVMR(c, GLfloat); \
func(_index, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetVertexAttribiv 278
#define maIOCtl_glGetVertexAttribiv_case(func) \
case 278: \
{ \
GLuint _index = (GLuint)a; \
GLenum _pname = (GLenum)b; \
GLint* _params = GVMR(c, GLint); \
func(_index, _pname, _params); \
return 0; \
} \

#define maIOCtl_glGetVertexAttribPointerv 279
#define maIOCtl_glGetVertexAttribPointerv_case(func) \
case 279: \
{ \
GLuint _index = (GLuint)a; \
GLenum _pname = (GLenum)b; \
void* _pointer = GVMR(c, MAAddress); \
func(_index, _pname, _pointer); \
return 0; \
} \

#define maIOCtl_glIsFramebuffer 280
#define maIOCtl_glIsFramebuffer_case(func) \
case 280: \
{ \
GLuint _framebuffer = (GLuint)a; \
return func(_framebuffer); \
} \

#define maIOCtl_glIsProgram 281
#define maIOCtl_glIsProgram_case(func) \
case 281: \
{ \
GLuint _program = (GLuint)a; \
return func(_program); \
} \

#define maIOCtl_glIsRenderbuffer 282
#define maIOCtl_glIsRenderbuffer_case(func) \
case 282: \
{ \
GLuint _renderbuffer = (GLuint)a; \
return func(_renderbuffer); \
} \

#define maIOCtl_glIsShader 283
#define maIOCtl_glIsShader_case(func) \
case 283: \
{ \
GLuint _shader = (GLuint)a; \
return func(_shader); \
} \

#define maIOCtl_glLinkProgram 284
#define maIOCtl_glLinkProgram_case(func) \
case 284: \
{ \
GLuint _program = (GLuint)a; \
func(_program); \
return 0; \
} \

#define maIOCtl_glReleaseShaderCompiler 285
#define maIOCtl_glReleaseShaderCompiler_case(func) \
case 285: \
{ \
func(); \
return 0; \
} \

#define maIOCtl_glRenderbufferStorage 286
#define maIOCtl_glRenderbufferStorage_case(func) \
case 286: \
{ \
GLenum _target = (GLenum)a; \
GLenum _internalformat = (GLenum)b; \
GLsizei _width = (GLsizei)c; \
GLsizei _height = (GLsizei)ARG_NO_4; \
func(_target, _internalformat, _width, _height); \
return 0; \
} \

#define maIOCtl_glShaderBinary 287
#define maIOCtl_glShaderBinary_case(func) \
case 287: \
{ \
GLsizei _n = (GLsizei)a; \
const GLuint* _shaders = GVMR(b, GLuint); \
GLenum _binaryformat = (GLenum)c; \
const void* _binary = GVMR(ARG_NO_4, MAAddress); \
GLsizei _length = (GLsizei)ARG_NO_5; \
func(_n, _shaders, _binaryformat, _binary, _length); \
return 0; \
} \

#define maIOCtl_glShaderSource 288
#define maIOCtl_glShaderSource_case(func) \
case 288: \
{ \
GLuint _shader = (GLuint)a; \
GLsizei _count = (GLsizei)b; \
void* _string = GVMR(c, MAAddress); \
const GLint* _length = GVMR(ARG_NO_4, GLint); \
func(_shader, _count, _string, _length); \
return 0; \
} \

#define maIOCtl_glStencilFuncSeparate 289
#define maIOCtl_glStencilFuncSeparate_case(func) \
case 289: \
{ \
GLenum _face = (GLenum)a; \
GLenum _func = (GLenum)b; \
GLint _ref = (GLint)c; \
GLuint _mask = (GLuint)ARG_NO_4; \
func(_face, _func, _ref, _mask); \
return 0; \
} \

#define maIOCtl_glStencilMaskSeparate 290
#define maIOCtl_glStencilMaskSeparate_case(func) \
case 290: \
{ \
GLenum _face = (GLenum)a; \
GLuint _mask = (GLuint)b; \
func(_face, _mask); \
return 0; \
} \

#define maIOCtl_glStencilOpSeparate 291
#define maIOCtl_glStencilOpSeparate_case(func) \
case 291: \
{ \
GLenum _face = (GLenum)a; \
GLenum _fail = (GLenum)b; \
GLenum _zfail = (GLenum)c; \
GLenum _zpass = (GLenum)ARG_NO_4; \
func(_face, _fail, _zfail, _zpass); \
return 0; \
} \

#define maIOCtl_glUniform1f 292
#define maIOCtl_glUniform1f_case(func) \
case 292: \
{ \
GLint _location = (GLint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
func(_location, _x); \
return 0; \
} \

#define maIOCtl_glUniform1fv 293
#define maIOCtl_glUniform1fv_case(func) \
case 293: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLfloat* _v = GVMR(c, GLfloat); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniform1i 294
#define maIOCtl_glUniform1i_case(func) \
case 294: \
{ \
GLint _location = (GLint)a; \
GLint _x = (GLint)b; \
func(_location, _x); \
return 0; \
} \

#define maIOCtl_glUniform1iv 295
#define maIOCtl_glUniform1iv_case(func) \
case 295: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLint* _v = GVMR(c, GLint); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniform2f 296
#define maIOCtl_glUniform2f_case(func) \
case 296: \
{ \
GLint _location = (GLint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = c; \
GLfloat _y = _y_dv.f; \
func(_location, _x, _y); \
return 0; \
} \

#define maIOCtl_glUniform2fv 297
#define maIOCtl_glUniform2fv_case(func) \
case 297: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLfloat* _v = GVMR(c, GLfloat); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniform2i 298
#define maIOCtl_glUniform2i_case(func) \
case 298: \
{ \
GLint _location = (GLint)a; \
GLint _x = (GLint)b; \
GLint _y = (GLint)c; \
func(_location, _x, _y); \
return 0; \
} \

#define maIOCtl_glUniform2iv 299
#define maIOCtl_glUniform2iv_case(func) \
case 299: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLint* _v = GVMR(c, GLint); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniform3f 300
#define maIOCtl_glUniform3f_case(func) \
case 300: \
{ \
GLint _location = (GLint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = c; \
GLfloat _y = _y_dv.f; \
MA_FV _z_dv; \
_z_dv.i = ARG_NO_4; \
GLfloat _z = _z_dv.f; \
func(_location, _x, _y, _z); \
return 0; \
} \

#define maIOCtl_glUniform3fv 301
#define maIOCtl_glUniform3fv_case(func) \
case 301: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLfloat* _v = GVMR(c, GLfloat); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniform3i 302
#define maIOCtl_glUniform3i_case(func) \
case 302: \
{ \
GLint _location = (GLint)a; \
GLint _x = (GLint)b; \
GLint _y = (GLint)c; \
GLint _z = (GLint)ARG_NO_4; \
func(_location, _x, _y, _z); \
return 0; \
} \

#define maIOCtl_glUniform3iv 303
#define maIOCtl_glUniform3iv_case(func) \
case 303: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLint* _v = GVMR(c, GLint); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniform4f 304
#define maIOCtl_glUniform4f_case(func) \
case 304: \
{ \
GLint _location = (GLint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = c; \
GLfloat _y = _y_dv.f; \
MA_FV _z_dv; \
_z_dv.i = ARG_NO_4; \
GLfloat _z = _z_dv.f; \
MA_FV _w_dv; \
_w_dv.i = ARG_NO_5; \
GLfloat _w = _w_dv.f; \
func(_location, _x, _y, _z, _w); \
return 0; \
} \

#define maIOCtl_glUniform4fv 305
#define maIOCtl_glUniform4fv_case(func) \
case 305: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLfloat* _v = GVMR(c, GLfloat); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniform4i 306
#define maIOCtl_glUniform4i_case(func) \
case 306: \
{ \
GLint _location = (GLint)a; \
GLint _x = (GLint)b; \
GLint _y = (GLint)c; \
GLint _z = (GLint)ARG_NO_4; \
GLint _w = (GLint)ARG_NO_5; \
func(_location, _x, _y, _z, _w); \
return 0; \
} \

#define maIOCtl_glUniform4iv 307
#define maIOCtl_glUniform4iv_case(func) \
case 307: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
const GLint* _v = GVMR(c, GLint); \
func(_location, _count, _v); \
return 0; \
} \

#define maIOCtl_glUniformMatrix2fv 308
#define maIOCtl_glUniformMatrix2fv_case(func) \
case 308: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
GLboolean _transpose = (GLboolean)c; \
const GLfloat* _value = GVMR(ARG_NO_4, GLfloat); \
func(_location, _count, _transpose, _value); \
return 0; \
} \

#define maIOCtl_glUniformMatrix3fv 309
#define maIOCtl_glUniformMatrix3fv_case(func) \
case 309: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
GLboolean _transpose = (GLboolean)c; \
const GLfloat* _value = GVMR(ARG_NO_4, GLfloat); \
func(_location, _count, _transpose, _value); \
return 0; \
} \

#define maIOCtl_glUniformMatrix4fv 310
#define maIOCtl_glUniformMatrix4fv_case(func) \
case 310: \
{ \
GLint _location = (GLint)a; \
GLsizei _count = (GLsizei)b; \
GLboolean _transpose = (GLboolean)c; \
const GLfloat* _value = GVMR(ARG_NO_4, GLfloat); \
func(_location, _count, _transpose, _value); \
return 0; \
} \

#define maIOCtl_glUseProgram 311
#define maIOCtl_glUseProgram_case(func) \
case 311: \
{ \
GLuint _program = (GLuint)a; \
func(_program); \
return 0; \
} \

#define maIOCtl_glValidateProgram 312
#define maIOCtl_glValidateProgram_case(func) \
case 312: \
{ \
GLuint _program = (GLuint)a; \
func(_program); \
return 0; \
} \

#define maIOCtl_glVertexAttrib1f 313
#define maIOCtl_glVertexAttrib1f_case(func) \
case 313: \
{ \
GLuint _indx = (GLuint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
func(_indx, _x); \
return 0; \
} \

#define maIOCtl_glVertexAttrib1fv 314
#define maIOCtl_glVertexAttrib1fv_case(func) \
case 314: \
{ \
GLuint _indx = (GLuint)a; \
const GLfloat* _values = GVMR(b, GLfloat); \
func(_indx, _values); \
return 0; \
} \

#define maIOCtl_glVertexAttrib2f 315
#define maIOCtl_glVertexAttrib2f_case(func) \
case 315: \
{ \
GLuint _indx = (GLuint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = c; \
GLfloat _y = _y_dv.f; \
func(_indx, _x, _y); \
return 0; \
} \

#define maIOCtl_glVertexAttrib2fv 316
#define maIOCtl_glVertexAttrib2fv_case(func) \
case 316: \
{ \
GLuint _indx = (GLuint)a; \
const GLfloat* _values = GVMR(b, GLfloat); \
func(_indx, _values); \
return 0; \
} \

#define maIOCtl_glVertexAttrib3f 317
#define maIOCtl_glVertexAttrib3f_case(func) \
case 317: \
{ \
GLuint _indx = (GLuint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = c; \
GLfloat _y = _y_dv.f; \
MA_FV _z_dv; \
_z_dv.i = ARG_NO_4; \
GLfloat _z = _z_dv.f; \
func(_indx, _x, _y, _z); \
return 0; \
} \

#define maIOCtl_glVertexAttrib3fv 318
#define maIOCtl_glVertexAttrib3fv_case(func) \
case 318: \
{ \
GLuint _indx = (GLuint)a; \
const GLfloat* _values = GVMR(b, GLfloat); \
func(_indx, _values); \
return 0; \
} \

#define maIOCtl_glVertexAttrib4f 319
#define maIOCtl_glVertexAttrib4f_case(func) \
case 319: \
{ \
GLuint _indx = (GLuint)a; \
MA_FV _x_dv; \
_x_dv.i = b; \
GLfloat _x = _x_dv.f; \
MA_FV _y_dv; \
_y_dv.i = c; \
GLfloat _y = _y_dv.f; \
MA_FV _z_dv; \
_z_dv.i = ARG_NO_4; \
GLfloat _z = _z_dv.f; \
MA_FV _w_dv; \
_w_dv.i = ARG_NO_5; \
GLfloat _w = _w_dv.f; \
func(_indx, _x, _y, _z, _w); \
return 0; \
} \

#define maIOCtl_glVertexAttrib4fv 320
#define maIOCtl_glVertexAttrib4fv_case(func) \
case 320: \
{ \
GLuint _indx = (GLuint)a; \
const GLfloat* _values = GVMR(b, GLfloat); \
func(_indx, _values); \
return 0; \
} \

#define maIOCtl_glVertexAttribPointer 321
#define maIOCtl_glVertexAttribPointer_case(func) \
case 321: \
{ \
GLuint _indx = (GLuint)a; \
GLint _size = (GLint)b; \
GLenum _type = (GLenum)c; \
GLboolean _normalized = (GLboolean)ARG_NO_4; \
GLsizei _stride = (GLsizei)ARG_NO_5; \
const void* _ptr = GVMR(ARG_NO_6, MAAddress); \
func(_indx, _size, _type, _normalized, _stride, _ptr); \
return 0; \
} \


#endif	//IX_GL2_DEFS_H
