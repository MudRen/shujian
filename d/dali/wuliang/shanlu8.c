// Modify By River 98/12
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ų����У��ٲ�̤���ľ��ǰ������ݣ�����û��·,ÿ��һ����������
���̵�С��,����������塣
LONG
	);
        set("outdoors", "����");

	set("exits", ([
           "south" : __DIR__"xiaoxi",
           "north" : __DIR__"shanlu9",
           "east" : __DIR__"anbian1",
           "west" : __FILE__,
	]));

	set("coor/x",-300);
  set("coor/y",-290);
   set("coor/z",-20);
   setup();
}

void init()
{
       object me = this_player();
        if( random((int)(me->query("kar")))<15
        && me->query_con() < 30){
       me->set_temp("last_damage_from", "��ɭ�����ƣ������");
         me->add("qi", -50);
         me->add("jingli", -10);
         me->receive_wound("jing", 20);
         }
       else{
         me->add("qi", -10);
         }
}
