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
	 * copy_dest holds the address of dest, not its value.
	 * When dest (or src) is passed as an argument to the function,
	 * it is implicitly converted to a void* type,
	 * which is a generic pointer
	 *type that can hold the address of any data type.
	 */
	char *copy_dest = (char *)dest;
	char *copy_src = (char *)src;
	/*
	 * By casting dest to char* and assigning it to copy_dest,
	 * we create a new pointer copy_dest
	 * that points to the same address as dest.
	 * This allows us to treat the memory
	 * at that address as a sequence of characters
	 * (char type) and perform byte-wise operations
	 * so copy_dest a pointer variable
	 * that holds the memory address of dest and
	 *copy_dest refers to the value stored at that address.
	 */

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
		copy_dest[i] = copy_src[i];
	/* copy_dest[i] = copy_src[i] <==> *(copy_dest + i) = *(copy_src + i); */
	return (dest);
}


/**
 * _realloc - reallocates a block of memory
 *
 * @ptr: pointer to malloc'ated block
 * @old_size: byte size of current block
 * @new_size: byte size of new block
 *
 * Return: pointer to the new memory block.
 */

void *_realloc(char *ptr, size_t old_size, size_t new_size)
{
	char *copy_ptr = (char *)ptr;
	char *temp = NULL;
	int size = 0;

	if (ptr == NULL)
		return ((char *)malloc(new_size));
	else if (new_size == old_size)
		return (ptr);
	else if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		/* create temporary storage */
		temp = (char *)malloc(new_size);
		if (temp == NULL)
			return (NULL);
		/* copy n bytes from ptr = copy_ptr into temp */
		size = old_size > new_size ? old_size : new_size;
		_memcpy(temp, copy_ptr, size);
		/* free pointer */
		free(ptr);
		copy_ptr = NULL, ptr = NULL;
		/* return the new pointer with the new size */
		return (temp);
	}
}
