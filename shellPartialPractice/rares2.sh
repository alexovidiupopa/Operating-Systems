#!/bin/bash

count=0
D=$1

for d in `find $D`; do
	        if [ -d $d ];then
			                continue
					        fi
						        c=$(wc -l $d)
							        b=0
								        for a in $c;do
										                (( b=$a ))
												                break
														        done
															        if [ $b -gt 500 ];then
																	                (( count++ ))
																			        fi
																				        if [ $count -eq 2 ];then
																						                break;
																								        fi
																								done

																								echo $count
