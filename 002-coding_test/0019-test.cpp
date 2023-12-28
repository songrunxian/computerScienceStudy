#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

//本题靓点：（1）二分查找 配合 （2）界点确认

long Triangle (long);
long Pentagonal (long);
long Hexagonal (long);
bool isSame( long (*f1) (long), long, long );

int main() {
        long n = 285;
        while (++n) {
                long tri = Triangle(n);
                long flag = isSame(Pentagonal, tri, n) & isSame(Hexagonal, tri, n);
                if ( flag ) {
                        printf("%ld\n", Triangle(n));
                        break;
                }
        }
        return 0;
}

long Triangle (long num) {
        return num*(num + 1) / 2;
}
long Pentagonal (long num) {
        return num*(3*num - 1) / 2;
}
long Hexagonal (long num) {
        return num*(2*num - 1);
}
bool isSame ( long (*f1) (long ), long re, long bd) {
        /*
        for(long i = 1; i <= bd; i++) {
                if (re == f1(i)) return true;
        }
        return false;*/
        long l = 1, r = bd, mid = (r+l) >> 1;
        while( l <= r ) {
                if(re == f1(mid)) return true;
                else if (re > f1(mid)) {
                        l = mid + 1;
                        mid = (r+l) >> 1;
                } else {
                        r = mid - 1;
                        mid = (r+l) >> 1;
                }
        }
        return false;
}
