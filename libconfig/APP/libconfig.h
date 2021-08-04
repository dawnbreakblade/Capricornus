/*-----------------------------------------------------------------------------------------
**
** 版权(Copyright): Inory, 2021~ 
**
** 文件名(File Name): parsectx.h
**
** 描述(Description): 本文件定义结构化配置文件库的开放的接口
**
** 设计注记(Design Annotation):
**
** 作者(Author):
**		Inory, 2021年7月31日创建本文件
**
** 更改历史(Modification Histroy):
**		2021年7月31日 创建本文件 by Inory
**		$Revision$
**		$Date&
**		$Author$
**		$Log$
**
**-----------------------------------------------------------------------------------------
*/
#ifndef __libconfig_h
#define __libconfig_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#if defined(LIBCONFIG_STATIC)
#define LIBCONFIG_API
#elif defined(LIBCONFIG_EXPORTS)
#define LIBCONFIG_API __declspec(dllexport)
#else /* ! LIBCONFIG_EXPORTS */
#define LIBCONFIG_API __declspec(dllimport)
#endif /* ! LIBCONFIG_STATIC */
#else /* ! WIN32 */
#define LIBCONFIG_API
#endif /* WIN32 */

/*-----------------------------------------------------------------------------------------
**									  Macro Definition
**-----------------------------------------------------------------------------------------
*/
#define LIBCONFIG_VER_MAJOR 1
#define LIBCONFIG_VER_MINOR 0
#define LIBCONFIG_VER_REVISION 0

/*-----------------------------------------------------------------------------------------
**									  	   Include
**-----------------------------------------------------------------------------------------
*/
#include <stdio.h>

/*-----------------------------------------------------------------------------------------
**									  Macro Definition
**-----------------------------------------------------------------------------------------
*/
#define CONFIG_TYPE_NONE	0
#define CONFIG_TYPE_GROUP	1
#define CONFIG_TYPE_INT		2
#define CONFIG_TYPE_INT64	3
#define CONFIG_TYPE_FLOAT	4
#define CONFIG_TYPE_STRING  5
#define CONFIG_TYPE_BOOL	6
#define CONFIG_TYPE_ARRAY	7
#define CONFIG_TYPE_LIST	8

#define CONFIG_FORMAT_DEFAULT 0
#define CONFIG_FORMAT_HEX	  1

#define CONFIG_OPTION_AUTOCONVERT 0x01
#define CONFIG_OPTION_SEMICOLON_SEPARATORS 0x02
#define CONFIG_OPTION_COLON_ASSIGNMENT_FOR_GROUPS 0x04
#define CONFIG_OPTION_COLON_ASSIGNMENT_FOR_NON_GROUPS 0x08
#define CONFIG_OPTION_OPEN_BRACE_ON_SEPARATE_LINE 0x10
#define CONFIG_OPTION_ALLOW_SCIENTIFIC_NOTATION 0x20
#define CONFIG_OPTION_FSYNC 0x40
#define CONFIG_OPTION_ALLOW_OVERRIDES 0x80

#define CONFIG_TRUE (1)
#define CONFIG_FALSE (0)

/*-----------------------------------------------------------------------------------------
**									  Union Definition
**-----------------------------------------------------------------------------------------
*/
typedef union config_value_t
{
	int ival;
	long long llval;
	double fval;
	char* sval;
	struct config_list_t* list;
} config_value_t;

/*-----------------------------------------------------------------------------------------
**									  Struct Definition
**-----------------------------------------------------------------------------------------
*/
typedef struct config_setting_t
{
	char* name;
	short type;
	short format;
	config_value_t value;
	struct config_setting_t* parent;
	struct config_t* config;
	void* hook;
	unsigned int line;
	const char* file;
} config_setting_t;

/*-----------------------------------------------------------------------------------------
**									  Enum Definition
**-----------------------------------------------------------------------------------------
*/
typedef enum
{
	CONFIG_ERR_NONE = 0,
	CONFIG_ERR_FILE_IO = 1,
	CONFIG_ERR_PARSE = 2
} config_error_t;

/*-----------------------------------------------------------------------------------------
**									  Struct Definition
**-----------------------------------------------------------------------------------------
*/
typedef struct config_list_t
{
	unsigned int length;
	config_setting_t** elements;
} config_list_t;

typedef const char **(*config_include_fn_t)(struct config_t *, const char *, const char *, const char **);

typedef struct config_t
{
	config_setting_t* root;
	void (*destructor)(void* );
	int options;
	unsigned short tab_width;
	unsigned short float_precision;
	unsigned short default_format;
	const char* include_dir;
	config_include_fn_t include_fn;
	const char* error_text;
	const char* error_file;
	int error_line;
	config_error_t error_type;
	const char** filenames;
	void* hook;
} config_t;

/*-----------------------------------------------------------------------------------------
**									 Function Declaration
**-----------------------------------------------------------------------------------------
*/
extern LIBCONFIG_API int config_read(config_t* config, FILE* stream);
extern LIBCONFIG_API void config_write(const config_t* config, FILE* stream);

extern LIBCONFIG_API void config_set_default_format(config_t* config, short format);

extern LIBCONFIG_API void config_set_options(config_t* config, int options);
extern LIBCONFIG_API int config_get_options(const config_t* config);

extern LIBCONFIG_API void config_set_option(config_t* config, int option, int flag);
extern LIBCONFIG_API int config_get_option(const config_t* config, int option);

extern LIBCONFIG_API int config_read_string(config_t* config, const char* str);

extern LIBCONFIG_API int config_read_file(config_t* config, const char* filename);
extern LIBCONFIG_API int config_write_file(config_t* config, const char* filename);

extern LIBCONFIG_API void config_set_destructor(config_t* config, void (*destructor)(void *));
extern LIBCONFIG_API void config_set_include_dir(config_t* config, const char* include_dir);
extern LIBCONFIG_API void config_set_include_func(config_t* config, config_include_fn_t func);

extern LIBCONFIG_API void config_set_float_precision(config_t* config, unsigned short digits);
extern LIBCONFIG_API unsigned short config_get_float_precision(const config_t* config);

extern LIBCONFIG_API void config_set_tab_width(config_t* config, unsigned short width);
extern LIBCONFIG_API unsigned short config_get_tab_width(const config_t* config);

extern LIBCONFIG_API void config_set_hook(config_t* config, void* hook);

#define config_get_hook(C) ((C)->hook)

extern LIBCONFIG_API void config_init(config_t* config);
extern LIBCONFIG_API void config_destroy(config_t* config);
extern LIBCONFIG_API void config_clear(config_t* config);

extern LIBCONFIG_API int config_setting_get_int(const config_setting_t* setting);
extern LIBCONFIG_API long long config_setting_get_int64(const config_setting_t* setting);
extern LIBCONFIG_API double config_setting_get_float(const config_setting_t* setting);
extern LIBCONFIG_API int config_setting_get_bool(const config_setting_t* setting);
extern LIBCONFIG_API const char* config_setting_get_string(const config_setting_t* setting);

extern LIBCONFIG_API int config_setting_lookup_int(const config_setting_t* setting, const char* name, int* value);
extern LIBCONFIG_API int config_setting_lookup_int64(const config_setting_t* setting, const char* name, long long* value);
extern LIBCONFIG_API int config_setting_lookup_float(const config_setting_t* setting, const char* name, double* value);
extern LIBCONFIG_API int config_setting_lookup_bool(const config_setting_t* setting, const char* name, int* value);
extern LIBCONFIG_API int config_setting_lookup_string(const config_setting_t* setting, const char* name, const char** value);



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __libconfig_h */
