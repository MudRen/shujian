// wanfoding.c
// ���
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY "���" NOR);
        set("long",@long
�����Ƕ���ɽ�ϵ���𶥣������Ѿ��������ɸ�ɽ֮�ۣ������ǱȽϺ���
�ġ������м���ľ�����Ƕ����ɵ��е������Լ����ִ�İ���֮������
��������ϵ�������������Ǿ��϶���
long);
        set("outdoors", "��üɽ");
        set("exits",([
             "north":__DIR__"mupeng",
             "west" : __DIR__"jiulaodong",
             "enter" : __DIR__"wanfota",
]));
        setup();
}

void init()
{
   object me, room;
   me = this_player();
   room = this_object();
   if(interactive(me) && (objectp(present("zhi huan", me)))){
        message_vision(HIR"ֻ����ǰ��һ�������������˵����������ָ�������ߣ�\n"NOR, me);   
        new(__DIR__"npc/shouta")->move(environment(me));        
        room->delete("exits");
        }       
}

int valid_leave(object me, string dir)
{
 if (dir == "north" && me->query("gender") == "Ů��" )
    return notify_fail("�������е��ӵ���Ϣ�ң�����ò�Ҫ��ȥ��\n");
 if (dir == "enter" && (me->query("class") != "bonze" && me->query("family/family_name") != "������" ) )
    return notify_fail("�����Ƕ����ɵķ��ʥ�أ�����ò�Ҫ��ȥ��\n");
    return ::valid_leave(me, dir);
} 
