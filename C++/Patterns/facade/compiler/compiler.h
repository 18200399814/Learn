#ifndef _COMPILCER
#define _COMPILCER

#include <iostream>

class Scanner
{
public:
	void scan()
	{
		std::cout<<"�ʷ�����"<<std::endl;
	}
};

class Parser
{
public:
	void parse()
	{
		std::cout<<"�﷨����"<<std::endl;
	}
};

class Compile
{
public:
	void compile()
	{
		std::cout<<"����"<<std::endl;
	}
};

class Assembly
{
public:
	void assemble()
	{
		std::cout<<"���"<<std::endl;
	}
};

class Linker
{
public:
	void link()
	{
		std::cout<<"�ν�"<<std::endl;
	}
};

class Compiler
{
public:
	void compile()
	{
		scanner.scan();
		parser.parse();
		compiling.compile();
		assembly.assemble();
		linker.link();
	}
private:
	Scanner scanner;
	Parser parser;
	Compile compiling;
	Assembly assembly;
	Linker linker;
};

#endif //_COMPILCER