targets = 'scheduler' 'enq' 'deq' 'stat'

.PHONY: clean
clean:
	for target in $(targets) ;\
	do \
		rm $$target; \
	done

all:
	for target in $(targets) ;\
	do \
		gcc $$target.c -o $$target; \
	done
