// /d/city/beidajie3.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң�����˶�
�����ϱ���ȥ�����������ݵ����Ĺ㳡��������������վ�����Ծ��ǵĿ�����
ʱ�ἱʻ���룬Ƭ�̺��ֻ�����һƥ�������������������ȥ��
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"yizhan",
                "south" : __DIR__"guangchangdong",
		"west" : __DIR__"guangchangbei",
		"north" : __DIR__"beidajie2",
	]));

        set("objects", ([
                __DIR__"npc/jingchengke" : 1,
                NPC_D("zhaojy") : 1,
        ]));
   set("incity",1);
	setup();
}

