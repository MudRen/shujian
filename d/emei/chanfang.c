// Room: /d/emei/chanfang.c

inherit ROOM;
#include <room.h>
#include <ansi.h>
// #include "jingzuo.h"
void create()
{
	set("short", "����");
	set("long", @LONG
������һ�䰲���������������Ǹ������е��Ӵ�������֮������������
����ط���������š���λ����ʦ̫���׼�Ů�����������붨��
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"lingwenge",
]));
    set("jingzuo", 1);
    set("no_fight", 1);
	setup();

}
