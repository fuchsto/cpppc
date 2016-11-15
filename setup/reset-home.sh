#!/bin/sh

CONFIRMED=0

read -p "This will delete files in your home directory. Are you sure? " choice
case "$choice" in
	y|Y ) CONFIRMED=1 ;;
	* ) ;;
esac

if [ "$CONFIRMED" -eq "1" ] ; then

  cd ~

	rm -Rf ~/workspaces
	rm -Rf ~/bin
	rm -Rf ~/.config
	rm -Rf ~/.vim
	rm -Rf ~/.ssh
	rm -Rf ~/.tmux
	rm -Rf ~/.oh-my-zsh
	rm ~/.gitconfig
	rm ~/.zshrc
	rm ~/.zshrc.local

	unlink .tmux.conf
else
	exit 1
fi
