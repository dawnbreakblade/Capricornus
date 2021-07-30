/*-----------------------------------------------------------------------------------------
**
** 版权(Copyright): Inory, 2021~ 
**
** 文件名(File Name): grammar.h
**
** 描述(Description): 本文件定义结构化配置文件库语义解析方式
**
** 设计注记(Design Annotation):
**
** 作者(Author):
**		Inory, 2021年7月30日创建本文件
**
** 更改历史(Modification Histroy):
**		2021年7月30日 创建本文件 by Inory
**		$Revision$
**		$Date&
**		$Author$
**		$Log$
**
**-----------------------------------------------------------------------------------------
*/
#ifndef YY_LIBCONFIG_YY_GRAMMAR_H_INCLUDED
#define YY_LIBCONFIG_YY_GRAMMAR_H_INCLUDED
/* Debug traces */
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#if YYDEBUG
extern int libconfig_yydebug;
#endif

/* Token type. */
#ifndef YYTOKENTYPE
#define YYTOKENTYPE
enum yytokentype
{
	TOK_BOOLEAN = 258,
	TOK_INTEGER = 259,
	TOK_HEX = 260,
	TOK_INTEGER64 = 261,
	TOK_HEX64 = 262,
	TOK_FLOAT = 263,
	TOK_STRING = 264,
	TOK_NAME = 265,
	TOK_EQUALS = 266,
	TOK_NEWLINE = 267,
	TOK_ARRAY_START = 268,
	TOK_ARRAY_END = 269,
	TOK_LIST_START = 270,
	TOK_LIST_END = 271,
	TOK_COMMA = 272,
	TOK_GROUP_START = 273,
	TOK_GROUP_END = 274,
	TOK_SEMICOLON = 275,
	TOK_GARBAGE = 276,
	TOK_ERROR = 277
};
#endif
/*-----------------------------------------------------------------------------------------
**									  Macro Definition
**-----------------------------------------------------------------------------------------
*/
/* Tokens */
#define TOK_BOOLEAN 258
#define TOK_INTEGER 259
#define TOK_HEX 260
#define TOK_INTEGER64 261



/* Value type. */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
	int ival;
	long long llval;
	double fval;
	char* sval;
};

typedef union YYSTYPE YYSTYPE;
#define YYSTYPE_IS_TRIVIAL 1
#define YYSTYPE_IS_DECLARED 1
#endif

/*-----------------------------------------------------------------------------------------
**									 Function Declaration
**-----------------------------------------------------------------------------------------
*/
int libconfig_yyparse(void *scanner, struct parse_context *ctx, struct scan_context *scan_ctx);

#endif /* YY_LIBCONFIG_YY_GRAMMAR_H_INCLUDED */
