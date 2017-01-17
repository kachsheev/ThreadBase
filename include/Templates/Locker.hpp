#ifndef TEMPLATES_LOCKER_HPP
#define TEMPLATES_LOCKER_HPP

template<typename LockStruct>
class Locker
{
public:
	Locker(LockStruct &lockingStruct) : lockStruct(lockingStruct)
	{
	}

protected:
	LockStruct &get()
	{
		return lockStruct;
	}

private:
	LockStruct &lockStruct;
};

#endif // TEMPLATES_LOCKER_HPP
