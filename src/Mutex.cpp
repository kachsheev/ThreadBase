#include "Mutex.hpp"

Mutex::Mutex()
{
	init();
}

Mutex::Mutex(bool locked): Mutex()
{
	if (locked)
	{
		lock();
	}
}

Mutex::~Mutex()
{
	clear();
}

void Mutex::lock()
{
	pthread_mutex_lock(&get());
}

bool Mutex::tryLock()
{
	int err = pthread_mutex_trylock(&get());
	return err > 0;
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&get());
}

void Mutex::init()
{
	pthread_mutexattr_init(&attributes());
	pthread_mutex_init(&get(), &attributes());
}

void Mutex::clear()
{
	pthread_mutex_destroy(&get());
	pthread_mutexattr_destroy(&attributes());
}

