#!/bin/sh

cd ~
mkdir ~/.ssh
touch ~/.ssh/environment

cd ~
touch ~/.shfun.sh
mkdir ~/bin
cd ~/bin
ln -s `which clang-3.8` clang
ln -s `which clang++-3.8` clang++

cd ~
cp -ax /opt/dotfiles/tmux .tmux
ln -s ~/.tmux/tmux.conf .tmux.conf

cd ~
cp -ax /opt/dotfiles/vim ~/.vim
cd ~/.vim
rm -Rf bundle
ln -s /opt/vim/bundle

cd ~
mkdir -p ~/.config/nvim
cd ~/.config/nvim
cp /opt/dotfiles/nvim/init.vim .
ln -s ~/.vim/bundle
ln -s ~/.vim/colors
ln -s ~/.vim/autoload
ln -s ~/.vim/bin
ln -s ~/.vim/doc

cd ~
git clone `cat /opt/dotfiles/zsh/oh-my-zsh.giturl` ~/.oh-my-zsh
cp /opt/dotfiles/zsh/oh-my-zsh/themes/* ~/.oh-my-zsh/themes
cp /opt/dotfiles/zsh/zshrc .zshrc
touch .zshrc.local

cd ~
cp /opt/dotfiles/gitconfig ~/.gitconfig

mkdir ~/workspaces
cd ~/workspaces
# git clone https://github.com/dash-project/dash.git -b development ./dash-development
# cd ~/workspaces/dash-development
cp /opt/vim-plugins/ycm_global_conf.py .ycm_extra_conf.py

cd ~

