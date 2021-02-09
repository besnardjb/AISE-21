all: reader writer
reader: reader.c
	gcc -o $@ $<

writer: writer.c
	gcc -o $@ $<

clean:
	rm -f file.txt reader writer
.PHONY: clean
