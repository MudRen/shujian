// Room: /city/zhengting.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	�����Ǹ����ھֵ���������ֻ̫ʦ��һ���ſ������������ž�ͷ���ֳ�
�̴������ڱ�Ŀ��˼��ǽ�Ϲ��ż����ֻ���һ�ѱ�����
LONG
	);
	set("exits", ([
		"north" : __DIR__"biaoju",
	]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }