// Room: /u/jpei/thd/taohua.c

inherit ROOM;

void create()
{
        int thd1, thd2, thd3, thd4;

        thd1 = random(4) + 1;
        thd2 = random(4) + 1;
        thd3 = random(4) + 1;
        thd4 = random(4) + 1;
        while (thd1 != 4 && thd2 != 4 && thd3 != 4 && thd4 != 4) {
                thd1 = random(4) + 1;
                thd2 = random(4) + 1;
                thd3 = random(4) + 1;
                thd4 = random(4) + 1;
        }
        set("short", "�һ���");
        set("long", @LONG
����һƬï�ܵ��һ��ԣ���һ�߽�������ʧ�˷���
LONG
        );

        set("exits", ([
                "east" : __DIR__"taohua" + thd1,
                "west" : __DIR__"taohua" + thd2,
                "south" : __DIR__"taohua" + thd3,
                "north" : __DIR__"taohua" + thd4,
        ]));
        set("outdoors","�һ���");
        setup();
}

void init()
{
        object letter, ob=this_player();

        if ((letter = present("recommend letter", ob)) && letter->query("owner") == ob->query("id")) {
                write("�������ɻ���ô��������һ���һ�������۴����ưͺ�Ȼ���˳���������������ϵ��Ƽ��ź�ʾ����������ߡ�\n");
                write("û����ã����Ǿʹ������һ��󣬾���һƬ�����ֺ�����һ��ͤ�Ӹ�ǰ��\n");
                ob->move(__DIR__"jicui", 1);
                tell_room(environment(ob), "һ����������" + ob->name() + "���˹�����\n", ({ob}));
                return;
        }

        if ((ob->query("family/family_name") == "�һ���" && ob->query_skill("qimen-bagua", 1) > 19) ||
                ob->query_skill("qimen-bagua", 1) > 130) {
                write("������ƽ����������Щ���׵��󷨣����Բ���ϸ�룬�Ų����߳�����\n");
	        ob->move(__DIR__"shangang", 1);
                tell_room(environment(ob), "ȴ����Ӱ��˸�����Ժ�Ȼ�ֳ�һ��ȱ�ڣ�" + ob->name() + "���������\n", ({ob}));
                return;
        }
        if (ob->query_temp("step_count") > 99) {
                ob->delete_temp("step_count");
                write("���������۵þ�ƣ����������������֧�����˹�ȥ��\n");
                write("���Ժ������ƺ����˰���̧�����󣬷·��и����ϵ������ȵ������ӵ�����ȥ����\n");
                ob->unconcious();
        ob->move(__DIR__"haibin", 1);
                message("vision", "��Ȼһ����ӿ�˹�������һ����ˮ�ݵð����ļһ�嵽�˰��ߡ�\n", environment(ob), ob);
                return;
        }
        ob->add_temp("step_count", 1);
}
