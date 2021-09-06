// Room: /d/wizard/wizard_room.c

inherit ROOM;

void create()
{
        set("short", "��ʦ������");
        set("long", @LONG
�ڿ������Ĵ����������з���һ�ź�ľ��Բ������ʦͨ����������
����ͨ��һЩ��Ҫ������޸ĵ��᰸�����������԰��ܻ㣬�ϱ��Ͷ��ߵ�ͨ��
��ͨ��������̨�������ͨ��ͨ���Խ�ɽׯ�����ҡ�
LONG );
	set("exits", ([
		"west" : __DIR__"wizard_room",
		"tiandi" : "/cmds/leitai/leitai",
		"fengyun" : "/cmds/leitai/leitai1",
		"longhu" : "/cmds/leitai/leitai2",
		"down" : __DIR__"guest_room",
                "up" : "/cmds/leitai/bwdh/zongtai",
        ]));
	set("valid_startroom", 1);
        set("no_fight", 1);
	set("incity",1);
	setup();
        call_other("/clone/board/post_b", "???");
}

void init()
{
  	object me = this_player();

  	if (userp(me) && !wiz_level(me)) {
    		me->move("/d/wizard/guest_room");
    		message_vision("$N����ʦ��Ϣ�����ص�ˤ��������\n", me);
    		me->unconcious();
  	}
}
