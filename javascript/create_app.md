# Create an application with Cordova

Source: https://cordova.apache.org/docs/en/10.x/guide/cli/index.html

Open a terminal and go to the directory where you usually store your code (with the command `cd`).

Create the folder:
```
cordova create hello com.example.hello HelloWorld
```
Add the platforms that you want:
```
cordova platform add ios
```
Check that the requirements are satisfied:
```
cordova requirements
```
If there is an error, it means that a problem happened during the installation.


Build the app:
```
cordova build
```

Open the emulator and run the app:
```
cordova emulate ios
cordova run ios
```
