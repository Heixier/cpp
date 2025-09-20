#!/bin/bash

#Run fclean on all subdirectories

for dir in */; do
	make -C "$dir" fclean
done
