#include "crypt_helper.h"

/////////////////////////////////////////////
//��������:aes cbc padding�����ַ���
//��������:
//		in	Ҫ���ܵ��ַ���
//����ֵ:
//		���ܺ���ַ���
std::string encrypt_cbc(std::string in)
{
	// Encryptor ������
	CRijndael rin;
	unsigned char * pOutPut = new unsigned char[in.length() + 16];
	rin.Init(CRijndael::CBC, CRijndael::EncryptDir, (const unsigned char*)my_key,
		CRijndael::Key16Bytes, (const unsigned char*)my_iv);
	int nSize = rin.PadEncrypt((const unsigned char*)in.c_str(), in.length(), pOutPut);

	return Base64::base64Encode(pOutPut, nSize);
}

/////////////////////////////////////////////
//�ο�URL:http://www.cnblogs.com/yipu/articles/3871576.html
//��������:aes ecb padding�����ַ���(��Ӧphp��java��aes pkcs5padding����)
//��������:
//		in	Ҫ���ܵ��ַ���
//����ֵ:
//		���ܺ���ַ���
std::string encrypt_ecb(std::string in)
{
	// Encryptor ������
	CRijndael rin;
	unsigned char * pOutPut = new unsigned char[in.length() + 16];
	rin.Init(CRijndael::ECB, CRijndael::EncryptDir, (const unsigned char*)my_key,
		CRijndael::Key16Bytes, (const unsigned char*)my_iv);
	int nSize = rin.PadEncrypt((const unsigned char*)in.c_str(), in.length(), pOutPut);

	return Base64::base64Encode(pOutPut, nSize);
}