*This project has been created as part of the 42 curriculum by sekartav.*

# ft_printf

## Description

**ft_printf**, C dilindeki standart `printf` fonksiyonunun yeniden yazılmış bir versiyonudur.

Bu projenin temel amacı:

- Variadic fonksiyonları (`stdarg.h`) öğrenmek
- Format string parsing mantığını kavramak
- Farklı veri tiplerini düşük seviyeli I/O kullanarak yazdırmak
- Sayı tabanı dönüşümlerini ve recursion tekniklerini uygulamak

`ft_printf`, 42 müfredatındaki sonraki projelerde kullanılacak temel bir yapı taşıdır ve formatlama, pointer kullanımı ve bellek kontrolü konularında pratik kazandırır.

---

## Supported Format Specifiers

| Specifier | Description |
|-----------|-------------|
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

## Instructions

### Requirements

- GCC or Clang
- make
- Unix-based system

### Compilation

```bash
make
```

### Cleaning object files

```bash
make clean
```

### Full clean

```bash
make fclean
```

### Rebuild

```bash
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

## Algorithm and Data Structure Explanation

### Overall Approach

`ft_printf` fonksiyonu, format string’i karakter karakter dolaşarak çalışır.

Algoritma şu adımlardan oluşur:

1. Format string baştan sona okunur.
2. Normal karakterle karşılaşılırsa doğrudan ekrana yazdırılır.
3. `%` karakteri görülürse:
   - Bir sonraki karakter okunur.
   - Bu karakter format belirteci olarak yorumlanır.
4. Belirtece göre uygun yazdırma fonksiyonu çağrılır.

Bu işlem string sonuna kadar devam eder.

---

### Variadic Argument Handling

Fonksiyon, değişken sayıda argüman almak için `stdarg.h` kullanır:

- `va_list` → argüman listesini tutar
- `va_start` → argüman listesini başlatır
- `va_arg` → sıradaki argümanı alır
- `va_end` → listeyi sonlandırır

Bu yapı sayesinde fonksiyon, her format belirteci için doğru veri tipini alıp yazdırabilir.

---

### Number Printing Strategy

Sayılar **recursive bölme yöntemi** ile yazdırılır.

Örnek: `1234` yazdırma süreci

```
1234 / 10 → 123
123 / 10 → 12
12 / 10 → 1
1 / 10 → 0
```

Sonrasında rakamlar geri dönüşte yazdırılır:

```
1 → 2 → 3 → 4
```

Bu yöntem:

- Ek bellek kullanmaz
- Stack üzerinde çalışır
- Daha sade ve okunabilir bir algoritma sağlar

---

### Hexadecimal Conversion

Hexadecimal dönüşümde:

1. Sayı 16’ya bölünür.
2. Kalan değer base string içinden alınır.

Örnek:

```
255 → 255 % 16 = 15 → 'f'
255 / 16 = 15
15 % 16 = 15 → 'f'
```

Sonuç:

```
ff
```

Bu işlem de recursive şekilde yapılır.

---

### Pointer Printing

Pointer adresleri:

- `unsigned long` tipine dönüştürülür
- Başına `0x` eklenir
- Hexadecimal olarak yazdırılır

---

## Resources

### Classic references

- `man 3 printf`
- The C Programming Language — Kernighan & Ritchie
- https://en.cppreference.com/w/c/io/fprintf
- Beej's Guide to C — https://beej.us/guide/bgc/

### 42 and community resources

- 42 ft_printf subject PDF
- 42 cursus GitBook
- Various 42 student repositories for comparison

---

## AI Usage

AI tools (ChatGPT, Grok, Claude) were used for:

- Understanding variadic function mechanics
- Planning format parsing logic
- Reviewing edge cases
- Improving code readability and structure

> No function was directly copied.  
> All implementations were written by me.  
> AI was used strictly as a learning and review assistant.

---

## Author

* sekartav - 42 Student
