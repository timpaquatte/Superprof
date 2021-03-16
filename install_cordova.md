# Installation of the development environment for Cordova on MacOSX

## Requirements

* Download Xcode from the App Store

* Open a terminal by opening the Launchpad and typing "Terminal", then write the following commands:

```
xcode-select --install
brew install ios-deploy
```

If the last command failed because brew is not installed, type this command to install it:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install Cocoapods
```
sudo gem install cocoapods
```

## Cordova

* Install Node.js for MacOSX at this link: https://nodejs.org/en/download/
* Install Cordova with npm:
```
sudo npm install -g cordova
```

The installation should be complete !!