inherit ROOM;

void create()
{
	set("short", "���ű�Ӫ");
	set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ�������
�Ķ������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ��
�����ܡ�
LONG
        );

	set("exits", ([
		"west" : __DIR__"jail",
		"east" : __DIR__"northgate",
	]));

	set("objects", ([
		__DIR__"npc/liangdong" : 1,
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 4,
	]));

        set("cost", 0);
	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me)
	 && objectp(present("zhao liangdong", environment(me)))
	 && dir == "west")
		return notify_fail("�����������ȵ��������˵ȣ�һ���뿪��\n");
	return ::valid_leave(me, dir);
}
