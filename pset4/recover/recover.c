#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check for incorrect usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // try to open file for reading
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Could not open the specified file\n");
        return 1;
    }

    // create buffer
    BYTE *buffer = malloc(sizeof(BYTE) * 512);

    // declare variables
    FILE *nfile = NULL;
    char *filename = malloc(sizeof(char) * 7);
    int recovered = 0;
    int found = 0;


    while (1)
    {
        int read = fread(buffer, 1, 512, file);
        // look for end of file
        if (read < 512)
        {
            fclose(file);
            fclose(nfile);
            break;
        }

        // look for beginning of a jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // if its the first jpg found, create a new file
            if (!found)
            {
                found = 1;
                sprintf(filename, "%03i.jpg", recovered);
                nfile = fopen(filename, "w");

                // check for error opening file
                if (nfile == NULL)
                {
                    printf("Could not create a new file\n");
                    return 1;
                }

                // write buffer to file
                fwrite(buffer, 1, 512, nfile);
            }
            // if not, close the current file, and then create another one
            else
            {
                fclose(nfile);
                recovered++;
                sprintf(filename, "%03i.jpg", recovered);
                nfile = fopen(filename, "w");
                fwrite(buffer, 1, 512, nfile);
            }
        }

        else
        {
            if (found)
            {
                fwrite(buffer, 1, 512, nfile);
            }
        }

    }

    fclose(file);
    fclose(nfile);
}
