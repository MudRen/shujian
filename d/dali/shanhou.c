// by cool 98.2.20
// Modify By River 98/12/
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY"�Ʋ��"NOR);
	set("long", @LONG
������ۡ��ģ��С���ſ�����һ���ƣ��������֡��Ʋ�������Ʋ����
��̩���������Ľ����ֵܣ�������Ϊ��������ս�����شʹ˸�ۡ�������õ���
�������ţ�û��ʲô��ĳ��ڣ�����ͨ������֡�
LONG
	);
	set("exits", ([
              "east" : __DIR__"xijie5",
        ]));

        set("objects", ([
              __DIR__"npc/bing" : 2,
              __DIR__"npc/gaoshengtai" : 1,
        ]));
	set("coor/x",-340);
  set("coor/y",-430);
   set("coor/z",-20);
   setup();
}
