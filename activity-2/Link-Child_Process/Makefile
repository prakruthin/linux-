src = Link_Child.c
src1 = new.c
project = Link_Child
target: $(src) $(src1)
	gcc $< -o $@
	gcc $> -o new
run: $(project)
	./$^