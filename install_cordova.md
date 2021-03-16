# Installation of the development environment for Cordova on MacOSX

## Requirements

* Download Xcode from the App Store

* Open a terminal (Launchpad -> Terminal), type:

```
xcode-select --install
brew install ios-deploy
```

If brew is not installed, type this command to install it:
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Install Cocoapods
```
sudo gem install cocoapods
```

## Cordova

* Install Node.js at this link: https://nodejs.org/en/download/
* Install Cordova with npm:
```
sudo npm install -g cordova
```