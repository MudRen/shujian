// room: well1.c
// Jay 4/8/96

inherit ROOM;

int do_use(string);
int do_zuan();

void create()
{
        set("short", "����");
        set("long", @LONG
������һ�ڿݾ��ľ��ס����߼�����ʲôҲ�����塣
LONG
        );

        set("exits", ([
                "up" : __DIR__"well",
        ]));

        set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{

        if( !arg || arg != "fire" ) return 0;

        if (!present("fire", this_player())) return 0;
        if( arg == "fire" ) {
             write("���ȼ�˻��ۣ����־���ʲôҲû�С�\n");
             return 1;
        }
	return 0;
}

int do_zuan()
{
	object me;
	me = this_player();

	message_vision("$N��ûͷ��Ӭһ���ںڶ����ľ���Ϲ�꣬���һͷײ�ھ��ڵ�ʯͷ�ϡ�\n", me);
	if(random(2) == 1)
		me->unconcious();
	return 1;
}
