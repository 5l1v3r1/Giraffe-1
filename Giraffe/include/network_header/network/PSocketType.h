// Huazhong Univserity of Science and Technology.
// project: Netlet Middleware
// author: tuxuping. 
// email:  xupingtu@gmail.com, 
// date:   2009-6-23
// all rights reserved.


#ifndef  PSOCKET_TYPE_H_
#define    PSOCKET_TYPE_H_



namespace  Network{

	class NETWORK_EXPORT PSocketType
	{

	public:
		PSocketType(U32   iType, S8 * inDeli, U32 iDeliSize, U32  iSizeFrom,
			U32 iSizeLen, U32  iSizeCountFrom);

		virtual ~PSocketType(void);

		U32						getSizeFrom()const ;
		U32						getSizeLen() const;
		U32						getSizeCountFrom() const ;
		void					getDelimitation( char *  store, U32  * storeLen) const;
		U32						getBaseHeaderLen( )const;

		U32						getId() const ;

	private:

		//��ʾ���ķָ�����һ��û�зָ���������httpЭ��ķָ���Ϊ��"\r\n\r\n"
		char					m_cDelimitation[8];

		//��ʾ���ķָ����ĳ��ȣ�http�ķָ����ĳ���Ϊ4���ֽڡ�
		U32						m_iDelimitationSize;

		// ��ʾ ��ʾ�����ȵ��Ǹ��ֶε�λ�ã�����ڰ�ͷ��һ���ֽڵ�ƫ�ơ�һ���ڰ������ֽڣ�Ϊ0
		U32						m_iSizeFrom;

		// ��ʾ ��ʾ�����ȵ��Ǹ��ֶ�ռ���ٸ��ֽڵĳ��ȡ�һ��Ϊ2���ֽڳ��ȡ����˰����ֻ��2^16�ֽڡ�
		U32						m_iSizeLen;

		// ��ʾ�����������ĳ��ȣ��е��Ǵӵ�0���ֽڼ��㣬�е���ȥ����ͷ��ʼ����
		U32						m_iSizeCountFrom;

		//�˰������͡�
		U32						m_iId;

	};

}

#endif // PSOCKET_TYPE_H_
