#��һ����Ĺ����ļ��У���ͬ���ļ����չ��ܱ����ֵ���ͬ��ģ���У�Ҳ��˵�ܶ��Դ�ļ����������˲�ͬ��Ŀ¼�¡�
#ÿ��ģ����ܶ������Լ��ı���˳��͹��������һ��Makefile�ļ�����������ģ��ı�����򣬾ͻ���ң�ִ��ʱҲ�᲻���㣬
#���Ծ���Ҫ�ڲ�ͬ��ģ���зֱ�����ǵĹ������������Ҳ����ÿһ��ģ�鶼��дһ��Makefile�ļ��������������������
#���ҿ���Ѹ�ٷ���ģ���е����⡣��������ֻ��Ҫ��������ģ���е�Makefile�Ϳ���ʵ������Ŀ��ƣ������make��Ƕ��ִ�С�

TARGET := bin/main.exe

CINCLUDE := -I include
OBJ := build/main.o
LIBS := lib/libcopy.a

#��αĿ��all֮��.PHONYҪ���ڱ���֮��
.PHONY:all clean

#����make����ʱ��Ĭ��ִ�е���Makefile�ļ��д�����һ��Ŀ����������ִ�б��붯��������clean��run��
all:$(TARGET)

#Makefile��Ƕ��ִ��make�ķ��������֣�cd subdir&&make �� make -C subdir��
_CHANGE_WAY_ :=

ifdef _CHANGE_WAY_

#�ڵ�ǰĿ¼����һ��sourceĿ¼��һ��Makefile�ļ�����Ŀ¼source�»���һ��Makefile�ļ���
#����ļ����������������Ŀ¼�ļ��ı������ʹ��ʱֻ��Ҫ��������Ŀ¼��ִ��make���
#������ִ�е�cd source && make����ʱ���������뵽��Ŀ¼��ִ��make�������Ƕ��ִ��make��
#���ǰ�������Makefile��Ϊ���ܿ�Makefile��
$(TARGET):
	cd source && make
	$(CC) -o $@ $(OBJ)  $(LIBS) $(CINCULDE)

clean:
	cd source && make clean
	del /f bin\*.exe

else

#��make��Ƕ��ִ���У����Ǳ���CURDIR����make�Ĺ���Ŀ¼����ʹ��make��ѡ��-C��ʱ������ͻ����ָ����Ŀ¼�У�
#Ȼ��˱����ͻᱻ���¸�ֵ�������Makefile��û�жԴ˱���������ʽ�ĸ�ֵ��������ô���ͱ�ʾmake�Ĺ���Ŀ¼��
#����Ҳ������Makefile��Ϊ���������һ���µ�ֵ����Ȼ���¸�ֵ��������������ٴ���make�Ĺ���Ŀ¼��
$(TARGET):
	make -C source
	$(CC) -o $@ $(OBJ)  $(LIBS) $(CINCULDE)

clean:
	make clean -C source
	del /f bin\*.exe

endif

run:
	$(TARGET)

include common/Makefile

#ʹ��makeǶ��ִ�е�ʱ�򣬱����Ƿ񴫵�Ҳ��������Ҫע��ġ������Ҫ�����Ĵ��ݣ���ô����ʹ��export <variable>��
#�������Ҫ�����Ĵ��ݣ���ô����ʹ��unexport <variable>��variable�Ǳ��������֣�����Ҫʹ�� "$" ����ַ���
#������еı�������Ҫ���ݣ���ôֻ��Ҫʹ��export�Ϳ��ԣ�����Ҫ���ӱ��������֡�

#Makefile�л����������������ǲ���ʹ�ùؼ���export�����������ܻᴫ�ݵ��²��Makefile�С�
#�����������ֱ���SHELL��MAKEFLAGS���ر���MAKEFLAGS������������make�Ĳ�����Ϣ�����ִ���ܿ�Makefileʱ��
#make������в����������ϲ��Makefile�ж����������������ôMAKEFLAGS������ֵ������make����ݵĲ�����
#���һᴫ�ݵ��²��Makefile�У�����һ��ϵͳ����Ļ���������

#make�������м�������ѡ������ݣ�������-C��-f��-o��-h��-W��������ǲ��봫��MAKEFLAGS������ֵ��
#��Makefile�п���������д��cd subdir && make MAKEFLAGS=��