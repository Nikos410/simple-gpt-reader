# simple-gpt-reader

A simple command-line utility to read information from gpt partitioned disks on linux.

## How to use:

1. Download a recent version from [releases](https://github.com/Nikos410/simple-gpt-reader/releases) or build from source.
2. Make it executable: `chmod 555 simple-gpt-reader`
3. Run it and specify the device, for example to read partition information from `/dev/sdb` run: `./simple-gpt-reader /dev/sdb`
 
If you can't open the device you might not have permissions to access the block device.
In that case try running the command as `sudo`.
 