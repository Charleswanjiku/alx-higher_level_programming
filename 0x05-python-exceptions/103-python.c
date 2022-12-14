#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - print some basic info about Python bytes objects
 * @p: python object
 * Return: nothing
 */

void print_python_bytes(PyObject *p)
{
	char *s;
	Py_ssize_t len, i;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
		printf("  [ERROR] Invalid Bytes Object\n");
	else
	{
		len = ((PyVarObject *)p)->ob_size;
		printf("  size: %lu\n", len);
		s = ((PyBytesObject *)p)->ob_sval;
		printf("  trying string: %s\n", s);
		if (len > 10)
			len = 10;
		else
			len++;
		printf("  first %lu bytes: ", len);
		for (i = 0; i < len - 1; i++)
			printf("%02x ", s[i] & 0xff);
		printf("%02x\n", s[len - 1] & 0xff);
	}
}

void print_python_float(PyObject *p)
{
	printf("[.] float object info\n");
	if (!PyFloat_Check(p))
		printf("  [ERROR] Invalid Float Object\n");
	else
		printf("  value: %f\n", ((PyFloatObject *)p)->ob_fval);
}

/**
 * print_python_list - print some basic info about Python lists
 * @p: python object
 * Return: nothing
 */

void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *in_list;

	printf("[*] Python list info\n");
	if (!PyList_Check(p))
		printf("  [ERROR] Invalid List Object\n");
	else
	{
		size = ((PyVarObject *)p)->ob_size;
		printf("[*] Size of the Python List = %lu\n", size);
		printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
		for (i = 0; i < size; i++)
		{
			in_list = ((PyListObject *)p)->ob_item[i];
			printf("Element %lu: %s\n", i,
					in_list->ob_type->tp_name);
			if (strcmp(in_list->ob_type->tp_name, "bytes") == 0)
				print_python_bytes(in_list);
			else if (strcmp(in_list->ob_type->tp_name,
						"float") == 0)
				print_python_float(in_list);
		}
	}
}
