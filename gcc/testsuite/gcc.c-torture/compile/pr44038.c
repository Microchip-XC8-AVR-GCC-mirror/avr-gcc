#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

struct Ustr {
    char data[1]; 
};
int ustr_xi__embed_val_get(__CONST char *);
inline static int ustr_len(__CONST struct Ustr *s1)
{
  return ustr_xi__embed_val_get(s1->data);
}
static __CONST struct Ustr *s1 = ((__CONST struct Ustr *) "");
int tst(char *cstr)
{
  return ustr_len(s1);
}
