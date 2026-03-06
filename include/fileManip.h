#ifndef FILEMANIP_H
#define FILEMANIP_H

int makeFile(char const *fileName, char const *content);
int editFile(char const *fileName, char const *content);
int deleteFile(char const *fileName);

#endif /* FILEMANIP_H */