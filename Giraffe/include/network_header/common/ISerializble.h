// Huazhong Univserity of Science and Technology.
// project: Netlet Middleware
// author: tuxuping ( borrowed)  
// Author: ArcherSC
// email:  xupingtu@gmail.com, 
// date:   2009-6-23
// all rights reserved.

// tuxuping, kimi
// to serialize a object to binary bytes.

/*
revised by kimi 2008-12-03
STRING_MAXSIZE, writeString, readString
*/

#ifndef ISERIALIZBLE_H
#define ISERIALIZBLE_H



enum
{
	STRING_MAXSIZE = 1024,//MAX_CHAT_MSG_LENGTH,//�����ַ�������󳤶�
};



U32 getStringLength(const String& s);


class NETWORK_EXPORT ISerializble
{
public:
	virtual ~ISerializble(void);


	static void							writeU8(S8 * buff, U8 value);
	static void							writeU16(S8 * buff, U16 value);
	static void							writeU32(S8 * buff, U32 value);
	static void							writeS8(S8 * buff, S8 value);
	static void							writeS16(S8 * buff, S16 value);
	static void							writeS32(S8 * buff, S32 value);

	static U8							readU8(const S8 * buff );
	static U16							readU16(const S8 * buff );
	static U32							readU32(const S8 * buff );
	static S8							readS8(const S8 * buff );
	static S16							readS16(const S8 * buff ) ;
	static S32							readS32(const S8 * buff );

	static void							readU8(const S8 * buff ,U8& value);
	static void							readU16(const S8 * buff ,U16& value);
	static void							readU32(const S8 * buff ,U32& value);
	static void							readS8(const S8 * buff ,S8& value);
	static void							readS16(const S8 * buff ,S16& value);
	static void							readS32(const S8 * buff ,S32& value);

	//64λ����
	static void							writeU64(S8 * buff, U64 value);
	static void							writeS64(S8 * buff, S64 value);
	static U64								readU64(const S8 * buff);
	static S64								readS64(const S8 * buff);
	static void							readU64(const S8 * buff, U64& value);
	static void							readS64(const S8 * buff, S64& value);

	static void							writeBytes(S8 * buff, const char* data, std::size_t len);
	static char*							readBytes(const S8 * buff, char* data, std::size_t len);

	static U32								writeString(S8 * buff, const String& str);
	static String							readString(const S8 * buff);
	static U32								readString(const S8 * buff, String& str);

//Added by Wu
	static void								writeB8(S8 * buff, B8 value);
	static B8									readB8(const S8 * buff );


	virtual U32						getLength( ) const;

	// ���������л����������У��磺���緢��ǰд����������
	// buf: ���������׵�ַ�� offset: ��ʾ��ƫ����Ϊoffset�ĵط���ʼ��д����
	// ע�⣺����û�г��Ȱ�ȫ��飬ʹ��ǰ������ȷ���ڴ�Խ����
	virtual U32						serialize( S8 *  buf,  S32 offset ) const = 0;

	// �������������ݷ����л�Ϊ�����磺�����Ͻ��յ������ݴ���ڻ����У�
	// ��������ݻָ�Ϊ������
	// buf: ���������׵�ַ�� offset: ��ʾ��ƫ����Ϊoffset�ĵط���ʼ��������
	// ע�⣺����û�г��Ȱ�ȫ��飬ʹ��ǰ������ȷ���ڴ�Խ����
	virtual U32						deserialize( const S8 * buf, S32 offset ) = 0;


	U32								getStringLength(const String& s)const;
	
};


#endif//ISERIALIZBLE_H

