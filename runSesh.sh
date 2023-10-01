
cd ~/projects/FreeWatchSW/c-example
tmux new-session -d -s freewatch_sesh 
tmux split-window -h #'minicom -D /dev/ttyACM0 -b 115200'
tmux split-window -v 
tmux a
