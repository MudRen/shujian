// /d/jiaxing/lumu.c ��Ĺ
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "��Ĺ");
	set("long", @LONG
�����������ʵĴ����������º�Ȼ������������Ĺ��һ��Ĺ����д��
��½��չԪ֮Ĺ�����֣���һ�������ǡ�½�źη���֮Ĺ�����֡�Ĺ�������
ϥ�����ǰ����Ѿá�һ���۳�������ߴ�������Ĺ�����������
LONG
	);

	set("exits", ([
                 "west" : __DIR__"shulin1",
	]));

        set("objects", ([
                 __DIR__"npc/wu-santong" : 1,
        ]));

        set("outdoors", "����");
	setup();
}
