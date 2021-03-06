/*-----------------------------------------------------------------------------------------
**
** 版权(Copyright): Inory, 2021~ 
**
** 文件名(File Name): parsectx.h
**
** 描述(Description): 本文件定义结构化配置文件解析的内容
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
#ifndef __libconfig_parsectx_h
#define __libconfig_parsectx_h

/*-----------------------------------------------------------------------------------------
**										   Include
**-----------------------------------------------------------------------------------------
*/
#include "libconfig.h"
#include "strbuf.h"
#include "util.h"

/*-----------------------------------------------------------------------------------------
**									  Struct Definition
**-----------------------------------------------------------------------------------------
*/
struct parse_context
{
	config_t* config;
	config_setting_t* parent;
	config_setting_t* setting;
	char* name;
	strbuf_t string;
};

/*-----------------------------------------------------------------------------------------
**									  Macro Definition
**-----------------------------------------------------------------------------------------
*/
#define libconfig_parsectx_init(C) __zero(C)
#define libconfig_parsectx_cleanup(C) __delete(libconfig_strbuf_release(&((C)->string)))

#define libconfig_parsectx_append_string(C, S) libconfig_strbuf_append_string(&((C)->string), (S))
#define libconfig_parsectx_take_string(C) libconfig_strbuf_release(&((C)->string))

#endif /* __libconfig_parsectx_h */

