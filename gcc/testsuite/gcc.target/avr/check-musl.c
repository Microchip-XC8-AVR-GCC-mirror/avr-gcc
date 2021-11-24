int main ()
{
  #ifndef __WITH_MUSL__
  #error "Macro __WITH_MUSL__ is not defined."
  #endif
  return 0;
}
