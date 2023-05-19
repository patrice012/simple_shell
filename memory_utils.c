#include "header.h"


/**
 * _memcpy - function copies n bytes from memory area src to memory area dest.
 * @dest: destination
 * @src: source pointer
 * @n: number of bytes to copy
 * Return: None
 */


/*
 * Usage: _memcpy(ptr1, ptr2, 20) => copy 20 bytes of ptr2 into ptr1
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    /*
     * In the _memcpy function, copy_dest holds the address of dest,( copy_src for src)
     * not its value. When dest (or src) is passed as an argument to the function,
     * it is implicitly converted to a void* type, which is a generic pointer
     * type that can hold the address of any data type.
     */
    char *copy_dest = (char *)dest;
    char *copy_src = (char *)src;

    /*
     * By casting dest to char* and assigning it to copy_dest,
     * we create a new pointer copy_dest that points to the same address as dest.
     * This allows us to treat the memory at that address as a sequence of characters
     * (char type) and perform byte-wise operations
     *
     * so copy_dest a pointer variable that holds the memory address of dest and 
     * *copy_dest refers to the value stored at that address.
     */

    if (dest == NULL || src == NULL)
    {
        return (-1);
    }

    for (i = 0; i < n; i++)
        copy_dest[i] = copy_src[i];
    /* copy_dest[i] = copy_src[i] <==> *(copy_dest + i) = *(copy_src + i); */
}
