// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
���ڴ���ϣ����߶���������������·���������˲����࣬ż�������м�
�����߹���ֻ�������������У�С������һ�ǻ�ǽ¶����
LONG
	);
	set("group", 1);
        set("outdoors", "�����");
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : "/d/dali/yuxu/shangang",
		"west" : "/d/dali/yuxu/guanmen",
        ]));
	setup();
}
