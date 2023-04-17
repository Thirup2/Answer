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
    REPEAT
};
typedef enum status Status;

#endif