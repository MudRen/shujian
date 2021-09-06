// Room: /u/zqb/tiezhang/shuijing.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIM"����Ȫ"NOR);
	set("long", @LONG
����ǰ�У�һ·���̺���ϣ���ɽ��Ұ�����ʻ������������Ѽ���ת��һ
�����ԣ���ǰ����һ��Ȫˮ��Ȫˮ�峺���ף�ɢ����һ��������Ƣ��������Ȫ
ˮ���Աߣ�����һȺȺ�ĺ������򻨻�ף���ڻ��ϣ��������衣��������η
�ˣ��ɽ�ʱ�������ǵ�����ͣ����
LONG
	);

        set("outdoors", "tiezhang");
	set("exits", ([ 
"northwest" : __DIR__"guajia",
]));

	// set("no_clean_up", 0);
	set("resource", ([ 
"water" : 1,
]));

	
set("��ϵ��", 1);
   setup();
}


void init()
{
        add_action("do_tan", "mo");
}

int do_tan(string arg)
{
        object room, me,ob;
        mapping fam;
 
        me = this_player();
        fam = me->query("family");

        if(!living(me) ) return 0;

        if ( me->is_busy() || me->is_fighting())
              return notify_fail("����æ���ģ�\n");

        if( !arg || arg != "ˮ��" ) return 0;

        if( arg == "ˮ��" ){
            if ((!fam || fam["family_name"] != "����Ľ��") )
                return notify_fail("������̽��̽ˮ�ף�ֻ��Ȫˮ����ˬ�졣\n");
if ( present("shixi biao", this_player()))
return notify_fail("������̽��̽ˮ�ף�ֻ��Ȫˮ����ˬ���ޱȡ�\n");

if (query("��ϵ��") <1  ) 
return notify_fail(HIR"�������ˣ���ϵ���Ѿ�����ȡ���ˡ�\n"NOR);
ob = unew("d/tiezhang/obj/yuxi");
this_object()->add("��ϵ��",-1);
            message_vision(HIC"$N����ſ�ͣ�������ˮ��̽ȥ��ȴ�����������һ��������\n"NOR, me);

ob->set("owner",me->query("id"));
    ob->move(me);

              return 1; 
        }
}




