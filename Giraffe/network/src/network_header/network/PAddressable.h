// Huazhong Univserity of Science and Technology.
// project: Netlet Middleware
// author: tuxuping. 
// email:  xupingtu@gmail.com, 
// date:   2009-6-23
// all rights reserved.

//xupingtu 2008-6-12.

#ifndef PADDRESSABLE_H
#define PADDRESSABLE_H

#include "common/Header.h"
#include "common/ISerializble.h"

namespace Network {

	class NETWORK_EXPORT PAddressable : public ISerializble
	{

	public:

		// added by tuxuping, 2008-9-25
		//    FAIL_TRANSIT   NAT  FIREWALL UPNP
		//     (0/1)         (0/1) (0/1)   (0/1)
		// normal condition is: 0000, transit, no nat, no firewall, no upnp.
		enum{
			 NAT_nFIREWARLL_nUPNP = 4, //�����޷���ǽ��UPNP : 0100
			 nNAT_FIREWALL_nUPNP  = 2, //�����з���ǽ��UPNP : 0010
			 nNAT_nFIREWALL_nUPNP = 0, //�����޷���ǽ��UPNP:  0000
			 // �ݲ����ǣ����е����������޷���ǽ��
			 NAT_FIREWALL_nUPNP   = 6, //�����з���ǽ��UPNP:  0110

			 // ����������ָ��Ϊ����δ֪ԭ�򣬶����ܴ�Խ�������
			 nTRANSIT_NAT_nFIREWARLL_nUPNP = 8+4, //����Խ�����޷���ǽ��UPNP : 1100
			 nTRANSIT_nNAT_FIREWALL_nUPNP  = 8+2, //����Խ�����з���ǽ��UPNP : 1010

			 // 8+0 ��ʾls �ж�ʧ����Ϊ�����������û�з���ǽ����ôӦ�ò��������������ġ�
			 nTRANSIT_nNAT_nFIREWALL_nUPNP = 8+0, //����Խ�����޷���ǽ��UPNP:  1000
			 // �ݲ����ǣ����е����������޷���ǽ��
			 nTRANSIT_NAT_FIREWALL_nUPNP   = 8+6, //����Խ�����з���ǽ��UPNP:  1110
		};
    
    public:
 
		PAddressable( ) ;

		PAddressable( U32 pub_ip, U16 pub_port,U32 pri_ip, U16 pri_port, S8 netstatus, const unsigned char *pHost = NULL, unsigned short port = 0);
		
		~PAddressable();

		void Set( unsigned int addr, unsigned short port );

		static void				InetAddrLongToString( unsigned long iAddr, char *strAddr );

		virtual U32			getLength( ) const;

		virtual U32			serialize( S8 *  buf,  S32 offset ) const;

		virtual U32			deserialize( const S8 * buf, S32 offset );

		String					toString()const;

		U32						toString(S8 *  to_str)const;

		PAddressable &operator = ( const PAddressable &right );

		B8		operator		<( const PAddressable & addrssable ) const ;

		B8		operator		==( const PAddressable & addrssable )const ;

		U32						getGIP()const ;
		U32						getRIP()const ;
		U16						getGPort()const  ;
		U16						getRPort()const  ;
		U8						getNetStatus()const ;
		B8							hasUPnP()const; 
		B8							hasFireWall()const;
		B8							isFail2Transit()const;
		void						setFailTransit( B8	fail_or_not );
		B8							hasIP()const;  

		void						setNetStatus(U8 x); 
		void						setGIP(U32 x); 
		void						setRIP(U32 x); 
		
		void						setGPort(U16 x); 
		void						setRPort(U16 x); 

		// any field is 0, added by tuxuping , 2008-7-18
		B8							isNull() const;

		// get a null object. added by tuxuping , 2008-7-18
		static const PAddressable	&	getNull() ;

	private:	
		U32						m_iGIP;//�����ֽ���
		U32						m_iRIP;//�����ֽ���
		U8						m_cNetStatus;		
		U16						m_sGPort;//�����ֽ���
		U16						m_sRPort;//�����ֽ���

	};

}

#endif //PADDRESSABLE_H

