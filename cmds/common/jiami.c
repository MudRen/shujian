#pragma no_save_binary

#define MAX_SIZE 30000

buffer buf;
string file;
nosave object obb;

void check_again(int now);

int main(object me, string arg)
{
	int size, i, flag;

	seteuid(getuid(me));
	if (!arg) return notify_fail("ָ���ʽ��jiami <�ļ���>\n");
	flag = wizardp(me);
	file = resolve_path(me->query("cwd"), arg);
	switch (file[<2..<1]) {
		case ".c":
		case ".h":
			break;
		default:
			return notify_fail("�ļ������� .c �� .h ��β��\n");
	}
	if (file_size(file) < 0) return notify_fail("û������ļ���\n");
	if (flag) write("��ȡ " + file + "... ");
	buf = read_buffer(file);
	size = sizeof(buf);
	if (flag) write(size + " �ֽ� ... ");
	if (!size) return notify_fail(file + " ����Ϊ�㡣\n");
	if (buf[0] & 0x80) return notify_fail(file + " �Ѿ��������ˡ�\n");
	if (flag) write(" ���� ... ");
	if(size>MAX_SIZE) size=MAX_SIZE;
	// 1000
	for (i = 0; i < size; i++) buf[i] = ((buf[i] ^ ((i+128) & 0xD5)) * 257) >> (i & 7);
	if(sizeof(buf)>size)
	{
		obb=me;
		call_out("check_again",0,size);
		if (flag) write(" �������\n");
		return 1;
	}
	if (flag) write(" ���� ... ");
	write_buffer(file, 0, buf);
	if (flag) write(" ���\n");
	return 1;
}

void check_again(int now)
{
	int i,size;
	if(now>=sizeof(buf)){
		write_buffer(file, 0, buf);
		if(obb && userp(obb)) tell_object(obb,"������ɡ�\n");
		return;
	}
	size=sizeof(buf)-now;
	if(size>MAX_SIZE) size=MAX_SIZE;
	tell_object(obb,sprintf("now = %d size %d \n",now,size));
	for (i = now; i < now+size; i++) buf[i] = ((buf[i] ^ ((i+128) & 0xD5)) * 257) >> (i & 7);	
	call_out("check_again",1,now+size);
}