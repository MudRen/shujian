inherit ROOM;

void create()
{
        set("short", "��ɮ��");
        set("long", @LONG
���������»�����ɮ���估��ס֮�������ڹ�����������ʱ��
����������֮����һ����ǿ��׳����ɮ���Կ���������ѧ֮�ذ¡�
LONG
        );
        set("exits", ([
		"south" : __DIR__"wstang3",
		"north" : __DIR__"wstang1",
	]));
        set("objects", ([
		CLASS_D("shaolin") + "/wuseng1":1 ]) );
	set("coor/x",-30);
	set("coor/y",270);
	set("coor/z",120);
	setup();
}
