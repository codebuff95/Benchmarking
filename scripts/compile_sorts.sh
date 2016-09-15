# Compile all the sort files in the directory ../sorts_src
while read sortname
do
	sortnamewithoutextension=$(basename "$sortname" .cpp)
	g++ ../src/${sortname} -o ../bin/${sortnamewithoutextension}.exe
	#echo $sortname
	#echo $sortnamewithoutextension
done < <(ls ../src | grep '\.cpp$')
