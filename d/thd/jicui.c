// ROOM : /u/jpei/thd/jicui.c
// Modified by Numa 1990828

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", GRN"����ͤ"NOR);
        set("long", @LONG
��������֦��ɵ���ͤ��ͤ�з�����̨���Σ�ȫ�Ƕ���֮��õ�
���ˣ��ֳ������ƹ⣬��������һ������(duilian)�����治Զ������
���ϵ����˵Ŀͷ����ϱ����涼�������де������֡�
LONG
        );
        set("exits",([
                "north" : __DIR__"zhulin12",
                "south" : __DIR__"zhulin21",
                "east" : __DIR__"kefang",
                "enter" : __DIR__"room",
        ]) );
//set("no_clean_up",0);
        set("outdoors","�һ���");
        set("item_desc",([
                "duilian" : HIY"
\t��������              ��������
\t��    ��              ��    ��
\t�� �� ��              �� �� ��
\t�� �� ��              �� �� ��
\t�� Ӱ ��              �� �� ��
\t�� �� ��              �� �� ��
\t�� �� ��              �� �� ��
\t�� �� ��              �� �� ��
\t�� �� ��              �� �� ��
\t��    ��              ��    �� 
\t��������              ��������\n 
"NOR
        ]));
        set("objects",([
                __DIR__"npc/yaoshi.c" : 1,
        ]) ); 

        setup();
}

void init()
{
	object me = this_player();
	int lvl,lvl1,lvl2;
	lvl = me->query_skill("qimen-bagua", 1);
	lvl1 = me->query_skill("bihai-chaosheng", 1);
        if (lvl > 500 && !me->query("cut/thd")){
		lvl2 = (lvl - 200)/ 4;
                me->set_skill("qimen-bagua", 500);
		me->set_skill("bihai-chaosheng", lvl1 + lvl2);
		me->set("cut/thd", lvl2 * 4);
		write(HIG "ϵͳ�ѽ�������ġ����Ű��ԡ�ת��Ϊ���̺�����������\n" NOR);
	}
	if ( me->query("thd_job")){
		me->add("job_time/�һ���", me->query("thd_job"));
		me->delete("thd_job");
	}
}

int valid_leave(object me, string dir)
{
	object *ob, *deep_ob;
	int i, j, drop_flag;

	if (dir == "north" || dir == "east") {
		ob = all_inventory(me);
		drop_flag = 0;
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!drop_flag) {
					message_vision("$N������ҩʦ���ѱ������˷��£����ҩʦ���˸���\n", me);
					drop_flag = 1;
				}
				message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, ob[i]);
				ob[i]->move(this_object());
			}
			else {
				deep_ob = deep_inventory(ob[i]);
				for(j = 0; j < sizeof(deep_ob); j++) {
					if (userp(deep_ob[j])) {
						if (!drop_flag) {
							message_vision("$N������ҩʦ�������ϵı�����Ʒ���£����ҩʦ���˸���\n", me);
							drop_flag = 1;
						}
						message_vision(sprintf("$N����һ%s$n��\n", ob[i]->query("unit")), me, ob[i]);
						ob[i]->move(this_object());
						break;
					}
				}
			}
		}
	}
        if( dir =="enter" && objectp(present("huang yaoshi", environment(me)))) 
		return notify_fail("��ҩʦ����һ�죬��ס���ȥ·��Ц����û���ҵ�ͬ�������ܽ����﷿��\n");
	return ::valid_leave(me, dir);
}
