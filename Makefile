CC=gcc
CFLAGS=-Wall
LEX=flex
YACC=bison
LIBS=-lfl -lm
RM=rm -f

# Archivos de salida de flex y bison
LEX_SOURCE=lex.yy.c
YACC_SOURCE=calc.tab.c
YACC_HEADER=calc.tab.h

# Objetivos de archivos de objeto
OBJECTS=calc.tab.o lex.yy.o abb.o TS.o funciones.o

# Nombre del ejecutable final
EXECUTABLE=calculadora

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

# Compilación de código C generado por Bison
calc.tab.o: $(YACC_SOURCE) $(YACC_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilación de código C generado por Flex
lex.yy.o: $(LEX_SOURCE)
	$(CC) $(CFLAGS) -c $< -o $@

# Generar código fuente C desde Bison
$(YACC_SOURCE) $(YACC_HEADER): calc.y
	$(YACC) -d $<

# Generar código fuente C desde Flex
$(LEX_SOURCE): flex.l $(YACC_HEADER)
	$(LEX) $<

# Compilación de otros archivos C del proyecto
abb.o: abb.c abb.h
	$(CC) $(CFLAGS) -c $< -o $@

TS.o: TS.c TS.h
	$(CC) $(CFLAGS) -c $< -o $@

funciones.o: funciones.c funciones.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpieza del proyecto
clean:
	$(RM) $(EXECUTABLE) $(OBJECTS) $(LEX_SOURCE) $(YACC_SOURCE) $(YACC_HEADER)

# Ejecutar el programa
run: $(EXECUTABLE)
	valgrind ./$(EXECUTABLE)
