#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",HIR"������"NOR);
       set("long", @LONG
һ���������ң���������ľ���ɣ�������ɽ�������ı����𣬶���ʯ
�ڡ����ɽ��ʯ�ң����ǻ�Ȼ��ɣ�������ǰ����ɮ���������ǻۣ������
����ɽ�����ˡ��������ͨ�������겻Ϣ�����й������ҷ�ķ�������
��ͬ������ǧ�����������ơ�ְ��ɮ�ڵ����Ĵ�Ѳ�ӣ��Ա����衣һλ��
ɮ�Ŀ���������Ӳ�����
LONG
     );
	set("exits", ([
                "south" : __DIR__"xcping",
                "west" : __DIR__"xclang",
              "north"  : __DIR__"duanya",
	]));

        set("objects",([
           "/kungfu/class/shaolin/fangsheng" : 1,
        ]));

        set("coor/x",60);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}
