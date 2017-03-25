#include "crypt_helper.h"

/////////////////////////////////////////////
//函数功能:aes cbc padding加密字符串
//函数参数:
//		in	要加密的字符串
//返回值:
//		加密后的字符串
std::string encrypt_cbc(std::string in)
{
	// Encryptor 加密器
	CRijndael rin;
	unsigned char * pOutPut = new unsigned char[in.length() + 16];
	rin.Init(CRijndael::CBC, CRijndael::EncryptDir, (const unsigned char*)my_key,
		CRijndael::Key16Bytes, (const unsigned char*)my_iv);
	int nSize = rin.PadEncrypt((const unsigned char*)in.c_str(), in.length(), pOutPut);

	return Base64::base64Encode(pOutPut, nSize);
}

/////////////////////////////////////////////
//参考URL:http://www.cnblogs.com/yipu/articles/3871576.html
//函数功能:aes ecb padding加密字符串(对应php、java的aes pkcs5padding加密)
//函数参数:
//		in	要加密的字符串
//返回值:
//		加密后的字符串
std::string encrypt_ecb(std::string in)
{
	// Encryptor 加密器
	CRijndael rin;
	unsigned char * pOutPut = new unsigned char[in.length() + 16];
	rin.Init(CRijndael::ECB, CRijndael::EncryptDir, (const unsigned char*)my_key,
		CRijndael::Key16Bytes, (const unsigned char*)my_iv);
	int nSize = rin.PadEncrypt((const unsigned char*)in.c_str(), in.length(), pOutPut);

	return Base64::base64Encode(pOutPut, nSize);
}