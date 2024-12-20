SHELL = /bin/bash
TESTCASE_FOLDER = ./testcase
CC=gcc
EXE=main
OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, stack.o custom_assert.o $(EXE).o)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) -c $< -o $@

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

run: all
	./$(EXE) 

runtest: all
	@for infile in $(TESTCASE_FOLDER)/*.in; do \
		outfile="$${infile%.in}.out"; \
		golden_outfile="$${infile%.in}.golden_mac"; \
		./$(EXE) < $$infile > $$outfile; \
		./golden_mac < $$infile > $$golden_outfile; \
		diff -I "assertion failed" -u $$golden_outfile $$outfile; \
		if [ $$? -ne 0 ]; then \
			echo "$$infile: Test failed"; \
			exit 1; \
		else \
			echo "$$infile: Test passed"; \
		fi; \
		rm -f $$golden_outfile; \
	done

debug: CC += -DDEBUG -g
debug: all
.PHONY: debug

clean:
	rm -f $(OBJDIR)/*.o $(EXE)
	rmdir $(OBJDIR)
	rm -f $(TARGET) $(TESTCASE_FOLDER)/*.out
.PHONY: clean