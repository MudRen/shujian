// wdroad6.c ����·

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ƕ�������
˵���������˳�û�����ɾ�����
LONG
	);
        set("outdoors", "�䵱");

	set("exits", ([
                "east" : "/d/xiangyang/hanshui2",
		"west" : "/d/group/entry/wdroad7",
	]));
        set("objects",([
                CLASS_D("wudang")+"/quanjiannan" : 1,
                CLASS_D("wudang")+"/qlbz" : 2,
        ]));

        setup();
}
