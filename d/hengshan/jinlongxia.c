// Room: /d/hengshan/jinlongxia.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"����Ͽ"NOR);
	set("long", @LONG
����Ͽ�ֳ��������ǽ����ɽ����ڡ���ɽһ��̫��ɽ���������������
���еı�����������֮Ϊ������С���족������ب���������һ���н��е�
���У�������Ϊ����ɽ���С�����ԡ�̩ɽ������������ɽ������������ɽ��
�ԡ��͡���ɽ��ɡ���
LONG
	);
	set("exits", ([
                "southdown"  : "/d/changan/northroad10",
                "southwest"  : __DIR__"cuipinggu1",
	]));
	set("objects", ([
		__DIR__"npc/jing" : 1,
	]));
        set("outdoors", "��ɽ");
        setup();
}
