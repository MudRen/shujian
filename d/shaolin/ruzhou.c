// Room: /d/shaolin/ruzhou.c

inherit ROOM;
void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ���ر����̲�
�������������ˣ����������𸽽�ɽ�ϵĲݿܡ�����һ�Ӷӹٱ�����ȥȥ��һ
��ɭ������������������������֮һ����ɽ��
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"south" : "/d/nanyang/yidao3",
		"west" : __DIR__"shijie1",
	]));
        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
                CLASS_D("gaibang/qnqigai") : 1,
        ]));
	setup();
}
