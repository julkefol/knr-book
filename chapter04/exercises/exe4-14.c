#define swap(t, a, b)   if (sizeof(a) == sizeof(b) && sizeof(t) == sizeof(a)) {\
                            t temp = a;\
                            a = b;\
                            b = temp;\
                        }\
