targets = 'scheduler' 'enq' 'deq' 'stat'

.PHONY: clean
clean:
	for target in $(targets) ;\
	do \
		rm build/$$target; \
	done

all:
	for target in $(targets) ;\
	do \
		gcc $$target.c -o build/$$target; \
	done

sample:
	gcc sample.c -o build/sample
