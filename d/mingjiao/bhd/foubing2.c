// foubing2.c ��ɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"��ɽ"NOR);
	set("long", @LONG
����һ��ܴ󸡶���ɽ����������������ɡ�����ǰ��ı�ɽ�ܵ���ɽ֮
�ȣ����ϵ��ۻ�����ʱ�������ű�ɽ�ۻ���ůˮһ��������Ʈ����ʱ�㿴����
Զ֮����һ��С����(bing)�����ܿ��Ե����ã��򵺻�����
LONG);
        set("no_fight", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1); 
        set("outdoors","����");
	setup();
}

void init()
{
    if(interactive(this_player())){
         remove_call_out("run");
         call_out("run", 20+random(30));
    }
    add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me=this_player();
	if (!arg) return 0;
	if (arg=="bing" || arg== "С����"){
            message("vision", me->name() + "���ֱ���С���飬 ��ͨһ�����뺣�С�\n",environment(me), ({me}) );
       	    me->move(__DIR__"xbkai");
            message("vision", me->name() + "���Ǳ��������˹�����˫�ֱ���С���顣\n",environment(me), ({me}) );
            return 1;
        }
        return 0;
}

void run()
{
     object *obj;
     int i;
     obj = all_inventory(this_object());
     for(i=0; i<sizeof(obj); i++){ 
        tell_object(obj[i],HIW"\n��ɽ���ź�ˮů������Ʈ�롣\n\n"NOR);
       	obj[i]->move(__DIR__"dbshan");
     }
}
