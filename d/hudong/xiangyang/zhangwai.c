#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", YEL"Ӫ����"NOR);
        set("long", "������������Զ���ɹž�Ӫ�������⣺\n"+
"�����߿ɵ����"+HIG"������"NOR+"����\n"+
"���߿ɵ����"+HIW"�׻���"NOR+"����\n"+
"���߿ɵ����"+HIR"��ȸ��"NOR+"����\n"+
"�����߿ɵ����"+CYN"������"NOR+"����\n"
        );

        set("no_save", 1);
        set("outdoors", "����");
        

        set("exits", ([
"east" : "d/hudong/xiangyang/shandao",
"west" : "d/hudong/xiangyang/shandao1",
"north" : "d/hudong/xiangyang/shandao2",
"south" : "d/hudong/xiangyang/shandao3",
                
        ]));
       
        set("incity",1);
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "west" || dir == "east" || dir == "north" ||dir == "south"  ){
if ( !me->query_temp("cart"))
                        return notify_fail("���˳峵���ߡ�\n");
        }
return ::valid_leave(me, dir);

}
void init()
{
	add_action("do_get","ling");
	
}
int do_get(string arg)
{
	object me = this_player();
object obj;
if(!arg || arg == "" || arg != "�峵")	
return notify_fail("������ʲô��\n");
if(me->query_temp("cart"))
return notify_fail("���Ѿ�����ˡ�\n");
if(arg == "�峵")
{
obj =new("d/hudong/xiangyang/obj/cart");
message_vision(CYN"$Nһ���峵��¡¡��ʻ�˳�����\n"NOR, me);
me->set_temp("cart",1);  // ��ȡһ���峵
obj->move(this_object());
obj->set("name",obj->query("name")+(me->query("id")));
obj->set("long", obj->query("long")+"�����峵����"+me->query("name")+"������ݵġ�\n");
obj->set("make",me->query("id"));
return 1;
}
}

