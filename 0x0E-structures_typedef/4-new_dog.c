#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - gets length of string
 * @str: string
 * Return: length
 */
int _strlen(char *str)
{
	int i;

	while (*str++)
		i++;

	return (i);
}

/**
 * _strcpy - copies the string pointed to by src, plus terminating null byte
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * new_dog - create new instance of struct dog
 * @name: member
 * @age: member
 * @owner: member
 * Return: initialized instance of struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *cpy_name;
	char *cpy_owner;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->age = age;

	if (name != NULL)
	{
		cpy_name = malloc(_strlen(name) + 1);
		if (cpy_name == NULL)
		{
			free(dog);
			return (NULL);
		}
		dog->name = _strcpy(cpy_name, name);
	}
	else
		dog->name = NULL;

	if (owner != NULL)
	{
		cpy_owner = malloc(_strlen(owner) + 1);
		if (cpy_owner == NULL)
		{
			free(cpy_name);
			free(dog);
			return (NULL);
		}
		dog->owner = _strcpy(cpy_owner, owner);
	}
	else
		dog->owner = NULL;

	return (dog);
}

