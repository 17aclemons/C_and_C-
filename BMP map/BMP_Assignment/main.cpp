/*
Andrew Clemons
C and C++
BMP Map
*/

/*Create a Color bmp to B/W bmp file converter. Your code has to be 100% original and it should not use any pre-made image libraries. I expect you to do the conversion yourself. The bmp file format and color conversion will be discussed in class. 

Your application should: 

Check the first two bytes to confirm it is a valid bmp file. 10 pts
Extract and print the file size. Print an error if the file size does not match the amount read. 10 pts
Create a new file name the same as the old file with BW_"conversion method" appended to the name. 10 pts
Your code should include a comment block and be well commented. 10 pts
As command line input accept 1 for conversion using the lightness method; 2 for using the average method, and 3 for using the lumonosity method. Follow that with the filename of the file to be converted. Make sure to do error checking. 10 pts
The new file should be in b/w instead of color converted using the selected method. 50 pts
Conversion Formulas:

Lightness method: (max(R,G,B) + min (R,G,B)) / 2
Average method: (R+G+B)/3
Luminosity method: .21 * R + .72 * G + .07 * B
BMP Map:

Bytes 0 - 1 File Signature 0x424D --> "BM"

Bytes 2 - 5 File Size (Little endian byte ordering)

Bytes 10 - 13 Starting offset, of pixel array (Little endian byte ordering) BGRA values stored as a xy grid*/