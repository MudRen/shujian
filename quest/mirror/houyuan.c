// houyuan.c ������Ժ
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������Ժ");
	set("long", @LONG
	�����ǲ�����Ժ�����ֹ���������Ŀ��������ͭ�����ߵ��������ʡ�����
Ӧ�о��У�ֻҪӵ��һ�����͹����һ�����ˡ���Ա��������������ϣ�������
�غ��Ų�����������һ����(men)��
LONG
	);
	set("item_desc", ([
		"men" : "�������ƺ�ͨ��һ�����ҡ�\n",
	]));
	set("exits", ([
		"south" : __DIR__"dayuan",
		"west" : __DIR__"xixiang",
	]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }