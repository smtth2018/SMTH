// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef baseconfig_H
#define baseconfig_H
#include "util.h"
#include "utilstrencodings.h"
#include <vector>
#include <boost/assign/list_of.hpp>
#include "uint256.h"


using namespace std;
using namespace boost::assign;


//static const int MAX_MONEY_Define = 800000000;//总股本
//static const char* pszTimestamp_Define = "The Times 20/May/2016 Chancellor on brink of second bailout for banks";//创世块
//static const uint32_t nTime_Define = 1463699616;//创世块时间
//static const uint32_t nBits_Define = 0x1f00ffff;//难易度
//static const uint32_t nNonce_Define = 2083237070;//种子
//创世块
//static const uint256 hashGenesisBlock_Define = uint256("0xd4a7db3e2acbb1bed534112451a10899ef08045f07394ea761efc5f8bfc112a9");
//创世块
//static const uint256 hashMerkleRoot_Define = uint256("0x8364246efad6c74ccde79bc58d29f1695d46d036ee14790f2f147b4a4234dc3f");
//公钥
//static const std::vector<unsigned char> vAlertPubKey_Define = ParseHex("0436060fe571dafa52d7f066f683dedcc543aa44554a0b5e51877b3465cfc54b470a499ebefae2350a4996accad2837f3a3d6932d3ed9319c5240254c3eb5d8c07");
//前缀
//static const boost::assign_detail::generic_list<int>  Prefixes_PUBKEY_ADDRESS = list_of(25);//B
//static const boost::assign_detail::generic_list<int>  Prefixes_SCRIPT_ADDRESS = list_of(85);//b
//static const boost::assign_detail::generic_list<int>  Prefixes_SECRET_KEY = list_of(176);
//static const boost::assign_detail::generic_list<int>  Prefixes_EXT_PUBLIC_KEY = list_of(0x04)(0x88)(0xB2)(0x1E);
//static const boost::assign_detail::generic_list<int>  Prefixes_EXT_SECRET_KEY = list_of(0x04)(0x88)(0xAD)(0xE4);
//static const int COINBASE_MATURITY_Define = 100 ; //挖矿奖励的成熟时间
//static const int RecommendedNumConfirmations_Define = 6;//交易确认块数推荐值
//服务器
//static void InitvSeed(std::vector<CDNSSeedData> *vSeeds)
//{
//	vSeeds->push_back(CDNSSeedData("216.218.193.2", "216.218.193.2"));
//	/*vSeeds.push_back(CDNSSeedData("n1.bfccoin.org", "n1.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n2.bfccoin.org", "n2.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n3.bfccoin.org", "n3.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n4.bfccoin.org", "n4.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n5.bfccoin.org", "n5.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n6.bfccoin.org", "n6.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n7.bfccoin.org", "n7.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n8.bfccoin.org", "n8.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n9.bfccoin.org", "n9.bfccoin.org"));
//	vSeeds.push_back(CDNSSeedData("n10.bfccoin.org", "n10.bfccoin.org"));*/
//}
#endif