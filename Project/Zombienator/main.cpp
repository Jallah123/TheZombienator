#include <iostream>
#include "Program.h"

int main(int argc, char* args[])
{
	Program* p = Program::getInstance();
	p->Start();
	return 0;
}
