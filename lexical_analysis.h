#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//存放界符的hash表
static char limit_hash[128] = {0};

//关键字表
static const char* keywordarr[20] = {"char","float","double","int","long","signed","unsigned","for","while","do","goto","break","continue","const","volatile","register","auto"}; 

enum Status
{
    key,
    ident
};
enum Status sta;

void create_limit_hash();
int limit_symbol(char ch);
int operator_symbol(char** p,char** psto,size_t* index,char storage[]);
int IsNumber(char* p);
int IsAllNumberBeforeLimitSymbol(char* p);
void number_symbol(char** p,char** psto,size_t* index,char storage[]);
int IsAlphabet(char* ch);
void identifier_symbol(char** p,char** psto,size_t* index,char storage[]);
void IdentifierOrKeyword(char* p);
void keyword_symbol(char** p,char** psto,size_t* index,char storage[]);
void analysis(char* str);


