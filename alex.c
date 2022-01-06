#include "alex.h"
#include <ctype.h>
#include <string.h>

static int  ln = 0;
static char ident[256];
static FILE *ci = NULL;

int isKeyword(char * name) {
	if (strcmp(name, "int")==0)
		return 1;
	if (strcmp(name, "double")==0)
		return 1;
	if (strcmp(name, "float")==0)
		return 1;
	if (strcmp(name, "char")==0)
		return 1;
	if (strcmp(name, "while")==0)
		return 1;
	if (strcmp(name, "for")==0)
		return 1;
	if (strcmp(name, "if")==0)
		return 1;
	if (strcmp(name, "void")==0)
		return 1;
	if (strcmp(name, "switch")==0)
		return 1;
	if (strcmp(name, "ifndef")==0)
		return 1;
	if (strcmp(name, "define")==0)
		return 1;
	if (strcmp(name, "endif")==0)
		return 1;
	return 0;	
}

void alex_init4file( FILE *in ) {
   ln = 0;
   ci = in;
}

lexem_t alex_nextLexem( void ) {
	int c;
	while( (c= fgetc(ci)) != EOF ) {
 		if( isspace( c ) )
                        continue;
    		else if( c == '\n' ){
			ln++;
			continue;
		}
    		else if( c == '(' )
                        return OPEPAR;
    		else if( c == ')' )
      			return CLOPAR;
    		else if( c == '{' )
                        return OPEBRA;
    		else if( c == '}' )
                        return CLOBRA;
    		else if( isalpha(c) || c == '_' ) {
      			int i = 1;
      			ident[0] = c;
      			while( isalnum( c= fgetc(ci) ) || c == '_')
	      			ident[i++] = c;
              		ident[i] = '\0';
			
			// zwroc znak spowrotem do strumienia
			ungetc(c, ci);

      			return isKeyword(ident) ? OTHER : IDENT;
    		}

		else if( c == '"' ) {
			c = fgetc(ci);
      			while( c != EOF && c != '"' )
                		c = fgetc(ci);
				if( c == '\n' )
					ln++;
      			return c == EOF ? EOFILE : OTHER; 
    		}

		else if( c == '/' ) {
      			c = fgetc(ci);
			if( c == '/' ) {
				c = fgetc(ci);
				while( c != '\n' )
					c = fgetc(ci);
				ln++;
			}
			else if( c == '*' ) {
				c = fgetc(ci);
				while( 1 ) {
					if( c == '*' ) {
						c = fgetc(ci);
						if( c == '/' )
						       break;
						else if( c == '\n' )
							ln++;
					else if( c == '\n' )
						ln++;	
					}
					c = fgetc(ci);
				}
			}

			while( ! isspace(c) )
				c = fgetc(ci);
			return OTHER;
    		}

		else if( isdigit(c) || c == '.' ) {
      			c = fgetc(ci);
			while( ! isspace(c) )
				c = fgetc(ci);
			return OTHER;
    		}

		else {
      			return OTHER;
    		}
	}       
  	return EOFILE;
}

char * alex_ident( void ) {
   	return ident;
}

int alex_getLN() {
	return ln;
}

