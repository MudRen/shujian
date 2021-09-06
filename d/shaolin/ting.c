// Room: /d/shaolin/ting.c
// Date: bren

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"ӭ��ͤ"NOR);
	set("long", 
"������ӳ֮�У�һ��ʯͤ��Ȼ���С�ֻ��ͤ���Ҷ������ɷ�������š�"HIY"ӭ\n"
"��ͤ"NOR"���������֡���������ʿ���ڴ���������������ı������ſɽ������ڡ�\n"
"ͤ��������֪��ɮ����æµ���д���������͡�\n"
    );

	set("exits", ([
		"northup" : __DIR__"shijie9",
		"southdown" : __DIR__"shijie8",
	]));
	set("outdoors", "shaolin");
	set("objects",([
		CLASS_D("shaolin") + "/xu-tong" : 1,
		CLASS_D("shaolin") + "/xu-ming" : 1,
		CLASS_D("shaolin") + "/weitian" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_quit","quit");
}

int do_quit()
{
        object ob = this_player();
	if (ob->query_condition("sl_lunzhi") > 0){
		write("��������ֵ�������˳���Ϸ��\n");
                return 1;
        }
        return 0;
}

int valid_leave(object me, string dir)
{
	object *inv;
	mapping myfam;
	int i;

	myfam = (mapping)me->query("family");
  	if (!me->query("luohan_winner") && !present("yingxiong ling", me))
		if (me->query("gender") == "Ů��" && dir == "northup" ) {
			if(objectp(present("xu tong", environment(me))))
				return notify_fail("��ͨ������ס�����һ��˵����ǧ����������������Ů�����롣\n"
				 + RANK_D->query_respect(me) +"����ɽȥ�ɣ��������ûȤ��\n");
			if(objectp(present("xu ming", environment(me))))
				return notify_fail("����������������ǰ��˫�ֺ�ʲ˵���������ӷ�"
					"��λ" + RANK_D->query_respect(me) + "��������\nˡС�²��Ӵ�Ů"
                			"�͡�Ůʩ������һ����𣬺η�ȥ��üɽ��ϲ��\n");
		}
	if ((!myfam || myfam["family_name"] != "������" ) && dir == "northup") {
        	inv = all_inventory(me);
        	for(i=sizeof(inv)-1; i>=0; i--)
            	if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped"))) {
                	if(objectp(present("xu tong", environment(me))))
                    		return notify_fail("��ͨ��ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�����ǧ���"
                        "��أ���Ͳ��óֱ�����ɽ��\n");
                	if(objectp(present("xu ming", environment(me))))
                    		return notify_fail("����������������ǰ��˫�ֺ�ʲ˵������"
                        "���ӷ���λ" + RANK_D->query_respect(me) + "������"
                        "���С�\n�����徲֮�أ����������赶Ū��������ʩ����"
                        "�¡�\n");
		}
	}

	if (!me->query("muren_winner")
	 && mapp(myfam)
	 && myfam["family_name"]== "������" 
	 && me->query("class") == "bonze" 
	 && dir == "southdown" ) {
		if(objectp(present("xu tong", environment(me))))
			return notify_fail("��ͨ������ס�㹪��˵������λʦ���书��δ���ã�����"
                              "��ɽ����������������ֵ�������\n");
		if(objectp(present("xu ming", environment(me))))
			return notify_fail("����������ס�㹪��˵������λʦ���书��δ���ã�����"
                              "��ɽ����������������ֵ�������\n");
	}

	if (me->query_condition("sl_lunzhi") > 0)
		return notify_fail("��������ֵ�������뿪��\n");

	if(me->query("no_quest") && dir == "northup")
		return notify_fail("\n");

	return ::valid_leave(me, dir);
}
