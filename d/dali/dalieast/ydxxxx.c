// Room: /d/dali/ydxxxx.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�۾�¥��");
	set("long", @LONG
���ƾ�����ֻ����ʮ�����Σ���У�һ���峺���׵�С�ӣ����Ƕ���
�ŵ�һ��������������Զ������������б����һ���޴�����Ķ��У���������
��������
LONG
	);
        set("outdoors", "����");

	set("exits", ([
            "west" : __DIR__"ydxxx",
	    "up" : __DIR__"ydxxxxx",
	]));

	setup();
}
