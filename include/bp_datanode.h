#ifndef BP_DATANODE_H
#define BP_DATANODE_H
#include <record.h>
#include <record.h>
#include <bf.h>
#include <bp_file.h>
#include <bp_indexnode.h>
typedef struct BPLUS_DATA_NODE BPLUS_DATA_NODE;

#define BPLUS_DATA_NODE_SIZE sizeof(BPLUS_DATA_NODE*)
#define RECORDS_PER_BLOCK (BF_BLOCK_SIZE - BPLUS_DATA_NODE_SIZE) / sizeof(Record)



struct BPLUS_DATA_NODE{
    Record records[RECORDS_PER_BLOCK];
    struct BPLUS_DATA_NODE* next_data_leaf;
};

#endif 