#ifndef DESCRIPTOR_HPP
#define DESCRIPTOR_HPP

#include <pthread.h>
#include "Templates/PthreadObject.hpp"

class Descriptor: public PthreadObject<pthread_t, pthread_attr_t>
{
public:
	Descriptor();
	virtual ~Descriptor();

private:
	typedef PthreadObject<pthread_t, pthread_attr_t> Parent;
	virtual void init();
	virtual void clear();
};

#endif // DESCRIPTOR_HPP
