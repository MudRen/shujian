// Room: /d/tianshan/banshan.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
���˰����������ϵ���ɽ������Ѿ��������޵ĳ�����˿˿����������
Щ��Ļ�ѩ��ɽ����һ������Ĵ��ԭ��Զ�������޺�������ʥɽ������Ŀ��
���ɵ�һ�ɺ���׳־������ͷ����������Ӣ��������˭����ͷ��ɽ·���˺���
�Ѿ����˾�ͷ�����ֵ�ɽ�������ҵĶ��ż���ľ����
LONG);

	 set("exits", ([
                "southdown" :__DIR__"shanlu3",
	        "west" :__DIR__"duanhunya",

        ]));
        set("objects", ([
                __DIR__"npc/guanmingmei" : 1,
		__DIR__"npc/chenzhengde" : 1,
        ]));

	set("outdoors", "��ɽ");
	setup();
}
