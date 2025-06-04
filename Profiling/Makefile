perf:
	gcc -g -fno-omit-frame-pointer test1.c
	perf record ./a.out
	perf report

flamegraph:
	gcc -g -fno-omit-frame-pointer test1.c
	perf record --call-graph dwarf  -F 99 -g -- ./a.out
	perf script > out.perf
	~/Downloads/FlameGraph/stackcollapse-perf.pl ./out.perf > out.folded
	~/Downloads/FlameGraph/flamegraph.pl out.folded > flamegraph.svg
	firefox flamegraph.svg

	~/Downloads/hotspot-v1.5.1-x86_64.AppImage 

clean:
	rm -f *.out *.txt *.x *.data *.svg *.perf *.folded *.data*