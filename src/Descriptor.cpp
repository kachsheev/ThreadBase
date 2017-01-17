#include "Descriptor.hpp"

Descriptor::Descriptor()
{
	init();
}

Descriptor::~Descriptor()
{
	clear();
}

void Descriptor::init()
{
	int error = pthread_attr_init(&attributes());
	if (error >= 0)
	{
		setInitted(true);
	}
}

void Descriptor::clear()
{
	pthread_attr_destroy(&attributes());
}

