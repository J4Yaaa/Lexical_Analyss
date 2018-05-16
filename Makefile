a.out:main.c lexical_analysis.c
	gcc -o $@ $^ -g
.PHONY:clean
clean:
	rm a.out
