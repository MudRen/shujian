// Room: /d/village/tiejiangpu.c

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����һ�����Ǽ�ª�������̣����������Ǹ������裬����ú��������ǽ��
���ż�����ͷ�����ӵĽ�������ż����Ƴ�ͷ����������ǽ���ż����³�¯��
������
LONG
        );
	set("exits", ([
		"west" : __DIR__"shilu2",
	]));

	set("objects", ([
		__DIR__"npc/feng": 1 
	]));
	setup();
}
