#ifndef RECORD_H
#define RECORD_H

#define RECORD_SIZE sizeof(Record)


typedef enum Record_Attribute {
  ID,
  NAME,
  SURNAME,
  CITY
} Record_Attribute;

typedef struct Record {
	int id;
	char name[15];
	char surname[20];
	char city[20];
} Record;

Record randomRecord();

void printRecord(Record record);

#endif
