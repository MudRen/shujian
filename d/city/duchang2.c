inherit ROOM;

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
        [1;33m�աաաաաաաաաաաաաաաաաաա�[0m
            [1;33m�ա�[0m                                [1;33m�ա�[0m
            [1;33m�ա�[0m ��[1;33;41m��[0m    [1;33;41m��[0m����[1;33;41m��[0m����[1;33;41m��[0m   [1;33;41m��[0m  [1;33m  �ա�[0m
            [1;33m�ա�[0m                                [1;33m�ա�[0m
            [1;33m�աաաաաաաաաաաաաաաաաաա�[0m

    ��������������ͨ��ͬ�Ĺ����䡣��������ƻ�ͨ������Զ׼��
��Ϊ������Ƿ���ǽ������һ�ŷ��Ƶ�ֽ(paper)������д�Ź����ŵ�
��������Բ鿴������(pigroom)������״����
LONG
        );
        
        set("item_desc", ([
                "paper" : 
"�������ļ����ɵ͵��߷�Ϊ��\n\n"
"���֣�ѧͯ��ͯ������������ţ�\n"
"���ˣ���Ԫ����ʿ����Ԫ����ʿ��\n"
"����ʿ�����ͣ�̽�������ۣ�״Ԫ��\n"
"���֣�ѧʿ����ѧʿ���׸������䣬\n"
"����ʦ������\n"
        ]));
        
        set("exits", ([
        "east" : __DIR__"eproom",
        "west" : __DIR__"wproom",
        "south" : __DIR__"sproom",
        "north" : __DIR__"nproom",
        "down" : __DIR__"duchang",
        ]));

        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("objects", ([
               __DIR__"npc/qian-laoben" : 1,
        ]));

        set("coor/x",90);
  set("coor/y",-20);
   set("coor/z",10);
   set("incity",1);
	setup();
        "/clone/board/pig_b"->foo();
}


void init()
{
    add_action("do_pigroom", "room");
    add_action("do_pigroom", "pigroom");
}

int do_pigroom()
{
	object env1, env2, env3, env4;
    object *obj1, *obj2, *obj3, *obj4;
    object me = this_player();
    int i, i1, i2, i3, i4;

	env1 = load_object(__DIR__"eproom.c");
	obj1 = all_inventory(env1);

	env2 = load_object(__DIR__"nproom.c");
	obj2 = all_inventory(env2);

	env3 = load_object(__DIR__"sproom.c");
	obj3 = all_inventory(env3);

	env4 = load_object(__DIR__"wproom.c");
	obj4 = all_inventory(env4);


    for (i = 0; i < sizeof(obj1); i++) 
        if (userp(obj1[i]))
            i1++;

    for (i = 0; i < sizeof(obj2); i++) 
        if (userp(obj2[i]))
            i2++;

    for (i = 0; i < sizeof(obj3); i++) 
        if (userp(obj3[i]))
            i3++;

    for (i = 0; i < sizeof(obj4); i++) 
        if (userp(obj4[i]))
            i4++;

        tell_object(me, "���ڸ�������������У�\n" + 
        "����������" + "\n" +
        "��������" + i2 + "\n" +
        "���� " + i4 + "������" + i1 + " ��\n" + 
        "��������" + i3 + "\n" +
        "���������� \n");
    return 1;
}

