while read igname
do
	ignamewithoutextension=$(basename "$igname" .cpp)
	g++ ../src/ig/${igname} -o ../bin/ig/${ignamewithoutextension}.exe
done < <(ls ../src/ig | grep '\.cpp$')
