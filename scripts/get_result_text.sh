#Generates output of all the results.
while read igname
do
	ignamewithoutextension=$(basename "$igname" .cpp)
	ignames[$i]="$ignamewithoutextension"
	((i++))
done < <(ls ../src/ig | grep '\.cpp$')

while read size
do
	sizes[ $j ]="$size"
	(( j++ ))
done < <(cat < ../res/input_sizes)

while read sortname
do
	sortnamewithoutextension=$(basename "$sortname" .cpp)
	printf "Sort Name,${sortnamewithoutextension}\n"

	for igname in ${ignames[@]}
	do
		printf ",Input type,${igname}\n\n"
		printf ",Input size,"
		for size in ${sizes[@]}
		do
			printf "${size},"
		done
		printf "\n,Runtime(in ms),"
		for size in ${sizes[@]}
		do
			printf $(../bin/cpp/${sortnamewithoutextension}.exe < ../inputs/${igname}_${size}.input)
			printf ","
		done
		printf "\n\n"
	done
	printf "\n\n"
done < <(ls ../src/cpp | grep '\.cpp$')
