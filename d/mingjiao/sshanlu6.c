// sshanlu6.c ɽ·
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long",@LONG
����һ��һխ�ֶ���ɽ·�������Ѽ���ѩ����ѩ����ɽ·�����ָ����ӵ�
�Ҳ�������������������е�����ĺ�������ͷ���ϱ��ǰ�ɽ����
LONG);
    set("exits",([
        "eastdown"  :     __DIR__"shanting",
        "southup"   :     __DIR__"shanyao",
    ]));
    set("coor/x",-320);
  set("coor/y",120);
   set("coor/z",70);
   set("coor/x",-320);
 set("coor/y",120);
   set("coor/z",70);
   setup();
    set("outdoors", "���̹�����");
}

int valid_leave(object me, string dir)
{
     if ( dir == "southup" && userp(me)) {
       me->receive_damage("jing", 10);
       me->receive_damage("qi", 10);
       }
       return ::valid_leave(me, dir);
}

void init()
{
	object me=this_player();
	if (me->query("jing")<20 || me->query("qi") < 20){
	write("�㿴�����Ѿ������ˣ���Ϣһ���ٸ�·�ɡ�\n"NOR);
        me->start_busy(2);
        }
}
