#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"�껨Ժ"NOR);
        set("long",@LONG
�˴���ɽ��ˮ��һ��СϪ������ǰ����������һ������ľ�ź��
���ϣ����䵹Ӱǡ��һԲ��ӳ�ſ����ˮ�档Ϫ�Ա�ֲ�ٻ����紵��
�䣬�������껨Ժ֮�ơ�Ժ���껨�����������вؾ�����֮������
�м�����������ȥȥ��ȴ����һ˿���졣
LONG);
        set("outdoors","������");
        set("exits", ([
                "south" : __DIR__"wwj",
		"enter" : __DIR__"yuhua1",
                "east" : __DIR__"songlin2",
	]));
        set("coor/x",-310);
  set("coor/y",-290);
   set("coor/z",40);
   setup();
}
