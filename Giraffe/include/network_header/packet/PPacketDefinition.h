#ifndef   PPKTDEF_H
#define PPKTDEF_H 

// billion Coporation. Ltd
// author: tuxuping. 2009-6-23
// all rights reserved.

/************************************************************************/
/*���а�������ö�����������*/ //tuxuping 2008-5-20
/************************************************************************/

enum 
{
	//��ͷ���ݵ�ƫ����
	PACKET_LENGTH_OFFSET = 0,//������
	PACKET_TYPE_OFFSET = 2,//������
	PACKET_SUBTYPE_OFFSET = 3,//��������
	PACKET_VERSION_OFFSET = 4,//���汾
	PACKET_CHECKSUM_OFFSET = 6,//У���
	PACKET_DATA_OFFSET = 8,//������

	UDPPACKET_MAXSIZE = 1460,//UDP������󳤶�
	//modified by taozhe 2010.4.17
	//TCPPACKET_MAXSIZE = 4096,
	TCPPACKET_MAXSIZE = 8*1024*1024,//TCP������󳤶�

	CURRENT_PKT_VERSION = 2,//���ĵ�ǰ�汾
	COMMON_HEAD_LENGTH = 8,//��ͷ��������
};


/*
���Ľṹ������, length =����ͷ�ĳ��ȡ�+ ��other content�ĳ��ȡ���
-------------------------------------------------------------------
| length(2)|type(1)|subtype(1)|version(2)|checksum(2)|other content|
|------------------------------------------------------------------
|<----------------------��  ͷ---------------------->|
*/


namespace PPktDef
{

	// major type :  between 1 and 20.
	enum PacketType{
		// old is:
		//PEER_TO_NAT_SERVER = 6,  // with nat server.
		//INTERNAL_COMMUNICATION = 13, //added by tuxuping.

		PEER_TO_NAT_SERVER = 1,  // with nat server.
		INTERNAL_COMMUNICATION = 2, //added by tuxuping.		
		USER_DEFINE_MAJOR = 3, 

		MAX_MAJOR_TYPE = 255,
		UNDEFINE_PKT  = 0xff,//δ����İ�����
	};	

	//PEER_TO_NAT_SERVER = 6,  // with nat server.
	// minor type:
	enum {
		USER_DEFINE_MINOR = 20,
	};

	enum{

		NAT_REQ = 60,
		NAT_ACK = 61,
		NAT_TEST_REQ = 62,
		NAT_TEST_ACK =63,
		NAT_NOTIFY = 64,
		NAT_HEARTBEAT = 65,	
		NAT_RELAY = 66,
	};


	//PEER_TO_LOG_SERVER = 7,  // with log server.
	// minor type:
	enum {
		LOG_RESEARCH  = 70,
		LOG_DEBUG = 71,
	};

	// INTERNAL_COMMUNICATION = 13, internal platform communiction with itself. added by tuxuping 2008-9-27
	enum
	{
		QUIT_APPLICATION = 121,
		NO_DELETE = 122, // added.
	};

	NETWORK_EXPORT String   type2String( U8 type, U8 subtype );
	
}

#endif //PPKTDEF_H

