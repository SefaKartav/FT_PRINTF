*This project has been created as part of the 42 curriculum by sekartav.*
# ft_printf

## Description

**ft_printf**, C dilindeki standart `printf` fonksiyonunun yeniden yazılmış bir implementasyonudur.

Bu projenin amacı:

- Variadic fonksiyonları (`stdarg.h`) öğrenmek
- Format string parsing mantığını kavramak
- Farklı veri tiplerini düşük seviyeli I/O kullanarak yazdırmak
- Recursion ve sayı tabanı dönüşümlerini uygulamak

Bu proje, 42 müfredatındaki daha büyük projeler (get_next_line, pipex, minishell vb.) için temel oluşturur.

---

## Supported Format Specifiers

| Specifier | Description |
|------------|-------------|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer (hexadecimal) |
| `%d` | Signed decimal |
| `%i` | Signed decimal |
| `%u` | Unsigned decimal |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |

---

## Function Prototypes

```c
int ft_printf(const char *format, ...);

int ft_putchar(int a);
int ft_putstr(char *a);
int ft_putnbr(int n);
int ft_putnbrl(unsigned int n);

int ft_puthexb(unsigned int a, char *base);
int ft_puthexk(unsigned int a, char *base);
int ft_puthexl(unsigned long a);
int ft_puthexp(void *c);
```

---

## Project Structure

- **ft_printf.c**  
  Format string’i parse eder ve uygun yazdırma fonksiyonunu çağırır.

- **Character & String Output**
  - `ft_putchar`
  - `ft_putstr`

- **Decimal Output**
  - `ft_putnbr` (signed)
  - `ft_putnbrl` (unsigned)

- **Hexadecimal Output**
  - `ft_puthexb`
  - `ft_puthexk`
  - `ft_puthexl`
  - `ft_puthexp`

---

## Compilation

### Requirements

- GCC or Clang
- make
- Unix-based system

### Commands

```bash
make
make clean
make fclean
make re
```

---

## Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;
    char *str = "Hello";

    ft_printf("Number: %d\n", n);
    ft_printf("String: %s\n", str);
    ft_printf("Hex: %x\n", n);
    ft_printf("Pointer: %p\n", str);

    return (0);
}
```

---

## Concepts Practiced

- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)
- Format parsing
- Recursive number printing
- Base conversion (decimal → hexadecimal)
- Low-level output using `write`
- Memory-safe pointer handling

---

## AI Usage

AI tools (ChatGPT, Grok, Claude) were used for:

- Understanding variadic function mechanics
- Planning format parsing logic
- Reviewing edge cases
- Improving code structure and readability

> No function was directly copied.  
> All implementations were written by me.  
> AI was used strictly as a learning and review assistant.

---

## Author

* sekartav - 42 Student
