// mg-room4.c �Թ�����

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "�Թ�����" NOR);
        set("long", @LONG
������һ����ã��ıڹ��ļ��з������к��ˡ�����д���ֶ��Ǻ��֣�
ͨ���ϻ������˹��е������þߣ�ȴ�����������˵����£������֮����
���������������˽�����
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "southwest" : __DIR__"mg-room1",
              "northwest" : __DIR__"mg-room5",                     
        ]));
        setup(); 
        set("stone_count", 2);
}

void init()
{
        object me,ob;
        me = this_player();    
        if(random(10) > 6  && query("stone_count") >= 1){
         ob=unew(__DIR__"obj/shiqi");
       	 if( !clonep(ob)) return;
         if( clonep(ob) && ob->violate_unique()){
           destruct(ob);
           return;
         } 
          message_vision("ͻȻ�����һ�裬����ȵ���ʲôӲ������\n", me);
          ob->move(environment(me));
          add("stone_count", -1);
        }
}

int count = 20;
void reset()
{
    if (--count == 0) {count = 20; set("tu_count", 2); ::reset();}
}

int clean_up()
{
       return 0;
} 
