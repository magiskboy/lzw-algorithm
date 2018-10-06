struct lzw_table_entry{
	unsigned char base_code;
	unsigned char character;
};

#define GETCHAR(x) fread(&(x), sizeof(unsigned char), 1, inputfd)

#define PUTCHAR(x) fwrite(&(x), sizeof(unsigned char), 1, outputfd)
