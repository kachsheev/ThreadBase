#include "Semaphore.hpp"

Semaphore::Semaphore()
{
	init();
}

Semaphore::Semaphore(unsigned int startValue)
{
	init(startValue);
}

Semaphore::~Semaphore()
{
	clear();
}

int Semaphore::value()
{
	int currentValue;
	int error = sem_getvalue(&get(), &currentValue);
	if (!error)
	{
		return currentValue;
	}
	else
	{
		return -1;
	}
}

void Semaphore::post()
{
	sem_post(&get());
}

void Semaphore::wait()
{
	sem_wait(&get());
}

bool Semaphore::tryWait()
{
	int error = sem_trywait(&get());
	if (error)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Semaphore::init()
{
	int error = sem_init(&get(), 0, 0u);
	if (!error)
	{
		setInitted(true);
	}
	else
	{
		setInitted(false);
	}
}

void Semaphore::init(unsigned int startValue)
{
	int error = sem_init(&get(), 0, startValue);
	if (!error)
	{
		setInitted(true);
	}
	else
	{
		setInitted(false);
	}
}

void Semaphore::clear()
{
	if (initted())
		sem_destroy(&get());
}
