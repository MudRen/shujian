// Room: rimulundian.c

inherit ROOM;
#include <room.h>
#include <ansi.h>

void create()
{
        set("short", "��ľ�׵�");
        set("long", @LONG
�����Ĳ㣬�ϸ��𶥣��Ի�׳�ۡ���������ԭ�Ľ������Ҳ����������
�ͻ����Ƚ���������ɫ����������϶����������������������졢�����
�ޡ���ǰΧǽ�������Ⱥ���С��ͨ����ǰ������
LONG
        );

         set("exits", ([
                "north" : __DIR__"hufazhacang",
                "west" : __DIR__"yueliangmen",
                "east" : __DIR__"chiyangmen",
                "southeast" : __DIR__"zhaitang",
                "out" : __DIR__"xiekemen",
        ]));

          set("objects", ([__DIR__"npc/fanseng" : 2]));
        
        setup();
        create_door("out", "����ľ��", "enter", DOOR_CLOSED);                   
}
int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir)
{
        
         object *obj;
        
          
        if ((string)me->query("gender") == "����" && dir == "west"
           && present("hufa lama", environment(me)))
                return notify_fail("����������ס����������Ǳ���Ů������Ϣ�ľ�������ȥ���󷽱�ɣ�\n");

        if ((string)me->query("gender") == "Ů��" && dir == "east"
           && present("hufa lama", environment(me)))
                return notify_fail("����������ס����������Ǳ����е�����Ϣ�ľ�������ȥ���󷽱�ɣ�\n");
        if(dir == "southeast"&& me->query("family/family_name")!= "������"
           && present("hufa lama", environment(me)))
             return notify_fail(CYN"����������ס��˵��:������ڻ�ʳ���ţ����ɵ����뵽�������н����\n"NOR);
        obj = filter_array(deep_inventory(me),(:get_object:));
        if( sizeof(obj) && dir=="southeast" ) {
                write (HIR"�����͵͵�����˽�ȥ���������̫�࣬����һ����˩��ˤ���ڵء�\n"NOR);
                obj[0]->move(environment(me));
                me->unconcious();
        return 1;
        }
        return ::valid_leave(me, dir);
        
}
