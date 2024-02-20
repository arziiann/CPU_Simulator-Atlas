#ifndef PROTOTYPE_H
#define PROTOTYPE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define RAM_SIZE 64
#define PAGE_SIZE 4
#define HDD_SIZE 1024
#define CELL_SIZE 8

typedef struct {
    unsigned char vpn;
    unsigned char ppn;

    bool valid;
    bool dirty; //dirty bit indicating whether the page has been modified
}PageTableEntry;


unsigned char ram[RAM_SIZE];
unsigned char hdd[HDD_SIZE];


void read_memory(uint32_t address); //mmu
void write_memory (uint32_t address, char value); //mmu
void handle_page_fault (uint32_t page_number); //mmu
void evict_page (); //select page to evict, argument ?? 
void load_page_from_disk(uint32_t diak_page_number); //mc
void swap(uint32_t page_number_in, uint32_t page_number_out);
void get_offset(uint32_t address); //mmu 

//update













#endif //PROTOTYPE_H
