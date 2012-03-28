#pragma once

#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread.hpp>
#include <queue>


template <typename T > 
class  PSynQueue
{
	typedef boost::recursive_mutex MutexType;//ʹ�õݹ���

public:
	void push( const T& t) 
	{
		m_oQueue.push(t);
	}

	const T&	 front ( ) const
	{
		return m_oQueue.front();
	}

	void    pop( )
	{
		m_oQueue.pop();
	}

	bool	empty( ) const
	{
		return m_oQueue.empty();
	}

	void	lock( ) 
	{
		m_oMutex.lock();
	}

	void	unlock( )
	{
		m_oMutex.unlock();
	}

protected:
	//typedef MutexType::scoped_lock ScopedLockType;//ʹ��scoped lock����
	MutexType m_oMutex;//��
	std::queue< T >  m_oQueue;
};
