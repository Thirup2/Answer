#ifndef STATUS_H_
#define STATUS_H_

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