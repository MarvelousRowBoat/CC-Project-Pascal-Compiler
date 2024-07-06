/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ninad.yacc"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    #define MAX_SYMBOLS 1000
     
    int yylex();
    int yyerror(const char *msg);
    extern FILE *yyin;
     
    typedef struct symbol {
    char name[100];
    char type[10];
    int assigned;
    int isArray;
    struct symbol* next;
	} symbol;
     
    symbol symtab[MAX_SYMBOLS];
    int symtab_len = 0;
    char* current_type = "";
    int flag=1;
    int is_array = 0; 
    symbol* lookup(char* name) {
        for(int i = 0; i < symtab_len; i++) {
            if(strcmp(symtab[i].name, name) == 0) {
                return &symtab[i];
            }
        }
        return NULL;
    }
    
    
symbol* insert(char* name) {
    symbol* s = lookup(name);
    if(s != NULL) {
        printf("Error: Duplicate declaration of variable %s\n", name);
        flag=0;
        //exit(1);
    } else {
        s = malloc(sizeof(symbol));
        strcpy(s->name, name);
        s->assigned = 0;
        symtab[symtab_len] = *s;
        symtab_len++;
        return &symtab[symtab_len-1];
    }
}

void assign_type(symbol* list, char* type) {
    symbol* s = list;
    while(s != NULL) {
        strcpy(s->type, type);
        //symtab_len++;
        s = s->next;
    }
}
void setArray(symbol* s, int isArr){
    symbol* sym = s;
        sym->isArray = isArr;
        sym->assigned = 1;
}

     
    void assign(char* name) {
        symbol* s = lookup(name);
        if(s == NULL) {
            printf("Error: Undeclared variable %s\n", name);
            flag=0;
            //exit(1);
        } else {
            s->assigned = 1;
        }
    }
     
    void check_expr_type(symbol* s1, symbol* s2) {
    if(s1 != NULL && s2 != NULL) {
        printf("TYPE: %s %s\n", s1->type, s2->type);
        if(strcmp(s1->type, s2->type) != 0) {
            printf("Error: Type mismatch in arithmetic operation between %s and %s\n", s1->name, s2->name);
            flag=0;
            //exit(1);
        }
    } 
}
typedef struct assign_stmt {
    symbol* var;
    symbol* expr;
} assign_stmt; 
void check_assign_type(assign_stmt* stmt) {
    if(stmt->var != NULL && stmt->expr != NULL) {
        printf("TYPE: %s %s\n", stmt->var->type, stmt->expr->type);
        check_expr_type(stmt->var, stmt->expr);
    }
}

void check_assigned(char* name) {
        symbol* s = lookup(name);
        if(s != NULL && s->assigned == 0) {
            printf("Error: Variable %s used before assignment\n", name);
            flag=0;
            //exit(1);
        }
        else if(s == NULL){
            printf("Error: Undeclared variable %s\n", name);
            flag=0;
        }
    }
    

#line 183 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROG_ID = 258,                 /* PROG_ID  */
    INT = 259,                     /* INT  */
    REAL = 260,                    /* REAL  */
    BOOL = 261,                    /* BOOL  */
    VAR = 262,                     /* VAR  */
    CHAR = 263,                    /* CHAR  */
    TO = 264,                      /* TO  */
    DOWNTO = 265,                  /* DOWNTO  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    THEN = 270,                    /* THEN  */
    DO = 271,                      /* DO  */
    ARRAY = 272,                   /* ARRAY  */
    OF = 273,                      /* OF  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    NOT = 276,                     /* NOT  */
    BEG = 277,                     /* BEG  */
    END = 278,                     /* END  */
    READ = 279,                    /* READ  */
    WRITE = 280,                   /* WRITE  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MULTIPLY = 283,                /* MULTIPLY  */
    DIVIDE = 284,                  /* DIVIDE  */
    MOD = 285,                     /* MOD  */
    EQUAL = 286,                   /* EQUAL  */
    ASSIGN = 287,                  /* ASSIGN  */
    LT = 288,                      /* LT  */
    GT = 289,                      /* GT  */
    LTE = 290,                     /* LTE  */
    GTE = 291,                     /* GTE  */
    NE = 292,                      /* NE  */
    SEMICOLON = 293,               /* SEMICOLON  */
    COLON = 294,                   /* COLON  */
    COMMA = 295,                   /* COMMA  */
    DOT = 296,                     /* DOT  */
    LP = 297,                      /* LP  */
    RP = 298,                      /* RP  */
    LB = 299,                      /* LB  */
    RB = 300,                      /* RB  */
    NUM = 301,                     /* NUM  */
    STRING = 302,                  /* STRING  */
    ID = 303,                      /* ID  */
    RANGE = 304,                   /* RANGE  */
    REALNUM = 305                  /* REALNUM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PROG_ID 258
#define INT 259
#define REAL 260
#define BOOL 261
#define VAR 262
#define CHAR 263
#define TO 264
#define DOWNTO 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define THEN 270
#define DO 271
#define ARRAY 272
#define OF 273
#define AND 274
#define OR 275
#define NOT 276
#define BEG 277
#define END 278
#define READ 279
#define WRITE 280
#define PLUS 281
#define MINUS 282
#define MULTIPLY 283
#define DIVIDE 284
#define MOD 285
#define EQUAL 286
#define ASSIGN 287
#define LT 288
#define GT 289
#define LTE 290
#define GTE 291
#define NE 292
#define SEMICOLON 293
#define COLON 294
#define COMMA 295
#define DOT 296
#define LP 297
#define RP 298
#define LB 299
#define RB 300
#define NUM 301
#define STRING 302
#define ID 303
#define RANGE 304
#define REALNUM 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 112 "ninad.yacc"

        int ival;
        double rval;
        char* sval;
        struct symbol* sym;

#line 343 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROG_ID = 3,                    /* PROG_ID  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_TO = 9,                         /* TO  */
  YYSYMBOL_DOWNTO = 10,                    /* DOWNTO  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_ARRAY = 17,                     /* ARRAY  */
  YYSYMBOL_OF = 18,                        /* OF  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_BEG = 22,                       /* BEG  */
  YYSYMBOL_END = 23,                       /* END  */
  YYSYMBOL_READ = 24,                      /* READ  */
  YYSYMBOL_WRITE = 25,                     /* WRITE  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 28,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 29,                    /* DIVIDE  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_EQUAL = 31,                     /* EQUAL  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_LT = 33,                        /* LT  */
  YYSYMBOL_GT = 34,                        /* GT  */
  YYSYMBOL_LTE = 35,                       /* LTE  */
  YYSYMBOL_GTE = 36,                       /* GTE  */
  YYSYMBOL_NE = 37,                        /* NE  */
  YYSYMBOL_SEMICOLON = 38,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_DOT = 41,                       /* DOT  */
  YYSYMBOL_LP = 42,                        /* LP  */
  YYSYMBOL_RP = 43,                        /* RP  */
  YYSYMBOL_LB = 44,                        /* LB  */
  YYSYMBOL_RB = 45,                        /* RB  */
  YYSYMBOL_NUM = 46,                       /* NUM  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_ID = 48,                        /* ID  */
  YYSYMBOL_RANGE = 49,                     /* RANGE  */
  YYSYMBOL_REALNUM = 50,                   /* REALNUM  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_prog = 52,                      /* prog  */
  YYSYMBOL_v = 53,                         /* v  */
  YYSYMBOL_va = 54,                        /* va  */
  YYSYMBOL_type = 55,                      /* type  */
  YYSYMBOL_t = 56,                         /* t  */
  YYSYMBOL_varlist = 57,                   /* varlist  */
  YYSYMBOL_stmt_list = 58,                 /* stmt_list  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_Block = 60,                     /* Block  */
  YYSYMBOL_io_stmt = 61,                   /* io_stmt  */
  YYSYMBOL_varlis = 62,                    /* varlis  */
  YYSYMBOL_if_stmt = 63,                   /* if_stmt  */
  YYSYMBOL_else_part = 64,                 /* else_part  */
  YYSYMBOL_while_stmt = 65,                /* while_stmt  */
  YYSYMBOL_for_stmt = 66,                  /* for_stmt  */
  YYSYMBOL_assign_stmt = 67,               /* assign_stmt  */
  YYSYMBOL_expression = 68,                /* expression  */
  YYSYMBOL_e = 69,                         /* e  */
  YYSYMBOL_T = 70,                         /* T  */
  YYSYMBOL_f = 71                          /* f  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   153

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   131,   131,   133,   134,   135,   137,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   150,   151,   152,
     153,   154,   155,   157,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   185,
     187,   189,   194,   195,   196,   198,   200,   203,   204
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROG_ID", "INT",
  "REAL", "BOOL", "VAR", "CHAR", "TO", "DOWNTO", "IF", "ELSE", "WHILE",
  "FOR", "THEN", "DO", "ARRAY", "OF", "AND", "OR", "NOT", "BEG", "END",
  "READ", "WRITE", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MOD", "EQUAL",
  "ASSIGN", "LT", "GT", "LTE", "GTE", "NE", "SEMICOLON", "COLON", "COMMA",
  "DOT", "LP", "RP", "LB", "RB", "NUM", "STRING", "ID", "RANGE", "REALNUM",
  "$accept", "prog", "v", "va", "type", "t", "varlist", "stmt_list",
  "stmt", "Block", "io_stmt", "varlis", "if_stmt", "else_part",
  "while_stmt", "for_stmt", "assign_stmt", "expression", "e", "T", "f", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -26,    43,    15,   -65,   -13,    27,   -65,   -13,   -24,
     -65,    13,    -1,    99,    18,    -4,   -65,    99,   -65,   -65,
     -65,   -65,    19,    71,   -65,   -65,     4,     4,    25,   -65,
      46,    60,    28,   -65,   -65,    73,    79,    85,    90,    96,
     103,   124,   -65,    64,    64,   -65,   100,    50,   106,    97,
     -65,    58,   111,    98,    88,    64,    64,   -65,   -65,   -65,
     -65,   -65,   -65,   116,   106,    72,    64,    23,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    23,    64,    94,   102,   -65,   -32,   106,   -22,   -65,
     -65,    35,   135,   106,   106,   106,   106,   106,   106,   106,
     106,    97,    97,   -65,   -65,   -65,   -65,    87,   -65,     4,
     -65,   101,   -65,   118,   -65,    23,   -65,    64,    64,    22,
     -65,    64,   -65,    74,    92,   -65,   106,    23,    23,   -65,
     -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,     0,    14,     3,     0,
      16,     0,     0,     0,     0,     0,     2,     0,     9,    10,
      11,    12,     0,     0,     7,    13,     0,     0,     0,    23,
       0,     0,     0,    15,    17,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,    58,    56,     0,    47,    50,
      54,     0,     0,     0,     0,     0,     0,    22,    19,    21,
      20,    18,     5,     0,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,     0,    36,     0,     8,
      55,     0,    32,    44,    45,    43,    38,    39,    40,    41,
      42,    48,    49,    51,    52,    53,    33,     0,    24,     0,
      26,     0,    27,     0,    57,     0,    30,     0,     0,     0,
      28,     0,    31,     0,     0,    25,    37,     0,     0,    34,
      35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   -65,   131,    89,   143,   -65,   -64,   147,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -27,   -42,    63,
      51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,     8,    23,    24,     9,    15,    33,    34,
      35,    86,    36,   116,    37,    38,    39,    47,    48,    49,
      50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    64,    65,    92,    76,    77,     1,    26,   111,    27,
      28,   112,     3,    87,    88,    13,    14,   106,    10,    29,
      30,    31,     5,   113,    91,    43,    93,    94,    95,    96,
      97,    98,    99,   100,    26,     7,    27,    28,    17,    14,
     107,    68,    69,     4,    32,    10,    44,    30,    31,    10,
      45,   122,    46,    70,    16,    71,    72,    73,    74,    75,
      55,    76,    77,   129,   130,    67,    25,   125,    41,    68,
      69,    32,    56,    52,    81,   123,   124,    68,    69,   126,
     114,    70,   119,    71,    72,    73,    74,    75,    53,    70,
     127,    71,    72,    73,    74,    75,   117,   118,    76,    77,
      76,    77,    54,    18,    19,    20,    44,    21,   128,    42,
      45,    57,    46,    76,    77,    90,    22,    58,    76,    77,
      18,    19,    20,    59,    21,    78,    79,    80,    60,   103,
     104,   105,    76,    77,    61,    84,    85,   108,   109,   101,
     102,    62,    63,    82,    66,   110,    83,   115,    40,   120,
     121,    12,    89,    11
};

static const yytype_uint8 yycheck[] =
{
      27,    43,    44,    67,    26,    27,     3,    11,    40,    13,
      14,    43,    38,    55,    56,    39,    40,    81,    22,    23,
      24,    25,     7,    45,    66,    21,    68,    69,    70,    71,
      72,    73,    74,    75,    11,    48,    13,    14,    39,    40,
      82,    19,    20,     0,    48,    22,    42,    24,    25,    22,
      46,   115,    48,    31,    41,    33,    34,    35,    36,    37,
      32,    26,    27,   127,   128,    15,    48,    45,    49,    19,
      20,    48,    44,    48,    16,   117,   118,    19,    20,   121,
      45,    31,   109,    33,    34,    35,    36,    37,    42,    31,
      16,    33,    34,    35,    36,    37,     9,    10,    26,    27,
      26,    27,    42,     4,     5,     6,    42,     8,    16,    38,
      46,    38,    48,    26,    27,    43,    17,    38,    26,    27,
       4,     5,     6,    38,     8,    28,    29,    30,    38,    78,
      79,    80,    26,    27,    38,    47,    48,    43,    44,    76,
      77,    38,    18,    32,    44,    43,    48,    12,    17,    48,
      32,     8,    63,     6
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    38,     0,     7,    53,    48,    54,    57,
      22,    60,    57,    39,    40,    58,    41,    39,     4,     5,
       6,     8,    17,    55,    56,    48,    11,    13,    14,    23,
      24,    25,    48,    59,    60,    61,    63,    65,    66,    67,
      55,    49,    38,    21,    42,    46,    48,    68,    69,    70,
      71,    68,    48,    42,    42,    32,    44,    38,    38,    38,
      38,    38,    38,    18,    69,    69,    44,    15,    19,    20,
      31,    33,    34,    35,    36,    37,    26,    27,    28,    29,
      30,    16,    32,    48,    47,    48,    62,    69,    69,    56,
      43,    69,    59,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    71,    71,    71,    59,    69,    43,    44,
      43,    40,    43,    45,    45,    12,    64,     9,    10,    68,
      48,    32,    59,    69,    69,    45,    69,    16,    16,    59,
      59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    61,    61,    61,    61,    62,    62,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    70,    71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     0,     5,     4,     1,     4,     1,
       1,     1,     1,     3,     1,     2,     0,     1,     2,     2,
       2,     2,     2,     3,     4,     6,     4,     4,     3,     1,
       5,     2,     0,     4,     8,     8,     3,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     4,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: PROG_ID SEMICOLON v Block DOT  */
#line 131 "ninad.yacc"
                                        {flag=1;}
#line 1479 "y.tab.c"
    break;

  case 5: /* va: va varlist COLON type SEMICOLON  */
#line 135 "ninad.yacc"
                                        {current_type = (yyvsp[-1].sval); assign_type((yyvsp[-3].sym), current_type); if(is_array){ setArray((yyvsp[-3].sym),is_array);
                                                                                                  } is_array=0;}
#line 1486 "y.tab.c"
    break;

  case 6: /* va: varlist COLON type SEMICOLON  */
#line 137 "ninad.yacc"
                                   {current_type = (yyvsp[-1].sval); assign_type((yyvsp[-3].sym), current_type); if(is_array){ setArray((yyvsp[-3].sym),is_array);
                                                                                                  } is_array=0; }
#line 1493 "y.tab.c"
    break;

  case 7: /* type: t  */
#line 139 "ninad.yacc"
            { strcpy((yyval.sval), (yyvsp[0].sval)); }
#line 1499 "y.tab.c"
    break;

  case 8: /* type: ARRAY RANGE OF t  */
#line 140 "ninad.yacc"
                           { strcpy((yyval.sval) , (yyvsp[0].sval)); is_array = 1;}
#line 1505 "y.tab.c"
    break;

  case 9: /* t: INT  */
#line 141 "ninad.yacc"
           {strcpy((yyval.sval), "INT");}
#line 1511 "y.tab.c"
    break;

  case 10: /* t: REAL  */
#line 142 "ninad.yacc"
               {strcpy((yyval.sval) ,"REAL");}
#line 1517 "y.tab.c"
    break;

  case 11: /* t: BOOL  */
#line 143 "ninad.yacc"
                {strcpy((yyval.sval) ,"BOOL");}
#line 1523 "y.tab.c"
    break;

  case 12: /* t: CHAR  */
#line 144 "ninad.yacc"
               {strcpy((yyval.sval), "CHAR");}
#line 1529 "y.tab.c"
    break;

  case 13: /* varlist: varlist COMMA ID  */
#line 145 "ninad.yacc"
                              { (yyval.sym) = insert((yyvsp[0].sval)); (yyval.sym)->next = (yyvsp[-2].sym); }
#line 1535 "y.tab.c"
    break;

  case 14: /* varlist: ID  */
#line 146 "ninad.yacc"
         { (yyval.sym) = insert((yyvsp[0].sval)); }
#line 1541 "y.tab.c"
    break;

  case 24: /* io_stmt: READ LP ID RP  */
#line 159 "ninad.yacc"
                          {  assign((yyvsp[-1].sval)); }
#line 1547 "y.tab.c"
    break;

  case 25: /* io_stmt: READ LP ID LB expression RB  */
#line 160 "ninad.yacc"
                                      { assign((yyvsp[-3].sval)); }
#line 1553 "y.tab.c"
    break;

  case 28: /* varlis: varlis COMMA ID  */
#line 163 "ninad.yacc"
                            { check_assigned((yyvsp[0].sval)); }
#line 1559 "y.tab.c"
    break;

  case 29: /* varlis: ID  */
#line 164 "ninad.yacc"
                 {check_assigned((yyvsp[0].sval)); }
#line 1565 "y.tab.c"
    break;

  case 36: /* assign_stmt: ID ASSIGN e  */
#line 171 "ninad.yacc"
                             { assign((yyvsp[-2].sval)); symbol* s=lookup((yyvsp[-2].sval)); if(s->type!=NULL) check_expr_type(s, (yyvsp[0].sym)); }
#line 1571 "y.tab.c"
    break;

  case 37: /* assign_stmt: ID LB e RB ASSIGN e  */
#line 172 "ninad.yacc"
                             { assign((yyvsp[-5].sval)); }
#line 1577 "y.tab.c"
    break;

  case 48: /* e: e PLUS T  */
#line 183 "ninad.yacc"
                { (yyval.sym) = malloc(sizeof(symbol)); 
                        strcpy((yyval.sym)->type, (yyvsp[0].sym)->type); }
#line 1584 "y.tab.c"
    break;

  case 49: /* e: e MINUS T  */
#line 185 "ninad.yacc"
                    { (yyval.sym) = malloc(sizeof(symbol)); 
                    strcpy((yyval.sym)->type, (yyvsp[0].sym)->type);}
#line 1591 "y.tab.c"
    break;

  case 50: /* e: T  */
#line 187 "ninad.yacc"
            { (yyval.sym) = malloc(sizeof(symbol)); 
                    strcpy((yyval.sym)->type, (yyvsp[0].sym)->type); }
#line 1598 "y.tab.c"
    break;

  case 51: /* T: T MULTIPLY f  */
#line 189 "ninad.yacc"
                    { (yyval.sym) = malloc(sizeof(symbol)); 
                        if(strcmp((yyvsp[-2].sym)->type,"REAL")==0) strcpy((yyval.sym)->type, "REAL");
                        else if(strcmp((yyvsp[0].sym)->type,"REAL")==0) strcpy((yyval.sym)->type, "REAL");
                        else
                    strcpy((yyval.sym)->type, (yyvsp[0].sym)->type); }
#line 1608 "y.tab.c"
    break;

  case 52: /* T: T DIVIDE f  */
#line 194 "ninad.yacc"
                     { (yyval.sym) = malloc(sizeof(symbol)); strcpy((yyval.sym)->type, "REAL");}
#line 1614 "y.tab.c"
    break;

  case 53: /* T: T MOD f  */
#line 195 "ninad.yacc"
                  { (yyval.sym) = malloc(sizeof(symbol)); strcpy((yyval.sym)->type, "INT");}
#line 1620 "y.tab.c"
    break;

  case 54: /* T: f  */
#line 196 "ninad.yacc"
            { (yyval.sym) = malloc(sizeof(symbol)); 
                    strcpy((yyval.sym)->type, (yyvsp[0].sym)->type); }
#line 1627 "y.tab.c"
    break;

  case 55: /* f: LP e RP  */
#line 198 "ninad.yacc"
                { (yyval.sym) = malloc(sizeof(symbol)); 
                    strcpy((yyval.sym)->type, (yyvsp[-1].sym)->type); }
#line 1634 "y.tab.c"
    break;

  case 56: /* f: ID  */
#line 200 "ninad.yacc"
            { check_assigned((yyvsp[0].sval)); (yyval.sym) = malloc(sizeof(symbol)); symbol* s = lookup((yyvsp[0].sval)); 
                if(s->type=="INT" || s->type=="REAL")
                    strcpy((yyval.sym)->type, s->type); }
#line 1642 "y.tab.c"
    break;

  case 57: /* f: ID LB e RB  */
#line 203 "ninad.yacc"
                    { check_assigned((yyvsp[-3].sval)); }
#line 1648 "y.tab.c"
    break;

  case 58: /* f: NUM  */
#line 204 "ninad.yacc"
             { (yyval.sym) = malloc(sizeof(symbol)); strcpy((yyval.sym)->type, "INT"); }
#line 1654 "y.tab.c"
    break;


#line 1658 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 205 "ninad.yacc"

     
    int main() {
        char filename[100];
        printf("Enter the filename: ");
        scanf("%s", filename);
        yyin = fopen(filename, "r");
        if(yyin == NULL){
            printf("Error opening file!\n");
            return 1;
        }
        yyparse();
        if(flag==1){
            printf("valid input\n");
            printf("symbol table\n");
            for(int i=0;i<symtab_len;i++){
                printf("%-25s %-25s %-25d %-25d\n", symtab[i].name, symtab[i].type, symtab[i].assigned, symtab[i].isArray);
            }
        }
                    fclose(yyin);
        return 0;
    }
     
    int yyerror(const char *msg) {
        printf("Syntax error: %s\n", msg);
        return 0;
    }
