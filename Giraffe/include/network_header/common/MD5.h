// Huazhong Univserity of Science and Technology.
// project: Netlet Middleware
// author: tuxuping ( borrowed)  
// Author: ArcherSC
// email:  xupingtu@gmail.com, 
// date:   2009-6-23
// all rights reserved.

#ifndef  MD5_H
#define  MD5_H 

class MD5
{
private:
	unsigned int		m_Content[16];
	unsigned int		m_ContentLen;
	unsigned int		m_TotalLen;
	static unsigned int m_T[64];
	unsigned int		m_A, m_B, m_C, m_D;

private:
	inline void			FF(unsigned int& a, unsigned int b, unsigned int c, unsigned int d, int k, int i, int s);
	inline void			GG(unsigned int& a, unsigned int b, unsigned int c, unsigned int d, int k, int i, int s);
	inline void			HH(unsigned int& a, unsigned int b, unsigned int c, unsigned int d, int k, int i, int s);
	inline void			II(unsigned int& a, unsigned int b, unsigned int c, unsigned int d, int k, int i, int s);
	inline unsigned int roateLeft(unsigned int a, unsigned int c);

	void				transform();

public:
	//��ʼ��
	void				beginCal();
	//�����������������ˣ���������λ
	void				endCal();
	//��ʼ�����������ݣ��ڵ���endCalǰ�������Լ����������
	void				addData(const char* data, unsigned int size);
	//���������ȡ�ñ���
	char*				getCode();
	void				clearMemoryHelper(char* p);
};

#endif
