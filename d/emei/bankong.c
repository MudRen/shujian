// bankong.c
// �����

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "�����");
	set("long", 
HIW"���һ���������д�������������׹�䡣\n"NOR
);
	setup();
}
void init()
{ 
//    object me = this_player();
      add_action("do_action", "");                             
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
               case "practice":
               write(HIW"���һ���������д�������������׹�䡣\n\n"NOR);
                       return 1;
       }
       return 0;
}
