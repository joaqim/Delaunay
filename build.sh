#CONFIGURE_OPTS="--with-x11=yes --with-glfw=yes --with-ocr=no --enable-gl3=yes --with-boost=yes --disable-shm=yes"
CONFIGURE_OPTS="--with-x11=yes --with-glfw=yes --with-ocr=no --enable-gl3=yes --with-boost=yes " #--disable-shm=yes

if [ "$1" == "ycm" ]; then
	git clean -xi
	autoreconf -vfi
	ycm_generator -f -b autotools   --verbose . --configure_opts="$CONFIGURE_OPTS"
	exit 0
fi


./autogen.sh
#mkdir -p build; cd build
set e

cd src

if [ "$1" == "win" ]; then
	../configure --prefix=/mingw64
else
#	../configure --prefix=/usr --enable-gl3=yes
	#../configure --prefix=/usr --with-x11=yes --with-glfw=yes --with-ocr=yes

	  ../configure --prefix=/usr $CONFIGURE_OPTS

	  #NOTE: flag -C enables use of cache, will need to manually delete cache if new package is installed
	# might not work with some third party macros [https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.69/html_node/Caching-Results.html#Caching-Results]
fi
make -j6

#git submodule foreach git clean -xdf

