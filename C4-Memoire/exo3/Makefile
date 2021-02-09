all: user owner
user: user.c
	gcc -o $@ $<

owner: owner.c
	gcc -o $@ $<

clean:
	rm -f file.txt owner user
.PHONY: clean
