#ifndef __ARGON2HASH_H_
#define __ARGON2HASH_H_
using namespace std;

#include <argon2.h>

#define HASHLEN 32
#define SALTLEN 16

uint8_t *randomString(int len);
string getArgon2Hash(string password, uint8_t *salt);
bool verifyArgon2Hash(string password, string hash, uint8_t *salt);

string getArgon2Hash(string password, uint8_t *salt)
{
    // I used code from https://github.com/p-h-c/phc-winner-argon2
    uint8_t hash[HASHLEN];

    uint8_t *pwd = (uint8_t *)strdup(password.c_str());
    uint32_t pwdlen = strlen((char *)pwd);

    uint32_t t_cost = 2;         // 2-pass computation
    uint32_t m_cost = (1 << 16); // 64 mebibytes memory usage
    uint32_t parallelism = 1;    // number of threads and lanes

    // high-level API
    argon2i_hash_raw(t_cost, m_cost, parallelism, pwd, pwdlen, salt, SALTLEN, hash, HASHLEN);

    string hashStr = "";
    for (int i = 0; i < HASHLEN; ++i)
        hashStr += hash[i];

    return hashStr;
}

bool verifyArgon2Hash(string password, string hash, uint8_t *salt)
{
    // I used code from https://github.com/p-h-c/phc-winner-argon2

    uint8_t hash1[HASHLEN];

    uint8_t *pwd = (uint8_t *)strdup(password.c_str());
    uint32_t pwdlen = strlen((char *)pwd);

    uint32_t t_cost = 2;         // 2-pass computation
    uint32_t m_cost = (1 << 16); // 64 mebibytes memory usage
    uint32_t parallelism = 1;    // number of threads and lanes

    // high-level API
    argon2i_hash_raw(t_cost, m_cost, parallelism, pwd, pwdlen, salt, SALTLEN, hash1, HASHLEN);

    if (memcmp(hash1, hash.c_str(), HASHLEN))
        return false;
    else
        return true;
}

uint8_t *randomString(int len)
{
    srand(time(NULL));
    uint8_t *str = new uint8_t[len];
    for (int i = 0; i < len; ++i)
        str[i] = rand() % 256;

    return str;
}

#endif