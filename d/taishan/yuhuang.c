// Room: /d/taishan/.c

inherit ROOM;

void create()
{
        set("short", "��ʶ�");
        set("long", @LONG
�˴�����̩ɽ������������һ����۹ۣ���ǰΪ�ŵǷ�̨�������ʵ۷���
����ʽ������������С�̨����һ���ֱ�����˵�Ǻ������������Զ����һʯ
�٣����顸����С���´������������ϱ���������������֮��������̨��
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"nantian",
                "eastdown" : __DIR__"riguan",
                "west" : __DIR__"zhangren",
                "up" : __DIR__"fengchan",
        ]));
	set("objects",([
		__DIR__"npc/qinbing1" : 2,
		__DIR__"npc/tianmen" : 1
	]));
        set("no_clean_up", 1);
        set("outdoors", "̩ɽ");

	setup();
}

void init()
{
      add_action("do_ansuan","ansuan");
}

int do_ansuan()
{
       write("�㲻�������ﰵ���κ��ˡ�\n");
       return 1;
}
