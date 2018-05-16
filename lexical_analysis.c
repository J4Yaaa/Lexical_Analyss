#include "lexical_analysis.h"

//界符：左右中括号(‘[‘ 、‘]’) ,左右小括号（‘(‘、’)’), 分号（’;’),　空格(‘   ‘)，逗号（‘,’), 大括号(‘{‘、’}’), 双引号（‘ “ ’），井号（‘#’）。   
//运算符：＋，－， *,  /,  +=, ++， --，  *=,  -=,  /=, ==, &, &&, |, ||,~
//数字：所有数字组成的集合。
//标识符：以下划线或数字为开头，其余由数字，下划线，字母任意组成的集合。
//关键字：c语言本身定义的常用关键字集合。包括（int, long, float, double, short等等）。


//构建界符哈希表
void create_limit_hash()
{
    //构建一个界符的哈希表
    char limit[30] = {'[',']','(',')',';',' ',',','{','}','#','"','.'};
    size_t offset = 0;//计算当前符号对应的下标
    size_t i = 0;
    for(; i<30; ++i)
    {
        offset = limit[i];
        limit_hash[offset] = limit[i];
    }
}

//查找界符
int limit_symbol(char ch)
{
    size_t offset = ch;
    if(limit_hash[offset] == ch)
    {
        return 1;
    }
    return 0;
}

//查找运算符
int operator_symbol(char** p,char** psto,size_t* index,char storage[])
{
    if(**p == '+')
    {
        storage[(*index)++] = **p;
        ++(*p);
        if(**p == '+' || **p == '=')
        {//出现+=,或者++的情况
            storage[(*index)++] = **p;
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 3;
            ++(*p);
            return 1;
        }
        else
        {//单纯的+
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 2;
            return 1;
        }
    }
    else if(**p == '-')
    {
        storage[(*index)++] = **p;
        ++(*p);
        if(**p == '-' || **p == '=')
        {//出现-=,或者--的情况
            storage[(*index)++] = **p;
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 3;
            ++(*p);
            return 1;
        }
        else
        {//单纯的-
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 2;
            return 1;
        }
    }
    else if(**p == '*')
    {
        storage[(*index)++] = **p;
        ++(*p);
        if(**p == '*' || **p == '=')
        {
            storage[(*index)++] = **p;
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 3;
            ++(*p);
            return 1;
        }
        else
        {
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 2;
            return 1;
        }
    }
    else if(**p == '/')
    {
        storage[(*index)++] = **p;
        ++(*p);
        if(**p == '/' || **p == '=')
        {
            storage[(*index)++] = **p;
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 3;
            ++(*p);
            return 1;
        }
        else
        {
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 2;
            return 1;
        }
    }
    else if(**p == '&')
    {
        storage[(*index)++] = **p;
        ++(*p);
        if(**p == '&' || **p == '=')
        {
            storage[(*index)++] = **p;
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 3;
            ++(*p);
            return 1;
        }
        else
        {
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 2;
            return 1;
        }
    }
    else if(**p == '|')
    {
        storage[(*index)++] = **p;
        ++(*p);
        if(**p == '|' || **p == '=')
        {
            storage[(*index)++] = **p;
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 3;
            ++(*p);
            return 1;
        }
        else
        {
            storage[(*index)++] = '\0';
            printf("%s  运算符\n",*psto);
            *psto += 2;
            return 1;
        }
    }
    else if(**p == '~')
    {
        storage[(*index)++] = **p;
        storage[(*index)++] = '\0';
        printf("%s  运算符\n",*psto);
        *psto += 2;
        ++(*p);
        return 1;
    }
    else if(**p == '=')
    {
        storage[(*index)++] = **p;
        storage[(*index)++] = '\0';
        printf("%s  运算符\n",*psto);
        *psto += 2;
        ++(*p);
        return 1;
    }
    else if(**p == '>')
    {
        storage[(*index)++] = **p;
        storage[(*index)++] = '\0';
        printf("%s  运算符\n",*psto);
        *psto += 2;
        ++(*p);
        return 1;
    }
    else if(**p == '<')
    {
        storage[(*index)++] = **p;
        storage[(*index)++] = '\0';
        printf("%s  运算符\n",*psto);
        *psto += 2;
        ++(*p);
        return 1;
    }
    return 0;
}

int IsOperator(char* p)
{
    if(*p == '+' || *p == '-' || *p == '*' || *p == '/'
       || *p == '=' || *p == '&' || *p == '|' || *p == '~'
       || *p == '>' || *p == '<')
        return 1;
    return 0;
}

int IsNumber(char* p)
{
    if(*p < '9' && *p >= '0')
        return 1;
    return 0;
}

//判断一个是数字还是标识符
int IsAllNumberBeforeLimitSymbol(char* p)
{
    while(IsNumber(p))
    {
        ++p;
    }
    if(limit_symbol(*p) || *p == '+' || *p == '-' || *p == '*' || *p == '/')
    {
        return 1;
    }
    return 0;
}

void number_symbol(char** p,char** psto,size_t* index,char storage[])
{
    size_t count = 0;
    while(limit_symbol(**p) == 0)
    {
        storage[(*index)++] = **p;
        ++count;
        ++(*p);
    }
    storage[(*index)++] = '\0';
    printf("%s  数字\n",*psto);
    (*psto) += (count+1);
}

int IsAlphabet(char* ch)
{
    if((*ch <= 'Z' && *ch >= 'A') ||
       (*ch <= 'z' && *ch >= 'a'))
    {
        return 1;
    }
    return 0;
}

void identifier_symbol(char** p,char** psto,size_t* index,char storage[])
{
    size_t count = 0;
    while(!limit_symbol(**p) && !IsOperator(*p))
    {
        storage[(*index)++] = **p;
        ++count;
        ++(*p);
    }
    storage[(*index)++] = '\0';
    printf("%s  标识符\n",*psto);
    (*psto) += (count+1);
}

//判断是标识符还是关键字
void IdentifierOrKeyword(char* p)
{
    char* str = p;
    while(!limit_symbol(*str) && !IsOperator(str))
    {
        if(IsAlphabet(str) || *str == '_')
        {
            ++str;
        }
        else if(!limit_symbol(*str) && !IsOperator(str))
        {
            printf("输入有误\n");
            exit(1);
        }
    }
    size_t size = str - p;
    char* buf = (char*)malloc(sizeof(char)*(size+1));
    memcpy(buf,p,size);
    buf[size] = '\0';
    size_t keyword_size = sizeof(keywordarr[0]);
    //判断buf是不是关键字
    size_t i = 0;
    for(;i < keyword_size;++i)
    {
        if(strcmp(buf,keywordarr[i]) == 0)
        {
            sta = key;
            return;
        }
    }
    sta = ident;
}

void keyword_symbol(char** p,char** psto,size_t* index,char storage[])
{
    size_t count = 0;
    while(limit_symbol(**p) == 0)
    {
        storage[(*index)++] = **p;
        ++count;
        ++(*p);
    }
    storage[(*index)++] = '\0';
    printf("%s  关键字\n",*psto);
    (*psto) += (count+1);
}
void analysis(char* str)
{
    char* p = str; //p表示当前分析到哪一个字符了
    char storage[128] = {0}; //存储每一次分析得到的字符;
    char* psto = storage;
    size_t index = 0;//表示存储到storage数组中的第几个元素了
    create_limit_hash();
    while(*p != '\0')
    {
        //1.判断是不是界符,是的话就存储到storage数组中,并且直接输出(因为界符都是单个字符)
        if(limit_symbol(*p) == 1)
        {
            storage[index++] = *p;
            storage[index++] = '\0';
            if(!isspace(*p))
            {
                printf("%s  界符\n",psto);
            }
            psto += 2;
            ++p;
            continue;
        }
        //2.判断是不是运算符
        //  a)对于单个存在的运算符(~),处理方式与界符一致
        //  b)对于有可能不是单个存在的运算符(+,+=),需要再次向后判断一个字符
        if(operator_symbol(&p,&psto,&index,storage) == 1)
        {
            continue;
        }

        //3.处理数字
        //  a)如果单个/连续的纯数字后边出现了界符,就输出这是一个数字集合
        if(IsNumber(p) == 1)
        {
            //判断下一个界符前面是不是都是数字
            if(IsAllNumberBeforeLimitSymbol(p) == 1)
            {
                //处理这些数字
                number_symbol(&p,&psto,&index,storage);
                continue;
            }
        }

        //4.处理标识符/关键字
        //  a)以数字/字母/下划线开头
        //    ->如果碰到界符,就在关键字表中查找,如果没有找到,表示这是一个标识符,输出
        //    ->如果碰到界符,并且在关键字标中查找到关键字,就输出关键字标识
        //  b)不是数字/字母/下划线开头
        //    ->如果不是界符,表示输入错误,返回错误,退出
        if(*p == '_')
        {//如果以 _ 开头的一定是标识符
            identifier_symbol(&p,&psto,&index,storage);
            continue;
        }
        if(IsAlphabet(p) == 1)
        {
            IdentifierOrKeyword(p);
            if(sta == key)
            {
                keyword_symbol(&p,&psto,&index,storage);
                continue;
            }
            else if(sta == ident)
            {
                identifier_symbol(&p,&psto,&index,storage);
                continue;
            }
        }
        continue;
    }
}
