// /d/gb/xiao-mushi.c СĹ��
// by Looklove Y2K 5/10
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"СĹ��"NOR);
        set("long", @LONG
����һ��СĹ�ң�ǽ�Ϲ����˻�棬�յù������ġ�ǽ����һ�ڲ�̫���
������Լ���Կ����������峺��Ȫˮ����������һ��̯���Ĳ��ڴ����������
�����Ӹ������ռ�������ʣ��ͷ�������ǿ��ڽ�������ƴ��ߴ����˯��
LONG);
        set("resource/water", 1);
	set("drink_msg","$Nſ�ھ�̨���Ϻ���һ��ˮ��\n");
        set("sleep_room",1);
        set("no_fight", 1);

        set("exits", ([
		"east" : __DIR__"mszoulang",
        ]));

        set("objects", ([
		FOOD_D("mantou") : 4
        ]));

   	setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
	object me = this_player();
	object ob;

	if (arg && (ob = present(arg)) && ob->id("man tou")){
	 	if ( !wizardp(me) && (present("man tou", me) || me->query("family/family_name")!="ؤ��"
		 || me->query("food") > me->query("str")*10 )){
			write("�������и��Ͻл�����һ�����㲻�ɵ��������֡�\n");
			return 1;
		}
	}
	return 0;
}