// /u/dubei/miaojiang/mjqj

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY+"�置�澳"+NOR);
        set("long", @LONG
������ɽ���ı�Ե��������Ϊ�������ͱ��������Ź����������Ѿ�û��
�˵��㼣�ˣ���಻֪����С����������������ȥ��
LONG                           
        );
        set("wu_count",3);

	set("outdoors", "�置");

        set("exits", ([
                 "southwest" : __DIR__"mjqj",
        ]));

        setup();
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));
}
 
int do_wa(string arg)
{ 
	int i;
        object wu, me, *inv;

        me = this_player();
        inv = deep_inventory(me);

        i = sizeof(inv);

        if (!( present("xiao tiechan", this_player())))
		return notify_fail("���ڵ��������� ���������С���\n");

        if ( !arg || arg != "he shouwu" )
		return notify_fail("������ʲ�᣿\n");       

        if ((int)me->query("jingli")<200) 
		return notify_fail ("��̫���ˣ�\n");

        if(objectp(present("heshou wu", me)))        
		return notify_fail("���Ѿ��õ��������ˣ���ô��ô̰�ģ�\n");

        if(random(15)!=3) {
		me->add("jingli",-120);
		return notify_fail("�����˰��죬ֻ����һЩҰ�ݡ�\n"); 
        }

        while (i--)
        if( inv[i]->query("drug"))
		return notify_fail("�����˰��죬ֻ����һЩҰ�ݡ�\n");  
 
        if (query("wu_count") > 0){
		message_vision("$N��Ȼ����һ������ڣ��Ͽ����������\n",me);
		add("wu_count", -1);
		wu=new("/clone/medicine/neili/shouwu");
		wu->set("owner", me->query("id"));
		wu->move(me);
		log_file("quest/neili",sprintf("%-18s���置�õ�%s��\n",
			me->name(1)+"("+capitalize(me->query("id"))+")",wu->name()), me);
		me->add("jingli", -200);      
        }
	else
		message_vision("$N���˰��죬һ������\n", me);
	return 1;
}
