// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "�¼�С·");
        set("long", @LONG
��̤ʵ����Ժ����Ҷ������Ժ�ڵ�ʯ·�ϣ��ۼ�ͥ��һ�깫������һƬ��
Ҷ�������䡣��
LONG
        );
        set("outdoors", "����");
        set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"dadian",
            "south" : __DIR__"nianhuasi",
        ]));
       
        set("no_clean_up", 0);

        set("coor/x",-200);
  set("coor/y",-420);
   set("coor/z",10);
   setup();
}

void init()
{
        add_action("do_shoot", ({"shoot", "she"}));
}
int do_shoot(string arg)
{
        object me = this_player();
        int level, jinglicost;

        level = me->query_skill("finger", 1);
        if (arg == "leaf" || arg == "ye" || arg == "huangye"|| arg == "luoye") {
                jinglicost = level / 3 + random(level / 3);
                if (me->query("jingli") <= jinglicost) {
                        write("��̫���ˣ���ЪЪ�ɣ�\n");
                        return 1;
                }
		if (me->is_busy()) return notify_fail("�����ں�æ��\n");
                if (level < 30) {
                        write("�㿴�Ż������µĻ�Ҷ��������ָ����Ҷ��ȥ��ȴ��ôҲ������ָ������\n");
                        return 1;
                }
                me->receive_damage("jingli", jinglicost);
                if (level <= 100) {
                        write("��������ָ��һ��ָ���׼һƬ��Ҷ��ȥ��");
                        if (level < 40) write("��Ҷ�ƺ�΢΢����һ�¡�\n");
                        else if (level < 50) write("��Ҷ�ƺ�����һ�¡�\n");
                        else if (level < 60) write("��Ҷ���ᶯ��һ�¡�\n");
                        else if (level < 70) write("��Ҷ����Ļ���һ�¡�\n");
                        else if (level < 80) write("��Ҷ����ö�Ʈ��ɢ������һ���ּ���Ʈ�䡣\n");
                        else if (level < 90) write("��Ҷ����ĵ�����������������ö࣬Ȼ�����Ʈ�䡣\n");
                        else write("���͡���һ�����죬һƬ��Ҷ����ָ�������գ�Ȼ���������Ʈ�䡣\n");
                        me->improve_skill("finger", me->query("int"));
                        if (!random(5)) message("vision", "$N���ſ���ָָ��㣬��֪����ʲô��\n", me, ({ me }));
                }
                else {
                        write("ֻ�������Ҷ��ƬƬ���裬�㲻�ɵĳ��ˣ�\n");
                                        }
                return 1;
        }
        return notify_fail("��Ҫıɱ˭��\n");
}
