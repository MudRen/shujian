// Room: /d/city/bingying.c

inherit ROOM;

void create()
{
        set("short", "��Ӫ");
        set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�������
�Ķ������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ��
�����ܡ����������������ȫ�������Χ�˹��������ƿ�����̫�������һ
��С����(window)��Ϊ�˷���̽��İ��գ����Դ�������ڴ���(pass)Щ�Ե�
������
LONG
        );
        set("item_desc", ([
                "men" : "����һ�ȼ�������š�\n",
        ]));
        set("exits", ([
                "south" : __DIR__"bingqiku",
                "east" : __DIR__"bingyingmen",
        ]));
        set("objects", ([
		NPC_D("guanfu/shi-qingshan") : 1,
                NPC_D("guanfu/wujiang") : 2,
                NPC_D("guanfu/bing") : 3,
        ]));
	set("incity",1);
	setup();
}
void init()
{
        add_action("do_visit", "look");
        add_action("do_pass", "pass");
}

int do_pass(string arg)
{
        object ob;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query_weight() > 5000)
                return notify_fail(ob->query("name")+"̫���ˣ����ܴӴ���������ȥ��\n");

	if (ob->query("no_drop")
	|| ob->query("id") == "huashi fen" || ob->query("id") == "tie he" || ob->is_container() || ob->query("hsf"))
                return notify_fail("��������Ų���ȥ��\n");

        message_vision("$N��һ"+ob->query("unit")+"$n�Ӵ������˽�ȥ��\n", this_player(), ob);
        ob->move("/d/city/dalao");
        message("vision", this_player()->name()+"�Ӵ���������һ"
                +ob->query("unit")+ob->query("name")+"��\n",environment(ob), ob);
        return 1;
}
int do_visit(string arg)
{
        object env, me = this_player();

        if (arg != "window") return 0;

        if(!( env = find_object("/d/city/dalao")) )
                env = load_object("/d/city/dalao");

        message_vision("$Nſ�ڴ�̨��������ȥ��\n", me);
        tell_room(env, "��е���һ˫�۾��ڴ�������㡣\n");
        return COMMAND_DIR"std/look"->look_room(me, env);
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("guan bing", environment(me))) &&
                dir == "south")
                return notify_fail("�ٱ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
