1. troubleshooting 1 - android avd cannot launch with unknown error "fire a bug against android studio"

This problem happens because my Macbook is running macos 11.7.10. Android studio always download the latest emulator launcher which is built on macos 12. this error does not have proper error on Android studio but an "unknown error".

The exact error was found while trying to launch avd from command line.
I used sdkmanager to download emulator, which is what Android studio do. It gets the latest version emulator. While launch AVD with the latest emulator, the following error observed.

yz@iMaple Downloads % ./emulator/emulator -avd Android12Emulator
dyld: Symbol not found: __ZTVNSt3__115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEEE
  Referenced from: /Users/yz/Downloads/emulator/lib64/libabseil_dll.dylib (which was built for Mac OS X 12.7)
  Expected in: /usr/lib/libc++.1.dylib
 in /Users/yz/Downloads/emulator/lib64/libabseil_dll.dylib
zsh: abort      ./emulator/emulator -avd Android12Emulator
yz@iMaple Downloads % 

To work this around, one has to download older version emulator from google's website. I got an emulator for Android 12. And launched AVD from command line without error.

download older version 
yz@iMaple emulator 2 % ./emulator -avd Android12Emulator
2. troubleshooting - aosp building failure, cannot mount a directory on ubuntu 24

E][2025-04-07T21:44:24-0400][1] initCloneNs():379 mount('/', '/', NULL, MS_REC|MS_PRIVATE, NULL): Pe
rmission denied
[F][2025-04-07T21:44:24-0400][1] runChild():469 Launching child process failed
[W][2025-04-07T21:44:24-0400][1476214] runChild():489 Received error message from the child process b
efore it has been executed
[E][2025-04-07T21:44:24-0400][1476214] standaloneMode():272 Couldn't launch the child process
21:44:25 ninja failed with: exit status 1

it relates to ubuntu 24 selinux rule

workaround
https://github.com/google/nsjail/issues/236
sudo sysctl -w kernel.apparmor_restrict_unprivileged_unconfined=0
sudo sysctl -w kernel.apparmor_restrict_unprivileged_userns=0



