{a[$1]+=$2}
END{
	for(x in a){
		print x,a[x]
	}	
}
