// /u/beyond/hangzhou/hubian.c ������
 
inherit ROOM;
void create()
{
        set("short","������");
        set("long", @LONG
��������ɽ��ˮ�㣬�̲�����������ɽɫ����ӳ��Ȥ�����ۺ������羵
���У������������续���Ρ�����֮�����������Թ����������ǳ����ޡ�
�����ġ��㡢�ᡢ�������������δ���ʫ�������ġ����������緽�ã�ɽɫ
���������棬�������������ӣ���ױŨĨ�����ˡ�һʫ���������������ľ�
ɫ�������쾡�¡�
LONG
        );
        set("exits", ([
		"northwest" : __DIR__"baidi",
                "east" : __DIR__"yuemiao",
	]));
	   	set("objects", ([ 
		"d/baituo/npc/ouyangke" : 1,
		"d/baituo/npc/baiyishaonv" : 2,
	]));
	set("outdoors", "����");
	setup();
}
