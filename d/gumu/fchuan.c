// Room: /u/xdd/gumu/fanchuan.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
     set("short",HIY"����"NOR);
     set("long", @LONG
�˴����Ƿ�������������ɽ�����ڣ����������󽫾�������ʳ���ڴˣ���
����������;���ͻ��ƣ��ɰ�ɭӳ,ˮ������������䣬��Ȼ�н��Ͼ�ɫ��
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
		"east" : "/d/xiangyang/shanxiroad1",
		"west" : __DIR__"xiaolu1",
     ]));

	setup();
}
