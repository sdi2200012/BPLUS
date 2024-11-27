#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"
#include "bp_file.h"
#include "record.h"
#include <bp_datanode.h>
#include <bp_indexnode.h>
#include <stdbool.h>

#define CALL_BF(call)         \
  {                           \
    BF_ErrorCode code = call; \
    if (code != BF_OK)        \
    {                         \
      BF_PrintError(code);    \
      return BF_ERROR;     \
    }                         \
  }




int BP_CreateFile(char *fileName){
  //Initialize the block 0 with metadata
  CALL_BF(BF_CreateFile(fileName));
  int file_desc;
  CALL_BF(BF_OpenFile(fileName, &file_desc));
  BF_Block* block;
  BF_Block_Init(&block);
  CALL_BF(BF_AllocateBlock(file_desc, block));
  void* data;
  data = BF_Block_GetData(block);
  BPLUS_INFO* bplusinfo;
  bplusinfo = data;
  bplusinfo->IsBplus = true;
  bplusinfo->nodes_count = 1;
  bplusinfo->height = 0;
  BF_Block_SetDirty(block);
  BF_UnpinBlock(block);
  BF_Block_Destroy(&block);

  //Initialize root node of the B+ tree
  BF_Block_Init(&block);
  CALL_BF(BF_AllocateBlock(file_desc, block));
  bplusinfo->root = malloc(sizeof(BPLUS_INDEX_NODE));
  bplusinfo->root = data;
  for (int i=0 ; i<3; i++){
    bplusinfo->root->child[i] = NULL;
  }
  for (int i=0; i < RECORDS_PER_BLOCK; i++){
    bplusinfo->root->key[i] = 0;
  }
  BF_Block_SetDirty(block);
  BF_UnpinBlock(block);
  BF_Block_Destroy(&block);
  CALL_BF(BF_CloseFile(file_desc));
  return 0;
}


BPLUS_INFO* BP_OpenFile(char *fileName, int *file_desc)
{
  return 0;
}

int BP_CloseFile(int file_desc,BPLUS_INFO* info)
{  
  return 0;
}

int BP_InsertEntry(int file_desc,BPLUS_INFO *bplus_info, Record record)
{ 
  return 0;
}

int BP_GetEntry(int file_desc,BPLUS_INFO *bplus_info, int value,Record** record)
{  
  *record=NULL;
  return 0;
}

