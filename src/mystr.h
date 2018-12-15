//
// A simpler string library for silly educational purposes
//

#include <string.h>

struct mystr
{
    char *Data;
    size_t Length;

    ~mystr()
    {
        if (Data) free(Data);
    }
};

mystr AllocateString(size_t Length)
{
    char *Data = (char *)malloc(Length);
    mystr Result = {Data, Length};
    return Result;
}

mystr MakeString(char *Data)
{
    size_t Length = strlen(Data);
    char *DataCopy = (char *)malloc(Length);
    memcpy(DataCopy, Data, Length);
    return mystr{DataCopy, Length};
}

char *GetCString(mystr String)
{
    char *result = (char *)malloc(String.Length + 1);
    memcpy(result, String.Data, String.Length);
    result[String.Length] = 0;
    return result;
}

mystr AppendByteToCopyOfString(char Byte, mystr String)
{
    mystr Result = {};
    Result.Length = String.Length + 1;
    Result.Data = (char *)malloc(Result.Length);
    memcpy(Result.Data, String.Data, String.Length);
    Result.Data[String.Length] = Byte;
    return Result;
}
