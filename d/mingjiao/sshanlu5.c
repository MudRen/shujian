// sshanlu5.c ɽ·
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long",@LONG
����һ��һխ�ֶ���ɽ·��ɽ·���Գ����ָ����ӵ��Ҳ���������û��ͷ��
ż�����м�֦������ס���ȥ·��һ��С����ᱻ����ˡ�
LONG);
    set("exits",([
        "westdown"  :     __DIR__"xuanya3",
        "southup"   :     __DIR__"shanting",
    ]));
    set("objects",([
         __DIR__"npc/guiren"  :    2,
    ]));	
    set("coor/x",-310);
  set("coor/y",130);
   set("coor/z",50);
   set("coor/x",-310);
 set("coor/y",130);
   set("coor/z",50);
   setup();
    set("outdoors", "���̹�����");
}

int valid_leave(object me, string dir)
{
       if (dir == "southup" && userp(me)){
           me->receive_damage("jing", 10);
           me->receive_damage("qi", 10);
       }
       return ::valid_leave(me, dir);
}

void init()
{
	object me=this_player();
	if (me->query("jing")<20 || me->query("qi")<20 ){
	  write("�㿴�����Ѿ������ˣ���Ϣһ���ٸ�·�ɡ�\n"NOR);
          me->start_busy(2);
        }
}
