// Room: /city/bingyindamen.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "��Ӫ����");
	set("long", @LONG
	����վ�ڱ�Ӫ���ſڣ������һ�ż�ª��Ӫ�������Կ��������Ʒ��Ĺٱ�
���ڲ�������ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ��ģ�����øϿ��߿���
LONG
	);
	set("exits", ([
		"south" : __DIR__"bingyin",
		"north" : __DIR__"xidajie1",
	]));

	setup();
}

//�Ǿ���
int is_mirror() { return 1; }