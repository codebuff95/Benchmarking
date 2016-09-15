while read line
do
	array[ $j ]="${line}"
	(( j++ ))
done < <(cat < ../res/input_sizes)

while read igname
do
	ignamewithoutextension=$(basename "$igname" .exe)
	ignameswithoutextension[ $i ]="$ignamewithoutextension"
	(( i++ ))
done < <(ls ../bin/ig)

for inputsize in ${array[@]}
do
	for igname in ${ignameswithoutextension[@]}
		do
			echo ${inputsize} | ../bin/ig/${igname}.exe > ../inputs/${igname}_${inputsize}.input
		done
done

echo "Generated all input files."
