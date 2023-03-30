# Vibration Strategy
vibration patterns using C++ and Raspberry Pi  4 
# Install Steps
## Installing MATRIX HAL
### Add Matrix repository and key 
```batch
curl https://s3.amazonaws.com/apt.matrix.one/doc/apt-key.gpg | sudo apt-key add -
echo "deb https://apt.matrix.one/raspbian $(lsb_release -sc) main" | sudo tee /etc/apt/sources.list.d/matrixlabs.list
```
### Update System and Install the MATRIX HAL Packages 
```batch
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install matrixio-creator-init libmatrixio-creator-hal libmatrixio-creator-hal-dev
```
### Reboot your PI
```batch
sudo reboot
```
## Clone the Vibration Strategy 
```batch
cd ~/
git clone https://github.com/AmraneNecira/-vibration-strategy.git
```
## Compile your program
```batch
cd ~/vibration-strategy 
g++ -o vibration-strategy main.cpp -std=c++11 -lmatrix_creator_hal
```
## Run your program
```batch
cd ~/vibration-strategy 
./vibration-strategy
```
