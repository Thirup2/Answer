#ifndef Status_H_
#define Status_H_

enum status
{
    SUCCESS,
    ISFULL,
    ISEMPTY,
    WRONGPOS,
    NOVALUE,
    OVERFLOW,
    ISIN
};
typedef enum status Status;

#endif