#pragma once
#ifdef MYLIB_EXPORTS    
#define MYLIBAPI extern "C" __declspec(dllexport)
#else
#define MYLIBAPI extern "C" __declspec(dllimport)
#endif

MYLIBAPI int add(int , int );
MYLIBAPI int sub(int , int );
MYLIBAPI int mul(int , int );
MYLIBAPI int divi(int , int );

