#include "prototype.h"
 
void read_memory (uint32_t address) {};

void write_memory (uint32_t address, char value) {};

void handle_page_fault (uint32_t page_number) {};

void evict_page () {};

void load_page_from_disk (uint32_t disk_page_number) {};

void swap (uint32_t page_number_in, uint16_t page_number_out) {};

void get_offset () {};