#include <stdint.h>

uint16_t	rev_uint16(uint16_t n)
{
	return (((n >> 8) & 0xff) | ((n & 0xff) << 8));
}
