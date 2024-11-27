#ifndef BP_INDEX_NODE_H
#define BP_INDEX_NODE_H
#include <record.h>
#include <bf.h>
#include <bp_file.h>
#include <bp_datanode.h>


typedef struct
{
    int key[RECORDS_PER_BLOCK];
    void* child[3];
} BPLUS_INDEX_NODE;

#endif