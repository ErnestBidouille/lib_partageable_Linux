#include <iostream>
#include <dlfcn.h>

void validate(void *handle)
{
	if (!handle)
	{
		fprintf(stderr, "dlopen failed: %s\n", dlerror());
		exit(EXIT_FAILURE);
	}
}
int main(int argc, char **argv)
{
	void *libComposant1 = dlopen("libComposant1.so", RTLD_NOW);
	validate(libComposant1);
	void *libComposant2 = dlopen("libComposant2.so", RTLD_NOW);
	validate(libComposant2);
	int data1 = 3;
	int data2 = 5;
	int (*composant1)(int, int) = (int (*)(int, int))dlsym(libComposant1, "composant1");
	int (*composant2)(int, int) = (int (*)(int, int))dlsym(libComposant2, "composant2");
	char *(*getComposant1Version)(void) = (char *(*)(void))dlsym(libComposant1, "getComposant1Version");
	int valeur1 = composant1(data1, data2);
	int valeur2 = composant2(data1, data2);
	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 : " << valeur1 << " valeur 2 : " << valeur2 << std::endl;
	dlclose(libComposant1);
	dlclose(libComposant2);
}