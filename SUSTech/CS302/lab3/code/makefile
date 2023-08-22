targets = 'scheduler' 'enq' 'deq' 'stat'
samples = '100ms' 'inf'


.PHONY: clean 100ms inf run

100ms:
	build/enq $$PWD/build/100ms

inf:
	build/enq $$PWD/build/inf

run:
	build/scheduler

clean:
	for target in $(targets) ;\
	do \
		rm build/$$target; \
	done
	for sample in $(samples) ;\
	do \
		rm build/$$sample; \
	done

sampler:
	for sample in $(samples) ;\
	do \
		gcc samples/$$sample.c -o build/$$sample; \
	done

scheduler:
	for target in $(targets) ;\
	do \
		gcc $$target.c -o build/$$target; \
	done

all: sampler scheduler


