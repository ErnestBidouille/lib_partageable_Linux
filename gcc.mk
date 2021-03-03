
%.o : $.c
	gcc -fPIC ${CFLAGS} -c $< -o $@

%.o : %.cpp
	g++ -fPIC ${CPPFLAGS} -c $< -o $@

${EXE} : ${OBJS}
	g++ ${OBJS} -ldl -o $@

${LIBSO} : ${LIBSO_OBJS}
	gcc -o $@ -shared $^
