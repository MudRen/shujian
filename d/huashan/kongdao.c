// Room: /d/huashan/kongdao.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "�׵�");
        set("long", @LONG
����һ��խխ�Ŀ׵����������ʲôҲ���������
LONG);
        set("indoors", "��ɽ" );

        setup();
}

void init()
{
        add_action("do_break", "break");
        add_action("do_use", "use");
}

int do_break(string arg)
{
        object me = this_player();
        object weapon;

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
        if (arg != "wall")
                return notify_fail("��Ҫ����ʲô��\n");
        if (query("exits/out"))
                return notify_fail("ǽ���Ѿ��������ˡ�\n");

        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword")
                return notify_fail("�������޽�������Ʊڣ�\n");

        message_vision("$N����"+weapon->name()+"��������������ʯ�ڡ�\n", me);
        if (me->query("neili") < 200) {
                me->set("neili", 0);
                message_vision("ֻ���ĵ�һ����"+weapon->name()+"��Ϊ���أ�ԭ��$N�������㡣\n", me);
                weapon->move(environment(me));
                weapon->set("name", "�ϵ���" + weapon->name());
                weapon->set("value", 49);
                weapon->set("weapon_prop", 0);
                me->unconcious();
        } else {
                me->add("neili", -200);
                message_vision("����һ����"+weapon->name()+"��������ʯ��֮�У�ֱ��û����ʯ����¶����һ�����ڡ�\n", me);
                set("exits/out", __DIR__"shandong");
                call_out("close", 2);
        }
        return 1;
}

void close()
{
        tell_room(this_object(), "ʯ�������������ֶ�ס�˶��ڡ�\n");
        delete("exits/out");
}

int do_use(string arg)
{
        object me = this_player();

        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ء�\n");
        if (arg != "fire" || !present("fire", me) || userp(present("fire", me)))
                return notify_fail("��Ҫ��ʲô��\n");
        message_vision("$N��ȼ���ۣ�����������˹�ȥ��\n", me);
	 me->move(__DIR__"yongdao");
        tell_room(environment(me), me->name()+"���������˹�����\n", ({ me }));
        return 1;
}
