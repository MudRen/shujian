// Room: bianhou.c
// By River 98/08
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIB"�Һ�"NOR);
        set("long", @LONG
������ǹ�Ĺ�����Ҷ�֮�󣬺������ʲô�����������
LONG
    );
      
        set("objects",([
             __DIR__"obj/silkey" : 1,   
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump","jump");
        add_action("do_search", "search");
}

int do_jump(string arg)
{
        object me,room;
        me=this_player();  
        if (arg!="down") return 0;
        message("vision",me->name()+"һ����������ȥ��\n",this_object());
        if(room=find_object(__DIR__"gmzt"))
        message("vision",me->name()+"���Ҷ������˹�����\n",room);
        me->move(__DIR__"gmzt");
        return 1;
}

int do_search(string arg)
{
	object me,key;
	me = this_player();
	if(arg) return 0;
	key = unew(__DIR__"obj/silkey");
        if(!clonep(key)) return notify_fail("�������ˣ������Һ�ʲô����Ҳû���ҵ���\n");
        if(clonep(key) && key->violate_unique()){
           destruct(key);
           return notify_fail("�������ˣ������Һ�ʲô����Ҳû���ҵ���\n");
        }
        message_vision(HIB"$N������ϸ���������Һ�ڰ���������$n��\n"NOR, me, key);
        key->move(me);
	return 1;
}

void reset()
{
        object *ob;
        int i;
        ob = all_inventory(this_object());
        for(i=0; i < sizeof(ob); i++){
                if( userp(ob[i]) ) continue;
                ob[i]->reincarnate();
                if( !ob[i]->return_home() ) destruct(ob[i]);
        }
}
