#include <cont_ref.h>

int main(){
	
	int *v = malloc2(sizeof(int));
	*v=10;
	int *w= malloc2(sizeof(int));
	print_nodes();
	*w = 20;
	atrib(v,w);
	print_nodes();
	char *c = malloc2(sizeof(char));
	*c = 'Z';
	print_nodes();
	atrib2(w,NULL);
	print_nodes();
	return 0;
}
