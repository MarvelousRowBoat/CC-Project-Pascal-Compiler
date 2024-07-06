%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <assert.h>
     
    #define MAX_SYMBOLS 1000
     
    int yylex();
    int yyerror(const char *msg);
    extern FILE *yyin;
    char finalTree[10000];

    typedef struct symbol {
    int isArray;
    char name[100];
    char type[10];
    char treeData[10000];
    int assigned;
    struct symbol* next;
	} symbol;
     
    symbol symtab[MAX_SYMBOLS];
    int symtab_len = 0;
    char* current_type = "";
    int flag=1;
    int is_array = 0;

    void setArray(symbol* list, int isArray){
       symbol* s = list;
       s->isArray = isArray;
       s->assigned = 1;
        
    } 
    symbol* lookup(char* name) {
        for(int i = 0; i < symtab_len; i++) {
            if(strcmp(symtab[i].name, name) == 0) {
                return &symtab[i];
            }
        }
        return NULL;
    }
    
    char* concatenate(int count, ...) {
    va_list args;
    int i;

    // First, determine total length of resulting string
    int length = 0;
    va_start(args, count);
    for(i = 0; i < count; i++) {
        char* str = va_arg(args, char*);
        length += strlen(str);
    }
    va_end(args);

    // Allocate memory for resulting string and null character
    char* result = malloc((length + 1) * sizeof(char));

    // Now, concatenate strings
    va_start(args, count);
    strcpy(result, va_arg(args, char*)); // Copy first string
    for(i = 1; i < count; i++) {
        strcat(result, va_arg(args, char*)); // Concatenate remaining strings
    }
    va_end(args);

    return result;
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
        // printf("TYPE: %s %s\n", s1->type, s2->type);
        //printf(" ");
        // printf("%s",s1->treeData);
        if(strcmp(s1->type, s2->type) != 0) {
        //printf("hi");
            printf("Error: Type mismatch in arithmetic operator");
                        flag=0;}       
            //exit(1);
        }
        //printf("hi");
     
}
typedef struct assign_stmt {
    symbol* var;
    symbol* expr;
} assign_stmt; 
void check_assign_type(assign_stmt* stmt) {
    if(stmt->var != NULL && stmt->expr != NULL) {
        //printf("TYPE: %s %s\n", stmt->var->type, stmt->expr->type);
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
    %}
%union
{
        int ival;
        double rval;
        char* sval;
        struct symbol* sym;
}
     
%token PROG_ID INT REAL BOOL VAR CHAR TO DOWNTO IF ELSE WHILE FOR THEN DO ARRAY OF AND OR NOT BEG END READ WRITE 
           PLUS MINUS MULTIPLY DIVIDE MOD EQUAL ASSIGN LT GT LTE GTE NE SEMICOLON COLON COMMA DOT LP RP LB RB
%token <ival> NUM
%token <sval> STRING ID RANGE
%token <rval> REALNUM
/* %type <sval>   */
%type <sym> t type varlist f T e expression assign_stmt stmt Block if_stmt for_stmt while_stmt io_stmt stmt_list varlis else_part va v prog
%left NOT
%left AND
%left  OR
%%
                                        // flag = 1;
    prog: PROG_ID SEMICOLON v Block DOT { strcpy(finalTree, concatenate(5,"prog[PROG_ID][;][v",$3->treeData,"][Block",$4->treeData,"][.]")); FILE *out = fopen("syntaxtree.txt" , "w"); fprintf(out , "[%s]",finalTree);}
        ;
    v : VAR va { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[VAR][va",$2->treeData,"]")); }
        | { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, "");};
    va: va varlist COLON type SEMICOLON {current_type = $4->type; assign_type($2, current_type); if(is_array){ setArray($2 , is_array);} is_array = 0;$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(7,"[va",$1->treeData,"][varlist:",$2->treeData,"][COLON][type:",$4->treeData,"][;]")); } 
    | varlist COLON type SEMICOLON {current_type = $3->type; assign_type($1, current_type); if(is_array){ setArray($1 , is_array);} is_array = 0; $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(5,"[varlist:",$1->treeData,"][COLON][type:",$3->treeData,"][;]")); }; 
    type: t { $$ = malloc(sizeof(symbol)); strcpy($$->type, $1->type); strcpy($$->treeData, concatenate(3,"[t",$1->treeData,"]"));}
        | ARRAY RANGE OF t {$$ = malloc(sizeof(symbol));strcpy($$->type , $4->type); is_array = 1; strcpy($$->treeData, concatenate(5,"[ARRAY][RANGE",$2,"][OF][t",$4->treeData,"]")); } 
    t: INT {$$ = malloc(sizeof(symbol)); strcpy($$->type, "INT");strcpy($$->treeData, "[INT]");}
        | REAL {$$ = malloc(sizeof(symbol));strcpy($$->type ,"REAL");   strcpy($$->treeData, "[REAL]");}
        | BOOL  {$$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL");   strcpy($$->treeData, "[BOOL]");}
        | CHAR {$$ = malloc(sizeof(symbol));strcpy($$->type, "CHAR");   strcpy($$->treeData, "[CHAR]");}
    varlist: varlist COMMA ID { $$ = insert($3); $$->next = $1;strcpy($$->treeData, concatenate(5,"[varlist:",$1->treeData,"][,][ID:",$3,"]"));}
        | ID { $$ = insert($1);  strcpy($$->treeData,concatenate(3,"[ID:",$1,"]"));}; 
    stmt_list:  stmt stmt_list{ $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(5,"[stmt",$1->treeData,"][stmt_list",$2->treeData,"]")); printf(" ");}  
        | { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, "");}
        ;
    stmt: Block  {$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[Block",$1->treeData,"]"));}
        |assign_stmt SEMICOLON { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[assign_stmt",$1->treeData,"][;]"));}
        | if_stmt SEMICOLON { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[if_stmt",$1->treeData,"][;]"));}
        | for_stmt SEMICOLON { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[for_stmt",$1->treeData,"][;]"));}
        | while_stmt SEMICOLON { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[while_stmt",$1->treeData,"][;]"));}
        | io_stmt SEMICOLON { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[io_stmt",$1->treeData,"][;]"));}
        ;
    Block: BEG stmt_list END {$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[BEG][stmt_list",$2->treeData,"][END]")); }
        ;
    io_stmt: READ LP ID RP{  assign($3); $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[READ][(][ID:",$3,"][)]")); } 
        | READ LP ID LB e RB RP{ assign($3); $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(5,"[READ][(][ID:",$3,"][)][expression",$5->treeData,"]"));}
        | WRITE LP STRING RP {$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[WRITE][STRING:",$3,"]"));}
        | WRITE LP varlis RP {$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[WRITE][varlis",$3->treeData,"]"));};
    varlis: varlis COMMA ID { check_assigned($3); $$=malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(5,"[varlis:",$1->treeData,"][,][ID:",$3,"]"));}
            | ID {check_assigned($1); $$=malloc(sizeof(symbol)); strcpy($$->treeData, $1); }   
    if_stmt: IF expression THEN stmt else_part { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(7,"[IF][expression",$2->treeData,"][THEN][stmt",$4->treeData,"][else_part",$5->treeData,"]"));};
    else_part: ELSE stmt { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(3,"[ELSE][stmt",$2->treeData,"]"));}
        | { $$ = malloc(sizeof(symbol)); strcpy($$->treeData, "");};
    while_stmt: WHILE expression DO stmt {$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(5,"[WHILE][expression",$2->treeData,"][DO][stmt",$4->treeData,"]"))   ;}
    for_stmt: FOR assign_stmt TO e DO stmt {$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(7,"[FOR][assign_stmt:",$2->treeData,"][TO][e",$4->treeData,"][DO][stmt",$6->treeData,"]"));};
        | FOR assign_stmt DOWNTO e DO stmt {$$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(7,"[FOR][assign_stmt:",$2->treeData,"][DOWNTO][e",$4->treeData,"][DO][stmt",$6->treeData,"]"));};
    assign_stmt: ID ASSIGN expression { assign($1); symbol *s=lookup($1);if(s->type!=NULL) {check_expr_type(s, $3);} $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(5,"[ID:",$1,"][:=][expression",$3->treeData,"]"));  
    }
        |ID LB e RB ASSIGN e { assign($1); $$ = malloc(sizeof(symbol)); strcpy($$->treeData, concatenate(7,"[ARRAY:",$1,"][(][index:expression",$3->treeData,"][)][:=][e",$6->treeData,"]"));}
    expression: e LT e { $$ = malloc(sizeof(symbol)); strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][LT][e",$3->treeData,"]"));}
        | e GT e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][GT][e",$3->treeData,"]"));}
        | e LTE e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][LTE][e",$3->treeData,"]"));}
        | e GTE e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][GTE][e",$3->treeData,"]"));}
        | e NE e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][NE][e",$3->treeData,"]"));}
        | e EQUAL e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][EQUAL][e",$3->treeData,"]"));}
        | e AND e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][AND][e",$3->treeData,"]"));}
        | e OR e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][OR][e",$3->treeData,"]"));}
        | NOT e { $$ = malloc(sizeof(symbol));strcpy($$->type,"BOOL"); strcpy($$->treeData, concatenate(3,"[NOT][e",$2->treeData,"]"));}
        | e { $$ = malloc(sizeof(symbol));
                strcpy($$->type, $1->type); 
              strcpy($$->treeData, concatenate(3,"[e",$1->treeData,"]"));
              //printf("%s",$$->treeData);
              };
    e: e PLUS T { $$ = malloc(sizeof(symbol)); 
                        strcpy($$->type, $3->type); 
                        strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][+][T",$3->treeData,"]"));}
        | e MINUS T { $$ = malloc(sizeof(symbol)); 
                    strcpy($$->type, $3->type);
                    strcpy($$->treeData, concatenate(5,"[e",$1->treeData,"][-][T",$3->treeData,"]"));} 
        | T { $$ = malloc(sizeof(symbol)); 
                    strcpy($$->type, $1->type);
                     strcpy($$->treeData, concatenate(3,"[T",$1->treeData,"]"));
                     //printf("%s",$$->treeData);
                     }
    T: T MULTIPLY f { $$ = malloc(sizeof(symbol)); 
                        if(strcmp($1->type,"REAL")==0) strcpy($$->type, "REAL");
                        else if(strcmp($3->type,"REAL")==0) strcpy($$->type, "REAL");
                        else
                    strcpy($$->type, $3->type); 
                    strcpy($$->treeData, concatenate(5,"[T",$1->treeData,"][*][f",$3->treeData,"]"));}
        | T DIVIDE f { $$ = malloc(sizeof(symbol)); strcpy($$->type, "REAL");
        strcpy($$->treeData, concatenate(5,"[T",$1->treeData,"][/][f",$3->treeData,"]"));}
        | T MOD f { $$ = malloc(sizeof(symbol)); strcpy($$->type, "INT");
        strcpy($$->treeData, concatenate(5,"[T",$1->treeData,"][%][f",$3->treeData,"]"));}  
        | f { $$ = malloc(sizeof(symbol)); 
                    strcpy($$->type, $1->type); 
                    strcpy($$->treeData,concatenate(3,"[f",$1->treeData,"]"));
                    //printf("%s",$$->treeData);
                    }
    f:  LP e RP { $$ = malloc(sizeof(symbol)); 
                    strcpy($$->type, $2->type); 
                    strcpy($$->treeData, concatenate(3,"[(][e",$2->treeData,"][)]"));}
        |ID { check_assigned($1); $$ = malloc(sizeof(symbol)); symbol* s = lookup($1); 
                if(strcmp(s->type,"REAL")==0|| strcmp(s->type,"INT")==0)
                    strcpy($$->type, s->type); 
                strcpy($$->treeData, concatenate(3,"[ID:",s->name,"]"));
                // printf("%s",$$->treeData);
                }
        |ID LB e RB { check_assigned($1); $$ = malloc(sizeof(symbol)); symbol* s=lookup($1); 
                    strcpy($$->type,s->type); strcpy($$->treeData, concatenate(5,"[ARRAY:",$1,"][(][index:expression",$3->treeData,"][)]"));}
        |NUM { $$ = malloc(sizeof(symbol)); strcpy($$->type, "INT"); strcpy($$->treeData, "[NUM]");};    
    %%
     
    int main(int argc, char *argv[]) {
        char filename[100];
        if(argc < 2) {
            printf("Filename not provided!\n");
            return 1;
        }
        strcpy(filename, argv[1]);
        yyin = fopen(filename, "r");
        if(yyin == NULL){
            printf("Error opening file!\n");
            return 1;
        }
        yyparse();
        if(flag==1){
            printf("valid input\n");
           
        }
          /* printf("symbol table\n");
            for(int i=0;i<symtab_len;i++){
                printf("%-25s %-25s %-25d %-25d\n", symtab[i].name, symtab[i].type, symtab[i].assigned, symtab[i].isArray);
            }  */
                    fclose(yyin);
        return 0;
    }
     
    int yyerror(const char *msg) {
        printf("Syntax error: %s\n", msg);
        return 0;
    }