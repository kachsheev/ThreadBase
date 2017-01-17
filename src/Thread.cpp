#include "Thread.hpp"

Thread::Thread() :
		descriptor(),
		status(Thread::Status::NOT_RUN),
		semaphore(1u)
{
}

Thread::~Thread()
{
	join();
}

void Thread::start()
{
	setStatus(Thread::Status::STARTING);
	pthread_create(&descriptor.get(), &descriptor.attributes(),
			Thread::threadTask, nullptr);
}

void Thread::join()
{
	if (getStatus() != Thread::Status::FINISHED
			&& getStatus() != Thread::Status::NOT_RUN)
		pthread_join(descriptor.get(), nullptr);
}

void Thread::cancel()
{
	if (pthread_cancel(descriptor.get()) < 0)
	{
		setStatus(Thread::Status::FINISHED);
	}
}

Thread::Status Thread::getStatus() const
{
	return status;
}

void Thread::setStatus(Thread::Status newStatus)
{
	volatile Semaphore::Locker locker(semaphore);
	status = newStatus;
}

void Thread::enableCancel()
{
}

void Thread::disableCancel()
{
}

void *Thread::threadTask(void *data)
{
	Thread *thread = reinterpret_cast<Thread *>(data);

	thread->setStatus(Thread::Status::READY);
	thread->run();
	thread->setStatus(Thread::Status::FINISHED);

	return nullptr;
}
