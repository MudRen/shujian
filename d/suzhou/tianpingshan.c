#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ƽɽ");
        set("long",@long
��������ɽ�����뼸��ؾ͵�����ƽɽ����Ϊ����������ɽ֮��߷塣
�����ƽ̹���ƶ�����������ɽ�Ƹ߾����������ƣ�Ҳ�ơ�����ɽ�������أ�
��������������ƽɽ���뷶����������Ҳ�ơ�����ɽ����
long);
set("outdoors", "suzhou");
set("exits",([
"northeast" : __DIR__"qsgdao",
"north" : __DIR__"shihu",
"southeast" : __DIR__"lingyanshan",
"eastup" : __DIR__"baiyunquan",
]));
set("coor/x",110);
  set("coor/y",-280);
   set("coor/z",0);
   setup();
}
