#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"���"NOR);
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��
�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�������������һ���ź��ſ���
�ǣ���̨������һλ�ϰ�����ڵ������̡�
LONG
	);
	set("resource/water", 1);
        set("objects",([
                 __DIR__"npc/shinv" : 1,
        ]));
	set("exits", ([
		"southwest" : __DIR__"nandajie1",
	]));

	set("coor/x",120);
  set("coor/y",-230);
   set("coor/z",0);
   set("incity",1);
	setup();
}

