#ifndef OBJECT_HPP
#define OBJECT_HPP

template<class Type, class Attr>
class PthreadObject
{
public:
	PthreadObject() : initStatus(false)
	{
	}

	virtual ~PthreadObject()
	{
	}

	Type &get() noexcept
	{
		return obj;
	}

	const Type &get() const noexcept
	{
		return obj;
	}

	Attr &attributes() noexcept
	{
		return attr;
	}

	const Attr &attributes() const noexcept
	{
		return attr;
	}

	bool initted() const noexcept
	{
		return initStatus;
	}

protected:
	virtual void init() = 0;
	virtual void clear() = 0;

	void setInitted(bool initted)
	{
		initStatus = initted;
	}

private:
	bool initStatus;
	Type obj;
	Attr attr;
};

#endif // OBJECT_HPP
