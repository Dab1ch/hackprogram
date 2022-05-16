from numba import njit, prange
from time import perf_counter


@njit(fastmath=True)
def razr(code, allowed, i):
    for n in range(1, len(code)+1):
        code = code[:len(code)-n] + allowed[i//len(allowed)**(n-1)%len(allowed)] + code[len(code)-n+1:]
    return code

@njit(fastmath=True)
def ruing(allowed, password):
    number = len(allowed)**len(password)
    code = allowed[0]*len(password)
    for i in range(number):
        code = razr(code, allowed, i)
        print(code)
        if code == password:
            break
    return code

if __name__ == '__main__':
    allowed = input('Введите разрешенные символы:')
    password = input('password:')
    start = perf_counter()
    code = ruing(allowed, password)
    end = perf_counter()
    print(code, end-start)
                
