// /dali/shudian.c ���
// bbb 1997/06/11
// Modify By River 98/12/
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������꣬�������䲼������ܣ��������˱�����ԭһ����ţ��Ŵβ�
�ӳ�ͥ�ƾ�Ӧ�ԣ�ȫ�������л��Ų�����һ��֮�£�����������С������
������Ϊ����
LONG
        );

        set("exits", ([
              "north" : __DIR__"nanjie1",
        ]));

        set("objects", ([
                __DIR__"npc/laoxiucai" : 1,
        ]) );

        set("coor/x",-330);
  set("coor/y",-470);
   set("coor/z",-20);
   setup();

}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/shudian",1);
      }
}
