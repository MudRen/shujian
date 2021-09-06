// Room: /d/meizhuang/jiushi.c
// By Lklv

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ����ң�����ƿ�������һ���˱Ǿ��㡣����������˸�ɫ����
�ľƺ���Ͱ����ɫ�ƾߣ��������硣
LONG
	);

	set("exits", ([
		"east" : __DIR__"huilang4",
	]));
	set("objects", ([
		"d/meizhuang/npc/dingjiansuper" : 1,
				]) );
	setup();
}

void init()
{
        add_action("do_zuan", "zuan");
}

int do_zuan(string arg ,string dir)
{
        object ob;
        object me = this_player();
        
                if (!this_player()->query_temp("quest/xxdf/start")){
                write("��û��Ϲ��ʲô���ӣ�\n");
             return 1;
        }

        if (arg != "table")
        {
                write("����Ҫ���Ķ��ꣿ\n");
                return 1;
        }

        if (objectp(ob = present("ding jian", this_object())) &&
            living(ob))
        {
                write("��͵͵�Ŀ��˿�" + ob->name() + "������������\n");
                return 1;
        }

        write("\n��������ŵ��Ƶ�ʯ���ĺ��棬����������һ��С����\n");
        if((int)me->query_skill("dodge",1) >= 30)
        {
              write("\n��Ѿ���ţ����֮���������Լ�����һ�������صĵص��\n\n");
              me->move(__DIR__"didao1");
              return 1;
        }
        write("\n����������һ�º����һ��С���������겻��ȥ��\n");
        me->add("jing", -10);
        me->add("qi", -10);

        return 1;
}


int valid_leave(object me, string dir)
{
        object ding;

        if (dir != "north" ||
            ! objectp(ding = present("ding jian", this_object())))
                return ::valid_leave(me, dir);

        return ding->permit_pass(me, dir);
}