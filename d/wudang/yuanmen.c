// xiaolu2.c �ּ�С��
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", WHT"Ժ��"NOR);
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ��
������������������Ķ����������ƺ���һ����ª��СԺ��
LONG
        );

        set("exits", ([
                "south" : __DIR__"houyuan.c",
                "north" : __DIR__"xiaolu2",
        ]));
        
        set("outdoors", "�䵱");
	set("cant_hubiao", 1);

        set("objects",([
                CLASS_D("wudang")+ "/yinlt" : 1,
        ]));

        create_door("south", "����", "north", DOOR_CLOSED);
        setup();
}

int get_object(object ob)
{
        return (userp(ob));
}

int valid_leave(object me, string dir)
{
	object obj;
        object *ob, *inv;
        mapping myfam;
        myfam =( mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "�䵱��")
         &&  objectp(obj =present("yin liting", environment(me)))
         && dir == "south"
         && living(obj))
           return notify_fail(CYN"����ͤ��סȥ·����ȭ������ʦ�����ڱչأ�û�²��ô��š�\n"NOR);

        if ((int)me->query("shen") < 0
         && me->query("family/family_name") == "�䵱��"
         && objectp(obj =present("yin liting", environment(me)))
         && dir == "south"
         && living(obj))
           return notify_fail(CYN"����ͤ����һ����Ȱ����ʦ�������˼��������ƶ񲻷�֮�ˣ��㻹��ȥ�����Щ����֮�°ɣ�\n"NOR);

        if((int)me->query_skill("yinyun-ziqi", 1) < 80
         && objectp(obj = present("yin liting", environment(me)))
         && dir == "south"
         && living(obj))
           return notify_fail(CYN"����ͤ����һ��,Ȱ��������ûҪ������,��Ҫ����ʦ�������˼����ޡ�\n"NOR);

	inv = deep_inventory(me);
	if (dir == "north"){
		write("������һ��С�����������������ӣ�����ɭɭ���������ء�\n");
		ob = filter_array(inv,(:get_object:));        
		if (me->query_condition("killer") && me->query("family/family_name") != "�䵱��") ;
		else if (myfam && myfam["family_name"] =="�䵱��" && myfam["generation"] == 2 && ! sizeof(ob))
			write("�������߹�������С���������Ų��߳������֡�\n");
		else {
			tell_room(environment(me), me->name()+"�������"YEL"С��"NOR"�첽�뿪��\n"NOR, ({ me }));
			me->move(__DIR__"xiaolu6");
			tell_room(environment(me), me->name()+"��"WHT"Ժ��"NOR"�첽���˹�����\n"NOR, ({ me }));
			return notify_fail("");
		}
	}
	return ::valid_leave(me, dir);
}
