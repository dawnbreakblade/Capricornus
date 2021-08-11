/*-----------------------------------------------------------------------------------------
**
** 版权(Copyright): Inory, 2021~ 
**
** 文件名(File Name): scanner.h
**
** 描述(Description): 本文件定义结构化配置文件浏览的内容
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
#ifndef libconfig_yyHEADER_H
#define libconfig_yyHEADER_H 1
#define libconfig_yyIN_HEADER 1

#define YY_INT_ALIGNED short int

#define FLEX_SCANNER
#define YY_FLEX_MAJOR_VERSION 1
#define YY_FLEX_MINOR_VERSION 0
#define YY_FLEX_SUBMINOR_VERSION 0
#if YY_FLEX_SUBMINOR_VERSION >= 0
#define FLEX_BETA
#endif

#ifdef yy_create_buffer
#define libconfig_yy_create_buffer_ALREADY_DEFINED
#else
#define yy_create_buffer libconfig_yy_create_buffer
#endif

#ifdef yy_delete_buffer
#define libconfig_yy_delete_buffer_ALREADY_DEFINED
#else
#define yy_delete_buffer libconfig_yy_delete_buffer
#endif

#ifdef yy_scan_buffer
#define libconfig_yy_scan_buffer_ALREADY_DEFINED
#else
#define yy_scan_buffer libconfig_yy_scan_buffer
#endif

#ifdef yy_scan_string
#define libconfig_yy_scan_string_ALREADY_DEFINED
#else
#define yy_scan_string libconfig_yy_scan_string
#endif





#endif /* libconfig_yyHEADER_H */
