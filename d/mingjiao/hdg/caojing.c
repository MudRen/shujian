// �ݾ� caojing.c
 
#include <ansi.h>

inherit ROOM;
void create() 
{ 
        set("short", "�ݾ�");
        set("long", @LONG
����һƬ�ݵأ�������Ƭ�ݵ����߰˼�é�ݣ�é�ݵ�ǰ�����Ҷ��ǻ��ԣ�
�����Ѿ����˵���ҽ�ɺ���ţ��ס���ˡ�
LONG
        );

        set("outdoors", "������");

        set("exits", ([ 
            "north" : __DIR__"maowu",
            "west" : __DIR__"maopeng",
            "south" : __DIR__"niupeng",
            "east" : __DIR__"xfang1",
]));

        setup();
}

int get_object(object ob)
{
        return (userp(ob));
}

int valid_leave(object me, string dir)
{
        object *ob, *inv;
        mapping myfam;
        myfam =( mapping)me->query("family");

        inv = deep_inventory(me);
        if (dir == "south"){
          write("������һƬ���ԣ�������������㻨�ݡ�\n");
          ob = filter_array(inv,(:get_object:));        
          if (myfam && myfam["family_name"] =="����" && myfam["generation"] == 35 && ! sizeof(ob))
          write("�������������Ž����Ľ̻壬�߹�����Ƭ���ԣ������Ų����˳�ȥ��\n");
          else {
             tell_room(environment(me), me->name()+"�������ţ��첽�뿪��\n"NOR, ({ me }));
             me->move(__DIR__"huapu1");
             tell_room(environment(me), me->name()+"�Ӳݾ��첽���˹�����\n"NOR, ({ me }));
             me->look();
             return notify_fail("");
          }
        }
        return ::valid_leave(me, dir);
}
