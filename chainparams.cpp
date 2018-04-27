// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "consensus/merkle.h"
#include "pow.h"
#include "arith_uint256.h"
#include "tinyformat.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>
#include "base58.h"
#include "chainparamsseeds.h"
#include <script/standard.h>

static CBlock CreateGenesisBlock(const char* pszTimestamp, const CScript& genesisOutputScript, uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    CMutableTransaction txNew;
    txNew.nVersion = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
	txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << std::vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = genesisReward;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nTime    = nTime;
    genesis.nBits    = nBits;
    genesis.nNonce   = nNonce;
    genesis.nVersion = nVersion;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

/**
 * Build the genesis block. Note that the output of its generation
 * transaction cannot be spent since it did not originally exist in the
 * database.
 *
 * CBlock(hash=000000000019d6, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=4a5e1e, nTime=1231006505, nBits=1d00ffff, nNonce=2083236893, vtx=1)
 *   CTransaction(hash=4a5e1e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
 *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73)
 *     CTxOut(nValue=50.00000000, scriptPubKey=0x5F1DF16B2B704C8A578D0B)
 *   vMerkleTree: 4a5e1e
 */
static CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, int32_t nVersion, const CAmount& genesisReward)
{
    const char* pszTimestamp = "The Times 2018-04-25 Chancellor on brink of second bailout for banks";
    const CScript genesisOutputScript = CScript() << ParseHex("047aff483d8800aab53551e4512324f51ee9e0f9dd4d2b1658facf27457a89eecf44585596278139cd07dc222b41d506d3cf51727bcea32e717306006a7f00cc56") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, nTime, nNonce, nBits, nVersion, genesisReward);
}

/**
 * Main network
 */
/**
 * What makes a good checkpoint block
 * + Is surrounded by blocks with reasonable timestamps
 *   (no blocks before with a timestamp after, none after with
 *    timestamp before)
 * + Contains no strange transactions
 */

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 31250;
        consensus.nMajorityEnforceBlockUpgrade = 750;
        consensus.nMajorityRejectBlockOutdated = 950;
        consensus.nMajorityWindow = 1000;
        consensus.BIP34Height = 227931;
        consensus.BIP34Hash = uint256S("0x000000000000024b89b42a942fe0d9fea3bb44ab7bd1b19115dd6a759c0808b8");
		//�Ѷ�ϵ��  
		consensus.powLimit = uint256S("000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
		consensus.nPowTargetTimespan = 24 * 60; 
		consensus.nPowTargetSpacing = 1 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.fPowNoRetargeting = false;

		/*const arith_uint256 bnPowLimit = UintToArith256(consensus.powLimit);
		uint32_t nbits =  bnPowLimit.GetCompact();*/
        /** 
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 32-bit integer with any alignment.
         */
		pchMessageStart[0] = 0x51;
		pchMessageStart[1] = 0x47;
		pchMessageStart[2] = 0x36;
		pchMessageStart[3] = 0x18;
        vAlertPubKey = ParseHex("047aff483d8800aab53551e4512324f51ee9e0f9dd4d2b1658facf27457a89eecf44585596278139cd07dc222b41d506d3cf51727bcea32e717306006a7f00cc56");
		nDefaultPort = 8333;
        nMaxTipAge = 24 * 60 * 60;
        nPruneAfterHeight = 1000; //100000

		genesis = CreateGenesisBlock(1524639796,  7311811, 0x1E00FFFF, 1, 1 * COIN);
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x00000050451fcb1ac7e2c74400445a1f8d807d7f9a38db5b0e3fe88452799957"));
        assert(genesis.hashMerkleRoot == uint256S("0x1990b7801407c7e4c910e17b4663378a877d202a05233dcde68ef77716fbed28"));

		vSeeds.push_back(CDNSSeedData("13.211.213.215", "13.211.213.215"));

		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 63);//T
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 30);//U
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 33);//V
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_main, pnSeed6_main + ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CChainParams {
public:
    CTestNetParams() {
  //      strNetworkID = "test";
		//consensus.nSubsidyHalvingInterval = 31250;
  //      consensus.nMajorityEnforceBlockUpgrade = 51;
  //      consensus.nMajorityRejectBlockOutdated = 75;
  //      consensus.nMajorityWindow = 100;
  //      consensus.BIP34Height = 21111;
  //      consensus.BIP34Hash = uint256S("0x0000000023b3a96d3484e5abb3755c413e7d41500f8e2a5c3f0dd01299cd8ef8");
  //      consensus.powLimit = uint256S("000000ffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
		//consensus.nPowTargetTimespan = 24 * 60; // two weeks
  //      consensus.nPowTargetSpacing = 1 * 60;
  //      consensus.fPowAllowMinDifficultyBlocks = true;
  //      consensus.fPowNoRetargeting = false;
  //      pchMessageStart[0] = 0x0b;
  //      pchMessageStart[1] = 0x11;
  //      pchMessageStart[2] = 0x09;
  //      pchMessageStart[3] = 0x07;
  //      vAlertPubKey = ParseHex("047aff483d8800aab53551e4512324f51ee9e0f9dd4d2b1658facf27457a89eecf44585596278139cd07dc222b41d506d3cf51727bcea32e717306006a7f00cc56");
		//nDefaultPort = 22111;
  //      nMaxTipAge = 0x7fffffff;
  //      nPruneAfterHeight = 1000;

		//genesis = CreateGenesisBlock(1460909705, 2121936627, 0x1E00FFFF, 1, 50 * COIN);
  //      consensus.hashGenesisBlock = genesis.GetHash();
  //      assert(consensus.hashGenesisBlock == uint256S("0x0000004a8eb8ea749f03b8256a202eff31c961aa5dc12819dafb281a7f32dcbe"));
  //      assert(genesis.hashMerkleRoot == uint256S("0x9669872ce8abe00a3446062063a99c05a2673581cf85e6cb944215aa64a55fb4"));

  //      vFixedSeeds.clear();
  //      vSeeds.clear();

		//base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 28);//T
		//base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 30);//U
		//base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 33);//V
		//base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
		//base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

  //      vFixedSeeds = std::vector<SeedSpec6>(pnSeed6_test, pnSeed6_test + ARRAYLEN(pnSeed6_test));

  //      fMiningRequiresPeers = true;
  //      fDefaultConsistencyChecks = false;
  //      fRequireStandard = false;
  //      fMineBlocksOnDemand = false;
  //      fTestnetToBeDeprecatedFieldRPC = true;

        /*checkpointData =  {
            boost::assign::map_list_of
            ( 546, uint256S("000000002a936ca763904c3c35fce2f3556c559c0214345d31b1bcebf76acb70")),
            1337966069,
            1488,
            300
        };*/

    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CChainParams {
public:
    CRegTestParams() {
        //strNetworkID = "regtest";
        //consensus.nSubsidyHalvingInterval = 150;
        //consensus.nMajorityEnforceBlockUpgrade = 750;
        //consensus.nMajorityRejectBlockOutdated = 950;
        //consensus.nMajorityWindow = 1000;
        //consensus.BIP34Height = -1; // BIP34 has not necessarily activated on regtest
        //consensus.BIP34Hash = uint256();
        //consensus.powLimit = uint256S("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        //consensus.nPowTargetTimespan = 14 * 24 * 60 * 60; // two weeks
        //consensus.nPowTargetSpacing = 10 * 60;
        //consensus.fPowAllowMinDifficultyBlocks = true;
        //consensus.fPowNoRetargeting = true;

        //pchMessageStart[0] = 0xfa;
        //pchMessageStart[1] = 0xbf;
        //pchMessageStart[2] = 0xb5;
        //pchMessageStart[3] = 0xda;
        //nMaxTipAge = 24 * 60 * 60;
        //nDefaultPort = 18444;
        //nPruneAfterHeight = 1000;

        //genesis = CreateGenesisBlock(1296688602, 2, 0x207fffff, 1, 50 * COIN);
        //consensus.hashGenesisBlock = genesis.GetHash();
        //assert(consensus.hashGenesisBlock == uint256S("0x0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206"));
        //assert(genesis.hashMerkleRoot == uint256S("0x4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b"));

        //vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        //vSeeds.clear();  //! Regtest mode doesn't have any DNS seeds.

        //fMiningRequiresPeers = false;
        //fDefaultConsistencyChecks = true;
        //fRequireStandard = false;
        //fMineBlocksOnDemand = true;
        //fTestnetToBeDeprecatedFieldRPC = false;

        ///*checkpointData = {
        //    boost::assign::map_list_of
        //    ( 0, uint256S("0f9188f13cb7b2c71f2a335e3a4fc328bf5beb436012afca590b1a11466e2206")),
        //    0,
        //    0,
        //    0
        //};*/
        //base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        //base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        //base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,239);
        //base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        //base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
    }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = 0;

const CChainParams &Params() {
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
            return mainParams;
    else if (chain == CBaseChainParams::TESTNET)
            return testNetParams;
    else if (chain == CBaseChainParams::REGTEST)
            return regTestParams;
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectParams(const std::string& network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
