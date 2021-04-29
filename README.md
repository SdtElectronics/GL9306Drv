# GL9306Drv
User-space driver of GL9306 light-stream sensor for Linux.
## Usage
Initialize an instance with the path to the serial connected to the sensor, e.g. `/dev/ttyS7`
```
lightSS sss("/dev/ttyS7");
```
Retrieve a frame excluding the head i.e. start from `Delta_XL`
```
const unsigned char* begin = sss.getFrame();
```
Print a frame excluding the head and tail i.e. from `Delta_XL` to `SQUAL`
```
for(size_t d = 0; d != 7; ++d){
    printf("%02X", begin[d]);
}
printf("\n");
```
Retrieve the SQUAL field in a frame
```
unsigned int SQUAL = sss.getSQUAL();
```