// Room: /d/huashan/place.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "ɽ·");
	set("long", 
HIW"��������ư���һ����������·�Ķ����±������š�\n"NOR
);
	setup();
}
void init()
{ 
	object me = this_player();
       add_action("do_action", "");                             
	call_out("do_go", 5, me);
}
int do_action(string arg)
{
       string action = query_verb();

       switch (action) {
               case "look":
               case "exercise": 
               case "lian":
               case "tuna":       
               case "quit":
               case "l" :
	        case "dazuo" :
	        case "save" : 
               case "practice":
               write(HIW"��������ư���һ����������·�Ķ����±������š�\n\n"NOR);
                       return 1;
       }
       return 0;
}	

void do_go()
{
	object me = this_player();
	write("����������ĸ����ưͺ��棬ʵ���Ǹ������ˣ�ֻ�ð�ľͰ�ӵ���\n", me);
	call_out("do_go1", 5, me);
}
void do_go1()
{
	object me = this_player();
	write("��һ������ưʹ���������һ���յ�ǰ��\n", me);
	me->move(__DIR__"kongdi");
	message_vision("�ưͳ������������ȥ��\n", me);
	call_out("do_back", 0, me);
}

void do_back(object me)
{
	if( present("shui tong", me))
	destruct(present("shui tong", me));
}
