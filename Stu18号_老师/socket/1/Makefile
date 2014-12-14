all: server client

server: srv.c wrap.c wrap.h lib.c lib.h
	gcc $^ -o $@

client: cli.c wrap.c wrap.h lib.c lib.h
	gcc $^ -o $@

.PHONY: all 
