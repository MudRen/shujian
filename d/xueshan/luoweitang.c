// Room: luoweitang.c

inherit ROOM;

void create()
{
	set("short", "��΢��");
	set("long", @LONG
�÷�ǰ���С���������ǰ����������ż������ε�שǽ��������Ϊ����
���ܽ��Ӷ��ĸ�¥����ǰ���������ܽ�������У��û�ׯ�ء��������ڽ��и�
��������޵�ͼ���������Ǵ����µ��Ӻ�����ɮ�½����۷�ĵط������·���
�Ħ�Ǿ;��������￪̳�۷���
LONG
        );

	set("exits", ([
		"west" : __DIR__"huilang4",
"east" : __DIR__"daritang",
	]));
        set("objects", ([
         __DIR__"npc/zheluoxing" : 1 ]));
	setup();
}
