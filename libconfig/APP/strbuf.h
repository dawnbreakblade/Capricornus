/*-----------------------------------------------------------------------------------------
**
** 版权(Copyright): Inory, 2021~ 
**
** 文件名(File Name): strbuf.h
**
** 描述(Description): 本文件定义字符串缓存相关的操作
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
#ifndef __libconfig_strbuf_h
#define __libconfig_strbuf_h

/*-----------------------------------------------------------------------------------------
**										   Include
**-----------------------------------------------------------------------------------------
*/
#include <string.h>
#include <sys/types.h>

/*-----------------------------------------------------------------------------------------
**									  Struct Definition
**-----------------------------------------------------------------------------------------
*/
typedef struct
{
	char* string;
	size_t length;
	size_t capacity;
} strbuf_t;

/*-----------------------------------------------------------------------------------------
**									 Function Declaration
**-----------------------------------------------------------------------------------------
*/
void libconfig_strbuf_append_string(strbuf_t* buf, const char* s);

void libconfig_strbuf_append_char(strbuf_t* buf, char c);

char *libconfig_strbuf_release(strbuf_t* buf);

#endif /* __libconfig_strbuf_h */

